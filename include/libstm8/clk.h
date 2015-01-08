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

#ifndef CLK_H
#define CLK_H

#include <libstm8/common.h>

/* TODO: Documentation from http://www.st.com/web/en/resource/technical/document/reference_manual/CD00218714.pdf */
#define CLK_BASE      0x0050C0
#define CLK_DIVR      MMIO8(CLK_BASE + 0x0) /* Clock master divider register */
#define CLK_CRTCR     MMIO8(CLK_BASE + 0x1) /* Clock RTC register */
#define CLK_ICKCR     MMIO8(CLK_BASE + 0x2) /* Internal clock control register */
#define CLK_PCKENR1   MMIO8(CLK_BASE + 0x3) /* Peripheral clock gating register 1 */
#define CLK_PCKENR2   MMIO8(CLK_BASE + 0x4) /* Peripheral clock gating register 2 */
#define CLK_CCOR      MMIO8(CLK_BASE + 0x5) /* Configurable clock control register */
#define CLK_ECKCR     MMIO8(CLK_BASE + 0x6) /* External clock control register */
#define CLK_SCSR      MMIO8(CLK_BASE + 0x7) /* System clock status register */
#define CLK_SWR       MMIO8(CLK_BASE + 0x8) /* System clock switch register */
#define CLK_SWCR      MMIO8(CLK_BASE + 0x9) /* Clock switch control register */
#define CLK_CSSR      MMIO8(CLK_BASE + 0xA) /* Clock security system register */
#define CLK_CBEEPR    MMIO8(CLK_BASE + 0xB) /* Clock BEEP register */
#define CLK_HSICALR   MMIO8(CLK_BASE + 0xC) /* HSI calibration register */
#define CLK_HSITRIMR  MMIO8(CLK_BASE + 0xD) /* HSI clock calibration trimming register */
#define CLK_HSIUNLCKR MMIO8(CLK_BASE + 0xE) /* HSI unlock register */
#define CLK_REGCSR    MMIO8(CLK_BASE + 0xF) /* Main regulator control status register */
#define CLK_PCKENR3   MMIO8(CLK_BASE + 0x10) /* Peripheral clock gating register 3 */

/* CLK values */

/* System clock prescaler. System clock source / reg_value. 
   These bits are written by software to define the system clock prescaling factor. */
#define CLK_DIV_CKM_SHIFT 0x0
#define CLK_DIV_CKM_MASK  0x7
#define CLK_DIV_CKM_1   0x0
#define CLK_DIV_CKM_2   0x1
#define CLK_DIV_CKM_4   0x2
#define CLK_DIV_CKM_8   0x3	/* default value. Maximal on low density device */
#define CLK_DIV_CKM_16  0x4
#define CLK_DIV_CKM_32  0x5
#define CLK_DIV_CKM_64  0x6
#define CLK_DIV_CKM_128 0x7

/* Clock RTC values */
/* These bits are written by software to select the clock RTC division factor.
   Any write with a non valid target code will be skipped.
   The content of these bits is frozen and write protected when RTCSWBSY is set. */
#define CLK_CRTC_DIV_SHIFT 0x5
#define CLK_CRTC_DIV_MASK  0x3
#define CLK_CRTC_DIV_1   0x0	/* default */
#define CLK_CRTC_DIV_2   0x1
#define CLK_CRTC_DIV_4   0x2
#define CLK_CRTC_DIV_8   0x3
#define CLK_CRTC_DIV_16  0x4
#define CLK_CRTC_DIV_32  0x5
#define CLK_CRTC_DIV_64  0x6
#define CLK_CRTC_DIV_128 0x7

/* These bits are written by software to select the clock source to be used by
   the RTC.  Any write with a non valid target code will be skipped.  The
   content of these bits is frozen and write protected when CLK_CRTC_SWBSY is set. */
#define CLK_CRTC_SEL_SHIFT 0x1
#define CLK_CRTC_SEL_MASK  0xf
#define CLK_CRTC_SEL_NONE 0x0
#define CLK_CRTC_SEL_HSI 0x1
#define CLK_CRTC_SEL_LSI 0x2
#define CLK_CRTC_SEL_HSE 0x4
#define CLK_CRTC_SEL_LSE 0x8
/* This bit is set by hardware any time a valid clock change for RTC is required.
   It is reset when the RTC clock change procedure is complete. */
#define CLK_CRTC_SWBSY 0x1

