/*
 * NVIC_Driver.c
 *
 *  Created on: 24-Dec-2025
 *      Author: Kathirvel A
 */

#include "NVIC_Driver.h"

void NVIC_EnableIRQ(uint8_t IQN){

	NVIC_ISERX_BASE[IQN/32] |= (1<<(IQN%32));

}

void NVIC_SetPriority(uint8_t IQN,uint8_t priority){

	NVIC_IPRX_BASE[IQN]  |= ((priority & 0x0F) << 4);

}
