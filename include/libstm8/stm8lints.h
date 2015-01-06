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

#ifndef STM8LINTS_H
#define STM8LINTS_H

/* Usage with sdcc: void function (void) __interrupt(INT_NAME) { code; } */
#define INT_RESERVED      0
#define INT_FLASH         1 /* FLASH end of programing/ write attempted to protected page interrupt */
#define INT_DMA1_01       2 /* DMA1 channels 0/1 half transaction/transaction complete interrupt */
#define INT_DMA1_23       3 /* DMA1 channels 2/3 half transaction/transaction complete interrupt */
#define INT_RTC           4 /* RTC alarm A/ wakeup */
#define INT_EXTI_EF_PVD   5 /* External interrupt port E/F PVD interrupt */
#define INT_EXTI_BG       6 /* External interrupt port B/G */
#define INT_EXTI_DH       7 /* External interrupt port D/H */
#define INT_EXTI0         8 /* External interrupt 0 */
#define INT_EXTI1         9 /* External interrupt 1 */
#define INT_EXTI2        10 /* External interrupt 2 */
#define INT_EXTI3        11 /* External interrupt 3 */
#define INT_EXTI4        12 /* External interrupt 4 */
#define INT_EXTI5        13 /* External interrupt 5 */
#define INT_EXTI6        14 /* External interrupt 6 */
#define INT_EXTI7        15 /* External interrupt 7 */
#define INT_LCD          16 /* LCD interrupt */
#define INT_CLK_TIM1_DAC 17 /* CLK system clock switch/ CSS interrupt/ TIM 1 break/DAC */
#define INT_COMP1_2_ADC1 18 /* COMP1 interrupt/ COMP2 interrupt/ ACD1 end of conversion/ analog watchdog/ overrun interrupt */
#define INT_TIM2_CHANGE  19 /* TIM2 update/overflow/trigger/break interrupt */
#define INT_TIM2_CAPTURE 20 /* TIM2 capture/compare interrupt */
#define INT_TIM3_CHANGE  21 /* TIM3 update/overflow/trigger/break interrupt */
#define INT_TIM3_CAPTURE 22 /* TIM3 capture/compare interrupt */
#define INT_TIM1_CHANGE  23 /* TIM1 update overflow/trigger/ COM */
#define INT_TIM1_CAPTURE 24 /* TIM1 capture/compare interrupt */
#define INT_TIM1_CHANGE  25 /* TIM4 update/overflow/trigger interrupt */
#define INT_SPI1         26 /* SPI1 TX buffer empty/ RX buffer not empty/ error/wakeup interrupt */
#define INT_USART1_TRANS 27 /* USART1 transmit data register empty/ transmission complete interrupt */
#define INT_USART1_RECV  28 /* USART1 received data ready/overrun error/ idle line detected/parity error/global error interrupt */
#define INT_I2C1         29 /* I2C1 interrupt */

#define INT_TRAP         -1 /* As for now SDCC not allow to change Software interrupt and this interrupt hardcoded to 0x0000 */
#define INT_RESET        -2 /* SDCC hardcodes Reset interrupt to initialization code added to files */

#endif
