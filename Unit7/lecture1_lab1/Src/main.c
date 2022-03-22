/**
 ******************************************************************************
 * @file           : main.c
 * @author         : mohamed
 * @brief          : Application program body
 ******************************************************************************
 */
//incs
#include "platform_Types.h"

//RCC
#define RCC_BASE    0x40021000
#define RCC_APB2ENR *(vuint32_t*) (RCC_BASE + 0x18)
#define RCC_IOPAEN (1<<2)
#define RCC_IOPBEN (1<<3)

//GPIOA
#define GPIOA_BASE   0x40010800
#define GPIOA_CRH    *(vuint32_t*) (GPIOA_BASE + 0x04)
#define GPIOA_CRL 	 *(vuint32_t*) (GPIOA_BASE + 0x00)
#define GPIOA_ODR    *(vuint32_t*) (GPIOA_BASE + 0x0C)
#define GPIOA_IDR    *(vuint32_t*) (GPIOA_BASE + 0x08)

//GPIOB
#define GPIOB_BASE   0x40010C00
#define GPIOB_CRH    *(vuint32_t*) (GPIOB_BASE + 0x04)
#define GPIOB_CRL 	 *(vuint32_t*) (GPIOB_BASE + 0x00)
#define GPIOB_ODR    *(vuint32_t*) (GPIOB_BASE + 0x0C)

void clock_init(void)
{
	//enable clock for GPIOA
	RCC_APB2ENR |= RCC_IOPAEN;
	//enable clock for GPIOB
	RCC_APB2ENR |= RCC_IOPBEN;

}
void gpio_init()
{
	//PinA1 input floating (highZ)
	GPIOA_CRL &= 0xFFFFFF0F;
	GPIOA_CRL |= (1<<6);
	//PinB1 output push-pull mode
	GPIOB_CRL &= 0xFFFFFF0F;
	GPIOB_CRL |= (1<<4);
	//PinA13 input floating (highZ)
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= (1<<22);
	//PinB13 output push-pull mode
	GPIOB_CRH &= 0xFF0FFFFF;
	GPIOB_CRH |= (1<<20);
}
void wait(vuint32_t x)
{
	vuint32_t i, j;
	for (i = 0; i < x; ++i)
		for (j = 0; j < 255; ++j);
}
int main(void)
{
	clock_init();
	gpio_init();
    while(1)
    {
    	// push button on PinA1
    	if(((GPIOA_IDR & (1 << 1)) >> 1) == 0) //pressed
    	{
    		//toggle led on PinB1
    		GPIOB_ODR ^= (1 << 1);
    		//single press
    		while((((GPIOA_IDR & (1 << 1)) >> 1) == 0));
    	}
    	// push button on PinA13
    	if(((GPIOA_IDR & (1 << 13)) >> 13) == 1) // pressed
    	{
    		//toggle led on PinB1
    		GPIOB_ODR ^= (1 << 13);
    	}
    	wait(1);
    }
}
