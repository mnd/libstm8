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

/* is active level has been detected on the break input */
#define TIM_SR1_BIF	(1 << 7)
#define TIM_SR1_TIF	(1 << 6) /* Trigger interrupt pending */
#define TIM_SR1_COMIF	(1 << 5) /* COM interrupt pending. CC bits updated */
#define TIM_SR1_CC4IF	(1 << 4)
#define TIM_SR1_CC3IF	(1 << 3)
#define TIM_SR1_CC2IF	(1 << 2)
/* If channel CC1 is configured as output:
   This flag is set by hardware when the counter matches the compare value.
   0: No match
   1: The content of the counter register TIM1_CNT matches the content
      of the TIM1_CCR1 register

   If channel CC1 is configured as input:
   This bit is set by hardware on a capture.
   0: No input capture has occurred
   1: The counter value has been captured in the TIM1_CCR1 register (an edge
      has been detected on IC1 which matches the selected polarity).
*/
#define TIM_SR1_CC1IF	(1 << 1)
/* Update interrupt flag.
   0: No update has occurred
   1: Update interrupt pending.
   This bit is set by hardware when the registers are updated:
   – At overflow or underflow if UDIS = 0 in the TIM1_CR1 register
   – When CNT is re-initialized by software using the UG bit in TIM1_EGR register,
     if URS = 0 and UDIS = 0 in the TIM1_CR1 register.
   – When CNT is re-initialized by a trigger event (refer to the TIM1_SMCR
     register description), if URS = 0 and UDIS = 0 in the TIM1_CR1 register.
*/
#define TIM_SR1_UIF	(1 << 0)

/* This flags is set by hardware only when the corresponding channel
   is configured in input capture mode.
   0: No overcapture has been detected
   1: The counter value has been captured in TIM1_CCR1 register while CC1IF flag
      was already set.
*/
#define TIM_SR2_CC4OF	(1 << 4) /* Capture/compare 4 overcapture flag */
#define TIM_SR2_CC3OF	(1 << 3)
#define TIM_SR2_CC2OF	(1 << 2)
#define TIM_SR2_CC1OF	(1 << 1)

/* set to generate a break event. The MOE bit is cleared and the BIF flag is set.
   An interrupt is generated if enabled by the BIE bit. */
#define TIM_EGR_BG	(1 << 7)
/* Trigger generation. 1: The TIF flag is set in TIMx_SR1 register.
   An interrupt is generated if enabled by the TIE bit. */
#define TIM_EGR_TG	(1 << 6)
/* Capture/compare control update generation.
   1: When the CCPC bit in the TIMx_CR2 register is set,
      it allows the CCiE, CCiNE CCiP, CCiNP, and OCiM bits to be updated.
*/
#define TIM_EGR_COMG	(1 << 5)
#define TIM_EGR_CC4G	(1 << 4)
#define TIM_EGR_CC3G	(1 << 3)
#define TIM_EGR_CC2G	(1 << 2)
/* Capture/compare 1 generation.
   0: No action
   1: A capture/compare event is generated on channel 1:
   If the CC1 channel is configured in output mode:
     The CC1IF flag is set and the corresponding interrupt request
     is sent if enabled.
   If the CC1 channel is configured in input mode:
     The current value of the counter is captured in the TIM1_CCR1 register.
     The CC1IF flag is set, and the corresponding interrupt request is sent
     if enabled. The CC1OF flag is set if the CC1IF flag is already high.
*/
#define TIM_EGR_CC1G	(1 << 1)
/* Update generation.
   Re-initializes the counter and generates an update of the registers.
   Note that the prescaler counter is also cleared. The counter is cleared
   if center-aligned mode is selected or if DIR = 0 (up-counting).
   Otherwise, it takes the auto-reload value (TIM1_ARR) if DIR = 1 (down-counting)
*/
#define TIM_EGR_UG	(1 << 0)

/* CHANNEL CONFIGURED IN OUTPUT */

