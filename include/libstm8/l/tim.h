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
#ifndef TIM_H
#define TIM_H

#include <libstm8/common.h>

/* TIM1 16-bit advanced control timer */
#define TIM1_BASE  0x0052B0
#define TIM1_CR1   MMIO8(TIM1_BASE + 0x0)
#define TIM1_CR2   MMIO8(TIM1_BASE + 0x1)
#define TIM1_SMCR  MMIO8(TIM1_BASE + 0x2)
#define TIM1_ETR   MMIO8(TIM1_BASE + 0x3)
#define TIM1_DER   MMIO8(TIM1_BASE + 0x4)
#define TIM1_IER   MMIO8(TIM1_BASE + 0x5)
#define TIM1_SR1   MMIO8(TIM1_BASE + 0x6)
#define TIM1_SR2   MMIO8(TIM1_BASE + 0x7)
#define TIM1_EGR   MMIO8(TIM1_BASE + 0x8)
#define TIM1_CCMR1 MMIO8(TIM1_BASE + 0x9)
#define TIM1_CCMR2 MMIO8(TIM1_BASE + 0xA)
#define TIM1_CCMR3 MMIO8(TIM1_BASE + 0xB)
#define TIM1_CCMR4 MMIO8(TIM1_BASE + 0xC)
#define TIM1_CCER1 MMIO8(TIM1_BASE + 0xD)
#define TIM1_CCER2 MMIO8(TIM1_BASE + 0xE)
#define TIM1_CNTRH MMIO8(TIM1_BASE + 0xF)
#define TIM1_CNTRL MMIO8(TIM1_BASE + 0x10)
#define TIM1_PSCRH MMIO8(TIM1_BASE + 0x11)
#define TIM1_PSCRL MMIO8(TIM1_BASE + 0x12)
#define TIM1_ARRH  MMIO8(TIM1_BASE + 0x13)
#define TIM1_ARRL  MMIO8(TIM1_BASE + 0x14)
#define TIM1_RCR   MMIO8(TIM1_BASE + 0x15) /* TIM1 Repetition counter register */
#define TIM1_CCR1H MMIO8(TIM1_BASE + 0x16)
#define TIM1_CCR1L MMIO8(TIM1_BASE + 0x17)
#define TIM1_CCR2H MMIO8(TIM1_BASE + 0x18)
#define TIM1_CCR2L MMIO8(TIM1_BASE + 0x19)
#define TIM1_CCR3H MMIO8(TIM1_BASE + 0x1A)
#define TIM1_CCR3L MMIO8(TIM1_BASE + 0x1B)
#define TIM1_CCR4H MMIO8(TIM1_BASE + 0x1C)
#define TIM1_CCR4L MMIO8(TIM1_BASE + 0x1D)
#define TIM1_BKR   MMIO8(TIM1_BASE + 0x1E)
#define TIM1_DTR   MMIO8(TIM1_BASE + 0x1F) /* TIM1 dead-time register */
#define TIM1_OISR  MMIO8(TIM1_BASE + 0x20)
#define TIM1_DCR1  MMIO8(TIM1_BASE + 0x21) /* DMA1 control register 1 */
#define TIM1_DCR2  MMIO8(TIM1_BASE + 0x22) /* DMA1 control register 2 */
#define TIM1_DMA1R MMIO8(TIM1_BASE + 0x23) /* TIM1 DMA1 address for burst mode */



/* 16-bit general purpose timers TIM 2,3,5 */

