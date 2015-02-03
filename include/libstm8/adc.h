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
#ifndef ADC_H
#define ADC_H

#include <libstm8/common.h>

#define ADC1_CR1  MMIO8(0x005340)	/* ADC1 configuration register 1 */
#define ADC1_CR2  MMIO8(0x005341)	/* ADC1 configuration register 2 */
#define ADC1_CR3  MMIO8(0x005342)	/* ADC1 configuration register 3 */
#define ADC1_SR   MMIO8(0x005343)	/* ADC1 status register */
#define ADC1_DRH  MMIO8(0x005344)	/* ADC1 data register high */
#define ADC1_DRL  MMIO8(0x005345)	/* ADC1 data register low */
#define ADC1_HTRH MMIO8(0x005346)	/* ADC1 high threshold register high */
#define ADC1_HTRL MMIO8(0x005347)	/* ADC1 high threshold register low */
#define ADC1_LTRH MMIO8(0x005348)	/* ADC1 low threshold register high */
#define ADC1_LTRL MMIO8(0x005349)	/* ADC1 low threshold register low */
#define ADC1_SQR1 MMIO8(0x00534A)	/* ADC1 channel sequence 1 register */
#define ADC1_SQR2 MMIO8(0x00534B)	/* ADC1 channel sequence 2 register */
#define ADC1_SQR3 MMIO8(0x00534C)	/* ADC1 channel sequence 3 register */
#define ADC1_SQR4 MMIO8(0x00534D)	/* ADC1 channel sequence 4 register */
#define ADC1_TRIGR1 MMIO8(0x00534E)	/* ADC1 trigger disable 1 */
#define ADC1_TRIGR2 MMIO8(0x00534F)	/* ADC1 trigger disable 2 */
#define ADC1_TRIGR3 MMIO8(0x005350)	/* ADC1 trigger disable 3 */
#define ADC1_TRIGR4 MMIO8(0x005351)	/* ADC1 trigger disable 4 */

#define ADC1_CR1_OVERIE	(1 << 7) /* is overrun interrupt enabled */
#define ADC1_CR1_AWDIE	(1 << 4) /* is analog watchdog interrupts enabled */
#define ADC1_CR1_EOCIE	(1 << 3) /* is end of conversion interrupt enabled */
#define ADC1_CR1_CONT	(1 << 2) /* single 0 / continuous 1 conversion mode */
#define ADC1_CR1_START	(1 << 1) /* Start conversion. Reset after one ADC cycle */
#define ADC1_CR1_ADON	(1 << 0) /* A/D converter ON 1 / OFF 0. */
/* These bits are used to configure the ADC resolution in bits */
#define ADC1_CR1_RES_SHIFT	5
#define ADC1_CR1_RES_MASK	0x3
#define ADC1_CR1_RES_12		0x0
#define ADC1_CR1_RES_10		0x1
#define ADC1_CR1_RES_8		0x2
#define ADC1_CR1_RES_6		0x3

#define ADC1_CR2_PRESC		(1 << 7) /* is clock prescaled by facror 2 */
/* Active edge for external triggers */
#define ADC1_CR2_TRIG_EDGE_SHIFT	5
#define ADC1_CR2_TRIG_EDGE_MASK		0x3
#define ADC1_CR2_TRIG_EDGE_RISING	0x1
#define ADC1_CR2_TRIG_EDGE_FALLING	0x2
#define ADC1_CR2_TRIG_EDGE_BOTH		0x2
/* External event selection: select the software start or one of 3 external events
   that can trigger a conversion.
*/
#define ADC1_CR2_EXTSEL_SHIFT	3
#define ADC1_CR2_EXTSEL_MASK	0x3
#define ADC1_CR2_EXTSEL_SOFTWARE 0x0
#define ADC1_CR2_EXTSEL_1	0x1
#define ADC1_CR2_EXTSEL_2	0x2
#define ADC1_CR2_EXTSEL_3	0x3
/* Sampling time selection for channels 0-23 */
#define ADC1_CR2_SMTP1_SHIFT	0
#define ADC1_CR2_SMTP1_MASK	0x7
#define ADC1_CR2_SMTP1_4	0x0
#define ADC1_CR2_SMTP1_9	0x1
#define ADC1_CR2_SMTP1_16	0x2
#define ADC1_CR2_SMTP1_24	0x3
#define ADC1_CR2_SMTP1_48	0x4
#define ADC1_CR2_SMTP1_96	0x5
#define ADC1_CR2_SMTP1_192	0x6
#define ADC1_CR2_SMTP1_384	0x7

