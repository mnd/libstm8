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

#define RTC_TR1 MMIO8(0x005140)	/* Time register 1 */
#define RTC_TR2 MMIO8(0x005141)	/* Time register 2 */
#define RTC_TR3 MMIO8(0x005142)	/* Time register 3 */
#define RTC_DR1 MMIO8(0x005144)	/* Date register 1 */
#define RTC_DR2 MMIO8(0x005145)	/* Date register 2 */
#define RTC_DR3 MMIO8(0x005146)	/* Date register 3 */
#define RTC_CR1 MMIO8(0x005148)	/* Control register 1 */
#define RTC_CR2 MMIO8(0x005149)	/* Control register 2 */
#define RTC_CR3 MMIO8(0x00514A)	/* Control register 3 */
#define RTC_ISR1 MMIO8(0x00514C) /* Initialization and status register 1 */
#define RTC_ISR2 MMIO8(0x00514D) /* Initialization and status register 2 */
/* Next 5 registers are not impacted by a system reset. 
   They are reset at power-on. */
#define RTC_SPRERH MMIO8(0x005150) /* Synchronous prescaler register high */
#define RTC_SPRERL MMIO8(0x005151) /* Synchronous prescaler register low */
#define RTC_APRER  MMIO8(0x005152) /* Asynchronous prescaler register */
#define RTC_WUTRH  MMIO8(0x005154) /* Wakeup timer register high */
#define RTC_WUTRL  MMIO8(0x005155) /* Wakeup timer register low */
#define RTC_WPR MMIO8(0x005159)	/* Write protection register */
#define RTC_ALRMAR1 MMIO8(0x00515C) /* Alarm A register 1 */
#define RTC_ALRMAR2 MMIO8(0x00515D) /* Alarm A register 2 */
#define RTC_ALRMAR3 MMIO8(0x00515E) /* Alarm A register 3 */
#define RTC_ALRMAR4 MMIO8(0x00515F) /* Alarm A register 4 */


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


#endif
