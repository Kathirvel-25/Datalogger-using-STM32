/*
 * ADC_Driver.h
 *
 *  Created on: 24-Dec-2025
 *      Author: Kathirvel A
 */

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_
#include "stm32f411retx_Driver.h"
#include "stdint.h"
#include "logdata.h"
#include "GPS_Driver.h"
#include "Usart2_Driver.h"
#include "string.h"
#include "stdio.h"


void ADC1_GPIO_Init(void);
void ADC1_Init(void);
uint16_t ADC1_ReadVal(void);
void ADC_Val(uint16_t adc,logdata *data);


#endif /* ADC_DRIVER_H_ */
