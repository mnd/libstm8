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
#ifndef IWDG_H
#define IWDG_H

#include <libstm8/common.h>

#define IWDG_KR  MMIO8(0x0050E0)	/* IWDG key register */
#define IWDG_PR  MMIO8(0x0050E1)	/* IWDG prescaler register */
#define IWDG_RLR MMIO8(0x0050E2)	/* IWDG reload register */

/* Writing the KEY_ENABLE value into IWDG_KR starts the IWDG. */
#define IWDG_KR_KEY_ENABLE	0xCC
/* Writing the KEY_REFRESH value refreshes the IWDG. */
#define IWDG_KR_KEY_REFRESH	0xAA
/* Writing the KEY_ACCESS value enables the access to the protected IWDG_PR and
   IWDG_RLR registers.
*/
#define IWDG_KR_KEY_ACCESS	0x55

/* Prescaler divider */
#define IWDG_PR_SHIFT	0
#define IWDG_PR_MASK	0x7
#define IWDG_PR_4	0x0
#define IWDG_PR_8	0x1
#define IWDG_PR_16	0x2
#define IWDG_PR_32	0x3
#define IWDG_PR_64	0x4	/* divider /64 */
#define IWDG_PR_128	0x5
#define IWDG_PR_256	0x6

/* IWDG_RLR[7:0] value loaded in the watchdog counter each time the value 
   IWDG_KR_KEY_REFRESH written in IWDG_KR register.
*/

#endif
