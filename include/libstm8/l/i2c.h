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
#ifndef I2C_H
#define I2C_H

#include <libstm8/common.h>

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

#define I2C_CR1_NOSTRETCH (1 << 7) /* is clock stretching disabled (Slave mode) */
/* General call disbled 0 / enabled 1. Address 0x00 is NACKed 0 /ACKed 1. */
#define I2C_CR1_ENGC	(1 << 6)
#define I2C_CR1_ENPEC	(1 << 5) /* is PEC calculation enabled */
#define I2C_CR1_ENARP	(1 << 4) /* is ARP enabled */
#define I2C_CR1_SMBTYPE	(1 << 3) /* SMBus Device 0 / Host 1 */
#define I2C_CR1_SMBUS	(1 << 1) /* I2C 0 / SMBus 1 mode */
/* Peripheral enable: the corresponding I/Os selected as alternate functions */
#define I2C_CR1_PE	(1 << 0)

#define I2C_CR2_SWRST	(1 << 7) /* When set I2C Peripheral at reset state */
/* SMBus alert
   This bit is set and cleared by software, and cleared by hardware when PE=0.
   0: Releases SMBAlert pin high. Alert Response Address Header followed by NACK.
   1: Drives SMBAlert pin low. Alert Response Address Header followed by ACK.
*/
#define I2C_CR2_ALERT	(1 << 5)
#define I2C_CR2_PEC	(1 << 4) /* PEC  transfer (in Tx or Rx mode) */
/* Bit 3 POS: Acknowledge position (for data reception).
   0: ACK bit controls the (N)ACK of the current byte being received in the
      shift register. The PEC bit indicates the current byte in the
      shift register is PEC.
   1: ACK bit controls the (N)ACK of the next byte which will be received in the
      shift register. The PEC bit indicates the next byte in the
      shift register is PEC.
*/
#define I2C_CR2_POS	(1 << 3)
/* When set acknowledge returned after a byte received (matched address or data) */
#define I2C_CR2_ACK	(1 << 2)
/* Stop generation
   – In Master mode:
   0: No Stop generation.
   1: Stop generation after the current byte transfer or after the current
      Start condition is sent.
   – In Slave mode:
   0: No Stop generation.
   1: Release the SCL and SDA lines after the current byte transfer.
*/
#define I2C_CR2_STOP	(1 << 1)
/* Start generation
   – In Master mode:
   0: No Start generation
   1: Repeated start generation
   – In Slave mode:
   0: No Start generation
   1: Start generation when the bus is free
*/
#define I2C_CR2_START	(1 << 0)

/* Peripheral clock frequency must be programmed to generate correct timings.
   You can set I2C1_FREQR register to values from 1 to 16.
*/

/* 1 least significant bit of I2C_OAR1L in 7 bit addressing mode not used. */
#define I2C_OAR1L_ADD_7_MASK	0xFE

#define I2C_OAR1H_ADDMODE	(1 << 7) /* 0 -- 7 bit, 1 -- 10 bit addr mode */
 /* Address mode configuration. Must be set to '1' by software */
#define I2C_OAR1H_ADDCONF	(1 << 6)
/* Two most significant bits in 10 bit addressing mode */
#define I2C_OAR1H_ADD_SHIFT	1
#define I2C_OAR1H_ADD_MASK	0x3

/* Dual addressing mode enable
   0: Only OAR1 is recognized in 7-bit Addressing mode.
   1: Both OAR1 and OAR2 are recognized in 7-bit Addressing mode.
*/
#define I2C_OAR2_ENDUAL	(1 << 0)
/* I2C_OAR2_ADD2 Bits 7:1 of address in Dual addressing mode. */
#define I2C_OAR2_ADD2_7_MASK	0xFE

/* I2C_DR -- Data register:
   – Transmitter mode: Byte transmission starts automatically when a byte is
     written in the DR register. A continuous transmit stream can be maintained
     if the next data to be transmitted is put in DR once the transmission is
     started (TXE=1)
   – Receiver mode: Received byte is copied into DR (RXNE=1). A continuous
     transmit stream can be maintained if DR is read before the next data is
     received (RXNE=1).
*/

/* Data register empty (transmitters). TXE is not set during address phase. */
#define I2C_SR1_TXE	(1 << 7)
/* Data register not empty (receivers). RXNE is not set during address phase. */
#define I2C_SR1_RXNE	(1 << 6)
#define I2C_SR1_STOPF	(1 << 4) /* Stop condition detected */
/* 10-bit header sent (Master mode).
   Set by hardware when the master has sent the first byte in 10-bit address mode
*/
#define I2C_SR1_ADD10	(1 << 3)
/* Byte transfer finished.
   – Set by hardware when NOSTRETCH=0 and:
     – In reception when a new byte is received (including ACK pulse)
       and DR has not been read yet (RXNE=1).
     – In transmission when a new byte should be sent
       and DR has not been written yet (TXE=1).
*/
#define I2C_SR1_BTF	(1 << 2)
/* Address sent (master mode)/matched (slave mode)
   – Address matched (Slave)
   0: Address mismatched or not received.
   1: Received address matched.
     – Set by hardware as soon as the received slave address matched with the
       OAR registers content or a general call or a SMBus is recognized. (when
       enabled depending on configuration).

   – Address sent (Master)
   0: No end of address transmission
   1: End of address transmission
     – For 10-bit addressing, the bit is set after the ACK of the 2nd byte.
     – For 7-bit addressing, the bit is set after the ACK of the byte.
*/
#define I2C_SR1_ADDR	(1 << 1)
/* Start bit (Master mode). Set when a Start condition generated. */
#define I2C_SR1_SB	(1 << 0)

