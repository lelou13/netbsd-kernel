/*******************************************************************************
Copyright (C) Marvell International Ltd. and its affiliates

Developed by Semihalf

********************************************************************************
Marvell BSD License

If you received this File from Marvell, you may opt to use, redistribute and/or
modify this File under the following licensing terms.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    *   Redistributions of source code must retain the above copyright notice,
            this list of conditions and the following disclaimer.

    *   Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.

    *   Neither the name of Marvell nor the names of its contributors may be
        used to endorse or promote products derived from this software without
        specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*******************************************************************************/

#ifndef _ARMADAXPREG_H_
#define _ARMADAXPREG_H_

#include <arm/marvell/mvsocreg.h>
#include <evbarm/marvell/marvellvar.h>

#define ARMADAXP_UNITID_DDR		MVSOC_UNITID_DDR
#define ARMADAXP_UNITID_DEVBUS		MVSOC_UNITID_DEVBUS
#define ARMADAXP_UNITID_MLMB		MVSOC_UNITID_MLMB
#define ARMADAXP_UNITID_PEX		MVSOC_UNITID_PEX
#define ARMADAXP_UNITID_USB		0x5	/* USB registers */
#define ARMADAXP_UNITID_XORE0		0x6	/* Reserved? */
#define ARMADAXP_UNITID_GBE0		0x7
#define ARMADAXP_UNITID_GBE1		0x7
#define ARMADAXP_UNITID_GBE2		0x3
#define ARMADAXP_UNITID_GBE3		0x3
#define ARMADAXP_UNITID_PEX0		MVSOC_UNITID_PEX
#define ARMADAXP_UNITID_PEX1		0x8
#define ARMADAXP_UNITID_PEX2		MVSOC_UNITID_PEX
#define ARMADAXP_UNITID_PEX3		0x8
#define ARMADAXP_UNITID_CRYPT		0x9
#define ARMADAXP_UNITID_SATA		0xa
#define ARMADAXP_UNITID_BM		0xc
#define ARMADAXP_UNITID_NAND		0xd	/* NAND registers */
#define ARMADAXP_UNITID_SDIO		0xd	/* SDIO registers */
#define ARMADAXP_UNITID_LCD		0xe
#define ARMADAXP_UNITID_XORE1		0xf

/* DDR Attributes */
#define ARMADAXP_ATTR_DDR_CS0		0x0e
#define ARMADAXP_ATTR_DDR_CS1		0x0d
#define ARMADAXP_ATTR_DDR_CS2		0x0b
#define ARMADAXP_ATTR_DDR_CS3		0x07

/* DEVBUS Attributes */
#define ARMADAXP_ATTR_DEVBUS_UART	0x01
#define ARMADAXP_ATTR_DEVBUS_SPI0_CS0	0x1e
#define ARMADAXP_ATTR_DEVBUS_SPI0_CS1	0x5e
#define ARMADAXP_ATTR_DEVBUS_SPI0_CS2	0x9e
#define ARMADAXP_ATTR_DEVBUS_SPI0_CS3	0xde
#define ARMADAXP_ATTR_DEVBUS_SPI0_CS4	0x1f
#define ARMADAXP_ATTR_DEVBUS_SPI0_CS5	0x5f
#define ARMADAXP_ATTR_DEVBUS_SPI0_CS6	0x9f
#define ARMADAXP_ATTR_DEVBUS_SPI0_CS7	0xdf
#define ARMADAXP_ATTR_DEVBUS_SPI1_CS0	0x1a
#define ARMADAXP_ATTR_DEVBUS_SPI1_CS1	0x5a
#define ARMADAXP_ATTR_DEVBUS_SPI1_CS2	0x9a
#define ARMADAXP_ATTR_DEVBUS_SPI1_CS3	0xda
#define ARMADAXP_ATTR_DEVBUS_SPI1_CS4	0x1b
#define ARMADAXP_ATTR_DEVBUS_SPI1_CS5	0x5b
#define ARMADAXP_ATTR_DEVBUS_SPI1_CS6	0x9b
#define ARMADAXP_ATTR_DEVBUS_SPI1_CS7	0xdb
#define ARMADAXP_ATTR_DEVBUS_DEV_CS0	0x3e
#define ARMADAXP_ATTR_DEVBUS_DEV_CS1	0x3d
#define ARMADAXP_ATTR_DEVBUS_DEV_CS2	0x3b
#define ARMADAXP_ATTR_DEVBUS_DEV_CS3	0x37
#define ARMADAXP_ATTR_DEVBUS_BOOT_CS	0x2f
#define ARMADAXP_ATTR_DEVBUS_BOOT_ROM	0x1d

