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
#ifndef DAC_H
#define DAC_H

#include <libstm8/common.h>

#define DAC_BASE	0x005380
#define DAC_CHxCR1(n)	MMIO8(DAC_BASE + 0x0 + 0x2 * (n - 1))
#define DAC_CHxCR2(n)	MMIO8(DAC_BASE + 0x1 + 0x2 * (n - 1))
#define DAC_CHxRDHRH(n)	MMIO8(DAC_BASE + 0x8 + 0xC * (n - 1))
#define DAC_CHxRDHRL(n)	MMIO8(DAC_BASE + 0x9 + 0xC * (n - 1))
#define DAC_CHxLDHRH(n)	MMIO8(DAC_BASE + 0xC + 0xC * (n - 1))
#define DAC_CHxLDHRL(n)	MMIO8(DAC_BASE + 0xD + 0xC * (n - 1))
#define DAC_CHxDHR8(n)	MMIO8(DAC_BASE + 0x10 + 0xC * (n - 1))
#define DAC_CHxDORH(n)	MMIO8(DAC_BASE + 0x2C + 0x4 * (n - 1))
#define DAC_CHxDORL(n)	MMIO8(DAC_BASE + 0x2D + 0x4 * (n - 1))

#define DAC_DCHxRDHRH(n) MMIO8(DAC_BASE + 0x20 + 0x2 * (n - 1))
#define DAC_DCHxRDHRL(n) MMIO8(DAC_BASE + 0x21 + 0x2 * (n - 1))
#define DAC_DCHxLDHRH(n) MMIO8(DAC_BASE + 0x24 + 0x2 * (n - 1))
#define DAC_DCHxLDHRL(n) MMIO8(DAC_BASE + 0x25 + 0x2 * (n - 1))
#define DAC_DCHxDHR8(n)  MMIO8(DAC_BASE + 0x28 + 0x1 * (n - 1))

#define DAC_SWTRIGR  MMIO8(DAC_BASE + 0x4) /* DAC software trigger register */
#define DAC_SR	     MMIO8(DAC_BASE + 0x5) /* DAC status register */

#define DAC_CH1CR1   DAC_CHxCR1(1)	/* DAC control register 1 */
#define DAC_CH1CR2   DAC_CHxCR2(1)	/* DAC control register 2 */
#define DAC_CH1RDHRH DAC_CHxRDHRH(1) /* right aligned data holding register high */
#define DAC_CH1RDHRL DAC_CHxRDHRL(1) /* right aligned data holding register low */
#define DAC_CH1LDHRH DAC_CHxLDHRH(1) /* left aligned data holding register high */
#define DAC_CH1LDHRL DAC_CHxLDHRL(1) /* left aligned data holding register low */
#define DAC_CH1DHR8  DAC_CHxDHR8(1) /* DAC 8-bit data holding register */
#define DAC_CH1DORH  DAC_CHxDORH(1) /* DAC data output register high */
#define DAC_CH1DORL  DAC_CHxDORL(1) /* DAC data output register low */

#define DAC_DCH1RDHRH DAC_DCHxRDHRH(1)
#define DAC_DCH1RDHRL DAC_DCHxRDHRL(1)
#define DAC_DCH1LDHRH DAC_DCHxLDHRH(1)
#define DAC_DCH1LDHRL DAC_DCHxLDHRL(1)
#define DAC_DCH1DHR8  DAC_DCHxDHR8(1)

#define DAC_CH2CR1   DAC_CHxCR1(2)
#define DAC_CH2CR2   DAC_CHxCR2(2)
#define DAC_CH2RDHRH DAC_CHxRDHRH(2)
#define DAC_CH2RDHRL DAC_CHxRDHRL(2)
#define DAC_CH2LDHRH DAC_CHxLDHRH(2)
#define DAC_CH2LDHRL DAC_CHxLDHRL(2)
#define DAC_CH2DHR8  DAC_CHxDHR8(2)
#define DAC_CH2DORH  DAC_CHxDORH(2)
#define DAC_CH2DORL  DAC_CHxDORL(2)

#define DAC_DCH2RDHRH DAC_DCHxRDHRH(2)
#define DAC_DCH2RDHRL DAC_DCHxRDHRL(2)
#define DAC_DCH2LDHRH DAC_DCHxLDHRH(2)
#define DAC_DCH2LDHRL DAC_DCHxLDHRL(2)
#define DAC_DCH2DHR8  DAC_DCHxDHR8(2)

/* Channel 2 available only on on high devices so clone names without CHx */
#define DAC_CR1   DAC_CH1CR1
#define DAC_CR2   DAC_CH1CR2
#define DAC_RDHRH DAC_CH1RDHRH
#define DAC_RDHRL DAC_CH1RDHRL
#define DAC_LDHRH DAC_CH1LDHRH
#define DAC_LDHRL DAC_CH1LDHRL
#define DAC_DHR8  DAC_CH1DHR8
#define DAC_DORH  DAC_CH1DORH
#define DAC_DORL  DAC_CH1DORL


