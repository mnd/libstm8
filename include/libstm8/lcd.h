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
#ifndef LCD_H
#define LCD_H

#include <libstm8/common.h>

#define LCD_BASE 0x005400	/* Base address for LCD registers */
#define LCD_CR1 MMIO8(LCD_BASE + 0x00)	/* LCD control register 1 */
#define LCD_CR2 MMIO8(LCD_BASE + 0x01)	/* LCD control register 2 */
#define LCD_CR3 MMIO8(LCD_BASE + 0x02)	/* LCD control register 3 */
#define LCD_FRQ MMIO8(LCD_BASE + 0x03)	/* LCD frequency selection register */
#define LCD_PM0 MMIO8(LCD_BASE + 0x04)	/* LCD Port mask register 0 */
#define LCD_PM1 MMIO8(LCD_BASE + 0x05)	/* LCD Port mask register 1 */
#define LCD_PM2 MMIO8(LCD_BASE + 0x06)	/* LCD Port mask register 2 */
#define LCD_PM3 MMIO8(LCD_BASE + 0x07)	/* LCD Port mask register 3 */
#define LCD_PM4 MMIO8(LCD_BASE + 0x08)
#define LCD_PM5 MMIO8(LCD_BASE + 0x09)
#define LCD_CR4 MMIO8(LCD_BASE + 0x2F)


/* CR1 register map */

#define LCD_CR1_BLINK_SHIFT		6 /* Which segments to blink */
#define LCD_CR1_BLINK_MASK		0x3
#define LCD_CR1_BLINK_DISABLE		0x0
#define LCD_CR1_BLINK_SEG0_COM0_ENABLE	0x1
#define LCD_CR1_BLINK_SEG0_ENABLE	0x2
#define LCD_CR1_BLINK_ALL_ENABLE	0x3

#define LCD_CR1_BLINKF_SHIFT	3 /* Blink frequency */
#define LCD_CR1_BLINKF_MASK	0x7
#define LCD_CR1_BLINKF_8	0x0 /* 1/8 */
#define LCD_CR1_BLINKF_16	0x1
#define LCD_CR1_BLINKF_32	0x2
#define LCD_CR1_BLINKF_64	0x3
#define LCD_CR1_BLINKF_128	0x4
#define LCD_CR1_BLINKF_256	0x5
#define LCD_CR1_BLINKF_512	0x6
#define LCD_CR1_BLINKF_1024	0x7 /* 1/1024 */

#define LCD_CR1_DUTY_SHIFT	1 /* duty ratio selection */
#define LCD_CR1_DUTY_MASK	0x3
#define LCD_CR1_DUTY_STATIC	0x0
#define LCD_CR1_DUTY_1_2	0x1
#define LCD_CR1_DUTY_1_3	0x2
#define LCD_CR1_DUTY_1_4	0x3

#define LCD_CR1_BIAS_1_2	0x1

/* CR2 register map */

/* Pulse ON duration. Short time is lower power consumtion but less contrast */
#define LCD_CR2_PON_SHIFT	5
#define LCD_CR2_PON_MASK	0x7
#define LCD_CR2_PON_0		0x0
#define LCD_CR2_PON_1		0x1
#define LCD_CR2_PON_2		0x2
#define LCD_CR2_PON_3		0x3
#define LCD_CR2_PON_4		0x4
#define LCD_CR2_PON_5		0x5
#define LCD_CR2_PON_6		0x6
#define LCD_CR2_PON_7		0x7

#define LCD_CR2_HD	(1 << 4) /* is hard drive permanent enabled */

/* Contrast control.
   These bits specify one of the V_LCD maximum voltage (independent of V_DD) */
#define LCD_CR2_CC_SHIFT	1
#define LCD_CR2_CC_MASK		0x7
#define LCD_CR2_CC_0		0x0
#define LCD_CR2_CC_1		0x1
#define LCD_CR2_CC_2		0x2
#define LCD_CR2_CC_3		0x3
#define LCD_CR2_CC_4		0x4
#define LCD_CR2_CC_5		0x5
#define LCD_CR2_CC_6		0x6
#define LCD_CR2_CC_7		0x7

