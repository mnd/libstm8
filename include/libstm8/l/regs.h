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

/* IWDG register map */
#include <libstm8/l/iwdg.h>

/* WWDG register map */
#include <libstm8/l/wwdg.h>

/* General hardware register map */

#define FLASH_CR1   MMIO8(0x005050)	/* Flash control register 1 */
#define FLASH_CR2   MMIO8(0x005051)	/* Flash control register 2 */
#define FLASH_PUKR  MMIO8(0x005052)	/* Flash program memory unprotection key register */
#define FLASH_DUKR  MMIO8(0x005053)	/* Data EEPROM unprotection key register */
#define FLASH_IAPSR MMIO8(0x005054)	/* Flash in-application programming status register */

#define EXTI_CR1   MMIO8(0x0050A0)	/* External interrupt control register 1 */
#define EXTI_CR2   MMIO8(0x0050A1)	/* External interrupt control register 2 */
#define EXTI_CR3   MMIO8(0x0050A2)	/* External interrupt control register 3 */
#define EXTI_SR1   MMIO8(0x0050A3)	/* External interrupt status register 1 */
#define EXTI_SR2   MMIO8(0x0050A4)	/* External interrupt status register 2 */
#define EXTI_CONF1 MMIO8(0x0050A5)	/* External interrupt port select register 1 */

#define WFE_CR1 MMIO8(0x0050A6)	/* WFE control register 1 */
#define WFE_CR2 MMIO8(0x0050A7)	/* WFE control register 2 */
#define WFE_CR3 MMIO8(0x0050A8)	/* WFE control register 3 */

#define RTC_TR1 MMIO8(0x005140)	/* Time register 1 */
#define RTC_TR2 MMIO8(0x005141)	/* Time register 2 */
#define RTC_TR3 MMIO8(0x005142)	/* Time register 3 */

#define RTC_DR1 MMIO8(0x005144)	/* Date register 1 */
#define RTC_DR2 MMIO8(0x005145)	/* Date register 2 */
#define RTC_DR3 MMIO8(0x005146)	/* Date register 3 */

#define RTC_CR1 MMIO8(0x005148)	/* Control register 1 */
#define RTC_CR2 MMIO8(0x005149)	/* Control register 2 */
#define RTC_CR3 MMIO8(0x00514A)	/* Control register 3 */

#define RTC_ISR1 MMIO8(0x00514C)	/* Initialization and status register 1 */
#define RTC_ISR2 MMIO8(0x00514D)	/* Initialization and status register 2 */

/* Next 5 registers are not impacted by a system reset. They are reset at power-on. */
#define RTC_SPRERH MMIO8(0x005150)	/* Synchronous prescaler register high */
#define RTC_SPRERL MMIO8(0x005151)	/* Synchronous prescaler register low */
#define RTC_APRER  MMIO8(0x005152)	/* Asynchronous prescaler register */
#define RTC_WUTRH  MMIO8(0x005154)	/* Wakeup timer register high */
#define RTC_WUTRL  MMIO8(0x005155)	/* Wakeup timer register low */

#define RTC_WPR MMIO8(0x005159)	/* Write protection register */

#define RTC_ALRMAR1 MMIO8(0x00515C)	/* Alarm A register 1 */
#define RTC_ALRMAR2 MMIO8(0x00515D)	/* Alarm A register 2 */
#define RTC_ALRMAR3 MMIO8(0x00515E)	/* Alarm A register 3 */
#define RTC_ALRMAR4 MMIO8(0x00515F)	/* Alarm A register 4 */

#define SPI1_CR1    MMIO8(0x005200)	/* SPI1 control register 1 */
#define SPI1_CR2    MMIO8(0x005201)	/* SPI1 control register 2 */
#define SPI1_ICR    MMIO8(0x005202)	/* SPI1 interrupt control register */
#define SPI1_SR     MMIO8(0x005203)	/* SPI1 status register */
#define SPI1_DR     MMIO8(0x005204)	/* SPI1 data register */
#define SPI1_CRCPR  MMIO8(0x005205)	/* SPI1 CRC polynomial register */
#define SPI1_RXCRCR MMIO8(0x005206)	/* SPI1 Rx CRC register */
#define SPI1_TXCRCR MMIO8(0x005207)	/* SPI1 Tx CRC register */

