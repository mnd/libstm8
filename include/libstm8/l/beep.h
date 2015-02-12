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
#ifndef BEEP_H
#define BEEP_H

#include <libstm8/common.h>

#define BEEP_CSR1 MMIO8(0x0050F0)	/* BEEP control/status register 1 */
#define BEEP_CSR2 MMIO8(0x0050F3)	/* BEEP control/status register 2 */

/* Measurement enable
   This bit connects the BEEPCLK to the TIM2 channel 1 input capture.
   This allows the timer to be used to measure the LSI frequency (f_LSI)
*/
#define BEEP_CSR1_MSR	(1 << 0)

#define BEEP_CSR2_BEEPEN (1 << 5) /* is BEEP enabled */
/* select 1, 2 or 4 kHz BEEP output when calibration is done. */
#define BEEP_CSR2_BEEPSEL_SHIFT	6
#define BEEP_CSR2_BEEPSEL_MASK	0x3
#define BEEP_CSR2_BEEPSEL_1KHZ	0x0 /* BEEPCLK / (8 x BEEP_DIV) kHz output */
#define BEEP_CSR2_BEEPSEL_2KHZ	0x1 /* BEEPCLK / (4 x BEEP_DIV) kHz output */
#define BEEP_CSR2_BEEPSEL_4KHZ	0x2 /* BEEPCLK / (2 x BEEP_DIV) kHz output */
#define BEEP_CSR2_BEEPSEL_4KHZ1	0x3
/* BEEP prescaler divider (BEEP_DIV) */
#define BEEP_CSR2_BEEPDIV_SHIFT	0
#define BEEP_CSR2_BEEPDIV_MASK	0x1F
#define BEEP_CSR2_BEEPDIV_INVALID 0x1F /* invalid reset value. Must be changed */
#define BEEP_CSR2_BEEPDIV(n)	((n) - 2)

#endif