/* Sampling time selection for channels 24, V_REFINT and TS. */
#define ADC1_CR3_SMTP2_SHIFT	5
#define ADC1_CR3_SMTP2_MASK	0x7
#define ADC1_CR3_SMTP2_4	0x0
#define ADC1_CR3_SMTP2_9	0x1
#define ADC1_CR3_SMTP2_16	0x2
#define ADC1_CR3_SMTP2_24	0x3
#define ADC1_CR3_SMTP2_48	0x4
#define ADC1_CR3_SMTP2_96	0x5
#define ADC1_CR3_SMTP2_192	0x6
#define ADC1_CR3_SMTP2_384	0x7
/* Channel selection:
   Used to select the channel to be checked by the analog watchdog
*/
#define ADC1_CR3_CHSEL_SHIFT	0
#define ADC1_CR3_CHSEL_MASK	0x1F
#define ADC1_CR3_CHSEL_0	0x0
#define ADC1_CR3_CHSEL_1	0x1
#define ADC1_CR3_CHSEL_2	0x2
#define ADC1_CR3_CHSEL_3	0x3
#define ADC1_CR3_CHSEL_4	0x4
#define ADC1_CR3_CHSEL_5	0x5
#define ADC1_CR3_CHSEL_6	0x6
#define ADC1_CR3_CHSEL_7	0x7
#define ADC1_CR3_CHSEL_8	0x8
#define ADC1_CR3_CHSEL_9	0x9
#define ADC1_CR3_CHSEL_10	0xA
#define ADC1_CR3_CHSEL_11	0xB
#define ADC1_CR3_CHSEL_12	0xC
#define ADC1_CR3_CHSEL_13	0xD
#define ADC1_CR3_CHSEL_14	0xE
#define ADC1_CR3_CHSEL_15	0xF
#define ADC1_CR3_CHSEL_16	0x10
#define ADC1_CR3_CHSEL_17	0x11
#define ADC1_CR3_CHSEL_18	0x12
#define ADC1_CR3_CHSEL_19	0x13
#define ADC1_CR3_CHSEL_20	0x14
#define ADC1_CR3_CHSEL_21	0x15
#define ADC1_CR3_CHSEL_22	0x16
#define ADC1_CR3_CHSEL_23	0x17
#define ADC1_CR3_CHSEL_24	0x18
#define ADC1_CR3_CHSEL_25	0x19
#define ADC1_CR3_CHSEL_26	0x1A
#define ADC1_CR3_CHSEL_27	0x1B
#define ADC1_CR3_CHSEL_V_REFINT	0x1C
#define ADC1_CR3_CHSEL_TS	0x1D

#define ADC1_SR_OVER	(1 << 2) /* is overrun occurred */
#define ADC1_SR_AWD	(1 << 1) /* is analog watchdog event occurred */
#define ADC1_SR_EOC	(1 << 0) /* is conversion complete */

/* ADC1_DRH contain the 4 MS bits of the converted data. */
#define ADC1_DRH_MASK	0xF
/* ADC1_DRL contain the 8 LS bits of the converted data. */

/* ADC1_HTRH define the 4 MSB of the higher threshold for the analog watchdog */
#define ADC1_HTRH_MASK 0xF
/* ADC1_HTRL define the 8 LSB of the higher threshold for the analog watchdog */

/* ADC1_LTRH define the 4 MSB of the lower threshold for the analog watchdog */
#define ADC1_LTRH_MASK 0xF
/* ADC1_LTRL define the 8 LSB of the lower threshold for the analog watchdog */

/* The reference voltage threshold data bits are right aligned and their
   configuration depends on the programmed resolution, as described below:

   12-bit resolution: 
     ADC1_HTRH & ADC1_LTRH Bits 7:4 = reserved ; Bits 3:0 = HT[11:8] or LT[11:8]
     ADC1_HTRL & ADC1_LTRL Bits 7:0 = HT[7:0] or LT[7:0]
   10-bit resolution: 
     ADC1_HTRH & ADC1_LTRH Bits 7:2 = reserved ; Bits 1:0 = HT[9:8] or LT[9:8]
     ADC1_HTRL & ADC1_LTRL Bits 7:0 = HT[7:0] or LT[7:0]
   8-bit resolution: 
     ADC1_HTRH & ADC1_LTRH Bits 7:0 = reserved
     ADC1_HTRL & ADC1_LTRL Bits 7:0 = HT[7:0] or LT[7:0]
   6-bit resolution: 
     ADC1_HTRH & ADC1_LTRH Bits 7:0 = reserved
     ADC1_HTRL & ADC1_LTRL Bits 7:6 = reserved ; Bits 5:0 = HT[5:0] or LT[5:0]
*/

