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
#ifndef GCR_H
#define GCR_H

#include <libstm8/common.h>

#define CFG_GCR MMIO8(0x007F60)	/* Global configuration register */
/* Activation level. Is IRET return to main mode after WFI */
#define CFG_GCR_AL  (1 << 1)
/* SWIM disable.
   When SWIM mode is enabled, the SWIM pin cannot be used as general purpose I/O
*/
#define CFG_GCR_SWD (1 << 0)


#endif
