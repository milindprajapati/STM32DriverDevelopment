/*
 * stm32f302x.h
 *
 *  Created on: Aug 8, 2019
 *      Author: milin
 */

#ifndef STM32F302X_H_
#define STM32F302X_H_

#include <stdint.h>



#define ENABLE 1
#define DISABLE 0
#define SET ENABLE
#define RESET DISABLE
#define GPIO_PIN_SET SET
#define GPIO_PIN_RESET RESET
#define __vo volatile
#define FLAG_RESET RESET
#define FLAG_SET SET
/*
 * Processor Specific Registers
 *
 *
 */

#define NVIC_ISER0	((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1	((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2	((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3	((__vo uint32_t*)0xE000E10C)

#define NVIC_ICER0	((__vo uint32_t*)0xE000E180)
#define NVIC_ICER1	((__vo uint32_t*)0xE000E184)
#define NVIC_ICER2	((__vo uint32_t*)0xE000E188)
#define NVIC_ICER3	((__vo uint32_t*)0xE000E18C)

#define NVIC_PR_BASE	((__vo uint32_t*)0xE000E400)
#define NO_PR_BITS 		4

#define NVIC_IRQPR_0 	0
#define NVIC_IRQPR_1	1
#define NVIC_IRQPR_2	2
#define NVIC_IRQPR_3	3
#define NVIC_IRQPR_4	4
#define NVIC_IRQPR_5	5
#define NVIC_IRQPR_6	6
#define NVIC_IRQPR_7	7
#define NVIC_IRQPR_8	8
#define NVIC_IRQPR_9	9
#define NVIC_IRQPR_10	10
#define NVIC_IRQPR_11	11
#define NVIC_IRQPR_12	12
#define NVIC_IRQPR_13	13
#define NVIC_IRQPR_14	14
#define NVIC_IRQPR_15	15

/*< Base Address of Memory >*/
#define FLASH_BASE            ((uint32_t)0x08000000) /*!< FLASH base address in the alias region */
#define SRAM_BASE             ((uint32_t)0x20000000) /*!< SRAM base address in the alias region */
#define PERIPH_BASE           ((uint32_t)0x40000000) /*!< Peripheral base address in the alias region */
#define SRAM_BB_BASE          ((uint32_t)0x22000000) /*!< SRAM base address in the bit-band region */
#define PERIPH_BB_BASE        ((uint32_t)0x42000000) /*!< Peripheral base address in the bit-band region */

/*!< Peripheral memory map> */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000)
#define AHB3PERIPH_BASE       (PERIPH_BASE + 0x10000000)

/*!< APB1 peripherals */
#define SPI2_BASE             (APB1PERIPH_BASE + 0x00003800)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x00003C00)
#define USART2_BASE           (APB1PERIPH_BASE + 0x00004400)
#define USART3_BASE           (APB1PERIPH_BASE + 0x00004800)
#define I2C3_BASE             (APB1PERIPH_BASE + 0x00007800)

/*!< APB2 peripherals */
#define SPI1_BASE             (APB2PERIPH_BASE + 0x00003000)
#define USART1_BASE           (APB2PERIPH_BASE + 0x00003800)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x00000400)
#define SYSCFG_BASE           (APB2PERIPH_BASE + 0x00000000)

/*!< AHB1 peripherals */
#define RCC_BASE              (AHB1PERIPH_BASE + 0x00001000)
#define FLASH_R_BASE          (AHB1PERIPH_BASE + 0x00002000) /*!< Flash registers base address */
#define OB_BASE               ((uint32_t)0x1FFFF800)     /*!< Flash Option Bytes base address */
#define CRC_BASE              (AHB1PERIPH_BASE + 0x00003000)
#define TSC_BASE              (AHB1PERIPH_BASE + 0x00004000)

/*!< AHB2 peripherals */
#define GPIOA_BASE            (AHB2PERIPH_BASE + 0x0000)
#define GPIOB_BASE            (AHB2PERIPH_BASE + 0x0400)
#define GPIOC_BASE            (AHB2PERIPH_BASE + 0x0800)
#define GPIOD_BASE            (AHB2PERIPH_BASE + 0x0C00)
#define GPIOE_BASE            (AHB2PERIPH_BASE + 0x1000)
#define GPIOF_BASE            (AHB2PERIPH_BASE + 0x1400)

