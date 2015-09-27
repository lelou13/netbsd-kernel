/* $NetBSD: dec_axppci_33.c,v 1.67 2012/10/13 17:58:54 jdc Exp $ */

/*
 * Copyright (c) 1995, 1996, 1997 Carnegie-Mellon University.
 * All rights reserved.
 *
 * Author: Chris G. Demetriou
 *
 * Permission to use, copy, modify and distribute this software and
 * its documentation is hereby granted, provided that both the copyright
 * notice and this permission notice appear in all copies of the
 * software, derivative works or modified versions, and any portions
 * thereof, and that both notices appear in supporting documentation.
 *
 * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"
 * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND
 * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.
 *
 * Carnegie Mellon requests users of this software to return to
 *
 *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU
 *  School of Computer Science
 *  Carnegie Mellon University
 *  Pittsburgh PA 15213-3890
 *
 * any improvements or extensions that they make and grant Carnegie the
 * rights to redistribute these changes.
 */
/*
 * Additional Copyright (c) 1997 by Matthew Jacob for NASA/Ames Research Center
 */

#include "opt_kgdb.h"

#include <sys/cdefs.h>			/* RCS ID & Copyright macro defns */

__KERNEL_RCSID(0, "$NetBSD: dec_axppci_33.c,v 1.67 2012/10/13 17:58:54 jdc Exp $");

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/device.h>
#include <sys/termios.h>
#include <sys/conf.h>
#include <dev/cons.h>

#include <uvm/uvm_extern.h>

#include <machine/rpb.h>
#include <machine/alpha.h>
#include <machine/autoconf.h>
#include <machine/cpuconf.h>

#include <dev/ic/comreg.h>
#include <dev/ic/comvar.h>

#include <dev/isa/isareg.h>
#include <dev/isa/isavar.h>
#include <dev/ic/i8042reg.h>
#include <dev/ic/pckbcvar.h>
#include <dev/pci/pcireg.h>
#include <dev/pci/pcivar.h>

#include <alpha/pci/lcareg.h>
#include <alpha/pci/lcavar.h>

#include <dev/scsipi/scsi_all.h>
#include <dev/scsipi/scsipi_all.h>
#include <dev/scsipi/scsiconf.h>

#include "pckbd.h"

#ifndef CONSPEED
#define CONSPEED TTYDEF_SPEED
#endif
static int comcnrate = CONSPEED;

void dec_axppci_33_init(void);
static void dec_axppci_33_cons_init(void);
static void dec_axppci_33_device_register(device_t, void *);

#ifdef KGDB
#include <machine/db_machdep.h>

static const char *kgdb_devlist[] = {
	"com",
	NULL,
};
#endif /* KGDB */

const struct alpha_variation_table dec_axppci_33_variations[] = {
	{ 0, "Alpha PC AXPpci33 (\"NoName\")" },
	{ 0, NULL },
};

static struct lca_config *lca_preinit(void);

static struct lca_config *
lca_preinit(void)
{
	extern struct lca_config lca_configuration;

	lca_init(&lca_configuration, 0);
	return &lca_configuration;
}

#define	NSIO_PORT  0x26e	/* Hardware enabled option: 0x398 */
#define	NSIO_BASE  0
#define	NSIO_INDEX NSIO_BASE
#define	NSIO_DATA  1
#define	NSIO_SIZE  2
#define	NSIO_CFG0  0
#define	NSIO_CFG1  1
#define	NSIO_CFG2  2
#define	NSIO_IDE_ENABLE 0x40

void
dec_axppci_33_init(void)
{
	int cfg0val;
	uint64_t variation;
	bus_space_tag_t iot;
	struct lca_config *lcp;
	bus_space_handle_t nsio;
#define	A33_NSIOBARRIER(type) bus_space_barrier(iot, nsio,\
				NSIO_BASE, NSIO_SIZE, (type))

	platform.family = "DEC AXPpci";

	if ((platform.model = alpha_dsr_sysname()) == NULL) {
		variation = hwrpb->rpb_variation & SV_ST_MASK;
		if ((platform.model = alpha_variation_name(variation,
		    dec_axppci_33_variations)) == NULL)
			platform.model = alpha_unknown_sysname();
	}

	platform.iobus = "lca";
	platform.cons_init = dec_axppci_33_cons_init;
	platform.device_register = dec_axppci_33_device_register;

	lcp = lca_preinit();
	iot = &lcp->lc_iot;
	if (bus_space_map(iot, NSIO_PORT, NSIO_SIZE, 0, &nsio))
		return;

	bus_space_write_1(iot, nsio, NSIO_INDEX, NSIO_CFG0);
	A33_NSIOBARRIER(BUS_SPACE_BARRIER_READ | BUS_SPACE_BARRIER_WRITE);
	cfg0val = bus_space_read_1(iot, nsio, NSIO_DATA);

	cfg0val |= NSIO_IDE_ENABLE;

	bus_space_write_1(iot, nsio, NSIO_INDEX, NSIO_CFG0);
	A33_NSIOBARRIER(BUS_SPACE_BARRIER_WRITE);
	bus_space_write_1(iot, nsio, NSIO_DATA, cfg0val);
	A33_NSIOBARRIER(BUS_SPACE_BARRIER_WRITE);
	bus_space_write_1(iot, nsio, NSIO_DATA, cfg0val);

	/* Leave nsio mapped to catch any accidental port space collisions  */

	/*
	 * AXPpci33 systems have either 0, 256K, or 1M secondary
	 * caches.  Default to middle-of-the-road.
	 *
	 * XXX Dynamically size it!
	 */
	uvmexp.ncolors = atop(256 * 1024);
}

