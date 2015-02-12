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
#ifndef ITC_H
#define ITC_H

#include <libstm8/common.h>

#define ITC_SPR_BASE 0x007F70
/* Interrupt Software priority register 1 */
#define ITC_SPR1 MMIO8(ITC_SPR_BASE + 0x0)
/* Interrupt Software priority register 2 */
#define ITC_SPR2 MMIO8(ITC_SPR_BASE + 0x1)
/* Interrupt Software priority register 3 */
#define ITC_SPR3 MMIO8(ITC_SPR_BASE + 0x2)
/* Interrupt Software priority register 4 */
#define ITC_SPR4 MMIO8(ITC_SPR_BASE + 0x3)
/* Interrupt Software priority register 5 */
#define ITC_SPR5 MMIO8(ITC_SPR_BASE + 0x4)
/* Interrupt Software priority register 6 */
#define ITC_SPR6 MMIO8(ITC_SPR_BASE + 0x5)
/* Interrupt Software priority register 7 */
#define ITC_SPR7 MMIO8(ITC_SPR_BASE + 0x6)
/* Interrupt Software priority register 8 */
#define ITC_SPR8 MMIO8(ITC_SPR_BASE + 0x7)

/* VECTxSPR_REG(n) >> VECTxSPR_SHIFT(n)) & VECTxSPR_MASK = priority for vector n */
#define VECTxSPR_SHIFT(n) (((n) % 4) * 2)
#define VECTxSPR_MASK	0x3
#define VECTxSPR_REG(n)	MMIO8(ITC_SPR_BASE + ((n) / 4))
/* Priority levels:  */
#define ITC_SPR_0	0x2	/* Level 0 (main) */
#define ITC_SPR_1	0x1	/* Level 1 */
#define ITC_SPR_2	0x0	/* Level 2 */
#define ITC_SPR_3	0x3	/* Level 3 (= software priority disabled) */


#endif
