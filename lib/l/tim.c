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

#include <libstm8/l/tim.h>

void
timer_set_mode(uint16_t timer_peripheral, uint8_t alignment, uint8_t direction)
{
  uint8_t cr1 = TIM_CR1(timer_peripheral);

  cr1 &= ~(TIM_CR1_DIR | (TIM_CR1_CMS_MASK << TIM_CR1_CMS_SHIFT));
  cr1 |= ((uint8_t) direction) | ((uint8_t) alignment);

  TIM_CR1(timer_peripheral) = cr1;
}

void
timer_set_prescaler (uint16_t timer_peripheral, uint16_t value)
{
  switch (timer_peripheral)
    {
    case TIM1_BASE:
      TIM1_PSCRH = (uint8_t) (value >> 8);
      TIM1_PSCRL = (uint8_t) (value & 0xFF);
      break;
    case TIM4_BASE:
      TIM4_PSCR = (uint8_t) (value & 0xFF);
      break;
    default:
      TIM_PSCR(timer_peripheral) = (uint8_t) (value & 0xFF);
      break;
    }
}

void
timer_set_period (uint16_t timer_peripheral, uint16_t period)
{
  switch (timer_peripheral)
    {
    case TIM1_BASE:
      TIM1_ARRH = (uint8_t) (period >> 8);
      TIM1_ARRL = (uint8_t) (period & 0xFF);
      break;
    case TIM4_BASE:
      TIM4_ARR = (uint8_t) (period & 0xFF);
      break;
    default:
      TIM_ARRH(timer_peripheral) = (uint8_t) (period >> 8);
      TIM_ARRL(timer_peripheral) = (uint8_t) (period & 0xFF);
      break;
    }
}

void
timer_set_repetition_counter (uint16_t timer_peripheral, uint8_t value)
{
  if (timer_peripheral == TIM1_BASE)
    {
      TIM1_RCR = value;
    }
}

void
timer_enable_preload (uint16_t timer_peripheral)
{
  TIM_CR1(timer_peripheral) |= TIM_CR1_ARPE;
}

void
timer_disable_preload (uint16_t timer_peripheral)
{
  TIM_CR1(timer_peripheral) &= ~TIM_CR1_ARPE;
}

void
timer_set_oc_mode (uint16_t timer_peripheral, enum tim_oc_id oc_id,
		   enum tim_oc_mode oc_mode)
{
  if (timer_peripheral == TIM4_BASE)
    {
      return;
    }
  else if (timer_peripheral == TIM1_BASE)
    {
      switch (oc_id)
	{
	case TIM_OC1:
	case TIM_OC1N:
	  TIM1_CCMR1 &= ~(TIM_CCMR1_OC1M_MASK << TIM_CCMR1_OC1M_SHIFT);
	  TIM1_CCMR1 |= (uint8_t) oc_mode;
	  break;
	case TIM_OC2:
	case TIM_OC2N:
	  TIM1_CCMR2 &= ~(TIM_CCMR2_OC2M_MASK << TIM_CCMR2_OC2M_SHIFT);
	  TIM1_CCMR2 |= (uint8_t) oc_mode;
	  break;
	case TIM_OC3:
	case TIM_OC3N:
	  TIM1_CCMR3 &= ~(TIM_CCMR3_OC3M_MASK << TIM_CCMR3_OC3M_SHIFT);
	  TIM1_CCMR3 |= (uint8_t) oc_mode;
	  break;
	case TIM_OC4:
	  TIM1_CCMR4 &= ~(TIM_CCMR4_OC4M_MASK << TIM_CCMR4_OC4M_SHIFT);
	  TIM1_CCMR4 |= (uint8_t) oc_mode;
	  break;
	}
    }
  else			/* TIM2,3,5 */
    {
      switch (oc_id)
	{
	case TIM_OC1:
	case TIM_OC1N:
	  TIM_CCMR1(timer_peripheral) &=
	    ~(TIM_CCMR1_OC1M_MASK << TIM_CCMR1_OC1M_SHIFT);
	  TIM_CCMR1(timer_peripheral) |= (uint8_t) oc_mode;
	  break;
	case TIM_OC2:
	case TIM_OC2N:
	  TIM_CCMR2(timer_peripheral) &=
	    ~(TIM_CCMR2_OC2M_MASK << TIM_CCMR2_OC2M_SHIFT);
	  TIM_CCMR2(timer_peripheral) |= (uint8_t) oc_mode;
	  break;
	}
    }
}

void
timer_enable_oc_preload (uint32_t timer_peripheral, enum tim_oc_id oc_id)
{
  if (timer_peripheral == TIM4_BASE)
    {
      return;
    }
  else if (timer_peripheral == TIM1_BASE)
    {
      switch (oc_id)
	{
	case TIM_OC1:
	case TIM_OC1N:
	  TIM1_CCMR1 |= TIM_CCMR1_OC1PE;
	  break;
	case TIM_OC2:
	case TIM_OC2N:
	  TIM1_CCMR2 |= TIM_CCMR2_OC2PE;
	  break;
	case TIM_OC3:
	case TIM_OC3N:
	  TIM1_CCMR3 |= TIM_CCMR3_OC3PE;
	  break;
	case TIM_OC4:
	  TIM1_CCMR4 |= TIM_CCMR4_OC4PE;
	  break;
	}
    }
  else			/* TIM2,3,5 */
    {
      switch (oc_id)
	{
	case TIM_OC1:
	case TIM_OC1N:
	  TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC1PE;
	  break;
	case TIM_OC2:
	case TIM_OC2N:
	  TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC2PE;
	  break;
	}
    }
}

void
timer_disable_oc_preload (uint32_t timer_peripheral, enum tim_oc_id oc_id)
{
  if (timer_peripheral == TIM4_BASE)
    {
      return;
    }
  else if (timer_peripheral == TIM1_BASE)
    {
      switch (oc_id)
	{
	case TIM_OC1:
	case TIM_OC1N:
	  TIM1_CCMR1 &= ~TIM_CCMR1_OC1PE;
	  break;
	case TIM_OC2:
	case TIM_OC2N:
	  TIM1_CCMR2 &= ~TIM_CCMR2_OC2PE;
	  break;
	case TIM_OC3:
	case TIM_OC3N:
	  TIM1_CCMR3 &= ~TIM_CCMR3_OC3PE;
	  break;
	case TIM_OC4:
	  TIM1_CCMR4 &= ~TIM_CCMR4_OC4PE;
	  break;
	}
    }
  else			/* TIM2,3,5 */
    {
      switch (oc_id)
	{
	case TIM_OC1:
	case TIM_OC1N:
	  TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_OC1PE;
	  break;
	case TIM_OC2:
	case TIM_OC2N:
	  TIM_CCMR2(timer_peripheral) &= ~TIM_CCMR2_OC2PE;
	  break;
	}
    }
}
