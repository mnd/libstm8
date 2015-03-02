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
#ifndef EXTI_H
#define EXTI_H

#include <libstm8/common.h>

#define EXTI_BASE  0x0050A0
/* External interrupt control register 1 */
#define EXTI_CR1   MMIO8(EXTI_BASE + 0x0)
/* External interrupt control register 2 */
#define EXTI_CR2   MMIO8(EXTI_BASE + 0x1)
/* External interrupt control register 3 */
#define EXTI_CR3   MMIO8(EXTI_BASE + 0x2)
/* External interrupt control register 4 */
#define EXTI_CR4   MMIO8(EXTI_BASE + 0xA)
/* External interrupt status register 1 */
#define EXTI_SR1   MMIO8(EXTI_BASE + 0x3)
/* External interrupt status register 2 */
#define EXTI_SR2   MMIO8(EXTI_BASE + 0x4)
/* External interrupt port select register 1 */
#define EXTI_CONF1 MMIO8(EXTI_BASE + 0x5)
/* External interrupt port select register 2 */
#define EXTI_CONF2 MMIO8(EXTI_BASE + 0xB)

/* Portx bit `n' external interrupt sensitivity bits. This bits define the
   sensitivity of bit `n' of Port A, B, C, D and/or E external interrupts.
*/
#define EXTI_PxIS_REG(n)   MMIO8(EXTI_BASE + (n) / 4)
#define EXTI_PxIS_SHIFT(n) (((n) % 4) * 2)
#define EXTI_PxIS_MASK     0x3

/* Port X external interrupt sensitivity bits. They define the sensitivity of
   the Port X external interrupts, when EXTIX for Port X[3:0] and/or Port X[7:4]
   is enabled. 
*/
#define EXTI_CR3_PBIS_SHIFT	0
#define EXTI_CR3_PBIS_MASK	0x3
#define EXTI_CR3_PDIS_SHIFT	2
#define EXTI_CR3_PDIS_MASK	0x3
#define EXTI_CR3_PEIS_SHIFT	4
#define EXTI_CR3_PEIS_MASK	0x3
#define EXTI_CR3_PFIS_SHIFT	6
#define EXTI_CR3_PFIS_MASK	0x3
#define EXTI_CR4_PGIS_SHIFT	0
#define EXTI_CR4_PGIS_MASK	0x3
#define EXTI_CR4_PHIS_SHIFT	2
#define EXTI_CR4_PHIS_MASK	0x3

/* Sensitivity bit possible values */
#define EXTI_FALLING_LOW	0x0 /* Falling edge and low level */
#define EXTI_RISING		0x1 /* Rising edge only */
#define EXTI_FALLING		0x2 /* Falling edge only */
#define EXTI_RISING_FALLING	0x3 /* Rising and falling edge */

/* Port A/B/C/D/E/F bit `n' external interrupt flag. 
   These bits are set by hardware when an interrupt event occurs on the
   corresponding pin.
*/
#define EXTI_SR1_PxF(n)	(1 << (n))

/* Port H external interrupt flag.
   This bit is set by hardware when an interrupt event occurs on the
   corresponding pin.
*/
#define EXTI_SR2_PHF	(1 << 5)
#define EXTI_SR2_PGF	(1 << 4)
#define EXTI_SR2_PFF	(1 << 3)
#define EXTI_SR2_PEF	(1 << 2)
#define EXTI_SR2_PDF	(1 << 1)
#define EXTI_SR2_PBF	(1 << 0)

/* 0: Port E is used for interrupt generation
   1: Port F is used for interrupt generation
*/
#define EXTI_CONF1_PFES  (1 << 7)
/* 0: PF[3:0] are used for EXTI3-EXTI0 interrupt generation
   1: PF[3:0] are used for EXTIF interrupt generation
*/
#define EXTI_CONF1_PFLIS (1 << 6)
/* 0: PE[7:4] are used for EXTI7-EXTI4 interrupt generation
   1: PE[7:4] are used for EXTIE interrupt generation
*/
#define EXTI_CONF1_PEHIS (1 << 5)
/* 0: PE[3:0] are used for EXTI3-EXTI0 interrupt generation
   1: PE[3:0] are used for EXTIE interrupt generation
*/
#define EXTI_CONF1_PELIS (1 << 4)
/* 0: PD[7:4] are used for EXTI7-EXTI4 interrupt generation
   1: PD[7:4] are used for EXTID interrupt generation
*/
#define EXTI_CONF1_PDHIS (1 << 3)
/* 0: PD[3:0] are used for EXTI3-EXTI0 interrupt generation
   1: PD[3:0] are used for EXTID interrupt generation
*/
#define EXTI_CONF1_PDLIS (1 << 2)
/* 0: PB[7:4] are used for EXTI7-EXTI4 interrupt generation
   1: PB[7:4] are used for EXTIB interrupt generation
*/
#define EXTI_CONF1_PBHIS (1 << 1)
/* 0: PB[3:0] are used for EXTI3-EXTI0 interrupt generation
   1: PB[3:0] are used for EXTIB interrupt generation
*/
#define EXTI_CONF1_PBLIS (1 << 0)
/* 0: Port D is used for interrupt generation
   1: Port H is used for interrupt generation
*/
#define EXTI_CONF2_PHDS
/* 0: Port B is used for interrupt generation
   1: Port G is used for interrupt generation
*/
#define EXTI_CONF2_PGBS
/* 0: PH[7:4] are used for EXTI7-EXTI4 interrupt generation
   1: PH[7:4] are used for EXTIH interrupt generation
*/
#define EXTI_CONF2_PHHIS
/* 0: PH[3:0] are used for EXTI3-EXTI0 interrupt generation
   1: PH[3:0] are used for EXTIH interrupt generation
*/
#define EXTI_CONF2_PHLIS
/* 0: PG[7:4] are used for EXTI7-EXTI4 interrupt generation
   1: PG[7:4] are used for EXTIG interrupt generation
*/
#define EXTI_CONF2_PGHIS
/* 0: PG[3:0] are used for EXTI3-EXTI0 interrupt generation
   1: PG[3:0] are used for EXTIG interrupt generation
*/
#define EXTI_CONF2_PGLIS
/* 0: PF[7:4] are used for EXTI7-EXTI4 interrupt generation
   1: PF[7:4] are used for EXTIF interrupt generation
*/
#define EXTI_CONF2_PFHIS

#endif
