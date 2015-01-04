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
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef STM8LREGS_SDCC_H
#define STM8LREGS_SDCC_H

/* Factory conversion registers */

volatile __at (0x004910) unsigned char VREFINT_Factory_CONV; /* Internal reference voltage factory conversion */
volatile __at (0x004911) unsigned char TS_Factory_CONV_V90;  /* Temperature sensor output voltage */

/* The VREFINT_Factory_CONV byte represents the 8 LSB of the result 
   of the VREFINT 12-bit ADC conversion performed in factory. 
   The MSB have a fixed value: 0x6.

   The TS_Factory_CONV_V90 byte represents the 8 LSB of the result
   of the V90 12-bit ADC conversion performed in factory.
   The 2 MSB have a fixed value: 0x3.
*/


/* I/O port hardware register map */

volatile __at (0x005000) unsigned char PA_ODR; /* Port A data output latch register */
volatile __at (0x005001) unsigned char PA_IDR; /* Port A input pin value register */
volatile __at (0x005002) unsigned char PA_DDR; /* Port A data direction register */
volatile __at (0x005003) unsigned char PA_CR1; /* Port A control register 1 */
volatile __at (0x005004) unsigned char PA_CR2; /* Port A control register 2 */

volatile __at (0x005005) unsigned char PB_ODR; /*  */
volatile __at (0x005006) unsigned char PB_IDR; /*  */
volatile __at (0x005007) unsigned char PB_DDR; /*  */
volatile __at (0x005008) unsigned char PB_CR1; /*  */
volatile __at (0x005009) unsigned char PB_CR2; /*  */

volatile __at (0x00500A) unsigned char PC_ODR; /*  */
volatile __at (0x00500B) unsigned char PC_IDR; /*  */
volatile __at (0x00500C) unsigned char PC_DDR; /*  */
volatile __at (0x00500D) unsigned char PC_CR1; /*  */
volatile __at (0x00500E) unsigned char PC_CR2; /*  */

volatile __at (0x00500F) unsigned char PD_ODR; /*  */
volatile __at (0x005010) unsigned char PD_IDR; /*  */
volatile __at (0x005011) unsigned char PD_DDR; /*  */
volatile __at (0x005012) unsigned char PD_CR1; /*  */
volatile __at (0x005013) unsigned char PD_CR2; /*  */

volatile __at (0x005014) unsigned char PE_ODR; /*  */
volatile __at (0x005015) unsigned char PE_IDR; /*  */
volatile __at (0x005016) unsigned char PE_DDR; /*  */
volatile __at (0x005017) unsigned char PE_CR1; /*  */
volatile __at (0x005018) unsigned char PE_CR2; /*  */

volatile __at (0x005019) unsigned char PF_ODR; /*  */
volatile __at (0x00501A) unsigned char PF_IDR; /*  */
volatile __at (0x00501B) unsigned char PF_DDR; /*  */
volatile __at (0x00501C) unsigned char PF_CR1; /*  */
volatile __at (0x00501D) unsigned char PF_CR2; /*  */

/* General hardware register map */

volatile __at (0x005050) unsigned char FLASH_CR1; /* Flash control register 1 */
volatile __at (0x005051) unsigned char FLASH_CR2; /* Flash control register 2 */
volatile __at (0x005052) unsigned char FLASH_PUKR; /* Flash program memory unprotection key register */
volatile __at (0x005053) unsigned char FLASH_DUKR; /* Data EEPROM unprotection key register */
volatile __at (0x005054) unsigned char FLASH_IAPSR; /* Flash in-application programming status register */

volatile __at (0x005070) unsigned char DMA1_GCSR; /* DMA1 global configuration & status register */
volatile __at (0x005071) unsigned char DMA1_GIR1; /* DMA1 global interrupt register 1 */

volatile __at (0x005075) unsigned char DMA1_C0CR; /* DMA1 channel 0 configuration register */
volatile __at (0x005076) unsigned char DMA1_C0SPR; /* DMA1 channel 0 status & priority register */
volatile __at (0x005077) unsigned char DMA1_C0NDTR; /* DMA1 number of data to transfer register (channel 0) */
volatile __at (0x005078) unsigned char DMA1_C0PARH; /* DMA1 peripheral address high register (channel 0) */
volatile __at (0x005079) unsigned char DMA1_C0PARL; /* DMA1 peripheral address low register (channel 0) */
volatile __at (0x00507B) unsigned char DMA1_C0M0ARH; /* DMA1 memory 0 address high register (channel 0) */
volatile __at (0x00507C) unsigned char DMA1_C0M0ARL; /* DMA1 memory 0 address low register (channel 0) */

