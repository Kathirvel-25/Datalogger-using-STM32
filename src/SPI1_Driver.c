
#include "SPI1_Driver.h"


void SPI1_GPIOConfig(void){

    RCC->AHB1ENR |= GPIOA_Clock_Enable;

    GPIOA->MODER  &= ~((0b11<<10) | (0b11<<12) | (0b11<<14) | (0b11<<8));
    GPIOA->MODER  |=  ((0b10<<10) | (0b10<<12) | (0b10<<14) | (0b01<<8));

    GPIOA->PUPDR  &= ~((0b11<<10) | (0b11<<12) | (0b11<<14) | (0b11<<8));


    GPIOA->AFRL &= ~((0xF<<20) | (0xF<<24) | (0xF<<28));
    GPIOA->AFRL |=  ((0x5<<20) | (0x5<<24) | (0x5<<28));    // PA5- SCK  PA6-MISO  PA7-MOSI

   GPIOA->ODR |= CS_high;  //CS high

}

void SPI1_Init(void)
{
    RCC->APB2ENR |= SPI_Clock_Enabe;   // SPI1 clock

    SPI1->CR1 |=  MASTER_MODE;     // Master

    SPI1->CR1 |=  (1 << 9);     // SSM
    SPI1->CR1 |=  (1 << 8);     // SSI


    SPI1->CR1 &= ~(1 << 7);

    SPI1->CR1 &= ~((1 << 1) | (1 << 0)); // Mode 0

    SPI1->CR1 |=  (0x6 << 3);   // Prescaler /128

    SPI1->CR1 |= SPI_ON;   // ENABLE SPI (LAST)
}

void SPI1_Transmit(uint8_t *tdata,uint8_t size){

	while(size){

		while(!(SPI1->SR & Trans_Status));

		SPI1->DR = *tdata++;

		size--;

	}

	while((SPI1->SR & BSY_Status));

}

void SPI1_Receive(uint8_t *rdata,uint16_t size){


	while(size){

		while(!(SPI1->SR & Trans_Status));

		SPI1->DR = 0xFF;

		while(!(SPI1->SR & Rece_Status));

		*rdata++ = SPI1->DR;

		size--;

	}
	while((SPI1->SR & BSY_Status));

}

void CS_Low(void){

	GPIOA->ODR &= ~CS_high;

}
void CS_High(void){
	GPIOA->ODR |= CS_high;
}
