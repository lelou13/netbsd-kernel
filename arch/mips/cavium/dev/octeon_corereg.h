/*	$NetBSD: octeon_corereg.h,v 1.2 2015/06/01 22:55:12 matt Exp $	*/

/*
 * Copyright (c) 2007 Internet Initiative Japan, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _OCTEON_COREREG_H_
#define _OCTEON_COREREG_H_

/*
 * Core Coprocessor 0 Privileged Registers.
 */

#ifdef _LOCORE
#define	CP0_INDEX		$0	/* Index Register */
#define	CP0_RANDOM		$1	/* Random Register */
#define	CP0_ENTRYLO0		$2	/* EntryLo0 Registers */
#define	CP0_ENTRYLO1		$3	/* EntryLo1 Registers */
#define	CP0_CONTEXT		$4	/* Context Register */
#define	CP0_PAGEMASK		$5	/* PageMask Register */
#define	CP0_PAGEGRAIN		$5, 1	/* PageGrain Register */
#define	CP0_WIRED		$6	/* Wired Register */
#define	CP0_HWRENA		$7	/* HWREna Register */
#define	CP0_BADVADDR		$8	/* BadVAddr Register */
#define	CP0_COUNT		$9	/* Count Register */
#define	CP0_ENTRYHI		$10	/* EntryHi Register */
#define	CP0_COMPARE		$11	/* Compare Register */
#define	CP0_STATUS		$12	/* Status Register */
#define	CP0_INTCTL		$12, 1	/* IntCtl Register */
#define	CP0_SRSCTL		$12, 2	/* SRSCtl Register */
#define	CP0_CAUSE		$13	/* Cause Register */
#define	CP0_EPC			$14	/* Exception Program Counter */
#define	CP0_PRID		$15	/* PRId Register */
#define	CP0_EBASE		$15, 1	/* EBase Register */
#define	CP0_CONFIG		$16	/* Config Register */
#define	CP0_CONFIG1		$16, 1	/* Config1 Register */
#define	CP0_CONFIG2		$16, 2	/* Config2 Register */
#define	CP0_CONFIG3		$16, 3	/* Config3 Register */
#define	CP0_WATCHLO		$18	/* WatchLo Register */
#define	CP0_WATCHLO1		$18, 1	
#define	CP0_WATCHHI		$19	/* WatchHi Register */
#define	CP0_WATCHHI1		$19, 1	
#define	CP0_XCONTEXT		$20	/* XContext Register */
#define	CP0_DEBUG		$23	/* Debug Register */
#define	CP0_DPC			$24	/* Debug Exception Program Counter Register */
#define	CP0_PCCTL		$25	/* Performance Counter Control Register */
#define	CP0_PCCTL1		$25, 2	
#define	CP0_PCCNT		$25, 1	/* Performance Counter Counter Register */
#define	CP0_PCCNT1		$25, 3	
#define	CP0_ERROREPC		$30	/* ErrorEPC */
#define	CP0_DESAVE		$31	/* DESAVE Register */
#define	CP0_CACHEERRI		$27	/* CacheErr (Icache) */
#define	CP0_CACHEERRD		$27, 1	/* CacheErr (Dcache) */
#define	CP0_TAGLOI		$28	/* TagLo Register (Icache) */
#define	CP0_TAGLOD		$28, 2	/* TagLo Register (Dcache) */
#define	CP0_DATALOI		$28, 1	/* DataLo Register (Icache) */
#define	CP0_DATALOD		$28, 3	/* DataLo Register (Dcache) */
#define	CP0_TAGHI		$29, 2	/* TagHi Register */
#define	CP0_DATAHII		$29, 1	/* DataHi Register (Icache) */
#define	CP0_DATAHID		$29, 3	/* DataHi Register (Dcache) */
#define	CP0_CVMCTL		$9, 7	/* CvmCtl Register */
#define	CP0_CVMMEMCTL		$11, 7	/* CvmMemCtl Register */
#define	CP0_CVMCNT		$9, 6	/* CvmCount Register */
#define	CP0_MCD			$22	/* Multi-Core Debug Register */
#endif

/* ---- register bits */

/* Index Register */

#define	CP0_INDEX_P				UINT32_C(0x80000000)
#define	CP0_INDEX_XXX_30_5			0x7fffffe0
#define	CP0_INDEX_INDEX				0x0000001f

/* Random Register */

#define	CP0_RANDOM_XXX_31_5			0xffffffe0
#define	CP0_RANDOM_RANDOM			0x0000001f