#define RCC                 ((RCC_TypeDef *) RCC_BASE)
#define USART1              ((USART_TypeDef *) USART1_BASE)
#define USART2              ((USART_TypeDef *) USART2_BASE)
#define USART3              ((USART_TypeDef *) USART3_BASE)
#define I2C1                ((I2C_TypeDef *) I2C1_BASE)
#define I2C2                ((I2C_TypeDef *) I2C2_BASE)
#define I2C3                ((I2C_TypeDef *) I2C3_BASE)
#define SPI1                ((SPI_TypeDef *) SPI1_BASE)
#define SPI2                ((SPI_TypeDef *) SPI2_BASE)
#define SPI3                ((SPI_TypeDef *) SPI3_BASE)
#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)

#define EXTI 				((EXTI_TypeDef *) EXTI_BASE)
#define SYSCFG              ((SYSCFG_TypeDef *) SYSCFG_BASE)

#define GPIO_BASEADDR_TO_CODE(x) 	((x == GPIOA)? 0 :\
									(x == GPIOB) ? 1 :\
									(x == GPIOC) ? 2 :\
									(x == GPIOD) ? 3 :\
									(x == GPIOE) ? 4 :\
									(x == GPIOF) ? 5 : 0)
/*
 * IRQ number of STM32F302xx
 */
#define IRQ_NO_EXTI0		6
#define IRQ_NO_EXTI1		7
#define IRQ_NO_EXTI2		8
#define IRQ_NO_EXTI3		9
#define IRQ_NO_EXTI4		10
#define IRQ_NO_EXTI9_5		23
#define IRQ_NO_EXTI15_10	40
/*CLK Enable/Disable MACROs Definition*/

/*
 CLK Enable MACROs for GPIOx
*/

#define GPIOA_PCLK_EN() (RCC-> AHBENR  |= (1<<17))
#define GPIOB_PCLK_EN() (RCC-> AHBENR  |= (1<<18))
#define GPIOC_PCLK_EN() (RCC-> AHBENR  |= (1<<19))
#define GPIOD_PCLK_EN() (RCC-> AHBENR  |= (1<<20))
#define GPIOF_PCLK_EN() (RCC-> AHBENR  |= (1<<22))

/*
 CLK Enable MACROs for I2Cx
*/
#define I2C1_PCLK_EN() (RCC-> APB1ENR  |= (1<<21))
#define I2C2_PCLK_EN() (RCC-> APB1ENR  |= (1<<22))
#define I2C3_PCLK_EN() (RCC-> APB1ENR  |= (1<<30))

/*
 CLK Enable MACROs for SPIx
*/
#define SPI1_PCLK_EN() (RCC-> APB2ENR  |= (1<<12))
#define SPI2_PCLK_EN() (RCC-> APB1ENR  |= (1<<14))
#define SPI3_PCLK_EN() (RCC-> APB1ENR  |= (1<<15))

/*
 CLK Enable MACROs for USARTx
*/
#define USART1_PCLK_EN() (RCC-> APB2ENR  |= (1<<14))
#define USART2_PCLK_EN() (RCC-> APB1ENR  |= (1<<17))
#define USART3_PCLK_EN() (RCC-> APB1ENR  |= (1<<18))

/*
 CLK Enable MACROs for SYSCFG
*/
#define SYSCFG_PCLK_EN() (RCC-> APB2ENR  |= (1<<0))

/*
 CLK Disable MACROs for GPIOx
*/

#define GPIOA_PCLK_DI() (RCC-> AHBENR  &= ~(1<<17))
#define GPIOB_PCLK_DI() (RCC-> AHBENR  &= ~(1<<18))
#define GPIOC_PCLK_DI() (RCC-> AHBENR  &= ~(1<<19))
#define GPIOD_PCLK_DI() (RCC-> AHBENR  &= ~(1<<20))
#define GPIOF_PCLK_DI() (RCC-> AHBENR  &= ~(1<<22))

/*
 CLK Disable MACROs for I2Cx
*/
#define I2C1_PCLK_DI() (RCC-> APB1ENR  &= ~(1<<21))
#define I2C2_PCLK_DI() (RCC-> APB1ENR  &= ~(1<<22))
#define I2C3_PCLK_DI() (RCC-> APB1ENR  &= ~(1<<30))