/* DAC noise/triangle waveform generation enable. */
#define DAC_CR1_WAVEN_SHIFT	6
#define DAC_CR1_WAVEN_MASK	0x3
#define DAC_CR1_WAVEN_NONE	0x0
#define DAC_CR1_WAVEN_NOISE	0x1
#define DAC_CR1_WAVEN_TRIANGLE	0x2
#define DAC_CR1_WAVEN_TRIANGLE1	0x3
/* DAC channel x trigger selection. */
#define DAC_CR1_TSEL_SHIFT	3
#define DAC_CR1_TSEL_MASK	0x7
#define DAC_CR1_TSEL_TIM4_TRGO	0x0 /* Timer 0 counter channel output selected */
#define DAC_CR1_TSEL_TIM5_TRGO	0x1
#define DAC_CR1_TSEL_PE4	0x2 /* external trigger */
#define DAC_CR1_TSEL_SWTRIG	0x7 /* software trigger */

/* 0: The data written into the data holding register (DHR)
      is transferred one CPU clock cycle later to the data output register (DORx).
   1: The data transfer from the DHRx to the DORx
      is synchronized by the selected trigger.
*/
#define DAC_CR1_TEN	(1 << 2)
#define DAC_CR1_BOFF	(1 << 1) /* is DAC Channel output buffer disabled */
#define DAC_CR1_EN	(1 << 0) /* is DAC channel enabled */

#define DAC_CR2_DMAUDRIE	(1 << 5) /* is DMA underrun interrupt enabled */
#define DAC_CR2_DMAEN		(1 << 4) /* is DMA enabled */
/* DAC channel x mask/amplitude selector. */
#define DAC_CR2_MAMP_SHIFT	0
#define DAC_CR2_MAMP_MASK	0xF
/* UnMask 1 LSB of LFSR bit / 2^1-1 triangle amplitude */
#define DAC_CR2_MAMP_1		0x0
#define DAC_CR2_MAMP_2		0x1
#define DAC_CR2_MAMP_3		0x2
#define DAC_CR2_MAMP_4		0x3
#define DAC_CR2_MAMP_5		0x4
#define DAC_CR2_MAMP_6		0x5
#define DAC_CR2_MAMP_7		0x6
#define DAC_CR2_MAMP_8		0x7
#define DAC_CR2_MAMP_9		0x8
#define DAC_CR2_MAMP_10		0x9
#define DAC_CR2_MAMP_11		0xA
/* UnMask 12 LSB of LFSR bit / 2^12-1 triangle amplitude */
#define DAC_CR2_MAMP_12		0xB

/* is DAC channel 2 software trigger enabled */
#define DAC_SWTRIGR_SWTRIG2	(1 << 1)
/* is DAC channel 1 software trigger enabled */
#define DAC_SWTRIGR_SWTRIG1	(1 << 0)

/* is DMA underrun condition detected on DAC channel 2 */
#define DAC_SR_DMAUDR2	(1 << 1)
/* is DMA underrun condition detected on DAC channel 1 */
#define DAC_SR_DMAUDR1	(1 << 0)

/* DAC_RDHRH -- These bits will be loaded as the 4 most significant bits
   of the 12-bit digital-to-analog conversion data stored into DHR.
*/
#define DAC_RDHRH_MASK	0xF
/* DAC_RDHRL -- These bits will be loaded as the 8 least significant bits
   of the 12-bit digital-to-analog conversion data stored into DHR.
*/

/* DAC_LDHRH -- These bits will be loaded as the 8 most significant bits 
   of the 12-bit digital-to-analog conversion data stored into DHR.
*/
/* DAC_LDHRL -- These bits will be loaded as the 4 least significant bits 
   of the 12-bit digital-to-analog conversion data stored into DHR.
*/
#define DAC_LDHRL_MASK	0xF
#define DAC_LDHRL_SHIFT	4

/* DAC_DHR8 -- These bits will be loaded as the 8 most significant bits
   of the 12-bit digital-to-analog conversion data stored into DHR.
*/

/* DAC_DCHxXXXXX -- register is DAC channel x dual mode  data holding registers
   with same meaning as previos registers. 

   Available on medium+ and high density devices only.
*/

/* DAC_DORH -- DAC data output register most significant bit.
   4 most significant bits of digital data currently under conversion. */
#define DAC_DORH_MASK 0xF
/* DAC_DORL -- DAC data output register least significant bit.
   4 least significant bits of digital data currently under conversion. */
#endif
