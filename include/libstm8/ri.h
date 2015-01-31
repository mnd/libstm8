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
#ifndef RI_H
#define RI_H

#include <libstm8/common.h>

#define RI_BASE   0x005430
#define RI_ICR1   MMIO8(RI_BASE + 0x1)	/* Timer input capture routing register 1 */
#define RI_ICR2   MMIO8(RI_BASE + 0x2)	/* Timer input capture routing register 2 */
#define RI_IOIR1  MMIO8(RI_BASE + 0x3)	/* I/O input register 1 */
#define RI_IOIR2  MMIO8(RI_BASE + 0x4)	/* I/O input register 2 */
#define RI_IOIR3  MMIO8(RI_BASE + 0x5)	/* I/O input register 3 */
#define RI_IOCMR1 MMIO8(RI_BASE + 0x6)	/* I/O control mode register 1 */
#define RI_IOCMR2 MMIO8(RI_BASE + 0x7)	/* I/O control mode register 2 */
#define RI_IOCMR3 MMIO8(RI_BASE + 0x8)	/* I/O control mode register 3 */
#define RI_IOSR1  MMIO8(RI_BASE + 0x9)	/* I/O switch register 1 */
#define RI_IOSR2  MMIO8(RI_BASE + 0xA)	/* I/O switch register 2 */
#define RI_IOSR3  MMIO8(RI_BASE + 0xB)	/* I/O switch register 3 */
#define RI_IOGCR  MMIO8(RI_BASE + 0xC)	/* I/O group control register */
#define RI_ASCR1  MMIO8(RI_BASE + 0xD)	/* Analog switch register 1 */
#define RI_ASCR2  MMIO8(RI_BASE + 0xE)	/* Analog switch register 2 */
#define RI_RCR    MMIO8(RI_BASE + 0xF)	/* Resistor control register 1 */
/* next regs on low density devices only */
#define RI_CR     MMIO8(RI_BASE + 0x20)
#define RI_IOMR1  MMIO8(RI_BASE + 0x21)
#define RI_IOMR2  MMIO8(RI_BASE + 0x22)
#define RI_IOMR3  MMIO8(RI_BASE + 0x23)
#define RI_IOMR4  MMIO8(RI_BASE + 0x24)
#define RI_IOIR4  MMIO8(RI_BASE + 0x25)
#define RI_IOCMR4 MMIO8(RI_BASE + 0x26)
#define RI_IOSR4  MMIO8(RI_BASE + 0x27)

/* TIM1 Input Capture 2 I/O selection */
#define RI_ICR1_IC2CS_MASK	0x1F
#define RI_ICR1_IC2CS_SHIFT	0
#define RI_ICR1_IC2CS_PD4	0x0
#define RI_ICR1_IC2CS_PF0	0x1
#define RI_ICR1_IC2CS_PF2	0x2
#define RI_ICR1_IC2CS_PE0	0x3
#define RI_ICR1_IC2CS_PE2	0x4
#define RI_ICR1_IC2CS_PE4	0x5
#define RI_ICR1_IC2CS_PE6	0x6
#define RI_ICR1_IC2CS_PD0	0x7
#define RI_ICR1_IC2CS_PD2	0x8
#define RI_ICR1_IC2CS_PD4_1	0x9 /* redefined default routing */
#define RI_ICR1_IC2CS_PD6	0xA
#define RI_ICR1_IC2CS_PC0	0xB
#define RI_ICR1_IC2CS_PC2	0xC
#define RI_ICR1_IC2CS_PC4	0xD
#define RI_ICR1_IC2CS_PC6	0xE
#define RI_ICR1_IC2CS_PB0	0xF
#define RI_ICR1_IC2CS_PB2	0x10
#define RI_ICR1_IC2CS_PB4	0x11
#define RI_ICR1_IC2CS_PB6	0x12
#define RI_ICR1_IC2CS_PA0	0x13
#define RI_ICR1_IC2CS_PA3	0x14
#define RI_ICR1_IC2CS_PA5	0x15
#define RI_ICR1_IC2CS_PA7	0x16
/* TIM1 Input Capture 3 I/O selection */
#define RI_ICR2_IC3CS_MASK	0x1F
#define RI_ICR2_IC3CS_SHIFT	0
#define RI_ICR2_IC3CS_PD5	0x0
#define RI_ICR2_IC3CS_PF1	0x1
#define RI_ICR2_IC3CS_PF3	0x2
#define RI_ICR2_IC3CS_PE1	0x3
#define RI_ICR2_IC3CS_PE3	0x4
#define RI_ICR2_IC3CS_PE5	0x5
#define RI_ICR2_IC3CS_PE7	0x6
#define RI_ICR2_IC3CS_PD1	0x7
#define RI_ICR2_IC3CS_PD3	0x8
#define RI_ICR2_IC3CS_PD5_1	0x9 /* redefined default routing */
#define RI_ICR2_IC3CS_PD7	0xA
#define RI_ICR2_IC3CS_PC1	0xB
#define RI_ICR2_IC3CS_PC3	0xC
#define RI_ICR2_IC3CS_PC5	0xD
#define RI_ICR2_IC3CS_PC7	0xE
#define RI_ICR2_IC3CS_PB1	0xF
#define RI_ICR2_IC3CS_PB3	0x10
#define RI_ICR2_IC3CS_PB5	0x11
#define RI_ICR2_IC3CS_PB7	0x12
#define RI_ICR2_IC3CS_PA2	0x13
#define RI_ICR2_IC3CS_PA4	0x14
#define RI_ICR2_IC3CS_PA6	0x15

