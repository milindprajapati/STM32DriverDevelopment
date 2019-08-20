/*
 * stm32f302xx_spi.c
 *
 *  Created on: Aug 16, 2019
 *      Author: milin
 */

#include "stm32f302xx_spi.h"

/*Clk Setup*/
void SPI_PeriClkCtrl(SPI_TypeDef *pSPIx, uint8_t status){


	if(status == ENABLE){
			if(pSPIx==SPI1){
				SPI1_PCLK_EN();
			}
			else if(pSPIx==SPI2){
				SPI2_PCLK_EN();
			}
			else if(pSPIx==SPI3){
				SPI3_PCLK_EN();
			}
		}
		else{
			if(pSPIx==SPI1){
				SPI1_PCLK_DI();
			}
			else if(pSPIx==SPI2){
				SPI2_PCLK_DI();
			}
			else if(pSPIx==SPI3){
				SPI3_PCLK_DI();
			}

		}
}

/*
 * Init/DeInit IO
 */
void SPI_Init(SPI_Handle_t *pSPIHandle){

	SPI_PeriClkCtrl(pSPIHandle ->pSPIx,ENABLE);

	uint32_t tempreg =0;
	tempreg |= pSPIHandle -> SPIConfig.SPI_DeviceMode << 2;
	if(pSPIHandle -> SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD){
		tempreg &= ~(1 << 15);
	}else if(pSPIHandle -> SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD){
		tempreg |= (1 << 15);
	}else if(pSPIHandle -> SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_RX){
		tempreg &= ~(1 << 15);
		tempreg |= (1 << 10);
	}

	tempreg |= pSPIHandle -> SPIConfig.SPI_SclkSpeed << 3;
	tempreg |= pSPIHandle -> SPIConfig.SPI_CRC << 11;
	tempreg |= pSPIHandle -> SPIConfig.SPI_CPOL<<1;
	tempreg |= pSPIHandle -> SPIConfig.SPI_CPHA<<0;
	tempreg |= pSPIHandle -> SPIConfig.SPI_SSM << SPI_CR1_SSM;
	pSPIHandle -> pSPIx -> CR1 = tempreg;
}
void SPI_DeInit(SPI_TypeDef *pSPIx){

}

/*
 * Data Send Receive
 */
void SPI_SendData(SPI_TypeDef *pSPIx, uint8_t *pTxBuffer, uint32_t len){
	while(len>0){
		while(SPI_GetFlagStatus(pSPIx,SPI_TXE_FLAG) == FLAG_RESET);

		if((pSPIx -> CR1 & (1 << SPI_CR1_CRCL))){
			pSPIx -> DR = *((uint16_t*) pTxBuffer);
			len--;
			len--;
			(uint16_t*) pTxBuffer++;
		}else{
			pSPIx -> DR = *pTxBuffer;
			len--;
			pTxBuffer++;
		}
	}
}

uint8_t SPI_GetFlagStatus(SPI_TypeDef *pSPIx, uint32_t FlagName){
	if(pSPIx -> SR & FlagName){
		return FLAG_SET;
	}
	return FLAG_RESET;
}
void SPI_ReceiveData(SPI_TypeDef *pSPIx, uint8_t *pRxBuffer, uint32_t len){
	while(len>0){
			while(SPI_GetFlagStatus(pSPIx,SPI_RXNE_FLAG) == FLAG_RESET);

			if((pSPIx -> CR1 & (1 << SPI_CR1_CRCL))){
				 *((uint16_t*) pRxBuffer) = pSPIx -> DR ;
				len--;
				len--;
				(uint16_t*) pRxBuffer++;
			}else{
				 *pRxBuffer = pSPIx -> DR ;
				len--;
				pRxBuffer++;
			}
		}
}


/*
 * IRQ Config and ISR handling
 */
void SPI_IRQITConfig(uint8_t IRQNumber, uint8_t status){

}

void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority){

}

void SPI_IRQHandling(SPI_Handle_t *pSPIHandle){

}

/*
 * Other Peripheral API's
 *
 */
void SPI_PeriCtrl(SPI_TypeDef *pSPIx, uint8_t status){
	if(status == ENABLE){
		pSPIx -> CR1 |= (1 << SPI_CR1_SPE);
	}else{
		pSPIx -> CR1 &= ~(1 << SPI_CR1_SPE);

	}
}
void SPI_SSIConfig(SPI_TypeDef *pSPIx, uint8_t status){
	if(status == ENABLE){
		pSPIx -> CR1 |= (1 << SPI_CR1_SSI);
	}else{
		pSPIx -> CR1 &= ~(1 << SPI_CR1_SSI);

	}
}