/*
 CLK Disable MACROs for SPIx
*/
#define SPI1_PCLK_DI() (RCC-> APB2ENR  &= ~(1<<12))
#define SPI2_PCLK_DI() (RCC-> APB1ENR  &= ~(1<<14))
#define SPI3_PCLK_DI() (RCC-> APB1ENR  &= ~(1<<15))

/*
 CLK Disable MACROs for USARTx
*/
#define USART1_PCLK_DI() (RCC-> APB2ENR  &= ~(1<<14))
#define USART2_PCLK_DI() (RCC-> APB1ENR  &= ~(1<<17))
#define USART3_PCLK_DI() (RCC-> APB1ENR  &= ~(1<<18))

/*
 * CLK Disable MACROs for SYSCFG
*/
#define SYSCFG_PCLK_DI() (RCC-> APB2ENR  &= ~(1<<0))


/*
 * GPIOx Reset Macros
 */

#define GPIOA_REG_RST() do{(RCC-> AHBRSTR  |= (1<<17)); 	(RCC-> AHBRSTR  &=~ (1<<17));}while(0)
#define GPIOB_REG_RST() do{(RCC-> AHBRSTR  |= (1<<18));		(RCC-> AHBRSTR  &=~ (1<<18));}while(0)
#define GPIOC_REG_RST() do{(RCC-> AHBRSTR  |= (1<<19));		(RCC-> AHBRSTR  &=~ (1<<19));}while(0)
#define GPIOD_REG_RST() do{(RCC-> AHBRSTR  |= (1<<20));		(RCC-> AHBRSTR  &=~ (1<<20));}while(0)
#define GPIOF_REG_RST() do{(RCC-> AHBRSTR  |= (1<<22));		(RCC-> AHBRSTR  &=~ (1<<22));}while(0)

/*
 * Perpheral Register Struct For GPIO
 */
typedef struct{
	  __vo uint32_t MODER;        /*!< GPIO port mode register,                                  Address offset: 0x00 */
	  __vo uint16_t OTYPER;       /*!< GPIO port output type register,                           Address offset: 0x04 */
	  uint16_t RESERVED0;         /*!< Reserved,                                                                 0x06 */
	  __vo uint32_t OSPEEDR;      /*!< GPIO port output speed register,                          Address offset: 0x08 */
	  __vo uint32_t PUPDR;        /*!< GPIO port pull-up/pull-down register,                     Address offset: 0x0C */
	  __vo uint16_t IDR;          /*!< GPIO port input data register,                            Address offset: 0x10 */
	  uint16_t RESERVED1;         /*!< Reserved,                                                                 0x12 */
	  __vo uint16_t ODR;          /*!< GPIO port output data register,                           Address offset: 0x14 */
	  uint16_t RESERVED2;         /*!< Reserved,                                                                 0x16 */
	  __vo uint32_t BSRR;         /*!< GPIO port bit set/reset registerBSRR,                     Address offset: 0x18 */
	  __vo uint32_t LCKR;         /*!< GPIO port configuration lock register,                    Address offset: 0x1C */
	  __vo uint32_t AFR[2];       /*!< GPIO alternate function low register,                Address offset: 0x20-0x24 */
	  __vo uint16_t BRR;          /*!< GPIO bit reset register,                                  Address offset: 0x28 */
	  uint16_t RESERVED3;         /*!< Reserved,  */
}GPIO_TypeDef;

/*
 * Perpheral Register Struct For RCC
 */