#define ADC1_SQR1_DMAOFF	(1 << 7) /* 0 -- DMA enabled, 1 -- disabled */
#define ADC1_SQR1_CHSEL_STS	(1 << 5) /* Selection of channel TS for scan */
/* Selection of channel V_REFINT for scan */
#define ADC1_SQR1_CHSEL_SVREFINT (1 << 4)
#define ADC1_SQR1_CHSEL_S27	(1 << 3) /* Selection of channel 27 for scan */
#define ADC1_SQR1_CHSEL_S26	(1 << 2)
#define ADC1_SQR1_CHSEL_S25	(1 << 1)
#define ADC1_SQR1_CHSEL_S24	(1 << 0)

#define ADC1_SQR2_CHSEL_S23	(1 << 7)
#define ADC1_SQR2_CHSEL_S22	(1 << 6)
#define ADC1_SQR2_CHSEL_S21	(1 << 5)
#define ADC1_SQR2_CHSEL_S20	(1 << 4)
#define ADC1_SQR2_CHSEL_S19	(1 << 3)
#define ADC1_SQR2_CHSEL_S18	(1 << 2)
#define ADC1_SQR2_CHSEL_S17	(1 << 1)
#define ADC1_SQR2_CHSEL_S16	(1 << 0)

#define ADC1_SQR3_CHSEL_S15	(1 << 7)
#define ADC1_SQR3_CHSEL_S14	(1 << 6)
#define ADC1_SQR3_CHSEL_S13	(1 << 5)
#define ADC1_SQR3_CHSEL_S12	(1 << 4)
#define ADC1_SQR3_CHSEL_S11	(1 << 3)
#define ADC1_SQR3_CHSEL_S10	(1 << 2)
#define ADC1_SQR3_CHSEL_S9	(1 << 1)
#define ADC1_SQR3_CHSEL_S8	(1 << 0)

#define ADC1_SQR4_CHSEL_S7	(1 << 7)
#define ADC1_SQR4_CHSEL_S6	(1 << 6)
#define ADC1_SQR4_CHSEL_S5	(1 << 5)
#define ADC1_SQR4_CHSEL_S4	(1 << 4)
#define ADC1_SQR4_CHSEL_S3	(1 << 3)
#define ADC1_SQR4_CHSEL_S2	(1 << 2)
#define ADC1_SQR4_CHSEL_S1	(1 << 1)
#define ADC1_SQR4_CHSEL_S0	(1 << 0)

/* Enable temperature sensor internal reference voltage  */
#define ADC1_TRIGR1_TSON	(1 << 5)
#define ADC1_TRIGR1_VREFINTON	(1 << 4) /* Enable internal reference voltage */
/* A value '1' in the TRIGx bit means that the Schmitt trigger 
   corresponding to channel x is disabled.
*/
#define ADC1_TRIGR1_TRIG27	(1 << 3) 
#define ADC1_TRIGR1_TRIG26	(1 << 2)
#define ADC1_TRIGR1_TRIG25	(1 << 1)
#define ADC1_TRIGR1_TRIG24	(1 << 0)

#define ADC1_TRIGR2_TRIG23	(1 << 7)
#define ADC1_TRIGR2_TRIG22	(1 << 6)
#define ADC1_TRIGR2_TRIG21	(1 << 5)
#define ADC1_TRIGR2_TRIG20	(1 << 4)
#define ADC1_TRIGR2_TRIG19	(1 << 3)
#define ADC1_TRIGR2_TRIG18	(1 << 2)
#define ADC1_TRIGR2_TRIG17	(1 << 1)
#define ADC1_TRIGR2_TRIG16	(1 << 0)

#define ADC1_TRIGR3_TRIG15	(1 << 7)
#define ADC1_TRIGR3_TRIG14	(1 << 6)
#define ADC1_TRIGR3_TRIG13	(1 << 5)
#define ADC1_TRIGR3_TRIG12	(1 << 4)
#define ADC1_TRIGR3_TRIG11	(1 << 3)
#define ADC1_TRIGR3_TRIG10	(1 << 2)
#define ADC1_TRIGR3_TRIG9	(1 << 1)
#define ADC1_TRIGR3_TRIG8	(1 << 0)

#define ADC1_TRIGR4_TRIG7	(1 << 7)
#define ADC1_TRIGR4_TRIG6	(1 << 6)
#define ADC1_TRIGR4_TRIG5	(1 << 5)
#define ADC1_TRIGR4_TRIG4	(1 << 4)
#define ADC1_TRIGR4_TRIG3	(1 << 3)
#define ADC1_TRIGR4_TRIG2	(1 << 2)
#define ADC1_TRIGR4_TRIG1	(1 << 1)
#define ADC1_TRIGR4_TRIG0	(1 << 0)

#endif
