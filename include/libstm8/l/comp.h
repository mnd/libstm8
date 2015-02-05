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
#ifndef COMP_H
#define COMP_H

#include <libstm8/common.h>

#define COMP_CSR1 MMIO8(0x005440) /* Comparator control and status register 1 */
#define COMP_CSR2 MMIO8(0x005441) /* Comparator control and status register 2 */
#define COMP_CSR3 MMIO8(0x005442) /* Comparator control and status register 3 */
#define COMP_CSR4 MMIO8(0x005443) /* Comparator control and status register 4 */
#define COMP_CSR5 MMIO8(0x005444) /* Comparator control and status register 5 */

#define COMP_CSR1_IE1	(1 << 5) /* is comparator 1 interrupt enabled */
#define COMP_CSR1_EF1	(1 << 4) /* is event detected at comparator 1 */
/* Comparator 1 output is low when non inverting input is at lower voltage
   than inverting input, otherwise comparator 1 output is high. */
#define COMP_CSR1_CMP1OUT (1 << 3) /* comparator 1 output */
#define COMP_CSR1_STE	(1 << 2)   /* is Schmitt trigger enabled */
/* Comparator 1 configuration */
#define COMP_CSR1_CMP1_SHIFT	0
#define COMP_CSR1_CMP1_MASK	0x3
#define COMP_CSR1_CMP1_DISABLED	0x0
/* Event detection on the falling/raising/both edge of comparator 1 output */
#define COMP_CSR1_CMP1_FALLING	0x1
#define COMP_CSR1_CMP1_RISING	0x2
#define COMP_CSR1_CMP1_BOTH	0x3


#define COMP_CSR2_IE2	(1 << 5) /* is comparator 2 interrupt enabled */
#define COMP_CSR2_EF2	(1 << 4) /* is event detected at comparator 2 */
#define COMP_CSR2_CMP2OUT (1 << 3) /* comparator 2 output */
#define COMP_CSR2_SPEED	(1 << 2)   /* Comparator 2 slow 0 / fast 1 speed mode */
/* Comparator 2 configuration */
#define COMP_CSR2_CMP2_SHIFT	0
#define COMP_CSR2_CMP2_MASK	0x3
#define COMP_CSR2_CMP2_DISABLED	0x0
/* Event detection on the falling/raising/both edge of comparator 2 output */
#define COMP_CSR2_CMP2_FALLING	0x1
#define COMP_CSR2_CMP2_RISING	0x2
#define COMP_CSR2_CMP2_BOTH	0x3

/* Comparator 2 output selection */
#define COMP_CSR3_OUTSEL_SHIFT	6
#define COMP_CSR3_OUTSEL_MASK	0x3
/* COMP2 output connected to Timer 2 input capture 2.
   The corresponding input capture from the I/O is no more available.
*/
#define COMP_CSR3_OUTSEL_TIM2_IC2 0x0
/* COMP2 output connected to Timer 3 input capture 2. 
   The corresponding input capture from the I/O is no more available.
*/
#define COMP_CSR3_OUTSEL_TIM3_IC2 0x1
/* COMP2 output connected to Timer 1 break input. 
   The break input from the I/O is no more available.
*/
#define COMP_CSR3_OUTSEL_TIM1_BRK 0x2
/* COMP2 output connected to Timer 1 OCREF clear */
#define COMP_CSR3_OUTSEL_TIM1_OCREFCLR 0x3

/* Comparator 2 inverting input selection */
#define COMP_CSR3_INSEL_SHIFT	3
#define COMP_CSR3_INSEL_MASK	0x7
#define COMP_CSR3_INSEL_NONE	0x0 /* no selection */
#define COMP_CSR3_INSEL_IO	0x1 /* Group 2 of I/Os */
#define COMP_CSR3_INSEL_VREFINT	0x2 /* Internal reference voltage V_REFINT */
#define COMP_CSR3_INSEL_VREFINT_34 0x3 /* 3/4 * V_REFINT */
#define COMP_CSR3_INSEL_VREFINT_12 0x4 /* 1/2 * V_REFINT */
#define COMP_CSR3_INSEL_VREFINT_14 0x5 /* 1/4 * V_REFINT */
#define COMP_CSR3_INSEL_DAC1	0x6    /* DAC1 */
#define COMP_CSR3_INSEL_DAC2	0x7    /* DAC2 */

#define COMP_CSR3_VREFEN (1 << 2) /* V_REFINT connected to COMP1 inverting input */
#define COMP_CSR3_WNDWE  (1 << 1) /* is Window mode enabled */
#define COMP_CSR3_VREFOUTEN (1 << 0) /* V_REFINT output enabled */

/* NOTE: About IO groups look at the end of <libstm8/ri.h>.

   When the trigger is disabled on an I/O, the associated bit in Px_IDR register 
   is always read as 0 even if another level is present on the pin.
*/

/* These bits control the Schmitt triggers of all the I/Os belonging 
   to the I/O group 8, corresponding to the COMP2 non inverting inputs.
*/
#define COMP_CSR4_NINVTRIG_PD1 (1 << 5)
#define COMP_CSR4_NINVTRIG_PD0 (1 << 4)
#define COMP_CSR4_NINVTRIG_PE5 (1 << 3)
/* These bits control the Schmitt triggers of all the I/Os belonging
   to the I/O group 2, corresponding to the COMP2 inverting inputs.
*/
#define COMP_CSR4_INVTRIG_PC7 (1 << 2)
#define COMP_CSR4_INVTRIG_PC4 (1 << 1)
#define COMP_CSR4_INVTRIG_PC3 (1 << 0)

/* These bits control the Schmitt triggers of all the I/Os belonging 
   to the I/O group 5, corresponding to the DAC outputs.
*/
#define COMP_CSR5_DACTRIG_PB4 (1 << 5)
#define COMP_CSR5_DACTRIG_PB5 (1 << 4)
#define COMP_CSR5_DACTRIG_PB6 (1 << 3)
/* These bits control the Schmitt triggers of all the I/Os belonging
   to the I/O group 3, corresponding to the V REFINT outputs.
*/
#define COMP_CSR5_VREFTRIG_PD6 (1 << 2)
#define COMP_CSR5_VREFTRIG_PD7 (1 << 1)
#define COMP_CSR5_VREFTRIG_PC2 (1 << 0)

#endif
