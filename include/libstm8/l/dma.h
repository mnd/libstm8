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
#ifndef DMA_H
#define DMA_H

#include <libstm8/common.h>

#define DMA1_BASE 0x005070
#define DMA1_GCSR MMIO8(DMA1_BASE + 0x0)	/* DMA1 global configuration & status register */
#define DMA1_GIR1 MMIO8(DMA1_BASE + 0x1)	/* DMA1 global interrupt register 1 */

#define DMA1_CxCR(n)	MMIO8(DMA1_BASE + 0x5 + (n)*0xA)
#define DMA1_CxSPR(n)	MMIO8(DMA1_BASE + 0x6 + (n)*0xA)
#define DMA1_CxNDTR(n)	MMIO8(DMA1_BASE + 0x7 + (n)*0xA)
#define DMA1_CxPARH(n)  MMIO8(DMA1_BASE + 0x8 + (n)*0xA)
#define DMA1_CxPARL(n)	MMIO8(DMA1_BASE + 0x9 + (n)*0xA)
#define DMA1_CxM0ARH(n)	MMIO8(DMA1_BASE + 0xB + (n)*0xA)
#define DMA1_CxM0ARL(n)	MMIO8(DMA1_BASE + 0xC + (n)*0xA)
/* only on channel 3 on medium+ and high density devices */
#define DMA1_CxM0EAR(n)	MMIO8(DMA1_BASE + 0xA + (n)*0xA)

#define DMA1_C0CR    DMA1_CxCR(0)   /* DMA1 channel 0 configuration register */
#define DMA1_C0SPR   DMA1_CxSPR(0)  /* DMA1 channel 0 status & priority register */
#define DMA1_C0NDTR  DMA1_CxNDTR(0) /* DMA1 number of data to transfer register */
#define DMA1_C0PARH  DMA1_CxPARH(0) /* DMA1 peripheral address high register */
#define DMA1_C0PARL  DMA1_CxPARL(0) /* DMA1 peripheral address low register */
#define DMA1_C0M0ARH DMA1_CxM0ARH(0) /* DMA1 memory 0 address high register */
#define DMA1_C0M0ARL DMA1_CxM0ARL(0) /* DMA1 memory 0 address low register */

#define DMA1_C1CR    DMA1_CxCR(1)
#define DMA1_C1SPR   DMA1_CxSPR(1)
#define DMA1_C1NDTR  DMA1_CxNDTR(1)
#define DMA1_C1PARH  DMA1_CxPARH(1)
#define DMA1_C1PARL  DMA1_CxPARL(1)
#define DMA1_C1M0ARH DMA1_CxM0ARH(1)
#define DMA1_C1M0ARL DMA1_CxM0ARL(1)

#define DMA1_C2CR    DMA1_CxCR(2)
#define DMA1_C2SPR   DMA1_CxSPR(2)
#define DMA1_C2NDTR  DMA1_CxNDTR(2)
#define DMA1_C2PARH  DMA1_CxPARH(2)
#define DMA1_C2PARL  DMA1_CxPARL(2)
#define DMA1_C2M0ARH DMA1_CxM0ARH(2)
#define DMA1_C2M0ARL DMA1_CxM0ARL(2)

#define DMA1_C3CR    DMA1_CxCR(3)
#define DMA1_C3SPR   DMA1_CxSPR(3)
#define DMA1_C3NDTR  DMA1_CxNDTR(3)
#define DMA1_C3PARH_C3M1ARH DMA1_CxPARH(3)
#define DMA1_C3PARL_C3M1ARL DMA1_CxPARL(3)
#define DMA1_C3M0ARH DMA1_CxM0ARH(3)
#define DMA1_C3M0ARL DMA1_CxM0ARL(3)
#define DMA1_C3M0EAR DMA1_CxM0EAR(3) /* only on medium+ and high density devices */

/* Timeout -- number of number of cycles to wait starting from the last request. */
#define DMA1_GCSR_TO_SHIFT	2
#define DMA1_GCSR_TO_MASK	0x3F

#define DMA1_GCSR_GB	(1 << 1) /* is there are ongoing DMA transfer */
#define DMA1_GCSR_GEN	(1 << 0) /* is DMA enabled according to DMA_CxCR */
/* is there pending interrupt on some channel */
#define DMA1_GIR1_IFC3	(1 << 3)
#define DMA1_GIR1_IFC2	(1 << 2)
#define DMA1_GIR1_IFC1	(1 << 1)
#define DMA1_GIR1_IFC0	(1 << 0)

#define DMA1_CxCR_MEM (1 << 6) /* Set channel works as memory channel. C3CR only */
#define DMA1_CxCR_MINCDEC (1 << 5) /* memory increment 0/decrement 1 mode */
#define DMA1_CxCR_CIRC	(1 << 4)   /* circular buffer mode (Auto-reload mode) */
#define DMA1_CxCR_DIR	(1 << 3)   /* 0: peripheral to the memory, 1: otherwise  */
#define DMA1_CxCR_HTIE	(1 << 2)   /* is half-transaction interrupt enabled. */
#define DMA1_CxCR_TCIE	(1 << 1)   /* is transaction complete interrupt enabled. */
#define DMA1_CxCR_EN	(1 << 0)   /* is channel enabled */

