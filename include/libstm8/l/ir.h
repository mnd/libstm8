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
#ifndef IR_H
#define IR_H

#include <libstm8/common.h>

#define IR_CR MMIO8(0x0052FF)	/* Infrared control register */
/* High Sink LED driver capability enable.
   When activated, this pin can sink 20 mA min. with a power supply down to 2 V.
*/
#define IR_CR_HS_EN	(1 << 1)
/* Infrared output enable.
   0: IR_TIM output disabled.
   1: IR_TIM output enabled and provided to PA0 (TIM2 and TIM3 must have
      been previously configured properly by software)
*/
#define IR_CR_IR_EN	(1 << 0)

#endif
