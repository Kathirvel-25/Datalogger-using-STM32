/*
 * GPS_Driver.h
 *
 *  Created on: 24-Dec-2025
 *      Author: Kathirvel A
 */

#ifndef GPS_DRIVER_H_
#define GPS_DRIVER_H_
#include "stm32f411retx_Driver.h"
#include "stdint.h"
#include "logdata.h"
#include "string.h"
#include "stdio.h"
#include "Usart2_Driver.h"
#define NMEABuff_size   128

extern USART2_Config ConFig;



typedef struct
{
	uint8_t *rdata;
	uint8_t rbusy;
	uint8_t length;
	uint8_t Idx;

}USART1_Config;




void GPS_GPIOInit(void);
void GPS_Init(void);
char *GPS_ProcessByte(uint8_t data);
void GPS_Read_IT(USART1_Config *config,uint8_t *data,uint8_t size);
void GPS_RequiredData(const char *nmeaBuff,logdata *logg);



#endif /* GPS_DRIVER_H_ */
