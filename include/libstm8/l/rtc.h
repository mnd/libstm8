/*
 * This file is part of the libstm8 project.
 *
 * Copyright (C) 2015 Nikolay Merinov <nikolay.merinov@member.fsf.org>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef RTC_H
#define RTC_H

#include <libstm8/common.h>

#define RTC_BASE 0x005140
#define RTC_TR1 MMIO8(RTC_BASE + 0x0)	/* Time register 1 */
#define RTC_TR2 MMIO8(RTC_BASE + 0x1)	/* Time register 2 */
#define RTC_TR3 MMIO8(RTC_BASE + 0x2)	/* Time register 3 */
#define RTC_DR1 MMIO8(RTC_BASE + 0x4)	/* Date register 1 */
#define RTC_DR2 MMIO8(RTC_BASE + 0x5)	/* Date register 2 */
#define RTC_DR3 MMIO8(RTC_BASE + 0x6)	/* Date register 3 */
#define RTC_CR1 MMIO8(RTC_BASE + 0x8)	/* Control register 1 */
#define RTC_CR2 MMIO8(RTC_BASE + 0x9)	/* Control register 2 */
#define RTC_CR3 MMIO8(RTC_BASE + 0xA)	/* Control register 3 */
#define RTC_ISR1 MMIO8(RTC_BASE + 0xC) /* Initialization and status register 1 */
#define RTC_ISR2 MMIO8(RTC_BASE + 0xD) /* Initialization and status register 2 */
/* Next 5 registers are not impacted by a system reset.
   They are reset at power-on. */
#define RTC_SPRERH MMIO8(RTC_BASE + 0x10) /* Synchronous prescaler register high */
#define RTC_SPRERL MMIO8(RTC_BASE + 0x11) /* Synchronous prescaler register low */
#define RTC_APRER  MMIO8(RTC_BASE + 0x12) /* Asynchronous prescaler register */
#define RTC_WUTRH  MMIO8(RTC_BASE + 0x14) /* Wakeup timer register high */
#define RTC_WUTRL  MMIO8(RTC_BASE + 0x15) /* Wakeup timer register low */
#define RTC_SSRH MMIO8(RTC_BASE + 0x17)
#define RTC_SSRL MMIO8(RTC_BASE + 0x18)
#define RTC_WPR MMIO8(RTC_BASE + 0x19) /* Write protection register */
#define RTC_SHIFTRH MMIO8(RTC_BASE + 0x1A)
#define RTC_SHIFTRL MMIO8(RTC_BASE + 0x1B)
#define RTC_ALRMAR1 MMIO8(RTC_BASE + 0x1C) /* Alarm A register 1 */
#define RTC_ALRMAR2 MMIO8(RTC_BASE + 0x1D) /* Alarm A register 2 */
#define RTC_ALRMAR3 MMIO8(RTC_BASE + 0x1E) /* Alarm A register 3 */
#define RTC_ALRMAR4 MMIO8(RTC_BASE + 0x1F) /* Alarm A register 4 */
#define RTC_ALRMASSRH MMIO8(RTC_BASE + 0x24)
#define RTC_ALRMASSRL MMIO8(RTC_BASE + 0x25)
#define RTC_ALRMASSMSKR MMIO8(RTC_BASE + 0x26)
#define RTC_CALRH MMIO8(RTC_BASE + 0x2A)
#define RTC_CALRL MMIO8(RTC_BASE + 0x2B)
#define RTC_TCR1 MMIO8(RTC_BASE + 0x2C)
#define RTC_TCR2 MMIO8(RTC_BASE + 0x2D)

/* Second tens in BCD format */
#define RTC_TR1_ST_SHIFT 4
#define RTC_TR1_ST_MASK  0x7
/* Second units in BCD format */
#define RTC_TR1_SU_SHIFT 0
#define RTC_TR1_SU_MASK  0xF

/* Minute tens in BCD format */
#define RTC_TR2_MNT_SHIFT 4
#define RTC_TR2_MNT_MASK  0x7
/* Minute units in BCD format */
#define RTC_TR2_MNU_SHIFT 0
#define RTC_TR2_MNU_MASK  0xF

