#include "stm32f411retx_Driver.h"
#include "NVIC_Driver.h"
#include "logdata.h"
#include "GPS_Driver.h"
#include "ADC_Driver.h"
#include "SPI1_Driver.h"
#include "W25Q_Driver.h"
#include "Usart2_Driver.h"
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

/*

For Number and Port see the corresponding c files 

For GPS    =     GPS.C
For USART2 =   USART2.C
FOR W25Q  =    SPI1.c


i use the SPI1 for the W25Q64J


Email id: lmbmkathirvela@gmail.com



*/


USART2_Config ConFig;

USART1_Config usart1;

logdata readback;

uint32_t flash = 0X000000;


void delay_ms(uint32_t ms)
{
    volatile uint32_t i;

    while (ms--)
    {
        for (i = 0; i < 8400; i++);   // ~1 ms at 84 MHz
    }
}


int main(void)
{

       ADC1_GPIO_Init();
       ADC1_Init();
        SPI1_GPIOConfig();
        SPI1_Init();
        GPS_GPIOInit();
        GPS_Init();
        USART2_GPIOInit();
        USART2_Init();

     NVIC_EnableIRQ(USART1_IRQn);
     NVIC_EnableIRQ(USART2_IRQn);




      uint32_t data;

      uint8_t st[10];

      uint8_t txBuf[128];




       while (1)
       {

    	   data = ADC1_ReadVal();

    	   ADC_Val(data, &da);



           if (usart1.rbusy == 0)
           {
               GPS_Read_IT(&usart1, st, 1);


               if (GPS_ProcessByte(st[0]))
               {

            	   if ((flash % 4096) == 0)   // sector boundary
            	   {
            	       Sector_Erase(flash);
					   Is_Bussy();
            	   }
				   if((flash % 256) + (sizeof(logdata)) > 256){
					   flash = (flash /256 +1) * 256
						   }


                 W25_Pageprogram(flash,(uint8_t*)&da,sizeof(logdata));

                 Is_Bussy();

                 W25_Read(flash,(uint8_t*)&readback,sizeof(logdata));

                 flash += sizeof(logdata);

 		      int len = snprintf((char*)txBuf, sizeof(txBuf), "LAT:%s%s\r\n" "LON:%s%s\r\n" "Temp:%" PRIu32 "\r\n" "----------------\r\n",
 		            	        readback.lat, readback.ns,
 		            	        readback.lon, readback.ew,
 		            	        readback.temp);

					 while(Config.busy);

 		       USART2_Transmit_IT(&ConFig, txBuf, len);

 		                                     


               }
               }
              }



 }

/* USART1 For the GPS */

void  USART1_IRQHandler(void)
{
     if((USART1->SR & (1<<5))&&(USART1->CR1 & (1<<5))){

        usart1.rdata[usart1.Idx++] = USART1->DR;

        if(usart1.Idx >= usart1.length){

        	USART1->CR1 &= ~(1<<5);

        	usart1.rbusy = 0;



        }

     }
}

/*USART 2 FOR the Terminal View*/

void USART2_IRQHandler()
{
	if((USART2->CR1 & (1<<7)) && (USART2->SR & (1<<7))){

              if(ConFig.Idx < ConFig.tlen){

		      USART2->DR = ConFig.tdata[ConFig.Idx++] ;

                }

              else{

		       USART2->CR1 &= ~(1<<7);

		       ConFig.busy = 0;
		   }

	}
}

