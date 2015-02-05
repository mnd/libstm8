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

#include <libstm8/lcd.h>
#include <libstm8/clk.h>

void
lcd_enable (void)
{
  LCD_CR3 |= LCD_CR3_LCDEN;
}

void
lcd_enable_segments (uint32_t segments)
{
  uint8_t n = 0;
  while (segments & 0x00FFFFFF)
    {
      if (segments & 1) LCD_PM_ENABLE_SEG(n);
      n++;
      segments >>= 1;
    }
}

void
lcd_disable_segments (uint32_t segments)
{
  uint8_t n = 0;
  while (segments)
    {
      if (segments & 1) LCD_PM_DISABLE_SEG(n);
      n++;
      segments >>= 1;
    }
}

void
lcd_wait_for_update_ready (void)
{
  LCD_CR3 |= LCD_CR3_SOFC;
  do {} while ((LCD_CR3 & LCD_CR3_SOF) == 0);
}

void
lcd_set_contrast (enum lcd_contrast contrast)
{
  LCD_CR2 &= ~(LCD_CR2_CC_MASK << LCD_CR2_CC_SHIFT);
  LCD_CR2 |= contrast << LCD_CR2_CC_SHIFT;
}

void
lcd_set_bias (enum lcd_bias bias)
{
  switch (bias)
    {
    case LCD_BIAS_1_3:
      LCD_CR1 |= LCD_CR1_BIAS_1_2;
      break;
    case LCD_BIAS_1_2:
      LCD_CR1 &= ~LCD_CR1_BIAS_1_2;
      break;
    case LCD_BIAS_1_4:
      LCD_CR1 &= ~LCD_CR1_BIAS_1_2;
      LCD_CR4 |= LCD_CR4_BIAS_1_4;
      break;
    }
}

void
lcd_set_duty (enum lcd_duty duty)
{
  LCD_CR1 &= ~(LCD_CR1_DUTY_MASK << LCD_CR1_DUTY_SHIFT);
  LCD_CR4 &= ~LCD_CR4_DUTY_8;

  switch (duty)
    {
    case LCD_DUTY_1_8:
      LCD_CR4 |= LCD_CR4_DUTY_8;
      break;
    default:
      LCD_CR1 |= duty << LCD_CR1_DUTY_SHIFT;
    }
}

void
lcd_set_prescaler (uint8_t ps)
{
  LCD_FRQ &= ~(LCD_FRQ_PS_MASK << LCD_FRQ_PS_SHIFT);
  LCD_FRQ |= ps << LCD_FRQ_PS_SHIFT;
}

void
lcd_set_divider (uint8_t div)
{
  LCD_FRQ &= ~(LCD_FRQ_DIV_MASK << LCD_FRQ_DIV_SHIFT);
  LCD_FRQ |= div << LCD_FRQ_DIV_SHIFT;
}

void
lcd_set_refresh_frequency (uint32_t frequency)
{
  uint32_t duty, lcd_clock, ps_mul_div;
  uint8_t div, ps;
  if (LCD_CR4 & LCD_CR4_DUTY_8)
    duty = 8;
  else
    duty = (LCD_CR1 >> LCD_CR1_DUTY_SHIFT) & LCD_CR1_DUTY_MASK;

  switch ((CLK_CRTCR >> CLK_CRTC_SEL_SHIFT) & CLK_CRTC_SEL_MASK)
    {
    case CLK_CRTC_SEL_HSI:
      lcd_clock = 16000000 / 2;
      break;
    case CLK_CRTC_SEL_LSI:
      lcd_clock = 38000 / 2;
      break;
    case CLK_CRTC_SEL_LSE:
      lcd_clock = 32786 / 2;
      break;
    case CLK_CRTC_SEL_HSE:    /* unknown. TODO: global variable to get value? */
    default:
      return;
    }
  lcd_clock >>= (CLK_CRTCR >> CLK_CRTC_DIV_SHIFT) & CLK_CRTC_DIV_MASK;

  ps_mul_div = lcd_clock / (frequency * duty);
  ps = 0;
  while (ps_mul_div >= 32)
    {
      ps_mul_div >>= 1;
      ps++;
    }
  div = ps_mul_div - 16;

  lcd_set_prescaler (ps);
  lcd_set_divider (div);
}