volatile __at (0x00507F) unsigned char DMA1_C1CR; /*  */
volatile __at (0x005080) unsigned char DMA1_C1SPR; /*  */
volatile __at (0x005081) unsigned char DMA1_C1NDTR; /*  */
volatile __at (0x005082) unsigned char DMA1_C1PARH; /*  */
volatile __at (0x005083) unsigned char DMA1_C1PARL; /*  */
volatile __at (0x005085) unsigned char DMA1_C1M0ARH; /*  */
volatile __at (0x005086) unsigned char DMA1_C1M0ARL; /*  */

volatile __at (0x005089) unsigned char DMA1_C2CR; /*  */
volatile __at (0x00508A) unsigned char DMA1_C2SPR; /*  */
volatile __at (0x00508B) unsigned char DMA1_C2NDTR; /*  */
volatile __at (0x00508C) unsigned char DMA1_C2PARH; /*  */
volatile __at (0x00508D) unsigned char DMA1_C2PARL; /*  */
volatile __at (0x00508F) unsigned char DMA1_C2M0ARH; /*  */
volatile __at (0x005090) unsigned char DMA1_C2M0ARL; /*  */

volatile __at (0x005093) unsigned char DMA1_C3CR; /*  */
volatile __at (0x005094) unsigned char DMA1_C3SPR; /*  */
volatile __at (0x005095) unsigned char DMA1_C3NDTR; /*  */
volatile __at (0x005096) unsigned char DMA1_C3PARH_C3M1ARH; /*  */
volatile __at (0x005097) unsigned char DMA1_C3PARL_C3M1ARL; /*  */
volatile __at (0x005099) unsigned char DMA1_C3M0ARH;	    /*  */
volatile __at (0x00509A) unsigned char DMA1_C3M0ARL;	    /*  */

volatile __at (0x00509E) unsigned char SYSCFG_RMPCR1; /* Remapping register 1 */
volatile __at (0x00509F) unsigned char SYSCFG_RMPCR2; /* Remapping register 2 */

volatile __at (0x0050A0) unsigned char EXTI_CR1; /* External interrupt control register 1 */
volatile __at (0x0050A1) unsigned char EXTI_CR2; /* External interrupt control register 2 */
volatile __at (0x0050A2) unsigned char EXTI_CR3; /* External interrupt control register 3 */
volatile __at (0x0050A3) unsigned char EXTI_SR1; /* External interrupt status register 1 */
volatile __at (0x0050A4) unsigned char EXTI_SR2; /* External interrupt status register 2 */
volatile __at (0x0050A5) unsigned char EXTI_CONF1; /* External interrupt port select register 1 */

volatile __at (0x0050A6) unsigned char WFE_CR1;	/* WFE control register 1 */
volatile __at (0x0050A7) unsigned char WFE_CR2;	/* WFE control register 2 */
volatile __at (0x0050A8) unsigned char WFE_CR3;	/* WFE control register 3 */

volatile __at (0x0050B0) unsigned char RST_CR; /* Reset control register */
volatile __at (0x0050B1) unsigned char RST_SR; /* Reset status register */

volatile __at (0x0050B2) unsigned char PWR_CSR1; /* Power control and status register 1 */
volatile __at (0x0050B3) unsigned char PWR_CSR2; /* Power control and status register 2 */

volatile __at (0x0050C0) unsigned char CLK_DIVR; /* Clock master divider register */
volatile __at (0x0050C1) unsigned char CLK_CRTCR; /* Clock RTC register */
volatile __at (0x0050C2) unsigned char CLK_ICKR; /* Internal clock control register */
volatile __at (0x0050C3) unsigned char CLK_PCKENR1; /* Peripheral clock gating register 1 */
volatile __at (0x0050C4) unsigned char CLK_PCKENR2; /* Peripheral clock gating register 2 */
volatile __at (0x0050C5) unsigned char CLK_CCOR; /* Configurable clock control register */
volatile __at (0x0050C6) unsigned char CLK_ECKR; /* External clock control register */
volatile __at (0x0050C7) unsigned char CLK_SCSR; /* System clock status register */
volatile __at (0x0050C8) unsigned char CLK_SWR;	/* System clock switch register */
volatile __at (0x0050C9) unsigned char CLK_SWCR; /* Clock switch control register */
volatile __at (0x0050CA) unsigned char CLK_CSSR; /* Clock security system register */
volatile __at (0x0050CB) unsigned char CLK_CBEEPR; /* Clock BEEP register */
volatile __at (0x0050CC) unsigned char CLK_HSICALR; /* HSI calibration register */
volatile __at (0x0050CD) unsigned char CLK_HSITRIMR; /* HSI clock calibration trimming register */
volatile __at (0x0050CE) unsigned char CLK_HSIUNLCKR; /* HSI unlock register */
volatile __at (0x0050CF) unsigned char CLK_REGCSR; /* Main regulator control status register */