typedef struct{
		__vo uint32_t CR;         /*!< RCC clock control register,                                  Address offset: 0x00 */
	  __vo uint32_t CFGR;       /*!< RCC clock configuration register,                            Address offset: 0x04 */
	  __vo uint32_t CIR;        /*!< RCC clock interrupt register,                                Address offset: 0x08 */
	  __vo uint32_t APB2RSTR;   /*!< RCC APB2 peripheral reset register,                          Address offset: 0x0C */
	  __vo uint32_t APB1RSTR;   /*!< RCC APB1 peripheral reset register,                          Address offset: 0x10 */
	  __vo uint32_t AHBENR;     /*!< RCC AHB peripheral clock register,                           Address offset: 0x14 */
	  __vo uint32_t APB2ENR;    /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x18 */
	  __vo uint32_t APB1ENR;    /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x1C */
	  __vo uint32_t BDCR;       /*!< RCC Backup domain control register,                          Address offset: 0x20 */
	  __vo uint32_t CSR;        /*!< RCC clock control & status register,                         Address offset: 0x24 */
	  __vo uint32_t AHBRSTR;    /*!< RCC AHB peripheral reset register,                           Address offset: 0x28 */
	  __vo uint32_t CFGR2;      /*!< RCC clock configuration register 2,                          Address offset: 0x2C */
	  __vo uint32_t CFGR3;      /*!< RCC clock configuration register 3,                          Address offset: 0x30 */
}RCC_TypeDef;

/*
 * Perpheral Register Struct For EXTI
 */

typedef struct {
	__vo uint32_t IMR;
	  __vo uint32_t EMR;
	  __vo uint32_t RTSR;
	  __vo uint32_t FTSR;
	  __vo uint32_t SWIER;
	  __vo uint32_t PR;
	  uint32_t      RESERVED1;
	  uint32_t      RESERVED2;
	  __vo uint32_t IMR2;
	  __vo uint32_t EMR2;
	  __vo uint32_t RTSR2;
	  __vo uint32_t FTSR2;
	  __vo uint32_t SWIER2;
	  __vo uint32_t PR2;
}EXTI_TypeDef;

/**
  *  Perpheral Register Struct for SysConfig
  */

typedef struct
{
  __vo uint32_t CFGR1;      /*!< SYSCFG configuration register 1,                   Address offset: 0x00 */
  __vo uint32_t RCR;        /*!< SYSCFG CCM SRAM protection register,               Address offset: 0x04 */
  __vo uint32_t EXTICR[4];  /*!< SYSCFG external interrupt configuration registers, Address offset: 0x14-0x08 */
  __vo uint32_t CFGR2;      /*!< SYSCFG configuration register 2,                    Address offset: 0x18 */
  __vo uint32_t RESERVED0;  /*!< Reserved,                                                           0x1C */
  __vo uint32_t RESERVED1;  /*!< Reserved,                                                          0x20 */
  __vo uint32_t RESERVED2;  /*!< Reserved,                                                          0x24 */
  __vo uint32_t RESERVED4;  /*!< Reserved,                                                          0x28 */
  __vo uint32_t RESERVED5;  /*!< Reserved,                                                          0x2C */
  __vo uint32_t RESERVED6;  /*!< Reserved,                                                          0x30 */
  __vo uint32_t RESERVED7;  /*!< Reserved,                                                          0x34 */
  __vo uint32_t RESERVED8;  /*!< Reserved,                                                          0x38 */
  __vo uint32_t RESERVED9;  /*!< Reserved,                                                          0x3C */
  __vo uint32_t RESERVED10; /*!< Reserved,                                                          0x40 */
  __vo uint32_t RESERVED11; /*!< Reserved,                                                          0x44 */
  __vo uint32_t RESERVED12; /*!< Reserved,                                                          0x48 */
  __vo uint32_t RESERVED13; /*!< Reserved,                                                          0x4C */
  __vo uint32_t CFGR3;      /*!< SYSCFG configuration register 3,                    Address offset: 0x50 */
} SYSCFG_TypeDef;