#define TIM2_BASE  0x005250
#define TIM2_CR1   MMIO8(TIM2_BASE + 0x0) /* TIM2 control register 1 */
#define TIM2_CR2   MMIO8(TIM2_BASE + 0x1) /* TIM2 control register 2 */
#define TIM2_SMCR  MMIO8(TIM2_BASE + 0x2) /* TIM2 Slave mode control register */
#define TIM2_ETR   MMIO8(TIM2_BASE + 0x3) /* TIM2 external trigger register */
#define TIM2_DER   MMIO8(TIM2_BASE + 0x4) /* TIM2 DMA1 request enable register */
#define TIM2_IER   MMIO8(TIM2_BASE + 0x5) /* TIM2 interrupt enable register */
#define TIM2_SR1   MMIO8(TIM2_BASE + 0x6) /* TIM2 status register 1 */
#define TIM2_SR2   MMIO8(TIM2_BASE + 0x7) /* TIM2 status register 2 */
#define TIM2_EGR   MMIO8(TIM2_BASE + 0x8) /* TIM2 event generation register */
#define TIM2_CCMR1 MMIO8(TIM2_BASE + 0x9) /* TIM2 capture/compare mode reg 1 */
#define TIM2_CCMR2 MMIO8(TIM2_BASE + 0xA) /* TIM2 capture/compare mode reg 2 */
#define TIM2_CCER1 MMIO8(TIM2_BASE + 0xB) /* TIM2 capture/compare enable reg 1 */
#define TIM2_CNTRH MMIO8(TIM2_BASE + 0xC) /* TIM2 counter high */
#define TIM2_CNTRL MMIO8(TIM2_BASE + 0xD) /* TIM2 counter low */
#define TIM2_PSCR  MMIO8(TIM2_BASE + 0xE) /* TIM2 prescaler register */
#define TIM2_ARRH  MMIO8(TIM2_BASE + 0xF) /* TIM2 auto-reload register high */
#define TIM2_ARRL  MMIO8(TIM2_BASE + 0x10) /* TIM2 auto-reload register low */
#define TIM2_CCR1H MMIO8(TIM2_BASE + 0x11) /* TIM2 capture/compare reg 1 high */
#define TIM2_CCR1L MMIO8(TIM2_BASE + 0x12) /* TIM2 capture/compare reg 1 low */
#define TIM2_CCR2H MMIO8(TIM2_BASE + 0x13) /* TIM2 capture/compare reg 2 high */
#define TIM2_CCR2L MMIO8(TIM2_BASE + 0x14) /* TIM2 capture/compare reg 2 low */
#define TIM2_BKR   MMIO8(TIM2_BASE + 0x15) /* TIM2 break register */
#define TIM2_OISR  MMIO8(TIM2_BASE + 0x16) /* TIM2 output idle state register */

#define TIM3_BASE  0x005280
#define TIM3_CR1   MMIO8(TIM3_BASE + 0x0)
#define TIM3_CR2   MMIO8(TIM3_BASE + 0x1)
#define TIM3_SMCR  MMIO8(TIM3_BASE + 0x2)
#define TIM3_ETR   MMIO8(TIM3_BASE + 0x3)
#define TIM3_DER   MMIO8(TIM3_BASE + 0x4)
#define TIM3_IER   MMIO8(TIM3_BASE + 0x5)
#define TIM3_SR1   MMIO8(TIM3_BASE + 0x6)
#define TIM3_SR2   MMIO8(TIM3_BASE + 0x7)
#define TIM3_EGR   MMIO8(TIM3_BASE + 0x8)
#define TIM3_CCMR1 MMIO8(TIM3_BASE + 0x9)
#define TIM3_CCMR2 MMIO8(TIM3_BASE + 0xA)
#define TIM3_CCER1 MMIO8(TIM3_BASE + 0xB)
#define TIM3_CNTRH MMIO8(TIM3_BASE + 0xC)
#define TIM3_CNTRL MMIO8(TIM3_BASE + 0xD)
#define TIM3_PSCR  MMIO8(TIM3_BASE + 0xE)
#define TIM3_ARRH  MMIO8(TIM3_BASE + 0xF)
#define TIM3_ARRL  MMIO8(TIM3_BASE + 0x10)
#define TIM3_CCR1H MMIO8(TIM3_BASE + 0x11)
#define TIM3_CCR1L MMIO8(TIM3_BASE + 0x12)
#define TIM3_CCR2H MMIO8(TIM3_BASE + 0x13)
#define TIM3_CCR2L MMIO8(TIM3_BASE + 0x14)
#define TIM3_BKR   MMIO8(TIM3_BASE + 0x15)
#define TIM3_OISR  MMIO8(TIM3_BASE + 0x16)


/* 8-bit basic timer TIM4 */
#define TIM4_BASE  0x0052E0
#define TIM4_CR1   MMIO8(TIM4_BASE + 0x0)
#define TIM4_CR2   MMIO8(TIM4_BASE + 0x1)
#define TIM4_SMCR  MMIO8(TIM4_BASE + 0x2)
#define TIM4_DER   MMIO8(TIM4_BASE + 0x3)
#define TIM4_IER   MMIO8(TIM4_BASE + 0x4)
#define TIM4_SR1   MMIO8(TIM4_BASE + 0x5)
#define TIM4_EGR   MMIO8(TIM4_BASE + 0x6)
#define TIM4_CNTR  MMIO8(TIM4_BASE + 0x7)
#define TIM4_PSCR  MMIO8(TIM4_BASE + 0x8)
#define TIM4_ARR   MMIO8(TIM4_BASE + 0x9)


