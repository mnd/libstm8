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
  gpio_mode_setup (GPIOC, GPIO_MODE_OUTPUT, GPIO_CR1_PP, GPIO_CR2_2, GPIO3);
}

void
usart_setup ()
{
  clk_periph_clock_enable (CLK_USART1);
  usart_set_baudrate (USART1, 9600);
  usart_set_databits (USART1, 8);
  usart_set_stopbits (USART1, USART_STOPBITS_1);
  usart_set_parity (USART1, USART_PARITY_NONE);

  usart_enable_mode (USART1, USART_MODE_TX);
}

void
usart_write (const char *str)
{
  while (*str)
    usart_send_blocking (USART1, *str++);
}

int
main ()
{
  int d;

  gpio_setup ();
  usart_setup ();

  while (1)
    {
      usart_write ("Hello world\n");
      d = 0xFFFF;
      do {} while (--d);
    }
}
