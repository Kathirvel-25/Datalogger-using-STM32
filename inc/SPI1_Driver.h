
#ifndef SPI1_DRIVER_H_
#define SPI1_DRIVER_H_
#include "stdint.h"
#include "stm32f411retx_Driver.h"



void SPI1_GPIOConfig(void);
void SPI1_Init(void);
void SPI1_Transmit(uint8_t *tdata,uint8_t size);
void SPI1_Receive(uint8_t *rdata,uint16_t size);
void CS_Low(void);
void CS_High(void);


#endif /* SPI1_DRIVER_H_ */
