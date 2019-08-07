/*
 * stm32f302xx_gpio.c
 *
 *  Created on: Aug 6, 2019
 *      Author: milin
 */


#include "stm32f302xx_gpio.h"

/*Clk Setup*/
void GPIO_PeriClkCtrl(GPIO_RegDef_t *pGPIOx, uint8_t status){

	if(status == ENABLE){
		if(pGPIOx==GPIOA){
			GPIOA_PCLK_EN()
		}
		else if(pGPIOx==GPIOB){
			GPIOB_PCLK_EN()
		}
		else if(pGPIOx==GPIOC){
			GPIOC_PCLK_EN()
		}
		else if(pGPIOx==GPIOD){
			GPIOD_PCLK_EN()
		}
		else if(pGPIOx==GPIOF){
			GPIOF_PCLK_EN()
		}
		else{}
	}
	else{
		f(pGPIOx==GPIOA){
					GPIOA_PCLK_DI()
				}
				else if(pGPIOx==GPIOB){
					GPIOB_PCLK_DI()
				}
				else if(pGPIOx==GPIOC){
					GPIOC_PCLK_DI()
				}
				else if(pGPIOx==GPIOD){
					GPIOD_PCLK_DI()
				}
				else if(pGPIOx==GPIOF){
					GPIOF_PCLK_DI()
				}
				else{}

	}

}

/*
 * Init/DeInit IO
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle){


}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){


}

/*
 * Read Write Operations
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber){

}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){


}
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t Value){


}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value){


}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber){


}

/*
 * IRQ Config
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t status){


}
void GPIO_IRQHandling(uint8_t PinNumber){


}