/* NAND Attributes */
#define ARMADAXP_ATTR_NAND_RESERVED	0x20

/* PCIe Attributes */
/* port 0, 1 has 4 lanes */
#define ARMADAXP_ATTR_PEXx0_MEM		0xe8
#define ARMADAXP_ATTR_PEXx0_IO		0xe0
#define ARMADAXP_ATTR_PEXx1_MEM		0xd8
#define ARMADAXP_ATTR_PEXx1_IO		0xd0
#define ARMADAXP_ATTR_PEXx2_MEM		0xb8
#define ARMADAXP_ATTR_PEXx2_IO		0xb0
#define ARMADAXP_ATTR_PEXx3_MEM		0x78
#define ARMADAXP_ATTR_PEXx3_IO		0x70
/* port 2, 3 has only 1 lane */
#define ARMADAXP_ATTR_PEX2_MEM		0xf8
#define ARMADAXP_ATTR_PEX2_IO		0xf0
#define ARMADAXP_ATTR_PEX3_MEM		0xf8
#define ARMADAXP_ATTR_PEX3_IO		0xf0

/* GbE Attributes */
#define ARMADAXP_ATTR_GBE_RESERVED	0x00

/* BM Attributes */
#define ARMADAXP_ATTR_BM_RESERVED	0x00

/* CRYPT Attributes */
#define ARMADAXP_ATTR_CRYPT_SWAP_MASK	__BITS(1,0)
#define ARMADAXP_ATTR_CRYPT_SWAP_B	(0x0 << 0)
#define ARMADAXP_ATTR_CRYPT_SWAP_NONE	(0x1 << 0)
#define ARMADAXP_ATTR_CRYPT_SWAP_BW	(0x2 << 0)
#define ARMADAXP_ATTR_CRYPT_SWAP_W	(0x3 << 0)
#define ARMADAXP_ATTR_CRYPT_UNIT_MASK	__BITS(3,2)
#define ARMADAXP_ATTR_CRYPT_UNIT0	(0x1 << 2)
#define ARMADAXP_ATTR_CRYPT_UNIT1	(0x2 << 2)

#define ARMADAXP_ATTR_CRYPT0_NOSWAP \
    (ARMADAXP_ATTR_CRYPT_SWAP_NONE|ARMADAXP_ATTR_CRYPT_UNIT0)
#define ARMADAXP_ATTR_CRYPT0_SWAP_BYTE \
    (ARMADAXP_ATTR_CRYPT_SWAP_B|ARMADAXP_ATTR_CRYPT_UNIT0)
#define ARMADAXP_ATTR_CRYPT0_SWAP_BYTE_WORD \
    (ARMADAXP_ATTR_CRYPT_SWAP_BW|ARMADAXP_ATTR_CRYPT_UNIT0)
#define ARMADAXP_ATTR_CRYPT0_SWAP_WORD \
    (ARMADAXP_ATTR_CRYPT_SWAP_W|ARMADAXP_ATTR_CRYPT_UNIT0)

#define ARMADAXP_ATTR_CRYPT1_NOSWAP \
    (ARMADAXP_ATTR_CRYPT_SWAP_NONE|ARMADAXP_ATTR_CRYPT_UNIT1)
#define ARMADAXP_ATTR_CRYPT1_SWAP_BYTE \
    (ARMADAXP_ATTR_CRYPT_SWAP_B|ARMADAXP_ATTR_CRYPT_UNIT1)
