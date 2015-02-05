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
#include <libstm8/l/adc.h>

void
adc_power_on ()
{
  ADC1_CR1 |= ADC1_CR1_ADON;
}

void
adc_off ()
{
  ADC1_CR1 &= ~ADC1_CR1_ADON;
}

void
adc_set_sample_time (uint8_t channel, enum adc_smtp time)
{
  if (channel <= 23)
    {
      ADC1_CR2 &= ~(ADC1_CR2_SMTP1_MASK << ADC1_CR2_SMTP1_SHIFT);
      ADC1_CR2 |= ((uint8_t) time) << ADC1_CR2_SMTP1_SHIFT;
    }
  else
    {
      ADC1_CR3 &= ~(ADC1_CR3_SMTP2_MASK << ADC1_CR3_SMTP2_SHIFT);
      ADC1_CR3 |= ((uint8_t) time) << ADC1_CR3_SMTP2_SHIFT;
    }
}

void
adc_set_sample_time_on_all_channels (enum adc_smtp time)
{
  adc_set_sample_time (0, time);
  adc_set_sample_time (24, time);
}

void
adc_select_channel (enum adc_channel channel)
{
  MMIO8(ADC1_SQR_BASE + (channel >> 3)) |= 1 << (channel & 0x7);
}

void
adc_disable_schmitt_trigger (enum adc_channel channel)
{
  MMIO8(ADC1_TRIGR_BASE + (channel >> 3)) |= 1 << (channel & 0x7);
}

void
adc_set_resolution (enum adc_resolution resolution)
{
  ADC1_CR1 &= ~(ADC1_CR1_RES_MASK << ADC1_CR1_RES_SHIFT);
  ADC1_CR1 &= ((uint8_t) resolution) << ADC1_CR1_RES_SHIFT;
}

void
adc_set_continuous_conversion_mode ()
{
  ADC1_SQR1 &= ~ADC1_SQR1_DMAOFF;
  ADC1_CR1 |= ADC1_CR1_CONT;
}

void
adc_set_single_conversion_mode ()
{
  ADC1_SQR1 |= ADC1_SQR1_DMAOFF;
  ADC1_CR1 &= ~ADC1_CR1_CONT;
}

void
adc_start_conversion ()
{
  ADC1_CR1 |= ADC1_CR1_START;
}

uint8_t
adc_eoc ()
{
  return (ADC1_SR & ADC1_SR_EOC);
}

uint16_t
adc_read_regular ()
{
  uint16_t data = ADC1_DRH << 8;
  data |= ADC1_DRL;
  return data;
}
