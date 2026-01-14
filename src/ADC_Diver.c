
#include "ADC_Driver.h"




void ADC1_GPIO_Init(void){

    RCC->AHB1ENR |= (1<<0);

    GPIOA->MODER &= ~(0b11<<0);

    GPIOA->MODER |= (0b11<<0);

    GPIOA->PUPDR &= ~(0b11<<0);

}

void ADC1_Init(void){
	RCC->APB2ENR |= (1<<8);

	ADC1->SQR3 = 0;   // channel 0

	ADC1->CR2 |= (1<<0);

	 for(volatile int i=0;i<1000;i++);
}

uint16_t ADC1_ReadVal(void){

	ADC1->CR2 |= (1<<30);

	while(!(ADC1->SR & (1<<1)));

    return ADC1->DR & 0x0FFF;

}

void ADC_Val(uint16_t adc,logdata *log)
{

    log->temp = (adc * 330UL) / 4095;
}