/* is TIM1_ARR register buffered through a preload register */
#define TIM_CR1_ARPE	(1 << 7)
#define TIM_CR1_DIR	(1 << 4) /* Counter used as up 0 / down 1 counter */
/* is counter stops counting at the next update event (clearing the CEN bit) */
#define TIM_CR1_OPM	(1 << 3)
/* Update request source.
   When enabled by the UDIS bit, the UIF bit is set and an update
   interrupt request is sent when:
   0: when one of the following events occurs:
      a. Registers are updated (counter overflow/underflow)
      b. UG bit is set by software
      c. Update event is generated through the clock/trigger controller
   1: only when registers are updated (counter overflow/underflow).
*/
#define TIM_CR1_URS	(1 << 2)
/* Update disable.
   0: A UEV is generated as soon as a counter overflow occurs,
      a software update is generated, or a hardware reset is generated
      by the clock/trigger mode controller. Buffered registers are then
      loaded with their preload values.
   1: A UEV is not generated and shadow registers keep their value (ARR, PSC, CCRi)
      The counter and the prescaler are re-initialized if the UG bit is set
      or if a hardware reset is received from the clock/trigger mode controller.
*/
#define TIM_CR1_UDIS	(1 << 1)
#define TIM_CR1_CEN	(1 << 0) /* is counter enabled */
/* Center-aligned mode selection.

   Note:Encoder mode (SMS = 001, 010 or 011 in TIM1_SMCR register) must be
   disabled in center-aligned mode.
*/
#define TIM_CR1_CMS_SHIFT 5
#define TIM_CR1_CMS_MASK  0x3
/* Edge-aligned mode.
   The counter counts up or down depending on the direction bit (DIR). */
#define TIM_CR1_CMS_EA	0x0
/* Center-aligned mode 1.
   The counter counts up and down alternately. Output compare interrupt flags
   of channels configured in output (CCiS = 00 in TIMx_CCMRi registers)
   are set only when the counter is counting down.
*/
#define TIM_CR1_CMS_CA1	0x1
/* Center-aligned mode 2.
   ... are set only when the counter is counting up.
*/
#define TIM_CR1_CMS_CA2	0x2
/* Center-aligned mode 3.
   .... are set both when the counter is counting up and down.
*/
#define TIM_CR1_CMS_CA3	0x3

/* TI1 (digital filter input) selection.
   0: TI1 is connected to CH1 input pin
   1: TI1 is connected to the 3 inputs CH1, CH2 and CH3 (XORed)
*/
#define TIM_CR2_TI1S (1 << 7)
/* TIM1_CCi DMA request sent when an CCi 0 / update 1 event occurs */
#define TIM_CR2_CCDS (1 << 3)
/* When capture/compare control bits are preloaded (CCPC = 1),
   they are updated
   0: by setting the COMG bit
   1: by setting the COMG bit or when an rising edge occurs on TRGI.
*/
#define TIM_CR2_COMS (1 << 2)
/* Capture/compare preloaded control
   0: The CCiE, CCiNE, CCiP, and CCiNP bits in the TIM1_CCERi registers
      and the OCiM bit in the TIM1_CCMRi registers are not preloaded
   1: CCiE, CCiNE, CCiP, CCiNP and OCiM bits are preloaded, after having been
      written, they are updated only when COMG bit is set in the TIM1_EGR register.
*/
#define TIM_CR2_CCPC (1 << 0)
/* Master mode selection.
   These bits select the information to be sent master mode to the slave timers
   for synchronization (TRGO).
*/
#define TIM_CR2_MMS_SHIFT	4
#define TIM_CR2_MMS_MASK	0x7
/* Reset - the UG bit from the TIMx_EGR register is used as a trigger output (TRGO)
   If the reset is generated by the trigger input (clock/trigger mode controller
   configured in trigger reset mode), the signal on TRGO is delayed compared
   to the actual reset.
*/
#define TIM_CR2_MMS_RESET	0x0
/* Enable - the counter enable signal is used as a trigger output (TRGO).
   It is used to start several timers at the same time or to control a window
   in which a slave timer is enabled. The counter enable signal is generated
   by a logic OR between the CEN control bit and the trigger input when configured
   in gated mode. When the counter enable signal is controlled by the trigger
   input, there is a delay on TRGO, except if the master/slave mode is selected
   (see the MSM bit description in TIMx_SMCR register).
*/
#define TIM_CR2_MMS_ENABLE	0x1
#define TIM_CR2_MMS_UPDATE	0x2 /* The update event is selected as a TRGO */
/* Compare pulse - The trigger output sends a positive pulse when the CC1IF flag
   is to be set (even if it was already high), as soon as a capture or a compare
   match occurs (TRGO).
*/
#define TIM_CR2_MMS_COMPARE_CC1IF  0x3
#define TIM_CR2_MMS_COMPARE_OC1REF 0x4 /* OC1REF signal is used as TRGO */
#define TIM_CR2_MMS_COMPARE_OC2REF 0x5 /* OC2REF signal is used as TRGO */
#define TIM_CR2_MMS_COMPARE_OC3REF 0x6 /* OC3REF signal is used as TRGO */
#define TIM_CR2_MMS_COMPARE_OC4REF 0x7 /* OC4REF signal is used as TRGO */