#define ARMADAXP_ATTR_CRYPT1_SWAP_BYTE_WORD \
    (ARMADAXP_ATTR_CRYPT_SWAP_BW|ARMADAXP_ATTR_CRYPT_UNIT1)
#define ARMADAXP_ATTR_CRYPT1_SWAP_WORD \
    (ARMADAXP_ATTR_CRYPT_SWAP_W|ARMADAXP_ATTR_CRYPT_UNIT1)


#define ARMADAXP_IRQ_ERR_SUMMARY	4

#define ARMADAXP_IRQ_GBE0_TH_RXTX	8	/* GBE0_TH_RXTX_Int */
#define ARMADAXP_IRQ_GBE1_TH_RXTX	10	/* GBE1_TH_RXTX_Int */
#define ARMADAXP_IRQ_GBE2_TH_RXTX	12	/* GBE2_TH_RXTX_Int */
#define ARMADAXP_IRQ_GBE3_TH_RXTX	14	/* GBE3_TH_RXTX_Int */

#define ARMADAXP_IRQ_LCD		29
#define ARMADAXP_IRQ_SPI		30
#define ARMADAXP_IRQ_TWSI0		31
#define ARMADAXP_IRQ_TWSI1		32
#define ARMADAXP_IRQ_IDMA0		33	/* IDMA Channel 0 */
#define ARMADAXP_IRQ_IDMA1		34	/* IDMA Channel 1 */
#define ARMADAXP_IRQ_IDMA2		35	/* IDMA Channel 2 */
#define ARMADAXP_IRQ_IDMA3		36	/* IDMA Channel 3 */
#define ARMADAXP_IRQ_TIMER0		37
#define ARMADAXP_IRQ_TIMER1		38
#define ARMADAXP_IRQ_TIMER2		39
#define ARMADAXP_IRQ_TIMER3		40
#define ARMADAXP_IRQ_UART0		41
#define ARMADAXP_IRQ_UART1		42
#define ARMADAXP_IRQ_UART2		43
#define ARMADAXP_IRQ_UART3		44
#if 0
#define ARMADAXP_IRQ_USB0		45
#define ARMADAXP_IRQ_USB1		46
#define ARMADAXP_IRQ_USB2		47
#else
/*
 * According to functional specification (MV-S107021-00B.pdf), interrupt number
 * for USB0_int is 47, in fact this number is 45. Because of that interrupt
 * number definitions are not equivalent to ArmadaXP functional specification
 * (MV-S107021-00B.pdf).
 */
#define ARMADAXP_IRQ_USB0		45	/* USB2 */
#define ARMADAXP_IRQ_USB1		46	/* USB1 */
#define ARMADAXP_IRQ_USB2		47	/* USB0 */
#endif
#define ARMADAXP_IRQ_CESA0		48
#define ARMADAXP_IRQ_CESA1		49
#define ARMADAXP_IRQ_RTC		50
#define ARMADAXP_IRQ_XOR0CH0		51	/* XOR0 Ch0 */
#define ARMADAXP_IRQ_XOR0CH1		52	/* XOR0 Ch1 */
#define ARMADAXP_IRQ_BM			53	/* Buffer Management */
#define ARMADAXP_IRQ_SDIO		54
#define ARMADAXP_IRQ_SATA0		55
#define ARMADAXP_IRQ_TDM		56
#define ARMADAXP_IRQ_SATA1		57
#define ARMADAXP_IRQ_PEX00		58	/* PCIe Port0.0 INTA/B/C/D */
#define ARMADAXP_IRQ_PEX01		59	/* PCIe Port0.1 INTA/B/C/D */
#define ARMADAXP_IRQ_PEX02		60	/* PCIe Port0.2 INTA/B/C/D */
#define ARMADAXP_IRQ_PEX03		61	/* PCIe Port0.3 INTA/B/C/D */
#define ARMADAXP_IRQ_PEX10		62	/* PCIe Port1.0 INTA/B/C/D */
#define ARMADAXP_IRQ_PEX11		63	/* PCIe Port1.1 INTA/B/C/D */
#define ARMADAXP_IRQ_PEX12		64	/* PCIe Port1.2 INTA/B/C/D */
#define ARMADAXP_IRQ_PEX13		65	/* PCIe Port1.3 INTA/B/C/D */
#define ARMADAXP_IRQ_XOR1CH2		94	/* XOR1 Ch2 */
#define ARMADAXP_IRQ_XOR1CH3		95	/* XOR1 Ch3 */
#define ARMADAXP_IRQ_PEX2		99	/* PCIe Port2 INTA/B/C/D */
#define ARMADAXP_IRQ_PEX3		103	/* PCIe Port3 INTA/B/C/D */

