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
#ifndef AES_H
#define AES_H

#include <libstm8/common.h>

/* AES presen only in high density STM8L16xx devices only. */
#define AES_BASE	0x0053D0
#define AES_CR		MMIO8(AES_BASE + 0x0)
#define AES_SR		MMIO8(AES_BASE + 0x1)
#define AES_DINR	MMIO8(AES_BASE + 0x2)
#define AES_DOUTR	MMIO8(AES_BASE + 0x3)

#define AES_CR_DMAEN	(1 << 7) /* is DMA enabled */
#define AES_CR_ERRIE	(1 << 6) /* is error interrupt enable. (RDERR|WRERR) */
#define AES_CR_CCIE	(1 << 5) /* Computation complete interrupt (CCF) enable */
/* Error flags clear. Writing 1 into this bit clears RDERR and WRERR flags. */
#define AES_CR_ERRFC	(1 << 4)
#define AES_CR_CCFC	(1 << 3) /* Writing 1 into this bit clears the CCF flag. */
#define AES_CR_EN	(1 << 0) /* is AES enabled */
/* AES mode of operation */
#define AES_CR_MODE_SHIFT	1
#define AES_CR_MODE_MASK	0x3
#define AES_CR_MODE_ENCRIPTION	0x0
#define AES_CR_MODE_KEY_DERIVATION 0x1
#define AES_CR_MODE_DECRIPTION	0x2
#define AES_CR_MODE_KEY_DECRIPTION 0x3 /* Key derivation + decryption */

/* This bit is set by hardware when an unexpected write operation into the
   AES_DINR is detected.
*/
#define AES_SR_WRERR	(1 << 2) /* Write error detected */
#define AES_SR_RDERR	(1 << 1) /* Unexpected read into the AES_DOUTR */
#define AES_SR_CCF	(1 << 0) /* Computation completed */

/* AES_DINR must be written 16 times for key derivation from encription key
   or 32 times for other operations (suitable key + text).
   Bytes writes from MSB to LSB.
*/
/* AES_DOUTR after CCF set this register contain 16 bytes result from MSB to LSB */

#endif
