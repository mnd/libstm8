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
#ifndef SPI_H
#define SPI_H

#include <libstm8/common.h>

#define SPI1_CR1    MMIO8(0x005200)	/* SPI1 control register 1 */
#define SPI1_CR2    MMIO8(0x005201)	/* SPI1 control register 2 */
#define SPI1_ICR    MMIO8(0x005202)	/* SPI1 interrupt control register */
#define SPI1_SR     MMIO8(0x005203)	/* SPI1 status register */
#define SPI1_DR     MMIO8(0x005204)	/* SPI1 data register */
#define SPI1_CRCPR  MMIO8(0x005205)	/* SPI1 CRC polynomial register */
#define SPI1_RXCRCR MMIO8(0x005206)	/* SPI1 Rx CRC register */
#define SPI1_TXCRCR MMIO8(0x005207)	/* SPI1 Tx CRC register */

#define SPI_CR1_LSBFIRST (1 << 7) /* MSB[0]/LSB[1] is transmitted first */
#define SPI_CR1_SPE	(1 << 6)  /* SPI enable */
#define SPI_CR1_MSTR	(1 << 2)  /* Slave[0]/Master[1] configuration */
#define SPI_CR1_CPOL	(1 << 1)  /* SCK to 0[0]/1[1] when idle */
/* 0: The first clock transition is the first data capture edge
   1: The second clock transition is the first data capture edge
*/
#define SPI_CR1_CPHA	(1 << 0)
/* Baud rate control */
#define SPI_CR1_BR_SHIFT 3
#define SPI_CR1_BR_MASK	0x7
#define SPI_CR1_BR_2	0x0
#define SPI_CR1_BR_4	0x0
#define SPI_CR1_BR_8	0x0
#define SPI_CR1_BR_16	0x0
#define SPI_CR1_BR_32	0x0	/* f_SYSCLK / 64 */
#define SPI_CR1_BR_64	0x0
#define SPI_CR1_BR_128	0x0
#define SPI_CR1_BR_256	0x0

/* 0: 2-line unidirectional data mode selected
   1: 1-line bidirectional data mode selected
*/
#define SPI_CR2_BDM	(1 << 7)
#define SPI_CR2_BDOE	(1 << 6) /* Input[0]/Output[1] only mode when BDM = 1 */
#define SPI_CR2_CRCEN	(1 << 5) /* Hardware CRC calculation enable */
/* Next transmit value is from Tx buffer [0] / Tx CRC register [1] */
#define SPI_CR2_CRCNEXT	(1 << 4)
#define SPI_CR2_RXONLY	(1 << 2) /* Full duplex [0] / Output disabled [1] */
#define SPI_CR2_SSM	(1 << 1) /* Is software slave management enabled */
#define SPI_CR2_SSI	(1 << 0) /* Slave [0] / Master [1] mode. */

#define SPI_ICR_TXIE	(1 << 7) /* TXE interrupt masked [0] / not masked [1] */
#define SPI_ICR_RXIE	(1 << 6) /* RXNE interrupt masked [0] / not masked [1] */
/* Error interrupt is masked[0] / enabled [1]. Error occurs if (CRCERR|OVR|MODF) */
#define SPI_ICR_ERRIE	(1 << 5)
#define SPI_ICR_WKIE	(1 << 4) /* wakeup interrupt masked [0] / enabled [1] */
#define SPI_ICR_TXDMAEN	(1 << 1) /* Tx buffer DMA disabled [0] / enabled [1] */
#define SPI_ICR_RXDMAEN	(1 << 0) /* Rx buffer DMA disabled [0] / enabled [1] */

#define SPI_SR_BSY	(1 << 7) /* is SPI is busy in communication */
#define SPI_SR_OVR	(1 << 6) /* is Overrun occurred */
#define SPI_SR_MODF	(1 << 5) /* is Mode fault occurred */
/* CRC value received match [0] / does not match [1] the SPI_RXCRCR value */
#define SPI_SR_CRCERR	(1 << 4)
#define SPI_SR_WKUP	(1 << 3) /* is Wakeup event occurred */
#define SPI_SR_TXE	(1 << 1) /* is Tx buffer empty */
#define SPI_SR_RXNE	(1 << 0) /* is Rx buffer not empty */

/* SPI_DR -- data register. Writes to TX buffer, reads from RX buffer */
/* SPI_CRCPR -- CRC polynomial register. 
   Contain polynomial (default: 0x7) for CRC calculation.
*/
/* SPI_RXCRCR -- Rx CRC Register.
   Contain the computed CRC value of the subsequently received bytes.
*/
/* SPI_TXCRCR -- Tx CRC register.
   Contain the computed CRC value of the subsequently transmitted bytes.
*/
#endif
