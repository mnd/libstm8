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
#ifndef RST_H
#define RST_H

#include <libstm8/common.h>

/* read many/write once register */
#define RST_CR MMIO8(0x0050B0)	/* Reset control register */
#define RST_SR MMIO8(0x0050B1)	/* Reset status register */

/* RST_CR = RST_CR_RSTPIN_KEY_PA1 to use PA1 as GPIO pin */
#define RST_CR_RSTPIN_KEY_PA1	0xD0
/* RST_CR = RST_CR_RSTPIN_KEY_NRST to use PA1 as Reset pin */
#define RST_CR_RSTPIN_KEY_NRST	0x00

#define RST_SR_BORF	(1 << 5) /* is Brownout reset occurred */
#define RST_SR_WWDGF	(1 << 4) /* is WWDG reset occurred */
#define RST_SR_SWIMF	(1 << 3) /* is SWIM reset occurred */
#define RST_SR_ILLOPF	(1 << 2) /* is Illegal Opcode reset occurred */
#define RST_SR_IWDGF	(1 << 1) /* is IWDG reset occured */
#define RST_SR_PORF	(1 << 0) /* is Power-on Reset occured */

#endif