/* Output compare 1 clear enable
   0: OC1REF is not affected by the OCREFCLR internal signal
   1: OC1REF is cleared as soon as a high level is detected on the
      OCREFCLR internal signal
*/
#define TIM_CCMR1_OC1CE	(1 << 7)
/* Output compare 1 preload enable
   0: Preload register on TIM1_CCR1 disabled. TIM1_CCR1 can be written at anytime.
      The new value is taken into account immediately.
   1: Preload register on TIM1_CCR1 enabled. Read/write operations access
      the preload register. TIM1_CCR1 preload value is loaded in the shadow
      register at each UEV.
*/
#define TIM_CCMR1_OC1PE	(1 << 3)
/* Output compare 1 fast enable
   0: CC1 behaves normally depending on the counter and CCR1 values, even when
      the trigger is on. The minimum delay to activate CC1 output when an edge
      occurs on the trigger input, is 5 clock cycles.
   1: An active edge on the trigger input acts like a compare match on the
      CC1 output. If this happens, OC is set to the compare level irrespective
      of the result of the comparison. The delay to sample the trigger input
      and to activate CC1 output is reduced to 3 clock cycles. OCFE acts
      only if the channel is configured in PWM1 or PWM2 mode.
*/
#define TIM_CCMR1_OC1FE	(1 << 2)
/* Output compare 1 mode. These bits define the behavior of the
   output reference signal, OC1REF, from which OC1 is derived.
*/
#define TIM_CCMR1_OC1M_SHIFT	4
#define TIM_CCMR1_OC1M_MASK	0x7
/* The comparison between the output compare register TIM1_CCR1 and the counter
   register TIM1_CNT has no effect on the outputs.
*/
#define TIM_CCMR1_OC1M_FROZEN	0x0
/* Set channel 1 to active level on match - OC1REF signal is forced high when
   the counter register TIM1_CNT matches the capture/compare register 1 (TIM1_CCR1)
*/
#define TIM_CCMR1_OC1M_MATCH_ACTIVE	0x1
#define TIM_CCMR1_OC1M_MATCH_INACTIVE	0x2 /* inactive level on match */
#define TIM_CCMR1_OC1M_TOGGLE	0x3 /* OC1REF toggles when TIM1_CNT = TIM1_CCR1 */
#define TIM_CCMR1_OC1M_FORCE_INACTIVE	0x4 /* OC1REF is forced low */
#define TIM_CCMR1_OC1M_FORCE_ACTIVE	0x5 /* OC1REF is forced high */
/* PWM mode 1 - In up-counting, channel 1 is active as long as
   TIM1_CNT < TIM1_CCR1, otherwise, the channel is inactive. In down-counting,
   channel 1 is inactive (OC1REF = 0) as long as TIM1_CNT > TIM1_CCR1,
   otherwise, the channel is active (OC1REF = 1).
*/
#define TIM_CCMR1_OC1M_PWM_1	0x6
#define TIM_CCMR1_OC1M_PWM_2	0x7 /* PWM mode 2 -- reverse rules from mode 1 */
/* Capture/compare 1 selection. This bitfield defines the direction of the
   channel (input/output) as well as the used input.
*/
#define TIM_CCMR1_CC1S_SHIFT	0
#define TIM_CCMR1_CC1S_MASK	0x3
#define TIM_CCMR1_CC1S_OUTPUT	0x0 /* CC1 channel is configured as output */
#define TIM_CCMR1_CC1S_INPUT_TI1FP1 0x1 /* CC1 input. IC1 is mapped on TI1FP1 */
#define TIM_CCMR1_CC1S_INPUT_TI2FP1 0x2 /* CC1 input. IC1 is mapped on TI2FP1 */
/* CC1 channel is configured as input, IC1 is mapped on TRC.
   This mode works only if an internal trigger input is selected
   through the TS bit (TIM1_SMCR register).
*/
#define TIM_CCMR1_CC1S_INPUT_TRC	0x3

/* CHANNEL CONFIGURED IN INPUT */

