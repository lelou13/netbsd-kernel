/*	$NetBSD: exynos5_loc.c,v 1.12 2014/09/05 08:01:05 skrll Exp $	*/

/*-
 * Copyright (c) 2014 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Nick Hudson
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
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <arm/samsung/exynos_io.h>
#include <arm/samsung/exynos_intr.h>

#include <arm/samsung/exynos5_reg.h>

#define IRQ_RP_TIMER			IRQ_SPI(127)
#define IRQ_CAM_B			IRQ_SPI(126)
#define IRQ_CAM_A			IRQ_SPI(125)
#define IRQ_MDMA1			IRQ_SPI(124)
#define IRQ_MCT_L1			IRQ_SPI(121)
#define IRQ_MCT_L0			IRQ_SPI(120)
#define IRQ_G3D_IRQMMU			IRQ_SPI(119)
#define IRQ_G3D_IRQJOB			IRQ_SPI(118)
#define IRQ_G3D_IRQGPU			IRQ_SPI(117)
#define IRQ_SATA			IRQ_SPI(115)
#define IRQ_CEC				IRQ_SPI(114)
#define IRQ_DP1_1			IRQ_SPI(113)
#define IRQ_INTFEEDCTRL_SSS		IRQ_SPI(112)
#define IRQ_PMU				IRQ_SPI(111)
#define IRQ_CAM_C			IRQ_SPI(110)
#define IRQ_SATAPMEREQ			IRQ_SPI(109)
#define IRQ_SATAPHY			IRQ_SPI(108)
#define IRQ_ADC0			IRQ_SPI(106)
#define IRQ_SPDIF			IRQ_SPI(105)
#define IRQ_PCM2			IRQ_SPI(104)
#define IRQ_PCM1			IRQ_SPI(103)
#define IRQ_PCM0			IRQ_SPI(102)
#define IRQ_AC97			IRQ_SPI(101)
#define IRQ_I2S2			IRQ_SPI(100)
#define IRQ_I2S1			IRQ_SPI(99)
#define IRQ_I2S0			IRQ_SPI(98)
#define IRQ_AUDIO_SS			IRQ_SPI(97)
#define IRQ_MFC				IRQ_SPI(96)
#define IRQ_HDMI			IRQ_SPI(95)
#define IRQ_MIXER			IRQ_SPI(94)
#define IRQ_EFNFCON_1			IRQ_SPI(93)
#define IRQ_EFNFCON_0			IRQ_SPI(92)
#define IRQ_G2D				IRQ_SPI(91)
#define IRQ_EFNFCON_DMA			IRQ_SPI(90)
#define IRQ_JPEG			IRQ_SPI(89)
#define IRQ_GSCL3			IRQ_SPI(88)
#define IRQ_GSCL2			IRQ_SPI(87)
#define IRQ_GSCL1			IRQ_SPI(86)
#define IRQ_GSCL0			IRQ_SPI(85)
#define IRQ_ROTATOR			IRQ_SPI(84)
#define IRQ_WDT_IOP			IRQ_SPI(83)
#define IRQ_MIPI_DSI_4LANE		IRQ_SPI(82)
#define IRQ_EFNFCON_DMA_ABORT		IRQ_SPI(81)
#define IRQ_MIPI_CSI_B			IRQ_SPI(80)
#define IRQ_MIPI_CSI_A			IRQ_SPI(79)
#define IRQ_SDMMC3			IRQ_SPI(78)
#define IRQ_SDMMC2			IRQ_SPI(77)
#define IRQ_SDMMC1			IRQ_SPI(76)
#define IRQ_SDMMC0			IRQ_SPI(75)
#define IRQ_USBOTG			IRQ_SPI(74)
#define IRQ_MIPI_HSI			IRQ_SPI(73)
#define IRQ_USB_DRD30			IRQ_SPI(72)
#define IRQ_USB_HOST20			IRQ_SPI(71)
#define IRQ_SPI2			IRQ_SPI(70)
#define IRQ_SPI1			IRQ_SPI(69)
#define IRQ_SPI0			IRQ_SPI(68)
#define IRQ_CPU_NFIQ_1			IRQ_SPI(67)
#define IRQ_CPU_NFIQ_0			IRQ_SPI(66)
#define IRQ_TMU				IRQ_SPI(65)
#define IRQ_HDMI_I2C			IRQ_SPI(64)
#define IRQ_I2C7			IRQ_SPI(63)
#define IRQ_I2C6			IRQ_SPI(62)
#define IRQ_I2C5			IRQ_SPI(61)
#define IRQ_I2C4			IRQ_SPI(60)
#define IRQ_I2C3_USI3			IRQ_SPI(59)
#define IRQ_I2C2_USI2			IRQ_SPI(58)
#define IRQ_I2C1_USI1			IRQ_SPI(57)
#define IRQ_I2C0_USI0			IRQ_SPI(56)
#define IRQ_MONOCNT			IRQ_SPI(55)
#define IRQ_UART3			IRQ_SPI(54)
#define IRQ_UART2			IRQ_SPI(53)
#define IRQ_UART1			IRQ_SPI(52)
#define IRQ_UART0			IRQ_SPI(51)
#define IRQ_GPIO_C2C			IRQ_SPI(50)
#define IRQ_GPIO			IRQ_SPI(47)
#define IRQ_GPIO_LB			IRQ_SPI(46)
#define IRQ_GPIO_RT			IRQ_SPI(45)
#define IRQ_RTC_TIC			IRQ_SPI(44)
#define IRQ_RTC_ALARM			IRQ_SPI(43)
#define IRQ_WDT				IRQ_SPI(42)
#define IRQ_RTIC			IRQ_SPI(41)
#define IRQ_TIMER4			IRQ_SPI(40)
#define IRQ_TIMER3			IRQ_SPI(39)
#define IRQ_TIMER2			IRQ_SPI(38)
#define IRQ_TIMER1			IRQ_SPI(37)
#define IRQ_TIMER0			IRQ_SPI(36)
#define IRQ_PDMA1			IRQ_SPI(35)
#define IRQ_PDMA0			IRQ_SPI(34)
#define IRQ_MDMA0_CORE			IRQ_SPI(33)

#define IRQ_SYSMMU_DRCISP_1		EXYNOS_COMBINERIRQ(11, 7)
#define IRQ_SYSMMU_ODC_1		EXYNOS_COMBINERIRQ(11, 1)
#define IRQ_SYSMMU_ODC_0		EXYNOS_COMBINERIRQ(11, 0)

#define IRQ_SYSMMU_ISP_1		EXYNOS_COMBINERIRQ(10, 7)
#define IRQ_SYSMMU_ISP_0		EXYNOS_COMBINERIRQ(10, 6)
#define IRQ_SYSMMU_DIS0_1		EXYNOS_COMBINERIRQ(10, 5)
#define IRQ_SYSMMU_DIS0_0		EXYNOS_COMBINERIRQ(10, 4)
#define IRQ_DP1				EXYNOS_COMBINERIRQ(10, 3)

#define IRQ_SYSMMU_DIS1_1		EXYNOS_COMBINERIRQ(9, 5)
#define IRQ_SYSMMU_DIS1_0		EXYNOS_COMBINERIRQ(9, 4)

#define IRQ_SYSMMU_MFCL_1		EXYNOS_COMBINERIRQ(8, 6)
#define IRQ_SYSMMU_MFCL_0		EXYNOS_COMBINERIRQ(8, 5)

#define IRQ_SYSMMU_TV_M0_1		EXYNOS_COMBINERIRQ(7, 5)
#define IRQ_SYSMMU_TV_M0_0		EXYNOS_COMBINERIRQ(7, 4)
#define IRQ_SYSMMU_MDMA1_1		EXYNOS_COMBINERIRQ(7, 3)
#define IRQ_SYSMMU_MDMA1_0		EXYNOS_COMBINERIRQ(7, 2)
#define IRQ_SYSMMU_MDMA0_1		EXYNOS_COMBINERIRQ(7, 1)
#define IRQ_SYSMMU_MDMA0_0		EXYNOS_COMBINERIRQ(7, 0)

#define IRQ_SYSMMU_SSS_1		EXYNOS_COMBINERIRQ(6, 7)
#define IRQ_SYSMMU_SSS_0		EXYNOS_COMBINERIRQ(6, 6)
#define IRQ_SYSMMU_RTIC_1		EXYNOS_COMBINERIRQ(6, 5)
#define IRQ_SYSMMU_RTIC_0		EXYNOS_COMBINERIRQ(6, 4)
#define IRQ_SYSMMU_MFCR_1		EXYNOS_COMBINERIRQ(6, 3)
#define IRQ_SYSMMU_MFCR_0		EXYNOS_COMBINERIRQ(6, 2)
#define IRQ_SYSMMU_ARM_1		EXYNOS_COMBINERIRQ(6, 1)

#define IRQ_SYSMMU_ARM_0		EXYNOS_COMBINERIRQ(5, 0)
#define IRQ_SYSMMU_3DNR_1		EXYNOS_COMBINERIRQ(5, 7)
#define IRQ_SYSMMU_3DNR_0		EXYNOS_COMBINERIRQ(5, 6)
#define IRQ_SYSMMU_MCUISP_1		EXYNOS_COMBINERIRQ(5, 5)
#define IRQ_SYSMMU_MCUISP_0		EXYNOS_COMBINERIRQ(5, 4)
#define IRQ_SYSMMU_SCALERCISP_1		EXYNOS_COMBINERIRQ(5, 3)
#define IRQ_SYSMMU_SCALERCISP_0		EXYNOS_COMBINERIRQ(5, 2)
#define IRQ_SYSMMU_FDISP_1		EXYNOS_COMBINERIRQ(5, 1)
#define IRQ_SYSMMU_FDISP_0		EXYNOS_COMBINERIRQ(5, 0)

#define IRQ_MCUIOP_CTIIRQ		EXYNOS_COMBINERIRQ(4, 7)
#define IRQ_MCUIOP_PMUIRQ		EXYNOS_COMBINERIRQ(4, 6)
#define IRQ_MCUISP_CTIIRQ		EXYNOS_COMBINERIRQ(4, 5)
#define IRQ_MCUISP_PMUIRQ		EXYNOS_COMBINERIRQ(4, 4)
#define IRQ_SYSMMU_JPEGX_1		EXYNOS_COMBINERIRQ(4, 3)
#define IRQ_SYSMMU_JPEGX_0		EXYNOS_COMBINERIRQ(4, 2)
#define IRQ_SYSMMU_ROTATOR_1		EXYNOS_COMBINERIRQ(4, 1)
#define IRQ_SYSMMU_ROTATOR_0		EXYNOS_COMBINERIRQ(4, 0)

#define IRQ_SYSMMU_SCALERPISP_1		EXYNOS_COMBINERIRQ(3, 7)
#define IRQ_SYSMMU_SCALERPISP_0		EXYNOS_COMBINERIRQ(3, 6)
#define IRQ_SYSMMU_FIMC_LITE0_1		EXYNOS_COMBINERIRQ(3, 5)
#define IRQ_SYSMMU_FIMC_LITE0_0		EXYNOS_COMBINERIRQ(3, 4)
#define IRQ_SYSMMU_DISP1_M0_1		EXYNOS_COMBINERIRQ(3, 3)
#define IRQ_SYSMMU_DISP1_M0_0		EXYNOS_COMBINERIRQ(3, 2)
#define IRQ_SYSMMU_FIMC_LITE2_1		EXYNOS_COMBINERIRQ(3, 1)
#define IRQ_SYSMMU_FIMC_LITE2_0		EXYNOS_COMBINERIRQ(3, 0)

#define IRQ_SYSMMU_GSCL3_1		EXYNOS_COMBINERIRQ(2, 7)
#define IRQ_SYSMMU_GSCL3_0		EXYNOS_COMBINERIRQ(2, 6)
#define IRQ_SYSMMU_GSCL2_1		EXYNOS_COMBINERIRQ(2, 5)
#define IRQ_SYSMMU_GSCL2_0		EXYNOS_COMBINERIRQ(2, 4)
#define IRQ_SYSMMU_GSCL1_1		EXYNOS_COMBINERIRQ(2, 3)
#define IRQ_SYSMMU_GSCL1_0		EXYNOS_COMBINERIRQ(2, 2)
#define IRQ_SYSMMU_GSCL0_1		EXYNOS_COMBINERIRQ(2, 1)
#define IRQ_SYSMMU_GSCL0_0		EXYNOS_COMBINERIRQ(2, 0)

#define IRQ_CPU_NCNTVIRQ_0		EXYNOS_COMBINERIRQ(1, 7)
#define IRQ_CPU_NCNTPSIRQ_0		EXYNOS_COMBINERIRQ(1, 6)
#define IRQ_CPU_NCNTPSNIRQ_0		EXYNOS_COMBINERIRQ(1, 5)
#define IRQ_CPU_NCNTHPIRQ_0		EXYNOS_COMBINERIRQ(1, 4)
#define IRQ_CPU_NCTIIRQ_0		EXYNOS_COMBINERIRQ(1, 3)
#define IRQ_CPU_NPMUIRQ_0		EXYNOS_COMBINERIRQ(1, 2)
#define IRQ_CPU_PARITYFAILSCU_0		EXYNOS_COMBINERIRQ(1, 1)
#define IRQ_CPU_PARITYFAIL0		EXYNOS_COMBINERIRQ(1, 0)

#define IRQ_TZASC_XR1BXW		EXYNOS_COMBINERIRQ(0, 7)
#define IRQ_TZASC_XR1BXR		EXYNOS_COMBINERIRQ(0, 6)
#define IRQ_TZASC_XLBXW			EXYNOS_COMBINERIRQ(0, 5)
#define IRQ_TZASC_XLBXR			EXYNOS_COMBINERIRQ(0, 4)
#define IRQ_TZASC_DRBXW			EXYNOS_COMBINERIRQ(0, 3)
#define IRQ_TZASC_DRBXR			EXYNOS_COMBINERIRQ(0, 2)
#define IRQ_TZASC_CBXW			EXYNOS_COMBINERIRQ(0, 1)
#define IRQ_TZASC_CBXR			EXYNOS_COMBINERIRQ(0, 0)


#define	OFFANDSIZE(p,n) \
	EXYNOS5##p##_##n##_OFFSET, 0x10000

static const struct exyo_locators exynos5_locators[] = {
	{ "exyogpio", 0, 0, NOPORT, NOINTR, 0 },
	{ "exyoiic", 0, 0, NOPORT, NOINTR, 0 },
	{ "exyowdt", OFFANDSIZE(,WDT), NOPORT, IRQ_WDT, 0 },
	{ "sscom", OFFANDSIZE(,UART0), 0, IRQ_UART0, 0 },
	{ "sscom", OFFANDSIZE(,UART1), 1, IRQ_UART1, 0 },
	{ "sscom", OFFANDSIZE(,UART2), 2, IRQ_UART2, 0 },
	{ "sscom", OFFANDSIZE(,UART3), 3, IRQ_UART3, 0 },
	{ "exyousb", OFFANDSIZE(,USB2HOST), NOPORT, IRQ_USB_HOST20, 0 },
};

const struct exyo_locinfo exynos5_locinfo = {
	.locators = exynos5_locators,
	.nlocators = __arraycount(exynos5_locators)
};


/* flag signal the use of gpio */
static const struct exyo_locators exynos5_i2c_locators[] = {
					/* busname, sdabit, slcbit, func */
	{ "iic0", OFFANDSIZE(,I2C0), 0, IRQ_I2C0_USI0, 1 , "GPB3", 0, 1, 2 },
	{ "iic1", OFFANDSIZE(,I2C1), 1, IRQ_I2C1_USI1, 1 , "GPB3", 2, 3, 2 },
	{ "iic2", OFFANDSIZE(,I2C2), 2, IRQ_I2C2_USI2, 1 , "GPA0", 6, 7, 3 },
	{ "iic3", OFFANDSIZE(,I2C3), 3, IRQ_I2C3_USI3, 1 , "GPA1", 2, 3, 3 },
	{ "iic4", OFFANDSIZE(,I2C4), 4, IRQ_I2C4,      1 , "GPA2", 0, 1, 3 },
	{ "iic5", OFFANDSIZE(,I2C5), 5, IRQ_I2C5,      1 , "GPA2", 2, 3, 3 },
	{ "iic6", OFFANDSIZE(,I2C6), 6, IRQ_I2C6,      1 , "GPB1", 3, 4, 4 },
	{ "iic7", OFFANDSIZE(,I2C7), 7, IRQ_I2C7,      1 , "GPB2", 2, 3, 3 },
	{ "iic8", OFFANDSIZE(,I2CHDMI), 8, IRQ_HDMI_I2C, 0 , "", 0, 0, 0 },
};


const struct exyo_locinfo exynos5_i2c_locinfo = {
	.locators = exynos5_i2c_locators,
	.nlocators = __arraycount(exynos5_i2c_locators)
};


