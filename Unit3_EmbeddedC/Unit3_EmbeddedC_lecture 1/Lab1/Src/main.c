/**
 ******************************************************************************
 * @file           : main.c
 * @author         : mohamed
 * @brief          : Main program body
 ******************************************************************************
 */

#include "platform_Types.h"

#define RCC_BASE   	0x40021000
#define PortA_BASE 	0x40010800
#define RCC_APB2ENR *(vuint32_t*) (RCC_BASE + 0x18)
#define GPIO_CRH 	*(vuint32_t*) (PortA_BASE + 0x04)
#define GPIO_ODR 	*(vuint32_t*) (PortA_BASE + 0x0C)
int main(void)
{
	RCC_APB2ENR |= 1 << 2;
	GPIO_CRH &= 0xff0fffff;
	GPIO_CRH |= 0x00200000;
	while(1)
	{
		GPIO_ODR |= 1 << 13; // set bit 13
		for(uint32 count = 0; count < 90000; count++);
		GPIO_ODR &= ~(1 << 13); // clear bit 13
		for(uint32 count = 0; count < 90000; count++);

	}
	return 0;
}