/* Internal clock register values */
#define CLK_ICKC_BEEPAHALT (1 << 6) /* BEEP clock Halt/Active-halt mode */
#define CLK_ICKC_FHWU   (1 << 5) /* fast wakeup from Halt/Active-halt modes */
#define CLK_ICK_CSAHALT (1 << 4) /* Disable main voltage regulator in Active-halt mode */
#define CLK_ICK_LSIRDY  (1 << 3) /* r/o. is LSI clock ready */
#define CLK_ICK_LSION   (1 << 2) /* It cannot be cleared when LSI is selected as someone clock source */
#define CLK_ICK_HSIRDY  (1 << 1) /* r/o. is HSI clock ready */
#define CLK_ICK_HSION   (1 << 0) /* It cannot be cleared when HSI is selected as someone clock source */

/* Peripheral clock gating register */
/* Enable peripheral clock */
#define CLK_PCKEN1_DAC (1 << 7)
#define CLK_PCKEN1_BEEP (1 << 6)
#define CLK_PCKEN1_USART1 (1 << 5)
#define CLK_PCKEN1_SPI1 (1 << 4)
#define CLK_PCKEN1_I2C1 (1 << 3)
#define CLK_PCKEN1_TIM4 (1 << 2)
#define CLK_PCKEN1_TIM3 (1 << 1)
#define CLK_PCKEN1_TIM2 (1 << 0)

/* The only bit which is enabled by default at reset state is used for the Boot
   ROM. Software has to be properly written to switch off the ROM clock after
   the Bootloader execution. */
#define CLK_PCKEN2_BOOT_ROM (1 << 7)
#define CLK_PCKEN2_COMP12 (1 << 5)  /* COMP1 and COMP2 */
#define CLK_PCKEN2_DMA1 (1 << 4)
#define CLK_PCKEN2_LCD (1 << 3)
#define CLK_PCKEN2_RTC (1 << 2)
#define CLK_PCKEN2_TIM1 (1 << 1)
#define CLK_PCKEN2_ADC1 (1 << 0)

#define CLK_PCKEN3_CSS_LSE (1 << 5)
#define CLK_PCKEN3_USART3 (1 << 4)
#define CLK_PCKEN3_USART2 (1 << 3)
#define CLK_PCKEN3_SPI2 (1 << 2)
#define CLK_PCKEN3_TIM5 (1 << 1)
#define CLK_PCKEN3_AES (1 << 0)

/* Configurable clock output register */
#define CLK_CCO_DIV_SHIFT 0x5
#define CLK_CCO_DIV_MASK  0x3
#define CLK_CCO_DIV_1   0x0
#define CLK_CCO_DIV_2   0x1
#define CLK_CCO_DIV_4   0x2
#define CLK_CCO_DIV_8   0x3
#define CLK_CCO_DIV_16  0x4
#define CLK_CCO_DIV_32  0x5
#define CLK_CCO_DIV_64  0x6
#define CLK_CCO_DIV_128 0x7

#define CLK_CCO_SEL_SHIFT 0x1
#define CLK_CCO_SEL_MASK  0xf
#define CLK_CCO_SEL_NONE 0x0
#define CLK_CCO_SEL_HSI 0x1
#define CLK_CCO_SEL_LSI 0x2
#define CLK_CCO_SEL_HSE 0x4
#define CLK_CCO_SEL_LSE 0x8

#define CLK_CCO_SWBSY 0x1

/* External clock register */
#define CLK_ECKC_LSEBYP (1 << 5) /* is LSE oscillator bypassed */
#define CLK_ECKC_HSEBYP (1 << 4) /* external 1-16 MHz oscillator bypassed with external clock */
#define CLK_ECKC_LSERDY (1 << 3) /* r/o. Is LSE ready */
#define CLK_ECKC_LSEON  (1 << 2)
#define CLK_ECKC_HSERDY (1 << 1)
#define CLK_ECKC_HSEON  (1 << 0)

/* System clock status register. r/o */
#define CLK_SCS_HSI 0x1         /* default */
#define CLK_SCS_LSI 0x2
#define CLK_SCS_HSE 0x4
#define CLK_SCS_LSE 0x8

/* System clock switch register */
/* this register protected by CLK_SWC_BSY */
#define CLK_SW_HSI 0x1          /* default */
#define CLK_SW_LSI 0x2
#define CLK_SW_HSE 0x4
#define CLK_SW_LSE 0x8