/* Select voltage: Internal (0) or external (1) */
#define LCD_CR2_VSEL	(1 << 0)

/* CR3 register map */

#define LCD_CR3_LCDEN	(1 << 6) /* LCD enabled */
#define LCD_CR3_SOFIE	(1 << 5) /* LCD start of frame interrupt enabled */
#define LCD_CR3_SOF	(1 << 4) /* r/o start of frame flag. Cleared with SOFC */
#define LCD_CR3_SOFC	(1 << 3) /* w/o clear SOF flag */

#define LCD_CR3_DEAD_SHIFT	0
#define LCD_CR3_DEAD_MASK	0x7
#define LCD_CR3_DEAD_NONE	0x0
#define LCD_CR3_DEAD_1_PHASE	0x1
#define LCD_CR3_DEAD_2_PHASE	0x2
#define LCD_CR3_DEAD_3_PHASE	0x3
#define LCD_CR3_DEAD_4_PHASE	0x4
#define LCD_CR3_DEAD_5_PHASE	0x5
#define LCD_CR3_DEAD_6_PHASE	0x6
#define LCD_CR3_DEAD_7_PHASE	0x7

/* LCD clock prescaler */
#define LCD_FRQ_PS_SHIFT	4
#define LCD_FRQ_PS_MASK		0xF
#define LCD_FRQ_PS_1		0x0
#define LCD_FRQ_PS_2		0x1
#define LCD_FRQ_PS_4		0x2
#define LCD_FRQ_PS_8		0x3
#define LCD_FRQ_PS_16		0x4
#define LCD_FRQ_PS_32		0x5
#define LCD_FRQ_PS_64		0x6
#define LCD_FRQ_PS_128		0x7
#define LCD_FRQ_PS_256		0x8
#define LCD_FRQ_PS_512		0x9
#define LCD_FRQ_PS_1024		0xA
#define LCD_FRQ_PS_2048		0xB
#define LCD_FRQ_PS_4096		0xC
#define LCD_FRQ_PS_8192		0xD
#define LCD_FRQ_PS_16384	0xE
#define LCD_FRQ_PS_32768	0xF

/* LCD clock divider */
#define LCD_FRQ_DIV_SHIFT	0
#define LCD_FRQ_DIV_MASK	0xF
#define LCD_FRQ_DIV_16		0x0
#define LCD_FRQ_DIV_17		0x1
#define LCD_FRQ_DIV_18		0x2
#define LCD_FRQ_DIV_19		0x3
#define LCD_FRQ_DIV_20		0x4
#define LCD_FRQ_DIV_21		0x5
#define LCD_FRQ_DIV_22		0x6
#define LCD_FRQ_DIV_23		0x7
#define LCD_FRQ_DIV_24		0x8
#define LCD_FRQ_DIV_25		0x9
#define LCD_FRQ_DIV_26		0xA
#define LCD_FRQ_DIV_27		0xB
#define LCD_FRQ_DIV_28		0xC
#define LCD_FRQ_DIV_29		0xD
#define LCD_FRQ_DIV_30		0xE
#define LCD_FRQ_DIV_31		0xF

/* LCD PM registers */

/* These bits determine the number of port pins to be used as segment drivers. */
#define LCD_PM(n)	MMIO8(LCD_BASE + 0x04 + (n))
#define LCD_PM_SEG(n)   (1 << ((n) % 0x8))
#define LCD_PM_ENABLE_SEG(n)	(LCD_PM((n) / 0x8) |= LCD_PM_SEG(n))
#define LCD_PM_DISABLE_SEG(n)	(LCD_PM((n) / 0x8) &= ~LCD_PM_SEG(n))

/* LCD CR4 register map */
#define LCD_CR4_PAGE_COM	(1 << 2)
#define LCD_CR4_DUTY_8		(1 << 1)
#define LCD_CR4_BIAS_1_4	(1 << 0)

/* LCD RAM */

