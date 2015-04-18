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
#ifndef USART_H
#define USART_H

#include <libstm8/common.h>

#define USART1	0x005230	/* base adress */
#define USART2	0x0053E0	/* on high density devices */
#define USART3	0x0053F0
#define USART_SR(base)   MMIO8(base + 0x0)   /* USART1 status register */
#define USART_DR(base)   MMIO8(base + 0x1)   /* USART1 data register */
#define USART_BRR1(base) MMIO8(base + 0x2)   /* USART1 baud rate register 1 */
#define USART_BRR2(base) MMIO8(base + 0x3)   /* USART1 baud rate register 2 */
#define USART_CR1(base)  MMIO8(base + 0x4)   /* USART1 control register 1 */
#define USART_CR2(base)  MMIO8(base + 0x5)   /* USART1 control register 2 */
#define USART_CR3(base)  MMIO8(base + 0x6)   /* USART1 control register 3 */
#define USART_CR4(base)  MMIO8(base + 0x7)   /* USART1 control register 4 */
#define USART_CR5(base)  MMIO8(base + 0x8)   /* USART1 control register 5 */
#define USART_GTR(base)  MMIO8(base + 0x9)   /* USART1 guard time register */
#define USART_PSCR(base) MMIO8(base + 0xA)   /* USART1 prescaler register */

#define USART1_SR USART_SR(USART1)
#define USART1_DR USART_DR(USART1)
#define USART1_BRR1 USART_BRR1(USART1)
#define USART1_BRR2 USART_BRR2(USART1)
#define USART1_CR1 USART_CR1(USART1)
#define USART1_CR2 USART_CR2(USART1)
#define USART1_CR3 USART_CR3(USART1)
#define USART1_CR4 USART_CR4(USART1)
#define USART1_CR5 USART_CR5(USART1)
#define USART1_GTR USART_GTR(USART1)
#define USART1_PSCR USART_PSCR(USART1)

#define USART2_SR USART_SR(USART2)
#define USART2_DR USART_DR(USART2)
#define USART2_BRR1 USART_BRR1(USART2)
#define USART2_BRR2 USART_BRR2(USART2)
#define USART2_CR1 USART_CR1(USART2)
#define USART2_CR2 USART_CR2(USART2)
#define USART2_CR3 USART_CR3(USART2)
#define USART2_CR4 USART_CR4(USART2)
#define USART2_CR5 USART_CR5(USART2)
#define USART2_GTR USART_GTR(USART2)
#define USART2_PSCR USART_PSCR(USART2)

#define USART3_SR USART_SR(USART3)
#define USART3_DR USART_DR(USART3)
#define USART3_BRR1 USART_BRR1(USART3)
#define USART3_BRR2 USART_BRR2(USART3)
#define USART3_CR1 USART_CR1(USART3)
#define USART3_CR2 USART_CR2(USART3)
#define USART3_CR3 USART_CR3(USART3)
#define USART3_CR4 USART_CR4(USART3)
#define USART3_CR5 USART_CR5(USART3)
#define USART3_GTR USART_GTR(USART3)
#define USART3_PSCR USART_PSCR(USART3)

/* Status register */
#define USART_SR_TXE  (1 << 7) /* is USART1_DR transferred to the shift register */
#define USART_SR_TC   (1 << 6) /* transmission complite */
#define USART_SR_RXNE (1 << 5) /* is received data ready to be read (USART1_DR) */
#define USART_SR_IDLE (1 << 4) /* is Idle Line detected */
#define USART_SR_OR   (1 << 3) /* is overrun error detected */
#define USART_SR_NF   (1 << 2) /* is noise detected */
#define USART_SR_FE   (1 << 1) /* is framing error or break character detected */
#define USART_SR_PE   (1 << 0) /* is parity error detected */

/* Data register */
/* USART1_DR[0:7] Contains the received or transmitted data character, depending
   on whether it is read from or written to. */

/* Baud rate register */
/* USART1_BRR1[0:7] is '21' nibbles in '3210' value for USART_DIV */
/* USART1_BRR2[0:3] is '0' nibble; USART1_BRR2[4:7] is '3' nibble */
/* USART baud rate = System clock / USART_DIV. See page 515 in 
   http://www.st.com/web/en/resource/technical/document/reference_manual/CD00218714.pdf */

/* Control register 1 */
#define USART_CR1_R8 (1 << 7) /* used to store the 9th bit of received when M=1 */
#define USART_CR1_T8 (1 << 6) /* ..to store the 9th bit of transmitted when M=1 */
#define USART_CR1_USARTD (1 << 5) /* USART disable (for low power consumption) */
#define USART_CR1_M    (1 << 4)	 /* This bit determines the word length. */
#define USART_CR1_WAKE (1 << 3)	 /* Idle line/address mark wakeup method */
#define USART_CR1_PCEN (1 << 2)	 /* Parity control enable */
#define USART_CR1_PS   (1 << 1)	 /* Even/Odd parity */
#define USART_CR1_PIEN (1 << 0)	 /* Parity error interrupt enable (PE) */

