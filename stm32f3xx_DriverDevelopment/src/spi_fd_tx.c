/*
 * spi_tx.c
 *
 *  Created on: Aug 19, 2019
 *      Author: milin
 */


#include "stm32f302x.h"
#include <string.h>
/*
 * PB12 --> NSS
 * PB13 -->	SCK
 * PB14 --> MISO
 * PB15 --> MOSI
 * ALT FUN Mode ----> 5
 *
 */
void SPI2_GPIOInits(void){
	GPIO_Handle_t SPIPins;

	SPIPins.pGPIOx = GPIOB;
	SPIPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	SPIPins.GPIO_PinConfig.GPIO_PinAtlFunMode = 5;
	SPIPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PP;
	SPIPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	SPIPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	//SCLK
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	GPIO_Init(&SPIPins);
	//MISO
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_14;
	GPIO_Init(&SPIPins);
	//MOSI
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_15;
	GPIO_Init(&SPIPins);
	//NSS
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_12;
	GPIO_Init(&SPIPins);
}

void SPI2_Inits(void){
	SPI_Handle_t SPI2handle;

	SPI2handle.pSPIx = SPI2;
	SPI2handle.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;
	SPI2handle.SPIConfig.SPI_DeviceMode = SPI_MODE_MASTER;
	SPI2handle.SPIConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV2;
	SPI2handle.SPIConfig.SPI_CRC = SPI_DFF_8b;
	SPI2handle.SPIConfig.SPI_CPOL = SPI_CPOL_LOW;
	SPI2handle.SPIConfig.SPI_CPHA = SPI_CPHA_LOW;
	SPI2handle.SPIConfig.SPI_SSM = SPI_SSM_EN;

	SPI_Init(&SPI2handle);

}
int main(void){

	char user_data [] ="Hello World!";
	SPI2_GPIOInits();
	SPI2_Inits();
	// Avoid MODF Error
	SPI_SSIConfig(SPI2,ENABLE);
	//Enable SPI2 Peripheral
	SPI_PeriCtrl(SPI2,ENABLE);

	//SEND data
	SPI_SendData(SPI2,(uint8_t *)user_data,strlen(user_data));

	SPI_PeriCtrl(SPI2,DISABLE);

	while(1);
	return 0;
}

void delay(void){
	for(uint32_t i =0; i<=50000/2;i++);
}