#define LCD_RAM_BASE 0x00540C
#define LCD_RAM(n) MMIO8(LCD_RAM_BASE + (n))

#define LCD_RAM0  LCD_RAM(0x0)	/* LCD display memory 0 */
#define LCD_RAM1  LCD_RAM(0x1)	/* LCD display memory 1 */
#define LCD_RAM2  LCD_RAM(0x2)	/* LCD display memory 2 */
#define LCD_RAM3  LCD_RAM(0x3)	/* LCD display memory 3 */
#define LCD_RAM4  LCD_RAM(0x4)	/* LCD display memory 4 */
#define LCD_RAM5  LCD_RAM(0x5)	/* LCD display memory 5 */
#define LCD_RAM6  LCD_RAM(0x6)	/* LCD display memory 6 */
#define LCD_RAM7  LCD_RAM(0x7)	/* LCD display memory 7 */
#define LCD_RAM8  LCD_RAM(0x8)	/* LCD display memory 8 */
#define LCD_RAM9  LCD_RAM(0x9)	/* LCD display memory 9 */
#define LCD_RAM10 LCD_RAM(0xA)	/* LCD display memory 10 */
#define LCD_RAM11 LCD_RAM(0xB)	/* LCD display memory 11 */
#define LCD_RAM12 LCD_RAM(0xC)	/* LCD display memory 12 */
#define LCD_RAM13 LCD_RAM(0xD)	/* LCD display memory 13 */

/* COM0: RAM0[0:7] RAM1[0:7] RAM2[0:7] RAM3[0:3]
   COM1: RAM3[4:7] RAM4[0:7] RAM5[0:7] RAM6[0:7]
   COM2: RAM7[0:7] RAM8[0:7] RAM9[0:7] RAM10[0:3]
   COM3: RAM10[4:7] RAM11[0:7] RAM12[0:7] RAM13[0:7]

   COM0: RAM14[0:7] RAM15[0:7]
   COM1: RAM16[0:7] RAM17[0:7]
   COM2: RAM18[0:7] RAM19[0:7]
   COM3: RAM20[0:7] RAM21[0:7]

   COM4-COM7 -- same addreses as COM0-COM3.
   To enable COM4-COM7 we need set bit LCD_CR4_DUTY_8.
   To switch addresses from COM(n) to COM(n+4) we must set LCD_CR4_PAGE_COM bit.
*/

enum lcd_contrast {
  LCD_CC_0 = LCD_CR2_CC_0,
  LCD_CC_1 = LCD_CR2_CC_1,
  LCD_CC_2 = LCD_CR2_CC_2,
  LCD_CC_3 = LCD_CR2_CC_3,
  LCD_CC_4 = LCD_CR2_CC_4,
  LCD_CC_5 = LCD_CR2_CC_5,
  LCD_CC_6 = LCD_CR2_CC_6,
  LCD_CC_7 = LCD_CR2_CC_7
};

enum lcd_bias {
  LCD_BIAS_1_3 = 0x0,
  LCD_BIAS_1_2 = 0x1,
  LCD_BIAS_1_4 = 0x2
};

enum lcd_duty {
  LCD_DUTY_STATIC = LCD_CR1_DUTY_STATIC,
  LCD_DUTY_1_2 = LCD_CR1_DUTY_1_2,
  LCD_DUTY_1_3 = LCD_CR1_DUTY_1_3,
  LCD_DUTY_1_4 = LCD_CR1_DUTY_1_4,
  LCD_DUTY_1_8  		/* LCD_DUTY_1_4 + 1 */
};

void lcd_enable (void);
void lcd_enable_segments (uint32_t segments);
void lcd_disable_segments (uint32_t segments);

void lcd_wait_for_update_ready (void);

void lcd_set_contrast (enum lcd_contrast contrast);
void lcd_set_bias (enum lcd_bias bias);
void lcd_set_duty (enum lcd_duty duty);
void lcd_set_prescaler (uint8_t ps);
void lcd_set_divider (uint8_t div);
void lcd_set_refresh_frequency (uint32_t frequency);


#endif