/* Input capture 1 filter. This bitfield defines f SAMPLING, the frequency
   used to sample TI1 input and the length of the digital filter applied to TI1.
   The digital filter is made of an event counter in which N events are needed
   to validate a transition on the output:
*/
#define TIM_CCMR1_IC1F_SHIFT	4
#define TIM_CCMR1_IC1F_MASK	0xF
#define TIM_CCMR1_IC1F_NONE	0x0 /* No filter, sampling is done at f_SYSCLK */
#define TIM_CCMR1_IC1F_1_2	0x1 /* f_SAMPLING = f_SYSCLK / 1 , N = 2 */
#define TIM_CCMR1_IC1F_1_4	0x2
#define TIM_CCMR1_IC1F_1_8	0x3
#define TIM_CCMR1_IC1F_2_6	0x4
#define TIM_CCMR1_IC1F_2_8	0x5
#define TIM_CCMR1_IC1F_4_6	0x6
#define TIM_CCMR1_IC1F_4_8	0x7
#define TIM_CCMR1_IC1F_8_6	0x8
#define TIM_CCMR1_IC1F_8_8	0x9
#define TIM_CCMR1_IC1F_16_5	0xA
#define TIM_CCMR1_IC1F_16_6	0xB
#define TIM_CCMR1_IC1F_16_8	0xC
#define TIM_CCMR1_IC1F_32_5	0xD
#define TIM_CCMR1_IC1F_32_6	0xE
#define TIM_CCMR1_IC1F_32_8	0xF /* f_SAMPLING = f_SYSCLK / 32 , N = 8 */
/* This bitfield defines the ratio of the prescaler acting on CC1 input (IC1).
   The prescaler is reset as soon as CC1E = 0 (TIM1_CCER register).
*/
#define TIM_CCMR1_IC1PSC_SHIFT	2
#define TIM_CCMR1_IC1PSC_MASK	0x3
/* No prescaler, capture is made each time an edge is detected on capture input */
#define TIM_CCMR1_IC1PSC_1	0x0
#define TIM_CCMR1_IC1PSC_2	0x1 /* Capture is made once every 2 events */
#define TIM_CCMR1_IC1PSC_4	0x2
#define TIM_CCMR1_IC1PSC_8	0x3 /* Capture is made once every 8 events */
/* TIM_CCMR1_CC1S same as before for output */


/* CHANNEL CONFIGURED IN OUTPUT */
#define TIM_CCMR2_OC2CE TIM_CCMR1_OC1CE
#define TIM_CCMR2_OC2PE	TIM_CCMR1_OC1PE
#define TIM_CCMR2_OC2FE	TIM_CCMR1_OC1FE
#define TIM_CCMR2_OC2M_SHIFT	TIM_CCMR1_OC1M_SHIFT
#define TIM_CCMR2_OC2M_MASK	TIM_CCMR1_OC1M_MASK
#define TIM_CCMR2_OC2M_FROZEN	TIM_CCMR1_OC1M_FROZEN
#define TIM_CCMR2_OC2M_MATCH_ACTIVE	TIM_CCMR1_OC1M_MATCH_ACTIVE
#define TIM_CCMR2_OC2M_MATCH_INACTIVE	TIM_CCMR1_OC1M_MATCH_INACTIVE
#define TIM_CCMR2_OC2M_TOGGLE	TIM_CCMR1_OC1M_TOGGLE
#define TIM_CCMR2_OC2M_FORCE_INACTIVE	TIM_CCMR1_OC1M_FORCE_INACTIVE
#define TIM_CCMR2_OC2M_FORCE_ACTIVE	TIM_CCMR1_OC1M_FORCE_ACTIVE
#define TIM_CCMR2_OC2M_PWM_1	TIM_CCMR1_OC1M_PWM_1
#define TIM_CCMR2_OC2M_PWM_2	TIM_CCMR1_OC1M_PWM_2
#define TIM_CCMR2_CC2S_SHIFT	TIM_CCMR1_CC1S_SHIFT
#define TIM_CCMR2_CC2S_MASK	TIM_CCMR1_CC1S_MASK
#define TIM_CCMR2_CC2S_OUTPUT	TIM_CCMR1_CC1S_OUTPUT
#define TIM_CCMR2_CC2S_INPUT_TI1FP2 TIM_CCMR1_CC1S_INPUT_TI1FP1
#define TIM_CCMR2_CC2S_INPUT_TI2FP2 TIM_CCMR1_CC1S_INPUT_TI2FP1
#define TIM_CCMR2_CC2S_INPUT_TRC	TIM_CCMR1_CC1S_INPUT_TRC
/* CHANNEL CONFIGURED IN INPUT */
#define TIM_CCMR2_IC2F_SHIFT	TIM_CCMR1_IC1F_SHIFT
#define TIM_CCMR2_IC2F_MASK	TIM_CCMR1_IC1F_MASK
#define TIM_CCMR2_IC2F_NONE	TIM_CCMR1_IC1F_NONE
#define TIM_CCMR2_IC2F_1_2	TIM_CCMR1_IC1F_1_2
#define TIM_CCMR2_IC2F_1_4	TIM_CCMR1_IC1F_1_4
#define TIM_CCMR2_IC2F_1_8	TIM_CCMR1_IC1F_1_8
#define TIM_CCMR2_IC2F_2_6	TIM_CCMR1_IC1F_2_6
#define TIM_CCMR2_IC2F_2_8	TIM_CCMR1_IC1F_2_8
#define TIM_CCMR2_IC2F_4_6	TIM_CCMR1_IC1F_4_6
#define TIM_CCMR2_IC2F_4_8	TIM_CCMR1_IC1F_4_8
#define TIM_CCMR2_IC2F_8_6	TIM_CCMR1_IC1F_8_6
#define TIM_CCMR2_IC2F_8_8	TIM_CCMR1_IC1F_8_8
#define TIM_CCMR2_IC2F_16_5	TIM_CCMR1_IC1F_16_5
#define TIM_CCMR2_IC2F_16_6	TIM_CCMR1_IC1F_16_6
#define TIM_CCMR2_IC2F_16_8	TIM_CCMR1_IC1F_16_8
#define TIM_CCMR2_IC2F_32_5	TIM_CCMR1_IC1F_32_5
#define TIM_CCMR2_IC2F_32_6	TIM_CCMR1_IC1F_32_6
#define TIM_CCMR2_IC2F_32_8	TIM_CCMR1_IC1F_32_8
#define TIM_CCMR2_IC2PSC_SHIFT	TIM_CCMR1_IC1PSC_SHIFT
#define TIM_CCMR2_IC2PSC_MASK	TIM_CCMR1_IC1PSC_MASK
#define TIM_CCMR2_IC2PSC_1	TIM_CCMR1_IC1PSC_1
#define TIM_CCMR2_IC2PSC_2	TIM_CCMR1_IC1PSC_2
#define TIM_CCMR2_IC2PSC_4	TIM_CCMR1_IC1PSC_4
#define TIM_CCMR2_IC2PSC_8	TIM_CCMR1_IC1PSC_8
/* TIM_CCMR2_CC2S same as before for output */

