/*
 * Stm32F103x6.h
 *
 *  Created on: Mar 25, 2022
 *      Author: Mohamed
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------

#include "platform_Types.h"

//-----------------------------
//Base addresses for Memories
//-----------------------------

#define FLASH_MEMORY_BASE						0x08000000UL
#define SRAM_MEMORY_BASE						0x20000000UL
#define SYSTEM_MEMORY_BASE						0x1FFFF000UL

#define PERIHERAL_BASE							0x40000000UL
#define CORTEX_M3_INTERNAL_PERIPHERALS_BASE		0xE0000000UL

//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------

#define RCC_BASE								0x40021000UL

//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------

//GPIO
//A,B fully included in LQFP48 Package
#define GPIOA_BASE								0x40010800UL
#define GPIOB_BASE								0x40010C00UL

//C,D partial included in LQFP48 Package
#define GPIOC_BASE								0x40011000UL
#define GPIOD_BASE								0x40011400UL

//E not included in LQFP48 Package
#define GPIOE_BASE								0x40011800UL

//EXTI
#define EXTI_BASE								0x4000400UL

//AFIO
#define AFIO_BASE								0x40010000UL

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*
//GPIO
typedef struct
{
	vuint32_t CRL;  //0x00
	vuint32_t CRH;	//0x04
	vuint32_t IDR;	//0x08
	vuint32_t ODR;	//0x0C
	vuint32_t BSRR;	//0x10
	vuint32_t BRR;	//0x14
	vuint32_t LCKR;	//0x18
}GPIO_TypeDef;

//RCC
typedef struct
{
	vuint32_t CR;  		//0x00
	vuint32_t CFGR;		//0x04
	vuint32_t CIR;		//0x08
	vuint32_t APB2RSTR;	//0x0C
	vuint32_t APB1RSTR;	//0x10
	vuint32_t AHBENR;	//0x14
	vuint32_t APB2ENR;	//0x18
	vuint32_t APB1ENR;	//0x1C
	vuint32_t BDCR;		//0x20
	vuint32_t CSR;		//0x24
	vuint32_t AHBSTR;	//0x28
	vuint32_t CFGR2;	//0x2C
}RCC_TypeDef;

//EXTI
typedef struct
{
	vuint32_t IMR;  	//0x00
	vuint32_t EMR;		//0x04
	vuint32_t RTSR;		//0x08
	vuint32_t FTSR;		//0x0C
	vuint32_t SWIER;	//0x10
	vuint32_t PR;		//0x14
}EXTI_TypeDef;

//AFIO
typedef struct
{
	vuint32_t EVCR;  	//0x00
	vuint32_t MAPR;		//0x04
	vuint32_t EXTICR1;	//0x08
	vuint32_t EXTICR2;	//0x0C
	vuint32_t EXTICR3;	//0x10
	vuint32_t EXTICR4;	//0x14
	vuint32_t Reserved;	//0x18
	vuint32_t MAPR2;	//0x1C
}AFIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
//GPIO
#define GPIOA				((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB				((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC				((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD				((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE				((GPIO_TypeDef *)GPIOE_BASE)
//RCC
#define RCC					((RCC_TypeDef *)RCC_BASE)
//EXTI
#define EXTI				((EXTI_TypeDef *)EXTI_BASE)
//AFIO
#define AFIO				((AFIO_TypeDef *)AFIO_BASE)

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
//GPIO
#define GPIOA_CLOCK_EN()	(RCC->APB2ENR |= (1<<2))
#define GPIOB_CLOCK_EN()	(RCC->APB2ENR |= (1<<3))
#define GPIOC_CLOCK_EN()	(RCC->APB2ENR |= (1<<4))
#define GPIOD_CLOCK_EN()	(RCC->APB2ENR |= (1<<5))
#define GPIOE_CLOCK_EN()	(RCC->APB2ENR |= (1<<6))

//AFIO
#define AFIO_CLOCK_EN()		(RCC->APB2ENR |= (1<<0))


#endif /* INC_STM32F103X6_H_ */
