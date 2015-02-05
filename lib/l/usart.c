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

#include <libstm8/l/usart.h>
#include <libstm8/l/clk.h>

void
usart_set_baudrate (uint16_t usart, uint32_t baud)
{
  uint32_t clock;
  uint16_t div;
  switch (CLK_SCSR)
    {
    case CLK_SCS_HSI:
      clock = 16000000;
      break;
    case CLK_SCS_LSI:
      clock = 38000;
      break;
    case CLK_SCS_LSE:
      clock = 32786;
      break;
    case CLK_SCS_HSE:	      /* unknown. TODO: global variable to get value? */
    defalut:
      return;
    }
  clock >>= (CLK_DIVR >> CLK_DIV_CKM_SHIFT) & CLK_DIV_CKM_MASK; /* sysclk speed */

  div = ((clock * 2) / baud + 1) / 2;
  USART_BRR1(usart) = (div >> 4) & 0xff;
  USART_BRR2(usart) = ((div >> 8) & 0xf0) | (div & 0xf);
}

void
usart_set_databits (uint16_t usart, uint8_t bits)
{
  if (bits == 8)
    USART_CR1(usart) &= ~USART_CR1_M; /* 8 bits */
  else
    USART_CR1(usart) |= USART_CR1_M; /* 9 bits */
}

void
usart_set_stopbits (uint16_t usart, enum usart_stopbits stopbits)
{
  uint8_t cr3 = USART_CR3(usart);
  cr3 = (cr3 & ~USART_STOPBITS_MASK) | stopbits;
  USART_CR3(usart) = cr3;
}

void
usart_enable_mode (uint16_t usart, enum usart_mode mode)
{
  uint8_t cr2 = USART_CR2(usart);
  cr2 = (cr2 & ~USART_MODE_MASK) | mode;
  USART_CR2(usart) = cr2;
}

void
usart_set_parity (uint16_t usart, enum usart_parity parity)
{
  uint8_t cr1 = USART_CR1(usart);

  cr1 = (cr1 & ~USART_PARITY_MASK) | parity;
  USART_CR1(usart) = cr1;
}

void
usart_wait_send_ready (uint16_t usart)
{
  do { } while (!(USART_SR(usart) & USART_SR_TXE));
}

void
usart_send (uint16_t usart, uint8_t byte)
{
  USART_DR(usart) = byte;
}

void
usart_send_blocking (uint16_t usart, uint8_t byte)
{
  usart_wait_send_ready (usart);
  usart_send (usart, byte);
}