/* CHANNEL CONFIGURED IN OUTPUT */
#define TIM_CCMR3_OC3CE TIM_CCMR1_OC1CE
#define TIM_CCMR3_OC3PE	TIM_CCMR1_OC1PE
#define TIM_CCMR3_OC3FE	TIM_CCMR1_OC1FE
#define TIM_CCMR3_OC3M_SHIFT	TIM_CCMR1_OC1M_SHIFT
#define TIM_CCMR3_OC3M_MASK	TIM_CCMR1_OC1M_MASK
#define TIM_CCMR3_OC3M_FROZEN	TIM_CCMR1_OC1M_FROZEN
#define TIM_CCMR3_OC3M_MATCH_ACTIVE	TIM_CCMR1_OC1M_MATCH_ACTIVE
#define TIM_CCMR3_OC3M_MATCH_INACTIVE	TIM_CCMR1_OC1M_MATCH_INACTIVE
#define TIM_CCMR3_OC3M_TOGGLE	TIM_CCMR1_OC1M_TOGGLE
#define TIM_CCMR3_OC3M_FORCE_INACTIVE	TIM_CCMR1_OC1M_FORCE_INACTIVE
#define TIM_CCMR3_OC3M_FORCE_ACTIVE	TIM_CCMR1_OC1M_FORCE_ACTIVE
#define TIM_CCMR3_OC3M_PWM_1	TIM_CCMR1_OC1M_PWM_1
#define TIM_CCMR3_OC3M_PWM_2	TIM_CCMR1_OC1M_PWM_2
#define TIM_CCMR3_CC3S_SHIFT	TIM_CCMR1_CC1S_SHIFT
#define TIM_CCMR3_CC3S_MASK	TIM_CCMR1_CC1S_MASK
#define TIM_CCMR3_CC3S_OUTPUT	TIM_CCMR1_CC1S_OUTPUT
#define TIM_CCMR3_CC3S_INPUT_TI3FP3 TIM_CCMR1_CC1S_INPUT_TI1FP1
#define TIM_CCMR3_CC3S_INPUT_TRC	TIM_CCMR1_CC1S_INPUT_TRC
/* CHANNEL CONFIGURED IN INPUT */
#define TIM_CCMR3_IC3F_SHIFT	TIM_CCMR1_IC1F_SHIFT
#define TIM_CCMR3_IC3F_MASK	TIM_CCMR1_IC1F_MASK
#define TIM_CCMR3_IC3F_NONE	TIM_CCMR1_IC1F_NONE
#define TIM_CCMR3_IC3F_1_2	TIM_CCMR1_IC1F_1_2
#define TIM_CCMR3_IC3F_1_4	TIM_CCMR1_IC1F_1_4
#define TIM_CCMR3_IC3F_1_8	TIM_CCMR1_IC1F_1_8
#define TIM_CCMR3_IC3F_2_6	TIM_CCMR1_IC1F_2_6
#define TIM_CCMR3_IC3F_2_8	TIM_CCMR1_IC1F_2_8
#define TIM_CCMR3_IC3F_4_6	TIM_CCMR1_IC1F_4_6
#define TIM_CCMR3_IC3F_4_8	TIM_CCMR1_IC1F_4_8
#define TIM_CCMR3_IC3F_8_6	TIM_CCMR1_IC1F_8_6
#define TIM_CCMR3_IC3F_8_8	TIM_CCMR1_IC1F_8_8
#define TIM_CCMR3_IC3F_16_5	TIM_CCMR1_IC1F_16_5
#define TIM_CCMR3_IC3F_16_6	TIM_CCMR1_IC1F_16_6
#define TIM_CCMR3_IC3F_16_8	TIM_CCMR1_IC1F_16_8
#define TIM_CCMR3_IC3F_32_5	TIM_CCMR1_IC1F_32_5
#define TIM_CCMR3_IC3F_32_6	TIM_CCMR1_IC1F_32_6
#define TIM_CCMR3_IC3F_32_8	TIM_CCMR1_IC1F_32_8
#define TIM_CCMR3_IC3PSC_SHIFT	TIM_CCMR1_IC1PSC_SHIFT
#define TIM_CCMR3_IC3PSC_MASK	TIM_CCMR1_IC1PSC_MASK
#define TIM_CCMR3_IC3PSC_1	TIM_CCMR1_IC1PSC_1
#define TIM_CCMR3_IC3PSC_2	TIM_CCMR1_IC1PSC_2
#define TIM_CCMR3_IC3PSC_4	TIM_CCMR1_IC1PSC_4
#define TIM_CCMR3_IC3PSC_8	TIM_CCMR1_IC1PSC_8
/* TIM_CCMR3_CC3S same as before for output */

