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

#include <stdbool.h>
#include <stdio.h>
#include <libstm8/stm8l.h>

static void
lcd_init (void)
{
  gpio_mode_setup (GPIOA, GPIO_MODE_OUTPUT, GPIO_C1_OD, GPIO_C2_2,
		   GPIO4 | GPIO5 | GPIO6 | GPIO7);
  gpio_mode_setup (GPIOB, GPIO_MODE_OUTPUT, GPIO_C1_OD, GPIO_C2_2,
		   GPIO0 | GPIO1 | GPIO2 | GPIO3 | GPIO4 | GPIO5 | GPIO6 | GPIO7);
  gpio_mode_setup (GPIOC, GPIO_MODE_OUTPUT, GPIO_C1_OD, GPIO_C2_2,
		   GPIO2 | GPIO3);
  gpio_mode_setup (GPIOD, GPIO_MODE_OUTPUT, GPIO_C1_OD, GPIO_C2_2,
		   GPIO0 | GPIO1 | GPIO2 | GPIO3 | GPIO4 | GPIO5 | GPIO6 | GPIO7);
  gpio_mode_setup (GPIOE, GPIO_MODE_OUTPUT, GPIO_C1_OD, GPIO_C2_2,
		   GPIO0 | GPIO1 | GPIO2 | GPIO3 | GPIO4 | GPIO5);
  
  clk_periph_clock_enable (CLK_RTC);
  clk_periph_clock_enable (CLK_LCD);
  clk_rtc_select_clock (CLK_CRTC_SEL_HSI);

 /* enable all 24 segments. Now correspondend pins can't be used as GPIO */
  lcd_enable_segments (0xFFFFFFL); /* disable segment 23 -- PC */
  lcd_set_duty (LCD_DUTY_1_4);
  lcd_set_bias (LCD_BIAS_1_4);

  /* Set screen redraw frequency to 64Hz */
  lcd_set_refresh_frequency (64);
  /* And increase contrast */
  lcd_set_contrast (LCD_CC_5);

  lcd_enable ();
}

static void
clear_lcd_ram(void)
{
  LCD_RAM0 = 0;
  LCD_RAM1 = 0;
  LCD_RAM2 = 0;
  LCD_RAM3 = 0;
  LCD_RAM4 = 0;
  LCD_RAM5 = 0;
  LCD_RAM6 = 0;
  LCD_RAM7 = 0;
  LCD_RAM8 = 0;
  LCD_RAM9 = 0;
  LCD_RAM10 = 0;
  LCD_RAM11 = 0;
  LCD_RAM12 = 0;
  LCD_RAM13 = 0;
}

/*	LCD MAPPING:
	    A
     _  ----------
COL |_| |\   |J  /|
       F| H  |  K |B
     _  |  \ | /  |
COL |_| --G-- --M--
        |   /| \  |
       E|  Q |  N |C
     _  | /  |P  \|
DP  |_| -----------
	    D

`mask' corresponds to bits in lexicographic order: mask & 1 == A, mask & 2 == B,
and so on.
 */