/* AM/PM notation. 0 -- AM or 24hour, 1 -- PM */
#define RTC_TR3_PM	(1 << 6)
/* Hour tens in BCD format */
#define RTC_TR3_HT_SHIFT 4
#define RTC_TR3_HT_MASK  0x3
/* Hour units in BCD format */
#define RTC_TR3_HU_SHIFT 0
#define RTC_TR3_HU_MASK  0xF

/* Date tens in BCD format */
#define RTC_DR1_DT_SHIFT 4
#define RTC_DR1_DT_MASK  0x3
/* Date units in BCD format */
#define RTC_DR1_DU_SHIFT 0
#define RTC_DR1_DU_MASK  0xF

/* Week day units. 1 -- Monday, .., 7 -- Sunday. 0 -- forbidden. */
#define RTC_DR2_WDU_SHIFT 5
#define RTC_DR2_WDU_MASK  0x7
/* Month tens in BCD format */
#define RTC_DR2_MT_SHIFT 4
#define RTC_DR2_MT_MASK  0x1
/* Month units in BCD format */
#define RTC_DR2_MU_SHIFT 0
#define RTC_DR2_MU_MASK  0xF

/* Year tens in BCD format */
#define RTC_DR3_YT_SHIFT 4
#define RTC_DR3_YT_MASK  0xF
/* Year units in BCD format */
#define RTC_DR3_YU_SHIFT 0
#define RTC_DR3_YU_MASK  0xF

/* Sub second value RTC_SS[15:0] = RTC_SSRH[7:0]:RTC_SSRL[7:0]
   RTC_SS is the value of the synchronous prescaler's counter. The fraction of
   second is given by the formula below:
     Second fraction = ( RTC_SPRE - SS) / (RTC_SPRE + 1)
*/

#define RTC_CR1_FMT	(1 << 6) /* Hour format: 24[0]/AMPM[1] */
#define RTC_CR1_RATIO	(1 << 5) /* System clock (SYSCLK) versus RTCCLK ratio */
#define RTC_CR1_BYPSHAD	(1 << 4) /* Bypass the shadow registers */
/* Wakeup clock selection */
#define RTC_CR1_WUCKSEL_SHIFT	0
#define RTC_CR1_WUCKSEL_MASK	0x7
#define RTC_CR1_WUCKSEL_RTC_16	0x0 /* RTCCLK/16 clock is selected */
#define RTC_CR1_WUCKSEL_RTC_8	0x1
#define RTC_CR1_WUCKSEL_RTC_4	0x2
#define RTC_CR1_WUCKSEL_RTC_2	0x3
#define RTC_CR1_WUCKSEL_CK_SPRE	0x4 /* ck_spre (usually 1 Hz) clock is selected */
/* ck_spre (usually 1 Hz) clock is selected and 0x10000 is added to the
   WUT counter value */
#define RTC_CR1_WUCKSEL_CK_SPRE_WUT	0x6

#define RTC_CR2_WUTIE	(1 << 6) /* Wakeup timer interrupt enable */
#define RTC_CR2_ALRAIE	(1 << 4) /* Alarm A interrupt enable */
#define RTC_CR2_WUTE	(1 << 2) /* Wakeup timer enable */
#define RTC_CR2_ALRAE	(1 << 0) /* Alarm A enable */

#define RTC_CR3_COE	(1 << 7) /* Calibration output RTC_CALIB enable */
#define RTC_CR3_POL	(1 << 4) /* Output polarity for RTC_ALARM */
#define RTC_CR3_COSEL	(1 << 3) /* Calibration output selection */
#define RTC_CR3_BCK	(1 << 2) /* Backup. Set if DST change was performed. */
#define RTC_CR3_SUB1H	(1 << 1) /* Subtract 1 hour (winter time change) */
#define RTC_CR3_ADD1H	(1 << 0) /* Add 1 hour (summer time change) */
/* Output selection to be routed to RTC_ALARM output */
#define RTC_CR3_OSEL_SHIFT	5
#define RTC_CR3_OSEL_MASK	0x3
#define RTC_CR3_OSEL_DISABLE	0x0 /* Output disable */
#define RTC_CR3_OSEL_ALARM	0x1 /* Alarm A output enable */
#define RTC_CR3_OSEL_WAKEUP	0x3 /* Wakeup output enable */

