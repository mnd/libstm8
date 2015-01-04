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
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef STM8REGS_H
#define STM8REGS_H

#ifndef USE_SDCC_AT		
#include "stm8lregs-define.h"	/* by default we would use define macro */
#else /* USE_SDCC_AT */
#include "stm8lregs-sdcc.h"	/* alternatively regular variables with __at (addr) feature */
#endif /* USE_SDCC_AT */

#define OPT_IWDG_HW_MASK   (1 << 0) /* is independent watchdog activated by hardware */
#define OPT_IWDG_HALT_MASK (1 << 1) /* independent window watchdog off on Halt/Active-halt */
#define OPT_WWDG_HW_MASK   (1 << 2) /* is window watchdog activated by hardware  */
#define OPT_WWDG_HALT_MASK (1 << 3) /* window window watchdog reset on Halt/Active-halt */

#define OPT_CLOCK_HSECNT_MASK (3 << 0) /* Number of HSE oscillator stabilization clock cycles: 1/16/512/4096 */
#define OPT_CLOCK_LSECNT_MASK (3 << 2) /* Number of LSE oscillator stabilization clock cycles: 1/16/512/4096 */

#define OPT_BOR_ON_MASK (1 << 0) /* is brownout reset on */
#define OPT_BOR_TH_MASK (7 << 1) /* Brownout reset thresholds */

#define UID_POINTER 0x4926	/* 96-bit unique device identifier which provides a reference number that is unique for any device and in any context.
				   The 96 bits of the identifier can never be altered by the user. */

#endif /* STM8REGS_H */
