#include "W25Q_Driver.h"
#define FLASH_SIZE     (60UL*1024*1024)
#define PAGE_SIZE        256
#define SECTOR_SIZE    4096

uint32_t flash_addr = 0x000000;
uint8_t   Page_buff[PAGE_SIZE];
uint16_t Page_idx =0;


static uint8_t W25_Readstatus(void){

	 uint8_t cmd =0X05;
	 uint8_t status;

	 CS_Low();
	 SPI1_Transmit(&cmd, 1);
	 SPI1_Receive(&status, 1);
	 CS_High();

	 return status;
}

static void W25_WriteEnable(void){

	uint8_t cmd = 0X06;

	CS_Low();
	SPI1_Transmit(&cmd, 1);
	CS_High();
}


 void Is_Bussy(void){

    while(W25_Readstatus() & 0x01);

 }

void W25_SectorErase(uint32_t address)
{
    uint8_t addr[3];
    uint8_t cmd = 0x20;

    addr[0] = (address >> 16) & 0xFF;
    addr[1] = (address >> 8)  & 0xFF;
    addr[2] =  address        & 0xFF;

    W25_WriteEnable();    

    CS_Low();

    SPI1_Transmit(&cmd,1);
    SPI1_Transmit(addr,3);
    CS_High();

    Is_Bussy();
}


void W25_ChipErase(void){

	uint8_t cmd = 0XC7;

	W25_WriteEnable();

	CS_Low();
	SPI1_Transmit(&cmd, 1);
	CS_High();

	Is_Bussy();
}

void W25_Read(uint32_t addr,uint8_t *rdata,uint16_t len){

	uint8_t cmd = 0x03;
	uint8_t r_addr[3];
	uint8_t dummy = 0xFF
	uint8_t throw;
	

	r_addr[0] = (addr>>16) & 0xFF;
	r_addr[1] = (addr >> 8) & 0xFF;
	r_addr[2] = addr & 0xFF;

	CS_Low();

	while(!(SPI1->SR & (1<<1)))
		SPI1->DR = duummy;
	while(!(SPI1->SR & (1<<0)))
		throw = SPI1->DR
			

	SPI1_Transmit(&cmd, 1);
	SPI1_Transmit(r_addr, 3);

	for (uin16_t i = 0; i < len; i++){
		while(!(SPI1->SR & (1<<1)))
			SPI1->DR = dummy;
		while(!(SPI1->SR & (1<<0)))
			rdata[i] = SPI1->DR;
	}
	while(!(SPI1->SR & (1<<7)));
	
	SPI1_Receive(rdata,len);

	CS_High();

}

void Sector_Erase(uint32_t addr){
	uint8_t w_addr[3];
	uint8_t cmd = 0x20;
	W25_WriteEnable();

	w_addr[0] = (addr >> 16) & 0xFF;
	w_addr[1] = (addr >> 8) & 0xFF;
	w_addr[2] = addr & 0xFF;

	CS_Low();

	SPI1_Transmit(&cmd, 1);
	SPI1_Transmit(w_addr,3);

	CS_High();

	Is_Bussy();
}

void W25_Pageprogram(uint32_t addr,uint8_t *tdata,uint16_t len){

	uint8_t cmd = 0x02;
	uint8_t w_addr[3];

	W25_WriteEnable();

	w_addr[0] = (addr >> 16) & 0xFF;
	w_addr[1] = (addr >> 8) & 0xFF;
	w_addr[2] = addr & 0xFF;

	CS_Low();

	SPI1_Transmit(&cmd, 1);
	SPI1_Transmit(w_addr,3);

	SPI1_Transmit(tdata,len);

	CS_High();

	Is_Bussy();
}

void Read_Id(uint8_t *id){

uint8_t cmd = 0x9F;
uint8_t dummy = 0xFF;
uint8_t throw;

CS_Low();
	
while(!(SPI1->SR & (1<<1)));
	SPI1->DR = dummy;
while(!(SPI1->SR & (1<<0)));
	throw = SPI1->DR;
	
SPI1_Transmit(&cmd,1);
	
for (int i = 0; i < 3; i++){
	while(!(SPI1->SR & (1<<1)));
	SPI1->DR = dummy;
		while(!(SPI1->SR & (1<<0)));
	id[i] = SPI1->DR;
}

	while (SPI1->SR (1<<7));
	CS_High();
}
	
	



}
	