/* EntryLo0, EntryLo1 Registers */

#define	CP0_ENTRYLON_FILL			UINT64_C(0xfffff80000000000)
#define	CP0_ENTRYLON_PFNX			UINT64_C(0x000007ffc0000000)
#define	CP0_ENTRYLON_PFN			UINT64_C(0x000000003fffffc0)
#define	CP0_ENTRYLON_C				UINT64_C(0x0000000000000038)
#define	CP0_ENTRYLON_D				UINT64_C(0x0000000000000004)
#define	CP0_ENTRYLON_V				UINT64_C(0x0000000000000002)
#define	CP0_ENTRYLON_G				UINT64_C(0x0000000000000001)

/* Context Register */

#define	CP0_CONTEXT_PTEBASE			UINT64_C(0xffffffffff800000)
#define	CP0_CONTEXT_BADVPN2			UINT64_C(0x00000000007ffff0)
#define	CP0_CONTEXT_XXX_3_0			UINT64_C(0x000000000000000f)

/* PageMask Register */

#define	CP0_PAGEMASK_XXX_31_29			UINT64_C(0xe000000000000000)
#define	CP0_PAGEMASK_MASK			UINT64_C(0x1fffffffffffe000)
#define	CP0_PAGEMASK_MASKX			UINT64_C(0x0000000000001800)
#define	CP0_PAGEMASK_XXX_10_0			UINT64_C(0x0000000000000fff)

/* PageGrain Register */

#define	CP0_PAGEGRAIN_ASE			0xc0000000
#define	CP0_PAGEGRAIN_ELPA			UINT32_C(0x20000000)
#define	CP0_PAGEGRAIN_ESP			UINT32_C(0x10000000)
#define	CP0_PAGEGRAIN_XXX_27_13			0x0fffe000
#define	CP0_PAGEGRAIN_XXX_7_0			0x000000ff

/* Wired Register */

#define	CP0_WIRED_XXX_31_5			UINT64_C(0xffffffffffffffe0)
#define	CP0_WIRED_WIRED				UINT64_C(0x000000000000001f)

/* HWREna Register */

#define	CP0_HWRENA_MASKX			0xc0000000
#define	CP0_HWRENA_XXX_29_4			0x3ffffff0
#define	CP0_HWRENA_MASK				0x0000000f

/* BadVAddr Register */

/* Count Register */

/* EntryHi Register */

#define	CP0_ENTRYHI_R				UINT64_C(0xc000000000000000)
#define	CP0_ENTRYHI_FILL			UINT64_C(0x3ffe000000000000)
#define	CP0_ENTRYHI_VPN2			UINT64_C(0x0001ffffffffe000)
#define	CP0_ENTRYHI_VPN2X			UINT64_C(0x0000000000001800)
#define	CP0_ENTRYHI_XXX_10_8			UINT64_C(0x0000000000000700)
#define	CP0_ENTRYHI_ASID			UINT64_C(0x00000000000000ff)

/* Compare Register */

/* Status Register */

#define	CP0_STATUS_CU3				UINT32_C(0x80000000)
#define	CP0_STATUS_CU2				UINT32_C(0x40000000)
#define	CP0_STATUS_CU1				UINT32_C(0x20000000)
#define	CP0_STATUS_CU0				UINT32_C(0x10000000)
#define	CP0_STATUS_RP				UINT32_C(0x08000000)
#define	CP0_STATUS_FR				UINT32_C(0x04000000)
#define	CP0_STATUS_RE				UINT32_C(0x02000000)
#define	CP0_STATUS_MX				UINT32_C(0x01000000)
#define	CP0_STATUS_PX				UINT32_C(0x00800000)
#define	CP0_STATUS_BEV				UINT32_C(0x00400000)
#define	CP0_STATUS_TS				UINT32_C(0x00200000)
#define	CP0_STATUS_SR				UINT32_C(0x00100000)
#define	CP0_STATUS_NMI				UINT32_C(0x00080000)
#define	CP0_STATUS_XXX_18_16			0x00070000
#define	CP0_STATUS_IM_7_4			0x0000fc00
#define	CP0_STATUS_IM_1_0			0x00000300
#define	CP0_STATUS_KX				UINT32_C(0x00000080)
#define	CP0_STATUS_SX				UINT32_C(0x00000040)
#define	CP0_STATUS_UX				UINT32_C(0x00000020)
#define	CP0_STATUS_KSU				0x00000018
#define	CP0_STATUS_ERL				UINT32_C(0x00000004)
#define	CP0_STATUS_EXL				UINT32_C(0x00000002)
#define	CP0_STATUS_IE				UINT32_C(0x00000001)

