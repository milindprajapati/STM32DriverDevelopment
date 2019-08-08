#include "stm32f302x.h"
void delay(void){
	for(uint32_t i =0; i<=50000;i++);
}
int main(void){

	GPIO_Handle_t led;
	GPIO_PeriClkCtrl(GPIOB, ENABLE);

	led.pGPIOx = GPIOB;
	led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	led.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	led.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PP;
	led.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_Init(&led);
	while(1){
		GPIO_ToggleOutputPin(GPIOB,13);
		delay();
	}
	return 0;
}