#define ARMADAXP_IRQ_SOURCES		116

/*
 * IRQ mappings for Error Interrupt Cause(ARMADAXP_MLMB_MPIC_ERR_CAUSE)
 */
#define ARMADAXP_IRQ_ERROR_BASE		120
#define ARMADAXP_IRQ_ERROR_SOURCES	32
#define ARMADAXP_IRQ_ERROR(x)		(120 + (x))
#define ARMADAXP_IRQ_ERROR_BIT(irq)	(1 << irq)

#define ARMADAXP_IRQ_CESA0_ERR		ARMADAXP_IRQ_ERROR(0)
#define ARMADAXP_IRQ_DEVBUS_ERR		ARMADAXP_IRQ_ERROR(1)
#define ARMADAXP_IRQ_IDMA_ERR		ARMADAXP_IRQ_ERROR(2)
#define ARMADAXP_IRQ_XOR1_ERR		ARMADAXP_IRQ_ERROR(3)
#define ARMADAXP_IRQ_PEX0_ERR		ARMADAXP_IRQ_ERROR(4)
#define ARMADAXP_IRQ_PEX1_ERR		ARMADAXP_IRQ_ERROR(5)
#define ARMADAXP_IRQ_GBE_ERR		ARMADAXP_IRQ_ERROR(6)
#define ARMADAXP_IRQ_CESA1_ERR		ARMADAXP_IRQ_ERROR(7)
#define ARMADAXP_IRQ_USB_ERR		ARMADAXP_IRQ_ERROR(8)
#define ARMADAXP_IRQ_DRAM_ERR		ARMADAXP_IRQ_ERROR(9)
#define ARMADAXP_IRQ_XOR0_ERR		ARMADAXP_IRQ_ERROR(10)
#define ARMADAXP_IRQ_BM_ERR		ARMADAXP_IRQ_ERROR(12)
#define ARMADAXP_IRQ_CIB_ERR		ARMADAXP_IRQ_ERROR(13)
#define ARMADAXP_IRQ_PEX2_ERR		ARMADAXP_IRQ_ERROR(15)
#define ARMADAXP_IRQ_PEX3_ERR		ARMADAXP_IRQ_ERROR(16)
#define ARMADAXP_IRQ_SATA0_ERR		ARMADAXP_IRQ_ERROR(17)
#define ARMADAXP_IRQ_SATA1_ERR		ARMADAXP_IRQ_ERROR(18)
#define ARMADAXP_IRQ_TDM_ERR		ARMADAXP_IRQ_ERROR(20)
#define ARMADAXP_IRQ_NAND_ERR		ARMADAXP_IRQ_ERROR(21)

#define ARMADAXP_MLMB_NWINDOW		20
#define ARMADAXP_MLMB_NREMAP		8

/*
 * Physical address of integrated peripherals
 */

#undef UNITID2PHYS
#define UNITID2PHYS(uid)	((ARMADAXP_UNITID_ ## uid) << 16)

/*
 * Real-Time Clock Unit Registers
 */
#define ARMADAXP_RTC_BASE	(MVSOC_DEVBUS_BASE + 0x0300)

/*
 * SPI Interface Registers
 */
#define ARMADAXP_SPI_BASE	(MVSOC_DEVBUS_BASE + 0x0600)

/*
 * TWSI Interface Registers
 */
