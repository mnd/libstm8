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
#ifndef DMA_H
#define DMA_H

#include <libstm8/common.h>

#define DMA1_BASE 0x005070
#define DMA1_GCSR MMIO8(DMA1_BASE + 0x0)	/* DMA1 global configuration & status register */
#define DMA1_GIR1 MMIO8(DMA1_BASE + 0x1)	/* DMA1 global interrupt register 1 */

#define DMA1_CxCR(n)	MMIO8(DMA1_BASE + 0x5 + (n)*0xA)
#define DMA1_CxSPR(n)	MMIO8(DMA1_BASE + 0x6 + (n)*0xA)
#define DMA1_CxNDTR(n)	MMIO8(DMA1_BASE + 0x7 + (n)*0xA)
#define DMA1_CxPARH(n)  MMIO8(DMA1_BASE + 0x8 + (n)*0xA)
#define DMA1_CxPARL(n)	MMIO8(DMA1_BASE + 0x9 + (n)*0xA)
#define DMA1_CxM0ARH(n)	MMIO8(DMA1_BASE + 0xB + (n)*0xA)
#define DMA1_CxM0ARL(n)	MMIO8(DMA1_BASE + 0xC + (n)*0xA)
/* only on channel 3 on medium+ and high density devices */
#define DMA1_CxM0EAR(n)	MMIO8(DMA1_BASE + 0xA + (n)*0xA)

#define DMA1_C0CR    DMA1_CxCR(0)   /* DMA1 channel 0 configuration register */
#define DMA1_C0SPR   DMA1_CxSPR(0)  /* DMA1 channel 0 status & priority register */
#define DMA1_C0NDTR  DMA1_CxNDTR(0) /* DMA1 number of data to transfer register */
#define DMA1_C0PARH  DMA1_CxPARH(0) /* DMA1 peripheral address high register */
#define DMA1_C0PARL  DMA1_CxPARL(0) /* DMA1 peripheral address low register */
#define DMA1_C0M0ARH DMA1_CxM0ARH(0) /* DMA1 memory 0 address high register */
#define DMA1_C0M0ARL DMA1_CxM0ARL(0) /* DMA1 memory 0 address low register */

#define DMA1_C1CR    DMA1_CxCR(1)   
#define DMA1_C1SPR   DMA1_CxSPR(1)  
#define DMA1_C1NDTR  DMA1_CxNDTR(1) 
#define DMA1_C1PARH  DMA1_CxPARH(1) 
#define DMA1_C1PARL  DMA1_CxPARL(1) 
#define DMA1_C1M0ARH DMA1_CxM0ARH(1)
#define DMA1_C1M0ARL DMA1_CxM0ARL(1)

#define DMA1_C2CR    DMA1_CxCR(2)   
#define DMA1_C2SPR   DMA1_CxSPR(2)  
#define DMA1_C2NDTR  DMA1_CxNDTR(2) 
#define DMA1_C2PARH  DMA1_CxPARH(2) 
#define DMA1_C2PARL  DMA1_CxPARL(2) 
#define DMA1_C2M0ARH DMA1_CxM0ARH(2)
#define DMA1_C2M0ARL DMA1_CxM0ARL(2)

#define DMA1_C3CR    DMA1_CxCR(3)   
#define DMA1_C3SPR   DMA1_CxSPR(3)  
#define DMA1_C3NDTR  DMA1_CxNDTR(3) 
#define DMA1_C3PARH_C3M1ARH DMA1_CxPARH(3) 
#define DMA1_C3PARL_C3M1ARL DMA1_CxPARL(3) 
#define DMA1_C3M0ARH DMA1_CxM0ARH(3)
#define DMA1_C3M0ARL DMA1_CxM0ARL(3)
#define DMA1_C3M0EAR DMA1_CxM0EAR(3) /* only on medium+ and high density devices */

/* Timeout -- number of number of cycles to wait starting from the last request. */
#define DMA1_GCSR_TO_SHIFT	2
#define DMA1_GCSR_TO_MASK	0x3F

#define DMA1_GCSR_GB	(1 << 1) /* is there are ongoing DMA transfer */
#define DMA1_GCSR_GEN	(1 << 0) /* is DMA enabled according to DMA_CxCR */
/* is there pending interrupt on some channel */
#define DMA1_GIR1_IFC3	(1 << 3)
#define DMA1_GIR1_IFC2	(1 << 2)
#define DMA1_GIR1_IFC1	(1 << 1)
#define DMA1_GIR1_IFC0	(1 << 0)

#define DMA1_CxCR_MEM (1 << 6) /* Set channel works as memory channel. C3CR only */
#define DMA1_CxCR_MINCDEC (1 << 5) /* memory increment 0/decrement 1 mode */
#define DMA1_CxCR_CIRC	(1 << 4)   /* circular buffer mode (Auto-reload mode) */
#define DMA1_CxCR_DIR	(1 << 3)   /* 0: peripheral to the memory, 1: otherwise  */
#define DMA1_CxCR_HTIE	(1 << 2)   /* is half-transaction interrupt enabled. */
#define DMA1_CxCR_TCIE	(1 << 1)   /* is transaction complete interrupt enabled. */
#define DMA1_CxCR_EN	(1 << 0)   /* is channel enabled */

#define DMA1_CxSPR_BUSY		(1 << 7) /* is there an ongoing DMA transfer */
#define DMA1_CxSPR_PEND		(1 << 6) /* is there a DMA pending request */
#define DMA1_CxSPR_TSIZE	(1 << 3) /* 8 or 16 bit transfer size */
#define DMA1_CxSPR_HTIF		(1 << 2) /* is half transaction completed */
#define DMA1_CxSPR_TCIF		(1 << 1) /* is transaction completed */
/* Channel priority level */
#define DMA1_CxSPR_PL_SHIFT	4
#define DMA1_CxSPR_PL_MASK	0x3
#define DMA1_CxSPR_PL_LOW	0x0
#define DMA1_CxSPR_PL_MEDIUM	0x1
#define DMA1_CxSPR_PL_HIGH	0x2
#define DMA1_CxSPR_PL_VERY_HIGH	0x3 /* DMA takes precedence over the CPU */

/* DMA1_CxNDTR(n) -- number of data (byte/word) to transfer. Can be read to get 
 progress.
*/

/* DMA1_CxPARH(n) -- peripheral address pointer high part */
/* DMA1_CxPARL(n) -- peripheral address pointer low part */

/* DMA1_C3PARH_C3M1ARH:DMA1_C3PARL_C3M1ARL
   when DMA1_CxCR_MEM disabled -- same as DMA1_CxPARH(n):DMA1_CxPARL(n)
   when DMA1_CxCR_MEM enabled -- destination memory adress at most 0x1F:0xFF in 
   mem-to-mem transfer.
*/
#define DMA1_C3PARH_C3M1ARH_MASK 0x1F

/* DMA1_CxM0ARH(n) -- memory address pointer high part */
/* DMA1_CxM0ARL(n) -- memory address pointer low part */
#define DMA1_CxM0ARH_MASK	0x7
#define DMA1_C3M0ARH_MEM_MASK	0xFF

#define DMA1_C3M0EAR_MASK 0x1 	/* additional bit for memory address */

#endif