volatile __at (0x0050D3) unsigned char WWDG_CR;	/* WWDG control register */
volatile __at (0x0050D4) unsigned char WWDG_WR;	/* WWDR window register */

volatile __at (0x0050E0) unsigned char IWDG_KR;	/* IWDG key register */
volatile __at (0x0050E1) unsigned char IWDG_PR;	/* IWDG prescaler register */
volatile __at (0x0050E2) unsigned char IWDG_RLR; /* IWDG reload register */

volatile __at (0x0050F0) unsigned char BEEP_CSR1; /* BEEP control/status register 1 */
volatile __at (0x0050F3) unsigned char BEEP_CSR2; /* BEEP control/status register 2 */

volatile __at (0x005140) unsigned char RTC_TR1;	/* Time register 1 */
volatile __at (0x005141) unsigned char RTC_TR2;	/* Time register 2 */
volatile __at (0x005142) unsigned char RTC_TR3;	/* Time register 3 */

volatile __at (0x005144) unsigned char RTC_DR1;	/* Date register 1 */
volatile __at (0x005145) unsigned char RTC_DR2;	/* Date register 2 */
volatile __at (0x005146) unsigned char RTC_DR3;	/* Date register 3 */

volatile __at (0x005148) unsigned char RTC_CR1;	/* Control register 1 */
volatile __at (0x005149) unsigned char RTC_CR2;	/* Control register 2 */
volatile __at (0x00514A) unsigned char RTC_CR3;	/* Control register 3 */

volatile __at (0x00514C) unsigned char RTC_ISR1; /* Initialization and status register 1 */
volatile __at (0x00514D) unsigned char RTC_ISR2; /* Initialization and status register 2 */

/* Next 5 registers are not impacted by a system reset. They are reset at power-on. */
volatile __at (0x005150) unsigned char RTC_SPRERH; /* Synchronous prescaler register high */
volatile __at (0x005151) unsigned char RTC_SPRERL; /* Synchronous prescaler register low */
volatile __at (0x005152) unsigned char RTC_APRER; /* Asynchronous prescaler register */
volatile __at (0x005154) unsigned char RTC_WUTRH; /* Wakeup timer register high */
volatile __at (0x005155) unsigned char RTC_WUTRL; /* Wakeup timer register low */

volatile __at (0x005159) unsigned char RTC_WPR;	/* Write protection register */

volatile __at (0x00515C) unsigned char RTC_ALRMAR1; /* Alarm A register 1 */
volatile __at (0x00515D) unsigned char RTC_ALRMAR2; /* Alarm A register 2 */
volatile __at (0x00515E) unsigned char RTC_ALRMAR3; /* Alarm A register 3 */
volatile __at (0x00515F) unsigned char RTC_ALRMAR4; /* Alarm A register 4 */

volatile __at (0x005200) unsigned char SPI1_CR1; /* SPI1 control register 1 */
volatile __at (0x005201) unsigned char SPI1_CR2; /* SPI1 control register 2 */
volatile __at (0x005202) unsigned char SPI1_ICR; /* SPI1 interrupt control register */
volatile __at (0x005203) unsigned char SPI1_SR;	/* SPI1 status register */
volatile __at (0x005204) unsigned char SPI1_DR;	/* SPI1 data register */
volatile __at (0x005205) unsigned char SPI1_CRCPR; /* SPI1 CRC polynomial register */
volatile __at (0x005206) unsigned char SPI1_RXCRCR; /* SPI1 Rx CRC register */
volatile __at (0x005207) unsigned char SPI1_TXCRCR; /* SPI1 Tx CRC register */