/* IntCtl Register */

#define	CP0_INTCTL_IPTI				0xe0000000
#define	CP0_INTCTL_IPPCI			0x1c000000
#define	CP0_INTCTL_XXX_25_10			0x03fffc00
#define	CP0_INTCTL_VS				0x000003e0
#define	CP0_INTCTL_XXX_4_0			0x0000001f

/* SRSCtl Register */

#define	CP0_SRSCTL_XXX_31_30			0xc0000000
#define	CP0_SRSCTL_HSS				0x3c000000
#define	CP0_SRSCTL_XXX_25_22			0x03c00000
#define	CP0_SRSCTL_EICSS			0x003c0000
#define	CP0_SRSCTL_XXX_17_16			0x00030000
#define	CP0_SRSCTL_ESS				0x0000f000
#define	CP0_SRSCTL_XXX_11_10			0x00000c00
#define	CP0_SRSCTL_EXL				0x000003c0
#define	CP0_SRSCTL_XXX_5_4			0x00000030
#define	CP0_SRSCTL_CSS				0x0000000f

/* Cause Register */

#define	CP0_CAUSE_BD				UINT32_C(0x80000000)
#define	CP0_CAUSE_TI				UINT32_C(0x40000000)
#define	CP0_CAUSE_CE				0x30000000
#define	CP0_CAUSE_DC				UINT32_C(0x08000000)
#define	CP0_CAUSE_PCI				UINT32_C(0x04000000)
#define	CP0_CAUSE_XXX_25_24			0x03000000
#define	CP0_CAUSE_IV				UINT32_C(0x00800000)
#define	CP0_CAUSE_WP				UINT32_C(0x00400000)
#define	CP0_CAUSE_XXX_21_16			0x003f0000
#define	CP0_CAUSE_IP_7_4			0x0000f000
#define	CP0_CAUSE_IP_3_2			0x00000c00
#define	CP0_CAUSE_IP_1_0			0x00000300
#define	CP0_CAUSE_XXX_7				UINT32_C(0x00000080)
#define	CP0_CAUSE_EXCCODE			0x0000007c
#define	CP0_CAUSE_XXX_1_0			0x00000003

/* Exception Program Counter */

/* PRId Register */

#define	CP0_PRID_COMPANY_OPTIONS		0xff000000
#define	CP0_PRID_COMPANY_ID			0x00ff0000
#define	CP0_PRID_PROCESSOR_ID			0x0000ff00
#define	CP0_PRID_REVISION			0x000000ff

/* EBase Register */

#define	CP0_EBASE_ALWAYS			UINT32_C(0x80000000)
#define	CP0_EBASE_XXX_30			UINT32_C(0x40000000)
#define	CP0_EBASE_EXCEPTION_BASE		0x3ffff000
#define	CP0_EBASE_XXX_11_10			0x00000c00
#define	CP0_EBASE_CPU_NUM			0x000003ff

/* Config Register */

#define	CP0_CONFIG_M				UINT32_C(0x80000000)
#define	CP0_CONFIG_IMPL				0x7fff0000
#define	CP0_CONFIG_BE				UINT32_C(0x00008000)
#define	CP0_CONFIG_AT				0x00006000
#define	CP0_CONFIG_AR				0x00001c00
#define	CP0_CONFIG_MT				0x00000380
#define	CP0_CONFIG_XXX_6_4			0x00000070
#define	CP0_CONFIG_VI				UINT32_C(0x00000008)
#define	CP0_CONFIG_KO				0x00000007

/* Config1 Register */

#define	CP0_CONFIG1_M				UINT32_C(0x10000000)
#define	CP0_CONFIG1_MMUSIZE_1			0x7e000000
#define	CP0_CONFIG1_IS				0x01c00000
#define	CP0_CONFIG1_IL				0x00380000
#define	CP0_CONFIG1_IA				0x00070000
#define	CP0_CONFIG1_DS				0x0000e000
#define	CP0_CONFIG1_DL				0x00001c00
#define	CP0_CONFIG1_DA				0x00000380
#define	CP0_CONFIG1_C2				UINT32_C(0x00000040)
#define	CP0_CONFIG1_MD				UINT32_C(0x00000020)
#define	CP0_CONFIG1_PC				UINT32_C(0x00000010)
#define	CP0_CONFIG1_WR				UINT32_C(0x00000008)
#define	CP0_CONFIG1_CA				UINT32_C(0x00000004)
#define	CP0_CONFIG1_EP				UINT32_C(0x00000002)
#define	CP0_CONFIG1_FP				UINT32_C(0x00000001)