/* CHANNEL CONFIGURED IN OUTPUT */
#define TIM_CCMR4_OC4CE TIM_CCMR1_OC1CE
#define TIM_CCMR4_OC4PE	TIM_CCMR1_OC1PE
#define TIM_CCMR4_OC4M_SHIFT	TIM_CCMR1_OC1M_SHIFT
#define TIM_CCMR4_OC4M_MASK	TIM_CCMR1_OC1M_MASK
#define TIM_CCMR4_OC4M_FROZEN	TIM_CCMR1_OC1M_FROZEN
#define TIM_CCMR4_OC4M_MATCH_ACTIVE	TIM_CCMR1_OC1M_MATCH_ACTIVE
#define TIM_CCMR4_OC4M_MATCH_INACTIVE	TIM_CCMR1_OC1M_MATCH_INACTIVE
#define TIM_CCMR4_OC4M_TOGGLE	TIM_CCMR1_OC1M_TOGGLE
#define TIM_CCMR4_OC4M_FORCE_INACTIVE	TIM_CCMR1_OC1M_FORCE_INACTIVE
#define TIM_CCMR4_OC4M_FORCE_ACTIVE	TIM_CCMR1_OC1M_FORCE_ACTIVE
#define TIM_CCMR4_OC4M_PWM_1	TIM_CCMR1_OC1M_PWM_1
#define TIM_CCMR4_OC4M_PWM_2	TIM_CCMR1_OC1M_PWM_2
#define TIM_CCMR4_CC4S_SHIFT	TIM_CCMR1_CC1S_SHIFT
#define TIM_CCMR4_CC4S_MASK	TIM_CCMR1_CC1S_MASK
#define TIM_CCMR4_CC4S_OUTPUT	TIM_CCMR1_CC1S_OUTPUT
#define TIM_CCMR4_CC4S_INPUT_TI3FP4 TIM_CCMR1_CC1S_INPUT_TI2FP1
#define TIM_CCMR4_CC4S_INPUT_TRC	TIM_CCMR1_CC1S_INPUT_TRC
/* CHANNEL CONFIGURED IN INPUT */
#define TIM_CCMR4_IC4F_SHIFT	TIM_CCMR1_IC1F_SHIFT
#define TIM_CCMR4_IC4F_MASK	TIM_CCMR1_IC1F_MASK
#define TIM_CCMR4_IC4F_NONE	TIM_CCMR1_IC1F_NONE
#define TIM_CCMR4_IC4F_1_2	TIM_CCMR1_IC1F_1_2
#define TIM_CCMR4_IC4F_1_4	TIM_CCMR1_IC1F_1_4
#define TIM_CCMR4_IC4F_1_8	TIM_CCMR1_IC1F_1_8
#define TIM_CCMR4_IC4F_2_6	TIM_CCMR1_IC1F_2_6
#define TIM_CCMR4_IC4F_2_8	TIM_CCMR1_IC1F_2_8
#define TIM_CCMR4_IC4F_4_6	TIM_CCMR1_IC1F_4_6
#define TIM_CCMR4_IC4F_4_8	TIM_CCMR1_IC1F_4_8
#define TIM_CCMR4_IC4F_8_6	TIM_CCMR1_IC1F_8_6
#define TIM_CCMR4_IC4F_8_8	TIM_CCMR1_IC1F_8_8
#define TIM_CCMR4_IC4F_16_5	TIM_CCMR1_IC1F_16_5
#define TIM_CCMR4_IC4F_16_6	TIM_CCMR1_IC1F_16_6
#define TIM_CCMR4_IC4F_16_8	TIM_CCMR1_IC1F_16_8
#define TIM_CCMR4_IC4F_32_5	TIM_CCMR1_IC1F_32_5
#define TIM_CCMR4_IC4F_32_6	TIM_CCMR1_IC1F_32_6
#define TIM_CCMR4_IC4F_32_8	TIM_CCMR1_IC1F_32_8
#define TIM_CCMR4_IC4PSC_SHIFT	TIM_CCMR1_IC1PSC_SHIFT
#define TIM_CCMR4_IC4PSC_MASK	TIM_CCMR1_IC1PSC_MASK
#define TIM_CCMR4_IC4PSC_1	TIM_CCMR1_IC1PSC_1
#define TIM_CCMR4_IC4PSC_2	TIM_CCMR1_IC1PSC_2
#define TIM_CCMR4_IC4PSC_4	TIM_CCMR1_IC1PSC_4
#define TIM_CCMR4_IC4PSC_8	TIM_CCMR1_IC1PSC_8
/* TIM_CCMR4_CC4S same as before for output */

