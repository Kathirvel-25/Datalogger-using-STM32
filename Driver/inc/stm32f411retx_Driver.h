
#ifndef stm32f411retx_Driver_h
#define stm32f411retx_Driver_h

#include "stdint.h"

/*BUS Base  Address*/

#define APB1PERIPH_BASEADDR          0x40000000U
#define APB2PERIPH_BASEADDR          0x40010000U
#define AHB1PERIPH_BASEADDR         0x40020000U
#define AHB2PERIPH_BASEADDR         0x50000000U

/*GPIO Base Address*/

#define GPIOA_BASEADDR                  0x40020000U
#define GPIOB_BASEADDR                  0x40020400U
#define GPIOC_BASEADDR                  0x40020800U
#define GPIOD_BASEADDR                  0x40020C00U

/*RCC Base Address*/

#define RCC_BASE_ADDR                   0x40023800U

/*SPI Base Address*/
#define SPI1_BASEADDR                    0x40013000U
#define SPI2_BASEADDR                    0x40003800U
#define SPI3_BASEADDR                    0x40003C00U

/*I2C Base Address */

#define I2C1_BASEADDR                    0x40005400U
#define I2C2_BASEADDR                    0x40005800U
#define I2C3_BASEADDR                    0x40005C00U

/*SYSCFG Base Address*/

#define SYSCFG_BASEADDR              0x40013800U

/*NVIC Base Address*/

#define NVIC_BASEADDR                   0xE000E100U

/*EXTI Base address*/

#define EXTI_BASEADDR                   0x40013C00U

/*USART Base Address*/
#define USART1_BASEADDR             0x40011000U
#define USART6_BASEADDR             0x40011400U
#define USART2_BASEADDR             0x40004400U

/*ADC1 Base Address*/

#define ADC1_BASEADDDR               0x40012000U

/*Timer Base Address*/
#define TIMER2_BASEADDR        0x40000000U
#define TIMER3_BASEADDR        0x40000400U
#define TIMER4_BASEADDR        0x40000800U
#define TIMER5_BASEADDR        0x40000C00U


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

/*Timers Related to the Register*/

typedef struct{
	volatile uint32_t CR1;
	volatile uint32_t  CR2;
	volatile uint32_t  SMCR;
	volatile uint32_t  DIER;
	volatile uint32_t  SR;
	volatile uint32_t  EGR;
	volatile uint32_t  CCMR1;
	volatile uint32_t  CCMR2;
	volatile uint32_t  CCER;
	volatile uint32_t  CNT;
	volatile uint32_t  PSC;
	volatile uint32_t  ARR;
	volatile uint32_t  RESERVED;
	volatile uint32_t  CCR1;
	volatile uint32_t  CCR2;
	volatile uint32_t  CCR3;
	volatile uint32_t  CCR4;
	volatile uint32_t  RESERVED1;
	volatile uint32_t DCR;
	volatile uint32_t DMAR;
	volatile uint32_t  OR;

}Timer_RegDef;

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

/*EXTI Related Registers*/
typedef struct {

	 volatile uint32_t IMR;       // INterrupt Masking Register
	 volatile uint32_t EMR;       // Event Masking TRegister
	 volatile uint32_t RTSR;      // Rising Trigger Selection Register
	 volatile uint32_t FTSR;      //Falling Trigger Selection Register
	 volatile uint32_t SWIER;      //Software Interrupt Event Register
	 volatile uint32_t PR;        //Pending Register
}EXTI_RegDef;


/*SYSCFG Related Register*/

typedef struct{

	volatile uint32_t MEMRMP;            //MEMMORY MAPPED REGISTER
	volatile uint32_t PMC;                   //Peripheral Mode config  register
	volatile uint32_t EXTICR1;         //External Interrupt config register
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t RESERVED;
	volatile uint32_t RESERVED1;
	volatile uint32_t CMPCR;    // Compensation Cell Control Register

}SYSCFG_RegDef;


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


/*I2C Related Register */
typedef struct
{
	volatile uint32_t   CR1;
	volatile uint32_t   CR2;
	volatile uint32_t   OAR1;
	volatile uint32_t   OAR2;
	volatile uint32_t   DR;
	volatile uint32_t   SR1;
	volatile uint32_t   SR2;
	volatile uint32_t   CCR;
	volatile uint32_t   TRISE;
	volatile uint32_t  FLTR;
}I2C_RegDef;



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
#define GPIOB   ((GPIO_RegDef*)GPIOB_BASEADDR)
#define GPIOC   ((GPIO_RegDef*)GPIOC_BASEADDR)
#define GPIOD   ((GPIO_RegDef*)GPIOD_BASEADDR)
/*RCC Mapped to Register*/

#define RCC     ((RCC_RegDef*)RCC_BASE_ADDR)

/*SYSCFG Mapped to Register*/

#define SYSCFG  ((SYSCFG_RegDef*)SYSCFG_BASEADDR)

/*SPI Mapped to the Register*/

#define SPI1          ((SPI_RegDef*)SPI1_BASEADDR)
#define SPI2          ((SPI_RegDef*)SPI2_BASEADDR)
#define SPI3          ((SPI_RegDef*)SPI3_BASEADDR)

/*NVIC Mapped Register */
#define NVIC_ISERX_BASE       ((volatile uint32_t*)NVIC_BASEADDR)
#define NVIC_ICERX_BASE       ((volatile uint32_t*) 0xE000E180U)
#define NVIC_ISPRX_BASE       ((volatile uint32_t*)0xE000E200U)
#define NVIC_ICPRX_BASE       ((volatile uint32_t*)0xE000E280U)
#define NVIC_IABRX_BASE       ((volatile uint32_t*)0xE000E300U)
#define NVIC_IPRX_BASE        ((volatile uint8_t*)0xE000E400U)

/*EXTI Mapped to Register */

#define EXTI                           ((EXTI_RegDef*)EXTI_BASEADDR)

/*USART Mapped to Register*/

#define USART1                       ((USART_RegDef*)USART1_BASEADDR)
#define USART6                       ((USART_RegDef*)USART6_BASEADDR)
#define USART2                       ((USART_RegDef*)USART2_BASEADDR)

/*I2C Mapped to Register*/

#define I2C1                          ((I2C_RegDef*)I2C1_BASEADDR)
#define I2C2                          ((I2C_RegDef*)I2C2_BASEADDR)
#define I2C3                          ((I2C_RegDef*)I2C3_BASEADDR)

/*ADC1 Mapped to Register*/

#define ADC1                       ((ADC1_RegDef*)ADC1_BASEADDDR)

/*Timer Mapped to Register*/
#define TIM2                         ((Timer_RegDef*)TIMER2_BASEADDR)
#define TIM3                         ((Timer_RegDef*)TIMER3_BASEADDR)
#define TIM4                         ((Timer_RegDef*)TIMER4_BASEADDR)
#define TIM5                         ((Timer_RegDef*)TIMER5_BASEADDR)

 /*EXTI Interrupt Number*/

#define EXTI0_IRQN   6
#define EXTI1_IRQN   7
#define EXTI2_IRQN   8
#define EXTI3_IRQN   9
#define EXTI4_IRQN   10
#define EXTI9_9IRQN  23
#define EXTI15_10    40
#define USART1_IRQn  37
#define USART2_IRQn  38
#define SPI1_IRQn     35
#define SPI2_IRQn     36
#define SPI3_IRQn     51

#endif




