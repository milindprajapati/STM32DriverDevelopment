/*
 * stm32f302xx_gpio.c
 *
 *  Created on: Aug 8, 2019
 *      Author: milin
 */


/*
 * stm32f302xx_gpio.c
 *
 *  Created on: Aug 6, 2019
 *      Author: milin
 */


#include "stm32f302xx_gpio.h"

/*Clk Setup*/
void GPIO_PeriClkCtrl(GPIO_TypeDef *pGPIOx, uint8_t status){

	if(status == ENABLE){
		if(pGPIOx==GPIOA){
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx==GPIOB){
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx==GPIOC){
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx==GPIOD){
			GPIOD_PCLK_EN();
		}
		else if(pGPIOx==GPIOF){
			GPIOF_PCLK_EN();
		}
	}
	else{
		if(pGPIOx==GPIOA){
			GPIOA_PCLK_DI();
		}
		else if(pGPIOx==GPIOB){
			GPIOB_PCLK_DI();
		}
		else if(pGPIOx==GPIOC){
			GPIOC_PCLK_DI();
		}
		else if(pGPIOx==GPIOD){
			GPIOD_PCLK_DI();
		}
		else if(pGPIOx==GPIOF){
			GPIOF_PCLK_DI();
		}

	}

}

/*
 * Init/DeInit IO
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
	uint32_t temp=0;
	//Enable Clock #HelpUSER

	GPIO_PeriClkCtrl(pGPIOHandle -> pGPIOx,ENABLE);
	//Mode
	if(pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG){
			temp = pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode << (2 *pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
			pGPIOHandle->pGPIOx->MODER &= ~( 0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //clearing
			pGPIOHandle -> pGPIOx->MODER |= temp;

 	}
	else{
		//Intrrupt Mode Coding
		if(pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_IT_FT){
			//Configure FTSR
			EXTI -> FTSR |= (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber );

			//Clear RTSR Bit
			EXTI -> RTSR &= ~(1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber );

		}else if(pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_IT_RT){
			//Configure RTSR
			EXTI -> RTSR |= (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber );

			//Clear FTSR Bit
			EXTI -> FTSR &= ~(1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber );
		}else if(pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_IT_RFT){
			//Configure FTSR & RTSR

			EXTI -> FTSR |= (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber );
			EXTI -> RTSR |= (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber );
		}

		//Configure GPIO in SYSCFG_EXTI
		uint8_t temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 4 ;
		uint8_t temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 4;
		uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
		SYSCFG_PCLK_EN();
		SYSCFG -> EXTICR [temp1] = portcode << (temp2 * 4);
		//Enable EXTI for Interrupt
		EXTI -> IMR |= (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber );

	}
	//Speed
	temp=0;
	temp = pGPIOHandle -> GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OSPEEDR &= ~( 0x3 << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //clearing
	pGPIOHandle -> pGPIOx->OSPEEDR |= temp;

	//PuPd
	temp=0;
	temp = pGPIOHandle -> GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->PUPDR &= ~( 0x3 << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //clearing
	pGPIOHandle -> pGPIOx->PUPDR |= temp;

	//OType
	temp=0;
	temp = pGPIOHandle -> GPIO_PinConfig.GPIO_PinOPType << ( pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER &= ~( 0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //clearing
	pGPIOHandle -> pGPIOx->OTYPER |= temp;

	//ATL Func
	temp=0;
	if(pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ALTFN){
		uint8_t temp1, temp2;

				temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
				temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber  % 8;
				pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << ( 4 * temp2 ) ); //clearing
				pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAtlFunMode << ( 4 * temp2 ) );
	}
}
void GPIO_DeInit(GPIO_TypeDef *pGPIOx){
	if(pGPIOx==GPIOA){
		GPIOA_REG_RST();
	}
	else if(pGPIOx==GPIOB){
		GPIOB_REG_RST();
	}
	else if(pGPIOx==GPIOC){
		GPIOC_REG_RST();
	}
	else if(pGPIOx==GPIOD){
		GPIOD_REG_RST();
	}
	else if(pGPIOx==GPIOF){
		GPIOF_REG_RST();
	}

}

/*
 * Read Write Operations
 */
uint8_t GPIO_ReadFromInputPin(GPIO_TypeDef *pGPIOx,uint8_t PinNumber){
	uint8_t value;
	value = (uint8_t)((pGPIOx -> IDR >> PinNumber) & 0x00000001);
	return value;
}
uint16_t GPIO_ReadFromInputPort(GPIO_TypeDef *pGPIOx){
	uint16_t value;
	value = (uint16_t)(pGPIOx -> IDR);
	return value;
}
void GPIO_WriteToOutputPin(GPIO_TypeDef *pGPIOx,uint16_t PinNumber,uint16_t Value){
	if(Value == GPIO_PIN_SET){
		//write 1 to ODR
		uint16_t hex=0;
		hex |=(1 << PinNumber);
		pGPIOx -> ODR |= hex;

	}else{
		//write 0 to ODR
		pGPIOx -> ODR &= ~(1 << PinNumber);
	}

}
void GPIO_WriteToOutputPort(GPIO_TypeDef *pGPIOx, uint16_t Value){
	pGPIOx -> ODR = Value;

}
void GPIO_ToggleOutputPin(GPIO_TypeDef *pGPIOx,uint8_t PinNumber){

	pGPIOx -> ODR ^= (1 << PinNumber);
}

/*
 * IRQ Config
 */
void GPIO_IRQITConfig(uint8_t IRQNumber, uint8_t status){

	if(status == ENABLE){
		if(IRQNumber <= 31){

			//program ISER0
			*NVIC_ISER0 |= (1 << IRQNumber);

		}else if(IRQNumber > 31 && IRQNumber <64){

			//program ISER1
			*NVIC_ISER1 |= (1 << (IRQNumber % 32));
		}else if(IRQNumber >= 64 && IRQNumber <96){

			//program ISER2
			*NVIC_ISER3 |= (1 << (IRQNumber % 64));
		}
	}else{
		if(IRQNumber <= 31){

			//program ICER0
			*NVIC_ISER0 |= (1 << (IRQNumber));
		}else if(IRQNumber > 31 && IRQNumber <64){

			//program ICER1
			*NVIC_ISER1 |= (1 << (IRQNumber % 32));
		}else if(IRQNumber >= 64 && IRQNumber <96){

			//program ICER2
			*NVIC_ISER3 |= (1 << (IRQNumber % 64));
		}
	}

}

void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority){
	uint8_t iprx = IRQNumber/4;
	uint8_t iprx_sec = IRQNumber%4;
	uint8_t shift_amount = (iprx_sec*8)+(8-NO_PR_BITS);
	*(NVIC_PR_BASE + (iprx*4)) |= (IRQPriority << (shift_amount));
}
void GPIO_IRQHandling(uint8_t PinNumber){

	if(EXTI -> PR & (1 << PinNumber)){
		EXTI -> PR |= (1 << PinNumber);
	}

}