#define RTC_ISR1_INIT	(1 << 7) /* Initialization mode. */
#define RTC_ISR1_INITF	(1 << 6) /* Initialization flag */
#define RTC_ISR1_RSF	(1 << 5) /* Registers synchronization flag */
#define RTC_ISR1_INITS	(1 << 4) /* Initialization status flag */
#define RTC_ISR1_SHPF	(1 << 3) /* Shift operation pending */
#define RTC_ISR1_WUTWF	(1 << 2) /* Wakeup timer write flag */
#define RTC_ISR1_RECALPF (1 << 1) /* Recalibration pending Flag */
#define RTC_ISR1_ALRAWF	(1 << 0) /* Alarm A write flag */

#define RTC_ISR2_TAMP3F	(1 << 7) /* TAMPER3 detection flag */
#define RTC_ISR2_TAMP2F	(1 << 6) /* TAMPER2 detection flag */
#define RTC_ISR2_TAMP1F	(1 << 5) /* TAMPER1 detection flag */
#define RTC_ISR2_WUTF	(1 << 2) /* Periodic wakeup flag */
#define RTC_ISR2_ALRAF	(1 << 0) /* Alarm A Flag */

#define RTC_SPRERH_MASK	0x7F
/* Synchronous prescaler factor PREDIV_S =  RTC_SPRERH[6:0]:RTC_SPRERL[7:0]
   ck_spre frequency = ck_apre frequency / (PREDIV_S+1)
*/

#define RTC_APRER_MASK	0x7F
/* Asynchronous prescaler factor PREDIV_A = RTC_APRER[6:0]
   ck_apre frequency = f_RTCCLK frequency / (PREDIV_A+1)
*/

/* Wakeup WUT[15:0] = RTC_WUTRH[7:0]:RTC_WUTRL[7:0] */

#define RTC_WPR_1	0xCA	/* First key */
#define RTC_WPR_2	0x53	/* Second key */

#define RTC_SHIFTRH_ADD1S	(7 << 1) /* Add one second */
/* MSB to subtract a fraction of a second */
#define RTC_SHIFTRH_SUBFS_SHIFT	0
#define RTC_SHIFTRH_SUBFS_MASK	0x7F
/* subtract a fraction of a second SUBFS[14:0]=RTC_SHIFTRH[6:0]:RTC_SHIFTRL[7:0] */

#define RTC_ALRMAR1_MSK1	(1 << 7) /* Alarm A Seconds mask */
/* Second tens in BCD format */
#define RTC_ALRMAR1_ST_SHIFT	4
#define RTC_ALRMAR1_ST_MASK	0x7
/* Second units in BCD format */
#define RTC_ALRMAR1_SU_SHIFT	0
#define RTC_ALRMAR1_SU_MASK	0xF

#define RTC_ALRMAR2_MSK2	(1 << 7) /* Alarm A minutes mask */
/* Minute tens in BCD format */
#define RTC_ALRMAR2_MNT_SHIFT	4
#define RTC_ALRMAR2_MNT_MASK	0x7
/* Minute units in BCD format */
#define RTC_ALRMAR2_MNU_SHIFT	0
#define RTC_ALRMAR2_MNU_MASK	0xF

#define RTC_ALRMAR3_MSK3	(1 << 7) /* Alarm A hours mask */
#define RTC_ALRMAR3_PM		(1 << 7) /* AM/PM notation */
/* Hour tens in BCD format */
#define RTC_ALRMAR3_HT_SHIFT	4
#define RTC_ALRMAR3_HT_MASK	0x3
/* Hour units in BCD format */
#define RTC_ALRMAR3_HU_SHIFT	0
#define RTC_ALRMAR3_HU_MASK	0xF

