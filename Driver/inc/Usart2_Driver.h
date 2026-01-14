/*
 * Usart2_Driver.h
 *
 *  Created on: 24-Dec-2025
 *      Author: Kathirvel A
 */

#ifndef USART2_DRIVER_H_
#define USART2_DRIVER_H_
#include "stm32f411retx_Driver.h"
#include "stdint.h"

typedef struct
{
	uint8_t *tdata;
	uint8_t Idx;
	uint8_t tlen;
	uint8_t busy;

}USART2_Config;


void USART2_GPIOInit(void);
void USART2_Init(void);
void USART2_Transmit(uint8_t *tdata,uint8_t size);
void USART2_Transmit_IT(USART2_Config *config,uint8_t *data,uint8_t size);


#endif /* USART2_DRIVER_H_ */