/* Control register 2 */
#define USART_CR2_TIEN  (1 << 7) /* Transmitter interrupt enable (TXE) */
#define USART_CR2_TCIEN (1 << 6) /* Transmission complete interrupt enable (TC) */
#define USART_CR2_RIEN  (1 << 5) /* Receiver interrupt enable (OR || RXNE) */
#define USART_CR2_ILIEN (1 << 4) /* IDLE Line interrupt enable (IDLE) */
#define USART_CR2_TEN   (1 << 3) /* This bit enables the transmitter. */
#define USART_CR2_REN   (1 << 2) /* This bit enables the receiver. */
#define USART_CR2_RWU   (1 << 1) /* Reviever in mute/active mode */
#define USART_CR2_SBK   (1 << 0) /* Set bit to send break characters */

/* Control register 3 */
#define USART_CR3_STOP_SHIFT 0x4
#define USART_CR3_STOP_MASK  0x3
#define USART_CR3_STOP_1 0x0	/* 1 STOP bit */
#define USART_CR3_STOP_2 0x2	/* 2 STOP bits */
#define USART_CR3_STOP_1_5 0x3	/* 1.5 STOP bits */

#define USART_CR3_CLKEN (1 << 3) /* This bit allow to enable the USART_CK pin. */
#define USART_CR3_CPOL  (1 << 2) /* Polarity. USART_CK to 0/1 when idle. */
#define USART_CR3_CPHA  (1 << 1) /* allows to select the phase of the clock output on the USART_CK pin*/
#define USART_CR3_LBCL  (1 << 0) /* is the clock pulse of the last data bit output to the USART_CK pin. */

/* Control register 4 */
/* Address of the USART node.  This bit-field gives the address of the USART
node.  This is used in multiprocessor communication during mute mode, for wakeup
with address mark detection. */
#define USART_CR4_ADD_SHIFT 0x0
#define USART_CR4_ADD_MASK  0xF

/* Control register 5 */
#define USART_CR5_DMAT  (1 << 7)	/* DMA Enable transmitter. */
#define USART_CR5_DMAR  (1 << 6)	/* DMA Enable receiver. */
#define USART_CR5_SCEN  (1 << 5)	/* Smartcard mode enable. */
#define USART_CR5_NACK  (1 << 4)	/* Smartcard NACK enable. */
#define USART_CR5_HDSEL (1 << 3)	/* Half duplex selection. */
#define USART_CR5_IRLP  (1 << 2)	/* IrDA Low power. */
#define USART_CR5_IREN  (1 << 1)	/* IrDA mode enable. */
#define USART_CR5_EIE   (1 << 0)	/* Error Interrupt enable. ((FE||OR||NF)&&DMAR) */

/* Guard time register */
/* USART1_GTR[0:7] gives the Guard time value in terms of number of baud clocks.
   This is used in Smartcard mode. The Transmission Complete flag is set after
   this guard time value. */

/* Prescaler register */
/* USART1_PSCR[0:7] used to set prescaler for system clock in IrDA and smartcard
   modes */

/* stopbits variable */
enum usart_stopbits {
  USART_STOPBITS_MASK = (USART_CR3_STOP_MASK << USART_CR3_STOP_SHIFT),
  USART_STOPBITS_1 = (USART_CR3_STOP_1 << USART_CR3_STOP_SHIFT),
  USART_STOPBITS_2 = (USART_CR3_STOP_2 << USART_CR3_STOP_SHIFT),
  USART_STOPBITS_1_5 = (USART_CR3_STOP_1_5 << USART_CR3_STOP_SHIFT)
};
/* parity variable*/
enum usart_parity {
  USART_PARITY_MASK = (USART_CR1_PCEN | USART_CR1_PS),
  USART_PARITY_NONE = 0x0,
  USART_PARITY_EVEN = USART_CR1_PCEN,
  USART_PARITY_ODD  = (USART_CR1_PCEN | USART_CR1_PS)
};
/* mode variable */
enum usart_mode {
  USART_MODE_MASK  = (USART_CR2_TEN | USART_CR2_REN), /* TX or RT mode */
  USART_MODE_RX    = USART_CR2_REN,
  USART_MODE_TX    = USART_CR2_TEN,
  USART_MODE_TX_RX = (USART_CR2_TEN | USART_CR2_REN)
};

/* function prototypes */
void usart_set_baudrate (uint16_t usart, uint32_t baud);
void usart_set_databits (uint16_t usart, uint8_t bits);
void usart_set_stopbits (uint16_t usart, enum usart_stopbits stopbits);
void usart_set_parity (uint16_t usart, enum usart_parity parity);
void usart_enable_mode (uint16_t usart, enum usart_mode mode);
void usart_wait_send_ready (uint16_t usart);
void usart_send (uint16_t usart, uint8_t byte);
void usart_send_blocking (uint16_t usart, uint8_t byte);
void usart_wait_recv_ready (uint16_t usart);
uint8_t usart_recv (uint16_t usart);
uint8_t usart_recv_blocking (uint16_t usart);

void usart_enable_tx_dma (uint16_t usart);
void usart_enable_rx_dma (uint16_t usart);
void usart_disable_tx_dma (uint16_t usart);
void usart_disable_rx_dma (uint16_t usart);
#endif