/* These bits return the corresponding I/O pin value irrespective of the port
   configuration (similar to the Px_IDR register). This register is
   read-only. */
#define RI_IOIR1_CH22I	(1 << 7)
#define RI_IOIR1_CH19I	(1 << 6)
#define RI_IOIR1_CH16I	(1 << 5)
#define RI_IOIR1_CH13I	(1 << 4)
#define RI_IOIR1_CH10I	(1 << 3)
#define RI_IOIR1_CH7I	(1 << 2)
#define RI_IOIR1_CH4I	(1 << 1)
#define RI_IOIR1_CH1I	(1 << 0)

#define RI_IOIR2_CH23I	(1 << 7)
#define RI_IOIR2_CH20I	(1 << 6)
#define RI_IOIR2_CH17I	(1 << 5)
#define RI_IOIR2_CH14I	(1 << 4)
#define RI_IOIR2_CH11I	(1 << 3)
#define RI_IOIR2_CH8I	(1 << 2)
#define RI_IOIR2_CH5I	(1 << 1)
#define RI_IOIR2_CH2I	(1 << 0)

#define RI_IOIR3_CH24I	(1 << 7)
#define RI_IOIR3_CH21I	(1 << 6)
#define RI_IOIR3_CH18I	(1 << 5)
#define RI_IOIR3_CH15I	(1 << 4)
#define RI_IOIR3_CH12I	(1 << 3)
#define RI_IOIR3_CH9I	(1 << 2)
#define RI_IOIR3_CH6I	(1 << 1)
#define RI_IOIR3_CH3I	(1 << 0)

#define RI_IOIR4_CH28I	(1 << 7)
#define RI_IOIR4_CH27I	(1 << 6)
#define RI_IOIR4_CH26I	(1 << 1)
#define RI_IOIR4_CH29I	(1 << 0)

/* 0: I/O x is controlled by the standard GPIO registers. The I/O x switch is
   directly controlled by the RI_IOSRx register.

   1: I/O x is set to protected mode and is only controlled by the RI_IOSRx and
   RI_IOGCR registers (standard GPIO registers have no effect on the
   configuration of I/O x).
*/
#define RI_IOCMR1_CH22M	(1 << 7)
#define RI_IOCMR1_CH19M	(1 << 6)
#define RI_IOCMR1_CH16M	(1 << 5)
#define RI_IOCMR1_CH13M	(1 << 4)
#define RI_IOCMR1_CH10M	(1 << 3)
#define RI_IOCMR1_CH7M	(1 << 2)
#define RI_IOCMR1_CH4M	(1 << 1)
#define RI_IOCMR1_CH1M	(1 << 0)

#define RI_IOCMR2_CH23M	(1 << 7)
#define RI_IOCMR2_CH20M	(1 << 6)
#define RI_IOCMR2_CH17M	(1 << 5)
#define RI_IOCMR2_CH14M	(1 << 4)
#define RI_IOCMR2_CH11M	(1 << 3)
#define RI_IOCMR2_CH8M	(1 << 2)
#define RI_IOCMR2_CH5M	(1 << 1)
#define RI_IOCMR2_CH2M	(1 << 0)

#define RI_IOCMR3_CH24M	(1 << 7)
#define RI_IOCMR3_CH21M	(1 << 6)
#define RI_IOCMR3_CH18M	(1 << 5)
#define RI_IOCMR3_CH15M	(1 << 4)
#define RI_IOCMR3_CH12M	(1 << 3)
#define RI_IOCMR3_CH9M	(1 << 2)
#define RI_IOCMR3_CH6M	(1 << 1)
#define RI_IOCMR3_CH3M	(1 << 0)

