
#ifndef W25Q_DRIVER_H_
#define W25Q_DRIVER_H_
#include "stm32f411retx_Driver.h"
#include "SPI1_Driver.h"
#include "stdint.h"


void W25_ChipErase(void);
void W25_Read(uint32_t addr,uint8_t *rdata,uint16_t len);
void W25_Pageprogram(uint32_t addr,uint8_t *rdata,uint16_t len);
void Sector_Erase(uint32_t addr);
void W25_SectorErase(uint32_t address);
void Is_Bussy(void);
void Read_Id(uint8_t *id);

#endif /* W25Q_DRIVER_H_ */

