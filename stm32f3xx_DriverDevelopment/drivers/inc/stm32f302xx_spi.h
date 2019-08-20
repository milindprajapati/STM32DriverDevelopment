/*
 * stm32f302xx_spi.h
 *
 *  Created on: Aug 16, 2019
 *      Author: milin
 */

#ifndef INC_STM32F302XX_SPI_H_
#define INC_STM32F302XX_SPI_H_

#include "stm32f302x.h"


#define SPI_MODE_MASTER 1
#define SPI_MODE_SLAVE	0

#define SPI_BUS_CONFIG_FD	0
#define SPI_BUS_CONFIG_HD	1
#define SPI_BUS_CONFIG_TX	2
#define SPI_BUS_CONFIG_RX	3

#define SPI_SCLK_SPEED_DIV2		0
#define SPI_SCLK_SPEED_DIV4		1
#define SPI_SCLK_SPEED_DIV8		2
#define SPI_SCLK_SPEED_DIV16	3
#define SPI_SCLK_SPEED_DIV32	4
#define SPI_SCLK_SPEED_DIV64	5
#define SPI_SCLK_SPEED_DIV128	6
#define SPI_SCLK_SPEED_DIV256	7

#define SPI_DFF_8b 	0
#define SPI_DFF_16b	1

#define SPI_CPOL_HIGH 	1
#define SPI_CPOL_LOW	0
#define SPI_CPHA_HIGH	1
#define SPI_CPHA_LOW	0

#define SPI_SSM_DI 	0
#define SPI_SSM_EN	1
/*
 * SPI related status flags definitions
 */
#define SPI_TXE_FLAG    ( 1 << SPI_SR_TXE)
#define SPI_RXNE_FLAG   ( 1 << SPI_SR_RXNE)
#define SPI_BUSY_FLAG   ( 1 << SPI_SR_BSY)
/*
 * SPI application states
 */
#define SPI_READY 					0
#define SPI_BUSY_IN_RX 				1
#define SPI_BUSY_IN_TX 				2

/*
 * Possible SPI Application events
 */
#define SPI_EVENT_TX_CMPLT   1
#define SPI_EVENT_RX_CMPLT   2
#define SPI_EVENT_OVR_ERR    3
#define SPI_EVENT_CRC_ERR    4

typedef struct{
	uint8_t SPI_DeviceMode;
	uint8_t SPI_BusConfig;
	uint8_t SPI_SclkSpeed;
	uint8_t SPI_CRC;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;
}SPI_Config_t;

typedef struct{
	SPI_TypeDef *pSPIx;
	SPI_Config_t SPIConfig;
}SPI_Handle_t;



/*Clk Setup*/
void SPI_PeriClkCtrl(SPI_TypeDef *pSPIx, uint8_t status);

/*
 * Init/DeInit IO
 */
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_TypeDef *pSPIx);

/*
 * Data Send Receive
 */
void SPI_SendData(SPI_TypeDef *pSPIx, uint8_t *pTxBuffer, uint32_t len);
void SPI_ReceiveData(SPI_TypeDef *pSPIx, uint8_t *pRxBuffer, uint32_t len);


/*
 * IRQ Config and ISR handling
 */
void SPI_IRQITConfig(uint8_t IRQNumber, uint8_t status);
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pSPIHandle);
uint8_t SPI_GetFlagStatus(SPI_TypeDef *pSPIx, uint32_t FlagName);

/*
 * Other Peri. APIs
 */

void SPI_PeriCtrl(SPI_TypeDef *pSPIx, uint8_t status);
void SPI_SSIConfig(SPI_TypeDef *pSPIx, uint8_t status);

#endif /* INC_STM32F302XX_SPI_H_ */