typedef struct
{
  __vo uint16_t CR1;      /*!< SPI Control register 1 (not used in I2S mode),       Address offset: 0x00 */
  uint16_t  RESERVED0;    /*!< Reserved, 0x02                                                            */
  __vo uint16_t CR2;      /*!< SPI Control register 2,                              Address offset: 0x04 */
  uint16_t  RESERVED1;    /*!< Reserved, 0x06                                                            */
  __vo uint16_t SR;       /*!< SPI Status register,                                 Address offset: 0x08 */
  uint16_t  RESERVED2;    /*!< Reserved, 0x0A                                                            */
  __vo uint16_t DR;       /*!< SPI data register,                                   Address offset: 0x0C */
  uint16_t  RESERVED3;    /*!< Reserved, 0x0E                                                            */
  __vo uint16_t CRCPR;    /*!< SPI CRC polynomial register (not used in I2S mode),  Address offset: 0x10 */
  uint16_t  RESERVED4;    /*!< Reserved, 0x12                                                            */
  __vo uint16_t RXCRCR;   /*!< SPI Rx CRC register (not used in I2S mode),          Address offset: 0x14 */
  uint16_t  RESERVED5;    /*!< Reserved, 0x16                                                            */
  __vo uint16_t TXCRCR;   /*!< SPI Tx CRC register (not used in I2S mode),          Address offset: 0x18 */
  uint16_t  RESERVED6;    /*!< Reserved, 0x1A                                                            */
  __vo uint16_t I2SCFGR;  /*!< SPI_I2S configuration register,                      Address offset: 0x1C */
  uint16_t  RESERVED7;    /*!< Reserved, 0x1E                                                            */
  __vo uint16_t I2SPR;    /*!< SPI_I2S prescaler register,                          Address offset: 0x20 */
  uint16_t  RESERVED8;    /*!< Reserved, 0x22*/
  } SPI_TypeDef;


typedef struct
{
  __vo uint32_t CR1;      /*!< I2C Control register 1,            Address offset: 0x00 */
  __vo uint32_t CR2;      /*!< I2C Control register 2,            Address offset: 0x04 */
  __vo uint32_t OAR1;     /*!< I2C Own address 1 register,        Address offset: 0x08 */
  __vo uint32_t OAR2;     /*!< I2C Own address 2 register,        Address offset: 0x0C */
  __vo uint32_t TIMINGR;  /*!< I2C Timing register,               Address offset: 0x10 */
  __vo uint32_t TIMEOUTR; /*!< I2C Timeout register,              Address offset: 0x14 */
  __vo uint32_t ISR;      /*!< I2C Interrupt and status register, Address offset: 0x18 */
  __vo uint32_t ICR;      /*!< I2C Interrupt clear register,      Address offset: 0x1C */
  __vo uint32_t PECR;     /*!< I2C PEC register,                  Address offset: 0x20 */
  __vo uint32_t RXDR;     /*!< I2C Receive data register,         Address offset: 0x24 */
  __vo uint32_t TXDR;     /*!< I2C Transmit data register,        Address offset: 0x28 */
}I2C_TypeDef;


/*
 * Bit position definitions SPI_CR1
 */
#define SPI_CR1_CPHA     				 0
#define SPI_CR1_CPOL      				 1
#define SPI_CR1_MSTR     				 2
#define SPI_CR1_BR   					 3
#define SPI_CR1_SPE     				 6
#define SPI_CR1_LSBFIRST   			 	 7
#define SPI_CR1_SSI     				 8
#define SPI_CR1_SSM      				 9
#define SPI_CR1_RXONLY      		 	10
#define SPI_CR1_CRCL     			 	11
#define SPI_CR1_CRCNEXT   			 	12
#define SPI_CR1_CRCEN   			 	13
#define SPI_CR1_BIDIOE     			 	14
#define SPI_CR1_BIDIMODE      			15

/*
 * Bit position definitions SPI_CR2
 */
#define SPI_CR2_RXDMAEN		 			0
#define SPI_CR2_TXDMAEN				 	1
#define SPI_CR2_SSOE				 	2
#define SPI_CR2_NSSP				 	3
#define SPI_CR2_FRF						4
#define SPI_CR2_ERRIE					5
#define SPI_CR2_RXNEIE				 	6
#define SPI_CR2_TXEIE					7


/*
 * Bit position definitions SPI_SR
 */
#define SPI_SR_RXNE						0
#define SPI_SR_TXE				 		1
#define SPI_SR_CHSIDE				 	2
#define SPI_SR_UDR					 	3
#define SPI_SR_CRCERR				 	4
#define SPI_SR_MODF					 	5
#define SPI_SR_OVR					 	6
#define SPI_SR_BSY					 	7
#define SPI_SR_FRE					 	8

#include "stm32f302xx_gpio.h"
#include "stm32f302xx_spi.h"
#include "stm32f302xx_i2c.h"
#include "stm32f302xx_usart.h"

#endif /* STM32F302X_H_ */
