/*
 * USART2_Driver.c
 *
 *  Created on: 24-Dec-2025
 *      Author: Kathirvel A
 */

#include "Usart2_Driver.h"


void USART2_GPIOInit(void){

	RCC->AHB1ENR |= (1<<0);

	GPIOA->MODER &= ~((0b11<<4) | (0b11<<6));

	GPIOA->MODER |= ((0b10<<4) | (0b10<<6));   // PA2- TX  PA3-RX

	GPIOA->PUPDR &= ~((0b11<<4) | (0b11<<6));

	GPIOA->AFRL &= ~((0x0F<<8) | (0x0F<<12));

	GPIOA->AFRL |= ((0x07<<8) | (0x07	<<12));

}

void USART2_Init(void){

	RCC->APB1ENR |= (1<<17);

	USART2->CR1 &= ~(1<<15);     // Oversampling by 16

	USART2->CR1 &= ~(1<<12);     // 8-Bit Data

	USART2->CR2 &= ~(0b11<<12);   // 1 STOP BIT

	USART2->BRR = (104<<4) | 3;

	USART2->CR1 |= ((1<<13) | (1<<3) | (1<<2));

}

void USART2_Transmit(uint8_t *tdata,uint8_t size){

	while(size){

		while(!(USART2->SR & (1<<7))){
			//TXE
		}

		 USART2->DR = *tdata++;



		size--;

	}
	while(!(USART2->SR & (1<<6)));

}

void USART2_Transmit_IT(USART2_Config *config,uint8_t *data,uint8_t size){

	if(config->busy == 1){
		return;
	}

	config->tdata = data;
    config->tlen  = size;
    config->Idx  = 0;
    config->busy = 1;


    USART2->CR1 |= (1<<7);  //TXE
}