#define RI_IOCMR4_CH28M	(1 << 7)
#define RI_IOCMR4_CH27M	(1 << 6)
#define RI_IOCMR4_CH26M	(1 << 1)
#define RI_IOCMR4_CH29M	(1 << 0)


/* If the corresponding RI_IOCMRx bit is cleared:
   0: I/O x switch is open (I/O x is controlled by the GPIO registers or ADC1).
   1: I/O x switch is closed (analog channel enabled).

   If the corresponding RI_IOCMRx bit is set and the AM bit is cleared in the
   RI_CR register (software management of the charge transfer acquisition
   sequence):
   0: I/O x is forced to output push-pull low mode.
   1: I/O x configuration is determined by bit 0 and bit 1 in the RI_IOGCR register.

   If the corresponding RI_IOCMRx bit is set and the AM bit is also set in the
   RI_CR register (hardware management of the charge transfer acquisition
   sequence):
   0: I/O x is forced to output push-pull low mode
   1: I/O x configuration is determined by the timer TIM2
*/
#define RI_IOSR1_CH22E	(1 << 7)
#define RI_IOSR1_CH19E	(1 << 6)
#define RI_IOSR1_CH16E	(1 << 5)
#define RI_IOSR1_CH13E	(1 << 4)
#define RI_IOSR1_CH10E	(1 << 3)
#define RI_IOSR1_CH7E	(1 << 2)
#define RI_IOSR1_CH4E	(1 << 1)
#define RI_IOSR1_CH1E	(1 << 0)

#define RI_IOSR2_CH23E	(1 << 7)
#define RI_IOSR2_CH20E	(1 << 6)
#define RI_IOSR2_CH17E	(1 << 5)
#define RI_IOSR2_CH14E	(1 << 4)
#define RI_IOSR2_CH11E	(1 << 3)
#define RI_IOSR2_CH8E	(1 << 2)
#define RI_IOSR2_CH5E	(1 << 1)
#define RI_IOSR2_CH2E	(1 << 0)

#define RI_IOSR3_CH24E	(1 << 7)
#define RI_IOSR3_CH21E	(1 << 6)
#define RI_IOSR3_CH18E	(1 << 5)
#define RI_IOSR3_CH15E	(1 << 4)
#define RI_IOSR3_CH12E	(1 << 3)
#define RI_IOSR3_CH9E	(1 << 2)
#define RI_IOSR3_CH6E	(1 << 1)
#define RI_IOSR3_CH3E	(1 << 0)

#define RI_IOSR4_CH28E	(1 << 7)
#define RI_IOSR4_CH27E	(1 << 6)
#define RI_IOSR4_CH26E	(1 << 1)
#define RI_IOSR4_CH29E	(1 << 0)

/* RI_IOGCR_IOMx bits control the x'th I/O of each group of I/Os . */
#define RI_IOGCR_IOM1_SHIFT	0
#define RI_IOGCR_IOM1_MASK	0x3

#define RI_IOGCR_IOM2_SHIFT	2
#define RI_IOGCR_IOM2_MASK	0x3

#define RI_IOGCR_IOM3_SHIFT	4
#define RI_IOGCR_IOM3_MASK	0x3

#define RI_IOGCR_IOM4_SHIFT	6
#define RI_IOGCR_IOM4_MASK	0x3

/* If the bit AM in the RI_CR register is cleared (software management of the
   charge transfer acquisition sequence):
*/
#define RI_IOGCR_IOM_OUT_PP_LOW		0x0 /* I/O x is forced to output push-pull low mode. */
#define RI_IOGCR_IOM_OUT_PP_HIGH	0x1 /* I/O x is forced to output push-pull high mode. */
#define RI_IOGCR_IOM_INF_OPEN		0x2 /* I/O x is forced to input floating mode with the I/O switch open. */
#define RI_IOGCR_IOM_INF_CLOSE		0x3 /* I/O x is forced to input floating mode with the I/O switch closed. 
					       The I/O x Schmitt trigger hysteresis is disabled
					       but the I/O pin value can still be read. */

/* If the AM bit in the RI_CR register is set (hardware management of the charge
   transfer acquisition sequence):
*/
#define RI_IOGCR_IOM_SAMPLING	0x0 /* I/O used for the sampling capacitor */
#define RI_IOGCR_IOM_ELECTRODE	0x1 /* I/O used for the electrode */

