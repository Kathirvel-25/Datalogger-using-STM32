
#ifndef stm32f411retx_Driver_h
#define stm32f411retx_Driver_h

#include "stdint.h"

/*BUS Base  Address*/
#define APB1PERIPH_BASEADDR          0x40000000U
#define APB2PERIPH_BASEADDR          0x40010000U
#define AHB1PERIPH_BASEADDR         0x40020000U


/*GPIO Base Address*/
#define GPIOA_BASEADDR                  0x40020000U

/*RCC Base Address*/
#define RCC_BASE_ADDR                   0x40023800U

/*SPI Base Address*/
#define SPI1_BASEADDR                    0x40013000U

/*NVIC Base Address*/
#define NVIC_BASEADDR                   0xE000E100U

/*USART Base Address*/
#define USART1_BASEADDR             0x40011000U
#define USART6_BASEADDR             0x40011400U
#define USART2_BASEADDR             0x40004400U

/*ADC1 Base Address*/
#define ADC1_BASEADDDR               0x40012000U




/*GPIO Related Registers*/
typedef struct{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL;
	volatile uint32_t AFRH;

}GPIO_RegDef;

/*RCC Related Registers*/
typedef struct{
   volatile	uint32_t CR;
   volatile	uint32_t PLLCFGR;
   volatile	uint32_t CFGR;
   volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
   volatile uint32_t AHB2RSTR;
   volatile uint32_t RESERVED1;
   volatile uint32_t RESERVED2;
   volatile uint32_t APB1RSTR;
   volatile uint32_t APB2RSTR;
   volatile uint32_t RESERVED3;
   volatile uint32_t RESERVED4;
   volatile uint32_t AHB1ENR;
   volatile uint32_t AHB2ENR;
   volatile uint32_t RESERVED5;
    volatile uint32_t RESERVED6; // 1 table
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t RESERVED7;
	volatile uint32_t RESERVED8;
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t RESERVED9;
	volatile uint32_t RESERVED10;
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	volatile uint32_t RESERVED11;
	volatile uint32_t RESERVED12;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t RESERVED13;
	volatile uint32_t RESERVED14;
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
	volatile uint32_t DCKCFGR;

}RCC_RegDef;

/*SPI Related Registers*/
typedef struct
{
	volatile uint32_t  CR1;
	volatile uint32_t CR2;
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t CRCPR;
	volatile uint32_t RXCRCR;
	volatile uint32_t TXCRCR;
	volatile uint32_t I2SCFGR;
	volatile uint32_t I2SPR;


}SPI_RegDef;


/*ADC1 Related Register*/
typedef struct {

	volatile uint32_t SR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SMPR1;
	volatile uint32_t  SMPR2;
	volatile uint32_t  JOFR1;
	volatile uint32_t JOFR2;
	volatile uint32_t JOFR3;
	volatile uint32_t JOFR4;
	volatile uint32_t  HTR;
	volatile uint32_t  LTR;
	volatile uint32_t SQR1;
	volatile uint32_t SQR2;
	volatile uint32_t SQR3;
	volatile uint32_t JSQR;
	volatile uint32_t  JDR1;
	volatile uint32_t JDR2;
	volatile uint32_t JDR3;
	volatile uint32_t JDR4;
	volatile uint32_t DR;
}ADC1_RegDef;


/*USART Related Register */
typedef struct {
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t  CR1;
	volatile uint32_t  CR2;
	volatile uint32_t CR3;
	volatile uint32_t  GTPR;
}USART_RegDef;


/*GPIO Mapped to the Register*/
#define GPIOA   ((GPIO_RegDef*)GPIOA_BASEADDR)

/*RCC Mapped to Register*/
#define RCC     ((RCC_RegDef*)RCC_BASE_ADDR)


/*SPI Mapped to the Register*/
#define SPI1          ((SPI_RegDef*)SPI1_BASEADDR)


/*NVIC Mapped Register */
#define NVIC_ISERX_BASE       ((volatile uint32_t*)NVIC_BASEADDR)
#define NVIC_IPRX_BASE        ((volatile uint8_t*)0xE000E400U)


/*USART Mapped to Register*/
#define USART1                       ((USART_RegDef*)USART1_BASEADDR)
#define USART6                       ((USART_RegDef*)USART6_BASEADDR)
#define USART2                       ((USART_RegDef*)USART2_BASEADDR)


/*ADC1 Mapped to Register*/
#define ADC1                       ((ADC1_RegDef*)ADC1_BASEADDDR)

/*USART Interrupt Number*/
#define USART1_IRQn  37
#define USART2_IRQn  38

/*GPIO Related Register shifting*/
#define GPIOA_Clock_Enable  (1<<0)

/*ADC_Driver.c  Register Shift Details*/
#define ADC_Clock_Enable    (1<<8)
#define Analog_Mode         (0b11<<0)
#define ADC_Enable          (1<<0)
#define ADC_Conversion_Init (1<<30)
#define ADC_End_Coversion   (1<<1)
#define ADC_Mask             0x0FFF

/*GPS Related Register shifting */
#define AF_Mode_GPS_TX         (0b10<<18)
#define AF_Mode_GPS_RX         (0b10<<20)
#define Clear_TX               (0b11<<18)
#define CLear_RX               (0b11<<20)
#define Clear_AF_TX            (0x0F<<4)
#define Clear_AF_RX            (0x0F<<8)
#define AF_TX                  (0x07<<4)
#define AF_RX                  (0x07<<8)
#define GPS_Clock_Enable       (1<<4)
#define OVERSAM_16             (1<<15)
#define BIT_Format_8            (1<<12)
#define STOP_BIT_1              (0b11<<12)
#define MANTISSA                (104<<4)
#define FRACTION                   3
#define GPS_TX_ON               (1<<3)
#define GPS_RX_ON               (1<<2)
#define GPS_ON                  (1<<13)
#define GPS_Interrupt_TX_ON     (1<<5)
#define GPS_Interrupt_RX_Status (1<<5)


/*SPI1 Related Register Shifting */
#define CS_high                  (1<<4)
#define SPI_Clock_Enabe          (1<<12)
#define SPI_ON                   (1<<6)
#define MASTER_MODE             (1<<2)
#define Trans_Status              (1<<1)
#define Rece_Status              (1<<0)
#define BSY_Status               (1<<7)
#define TX_ON                    (1<<3)
#define RX_ON                     (1<<2)
#define USART_ON                  (1<<13)
#define USART2_CLK                (1<<17)
#define Interrupt_RX_ON          (1<<7)
#define Interrupt_RX_Status      (1<<7)


#endif