/* Config2 Register */

#define	CP0_CONFIG2_M				UINT32_C(0x80000000)
#define	CP0_CONFIG2_TU				0x70000000
#define	CP0_CONFIG2_TS				0x0f000000
#define	CP0_CONFIG2_TL				0x00f00000
#define	CP0_CONFIG2_TA				0x000f0000
#define	CP0_CONFIG2_SU				0x0000f000
#define	CP0_CONFIG2_SS				0x00000f00
#define	CP0_CONFIG2_SL				0x000000f0
#define	CP0_CONFIG2_SA				0x0000000f

/* Config3 Register */

#define	CP0_CONFIG3_M				UINT32_C(0x80000000)
#define	CP0_CONFIG3_XXX_30_8			0x7fffff00
#define	CP0_CONFIG3_LPA				UINT32_C(0x00000080)
#define	CP0_CONFIG3_VEIC			UINT32_C(0x00000040)
#define	CP0_CONFIG3_VINT			UINT32_C(0x00000020)
#define	CP0_CONFIG3_SP				UINT32_C(0x00000010)
#define	CP0_CONFIG3_XXX_3_2			0x0000000c
#define	CP0_CONFIG3_SM				UINT32_C(0x00000002)
#define	CP0_CONFIG3_TL				UINT32_C(0x00000001)

/* WatchLo Register */

#define	CP0_WATCHLO_VADDR			UINT64_C(0xfffffffffffffff8)
#define	CP0_WATCHLO_I				UINT64_C(0x0000000000000004)
#define	CP0_WATCHLO_R				UINT64_C(0x0000000000000002)
#define	CP0_WATCHLO_W				UINT64_C(0x0000000000000001)

/* WatchHi Register */

#define	CP0_WATCHHI_M				UINT32_C(0x80000000)
#define	CP0_WATCHHI_G				UINT32_C(0x40000000)
#define	CP0_WATCHHI_XXX_29_24			0x3f000000
#define	CP0_WATCHHI_ASID			0x00ff0000
#define	CP0_WATCHHI_XXX_15_12			0x0000f000
#define	CP0_WATCHHI_MASK			0x00000ff8
#define	CP0_WATCHHI_I				UINT32_C(0x00000004)
#define	CP0_WATCHHI_R				UINT32_C(0x00000002)
#define	CP0_WATCHHI_W				UINT32_C(0x00000001)

/* XContext Register */

#define	CP0_XCONTEXT_PTEBASE			UINT64_C(0xfffffc0000000000)
#define	CP0_XCONTEXT_R				UINT64_C(0x0000030000000000)
#define	CP0_XCONTEXT_BADVPN2			UINT64_C(0x000000fffffffff0)
#define	CP0_XCONTEXT_XXX_3_0			UINT64_C(0x000000000000000f)

/* Debug Register */

#define	CP0_DEBUG_DBD				UINT32_C(0x80000000)
#define	CP0_DEBUG_DM				UINT32_C(0x40000000)
#define	CP0_DEBUG_NODCR				UINT32_C(0x20000000)
#define	CP0_DEBUG_LSNM				UINT32_C(0x10000000)
#define	CP0_DEBUG_DOZE				UINT32_C(0x08000000)
#define	CP0_DEBUG_HALT				UINT32_C(0x04000000)
#define	CP0_DEBUG_COUNTDM			UINT32_C(0x02000000)
#define	CP0_DEBUG_IBUSEP			UINT32_C(0x01000000)
#define	CP0_DEBUG_MCHECKP			UINT32_C(0x00800000)
#define	CP0_DEBUG_CACHEEP			UINT32_C(0x00400000)
#define	CP0_DEBUG_DBUSEP			UINT32_C(0x00200000)
#define	CP0_DEBUG_IEXI				UINT32_C(0x00100000)
#define	CP0_DEBUG_DDBSIMPR			UINT32_C(0x00080000)
#define	CP0_DEBUG_DDBLIMPR			UINT32_C(0x00040000)
#define	CP0_DEBUG_EJTAG				0x00038000
#define	CP0_DEBUG_DEXCCODE			0x00007c00
#define	CP0_DEBUG_NOSST				UINT32_C(0x00000200)
#define	CP0_DEBUG_SST				UINT32_C(0x00000100)
#define	CP0_DEBUG_XXX_7_6			0x000000c0
#define	CP0_DEBUG_DINT				UINT32_C(0x00000020)
#define	CP0_DEBUG_DIB				UINT32_C(0x00000010)
#define	CP0_DEBUG_DDBS				UINT32_C(0x00000008)
#define	CP0_DEBUG_DDBL				UINT32_C(0x00000004)
#define	CP0_DEBUG_DBP				UINT32_C(0x00000002)
#define	CP0_DEBUG_DSS				UINT32_C(0x00000001)

