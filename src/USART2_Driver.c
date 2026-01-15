/*
 * USART2_Driver.c
 *
 *  Created on: 24-Dec-2025
 *      Author: Kathirvel A
 */

#include "Usart2_Driver.h"


void USART2_GPIOInit(void){

	RCC->AHB1ENR |= GPIOA_Clock_Enable;

	GPIOA->MODER &= ~((0b11<<4) | (0b11<<6));

	GPIOA->MODER |= ((0b10<<4) | (0b10<<6));   // PA2- TX  PA3-RX

	GPIOA->PUPDR &= ~((0b11<<4) | (0b11<<6));

	GPIOA->AFRL &= ~((0x0F<<8) | (0x0F<<12));

	GPIOA->AFRL |= ((0x07<<8) | (0x07	<<12));

}

void USART2_Init(void){

	RCC->APB1ENR |= USART2_CLK;

	USART2->CR1 &= ~OVERSAM_16;     // Oversampling by 16

	USART2->CR1 &= ~BIT_Format_8;     // 8-Bit Data

	USART2->CR2 &= ~STOP_BIT_1;   // 1 STOP BIT

	USART2->BRR = MANTISSA | FRACTION;

	USART2->CR1 |= (TX_ON | RX_ON | USART_ON);

}

void USART2_Transmit_IT(USART2_Config *config,uint8_t *data,uint8_t size){

	if(config->busy == 1){
		return;
	}

	config->tdata = data;
    config->tlen  = size;
    config->Idx  = 0;
    config->busy = 1;


    USART2->CR1 |= Interrupt_RX_ON;  //TXE
}