#define TIM_CCER1_CC2NP	(1 << 7)
#define TIM_CCER1_CC2NE	(1 << 6)
#define TIM_CCER1_CC2P	(1 << 5)
#define TIM_CCER1_CC2E	(1 << 4)
/* Capture/compare 1 complementary output polarity */
#define TIM_CCER1_CC1NP	(1 << 3) /* OC1N active high 0 / low 1 */
/* 0: Off - OC1N is not active. OC1N level is then a function of
      the MOE, OSSI, OSSR, OIS1, OIS1N and CC1E bits.
   1: On - OC1N signal is output on the corresponding output pin depending
      on the MOE, OSSI, OSSR, OIS1, OIS1N and CC1E bits.
*/
#define TIM_CCER1_CC1NE	(1 << 2)
/* CC1P: Capture/compare 1 output polarity

   CC1 channel configured as output:
   0: OC1 active high
   1: OC1 active low

   CC1 channel configured as input for trigger function (see table lower):
   0: Trigger on a high level or rising edge of TI1F
   1: Trigger on a low level or falling edge of TI1F

   CC1 channel configured as input for capture function (see table lower):
   0: Capture on a rising edge of TI1F or TI2F
   1: Capture on a falling edge of TI1F or TI2F
*/
#define TIM_CCER1_CC1P	(1 << 1)
/* Capture/compare 1 output enable

   CC1 channel is configured as output:
   0: Off - OC1 is not active. OC1 level is then a function of
      the MOE, OSSI, OSSR, OIS1, OIS1N and CC1NE bits.
   1: On - OC1 signal is output on the corresponding output pin depending on
      the MOE, OSSI, OSSR, OIS1, OIS1N and CC1NE bits.

   CC1 channel is configured as input:
   This bit determines if a capture of the counter value can be made in the
   input capture/compare register 1 (TIM1_CCR1) or not:
   0: Capture disabled
   1: Capture enabled
*/
#define TIM_CCER1_CC1E	(1 << 0) /*  */
/*
|------------------------+------------------------------------------------------------|
|Control bits            | Output states                                              |
|---+----+----+----+-----+----------------------------+-------------------------------|
|MOE|OSSI|OSSR|CCiE|CCiNE| OCi                        | OCiN                          |
|---+----+----+----+-----+----------------------------+-------------------------------|
| 1 | x  |  0 |  0 |  0  | Output disabled            | Output disabled               |
|   |    |    |    |     | (not driven by the timer)  | (not driven by the timer)     |
|   |    |----+----+-----+----------------------------+-------------------------------|
|   |    |  0 |  0 |  1  | Output disabled            | OCiREF + polarity OCiN =      |
|   |    |    |    |     | (not driven by the timer)  | OCiREF xor CCiNP              |
|   |    |----+----+-----+----------------------------+-------------------------------|
|   |    |  0 |  1 |  0  | OCiREF + polarity OCi =    | Output disabled               |
|   |    |    |    |     | OCiREF xor CCiP            | (not driven by the timer)     |
|   |    |----+----+-----+----------------------------+-------------------------------|
|   |    |  0 |  1 |  1  | OCiREF + polarity +        | Complementary to OCiREF       |
|   |    |    |    |     | deadtime                   | (not OCiREF) + polarity +     |
|   |    |    |    |     |                            | deadtime                      |
|   |    |----+----+-----+----------------------------+-------------------------------|
|   |    |  1 |  0 |  0  | Output disabled            | Output disabled               |
|   |    |    |    |     | (not driven by the timer)  | (not driven by the timer)     |
|   |    |----+----+-----+----------------------------+-------------------------------|
|   |    |  1 |  0 |  1  | Off state                  | OCiREF + polarity OCiN =      |
|   |    |    |    |     | (output enabled with       | OCiREF xor CCiNP              |
|   |    |    |    |     | inactive state) OCi = CCiP |                               |
|   |    |----+----+-----+----------------------------+-------------------------------|
|   |    |  1 |  1 |  0  | OCiREF + polarity OCi =    | Off state                     |
|   |    |    |    |     | OCiREF xor CCiP            | (output enabled with inactive |
|   |    |    |    |     |                            | state) OCiN = CCiNP           |
|   |    |----+----+-----+----------------------------+-------------------------------|
|   |    |  1 |  1 |  1  | OCiREF + polarity +        | Complementary to OCiREF       |
|   |    |    |    |     | deadtime                   | (not OCiREF) + polarity +     |
|   |    |    |    |     |                            | deadtime                      |
|---+----+----+----+-----+----------------------------+-------------------------------|
| 0 | 0  |  x |  x |  x  | Output disabled (not driven by the timer)                  |
|   |----+----+----+-----+-------------------------------+----------------------------|
|   | 1  |  x |  x |  x  | Off state (output enabled with inactive state)             |
|   |    |    |    |     | Asynchronously: OCi = CCiP and OCiN = CCiNP                |
|   |    |    |    |     | Then if the clock is present: OCi = OISi and OCiN = OISiN  |
|   |    |    |    |     | after a deadtime, assuming that OISi and OISiN do not      |
|   |    |    |    |     | correspond with OCi and OCiN in active state               |
|---+----+----+----+-----+-------------------------------+----------------------------|
*/

