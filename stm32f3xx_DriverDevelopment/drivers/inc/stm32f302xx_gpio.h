/*
 * stm32f302xx_gpio.h
 *
 *  Created on: Aug 8, 2019
 *      Author: milin
 */

#ifndef INC_STM32F302XX_GPIO_H_
#define INC_STM32F302XX_GPIO_H_

#include "stm32f302x.h"

#define GPIO_PIN_0	0
#define GPIO_PIN_1	1
#define GPIO_PIN_2	2
#define GPIO_PIN_4	4
#define GPIO_PIN_5	5
#define GPIO_PIN_6	6
#define GPIO_PIN_7	7
#define GPIO_PIN_8	8
#define GPIO_PIN_9	9
#define GPIO_PIN_10	10
#define GPIO_PIN_11	11
#define GPIO_PIN_12	12
#define GPIO_PIN_13	13
#define GPIO_PIN_14	14
#define GPIO_PIN_15	15

#define GPIO_MODE_IN		0
#define GPIO_MODE_OUT		1
#define GPIO_MODE_ALTFN		2
#define GPIO_MODE_ANALOG	3
#define GPIO_MODE_IT_FT		4
#define GPIO_MODE_IT_RT		5
#define GPIO_MODE_IT_RFT	6

#define GPIO_OTYPE_PP	0
#define GPIO_OTYPE_OD	1

#define GPIO_SPEED_LOW 		0
#define GPIO_SPEED_MEDIUM 	1
#define GPIO_SPEED_HIGH		2

#define GPIO_NO_PUPD	0
#define GPIO_PU			1
#define GPIO_PD			2

typedef struct{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAtlFunMode;
}GPIO_PinConfig_t;


typedef struct{
	GPIO_TypeDef *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;



/******************************
 * Supported API's
 *
 * ****************************
 */

/*Clk Setup*/
void GPIO_PeriClkCtrl(GPIO_TypeDef *pGPIOx, uint8_t status);

/*
 * Init/DeInit IO
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_TypeDef *pGPIOx);

/*
 * Read Write Operations
 */
uint8_t GPIO_ReadFromInputPin(GPIO_TypeDef *pGPIOx,uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_TypeDef *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_TypeDef *pGPIOx,uint16_t PinNumber,uint16_t Value);
void GPIO_WriteToOutputPort(GPIO_TypeDef *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_TypeDef *pGPIOx,uint8_t PinNumber);

/*
 * IRQ Config
 */
void GPIO_IRQITConfig(uint8_t IRQNumber, uint8_t status);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);

#endif /* INC_STM32F302XX_GPIO_H_ */