#define RTC_ALRMAR4_MSK4	(1 << 7) /* Alarm A Date mask */
#define RTC_ALRMAR4_WDSEL	(1 << 7) /* Date/Week day selection */
/* Date tens in BCD format */
#define RTC_ALRMAR4_DT_SHIFT	4
#define RTC_ALRMAR4_DT_MASK	0x3
/* Date units or Day in BCD format */
#define RTC_ALRMAR4_DU_SHIFT	0
#define RTC_ALRMAR4_DU_MASK	0xF

#define RTC_ALRMASSRH_MASK	0x7F
/* Subseconds value ALSS[14:0]=RTC_ALRMASSRH[6:0]:RTC_ALRMASSRL[7:0] */

#define RTC_ALRMASSMSKR_MASK	0xF
/* RTC_ALRMASSMSKR how many least significant bits os SS[14:0] would be compared */

#define RTC_CALRH_CALP	(1 << 7) /* Increase of RTC frequency by 488.5 ppm */
#define RTC_CALRH_CALW8	(1 << 6) /* Use an 8-second calibration cycle period */
#define RTC_CALRH_CALW16 (1 << 5) /* Use a 16-second calibration cycle period */
#define RTC_CALRH_CALM	(1 << 0)  /* MSB of calibration minus */
/* calibration minus CALM[8:0]=RTC_CALRH[0]:RTC_CALRL[7:0] */

#define RTC_TCR1_TAMP3TRG	(1 << 6) /* Active level for tamper input 3 */
#define RTC_TCR1_TAMP3E		(1 << 5) /* Tamper detection enable for TAMPER3 */
#define RTC_TCR1_TAMP2TRG	(1 << 4) /* Active level for tamper input 2 */
#define RTC_TCR1_TAMP2E		(1 << 3) /* Tamper detection enable for TAMPER2 */
#define RTC_TCR1_TAMP1TRG	(1 << 2) /* Active level for tamper 1 */
#define RTC_TCR1_TAMP1E		(1 << 1) /* Tamper detection enable for TAMPER1 */
#define RTC_TCR1_TAMPIE		(1 << 0) /* Tamper interrupt enable */

#define RTC_TCR2_TAMPPUDIS	(1 << 7) /* TAMPER pull-up disable */
/* Tamper precharge duration */
#define RTC_TCR2_TAMPPRCH_SHIFT	5
#define RTC_TCR2_TAMPPRCH_MASK	0x3
#define RTC_TCR2_TAMPPRCH_1	0x0 /* 1 RTCCLK clock cycle */
#define RTC_TCR2_TAMPPRCH_2	0x1
#define RTC_TCR2_TAMPPRCH_4	0x2
#define RTC_TCR2_TAMPPRCH_8	0x3 /* 8 RTCCLK clock cycle */
/* Tamper filter count */
#define RTC_TCR2_TAMPFLT_SHIFT	3
#define RTC_TCR2_TAMPFLT_MASK	0x3
/* Tamper is activated after 1 sample at the active level */
#define RTC_TCR2_TAMPFLT_1	0x0
#define RTC_TCR2_TAMPFLT_2	0x1
#define RTC_TCR2_TAMPFLT_4	0x2
/* Tamper is activated after 8 consecutive samples at the active level */
#define RTC_TCR2_TAMPFLT_8	0x3
/* Tamper sampling frequency */
#define RTC_TCR2_TAMPFREQ_SHIFT	0
#define RTC_TCR2_TAMPFREQ_MASK	0x7
/* RTCCLK / 32768 (1 Hz when RTCCLK = 32768 Hz) */
#define RTC_TCR2_TAMPFREQ_32768	0x0
#define RTC_TCR2_TAMPFREQ_16384	0x1
#define RTC_TCR2_TAMPFREQ_8192	0x2
#define RTC_TCR2_TAMPFREQ_4096	0x3
#define RTC_TCR2_TAMPFREQ_2048	0x4
#define RTC_TCR2_TAMPFREQ_1024	0x5
#define RTC_TCR2_TAMPFREQ_512	0x6
/* RTCCLK / 256 (128 Hz when RTCCLK = 32768 Hz) */
#define RTC_TCR2_TAMPFREQ_256	0x7

#endif
