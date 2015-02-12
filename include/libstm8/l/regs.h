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

#ifndef REGS_H
#define REGS_H

/* Factory conversion registers */

#define VREFINT_Factory_CONV  MMIO8(0x004910)	/* Internal reference voltage factory conversion */
#define TS_Factory_CONV_V90   MMIO8(0x004911)	/* Temperature sensor output voltage */

/* The VREFINT_Factory_CONV byte represents the 8 LSB of the result 
   of the VREFINT 12-bit ADC conversion performed in factory. 
   The MSB have a fixed value: 0x6.

   The TS_Factory_CONV_V90 byte represents the 8 LSB of the result
   of the V90 12-bit ADC conversion performed in factory.
   The 2 MSB have a fixed value: 0x3.
*/

/* General hardware register map */

/* I/O port hardware register map */
#include <libstm8/l/gpio.h>

/* CLK register map */
#include <libstm8/l/clk.h>

/* USART register map */
#include <libstm8/l/usart.h>

/* LCD register map */
#include <libstm8/l/lcd.h>

/* PWR register map */
#include <libstm8/l/pwr.h>

/* RST register map */
#include <libstm8/l/rst.h>

/* Routing Interface register map */
#include <libstm8/l/ri.h>

/* SYSCFG register map */
#include <libstm8/l/syscfg.h>

/* DMA register map */
#include <libstm8/l/dma.h>

/* ADC register map */
#include <libstm8/l/adc.h>

/* DAC register map */
#include <libstm8/l/dac.h>

/* COMP register map */
#include <libstm8/l/comp.h>

/* TIM 1 / TIM 2,3,5 / TIM 4 register map */
#include <libstm8/l/tim.h>

/* IRTIM register map */
#include <libstm8/l/ir.h>

/* BEEP register map */
#include <libstm8/l/beep.h>

/* RTC register map */
#include <libstm8/l/rtc.h>

/* IWDG register map */
#include <libstm8/l/iwdg.h>

/* WWDG register map */
#include <libstm8/l/wwdg.h>

/* AES register map */
#include <libstm8/l/aes.h>

/* I2C register map */
#include <libstm8/l/i2c.h>

/* SPI register map */
#include <libstm8/l/spi.h>

/* ITC register map */
#include <libstm8/l/itc.h>

/* EXTI register map */
#include <libstm8/l/exti.h>

/* WFE mode register map */
#include <libstm8/l/wfe.h>

/* FLASH register map */
#include <libstm8/l/flash.h>

/* CPU/SWIM/debug module/interrupt controller registers */

/* CPU_* accessible only in debug mode */
#define CPU_A   MMIO8(0x007F00)	/* Accumulator */
#define CPU_PCE MMIO8(0x007F01)	/* Program counter extended */
#define CPU_PCH MMIO8(0x007F02)	/* Program counter high */
#define CPU_PCL MMIO8(0x007F03)	/* Program counter low */
#define CPU_XH  MMIO8(0x007F04)	/* X index register high */
#define CPU_XL  MMIO8(0x007F05)	/* X index register low */
#define CPU_YH  MMIO8(0x007F06)	/* Y index register high */
#define CPU_YL  MMIO8(0x007F07)	/* Y index register low */
#define CPU_SPH MMIO8(0x007F08)	/* Stack pointer high */
#define CPU_SPL MMIO8(0x007F09)	/* Stack pointer low */
#define CPU_CCR MMIO8(0x007F0A)	/* Condition code register */

#define CFG_GCR MMIO8(0x007F60)	/* Global configuration register */

#define SWIM_CSR MMIO8(0x007F80) /* SWIM control status register */

#define DM_BK1RE  MMIO8(0x007F90) /* DM breakpoint 1 register extended byte */
#define DM_BK1RH  MMIO8(0x007F91) /* DM breakpoint 1 register high byte */
#define DM_BK1RL  MMIO8(0x007F92) /* DM breakpoint 1 register low byte */
#define DM_BK2RE  MMIO8(0x007F93) /* DM breakpoint 2 register extended byte */
#define DM_BK2RH  MMIO8(0x007F94) /* DM breakpoint 2 register high byte */
#define DM_BK2RL  MMIO8(0x007F95) /* DM breakpoint 2 register low byte */
#define DM_CR1    MMIO8(0x007F96) /* DM Debug module control register 1 */
#define DM_CR2    MMIO8(0x007F97) /* DM Debug module control register 2 */
#define DM_CSR1   MMIO8(0x007F98) /* DM Debug module control/status register 1 */
#define DM_CSR2   MMIO8(0x007F99) /* DM Debug module control/status register 2 */
#define DM_ENFCTR MMIO8(0x007F9A) /* DM enable function register */

/* Memory readout protection (ROP).
   0xAA: Disable readout protection (write access via SWIM protocol) */
#define OPT_ROP   MMIO8(0x004800)
#define OPT_UBC   MMIO8(0x004802) /* Size of the user boot code area. */
#define OPT_WDG   MMIO8(0x004808) /* Independent watchdog option */
/* Number of stabilization clock cycles for HSE and LSE oscillators */
#define OPT_CLOCK MMIO8(0x004809)
#define OPT_BOR   MMIO8(0x00480A) /* Brownout reset */
#define OPT_BL    MMIO16(0x00480B) /* Bootloader option 2 bytes */
/* option OPT_BL is checked by the boot ROM code after reset. Depending on
   content of addresses 00 480B, 00 480C and 0x8000 (reset vector) the CPU jumps
   to the bootloader or to the reset vector.  Refer to the UM0560 bootloader
   user manual for more details. */

/* is independent watchdog activated by hardware */
#define OPT_IWDG_HW_MASK   (1 << 0)
/* independent window watchdog off on Halt/Active-halt */
#define OPT_IWDG_HALT_MASK (1 << 1)
/* is window watchdog activated by hardware */
#define OPT_WWDG_HW_MASK   (1 << 2)
/* window window watchdog reset on Halt/Active-halt */
#define OPT_WWDG_HALT_MASK (1 << 3)

/* Number of HSE oscillator stabilization clock cycles: 1/16/512/4096 */
#define OPT_CLOCK_HSECNT_MASK (3 << 0)
/* Number of LSE oscillator stabilization clock cycles: 1/16/512/4096 */
#define OPT_CLOCK_LSECNT_MASK (3 << 2)

#define OPT_BOR_ON_MASK (1 << 0) /* is brownout reset on */
#define OPT_BOR_TH_MASK (7 << 1) /* Brownout reset thresholds */

/* UID: 96-bit unique device identifier which provides a reference number that
   is unique for any device and in any context.
   The 96 bits of the identifier can never be altered by the user. */
#define UID_POINTER 0x004926

#endif
