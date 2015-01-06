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
#ifndef GPIO_H
#define GPIO_H

#include "common.h"

#define GPIOA 0x005000
#define GPIOB 0x005005
#define GPIOC 0x00500A
#define GPIOD 0x00500F
#define GPIOE 0x005014
#define GPIOF 0x005019

#define GPIO_ODR(port) MMIO8(port + 0x0) /* Port data output latch register */
#define GPIO_IDR(port) MMIO8(port + 0x1) /* Port input pin value register */ 
#define GPIO_DDR(port) MMIO8(port + 0x2) /* Port data direction register */  
#define GPIO_CR1(port) MMIO8(port + 0x3) /* Port control register 1 */
#define GPIO_CR2(port) MMIO8(port + 0x4) /* Port control register 2 */

#define GPIOA_ODR GPIO_ODR(GPIOA)
#define GPIOA_IDR GPIO_IDR(GPIOA)
#define GPIOA_DDR GPIO_DDR(GPIOA)
#define GPIOA_CR1 GPIO_CR1(GPIOA)
#define GPIOA_CR2 GPIO_CR2(GPIOA)

#define GPIOB_ODR GPIO_ODR(GPIOB)
#define GPIOB_IDR GPIO_IDR(GPIOB)
#define GPIOB_DDR GPIO_DDR(GPIOB)
#define GPIOB_CR1 GPIO_CR1(GPIOB)
#define GPIOB_CR2 GPIO_CR2(GPIOB)

#define GPIOC_ODR GPIO_ODR(GPIOC)
#define GPIOC_IDR GPIO_IDR(GPIOC)
#define GPIOC_DDR GPIO_DDR(GPIOC)
#define GPIOC_CR1 GPIO_CR1(GPIOC)
#define GPIOC_CR2 GPIO_CR2(GPIOC)

#define GPIOD_ODR GPIO_ODR(GPIOD)
#define GPIOD_IDR GPIO_IDR(GPIOD)
#define GPIOD_DDR GPIO_DDR(GPIOD)
#define GPIOD_CR1 GPIO_CR1(GPIOD)
#define GPIOD_CR2 GPIO_CR2(GPIOD)

#define GPIOE_ODR GPIO_ODR(GPIOE)
#define GPIOE_IDR GPIO_IDR(GPIOE)
#define GPIOE_DDR GPIO_DDR(GPIOE)
#define GPIOE_CR1 GPIO_CR1(GPIOE)
#define GPIOE_CR2 GPIO_CR2(GPIOE)

#define GPIOF_ODR GPIO_ODR(GPIOF)
#define GPIOF_IDR GPIO_IDR(GPIOF)
#define GPIOF_DDR GPIO_DDR(GPIOF)
#define GPIOF_CR1 GPIO_CR1(GPIOF)
#define GPIOF_CR2 GPIO_CR2(GPIOF)

#endif