volatile __at (0x005210) unsigned char I2C1_CR1; /* I2C1 control register 1 */
volatile __at (0x005211) unsigned char I2C1_CR2; /* I2C1 control register 2 */
volatile __at (0x005212) unsigned char I2C1_FREQR; /* I2C1 frequency register */
volatile __at (0x005213) unsigned char I2C1_OARL; /* I2C1 own address register low */
volatile __at (0x005214) unsigned char I2C1_OARH; /* I2C1 own address register high */
volatile __at (0x005216) unsigned char I2C1_DR;	/* I2C1 data register */
volatile __at (0x005217) unsigned char I2C1_SR1; /* I2C1 status register 1 */
volatile __at (0x005218) unsigned char I2C1_SR2; /* I2C1 status register 2 */
volatile __at (0x005219) unsigned char I2C1_SR3; /* I2C1 status register 3 */
volatile __at (0x00521A) unsigned char I2C1_ITR; /* I2C1 interrupt control register */
volatile __at (0x00521B) unsigned char I2C1_CCRL; /* I2C1 clock control register low */
volatile __at (0x00521C) unsigned char I2C1_CCRH; /* I2C1 clock control register high */
volatile __at (0x00521D) unsigned char I2C1_TRISER; /* I2C1 TRISE register */
volatile __at (0x00521E) unsigned char I2C1_PECR; /* I2C1 packet error checking register */

volatile __at (0x005230) unsigned char USART1_SR; /* USART1 status register */
volatile __at (0x005231) unsigned char USART1_DR; /* USART1 data register */
volatile __at (0x005232) unsigned char USART1_BRR1; /* USART1 baud rate register 1 */
volatile __at (0x005233) unsigned char USART1_BRR2; /* USART1 baud rate register 2 */
volatile __at (0x005234) unsigned char USART1_CR1; /* USART1 control register 1 */
volatile __at (0x005235) unsigned char USART1_CR2; /* USART1 control register 2 */
volatile __at (0x005236) unsigned char USART1_CR3; /* USART1 control register 3 */
volatile __at (0x005237) unsigned char USART1_CR4; /* USART1 control register 4 */
volatile __at (0x005238) unsigned char USART1_CR5; /* USART1 control register 5 */
volatile __at (0x005239) unsigned char USART1_GTR; /* USART1 guard time register */
volatile __at (0x00523A) unsigned char USART1_PSCR; /* USART1 prescaler register */

volatile __at (0x005250) unsigned char TIM2_CR1; /* TIM2 control register 1 */
volatile __at (0x005251) unsigned char TIM2_CR2; /* TIM2 control register 2 */
volatile __at (0x005252) unsigned char TIM2_SMCR; /* TIM2 Slave mode control register */
volatile __at (0x005253) unsigned char TIM2_ETR; /* TIM2 external trigger register */
volatile __at (0x005254) unsigned char TIM2_DER; /* TIM2 DMA1 request enable register */
volatile __at (0x005255) unsigned char TIM2_IER; /* TIM2 interrupt enable register */
volatile __at (0x005256) unsigned char TIM2_SR1; /* TIM2 status register 1 */
volatile __at (0x005257) unsigned char TIM2_SR2; /* TIM2 status register 2 */
volatile __at (0x005258) unsigned char TIM2_EGR; /* TIM2 event generation register */
volatile __at (0x005259) unsigned char TIM2_CCMR1; /* TIM2 capture/compare mode register 1 */
volatile __at (0x00525A) unsigned char TIM2_CCMR2; /* TIM2 capture/compare mode register 2 */
volatile __at (0x00525B) unsigned char TIM2_CCER1; /* TIM2 capture/compare enable register 1 */
volatile __at (0x00525C) unsigned char TIM2_CNTRH; /* TIM2 counter high */
volatile __at (0x00525D) unsigned char TIM2_CNTRL; /* TIM2 counter low */
volatile __at (0x00525E) unsigned char TIM2_PSCR; /* TIM2 prescaler register */
volatile __at (0x00525F) unsigned char TIM2_ARRH; /* TIM2 auto-reload register high */
volatile __at (0x005260) unsigned char TIM2_ARRL; /* TIM2 auto-reload register low */
volatile __at (0x005261) unsigned char TIM2_CCR1H; /* TIM2 capture/compare register 1 high */
volatile __at (0x005262) unsigned char TIM2_CCR1L; /* TIM2 capture/compare register 1 low */
volatile __at (0x005263) unsigned char TIM2_CCR2H; /* TIM2 capture/compare register 2 high */
volatile __at (0x005264) unsigned char TIM2_CCR2L; /* TIM2 capture/compare register 2 low */
volatile __at (0x005265) unsigned char TIM2_BKR; /* TIM2 break register */
volatile __at (0x005266) unsigned char TIM2_OISR; /* TIM2 output idle state register */

