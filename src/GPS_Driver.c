
#include "GPS_Driver.h"




char  nmeaBuff[NMEABuff_size];
uint8_t nmeaIdx = 0;




 void GPS_RequiredData(const char *nmeaBuff,logdata *logg){


	if(strncmp(nmeaBuff,"$GPRMC",6) != 0){ return;}


	char buff[NMEABuff_size];

	strncpy(buff,nmeaBuff,NMEABuff_size-1);
	buff[NMEABuff_size - 1] = '\0';

	char *token;
	char *save;


	uint8_t field = 0;
	token = strtok_r(buff,",",&save);



	while(token != NULL){

		field++;

		switch (field){

		case 4:
		    strncpy(logg->lat, token, sizeof(logg->lat) - 1);
		    logg->lat[sizeof(logg->lat) - 1] = '\0';
		    break;

		case 5:
		    strncpy(logg->ns, token, sizeof(logg->ns) - 1);
		    logg->ns[sizeof(logg->ns) - 1] = '\0';
		    break;

		case 6:
		    strncpy(logg->lon, token, sizeof(logg->lon) - 1);
		    logg->lon[sizeof(logg->lon) - 1] = '\0';
		    break;

		case 7:
		    strncpy(logg->ew, token, sizeof(logg->ew) - 1);
		    logg->ew[sizeof(logg->ew) - 1] = '\0';
		    break;
		}

		token = strtok_r(NULL,",",&save);

	}

//	  uint8_t out[128];
//
//	  int n =  snprintf((char*)out,sizeof(out),"LAT:%s%s \r\n LON: %s%s \r\n",dat.lat,dat.ns,dat.lon,dat.ew);
//
//	  USART2_Transmit_IT(&ConFig,(uint8_t*)out,n);



}


void GPS_GPIOInit(void){

	RCC->AHB1ENR |= (1<<0);

    GPIOA->MODER &= ~((0b11<<18) | (0b11<<20));  // PA9 - TX  PA10-RX
    GPIOA->MODER |= ((0b10<<18) | (0b10<<20));

    GPIOA->PUPDR &= ~((0b11<<18) | (0b11<<20));

    GPIOA->PUPDR |=  (0b01<<20);

    GPIOA->AFRH &= ~((0x0F<<4) | (0x0F<<8));
    GPIOA->AFRH |=  ((0x07<<4) | (0x07<<8));    //USART1

}


void GPS_Init(void){

	RCC->APB2ENR |= (1<<4);

	USART1->CR1 &= ~(1<<15);     // Oversampling by 16

	USART1->CR1 &= ~(1<<12);     // 8-Bit Data

	USART1->CR2 &= ~(0b11<<12);   // 1 STOP BIT

	USART1->BRR  = (104 << 4) | 3;

	USART1->CR1 |= ((1<<3) | (1<<2));

	USART1->CR1 |= (1<<13);

}

char *GPS_ProcessByte(uint8_t data){

	if(data == '$'){
		nmeaIdx = 0;
	}

	if(nmeaIdx < NMEABuff_size -1){

		nmeaBuff[nmeaIdx++] = data;

	}

	if(data == '\n')
	{
		nmeaBuff[nmeaIdx] = '\0';
		nmeaIdx = 0;

		GPS_RequiredData(nmeaBuff,&da);

		return nmeaBuff;


	}
	return NULL;
}

void GPS_Read_IT(USART1_Config *config,uint8_t *data,uint8_t size){

	if(config->rbusy){
		return;
	}
	config->rdata = data;
    config->length = size;
    config->Idx = 0;
    config->rbusy = 1;

	USART1->CR1 |= (1<<5);

}




















