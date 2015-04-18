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

#include <libstm8/l/dma.h>

void
dma_channel_reset (uint16_t dma, enum dma_channel channel)
{
  (void) dma; /* on STM8L there is only DMA1, so ignore, at least now */

  DMA1_CxCR (channel) = 0;
  DMA1_CxNDTR (channel) = 0;
  DMA1_CxPARH (channel) = 0;
  DMA1_CxPARL (channel) = 0;
  DMA1_CxM0ARH (channel) = 0;
  DMA1_CxM0ARL (channel) = 0;
}

void
dma_set_peripheral_address (uint16_t dma, enum dma_channel channel,
			    uint16_t peripheral_adress)
{
  (void) dma;
  if (! (DMA1_CxCR (channel) & DMA1_CxCR_EN))
    {
      DMA1_CxPARH (channel) = (uint8_t) ((peripheral_adress >> 8) & 0xFF);
      DMA1_CxPARL (channel) = (uint8_t) ((peripheral_adress) & 0xFF);
    }
}

void
dma_set_number_of_data (uint16_t dma, enum dma_channel channel, uint8_t number)
{
  (void) dma;
  DMA1_CxNDTR (channel) = number;
}

void
dma_set_memory_address (uint16_t dma, enum dma_channel channel, uint16_t data)
{
  (void) dma;
  if (! (DMA1_CxCR (channel) & DMA1_CxCR_EN))
    {
      DMA1_CxM0ARH (channel) = (uint8_t) ((data >> 8) & 0xFF);
      DMA1_CxM0ARL (channel) = (uint8_t) ((data) & 0xFF);
    }
}

void
dma_set_read_from_memory (uint16_t dma, enum dma_channel channel)
{
  (void) dma;
  DMA1_CxCR (channel) |= DMA1_CxCR_DIR;
}

void
dma_enable_memory_increment_mode (uint16_t dma, enum dma_channel channel)
{
  (void) dma;
  DMA1_CxCR (channel) |= DMA1_CxCR_MINCDEC;
}

void
dma_clear_interrupt_flags (uint16_t dma, enum dma_channel channel,
			   uint8_t interrupts)
{
  (void) dma;
  DMA1_CxSPR (channel) &= ~(interrupts & (DMA1_CxSPR_TCIF | DMA1_CxSPR_HTIF));
}

void
dma_enable_transfer_complete_interrupt (uint16_t dma, enum dma_channel channel)
{
  (void) dma;
  dma_clear_interrupt_flags (dma, channel, DMA1_CxSPR_TCIF);
  DMA1_CxCR (channel) |= DMA1_CxCR_TCIE;
}

void
dma_enable_half_transfer_interrupt (uint16_t dma, enum dma_channel channel)
{
  (void) dma;
  dma_clear_interrupt_flags (dma, channel, DMA1_CxSPR_HTIF);
  DMA1_CxCR (channel) |= DMA1_CxCR_HTIE;
}

void
dma_disable_transfer_complete_interrupt (uint16_t dma, enum dma_channel channel)
{
  (void) dma;
  DMA1_CxCR (channel) &= ~DMA1_CxCR_TCIE;
}

void
dma_disable_half_transfer_interrupt (uint16_t dma, enum dma_channel channel)
{
  (void) dma;
  DMA1_CxCR (channel) &= ~DMA1_CxCR_HTIE;
}

void
dma_set_priority (uint16_t dma, enum dma_channel channel, uint8_t priority)
{
  (void) dma;
  DMA1_CxSPR (channel) &= ~(DMA1_CxSPR_PL_MASK << DMA1_CxSPR_PL_SHIFT);
  DMA1_CxSPR (channel) &= ~(priority << DMA1_CxSPR_PL_SHIFT);
}

void
dma_set_size (uint16_t dma, enum dma_channel channel, enum dma_size size)
{
  (void) dma;
  if (size)
    DMA1_CxSPR (channel) |= DMA1_CxSPR_TSIZE;
  else
    DMA1_CxSPR (channel) &= ~DMA1_CxSPR_TSIZE;
}

void
dma_enable_channel (uint16_t dma, enum dma_channel channel)
{
  (void) dma;
  DMA1_CxCR (channel) |= DMA1_CxCR_EN;
}

void
dma_disable_channel (uint16_t dma, enum dma_channel channel)
{
  (void) dma;
  DMA1_CxCR (channel) &= ~DMA1_CxCR_EN;
}

void
dma_enable (uint16_t dma)
{
  (void) dma;
  DMA1_GCSR |= DMA1_GCSR_GEN;
}

void
dma_disable (uint16_t dma)
{
  (void) dma;
  DMA1_GCSR &= ~DMA1_GCSR_GEN;
}
