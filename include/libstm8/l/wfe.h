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
#ifndef WFE_H
#define WFE_H

#include <libstm8/common.h>

#define WFE_CR1 MMIO8(0x0050A6)	/* WFE control register 1 */
#define WFE_CR2 MMIO8(0x0050A7)	/* WFE control register 2 */
#define WFE_CR3 MMIO8(0x0050A8)	/* WFE control register 3 */

/* EXTI from pin 3 of all ports configured to generate wakeup events */
#define WFE_CR1_EXTI_EV3 (1 << 7)
/* EXTI from pin 2 of all ports configured to generate wakeup events */
#define WFE_CR1_EXTI_EV2 (1 << 6)
/* EXTI from pin 1 of all ports configured to generate wakeup events */
#define WFE_CR1_EXTI_EV1 (1 << 5)
/* EXTI from pin 0 of all ports configured to generate wakeup events */
#define WFE_CR1_EXTI_EV0 (1 << 4)
/* TIM1 capture and compare interrupts logically ORed and configured to generate
   wakeup events */
#define WFE_CR1_TIM1_EV1 (1 << 3)
/* TIM1 update, trigger and break interrupts logically ORed and configured to
   generate wakeup events */
#define WFE_CR1_TIM1_EV0 (1 << 2)
/* TIM2 capture and compare interrupts logically ORed and configured to generate
   wakeup events */
#define WFE_CR1_TIM2_EV1 (1 << 1)
/* TIM2 update, trigger and break interrupts logically ORed and configured to
   generate wakeup events */
#define WFE_CR1_TIM2_EV0 (1 << 0)

/* Interrupts from ADC1 and comparators are configured to generate wakeup events */
#define WFE_CR2_ADC1_COMP_EV	(1 << 7)
/* EXTI from Port E or Port F configured to generate wakeup events */
#define WFE_CR2_EXTI_EVE_F	(1 << 6)
/* EXTI from Port D or Port H configured to generate wakeup events */
#define WFE_CR2_EXTI_EVD_H	(1 << 5)
/* EXTI from Port B or Port G configured to generate wakeup events */
#define WFE_CR2_EXTI_EVB_G	(1 << 4)
/* EXTI from pin 7 of all ports configured to generate wakeup events */
#define WFE_CR2_EXTI_EV7	(1 << 3)
/* EXTI from pin 6 of all ports configured to generate wakeup events */
#define WFE_CR2_EXTI_EV6	(1 << 2)
/* EXTI from pin 5 of all ports configured to generate wakeup events */
#define WFE_CR2_EXTI_EV5	(1 << 1)
/* EXTI from pin 4 of all ports configured to generate wakeup events */
#define WFE_CR2_EXTI_EV4	(1 << 0)

/* DMA1 channel 2 and 3 interrupts configured to generate wakeup events */
#define WFE_CR3_DMA1CH23_EV	(1 << 7)
/* DMA1 channel 0 and 1 interrupts configured to generate wakeup events */
#define WFE_CR3_DMA1CH01_EV	(1 << 6)
/* USART1 Rx and Tx interrupts configured to generate wakeup events */
#define WFE_CR3_USART1_EV	(1 << 5)
/* I2C1 Rx and Tx interrupts configured to generate wakeup events */
#define WFE_CR3_I2C1_EV		(1 << 4)
/* SPI1 Rx and Tx interrupts configured to generate wakeup events */
#define WFE_CR3_SPI1_EV		(1 << 3)
/* TIM4 update and trigger interrupts logically ORed and configured to generate
   wakeup events */
#define WFE_CR3_TIM4_EV		(1 << 2)
/* TIM3 capture and compare interrupts logically ORed and configured to generate
   wakeup events */
#define WFE_CR3_TIM3_EV1	(1 << 1)
/* TIM3 update, trigger and break interrupts logically ORed and configured to
   generate wakeup events */
#define WFE_CR3_TIM3_EV0	(1 << 0)

#endif