/* 0: No action.
   1: The effect of an event on the trigger input (TRGI) is delayed to allow
      a perfect synchronization between TIM1 and another timer (through TRGO).
*/
#define TIM_SMCR_MSM	(1 << 7)
/* 0: OCREFCLR_Internal is connected to the OCREFCLR input
   1: OCREFCLR_Internal is connected to ETRF external trigger
*/
#define TIM_SMCR_OCCS	(1 << 3)
/* Trigger selection.
   This bitfield selects the trigger input (TRGI) to be used to synchronize the counter.
*/
#define TIM_SMCR_TS_SHIFT	4
#define TIM_SMCR_TS_MASK	0x7
#define TIM_SMCR_TS_TIM4 0x0 /* Internal trigger ITR0 connected to TIM4 TRGO */
#define TIM_SMCR_TS_TIM5 0x1 /* Internal trigger ITR0 connected to TIM5 TRGO */
#define TIM_SMCR_TS_TIM3 0x2 /* Internal trigger ITR0 connected to TIM3 TRGO */
#define TIM_SMCR_TS_TIM2 0x3 /* Internal trigger ITR0 connected to TIM2 TRGO */
#define TIM_SMCR_TS_TI1F_ED	0x4 /* TI1 edge detector (TI1F_ED) */
#define TIM_SMCR_TS_TI1FP1	0x5 /* Filtered timer input 1 (TI1FP1) */
#define TIM_SMCR_TS_TI2FP2	0x6 /* Filtered timer input 2 (TI2FP2) */
#define TIM_SMCR_TS_ETRF	0x7 /* External trigger input (ETRF) */
/* Clock/trigger/slave mode selection.
   When external signals are selected, the active edge of the trigger signal (TRGI)
   is linked to the polarity selected on the external input (see input control
   register and control register description).
*/
#define TIM_SMCR_TS_SMS_SHIFT	0
#define TIM_SMCR_TS_SMS_MASK	0x7
/* Clock/trigger controller disabled - If CEN = 1, the prescaler is clocked
   directly by the internal clock.
*/
#define TIM_SMCR_TS_SMS_DISABLE	0x0
/* Encoder mode 1 - Counter counts up or down on TI2FP2 edge
   depending on TI1FP1 level
*/
#define TIM_SMCR_TS_SMS_ENCODER1 0x1
/* Counter counts up or down on TI1FP1 edge depending on TI2FP2 level */
#define TIM_SMCR_TS_SMS_ENCODER2 0x2
/* Counter counts up or down on both TI1FP1 and TI2FP2 edges depending on
   the level of the other input.
*/
#define TIM_SMCR_TS_SMS_ENCODER3 0x3
/* Reset mode - Rising edge of the selected trigger signal (TRGI) re-initializes
   the counter and generates an update of the registers.
*/
#define TIM_SMCR_TS_SMS_RESET	0x4
/* Trigger gated mode - The counter clock is enabled when the TRGI is high.
   The counter stops (but is not reset) as soon as the trigger becomes low.
   Both start and stop of the counter are controlled.
*/
#define TIM_SMCR_TS_SMS_GATED	0x5
/* Trigger standard mode - The counter starts at a rising edge of the trigger
   TRGI (but, it is not reset). Only the start of the counter is controlled.
*/
#define TIM_SMCR_TS_SMS_STANDARD 0x6
/* External clock mode 1
   Rising edges of the selected trigger (TRGI) clock the counter
*/
#define TIM_SMCR_TS_SMS_EXTERNAL 0x7
/*
| Slave TIM | ITR0 (TS=000) | ITR1 (TS=001) | ITR2 (TS=010) | ITR3 (TS=011) |
|-----------+---------------+---------------+---------------+---------------|
| TIM2      | TIM4          | TIM1          | TIM3          |               |
| TIM3      | TIM4          | TIM1          |               | TIM2          |
|           | TIM4          | TIM1          | TIM3          | TIM2          |
*/