static void write_mask_to_lcd_ram (int position, uint16_t mask, int clear_before)
{
  int P1, P2, P3, P4;
 /* HACK: COMx contains copy of LCD_RAM only 
    if any writing go through this function */
  static uint32_t COM0, COM1, COM2, COM3;

  /* Every pixel of character at position can be accessed
     as LCD_RAM_COMx & (1 << Px) */
  P1 = 2*position;
  P2 = P1+1;
  
  P3 = 23 - 2*position;
  P4 = P3 - 1;

  if (clear_before)
    {
      COM0 &= ~(1L << P1 | 1L << P2 | 1L << P3 | 1L << P4);
      COM1 &= ~(1L << P1 | 1L << P2 | 1L << P3 | 1L << P4);
      COM2 &= ~(1L << P1 | 1L << P2 | 1L << P3 | 1L << P4);
      COM3 &= ~(1L << P1 | 1L << P2 | 1L << P3 | 1L << P4);
    }
	
  COM0 = COM0
    | ((uint32_t) ((mask >> 0x1) & 1) << P4) 
    | ((uint32_t) ((mask >> 0x4) & 1) << P1)
    | ((uint32_t) ((mask >> 0x6) & 1) << P3)
    | ((uint32_t) ((mask >> 0xA) & 1) << P2);
  COM1 = COM1
    | ((uint32_t) ((mask >> 0x0) & 1) << P4) 
    | ((uint32_t) ((mask >> 0x2) & 1) << P2)
    | ((uint32_t) ((mask >> 0x3) & 1) << P1)
    | ((uint32_t) ((mask >> 0x5) & 1) << P3);
  COM3 = COM3
    | ((uint32_t) ((mask >> 0x7) & 1) << P3)
    | ((uint32_t) ((mask >> 0x8) & 1) << P4)
    | ((uint32_t) ((mask >> 0xB) & 1) << P1)
    | ((uint32_t) ((mask >> 0xE) & 1) << P2);
  COM2 = COM2
    | ((uint32_t) ((mask >> 0x9) & 1) << P4)
    | ((uint32_t) ((mask >> 0xC) & 1) << P1)
    | ((uint32_t) ((mask >> 0xD) & 1) << P3)
    | ((uint32_t) ((mask >> 0xF) & 1)) << P2;

  LCD_RAM0  = (COM0 >>  0) & 0xFF;
  LCD_RAM1  = (COM0 >>  8) & 0xFF;
  LCD_RAM2  = (COM0 >> 16) & 0xFF;
  LCD_RAM3  = ((COM0 >>24) & 0x0F) | (((COM1 >> 0) & 0x0F) << 4);
  LCD_RAM4  = (COM1 >>  4) & 0xFF;
  LCD_RAM5  = (COM1 >> 12) & 0xFF;
  LCD_RAM6  = (COM1 >> 20) & 0xFF;
  LCD_RAM7  = (COM2 >>  0) & 0xFF;
  LCD_RAM8  = (COM2 >>  8) & 0xFF;
  LCD_RAM9  = (COM2 >> 16) & 0xFF;
  LCD_RAM10 = ((COM2 >>24) & 0x0F) | (((COM3 >> 0) & 0x0F) << 4);
  LCD_RAM11 = (COM3 >>  4) & 0xFF;
  LCD_RAM12 = (COM3 >> 12) & 0xFF;
  LCD_RAM13 = (COM3 >> 20) & 0xFF;
}

static void
write_char_to_lcd_ram (int position, uint8_t symbol, bool clear_before)
{
  uint16_t from_ascii[0x60] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    /*         !       "       #       $      %        &       ' */
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    /* (       )       *       +       ,       -       .       / */
    0x0000, 0x0000, 0x3FC0, 0x1540, 0x0000, 0x0440, 0x4000, 0x2200,
    /* 0       1       2       3       4       5       6       7 */
    0x003F, 0x0006, 0x045B, 0x044F, 0x0466, 0x046D, 0x047D, 0x2201,
    /* 8       9       :       ;       <       =       >       ? */
    0x047F, 0x046F, 0x8000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    /* @       A       B       C       D       E       F       G */
    0x0000, 0x0477, 0x047C, 0x0039, 0x045E, 0x0479, 0x0471, 0x043D,
    /* H       I       J       K       L       M       N       O */
    0x0476, 0x1109, 0x001E, 0x1B00, 0x0038, 0x02B6, 0x08B6, 0x003F,
    /* P       Q       R       S       T       U       V       W */
    0x0473, 0x0467, 0x0C73, 0x046D, 0x1101, 0x003E, 0x0886, 0x2836,
    /* X       Y       Z       [       \       ]       ^       _ */
    0x2A80, 0x1280, 0x2209, 0x0000, 0x0880, 0x0000, 0x0000, 0x0008
  };
  if (symbol > 0x60) return; // masks not defined. Nothing to display
	
  write_mask_to_lcd_ram (position, from_ascii[symbol], clear_before);
}


static void
lcd_display_hello (void)
{
  lcd_wait_for_update_ready ();
  clear_lcd_ram (); 	/* all segments off */
  write_char_to_lcd_ram (0, '*', true);
  write_char_to_lcd_ram (1, 'H', true);
  write_char_to_lcd_ram (2, 'E', true);
  write_char_to_lcd_ram (3, 'L', true);
  write_char_to_lcd_ram (4, 'L', true);
  write_char_to_lcd_ram (5, 'O', true);
}

int
main (void)
{
  lcd_init ();

  lcd_display_hello ();

  do {} while (1);
}