#define DMA1_CxSPR_BUSY		(1 << 7) /* is there an ongoing DMA transfer */
#define DMA1_CxSPR_PEND		(1 << 6) /* is there a DMA pending request */
#define DMA1_CxSPR_TSIZE	(1 << 3) /* 8 or 16 bit transfer size */
#define DMA1_CxSPR_HTIF		(1 << 2) /* is half transaction completed */
#define DMA1_CxSPR_TCIF		(1 << 1) /* is transaction completed */
/* Channel priority level */
#define DMA1_CxSPR_PL_SHIFT	4
#define DMA1_CxSPR_PL_MASK	0x3
#define DMA1_CxSPR_PL_LOW	0x0
#define DMA1_CxSPR_PL_MEDIUM	0x1
#define DMA1_CxSPR_PL_HIGH	0x2
#define DMA1_CxSPR_PL_VERY_HIGH	0x3 /* DMA takes precedence over the CPU */

/* DMA1_CxNDTR(n) -- number of data (byte/word) to transfer. Can be read to get
 progress.
*/

/* DMA1_CxPARH(n) -- peripheral address pointer high part */
/* DMA1_CxPARL(n) -- peripheral address pointer low part */

/* DMA1_C3PARH_C3M1ARH:DMA1_C3PARL_C3M1ARL
   when DMA1_CxCR_MEM disabled -- same as DMA1_CxPARH(n):DMA1_CxPARL(n)
   when DMA1_CxCR_MEM enabled -- destination memory adress at most 0x1F:0xFF in
   mem-to-mem transfer.
*/
#define DMA1_C3PARH_C3M1ARH_MASK 0x1F

/* DMA1_CxM0ARH(n) -- memory address pointer high part */
/* DMA1_CxM0ARL(n) -- memory address pointer low part */
#define DMA1_CxM0ARH_MASK	0x7
#define DMA1_C3M0ARH_MEM_MASK	0xFF

#define DMA1_C3M0EAR_MASK 0x1 	/* additional bit for memory address */

/* DMA1 channel request mapping
   | IPs    | Channel 0 | Channel 1   | Channel 2 | Channel 3   |
   |--------+-----------+-------------+-----------+-------------|
   | ADC1   | EOC       | EOC         | EOC       | EOC         |
   | SPI1   |           | SPI1_RX     | SPI1_TX   |             |
   | AES    | AES_IN    |             |           | AES_OUT     |
   | I2C    | I2C_RX    |             |           | I2C_TX      |
   | USART1 |           | USART1_TX   | USART1_RX |             |
   | DAC    |           | DAC_CH2TRIG |           | DAC_CH1TRIG |
   | TIM2   | TIM2_CC1  | TIM2_U      |           | TIM2_CC2    |
   | TIM3   | TIM3_U    | TIM3_CC1    | TIM3_CC2  |             |
   | TIM1   | TIM1_CC3  | TIM1_CC4    | TIM1_U    | TIM1_CC2    |
   |        |           |             | TIM1_CC1  |             |
   |        |           |             | TIM1_COM  |             |
   | USART2 | USART2_TX |             |           | USART2_RX   |
   | USART3 |           | USART3_TX   | USART3_RX |             |
   | SPI2   | SPI2_RX   |             |           | SPI2_TX     |
   | TIM5   | TIM5_U    |             | TIM5_CC1  | TIM5_CC2    |
   | TIM4   | TIM4_U    | TIM4_U      | TIM4_U    | TIM4_U      |

   ADC1 and TIM4 can be mapped to any channel according to SYSCFG_RMPCR1
*/

enum dma_channel {
  DMA_CHANNEL0 = 0,
  DMA_CHANNEL1 = 1,
  DMA_CHANNEL2 = 2,
  DMA_CHANNEL3 = 3
};

enum dma_size {
  DMA_TSIZE_8BIT = 0,
  DMA_TSIZE_16BIT = 1
};

void dma_channel_reset (uint16_t dma, enum dma_channel channel);
void dma_set_peripheral_address (uint16_t dma, enum dma_channel channel,
				 uint16_t peripheral_adress);
void dma_set_number_of_data (uint16_t dma, enum dma_channel channel,
			     uint8_t number);
void dma_set_memory_address (uint16_t dma, enum dma_channel channel,
			     uint16_t data);
void dma_set_read_from_memory (uint16_t dma, enum dma_channel channel);
void dma_enable_memory_increment_mode (uint16_t dma, enum dma_channel channel);
void dma_clear_interrupt_flags (uint16_t dma, enum dma_channel channel,
				uint8_t interrupts);
void dma_enable_transfer_complete_interrupt (uint16_t dma,
					     enum dma_channel channel);
void dma_disable_transfer_complete_interrupt (uint16_t dma,
					     enum dma_channel channel);
void dma_enable_half_transfer_interrupt (uint16_t dma, enum dma_channel channel);
void dma_disable_half_transfer_interrupt (uint16_t dma, enum dma_channel channel);
void dma_set_size (uint16_t dma, enum dma_channel channel, enum dma_size size);
void dma_set_priority (uint16_t dma, enum dma_channel, uint8_t priority);
void dma_enable_channel (uint16_t dma, enum dma_channel channel);
void dma_disable_channel (uint16_t dma, enum dma_channel channel);
void dma_enable (uint16_t dma);
void dma_disable (uint16_t dmax);
#endif
