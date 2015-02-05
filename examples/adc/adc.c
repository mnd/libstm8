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

#include <stdio.h>
#include <libstm8/stm8l.h>

void
putchar (char c)
{
  usart_send_blocking (USART1, c);
}

void
usart_setup ()
{
  gpio_mode_setup (GPIOC, GPIO_MODE_OUTPUT, GPIO_CR1_PP, GPIO_CR2_2, GPIO3);

  clk_periph_clock_enable (CLK_USART1);
  usart_set_baudrate (USART1, 9600);
  usart_set_databits (USART1, 8);
  usart_set_stopbits (USART1, USART_STOPBITS_1);
  usart_set_parity (USART1, USART_PARITY_NONE);

  usart_enable_mode (USART1, USART_MODE_TX);
}

void
adc_setup ()
{
  uint16_t i = 0xFFF;
  clk_periph_clock_enable (CLK_ADC1);

  adc_set_single_conversion_mode ();
  /* We want to read V_REFINT, so we have to select it. */
  adc_enable_trigger (ADC_CH_VREFINT);
  adc_select_channel (ADC_CH_VREFINT);
  adc_set_sample_time_on_all_channels (ADC_SMTP_192);

  adc_power_on ();

  
  /* Wait for ADC starting up. */
  do {} while (--i);
}

int
main ()
{
  uint16_t d, v;
  usart_setup ();
  adc_setup ();

  while (1)
    {
      adc_start_conversion ();
      do {} while (adc_eoc () == 0);
      v = adc_read_regular ();

      printf ("ADC V_REFINT: %u\n", v);
      d = 0xFFFF;
      do {} while (--d);
    }
}
