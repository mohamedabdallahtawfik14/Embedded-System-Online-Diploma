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

//GPIOA
#define PortA_BASE  0x40010800
#define GPIO_CRH    *(vuint32_t*) (PortA_BASE + 0x04)
#define GPIOA_CRL 	*(vuint32_t*) (PortA_BASE + 0x00)
#define GPIO_ODR    *(vuint32_t*) (PortA_BASE + 0x0C)

//EXTI
#define EXTI_BASE 		0x40010400
#define EXTI_IMR    	*(vuint32_t*) (EXTI_BASE + 0x00)
#define EXTI_RTSR    	*(vuint32_t*) (EXTI_BASE + 0x08)
#define EXTI_PR    		*(vuint32_t*) (EXTI_BASE + 0x14)

//AFIO
#define AFIO_BASE		0x40010000
#define AFIO_EXTICR1    *(vuint32_t*) (AFIO_BASE + 0x08)

//NVIC
#define NVIC_EXTIE0 	*(vuint32_t*)(0xE000E100)

void clock_init(void)
{
	//enable clock for GPIOA
	RCC_APB2ENR |= RCC_IOPAEN;
	//enable clock for AFIO
	RCC_APB2ENR |= (1<<0);
}
void gpio_init()
{
	//pinA13 --> output
	 GPIO_CRH &= 0xff0fffff;
	 GPIO_CRH |= 0x00200000;
	 //pinA0 floating
	 GPIOA_CRL |= (1<<2);

}
int main(void)
{
	//EXTI0 configuration to PORTA0
	AFIO_EXTICR1 = 0;

	// rising trigger
	EXTI_RTSR |= (1<<0);

	//enable interrupt mask
	EXTI_IMR |= (1<<0);

	//enable NVIC ireq6
	NVIC_EXTIE0 |= (1<<6);
    while(1)
    {
    }
}
void EXTI0_IRQHandler(void)
{
	//toggle pinA13
	GPIO_ODR ^= (1<<13);
	//clear pending request for line 0
	EXTI_PR |= (1<<0);
}