/* Debug Exception Program Counter Register */

/* Performance Counter Control Register */

#define	CP0_PCCTL_M				UINT32_C(0x80000000)
#define	CP0_PCCTL_W				UINT32_C(0x40000000)
#define	CP0_PCCTL_XXX_29_11			0x3ffff800
#define	CP0_PCCTL_EVENT				0x000007e0
#define	CP0_PCCTL_IE				UINT32_C(0x00000010)
#define	CP0_PCCTL_U				UINT32_C(0x00000008)
#define	CP0_PCCTL_S				UINT32_C(0x00000004)
#define	CP0_PCCTL_K				UINT32_C(0x00000002)
#define	CP0_PCCTL_EXL				UINT32_C(0x00000001)

/* Performance Counter Counter Register */

/* ErrorEPC */

/* DESAVE Register */

/*
 * Cavium Networks-Specific Coprocessor 0 Register
 */

/* CacheErr (Icache) */

#define	CP0_CACHEERRI_XXX_63_55			UINT64_C(0xff80000000000000)
#define	CP0_CACHEERRI_BADCOLF			UINT64_C(0x007f000000000000)
#define	CP0_CACHEERRI_XXX_47			UINT64_C(0x0000800000000000)
#define	CP0_CACHEERRI_BADCOL			UINT64_C(0x00007f0000000000)
#define	CP0_CACHEERRI_XXX_39_37			UINT64_C(0x000000e000000000)
#define	CP0_CACHEERRI_LRUFAIL			UINT64_C(0x0000001000000000)
#define	CP0_CACHEERRI_AESFAIL			UINT64_C(0x0000000800000000)
#define	CP0_CACHEERRI_HSHFAIL			UINT64_C(0x0000000400000000)
#define	CP0_CACHEERRI_BHTBROKE			UINT64_C(0x0000000200000000)
#define	CP0_CACHEERRI_ICBROKE			UINT64_C(0x0000000100000000)
#define	CP0_CACHEERRI_XXX_31_15			UINT64_C(0x00000000ffff8000)
#define	CP0_CACHEERRI_QW			UINT64_C(0x0000000000006000)
#define	CP0_CACHEERRI_ROW			UINT64_C(0x0000000000001800)
#define	CP0_CACHEERRI_SET			UINT64_C(0x00000000000007e0)
#define	CP0_CACHEERRI_WAY			UINT64_C(0x0000000000000018)
#define	CP0_CACHEERRI_XXX_2_1			UINT64_C(0x0000000000000006)
#define	CP0_CACHEERRI_DPERR			UINT64_C(0x0000000000000001)

/* CacheErr (Dcache) */

#define	CP0_CACHEERRD_XXX_63_13			UINT64_C(0xffffffffffffe000)
#define	CP0_CACHEERRD_SET			UINT64_C(0x0000000000001f80)
#define	CP0_CACHEERRD_VA63			UINT64_C(0x0000000000000078)
#define	CP0_CACHEERRD_XXX_2_1			UINT64_C(0x0000000000000006)
#define	CP0_CACHEERRD_PERR			UINT64_C(0x0000000000000001)

/* TagLo Register (Icache) */

#define	CP0_TAGLOI_R				UINT64_C(0xc000000000000000)
#define	CP0_TAGLOI_XXX_61_60			UINT64_C(0x3000000000000000)
#define	CP0_TAGLOI_ASID				UINT64_C(0x0f00000000000000)
#define	CP0_TAGLOI_XXX_51_49			UINT64_C(0x00f0000000000000)
#define	CP0_TAGLOI_TAG				UINT64_C(0x000fffffffffe000)
#define	CP0_TAGLOI_INDEX			UINT64_C(0x0000000000001f80)
#define	CP0_TAGLOI_XXX_6_2			UINT64_C(0x000000000000007c)
#define	CP0_TAGLOI_G				UINT64_C(0x0000000000000002)
#define	CP0_TAGLOI_VALID			UINT64_C(0x0000000000000001)