volatile __at (0x005280) unsigned char TIM3_CR1; /*  */
volatile __at (0x005281) unsigned char TIM3_CR2; /*  */
volatile __at (0x005282) unsigned char TIM3_SMCR; /*  */
volatile __at (0x005283) unsigned char TIM3_ETR;  /*  */
volatile __at (0x005284) unsigned char TIM3_DER;  /*  */
volatile __at (0x005285) unsigned char TIM3_IER;  /*  */
volatile __at (0x005286) unsigned char TIM3_SR1;  /*  */
volatile __at (0x005287) unsigned char TIM3_SR2;  /*  */
volatile __at (0x005288) unsigned char TIM3_EGR;  /*  */
volatile __at (0x005289) unsigned char TIM3_CCMR1; /*  */
volatile __at (0x00528A) unsigned char TIM3_CCMR2; /*  */
volatile __at (0x00528B) unsigned char TIM3_CCER1; /*  */
volatile __at (0x00528C) unsigned char TIM3_CNTRH; /*  */
volatile __at (0x00528D) unsigned char TIM3_CNTRL; /*  */
volatile __at (0x00528E) unsigned char TIM3_PSCR;  /*  */
volatile __at (0x00528F) unsigned char TIM3_ARRH;  /*  */
volatile __at (0x005290) unsigned char TIM3_ARRL;  /*  */
volatile __at (0x005291) unsigned char TIM3_CCR1H; /*  */
volatile __at (0x005292) unsigned char TIM3_CCR1L; /*  */
volatile __at (0x005293) unsigned char TIM3_CCR2H; /*  */
volatile __at (0x005294) unsigned char TIM3_CCR2L; /*  */
volatile __at (0x005295) unsigned char TIM3_BKR;   /*  */
volatile __at (0x005296) unsigned char TIM3_OISR;  /*  */

volatile __at (0x0052B0) unsigned char TIM1_CR1; /*  */
volatile __at (0x0052B1) unsigned char TIM1_CR2; /*  */
volatile __at (0x0052B2) unsigned char TIM1_SMCR; /*  */
volatile __at (0x0052B3) unsigned char TIM1_ETR;  /*  */
volatile __at (0x0052B4) unsigned char TIM1_DER;  /*  */
volatile __at (0x0052B5) unsigned char TIM1_IER;  /*  */
volatile __at (0x0052B6) unsigned char TIM1_SR1;  /*  */
volatile __at (0x0052B7) unsigned char TIM1_SR2;  /*  */
volatile __at (0x0052B8) unsigned char TIM1_EGR;  /*  */
volatile __at (0x0052B9) unsigned char TIM1_CCMR1; /*  */
volatile __at (0x0052BA) unsigned char TIM1_CCMR2; /*  */
volatile __at (0x0052BB) unsigned char TIM1_CCMR3; /*  */
volatile __at (0x0052BC) unsigned char TIM1_CCMR4; /*  */
volatile __at (0x0052BD) unsigned char TIM1_CCER1; /*  */
volatile __at (0x0052BE) unsigned char TIM1_CCER2; /*  */
volatile __at (0x0052BF) unsigned char TIM1_CNTRH; /*  */
volatile __at (0x0052C0) unsigned char TIM1_CNTRL; /*  */
volatile __at (0x0052C1) unsigned char TIM1_PSCRH; /*  */
volatile __at (0x0052C2) unsigned char TIM1_PSCRL; /*  */
volatile __at (0x0052C3) unsigned char TIM1_ARRH;  /*  */
volatile __at (0x0052C4) unsigned char TIM1_ARRL;  /*  */
volatile __at (0x0052C5) unsigned char TIM1_RCR; /* TIM1 Repetition counter register */
volatile __at (0x0052C6) unsigned char TIM1_CCR1H; /*  */
volatile __at (0x0052C7) unsigned char TIM1_CCR1L; /*  */
volatile __at (0x0052C8) unsigned char TIM1_CCR2H; /*  */
volatile __at (0x0052C9) unsigned char TIM1_CCR2L; /*  */
volatile __at (0x0052CA) unsigned char TIM1_CCR3H; /*  */
volatile __at (0x0052CB) unsigned char TIM1_CCR3L; /*  */
volatile __at (0x0052CC) unsigned char TIM1_CCR4H; /*  */
volatile __at (0x0052CD) unsigned char TIM1_CCR4L; /*  */
volatile __at (0x0052CE) unsigned char TIM1_BKR;   /*  */
volatile __at (0x0052CF) unsigned char TIM1_DTR; /* TIM1 dead-time register */
volatile __at (0x0052D0) unsigned char TIM1_OISR; /*  */
volatile __at (0x0052D1) unsigned char TIM1_DCR1; /* DMA1 control register 1 */
volatile __at (0x0052D2) unsigned char TIM1_DCR2; /* DMA1 control register 2 */
volatile __at (0x0052D3) unsigned char TIM1_DMA1R; /* TIM1 DMA1 address for burst mode */