/* Switch control register */
#define CLK_SWC_IF  (1 << 3)    /* Clock switch interrupt flag */
#define CLK_SWC_IEN (1 << 2)    /* is clock switch interrupt enabled */
#define CLK_SWC_EN  (1 << 1)
#define CLK_SWC_BSY (1 << 0)    /* Is clock switch ongoing */
/* Writing '1' to this bit enables switching the system clock to the source
   defined in the CLK_SWR register. */

/* Clock security system register */
#define CLK_CSS_EN  (1 << 0) /* Clock security system enable */
#define CLK_CSS_AUX (1 << 1) /* Auxiliary oscillator connected to system clock */
#define CLK_CSS_DIE (1 << 2) /* Clock security system detection interrupt enable */
#define CLK_CSS_D   (1 << 3) /* clock security system detection */
#define CLK_CSS_DGON (1 << 4)   /* CSS deglitcher system */

/* Clock BEEP register */
#define CLK_CBEEP_SEL_SHIFT 0x1
#define CLK_CBEEP_SEL_MASK  0x3
#define CLK_CBEEP_SEL_NONE 0x0  /* no clock selected */
#define CLK_CBEEP_SEL_LSI 0x1   /* LSI clock used as BEEP clock source */
#define CLK_CBEEP_SEL_LSE 0x2   /* LSE clock used as BEEP clock source */

#define CLK_CBEEP_SWBSY 0x1	/* System busy during BEEP clock change */

/* CLK_HSICALR[0:7] read only factory setted */
/* CLK_HSITRIMR[0:7] user defined replacement for CLK_HSICALR */
#define CLK_HSIUNLCK_1 0xAC
#define CLK_HSIUNLCK_2 0x35
/* To set CLK_HSITRIMR you need to write CLK_HSIUNLCK_1 then CLK_HSIUNLCK_2
   in CLK_HSIUNLCKR, then set CLK_HSITRIMR
*/

/* Main regulator control status register */
#define CLK_REGCS_EEREADY (1 << 7) /* Flash program memory and Data EEPROM ready */
#define CLK_REGCS_EEBUSY  (1 << 6) /* Flash program memory and Data EEPROM busy */
#define CLK_REGCS_LSEPD   (1 << 5) /* LSE power-down */
#define CLK_REGCS_HSEPD   (1 << 4) /* HSE power-down */
#define CLK_REGCS_LSIPD   (1 << 3) /* LSI power-down */
#define CLK_REGCS_HSIPD   (1 << 2) /* HSI power-down */
#define CLK_REGCS_REGOFF  (1 << 1) /* Main regulator OFF. r/w */
#define CLK_REGCS_REGREADY (1 << 0) /* Main regulator ready */

/* Functions */
#define _REG_BIT(base, bit)		(((base) << 3) + (bit))
enum clk_periph_clken {
  CLK_DAC = _REG_BIT(0x3, 7),
  CLK_BEEP = _REG_BIT(0x3, 6),
  CLK_USART1 = _REG_BIT(0x3, 5),
  CLK_SPI1 = _REG_BIT(0x3, 4),
  CLK_I2C1 = _REG_BIT(0x3, 3),
  CLK_TIM4 = _REG_BIT(0x3, 2),
  CLK_TIM3 = _REG_BIT(0x3, 1),
  CLK_TIM2 = _REG_BIT(0x3, 0),

  CLK_BOOT_ROM = _REG_BIT(0x4, 7),
  CLK_COMP12 = _REG_BIT(0x4, 5),
  CLK_DMA1 = _REG_BIT(0x4, 4),
  CLK_LCD = _REG_BIT(0x4, 3),
  CLK_RTC = _REG_BIT(0x4, 2),
  CLK_TIM1 = _REG_BIT(0x4, 1),
  CLK_ADC1 = _REG_BIT(0x4, 0),

  CLK_CSS_LSE = _REG_BIT(0x10, 5),
  CLK_USART3 = _REG_BIT(0x10, 4),
  CLK_USART2 = _REG_BIT(0x10, 3),
  CLK_SPI2 = _REG_BIT(0x10, 2),
  CLK_TIM5 = _REG_BIT(0x10, 1),
  CLK_AES = _REG_BIT(0x10, 0)
};

void rcc_periph_clock_enable (enum clk_periph_clken clock);

#endif
