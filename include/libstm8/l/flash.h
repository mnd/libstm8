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
#ifndef FLASH_H
#define FLASH_H

#include <libstm8/common.h>

#define FLASH_CR1   MMIO8(0x005050) /* Flash control register 1 */
#define FLASH_CR2   MMIO8(0x005051) /* Flash control register 2 */
/* Flash program memory unprotection key register */
#define FLASH_PUKR  MMIO8(0x005052)
#define FLASH_DUKR  MMIO8(0x005053) /* Data EEPROM unprotection key register */
/* Flash in-application programming status register */
#define FLASH_IAPSR MMIO8(0x005054)

/* Flash program and data EEPROM I_DDQ mode selection during run, low power run
   and low power wait mode */
#define FLASH_CR1_EEPM	(1 << 3)
/* Flash program and data EEPROM I_DDQ mode during wait mode */
#define FLASH_CR1_WAITM	(1 << 2)
#define FLASH_CR1_IE	(1 << 1) /* Flash Interrupt enable */
#define FLASH_CR1_FIX	(1 << 0) /* Fixed Byte programming time */

#define FLASH_CR2_OPT	(1 << 7) /* is write access to option bytes enabled */
#define FLASH_CR2_WPRG	(1 << 6) /* is word program operation enabled */
#define FLASH_CR2_ERASE	(1 << 5) /* is block erase operation enabled */
#define FLASH_CR2_FPRG	(1 << 4) /* is fast block program operation enabled */
/* is standard block programming operation enabled (automatically first erasing) */
#define FLASH_CR2_PRG	(1 << 0)

/* Main program memory unlock keys.
   To disable the main program memory write protection we must write next two
   bytes in FLASH_PUKR register. If correct FLASH_IAPSR_PUL would be set.
*/
#define FLASH_PUKR_1	0x56
#define FLASH_PUKR_2	0xAE
/* Data EEPROM write unlock keys.
   To disable the DATA area write protection we must write next two
   bytes in FLASH_DUKR register. If correct FLASH_IAPSR_DUL would be set.
*/
#define FLASH_DUKR_1	0xAE
#define FLASH_DUKR_2	0x56

#define FLASH_IAPSR_HVOFF	(1 << 6) /* End of high voltage flag */
#define FLASH_IAPSR_DUL		(1 << 3) /* Data EEPROM area unlocked flag */
/* End of programming (write or erase operation) flag */
#define FLASH_IAPSR_EOP		(1 << 2)
#define FLASH_IAPSR_PUL		(1 << 1) /* Flash Program memory unlocked flag */
/* Write attempted to protected page flag */
#define FLASH_IAPSR_WR_PG_DIS	(1 << 0)

#endif
