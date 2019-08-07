/*
 * stm32f302xx_gpio.h
 *
 *  Created on: Aug 6, 2019
 *      Author: milin
 */

#ifndef INC_STM32F302XX_GPIO_H_
#define INC_STM32F302XX_GPIO_H_

#include "stm32f302xx.h"


typedef struct{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAtlFunMode;
}GPIO_PinConfig_t;


typedef struct{
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;


#endif /* INC_STM32F302XX_GPIO_H_ */


/******************************
 * Supported API's
 *
 * ****************************
 */

/*Clk Setup*/
void GPIO_PeriClkCtrl(GPIO_RegDef_t *pGPIOx, uint8_t status);

/*
 * Init/DeInit IO
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Read Write Operations
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);

/*
 * IRQ Config
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t status);
void GPIO_IRQHandling(uint8_t PinNumber);