/* In SMBus host mode:
   0: no SMBAlert
   1: SMBAlert event occurred on pin

   In SMBus slave mode:
   0: no SMBAlert response address header
   1: SMBAlert response address header to SMBAlert LOW received
*/
#define I2C_SR2_SMBALERT (1 << 7)
/* Timeout or Tlow error. Occurres when:
   a. SCL remained low for 25 ms (timeout)
   b. Master cumulative clock low extend time more than 10 ms (Tlow:mext)
   c. Slave cumulative clock low extend time more than 25 ms (Tlow:sext)
*/
#define I2C_SR2_TIMEOUT	(1 << 6)
/* Wakeup from Halt occurres condition:
   7-bit address or header match in Halt mode (slave mode) or Halt entered when
   in master mode.
*/
#define I2C_SR2_WUFH	(1 << 5)
/* PEC Error in reception
   0: no PEC error: receiver returns ACK after PEC reception (if ACK=1)
   1: PEC error: receiver returns NACK after PEC reception (whatever ACK)
*/
#define I2C_SR2_PECERR	(1 << 4)
/* Overrun or underrun. Set by hardware in slave mode when NOSTRETCH=1 and:
   – In reception when a new byte is received (including ACK pulse) and the DR
     register has not been read yet. New received byte is lost.
   – In transmission when a new byte should be sent and the DR register has not
     been written yet. The same byte is sent twice.
*/
#define I2C_SR2_OVR	(1 << 3)
#define I2C_SR2_AF	(1 << 2) /* Set by hardware when no acknowledge returned */
/* Set by hardware when the interface loses the arbitration of the bus
   to another master.
*/
#define I2C_SR2_ARLO	(1 << 1)
/* Misplaced Start or Stop condition.
   Set by hardware when the interface detects a SDA rising or falling edge while
   SCL is high, occuring in a non-valid position during a byte transfer.
*/
#define I2C_SR2_BERR	(1 << 0)

/* Dual flag (Slave mode). Received address matched with OAR1 0 / OAR2 1 */
#define I2C_SR3_DUALF	(1 << 7)
/* Set if SMBus Host address received when SMBTYPE=1 and ENARP=1. */
#define I2C_SR3_SMBHOST	(1 << 6)
/* Set if SMBus Device Default address received when ENARP=1 */
#define I2C_SR3_SMBDEFAULT (1 << 5)
#define I2C_SR3_GENCALL	(1 << 4) /* General call header received when ENGC=1 */
#define I2C_SR3_TRA	(1 << 2) /* Data bytes received 0/transmitted 1 */
/* Communication ongoing on the bus. Set on detection of SDA or SCL low */
#define I2C_SR3_BUSY	(1 << 1)
/* Set by hardware as soon as the interface is in Master mode (SB=1). */
#define I2C_SR3_MSL	(1 << 0)
/* I2C_SR3 must be read only when ADDR is found set in I2C_SR1 or when the STOPF
   bit is cleared.
*/

#define I2C_ITR_LAST	(1 << 4) /* 1: Next DMA EOT is the last transfer */
#define I2C_ITR_DMAEN	(1 << 3) /* 1: DMA request enabled when TXE=1 or RXNE =1 */
/* Buffer interrupt enable.
   0: TXE = 1 or RXNE = 1 does not generate any interrupt.
   1: TXE = 1 or RXNE = 1 generates Event interrupt.
*/
#define I2C_ITR_ITBUFEN	(1 << 2)
/* Event interrupt enable. This interrupt is generated when:
   – SB    = 1 (Master)
   – ADDR  = 1 (Master/Slave)
   – ADD10 = 1 (Master)
   – STOPF = 1 (Slave)
   – BTF   = 1 with no TXE or RXNE event
   – TXE  event to 1 if ITBUFEN = 1
   – RXNE event to 1 if ITBUFEN = 1
   – WUFH = 1 (asynchronous interrupt to wakeup from Halt)
*/
#define I2C_ITR_ITEVTEN	(1 << 1)
/* Error interrupt enable. This interrupt is generated when:
   – BERR = 1
   – ARLO = 1
   – AF = 1
   – OVR = 1
   – PECERR = 1
   – TIMEOUT = 1
   – SMBALERT = 1
*/
#define I2C_ITR_ITERREN	(1 << 0)

/* I2C_CCR[11:0]=I2C_CCRH[3:0]:I2C_CCRL[7:0] Clock control register (Master mode)
   Controls the SCLH clock in Master mode.
   – Standard mode or SMBus:
     Period(I2C) = 2 * CCR * t_MASTER
     t_high = CCR * t_MASTER
     t_low = CCR * t_MASTER
   – Fast_mode:
     If DUTY = 0:
       Period(I2C) = 3* CCR * t_MASTER
       t_high = CCR * t_MASTER
       t_low = 2 * CCR * t_MASTER
     If DUTY = 1: (to reach 400 kHz)
       Period(I2C) = 25 * CCR * t_MASTER
       t_high = 9 * CCR * t_MASTER
       t_low = 16 * CCR * t_MASTER
*/
#define I2C_CCRH_CCR_SHIFT 0
#define I2C_CCRH_CCR_MASK  0xF
#define I2C_CCRH_FS	(1 << 7) /* Standard[0]/master[1] mode I2C */
#define I2C_CCRH_DUTY	(1 << 6) /* Fast mode t_low/t_high = 2[0] | 16/9[1] */

/* Maximum rise time in Fast/Standard mode (Master mode).
   These bits must be programmed with the maximum SCL rise time given in the I2C
   bus specification, incremented by 1.
*/
#define I2C_TRISER_MASK	0x3F

/* I2C_PECR -- Packet error checking register.
   This register contains the internal PEC when ENPEC=1. */

#endif