/* Is analog switch closed.
   If the I/O is used for ADC1 input, the switch must be left open to allow the
   ADC1 to control it.
*/
#define RI_ASCR1_AS7	(1 << 7)
#define RI_ASCR1_AS6	(1 << 6)
#define RI_ASCR1_AS5	(1 << 5)
#define RI_ASCR1_AS4	(1 << 4)
#define RI_ASCR1_AS3	(1 << 3)
#define RI_ASCR1_AS2	(1 << 2)
#define RI_ASCR1_AS1	(1 << 1)
#define RI_ASCR1_AS0	(1 << 0)

#define RI_ASCR2_AS14	(1 << 6)
#define RI_ASCR2_AS11	(1 << 3)
#define RI_ASCR2_AS10	(1 << 2)
#define RI_ASCR2_AS9	(1 << 1)
#define RI_ASCR2_AS8	(1 << 0)

/* 1. To connect the pull-up or pull-down to ADC1 input, the corresponding ADC1
   analog switch must be enabled using the corresponding register.

   2. To avoid extra power consumption, only one resistor should be enabled at a
   time.
*/
#define RI_RCR_400KPD	(1 << 3) /* is 400 kΩ pull-down resistor enabled */
#define RI_RCR_10KPD	(1 << 2) /* is 10 kΩ pull-down resistor enabled */
#define RI_RCR_400KPU	(1 << 1) /* is 400 kΩ pull-up resistor enabled */
#define RI_RCR_10KPU	(1 << 0) /* is 10 kΩ pull-up resistor enabled */

/* This bit is set and cleared by software to select Timer halted mode. In this
   mode, TIM2 and TIM3 are halted when a trigger event occurs and remain halted
   until the event is cleared. This allows the event to be processed.
*/
#define RI_CR_THALT	(1 << 3)
/* This bit selects how the charge transfer acquisition sequence is managed.
   0 -- by software, 1 -- by hardware.
*/
#define RI_CR_AM	(1 << 2)
/* This flag is set by hardware when a trigger event occurs caused by V_IH
   voltage being reached on the sampling capacitor I/O and only if the
   corresponding I/O mask bit is not set. It is cleared by software writing
   “1”. If the bit TIE is set, an interrupt is generated.
*/
#define RI_CR_TIF	(1 << 1)
/* This bit enables the generation of an interrupt on trigger event. */
#define RI_CR_TIE	(1 << 0)

/* This registers only available on low density devices.
   These bits are set and cleared by software to mask events from an I/O or to
   avoid triggering multiple events from an I/O.
*/
#define RI_IOMR1_CH22E	(1 << 7)
#define RI_IOMR1_CH19E	(1 << 6)
#define RI_IOMR1_CH16E	(1 << 5)
#define RI_IOMR1_CH13E	(1 << 4)
#define RI_IOMR1_CH10E	(1 << 3)
#define RI_IOMR1_CH7E	(1 << 2)
#define RI_IOMR1_CH4E	(1 << 1)
#define RI_IOMR1_CH1E	(1 << 0)

#define RI_IOMR2_CH23E	(1 << 7)
#define RI_IOMR2_CH20E	(1 << 6)
#define RI_IOMR2_CH17E	(1 << 5)
#define RI_IOMR2_CH14E	(1 << 4)
#define RI_IOMR2_CH11E	(1 << 3)
#define RI_IOMR2_CH8E	(1 << 2)
#define RI_IOMR2_CH5E	(1 << 1)
#define RI_IOMR2_CH2E	(1 << 0)

#define RI_IOMR3_CH24E	(1 << 7)
#define RI_IOMR3_CH21E	(1 << 6)
#define RI_IOMR3_CH18E	(1 << 5)
#define RI_IOMR3_CH15E	(1 << 4)
#define RI_IOMR3_CH12E	(1 << 3)
#define RI_IOMR3_CH9E	(1 << 2)
#define RI_IOMR3_CH6E	(1 << 1)
#define RI_IOMR3_CH3E	(1 << 0)

#define RI_IOMR4_CH28E	(1 << 7)
#define RI_IOMR4_CH27E	(1 << 6)
#define RI_IOMR4_CH26E	(1 << 1)
#define RI_IOMR4_CH29E	(1 << 0)