#define ARMADAXP_TWSI1_BASE	(MVSOC_DEVBUS_BASE + 0x1100)

/*
 * UART Interface Registers
 */				/* NS16550 compatible */
#define ARMADAXP_COM2_BASE	(MVSOC_DEVBUS_BASE + 0x2200)
#define ARMADAXP_COM3_BASE	(MVSOC_DEVBUS_BASE + 0x2300)

/*
 * General Purpose Input/Output Port Registers
 */
#define ARMADAXP_GPIO0_BASE	(MVSOC_DEVBUS_BASE + 0x8100)
#define ARMADAXP_GPIO1_BASE	(MVSOC_DEVBUS_BASE + 0x8120)
#define ARMADAXP_GPIO2_BASE	(MVSOC_DEVBUS_BASE + 0x8140)

/*
 * Power Management Unit Registers
 */				/* NS16550 compatible */
#define ARMADAXP_PMU_BASE	(MVSOC_DEVBUS_BASE + 0xc000)

/*
 * Miscellanseous Register
 */
#define	ARMADAXP_MISC_BASE	(MVSOC_DEVBUS_BASE + 0x8200)

#define	ARMADAXP_MISC_PMCGC		0x20	/* PM Clock Gating Control */
#define	ARMADAXP_MISC_SAR_LO		0x30	/* Sample At Reset Low */
#define	ARMADAXP_MISC_SAR_HI		0x34	/* Sample At Reset High */
#define	ARMADAXP_MISC_RSTOUTNMASKR	0x60	/* RSTOUTn Mask Register */
#define	ARMADAXP_MISC_RSTOUTNMASKR_GLOBALSOFTRSTOUTEN (1 << 0)
#define	ARMADAXP_MISC_SSRR		0x64	/* System Soft Reset Register */
#define	ARMADAXP_MISC_SSRR_GLOBALSOFTRST	(1 << 0)

/* Multiprocessor Interrupt Controller Registers */
#define	ARMADAXP_MLMB_MPIC_BASE			0x20a00
#define	ARMADAXP_MLMB_MPIC_CPU_BASE		0x21800
#define	ARMADAXP_MLMB_MPIC_CTRL			0x0
#define	ARMADAXP_MLMB_MPIC_SOFT_INT		0x4
#define	ARMADAXP_MLMB_MPIC_ERR_CAUSE		0x20
#define	ARMADAXP_MLMB_MPIC_ISE			0x30
#define	ARMADAXP_MLMB_MPIC_ICE			0x34
#define	ARMADAXP_MLMB_MPIC_ISCR_BASE		0x100

#define	ARMADAXP_MLMB_MPIC_DOORBELL		0x78
#define	ARMADAXP_MLMB_MPIC_DOORBELL_MASK	0x7c
#define	ARMADAXP_MLMB_MPIC_CTP			0xb0
#define	ARMADAXP_MLMB_MPIC_IIACK		0xb4
#define	ARMADAXP_MLMB_MPIC_ISM			0xb8
#define	ARMADAXP_MLMB_MPIC_ICM			0xbc
#define	ARMADAXP_MLMB_MPIC_ERR_MASK		0xc0

/* Multiprocessor Interrupt Controller Shifts */
#define	MPIC_CTP_SHIFT			28 /* Global priority level field */
#define	MPIC_ISCR_SHIFT			24 /* IRQ source priority level field */

