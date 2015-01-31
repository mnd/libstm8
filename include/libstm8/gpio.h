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

#include <libstm8/common.h>

#define GPIOA 0x005000
#define GPIOB 0x005005
#define GPIOC 0x00500A
#define GPIOD 0x00500F
#define GPIOE 0x005014
#define GPIOF 0x005019

#define GPIO_ODR(port) MMIO8(port + 0x0) /* Port data output latch register */
#define GPIOA_ODR GPIO_ODR(GPIOA)
#define GPIOB_ODR GPIO_ODR(GPIOB)
#define GPIOC_ODR GPIO_ODR(GPIOC)
#define GPIOD_ODR GPIO_ODR(GPIOD)
#define GPIOE_ODR GPIO_ODR(GPIOE)
#define GPIOF_ODR GPIO_ODR(GPIOF)


#define GPIO_IDR(port) MMIO8(port + 0x1) /* Port input pin value register */ 
#define GPIOA_IDR GPIO_IDR(GPIOA)
#define GPIOB_IDR GPIO_IDR(GPIOB)
#define GPIOC_IDR GPIO_IDR(GPIOC)
#define GPIOD_IDR GPIO_IDR(GPIOD)
#define GPIOE_IDR GPIO_IDR(GPIOE)
#define GPIOF_IDR GPIO_IDR(GPIOF)

#define GPIO_DDR(port) MMIO8(port + 0x2) /* Port data direction register */  
#define GPIOA_DDR GPIO_DDR(GPIOA)
#define GPIOB_DDR GPIO_DDR(GPIOB)
#define GPIOC_DDR GPIO_DDR(GPIOC)
#define GPIOD_DDR GPIO_DDR(GPIOD)
#define GPIOE_DDR GPIO_DDR(GPIOE)
#define GPIOF_DDR GPIO_DDR(GPIOF)

#define GPIO_CR1(port) MMIO8(port + 0x3) /* Port control register 1 */
#define GPIOA_CR1 GPIO_CR1(GPIOA)
#define GPIOB_CR1 GPIO_CR1(GPIOB)
#define GPIOC_CR1 GPIO_CR1(GPIOC)
#define GPIOD_CR1 GPIO_CR1(GPIOD)
#define GPIOE_CR1 GPIO_CR1(GPIOE)
#define GPIOF_CR1 GPIO_CR1(GPIOF)

#define GPIO_CR2(port) MMIO8(port + 0x4) /* Port control register 2 */
#define GPIOA_CR2 GPIO_CR2(GPIOA)
#define GPIOB_CR2 GPIO_CR2(GPIOB)
#define GPIOC_CR2 GPIO_CR2(GPIOC)
#define GPIOD_CR2 GPIO_CR2(GPIOD)
#define GPIOE_CR2 GPIO_CR2(GPIOE)
#define GPIOF_CR2 GPIO_CR2(GPIOF)

/* GPIOx_ODR values */
#define GPIO_ODR_MASK(n) (0x1 << (n))

/* GPIOx_IDR values */
#define GPIO_IDR_MASK(n) (0x1 << (n))

/* GPIOx_DDR values */
#define GPIO_DDR_INPUT  0x0
#define GPIO_DDR_OUTPUT 0x1
#define GPIO_DDR_VAL(n, mode) ((mode) << (n))
#define GPIO_DDR_MASK(n)      (0x1    << (n))

/* GPIOx_CR1 values */
#define GPIO_CR1_OD 0x0 	/* In output mode pseudo open drain */
#define GPIO_CR1_PP 0x1 	/* In output mode push pull mode */
#define GPIO_CR1_FI 0x0	/* In input mode floating input */
#define GPIO_CR1_PU 0x1	/* In input mode input with pull-up */
#define GPIO_CR1_VAL(n, mode) ((mode) << (n))
#define GPIO_CR1_MASK(n)      (0x1    << (n))

/* GPIOx_CR2 values */
#define GPIO_CR2_ID 0x0		/* In input mode interrupts disabled */
#define GPIO_CR2_IE 0x1		/* In input mode interrupts enabled */
#define GPIO_CR2_2  0x0		/* In output mode speed up to 2 MHz */
#define GPIO_CR2_10 0x1		/* In output mode speed up to 10 MHz */
#define GPIO_CR2_VAL(n, mode) ((mode) << (n))
#define GPIO_CR2_MASK(n)      (0x1    << (n))

/* GPIO ports */
#define GPIO0 (1 << 0)
#define GPIO1 (1 << 1)
#define GPIO2 (1 << 2)
#define GPIO3 (1 << 3)
#define GPIO4 (1 << 4)
#define GPIO5 (1 << 5)
#define GPIO6 (1 << 6)
#define GPIO7 (1 << 7)

enum gpio_mode {
  GPIO_MODE_INPUT  = GPIO_DDR_INPUT,
  GPIO_MODE_OUTPUT = GPIO_DDR_OUTPUT
};

/* Function prototypes */
void gpio_mode_setup (uint16_t gpioport, enum gpio_mode mode,
		      uint8_t cr1, uint8_t cr2, uint8_t pins);

#endif