/* is ETR (External trigger) inverted (i.e. active at low level or falling edge) */
#define TIM_ETR_ETP	(1 << 7)
#define TIM_ETR_ECE	(1 << 6) /* is External clock mode 2 enabled. */
/* The ETRP frequency must be, at most,1/4 of f_SYSCLK frequency.
   A prescaler can be enabled to reduce ETRP frequency.
   It is useful when inputting fast external clocks.
*/
#define TIM_ETR_ETPS_SHIFT	4
#define TIM_ETR_ETPS_MASK	0x3
#define TIM_ETR_ETPS_OFF	0x0 /* Prescaler off */
#define TIM_ETR_ETPS_2		0x1 /* ETRP frequency divided by 2 */
#define TIM_ETR_ETPS_4		0x2
#define TIM_ETR_ETPS_8		0x3
/* External trigger filter.
   This bitfield defines the frequency used to sample the ETRP signal
   and the length of the digital filter applied to it. The digital filter
   is made of an event counter in which N events are needed to validate
   a transition on the output
*/
#define TIM_ETR_ETF_SHIFT	0
#define TIM_ETR_ETF_MASK	0xF
#define TIM_ETR_ETF_NONE	0x0 /* No filter, sampling is done at f_SYSCLK */
#define TIM_ETR_ETF_1_2		0x1 /* f_SAMPLING = f_SYSCLK / 1 , N = 2 */
#define TIM_ETR_ETF_1_4		0x2
#define TIM_ETR_ETF_1_8		0x3
#define TIM_ETR_ETF_2_6		0x4
#define TIM_ETR_ETF_2_8		0x5
#define TIM_ETR_ETF_4_6		0x6
#define TIM_ETR_ETF_4_8		0x7
#define TIM_ETR_ETF_8_6		0x8
#define TIM_ETR_ETF_8_8		0x9
#define TIM_ETR_ETF_16_5	0xA
#define TIM_ETR_ETF_16_6	0xB
#define TIM_ETR_ETF_16_8	0xC
#define TIM_ETR_ETF_32_5	0xD
#define TIM_ETR_ETF_32_6	0xE
#define TIM_ETR_ETF_32_8	0xF /* f_SAMPLING = f_SYSCLK / 32 , N = 8 */

#define TIM_DER_COMDE	(1 << 5) /* is commutation DMA request enabled */
#define TIM_DER_CC4DE	(1 << 4) /* is capture/compare 4 DMA request enabled */
#define TIM_DER_CC3DE	(1 << 3) /* is CC3 DMA request enabled */
#define TIM_DER_CC2DE	(1 << 2) /* is CC2 DMA request enabled */
#define TIM_DER_CC1DE	(1 << 1) /* is CC1 DMA request enabled */
#define TIM_DER_UDE	(1 << 0) /* is update DMA request enabled */

#define TIM_IER_BIE	(1 << 7) /* Break interrupt enabled */
#define TIM_IER_TIE	(1 << 6) /* Trigger interrupt enabled */
#define TIM_IER_COMIE	(1 << 5) /* Commutation interrupt enabled */
#define TIM_IER_CC4IE	(1 << 4) /* CC4 interrupt enabled */
#define TIM_IER_CC3IE	(1 << 3) /* CC3 interrupt enabled */
#define TIM_IER_CC2IE	(1 << 2) /* CC2 interrupt enabled */
#define TIM_IER_CC1IE	(1 << 1) /* CC1 interrupt enabled */
#define TIM_IER_UIE	(1 << 0) /* Update interrupt enabled */

#endif
