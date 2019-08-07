/*
 * stm32f302xx.h
 *
 *  Created on: Aug 6, 2019
 *      Author: milin
 */

#ifndef INC_STM32F302XX_H_
#define INC_STM32F302XX_H_

#include <stdint.h>


#define ENABLE 1
#define DISABLE 0
#define SET ENABLE
#define RESET DISABLE
#define GPIO_PIN_SET SET
#define GPIO_PIN_RESET RESET
#define __vo volatile
/* Base Address of Memory */


#define FLASH_BASEADDR 		0x08000000U
#define SRAM_BASEADDR  		0x20000000U
#define ROM_BASEADDR		0x1FFFD800U

#define PERIPH_BASE				0x40000000U
#define APB1PERIPH_BASEADDR		PERIPH_BASE
#define	APB2PERIPH_BASEADDR		0x40010000U
#define	AHB1PERIPH_BASEADDR		0x40020000U
#define	AHB2PERIPH_BASEADDR		0x48000000U
#define	AHB3PERIPH_BASEADDR 	0x50000000U

#define RCC_BASEADDR	(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOA_BASEADDR 	(AHB2PERIPH_BASE+0x0000)
#define GPIOB_BASEADDR 	(AHB2PERIPH_BASE+0x0400)
#define GPIOC_BASEADDR 	(AHB2PERIPH_BASE+0x0800)
#define GPIOD_BASEADDR 	(AHB2PERIPH_BASE+0x0C00)
#define GPIOF_BASEADDR 	(AHB2PERIPH_BASE+0x1400)

#define I2C1_BASEADDR	(APB1PERIPH_BASE + 0X5400)
#define I2C2_BASEADDR	(APB1PERIPH_BASE + 0X5800)
#define I2C3_BASEADDR	(APB1PERIPH_BASE + 0X7800)

#define USART1_BASEADDR	(APB2PERIPH_BASE + 0X3800)
#define USART2_BASEADDR	(APB1PERIPH_BASE + 0X4400)
#define USART3_BASEADDR	(APB1PERIPH_BASE + 0X4800)

#define SPI2_BASEADDR	(APB1PERIPH_BASE + 0X3800)
#define SPI3_BASEADDR	(APB1PERIPH_BASE + 0X3C00)

#define EXTI_BASEADDR 	(APB2PERIPH_BASE + 0X0400)

#define RCC				((RCC_RegDef_t*)  RCC_BASEADDR)
#define GPIOA 			((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB 			((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC 			((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD 			((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOF 			((GPIO_RegDef_t*) GPIOF_BASEADDR)
//--------------------Peripheral Definiton  ----------------

typedef struct{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
}GPIO_RegDef_t;

typedef struct{
	__vo uint32_t CR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t STR;
	__vo uint32_t APB2RSTR;
	__vo uint32_t APB1RSTR;
	__vo uint32_t AHBENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t APB1ENR;
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	__vo uint32_t AHBRSTR;
	__vo uint32_t CFGR2;
	__vo uint32_t CFGR3;
}RCC_RegDef_t;

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
#define SPI2_PCLK_DI() (RCC-> APB1ENR  &= ~(1<<14))
#define SPI3_PCLK_DI() (RCC-> APB1ENR  &= ~(1<<15))

/*
 CLK Disable MACROs for USARTx
*/
#define USART1_PCLK_DI() (RCC-> APB2ENR  &= ~(1<<14))
#define USART2_PCLK_DI() (RCC-> APB1ENR  &= ~(1<<17))
#define USART3_PCLK_DI() (RCC-> APB1ENR  &= ~(1<<18))

/*
 CLK Disable MACROs for SYSCFG
*/

#endif /* INC_STM32F302XX_H_ */