/* same description as before */
#define TIM_CCER2_CC4P	(1 << 5)
#define TIM_CCER2_CC4E	(1 << 4)
#define TIM_CCER2_CC3NP	(1 << 3)
#define TIM_CCER2_CC3NE	(1 << 2)
#define TIM_CCER2_CC3P	(1 << 1)
#define TIM_CCER2_CC3E	(1 << 0)

/* TIM_CNTRH:TIM_CNTRL -- 16 bit counter value */
/* TIM_PSCRH:TIM_PSCRL -- 16 bit prescaler register
   The counter clock frequency f CK_CNT is equal to f CK_PSC / (PSCR[15:0]+1).
*/
/* TIM_ARRH:TIM_ARRL -- 16 bit auto-reload value */
/* TIM_RCR -- Repetition counter value (REP).

   When the preload registers are enabled, these bits allow the user to set up
   the update rate of the compare registers (periodic transfers from preload to
   shadow registers) as well as the update interrupt generation rate if the
   update interrupt is enabled (UIE=1). Each time the REP_CNT related
   down-counter reaches zero, a UEV is generated and it restarts counting from
   the REP value. As REP_CNT is reloaded with the REP value only at the
   repetition update event U_RC, any write to the TIM1_RCR register is not taken
   into account until the next repetition update event.

   In PWM mode (REP+1) corresponds to:
   – The number of PWM periods in edge-aligned mode
   – The number of half PWM periods in center-aligned mode
*/
/* TIM_CCR1H:TIM_CCR1L -- 16 bit capture/compare 1 value.

   If the CC1 channel is configured as output (CC1S bits in TIM1_CCMR1 register):
   The value of CCR1 is loaded permanently into the actual capture/compare 1
   register if the preload feature is enabled (OC1PE bit in
   TIMx_CCMR1). Otherwise, the preload value is copied in the active
   capture/compare 1 register when a UEV occurs. The active capture/compare
   register contains the value which is compared to the counter register,
   TIMx_CNT, and signalled on the OC1 output.

   If the CC1 channel is configured as input (CC1S bits in TIM1_CCMR1 register):
   The value of CCR1 is the counter value transferred by the last input capture
   1 event (IC1). In this case, these bits are read only.
*/

