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
#ifndef CPU_H
#define CPU_H

#include <libstm8/common.h>

/* CPU_* registers accessible only in debug mode. 
   It's same registers as used in asm. */
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

/* PC=PCE:PCH:PCL; X=XH:XL; Y=YH:YL; SP=SPH:SPL */

/* Overflow.
   Indicates that an overflow occurred during the last signed arithmetic
   operation, on the MSB result bit. See the INC, INCW, DEC, DECW, NEG, NEGW,
   ADD, ADDW, ADC, SUB, SUBW, SBC, CP, and CPW instructions. */
#define CPU_CCR_V  (1 << 7)
#define CPU_CCR_0  (1 << 6)	/* unused? */
/* CPU_CCR_I1:CPU_CCR_I0 -- interrupt mask level (see at itc.h).
   These flags can be set and cleared by software through the RIM, SIM, HALT,
   WFI, WFE, IRET, TRAP, and POP instructions and are automatically set by
   hardware when entering an interrupt service routine. */
#define CPU_CCR_I1 (1 << 5)
/* Half carry bit.
   Set to 1 when a carry occurs between the bits 3 and 4 of the ALU during an
   ADD or ADC instruction. The H bit is useful in BCD arithmetic subroutines. */
#define CPU_CCR_H  (1 << 4)
#define CPU_CCR_I0 (1 << 3)
/* Negative.
   Indicates that the result of the last arithmetic, logical or data
   manipulation is negative (i.e. the most significant bit is a logic 1).
*/
#define CPU_CCR_N  (1 << 2)
/* Zero.
   Indicates that the result of the last arithmetic, logical or data
   manipulation is zero.
*/
#define CPU_CCR_Z  (1 << 1)
/* Carry.
   Indicates that a carry or borrow out of the ALU occurred during the last
   arithmetic operation on the MSB operation result bit. This bit is also
   affected during bit test, branch, shift, rotate and load instructions. See
   the ADD, ADC, SUB, and SBC instructions.
   - In a division operation, C indicates if trouble occurred during execution
     (quotient overflow or zero division). See the DIV instruction.
   - In bit test operations, C is the copy of the tested bit. See the BTJF and
     BTJT instructions.
   - In shift and rotate operations, the carry is updated. See the RRC, RLC,
     SRL, SLL, and SRA instructions.
   - This bit can be set, reset or complemented by software using the SCF, RCF,
     and CCF instructions.
*/
#define CPU_CCR_C  (1 << 0)

#endif
