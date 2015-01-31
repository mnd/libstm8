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
#ifndef PWR_H
#define PWR_H

#include <libstm8/common.h>

#define PWR_CSR1	MMIO8(0x0050B2)	/* Power control and status register 1 */
#define PWR_CSR2	MMIO8(0x0050B3)	/* Power control and status register 2 */

#define PWR_CSR1_PVDOF	(1 << 6) /* r/o. is V_DD below PVD threshold level */
#define PWR_CSR1_PVDIF	(1 << 5) /* PVD interrupt flag */
#define PWR_CSR1_PVDIEN	(1 << 4) /* PVD interrupt enabled */
#define PWR_CSR1_PVDE	(1 << 0) /* Power Voltage Detector enabled */

#define PWR_CSR1_PLS_MASK	0x7
#define PWR_CSR1_PLS_SHIFT	1
#define PWR_CSR1_PLS_185	0x0 /* PVD threshold = 1.85 V */
#define PWR_CSR1_PLS_205	0x1
#define PWR_CSR1_PLS_226	0x2
#define PWR_CSR1_PLS_245	0x3
#define PWR_CSR1_PLS_265	0x4
#define PWR_CSR1_PLS_285	0x5
#define PWR_CSR1_PLS_305	0x6
#define PWR_CSR1_PLS_PVD_IN	0x7 /* threshold level equal to PVD_IN input pin */

/* look at http://www.st.com/web/en/resource/technical/document/reference_manual/CD00218714.pdf
   page 68 for more information. */
#define PWR_CSR2_FWU		(1 << 2) /* Fast wakeup configuration bit */
#define PWR_CSR2_ULP		(1 << 1) /* Ultralow power configuration bit */
#define PWR_CSR2_VREFINTF	(1 << 0) /* is internal reference voltage on */

#endif