volatile __at (0x0052E0) unsigned char TIM4_CR1; /*  */
volatile __at (0x0052E1) unsigned char TIM4_CR2; /*  */
volatile __at (0x0052E2) unsigned char TIM4_SMCR; /*  */
volatile __at (0x0052E3) unsigned char TIM4_DER;  /*  */
volatile __at (0x0052E4) unsigned char TIM4_IER;  /*  */
volatile __at (0x0052E5) unsigned char TIM4_SR1;  /*  */
volatile __at (0x0052E6) unsigned char TIM4_EGR;  /*  */
volatile __at (0x0052E7) unsigned char TIM4_CNTR; /*  */
volatile __at (0x0052E8) unsigned char TIM4_PSCR; /*  */
volatile __at (0x0052E9) unsigned char TIM4_ARR;  /*  */

volatile __at (0x0052FF) unsigned char IR_CR; /* Infrared control register */

volatile __at (0x005340) unsigned char ADC1_CR1; /* ADC1 configuration register 1 */
volatile __at (0x005341) unsigned char ADC1_CR2; /* ADC1 configuration register 2 */
volatile __at (0x005342) unsigned char ADC1_CR3; /* ADC1 configuration register 3 */
volatile __at (0x005343) unsigned char ADC1_SR;	/* ADC1 status register */
volatile __at (0x005344) unsigned char ADC1_DRH; /* ADC1 data register high */
volatile __at (0x005345) unsigned char ADC1_DRL; /* ADC1 data register low */
volatile __at (0x005346) unsigned char ADC1_HTRH; /* ADC1 high threshold register high */
volatile __at (0x005347) unsigned char ADC1_HTRL; /* ADC1 high threshold register low */
volatile __at (0x005348) unsigned char ADC1_LTRH; /* ADC1 low threshold register high */
volatile __at (0x005349) unsigned char ADC1_LTRL; /* ADC1 low threshold register low */
volatile __at (0x00534A) unsigned char ADC1_SQR1; /* ADC1 channel sequence 1 register */
volatile __at (0x00534B) unsigned char ADC1_SQR2; /* ADC1 channel sequence 2 register */
volatile __at (0x00534C) unsigned char ADC1_SQR3; /* ADC1 channel sequence 3 register */
volatile __at (0x00534D) unsigned char ADC1_SQR4; /* ADC1 channel sequence 4 register */
volatile __at (0x00534E) unsigned char ADC1_TRIGR1; /* ADC1 trigger disable 1 */
volatile __at (0x00534F) unsigned char ADC1_TRIGR2; /* ADC1 trigger disable 2 */
volatile __at (0x005350) unsigned char ADC1_TRIGR3; /* ADC1 trigger disable 3 */
volatile __at (0x005351) unsigned char ADC1_TRIGR4; /* ADC1 trigger disable 4 */

volatile __at (0x005380) unsigned char DAC_CR1;	/* DAC control register 1 */
volatile __at (0x005381) unsigned char DAC_CR2;	/* DAC control register 2 */
volatile __at (0x005384) unsigned char DAC_SWTRIGR; /* DAC software trigger register */
volatile __at (0x005385) unsigned char DAC_SR; /* DAC status register */
volatile __at (0x005388) unsigned char DAC_RDHRH; /* DAC right aligned data holding register high */
volatile __at (0x005389) unsigned char DAC_RDHRL; /* DAC right aligned data holding register low */
volatile __at (0x00538C) unsigned char DAC_LDHRH; /* DAC left aligned data holding register high */
volatile __at (0x00538D) unsigned char DAC_LDHRL; /* DAC left aligned data holding register low */
volatile __at (0x005390) unsigned char DAC_DHR8; /* DAC 8-bit data holding register */
volatile __at (0x0053AC) unsigned char DAC_DORH; /* DAC data output register high */
volatile __at (0x0053AD) unsigned char DAC_DORL; /* DAC data output register low */