#define TIM_BKR_MOE	(1 << 7) /* Main output enable. is OC and OCN enabled */
/* Automatic output enable. MOE can be set by UEV */
#define TIM_BKR_AOE	(1 << 6)
#define TIM_BKR_BKP	(1 << 5) /* Break input BKIN is active low 0 / high 1 */
#define TIM_BKR_BKE	(1 << 4) /* is Break input (BKIN) enabled */
/* Off state selection for Run mode.
   This bit is used when MOE = 1 on channels with a complementary output
   which are configured as outputs.
   0: When inactive, OC/OCN outputs are disabled (OC/OCN enable output signal = 0)
   1: When inactive, OC/OCN outputs are enabled with their inactive level
      as soon as CCiE = 1 or CCiNE = 1, after which the OC/OCN enable
      output signal = 1
*/
#define TIM_BKR_OSSR	(1 << 3)
/* Off state selection for idle mode
   This bit is used when MOE = 0 on channels configured as outputs.
   0: When inactive, OCi outputs are disabled (OCi enable output signal = 0)
   1: When inactive, OCi outputs are forced first with their idle level
      as soon as CCiE = 1 (OC enable output signal = 1)
*/
#define TIM_BKR_OSSI	(1 << 2)
/* Lock configuration
   These bits offer a write protection against software errors.
*/
#define TIM_BKR_LOCK_SHIFT	0
#define TIM_BKR_LOCK_MASK	0x3
#define TIM_BKR_LOCK_OFF	0x0 /* No bits are write protected */
/* OISi bit in TIM1_OISR register and BKE/BKP/AOE bits in TIM1_BKR register
   can no longer be written.
*/
#define TIM_BKR_LOCK_1		0x1
/* LOCK level 1 + CC polarity bits (CCiP bits in TIM1_CCERi registers, as long
   as the related channel is configured in output through the CCiS bits) as well
   as the OSSR and OSSI bits can no longer be written.
*/
#define TIM_BKR_LOCK_2		0x2
/* LOCK level 2 + CC control bits (OCiM and OCiPE bits in TIM1_CCMRi registers,
   as long as the related channel is configured in output through the CCiS bits)
   can no longer be written.
*/
#define TIM_BKR_LOCK_3		0x3


#endif
