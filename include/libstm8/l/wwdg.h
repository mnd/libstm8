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
#ifndef WWDG_H
#define WWDG_H

#include <libstm8/common.h>

#define WWDG_CR MMIO8(0x0050D3)	/* WWDG control register */
#define WWDG_WR MMIO8(0x0050D4)	/* WWDR window register */

/* Is watchdog enabled. Only cleared by hardware after a reset. */
#define WWDG_CR_WDGA	(1 << 7)
/* 7-bit counter.
   These bits contain the value of the watchdog counter. It is decremented every
   12288 SYSCLK cycles (approximately). A reset is produced when it rolls over
   from 0x40 to 0x3F (T[6] becomes cleared).
*/
#define WWDG_CR_T_SHIFT	0
#define WWDG_CR_T_MASK	0x7F

/* 7-bit window value.
   These bits contain the window value to be compared to the downcounter.
*/
#define WWDG_WR_W_SHIFT	0
#define WWDG_WR_W_MASK	0x7F

#endif
