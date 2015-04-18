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

char tx[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\r\n";
int tx_len = 125;

void
clock_setup (void)
{
  clk_periph_clock_enable (CLK_USART1);
  clk_periph_clock_enable (CLK_DMA1);  
}

void
gpio_setup (void)
{
  /* USART_TX */
  gpio_mode_setup (GPIOC, GPIO_MODE_OUTPUT, GPIO_CR1_PP, GPIO_CR2_2, GPIO3);
}

void
usart_setup (void)
{
  usart_set_baudrate (USART1, 9600);
  usart_set_databits (USART1, 8);
  usart_set_stopbits (USART1, USART_STOPBITS_1);
  usart_set_parity (USART1, USART_PARITY_NONE);
  // usart_set_flow_control (USART1, USART_FLOWCONTROL_NONE);

  usart_enable_mode (USART1, USART_MODE_TX);

  /* nvic_set_priority(NVIC_DMA1_CHANNEL1_IRQ, 0); */
  /* nvic_enable_irq(NVIC_DMA1_CHANNEL1_IRQ); */
}

void
dma_write (char *data, int size)
{
  dma_channel_reset (DMA1_BASE, DMA_CHANNEL1);
  
  dma_set_peripheral_address (DMA1_BASE, DMA_CHANNEL1, (uint16_t)&USART1_DR);
  dma_set_memory_address(DMA1_BASE, DMA_CHANNEL1, (uint16_t)data);
  dma_set_number_of_data (DMA1_BASE, DMA_CHANNEL1, size);

  dma_set_read_from_memory (DMA1_BASE, DMA_CHANNEL1);
  dma_enable_memory_increment_mode (DMA1_BASE, DMA_CHANNEL1);

  dma_set_size (DMA1_BASE, DMA_CHANNEL1, DMA_TSIZE_8BIT);
  dma_set_priority (DMA1_BASE, DMA_CHANNEL1, DMA1_CxSPR_PL_VERY_HIGH);
  /* dma_enable_transfer_complete_interrupt (DMA1_BASE, DMA_CHANNEL1); */
  dma_enable_channel (DMA1_BASE, DMA_CHANNEL1);
  dma_enable (DMA1_BASE);

  usart_enable_tx_dma (USART1);
}

int
main (void)
{
  clock_setup ();
  gpio_setup ();
  usart_setup ();

  dma_write (tx, tx_len);
  do {} while (DMA1_CxNDTR (DMA_CHANNEL1)); /* transfer ended */
  dma_disable_transfer_complete_interrupt (DMA1_BASE, DMA_CHANNEL1);
  usart_disable_tx_dma (USART1);
  dma_disable_channel (DMA1_BASE, DMA_CHANNEL1);

  do {} while (1);
}
