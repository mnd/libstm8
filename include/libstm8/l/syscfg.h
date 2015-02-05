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
#ifndef SYSCFG_H
#define SYSCFG_H

#include <libstm8/common.h>

#define SYSCFG_RMPCR3 MMIO8(0x00509D)	/* Remapping register 3 */
#define SYSCFG_RMPCR1 MMIO8(0x00509E)	/* Remapping register 1 */
#define SYSCFG_RMPCR2 MMIO8(0x00509F)	/* Remapping register 2 */

/* 0: SPI1_MIS0 is mapped on PB7
      SPI1_MOSI is mapped on PB6
      SPI1_SCK  is mapped on PB5
      SPI1_NSS  is mapped on PB4

   1: SPI1_MIS0 is mapped on PA2
      SPI1_MOSI is mapped on PA3
      SPI1_SCK  is mapped on PC6
      SPI1_NSS  is mapped on PC5
*/
#define SYSCFG_RMPCR1_SPI1_REMAP1		(1 << 7)
/* 0: USART1_CK mapped on PC4
   1: USART1_CK mapped on PA0
*/
#define SYSCFG_RMPCR1_SPI1_USART1CK_REMAP	(1 << 6)
/* Define USART1_TX and USART1_RX remapping */
#define SYSCFG_RMPCR1_USART1TR_REMAP_SHIFT	4
#define SYSCFG_RMPCR1_USART1TR_REMAP_MASK	0x3
#define SYSCFG_RMPCR1_USART1TR_REMAP_PC3_PC2	0x0
#define SYSCFG_RMPCR1_USART1TR_REMAP_PA2_PA3	0x1
#define SYSCFG_RMPCR1_USART1TR_REMAP_PC5_PC6	0x2
/* TIM4 DMA request/acknowledge mapped on DMA1 channel x with CHx value */
#define SYSCFG_RMPCR1_TIM4DMA_REMAP_SHIFT	2
#define SYSCFG_RMPCR1_TIM4DMA_REMAP_MASK	0x3
#define SYSCFG_RMPCR1_TIM4DMA_REMAP_CH0		0x0
#define SYSCFG_RMPCR1_TIM4DMA_REMAP_CH1		0x1
#define SYSCFG_RMPCR1_TIM4DMA_REMAP_CH2		0x2
#define SYSCFG_RMPCR1_TIM4DMA_REMAP_CH3		0x3
/* ADC1 DMA request/acknowledge mapped on DMA1 channel x with CHx value */
#define SYSCFG_RMPCR1_ADC1DMA_REMAP_SHIFT	0
#define SYSCFG_RMPCR1_ADC1DMA_REMAP_MASK	0x3
#define SYSCFG_RMPCR1_ADC1DMA_REMAP_CH0		0x0
#define SYSCFG_RMPCR1_ADC1DMA_REMAP_CH1		0x1
#define SYSCFG_RMPCR1_ADC1DMA_REMAP_CH2		0x2
#define SYSCFG_RMPCR1_ADC1DMA_REMAP_CH3		0x3

/* 0: TIM2_BKIN & TIM3_BKIN mapped on PA4 & PA5
   1: TIM2_BKIN & TIM3_BKIN mapped on PG0 & PG1 (only on 64- and 80-pin packages)
*/
#define SYSCFG_RMPCR2_TIM23BKIN_REMAP	(1 << 7)
/* 0: TIM3_TRIG mapped on PD1 if TRIM3TRIG_REMAP1=0 or on PA5 if TRIM3TRIG_REMAP1=1
   1: TIM3_TRIG mapped on PG3 (only on 64- and 80-pin packages)
*/
#define SYSCFG_RMPCR2_TIM3TRIG_REMAP2	(1 << 6)
/* 0: SPI2_MIS0 is mapped on PG7
      SPI2_MOSI is mapped on PG6
      SPI2_SCK  is mapped on PG5
      SPI2_NSS  is mapped on PG4

   1: SPI2_MIS0 is mapped on PI3
      SPI2_MOSI is mapped on PI2
      SPI2_SCK  is mapped on PI1
      SPI2_NSS  is mapped on PI0
*/
#define SYSCFG_RMPCR2_SPI2_REMAP	(1 << 5)
/* 0: TIM3_TRIG mapped as defined in the TIM3TRIG_REMAP1 bit
   1: TIM3_TRIG mapped on OSC32_IN (LSE oscillator input)
*/
#define SYSCFG_RMPCR2_TIM3TRIGLSE_REMAP	(1 << 4)
/* 0: TIM2_TRIG mapped as defined in the TIM2TRIG_REMAP bit
   1: TIM2_TRIG mapped on OSC32_IN (LSE oscillator input)
*/
#define SYSCFG_RMPCR2_TIM2TRIGLSE_REMAP	(1 << 3)
/* 0: TIM3_TRIG mapped on PD1
   1: TIM3_TRIG mapped on PA5
*/
#define SYSCFG_RMPCR2_TIM3TRIG_REMAP1	(1 << 2)
/* 0: TIM2_TRIG mapped on PB3
   1: TIM2_TRIG mapped on PA4
*/
#define SYSCFG_RMPCR2_TIM2TRIG_REMAP	(1 << 1)
/* 0: ADC1_TRIG mapped on PA6
   1: ADC1_TRIG mapped on PD0
*/
#define SYSCFG_RMPCR2_ADC1TRIG_REMAP	(1 << 0)

/* 0: TIM2_CH2 is mapped on PB2
   1: TIM2_CH2 is mapped on PC6
*/
#define SYSCFG_RMPCR3_TIM2_CH2	(1 << 7)
/* 0: TIM2_CH1 is mapped on PB0
   1: TIM2_CH1 is mapped on PC5
*/
#define SYSCFG_RMPCR3_TIM2_CH1	(1 << 6)
/* 0: CCO mapped on PC4
   1: CCO mapped on PE2
*/
#define SYSCFG_RMPCR3_CCO_REMAP		(1 << 5)
/* 0: TIM3_CH2 mapped on PD0
   1: TIM3_CH2 mapped on PI3 (80-pin packages only)
*/
#define SYSCFG_RMPCR3_TIM3_CH2_REMAP	(1 << 4)
/* 0: TIM3_CH1 mapped on PB1
   1: TIM3_CH1 mapped on PI0 (80-pin packages only)
*/
#define SYSCFG_RMPCR3_TIM3_CH1_REMAP	(1 << 3)
/* 0: USART3_CK mapped on PG2
   1: USART3_CK mapped on PF2 (80-pin packages only)
*/
#define SYSCFG_RMPCR3_USART3CK_REMAP	(1 << 2)
/* 0: USART3_TX mapped on PG1 and USART3_RX mapped on PG0
   1: USART3_TX mapped on PF0 and USART3_RX mapped on PF1
*/
#define SYSCFG_RMPCR3_USART3TR_REMAP	(1 << 1)
/* 0: SPI1_MIS0 is mapped on PB7
      SPI1_MOSI is mapped on PB6
      SPI1_SCK  is mapped on PB5
      SPI1_NSS  is mapped on PB4

   1: SPI1_MIS0 is mapped on PF0
      SPI1_MOSI is mapped on PF1
      SPI1_SCK  is mapped on PF2
      SPI1_NSS  is mapped on PF3
*/
#define SYSCFG_RMPCR3_SPI1_REMAP2	(1 << 0)

#endif