volatile __at (0x005400) unsigned char LCD_CR1;	/* LCD control register 1 */
volatile __at (0x005401) unsigned char LCD_CR2;	/* LCD control register 2 */
volatile __at (0x005402) unsigned char LCD_CR3;	/* LCD control register 3 */
volatile __at (0x005403) unsigned char LCD_FRQ;	/* LCD frequency selection register */
volatile __at (0x005404) unsigned char LCD_PM0;	/* LCD Port mask register 0 */
volatile __at (0x005405) unsigned char LCD_PM1;	/* LCD Port mask register 1 */
volatile __at (0x005406) unsigned char LCD_PM2;	/* LCD Port mask register 2 */
volatile __at (0x005407) unsigned char LCD_PM3;	/* LCD Port mask register 3 */

volatile __at (0x00540C) unsigned char LCD_RAM0; /* LCD display memory 0 */
volatile __at (0x00540D) unsigned char LCD_RAM1; /* LCD display memory 1 */
volatile __at (0x00540E) unsigned char LCD_RAM2; /* LCD display memory 2 */
volatile __at (0x00540F) unsigned char LCD_RAM3; /* LCD display memory 3 */
volatile __at (0x005410) unsigned char LCD_RAM4; /* LCD display memory 4 */
volatile __at (0x005411) unsigned char LCD_RAM5; /* LCD display memory 5 */
volatile __at (0x005412) unsigned char LCD_RAM6; /* LCD display memory 6 */
volatile __at (0x005413) unsigned char LCD_RAM7; /* LCD display memory 7 */
volatile __at (0x005414) unsigned char LCD_RAM8; /* LCD display memory 8 */
volatile __at (0x005415) unsigned char LCD_RAM9; /* LCD display memory 9 */
volatile __at (0x005416) unsigned char LCD_RAM10; /* LCD display memory 10 */
volatile __at (0x005417) unsigned char LCD_RAM11; /* LCD display memory 11 */
volatile __at (0x005418) unsigned char LCD_RAM12; /* LCD display memory 12 */
volatile __at (0x005419) unsigned char LCD_RAM13; /* LCD display memory 13 */

volatile __at (0x005431) unsigned char RI_ICR1;	/* Timer input capture routing register 1 */
volatile __at (0x005432) unsigned char RI_ICR2;	/* Timer input capture routing register 2 */
volatile __at (0x005433) unsigned char RI_IOIR1; /* I/O input register 1 */
volatile __at (0x005434) unsigned char RI_IOIR2; /* I/O input register 2 */
volatile __at (0x005435) unsigned char RI_IOIR3; /* I/O input register 3 */
volatile __at (0x005436) unsigned char RI_IOCMR1; /* I/O control mode register 1 */
volatile __at (0x005437) unsigned char RI_IOCMR2; /* I/O control mode register 2 */
volatile __at (0x005438) unsigned char RI_IOCMR3; /* I/O control mode register 3 */
volatile __at (0x005439) unsigned char RI_IOSR1; /* I/O switch register 1 */
volatile __at (0x00543A) unsigned char RI_IOSR2; /* I/O switch register 2 */
volatile __at (0x00543B) unsigned char RI_IOSR3; /* I/O switch register 3 */
volatile __at (0x00543C) unsigned char RI_IOGCR; /* I/O group control register */
volatile __at (0x00543D) unsigned char RI_ASCR1; /* Analog switch register 1 */
volatile __at (0x00543E) unsigned char RI_ASCR2; /* Analog switch register 2 */
volatile __at (0x00543F) unsigned char RI_RCR; /* Resistor control register 1 */

volatile __at (0x005440) unsigned char COMP_CSR1; /* Comparator control and status register 1 */
volatile __at (0x005441) unsigned char COMP_CSR2; /* Comparator control and status register 2 */
volatile __at (0x005442) unsigned char COMP_CSR3; /* Comparator control and status register 3 */
volatile __at (0x005443) unsigned char COMP_CSR4; /* Comparator control and status register 4 */
volatile __at (0x005444) unsigned char COMP_CSR5; /* Comparator control and status register 5 */