/* 
|-------+------+---------------+------------+----------------+----------------|
|    IO | GPIO | IO switch     | ADC1 input | Analog switch  | Comparator /   |
| Group | Port | control bit   |            | control bit in | DAC / V_REFINT |
|       |      | RI_IOSRx regs |            | RI_ASCR1 reg   | functions      |
|-------+------+---------------+------------+----------------+----------------|
|     1 | PA6  | CH1E bit      | ADC1_IN0   | AS0 bit        | COMP1+ in      |
|       |------+---------------+------------|                |                |
|       | PA5  | CH2E bit      | ADC1_IN1   |                |                |
|       |------+---------------+------------|                |                |
|       | PA4  | CH3E bit      | ADC1_IN2   |                |                |
|       |------+---------------+------------|                |                |
|       | PA7  | CH29E bit     | -          |                |                |
|-------+------+---------------+------------+----------------+----------------|
|     2 | PC7  | CH4E bit      | ADC1_IN3   | AS1 bit        | COMP1+ in      |
|       |------+---------------+------------|                |                |
|       | PC4  | CH5E bit      | ADC1_IN4   |                | COMP2- in      |
|       |------+---------------+------------|                |                |
|       | PC3  | CH6E bit      | ADC1_IN5   |                |                |
|       |------+---------------+------------|                |                |
|       | PE7  | CH26E bit     | ADC1_IN25  |                |                |
|-------+------+---------------+------------+----------------+----------------|
|     3 | PC2  | CH7E bit      | ADC1_IN6   | AS2 bit        | COMP1+ in      |
|       |------+---------------+------------|                |                |
|       | PD7  | CH8E bit      | ADC1_IN7   |                | V_REFINT out   |
|       |------+---------------+------------|                |                |
|       | PD6  | CH9E bit      | ADC1_IN8   |                |                |
|-------+------+---------------+------------+----------------+----------------|
|     4 | PD5  | CH10E bit     | ADC1_IN9   | AS3 bit        | COMP1+ in      |
|       |------+---------------+------------|                |                |
|       | PD4  | CH11E bit     | ADC1_IN10  |                |                |
|       |------+---------------+------------|                |                |
|       | PB7  | CH12E bit     | ADC1_IN11  |                |                |
|-------+------+---------------+------------+----------------+----------------|
|     5 | PB6  | CH13E bit     | ADC1_IN12  | AS4 bit        | COMP1+ in      |
|       |------+---------------+------------|                |                |
|       | PB5  | CH14E bit     | ADC1_IN13  |                | DAC out        |
|       |------+---------------+------------|                |                |
|       | PB4  | CH15E bit     | ADC1_IN14  |                |                |
|-------+------+---------------+------------+----------------+----------------|
|     6 | PB3  | CH16E bit     | ADC1_IN15  | AS5 bit        | COMP1+ in      |
|       |------+---------------+------------|                |                |
|       | PB2  | CH17E bit     | ADC1_IN16  |                | DAC out        |
|       |------+---------------+------------|                |                |
|       | PB1  | CH18E bit     | ADC1_IN17  |                |                |
|-------+------+---------------+------------+----------------+----------------|
|     7 | PB0  | CH19E bit     | ADC1_IN18  | AS6 bit        | COMP1+ in      |
|       |------+---------------+------------|                |                |
|       | PD3  | CH20E bit     | ADC1_IN19  |                |                |
|       |------+---------------+------------|                |                |
|       | PD2  | CH21E bit     | ADC1_IN20  |                |                |
|       |------+---------------+------------|                |                |
|       | PE3  | CH27E bit     | ADC1_IN26  |                |                |
|-------+------+---------------+------------+----------------+----------------|
|     8 | PD1  | CH22E bit     | ADC1_IN21  | AS7 bit        | COMP1+ in      |
|       |------+---------------+------------|                |                |
|       | PD0  | CH23E bit     | ADC1_IN22  |                | COMP2+ in      |
|       |------+---------------+------------|                |                |
|       | PE5  | CH24E bit     | ADC1_IN23  |                |                |
|       |------+---------------+------------|                |                |
|       | PE4  | CH28E bit     | ADC1_IN27  |                |                |
|-------+------+---------------+------------+----------------+----------------|
|    NA | PF0  | NA            | ADC1_IN24  | AS8 bit        | COMP1+ in      |
|-------+------+---------------+------------+----------------+----------------|
|    NA | PF1  | NA            | ADC1_IN25  | AS9 bit        | COMP1+ in      |
|-------+------+---------------+------------+----------------+----------------|
|    NA | PF2  | NA            | ADC1_IN26  | AS10 bit       | COMP1+ in      |
|-------+------+---------------+------------+----------------+----------------|
|    NA | PF3  | NA            | ADC1_IN27  | AS11 bit       | COMP1+ in      |   
|-------+------+---------------+------------+----------------+----------------|
*/
#endif
