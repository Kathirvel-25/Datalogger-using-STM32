/*
 * NVIC_Driver.h
 *
 *  Created on: 24-Dec-2025
 *      Author: Kathirvel A
 */

#ifndef NVIC_DRIVER_H_
#define NVIC_DRIVER_H_
#include "stdint.h"
#include "stm32f411retx_Driver.h"

void NVIC_EnableIRQ(uint8_t IQN);

void NVIC_SetPriority(uint8_t IQN,uint8_t priority);

#endif /* NVIC_DRIVER_H_ */