/* TagLo Register (Dcache) */

#define	CP0_TAGLOD_R				UINT64_C(0xc000000000000000)
#define	CP0_TAGLOD_XXX_61_60			UINT64_C(0x3000000000000000)
#define	CP0_TAGLOD_ASID				UINT64_C(0x0f00000000000000)
#define	CP0_TAGLOD_XXX_51_49			UINT64_C(0x00f0000000000000)
#define	CP0_TAGLOD_TAG				UINT64_C(0x000fffffffffff80)
#define	CP0_TAGLOD_XXX_6_2			UINT64_C(0x000000000000007c)
#define	CP0_TAGLOD_G				UINT64_C(0x0000000000000002)
#define	CP0_TAGLOD_VALID			UINT64_C(0x0000000000000001)

/* DataLo Register (Icache) */

/* DataLo Register (Dcache) */

/* TagHi Register */

#define	CP0_TAGHI_XXX_63_36			UINT64_C(0xfffffff000000000)
#define	CP0_TAGHI_PTAG				UINT64_C(0x0000000fffffff80)
#define	CP0_TAGHI_XXX_6_1			UINT64_C(0x000000000000007e)
#define	CP0_TAGHI_VALID				UINT64_C(0x0000000000000001)

/* DataHi Register (Icache) */

#define	CP0_DATAHII_XXX_63_8			UINT64_C(0xffffffffffffff00)
#define	CP0_DATAHII_PAR				UINT64_C(0x00000000000000ff)

/* DataHi Register (Dcache) */

#define	CP0_DATAHID_XXX_63_8			UINT64_C(0xffffffffffffff00)
#define	CP0_DATAHID_PAR				UINT64_C(0x00000000000000ff)

/* CvmCtl Register */

#define	CP0_CVMCTL_XXX_63_32			UINT64_C(0xffffffff00000000)
#define	CP0_CVMCTL_FUSE_STARTBIT		UINT64_C(0x0000000080000000)
#define	CP0_CVMCTL_XXX_30			UINT64_C(0x0000000040000000)
#define	CP0_CVMCTL_KASUMI			UINT64_C(0x0000000020000000)
#define	CP0_CVMCTL_NODFA_CP21			UINT64_C(0x0000000010000000)
#define	CP0_CVMCTL_NOMUL			UINT64_C(0x0000000008000000)
#define	CP0_CVMCTL_NOCRYPTO			UINT64_C(0x0000000004000000)
#define	CP0_CVMCTL_RST_SHT			UINT64_C(0x0000000002000000)
#define	CP0_CVMCTL_BIST_DIS			UINT64_C(0x0000000001000000)
#define	CP0_CVMCTL_DISSETPRED			UINT64_C(0x0000000000800000)
#define	CP0_CVMCTL_DISJRPRED			UINT64_C(0x0000000000400000)
#define	CP0_CVMCTL_DISICACHE			UINT64_C(0x0000000000200000)
#define	CP0_CVMCTL_DISWAIT			UINT64_C(0x0000000000100000)
#define	CP0_CVMCTL_DEFET			UINT64_C(0x0000000000080000)
#define	CP0_CVMCTL_DISCO			UINT64_C(0x0000000000040000)
#define	CP0_CVMCTL_DISCE			UINT64_C(0x0000000000020000)
#define	CP0_CVMCTL_DDCLK			UINT64_C(0x0000000000010000)
#define	CP0_CVMCTL_DCICLK			UINT64_C(0x0000000000008000)
#define	CP0_CVMCTL_REPUN			UINT64_C(0x0000000000004000)
#define	CP0_CVMCTL_IPREF			UINT64_C(0x0000000000002000)
#define	CP0_CVMCTL_USEUN			UINT64_C(0x0000000000001000)
#define	CP0_CVMCTL_DISIOCACHE			UINT64_C(0x0000000000000800)
#define	CP0_CVMCTL_IRAND			UINT64_C(0x0000000000000400)
#define	CP0_CVMCTL_IPPCI			UINT64_C(0x0000000000000380)
#define	CP0_CVMCTL_IPTI				UINT64_C(0x0000000000000070)
#define	CP0_CVMCTL_XXX_3_2			UINT64_C(0x000000000000000c)
#define	CP0_CVMCTL_LE				UINT64_C(0x0000000000000002)
#define	CP0_CVMCTL_USELY			UINT64_C(0x0000000000000001)

