/**
 ******************************************************************************
 * @file           : app.c
 * @author         : mohamed
 * @brief          : application program body
 ******************************************************************************
 */
#include "platform_Types.h"
//register address
#define RCC_BASE   	0x40021000
#define PortA_BASE 	0x40010800
#define RCC_APB2ENR *(vuint32_t*) (RCC_BASE + 0x18)
#define GPIO_CRH 	*(vuint32_t*) (PortA_BASE + 0x04)
#define GPIO_ODR 	*(vuint32_t*) (PortA_BASE + 0x0C)

//bit field to enable port A
#define RCC_IOPAEN 	(1<<2)
#define	GPIOA13		(1UL<<13)

typedef union
{
	vuint32_t all_pins;
	struct 
	{
		vuint32_t reserved:13;
		vuint32_t pin_13:1;
	}PORT;
} R_ODR_t;

// pointer to union
volatile R_ODR_t *R_ODR= (volatile R_ODR_t*)(PortA_BASE + 0x0C);
uint8 arr[3] = {4, 5, 6};
uint8 const consarr[3] = {1, 2, 3};
vuint32_t bss_var[3];

int main(void)
{
	vuint32_t count;
	RCC_APB2ENR |= RCC_IOPAEN; //set bit2
	GPIO_CRH &= 0xff0fffff;
	GPIO_CRH |= 0x00200000;
	//infinity loop
	while(1)
	{
		R_ODR -> PORT.pin_13 = 1; // set bit 13
		for(count = 0; count < 90000; count++); //delay
		R_ODR -> PORT.pin_13 = 0; // clear bit 13
		for(count = 0; count < 90000; count++); //delay
	}
	return 0;
}