#define I2C1_CR1    MMIO8(0x005210)	/* I2C1 control register 1 */
#define I2C1_CR2    MMIO8(0x005211)	/* I2C1 control register 2 */
#define I2C1_FREQR  MMIO8(0x005212)	/* I2C1 frequency register */
#define I2C1_OARL   MMIO8(0x005213)	/* I2C1 own address register low */
#define I2C1_OARH   MMIO8(0x005214)	/* I2C1 own address register high */
#define I2C1_DR     MMIO8(0x005216)	/* I2C1 data register */
#define I2C1_SR1    MMIO8(0x005217)	/* I2C1 status register 1 */
#define I2C1_SR2    MMIO8(0x005218)	/* I2C1 status register 2 */
#define I2C1_SR3    MMIO8(0x005219)	/* I2C1 status register 3 */
#define I2C1_ITR    MMIO8(0x00521A)	/* I2C1 interrupt control register */
#define I2C1_CCRL   MMIO8(0x00521B)	/* I2C1 clock control register low */
#define I2C1_CCRH   MMIO8(0x00521C)	/* I2C1 clock control register high */
#define I2C1_TRISER MMIO8(0x00521D)	/* I2C1 TRISE register */
#define I2C1_PECR   MMIO8(0x00521E)	/* I2C1 packet error checking register */

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

#define ITC_SPR1 MMIO8(0x007F70)	/* Interrupt Software priority register 1 */
#define ITC_SPR2 MMIO8(0x007F71)	/* Interrupt Software priority register 2 */
#define ITC_SPR3 MMIO8(0x007F72)	/* Interrupt Software priority register 3 */
#define ITC_SPR4 MMIO8(0x007F73)	/* Interrupt Software priority register 4 */
#define ITC_SPR5 MMIO8(0x007F74)	/* Interrupt Software priority register 5 */
#define ITC_SPR6 MMIO8(0x007F75)	/* Interrupt Software priority register 6 */
#define ITC_SPR7 MMIO8(0x007F76)	/* Interrupt Software priority register 7 */
#define ITC_SPR8 MMIO8(0x007F77)	/* Interrupt Software priority register 8 */

#define SWIM_CSR MMIO8(0x007F80)	/* SWIM control status register */

#define DM_BK1RE  MMIO8(0x007F90)	/* DM breakpoint 1 register extended byte */
#define DM_BK1RH  MMIO8(0x007F91)	/* DM breakpoint 1 register high byte */
#define DM_BK1RL  MMIO8(0x007F92)	/* DM breakpoint 1 register low byte */
#define DM_BK2RE  MMIO8(0x007F93)	/* DM breakpoint 2 register extended byte */
#define DM_BK2RH  MMIO8(0x007F94)	/* DM breakpoint 2 register high byte */
#define DM_BK2RL  MMIO8(0x007F95)	/* DM breakpoint 2 register low byte */
#define DM_CR1    MMIO8(0x007F96)	/* DM Debug module control register 1 */
#define DM_CR2    MMIO8(0x007F97)	/* DM Debug module control register 2 */
#define DM_CSR1   MMIO8(0x007F98)	/* DM Debug module control/status register 1 */
#define DM_CSR2   MMIO8(0x007F99)	/* DM Debug module control/status register 2 */
#define DM_ENFCTR MMIO8(0x007F9A)	/* DM enable function register */

#define OPT_ROP   MMIO8(0x004800)	/* Memory readout protection (ROP). 0xAA: Disable readout protection (write access via SWIM protocol) */
#define OPT_UBC   MMIO8(0x004802)	/* Size of the user boot code area. */
#define OPT_WDG   MMIO8(0x004808)	/* Independent watchdog option */
#define OPT_CLOCK MMIO8(0x004809)	/* Number of stabilization clock cycles for HSE and LSE oscillators */
#define OPT_BOR   MMIO8(0x00480A)	/* Brownout reset */
#define OPT_BL    MMIO16(0x00480B)	/* Bootloader option 2 bytes */
/* option OPT_BL is checked by the boot ROM code after reset. Depending on content
of addresses 00 480B, 00 480C and 0x8000 (reset vector) the CPU jumps to the
bootloader or to the reset vector.  Refer to the UM0560 bootloader user manual
for more details. */

#define OPT_IWDG_HW_MASK   (1 << 0) /* is independent watchdog activated by hardware */
#define OPT_IWDG_HALT_MASK (1 << 1) /* independent window watchdog off on Halt/Active-halt */
#define OPT_WWDG_HW_MASK   (1 << 2) /* is window watchdog activated by hardware  */
#define OPT_WWDG_HALT_MASK (1 << 3) /* window window watchdog reset on Halt/Active-halt */

#define OPT_CLOCK_HSECNT_MASK (3 << 0) /* Number of HSE oscillator stabilization clock cycles: 1/16/512/4096 */
#define OPT_CLOCK_LSECNT_MASK (3 << 2) /* Number of LSE oscillator stabilization clock cycles: 1/16/512/4096 */

#define OPT_BOR_ON_MASK (1 << 0) /* is brownout reset on */
#define OPT_BOR_TH_MASK (7 << 1) /* Brownout reset thresholds */

#define UID_POINTER 0x004926	/* 96-bit unique device identifier which provides a reference number that is unique for any device and in any context.
				   The 96 bits of the identifier can never be altered by the user. */

#endif