#define	CP0_CVMCTL_BITS \
	"\177"		/* new format */ \
	"\020"		/* hex display */ \
	"\020"		/* %016x format */ \
	"b\x1f"		"FUSE_STARTBIT\0" \
	"b\x1c"		"NODFA_CP21\0" \
	"b\x1b"		"NOMUL\0" \
	"b\x1a"		"NOCRYPTO\0" \
	"b\x19"		"RST_SHT\0" \
	"b\x18"		"BIST_DIS\0" \
	"b\x17"		"DISSETPRED\0" \
	"b\x16"		"DISJRPRED\0" \
	"b\x15"		"DISICACHE\0" \
	"b\x14"		"DISWAIT\0" \
	"b\x13"		"DEFET\0" \
	"b\x12"		"DISCO\0" \
	"b\x11"		"DISCE\0" \
	"b\x10"		"DDCLK\0" \
	"b\x0f"		"DCICLK\0" \
	"b\x0e"		"REPUN\0" \
	"b\x0d"		"IPREF\0" \
	"b\x0c"		"USEUN\0" \
	"b\x0b"		"DISIOCACHE\0" \
	"b\x0a"		"IRAND\0" \
	"f\x07\x03"	"IPPCI\0" \
	"f\x04\x03"	"IPTI\0" \
	"b\x01"		"LE\0" \
	"b\x00"		"USELY\0"

/* CvmMemCtl Register */

#define	CP0_CVMMEMCTL_TLBBIST			UINT64_C(0x8000000000000000)
#define	CP0_CVMMEMCTL_L1CBIST			UINT64_C(0x4000000000000000)
#define	CP0_CVMMEMCTL_L1DBIST			UINT64_C(0x2000000000000000)
#define	CP0_CVMMEMCTL_DCMBIST			UINT64_C(0x1000000000000000)
#define	CP0_CVMMEMCTL_PTGBIST			UINT64_C(0x0800000000000000)
#define	CP0_CVMMEMCTL_WBFBIST			UINT64_C(0x0400000000000000)
#define	CP0_CVMMEMCTL_XXX_57_36			UINT64_C(0x03fffff000000000)
#define	CP0_CVMMEMCTL_DISMARKWBLONGTO		UINT64_C(0x0000000800000000)
#define	CP0_CVMMEMCTL_DISMRGCLRWBTO		UINT64_C(0x0000000400000000)
#define	CP0_CVMMEMCTL_IOBDMASCRMSB		UINT64_C(0x0000000300000000)
#define	CP0_CVMMEMCTL_SYNCWSMARKED		UINT64_C(0x0000000080000000)
#define	CP0_CVMMEMCTL_DISSYNCWS			UINT64_C(0x0000000040000000)
#define	CP0_CVMMEMCTL_DISWBFST			UINT64_C(0x0000000020000000)
#define	CP0_CVMMEMCTL_XKMEMENAS			UINT64_C(0x0000000010000000)
#define	CP0_CVMMEMCTL_XKMEMENAU			UINT64_C(0x0000000008000000)
#define	CP0_CVMMEMCTL_XKIOENAS			UINT64_C(0x0000000004000000)
#define	CP0_CVMMEMCTL_XKIOENAU			UINT64_C(0x0000000002000000)
#define	CP0_CVMMEMCTL_ALLSYNCW			UINT64_C(0x0000000001000000)
#define	CP0_CVMMEMCTL_NOMERGE			UINT64_C(0x0000000000800000)
#define	CP0_CVMMEMCTL_DIDTTO			UINT64_C(0x0000000000600000)
#define	CP0_CVMMEMCTL_CSRCLKALWYS		UINT64_C(0x0000000000100000)
#define	CP0_CVMMEMCTL_MCLKALWYS			UINT64_C(0x0000000000080000)
#define	CP0_CVMMEMCTL_WBFLTIME			UINT64_C(0x0000000000070000)
#define	CP0_CVMMEMCTL_ISTRNOL2			UINT64_C(0x0000000000008000)
#define	CP0_CVMMEMCTL_WBTHRESH			UINT64_C(0x0000000000007800)
#define	CP0_CVMMEMCTL_XXX_10_9			UINT64_C(0x0000000000000600)
#define	CP0_CVMMEMCTL_CVMSEGENAK		UINT64_C(0x0000000000000100)
#define	CP0_CVMMEMCTL_CVMSEGENAS		UINT64_C(0x0000000000000080)
#define	CP0_CVMMEMCTL_CVMSEGENAU		UINT64_C(0x0000000000000040)
#define	CP0_CVMMEMCTL_LMEMSZ			UINT64_C(0x000000000000003f)

