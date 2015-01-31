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

#include <libstm8/stm8l.h>

void
gpio_setup ()
{
  /* GPIOE_DDR = GPIO_DD(7, GPIO_DDR_OUTPUT); */
  /* GPIOE_CR1 = GPIO_C1(7, GPIO_CR1_PP); */
  /* GPIOC_DDR = GPIO_DD(7, GPIO_DDR_OUTPUT); */
  /* GPIOC_CR1 = GPIO_C1(7, GPIO_CR1_PP); */

  gpio_mode_setup (GPIOE, GPIO_MODE_OUTPUT, GPIO_CR1_PP, GPIO_CR2_2, GPIO7);
  gpio_mode_setup (GPIOE, GPIO_MODE_OUTPUT, GPIO_CR1_PP, GPIO_CR2_2, GPIO7);
}

int
main ()
{
  int d;

  gpio_setup ();

  GPIOE_ODR ^= GPIO7;		/* change output value on port E pin 7 */
  while (1)
    {
      GPIOE_ODR ^= GPIO7;
      GPIOC_ODR ^= GPIO7;
      d = 60000;
      do {} while (--d);
    }
}
