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

#include <libstm8/l/gpio.h>

void
gpio_mode_setup (uint16_t gpioport, enum gpio_mode mode,
		 uint8_t c1_mode, uint8_t c2_mode, uint8_t pins)
{
  uint8_t cr1, cr2, ddr, i;
  cr1 = GPIO_CR1(gpioport);
  cr2 = GPIO_CR2(gpioport);
  ddr = GPIO_DDR(gpioport);
  for (i = 0; i < 8; ++i)
    {
      if (! (pins & (1 << i))) continue;

      cr1 &= ~GPIO_CR1_MASK(i);
      cr1 |= GPIO_CR1_VAL(i, c1_mode);

      cr2 &= ~GPIO_CR2_MASK(i);
      cr2 |= GPIO_CR2_VAL(i, c2_mode);

      ddr &= ~GPIO_DDR_MASK(i);
      ddr |= GPIO_DDR_VAL(i, mode);
    }
  
  GPIO_CR1(gpioport) = cr1;
  GPIO_CR2(gpioport) = cr2;
  GPIO_DDR(gpioport) = ddr;
}
