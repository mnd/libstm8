#include <libstm8/gpio.h>

void gpio_mode_setup (uint16_t gpioport, uint8_t dd_mode,
		      uint8_t c1_mode, uint8_t c2_mode, uint8_t pins)
{
  uint8_t cr1, cr2, ddr, i;
  cr1 = GPIO_CR1(gpioport);
  cr2 = GPIO_CR2(gpioport);
  ddr = GPIO_DDR(gpioport);
  for (i = 0; i < 8; ++i)
    {
      if (! (pins & (1 << i))) continue;

      cr1 &= ~GPIO_C1_MASK(i);
      cr1 |= GPIO_C1(i, c1_mode);

      cr2 &= ~GPIO_C2_MASK(i);
      cr2 |= GPIO_C2(i, c2_mode);

      ddr &= ~GPIO_DD_MASK(i);
      ddr |= GPIO_DD(i, dd_mode);
    }
  
  GPIO_CR1(gpioport) = cr1;
  GPIO_CR2(gpioport) = cr2;
  GPIO_DDR(gpioport) = ddr;
}
