
#include "ADC_Driver.h"




void ADC1_GPIO_Init(void){

    RCC->AHB1ENR |= GPIOA_Clock_Enable;

    GPIOA->MODER &= ~Analog_Mode;

    GPIOA->MODER |= Analog_Mode;

    GPIOA->PUPDR &= ~(0b11<<0);

}

void ADC1_Init(void){

	RCC->APB2ENR |= ADC_Clock_Enable;

	ADC1->SQR3 = 0;   // channel 0  ie A0

	ADC1->CR2 |= ADC_Enable;

	 for(volatile int i=0;i<1000;i++);   // Delay for ADC ON
}

uint16_t ADC1_ReadVal(void){

	ADC1->CR2 |= ADC_Conversion_Init;

	while(!(ADC1->SR & ADC_End_Coversion));

    return ADC1->DR & ADC_Mask;

}

void ADC_Val(uint16_t adc,logdata *log)
{

    log->temp = (adc * 330UL) / 4095;
}