/* CPU/SWIM/debug module/interrupt controller registers */

/* CPU_* accessible only in debug mode */
volatile __at (0x007F00) unsigned char CPU_A; /* Accumulator */
volatile __at (0x007F01) unsigned char CPU_PCE;	/* Program counter extended */
volatile __at (0x007F02) unsigned char CPU_PCH;	/* Program counter high */
volatile __at (0x007F03) unsigned char CPU_PCL;	/* Program counter low */
volatile __at (0x007F04) unsigned char CPU_XH; /* X index register high */
volatile __at (0x007F05) unsigned char CPU_XL; /* X index register low */
volatile __at (0x007F06) unsigned char CPU_YH; /* Y index register high */
volatile __at (0x007F07) unsigned char CPU_YL; /* Y index register low */
volatile __at (0x007F08) unsigned char CPU_SPH;	/* Stack pointer high */
volatile __at (0x007F09) unsigned char CPU_SPL;	/* Stack pointer low */
volatile __at (0x007F0A) unsigned char CPU_CCR;	/* Condition code register */

volatile __at (0x007F60) unsigned char CFG_GCR;	/* Global configuration register */

volatile __at (0x007F70) unsigned char ITC_SPR1; /* Interrupt Software priority register 1 */
volatile __at (0x007F71) unsigned char ITC_SPR2; /* Interrupt Software priority register 2 */
volatile __at (0x007F72) unsigned char ITC_SPR3; /* Interrupt Software priority register 3 */
volatile __at (0x007F73) unsigned char ITC_SPR4; /* Interrupt Software priority register 4 */
volatile __at (0x007F74) unsigned char ITC_SPR5; /* Interrupt Software priority register 5 */
volatile __at (0x007F75) unsigned char ITC_SPR6; /* Interrupt Software priority register 6 */
volatile __at (0x007F76) unsigned char ITC_SPR7; /* Interrupt Software priority register 7 */
volatile __at (0x007F77) unsigned char ITC_SPR8; /* Interrupt Software priority register 8 */

volatile __at (0x007F80) unsigned char SWIM_CSR; /* SWIM control status register */

volatile __at (0x007F90) unsigned char DM_BK1RE; /* DM breakpoint 1 register extended byte */
volatile __at (0x007F91) unsigned char DM_BK1RH; /* DM breakpoint 1 register high byte */
volatile __at (0x007F92) unsigned char DM_BK1RL; /* DM breakpoint 1 register low byte */
volatile __at (0x007F93) unsigned char DM_BK2RE; /* DM breakpoint 2 register extended byte */
volatile __at (0x007F94) unsigned char DM_BK2RH; /* DM breakpoint 2 register high byte */
volatile __at (0x007F95) unsigned char DM_BK2RL; /* DM breakpoint 2 register low byte */
volatile __at (0x007F96) unsigned char DM_CR1; /* DM Debug module control register 1 */
volatile __at (0x007F97) unsigned char DM_CR2; /* DM Debug module control register 2 */
volatile __at (0x007F98) unsigned char DM_CSR1;	/* DM Debug module control/status register 1 */
volatile __at (0x007F99) unsigned char DM_CSR2;	/* DM Debug module control/status register 2 */
volatile __at (0x007F9A) unsigned char DM_ENFCTR; /* DM enable function register */

volatile __xdata __at (0x004800) unsigned char OPT_ROP;	/* Memory readout protection (ROP). 0xAA: Disable readout protection (write access via SWIM protocol) */
volatile __xdata __at (0x004802) unsigned char OPT_UBC;	/* Size of the user boot code area. */
volatile __xdata __at (0x004808) unsigned char OPT_WDG;	/* Independent watchdog option */
volatile __xdata __at (0x004809) unsigned char OPT_CLOCK; /* Number of stabilization clock cycles for HSE and LSE oscillators */
volatile __xdata __at (0x00480A) unsigned char OPT_BOR;	/* Brownout reset */
volatile __xdata __at (0x00480B) unsigned short OPT_BL; /* Bootloader option 2 bytes */
/* option OPT_BL is checked by the boot ROM code after reset. Depending on content
of addresses 00 480B, 00 480C and 0x8000 (reset vector) the CPU jumps to the
bootloader or to the reset vector.  Refer to the UM0560 bootloader user manual
for more details. */


#endif