/* Cache Main Control */
#define ARMADAXP_L2_BASE		0x8000
#define ARMADAXP_L2_CTRL		0x100
#define ARMADAXP_L2_AUX_CTRL		0x104
#define ARMADAXP_L2_CNTR_CTRL		0x200
#define ARMADAXP_L2_CNTR_CONF(x)	(0x204 + (x) * 0xc)
#define ARMADAXP_L2_INT_CAUSE		0x220
#define ARMADAXP_L2_CFU			0x228
#define ARMADAXP_L2_SYNC		0x700
#define ARMADAXP_L2_STATUS		0x704
/* Cache maintance operations */
#define ARMADAXP_L2_RANGE_BASE		0x720
#define ARMADAXP_L2_INV_PHYS		0x770
#define ARMADAXP_L2_INV_RANGE		0x774
#define ARMADAXP_L2_INV_IDXWAY		0x778
#define ARMADAXP_L2_INV_WAY		0x77c
#define ARMADAXP_L2_BLOCK		0x78c
#define ARMADAXP_L2_WB_PHYS		0x7b0
#define ARMADAXP_L2_WB_RANGE		0x7b4
#define ARMADAXP_L2_WB_IDXWAY		0x7b8
#define ARMADAXP_L2_WB_WAY		0x7bc
#define ARMADAXP_L2_WBINV_PHYS		0x7f0
#define ARMADAXP_L2_WBINV_RANGE		0x7f4
#define ARMADAXP_L2_WBINV_IDXWAY	0x7f8
#define ARMADAXP_L2_WBINV_WAY		0x7fc

/* Cache line size */
#define ARMADAXP_L2_SIZE		(256 * 1024) /* bytes */
#define ARMADAXP_L2_LINE_SIZE		32
#define ARMADAXP_L2_ALIGN		(ARMADAXP_L2_LINE_SIZE - 1)
#define ARMADAXP_L2_WAYS		4
#define ARMADAXP_L2_WAY_SIZE		(ARMADAXP_L2_SIZE / ARMADAXP_L2_WAYS)
#define ARMADAXP_L2_SETS \
    (ARMADAXP_L2_WAY_SIZE / ARMADAXP_L2_LINE_SIZE)

/* ARMADAXP_L2_CTRL */
#define L2_CTRL_ENABLE			(1 << 0)

/* ARMADAXP_L2_AUX_CTRL */
#define L2_AUX_WBWT_MODE_MASK		__BITS(1,0)
#define L2_AUX_WBWT_MODE_BY_ATTR	(0 << 0)
#define L2_AUX_WBWT_MODE_WB		(1 << 0)
#define L2_AUX_WBWT_MODE_WT		(2 << 0)
#define L2_AUX_FLUSH_ON_POWERDOWN	__BIT(3)
#define L2_AUX_ECC_ENABLE		__BIT(20)
#define L2_AUX_PARITY_ENABLE		__BIT(21)
#define L2_AUX_INVAL_UCE		__BIT(22)
#define L2_AUX_FORCE_WA_MASK		__BITS(24,23)
#define L2_AUX_FORCE_WA_BY_ATTR		(0 << 23)
#define L2_AUX_FORCE_WA_DISABLE		(1 << 23)
#define L2_AUX_FORCE_WA_ENABLE		(2 << 23)
#define L2_AUX_FORCE_WA_ENABLE_DT	(3 << 23)
#define L2_AUX_REP_STRAT_MASK		(3 << 27)
#define L2_AUX_REP_STRAT_LFSR		(1 << 27)
#define L2_AUX_REP_STRAT_PLRU		(2 << 27)
#define L2_AUX_REP_STRAT_SEMIPLRU	(3 << 27)
#define L2_AUX_L2_SIZE_MASK		(0x03 << 10)
#define L2_AUX_L2_SIZE_256K		(0x00 << 10)
#define L2_AUX_L2_ASSOC_MASK		(0x0f << 13)
#define L2_AUX_L2_ASSOC_4WAY		(0x03 << 13)
#define L2_AUX_L2_WAY_MASK		(0x07 << 17)
#define L2_AUX_L2_WAY_16K		(0x02 << 17)
#define L2_AUX_L2_WAY_32K		(0x03 << 17)
#define L2_AUX_L2_WAY_64K		(0x04 << 17)
#define L2_AUX_L2_WAY_128K		(0x05 << 17)
#define L2_AUX_L2_WAY_256K		(0x06 << 17)
#define L2_AUX_L2_WAY_512K		(0x07 << 17)

#define L2_ALL_WAYS			0xffffffff

/*
 * PCI-Express Interface Registers
 */