#define	CP0_CVMMEMCTL_BITS \
	"\177"		/* new format */ \
	"\020"		/* hex display */ \
	"\020"		/* %016x format */ \
	"b\x3f"		"TLBBIST\0" \
	"b\x3e"		"L1CBIST\0" \
	"b\x3d"		"L1DBIST\0" \
	"b\x3c"		"DCMBIST\0" \
	"b\x3b"		"PTGBIST\0" \
	"b\x3a"		"WBFBIST\0" \
	"b\x23"		"DISMARKWBLONGTO\0" \
	"b\x22"		"DISMRGCLRWBTO\0" \
	"f\x20\x02"	"IOBDMASCRMSB\0" \
	"b\x1f"		"SYNCWSMARKED\0" \
	"b\x1e"		"DISSYNCWS\0" \
	"b\x1d"		"DISWBFST\0" \
	"b\x1c"		"XKMEMENAS\0" \
	"b\x1b"		"XKMEMENAU\0" \
	"b\x1a"		"XKIOENAS\0" \
	"b\x19"		"XKIOENAU\0" \
	"b\x18"		"ALLSYNCW\0" \
	"b\x17"		"NOMERGE\0" \
	"f\x15\x02"	"DIDTTO\0" \
	"b\x14"		"CSRCLKALWYS\0" \
	"b\x13"		"MCLKALWYS\0" \
	"f\x10\x03"	"WBFLTIME\0" \
	"b\x0f"		"ISTRNOL2\0" \
	"f\x0b\x04"	"WBTHRESH\0" \
	"b\x08"		"CVMSEGENAK\0" \
	"b\x07"		"CVMSEGENAS\0" \
	"b\x06"		"CVMSEGENAU\0" \
	"f\x00\x06"	"LMEMSZ\0"

/* CvmCount Register */

/* Multi-Core Debug Register */

#define	CP0_MCD_XXX_63_17			UINT64_C(0xfffffffffffe0000)
#define	CP0_MCD_DEXCC				UINT64_C(0x0000000000010000)
#define	CP0_MCD_CGSTP				UINT64_C(0x0000000000008000)
#define	CP0_MCD_CVGSTP				UINT64_C(0x0000000000004000)
#define	CP0_MCD_CVDM				UINT64_C(0x0000000000002000)
#define	CP0_MCD_GSDB				UINT64_C(0x0000000000001000)
#define	CP0_MCD_XXX_11				UINT64_C(0x0000000000000800)
#define	CP0_MCD_MSKM2				UINT64_C(0x0000000000000400)
#define	CP0_MCD_MSKM1				UINT64_C(0x0000000000000200)
#define	CP0_MCD_MMC0				UINT64_C(0x0000000000000100)
#define	CP0_MCD_XXX_7				UINT64_C(0x0000000000000080)
#define	CP0_MCD_PLS2				UINT64_C(0x0000000000000040)
#define	CP0_MCD_PLS1				UINT64_C(0x0000000000000020)
#define	CP0_MCD_PLS0				UINT64_C(0x0000000000000010)
#define	CP0_MCD_XXX_3				UINT64_C(0x0000000000000008)
#define	CP0_MCD_MCD2				UINT64_C(0x0000000000000004)
#define	CP0_MCD_MCD1				UINT64_C(0x0000000000000002)
#define	CP0_MCD_MCD0				UINT64_C(0x0000000000000001)

/*
 * Core EJTAG DRSEG Registers
 */

/* XXX */

/*
 * Core EJTAG TAP Registers
 */

/* XXX */

/* ---- operations */

/* XXX */

/*
 * OCTEON Configuration and Status Registers (CSRs)
 */

#define	CSR_COP0			/* Core coprosessor 0 registers */
#define	CSR_COP2			/* Core coprosessor 2 registers */
#define	CSR_COREEJTAG			/* Core EJTAG registers */
#define	CSR_COREEJTAGTAP		/* Core EJTAG TAP registers */
#define	CSR_NCB				/* NCB registers */
#define	CSR_RSL				/* RSL registers */
#define	CSR_PCICONFIG			/* PCICONFIG registers */
#define	CSR_PCI				/* PCI registers */
#define	CSR_PCINCB			/* PCI_NCB registers */
#define	CSR_JTAGTAP			/* JTAG TAP registers */
#define	CSR_TWSICORE			/* TWSI Core registers */

/* XXX */

#endif /* _OCTEON_COREREG_H_ */
