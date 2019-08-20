#include "stm32f302x.h"
#include <string.h>
void led_write(void);
void buttonIT(void);
void delay(void);

int main(void){

	led_write();
	buttonIT();
	while(1);
	return 0;
}



void led_write(void){
	GPIO_Handle_t led;
	memset(&led,0,sizeof(led));
	GPIO_PeriClkCtrl(GPIOB, ENABLE);

	led.pGPIOx = GPIOB;
	led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	led.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	led.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PP;
	led.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_Init(&led);
	GPIO_WriteToOutputPin(GPIOB,13,GPIO_PIN_SET);

}

void buttonIT(void){

		GPIO_Handle_t btn;
		memset(&btn,0,sizeof(btn));
		GPIO_PeriClkCtrl(GPIOC, ENABLE);

		btn.pGPIOx = GPIOC;
		btn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_13;
		btn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
		btn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
		btn.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PP;
		btn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PU;
		GPIO_Init(&btn);
		GPIO_WriteToOutputPin(GPIOC,13,GPIO_PIN_SET);
		GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10, NVIC_IRQPR_15);
		GPIO_IRQITConfig(IRQ_NO_EXTI15_10,ENABLE);

		while(1);

}

void EXTI15_10_IRQHandler(void){
	delay();
	GPIO_IRQHandling(GPIO_PIN_13);
	GPIO_ToggleOutputPin(GPIOB,GPIO_PIN_13);
}
void delay(void){
	for(uint32_t i =0; i<=50000/2;i++);
}