#define ARMADAXP_PEX01_BASE	(MVSOC_PEX_BASE + 0x4000)
#define ARMADAXP_PEX02_BASE	(MVSOC_PEX_BASE + 0x8000)
#define ARMADAXP_PEX03_BASE	(MVSOC_PEX_BASE + 0xc000)
#define ARMADAXP_PEX10_BASE	(UNITID2PHYS(PEX1))
#define ARMADAXP_PEX11_BASE	(ARMADAXP_PEX10_BASE + 0x4000)
#define ARMADAXP_PEX12_BASE	(ARMADAXP_PEX10_BASE + 0x8000)
#define ARMADAXP_PEX13_BASE	(ARMADAXP_PEX10_BASE + 0xc000)
#define ARMADAXP_PEX2_BASE	(UNITID2PHYS(PEX2) + 0x2000)
#define ARMADAXP_PEX3_BASE	(UNITID2PHYS(PEX3) + 0x2000)

/*
 * USB 2.0 Interface Registers
 */
#define ARMADAXP_USB_BASE	(UNITID2PHYS(USB))	/* 0x50000 */
#define ARMADAXP_USB0_BASE	(ARMADAXP_USB_BASE + 0x0000)
#define ARMADAXP_USB1_BASE	(ARMADAXP_USB_BASE + 0x1000)
#define ARMADAXP_USB2_BASE	(ARMADAXP_USB_BASE + 0x2000)

/* 
 * XOR Engine Registers
 */
#define ARMADAXP_XORE0_BASE	(UNITID2PHYS(XORE0))	/* 0x60000 */
#define ARMADAXP_XORE1_BASE	(UNITID2PHYS(XORE1))	/* 0xf0000 */

/*
 * Gigabit Ethernet Registers
 */
#define ARMADAXP_GBE0_BASE	(UNITID2PHYS(GBE0))	/* 0x70000 */
#define ARMADAXP_GBE1_BASE	(ARMADAXP_GBE0_BASE + 0x4000)
#define ARMADAXP_GBE2_BASE	(UNITID2PHYS(GBE2))	/* 0x30000 */
#define ARMADAXP_GBE3_BASE	(ARMADAXP_GBE2_BASE + 0x4000)

/*
 * Precise Time Protocol (PTP) Registers
 */
#define ARMADAXP_PTP_BASE	(UNITID2PHYS(GBE0))	/* 0x7c000 */

/* 
 * Cryptographic Engine and Security Accelerator Registers
 */
#define ARMADAXP_CESA0_BASE	(UNITID2PHYS(CRYPT) + 0xd000)	/* 0x9d000 */
#define ARMADAXP_CESA1_BASE	(UNITID2PHYS(CRYPT) + 0xf000)	/* 0x9f000 */

#define ARMADAXP_XPSEC0_BASE	(UNITID2PHYS(CRYPT) + 0x0000)	/* 0x90000 */
#define ARMADAXP_XPSEC1_BASE	(UNITID2PHYS(CRYPT) + 0x2000)	/* 0x92000 */

/*
 * Serial-ATA Host Controller (SATAHC) Registers
 */
#define ARMADAXP_SATAHC_BASE	(UNITID2PHYS(SATA))	/* 0xa0000 */

/*
 * Buffer Management Controller Registers
 */
#define ARMADAXP_BMC_BASE	(UNITID2PHYS(BM))	/* 0xc0000 */

/*
 * NAND Flash Controller Version 2.0 Registers
 */
#define ARMADAXP_NAND_BASE	(UINTID2PHYS(NAND))

/*
 * PnC Unit Registers
 */
#define ARMADAXP_PNC_BASE	(UNITID2PHYS(PNC))	/* 0xc8000 */

/*
 * SDIO Registers
 */
#define ARMADAXP_SDIO_BASE	(UNITID2PHYS(SDIO) + 0x4000)	/* 0xd4000 */

/*
 * Liquid Crystal Display Registers
 */
#define ARMADAXP_LCD_BASE	(UNITID2PHYS(LCD))	/* 0xe0000 */

#endif /* _ARMADAXPREG_H_ */