static void
dec_axppci_33_cons_init(void)
{
	struct ctb *ctb;
	struct lca_config *lcp;

	lcp = lca_preinit();

	ctb = (struct ctb *)(((char *)hwrpb) + hwrpb->rpb_ctb_off);

	switch (ctb->ctb_term_type) {
	case CTB_PRINTERPORT:
		/* serial console ... */
		/* XXX */
		{
			/*
			 * Delay to allow PROM putchars to complete.
			 * FIFO depth * character time,
			 * character time = (1000000 / (defaultrate / 10))
			 */
			DELAY(160000000 / comcnrate);

			if(comcnattach(&lcp->lc_iot, 0x3f8, comcnrate,
			    COM_FREQ, COM_TYPE_NORMAL,
			    (TTYDEF_CFLAG & ~(CSIZE | PARENB)) | CS8))
				panic("can't init serial console");

			break;
		}

	case CTB_GRAPHICS:
#if NPCKBD > 0
		/* display console ... */
		/* XXX */
		(void) pckbc_cnattach(&lcp->lc_iot, IO_KBD, KBCMDP,
		    PCKBC_KBD_SLOT, 0);

		if (CTB_TURBOSLOT_TYPE(ctb->ctb_turboslot) ==
		    CTB_TURBOSLOT_TYPE_ISA)
			isa_display_console(&lcp->lc_iot, &lcp->lc_memt);
		else
			pci_display_console(&lcp->lc_iot, &lcp->lc_memt,
			    &lcp->lc_pc, CTB_TURBOSLOT_BUS(ctb->ctb_turboslot),
			    CTB_TURBOSLOT_SLOT(ctb->ctb_turboslot), 0);
#else
		panic("not configured to use display && keyboard console");
#endif
		break;

	default:
		printf("ctb->ctb_term_type = 0x%lx\n", ctb->ctb_term_type);
		printf("ctb->ctb_turboslot = 0x%lx\n", ctb->ctb_turboslot);

		panic("consinit: unknown console type %ld",
		    ctb->ctb_term_type);
	}
#ifdef KGDB
	/* Attach the KGDB device. */
	alpha_kgdb_init(kgdb_devlist, &lcp->lc_iot);
#endif /* KGDB */
}

static void
dec_axppci_33_device_register(device_t dev, void *aux)
{
	static int found, initted, diskboot, netboot;
	static device_t pcidev, ctrlrdev;
	struct bootdev_data *b = bootdev_data;
	device_t parent = device_parent(dev);

	if (found)
		return;

	if (!initted) {
		diskboot = (strcasecmp(b->protocol, "SCSI") == 0);
		netboot = (strcasecmp(b->protocol, "BOOTP") == 0) ||
		    (strcasecmp(b->protocol, "MOP") == 0);
#if 0
		printf("diskboot = %d, netboot = %d\n", diskboot, netboot);
#endif
		initted =1;
	}

	if (pcidev == NULL) {
		if (!device_is_a(dev, "pci"))
			return;
		else {
			struct pcibus_attach_args *pba = aux;

			if ((b->slot / 1000) != pba->pba_bus)
				return;
	
			pcidev = dev;
#if 0
			printf("\npcidev = %s\n", device_xname(dev));
#endif
			return;
		}
	}

	if (ctrlrdev == NULL) {
		if (parent != pcidev)
			return;
		else {
			struct pci_attach_args *pa = aux;
			int slot;

			slot = pa->pa_bus * 1000 + pa->pa_function * 100 +
			    pa->pa_device;
			if (b->slot != slot)
				return;
	
			if (netboot) {
				booted_device = dev;
#if 0
				printf("\nbooted_device = %s\n", device_xname(dev));
#endif
				found = 1;
			} else {
				ctrlrdev = dev;
#if 0
				printf("\nctrlrdev = %s\n", device_xname(dev));
#endif
			}
			return;
		}
	}

	if (!diskboot)
		return;

	if (device_is_a(dev, "sd") ||
	    device_is_a(dev, "st") ||
	    device_is_a(dev, "cd")) {
		struct scsipibus_attach_args *sa = aux;
		struct scsipi_periph *periph = sa->sa_periph;
		int unit;

		if (device_parent(parent) != ctrlrdev)
			return;

		unit = periph->periph_target * 100 + periph->periph_lun;
		if (b->unit != unit)
			return;
		if (b->channel != periph->periph_channel->chan_channel)
			return;

		/* we've found it! */
		booted_device = dev;
#if 0
		printf("\nbooted_device = %s\n", device_xname(dev));
#endif
		found = 1;
	}
}
