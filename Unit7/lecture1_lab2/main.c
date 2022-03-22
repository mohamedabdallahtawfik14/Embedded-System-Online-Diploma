/*
 * main.c
 *
 *  Created on: Mar 22, 2022
 *      Author: Mohamed
 */

#include "platform_Types.h"

//GPIO
#define GPIO_BASE 0x20
//PORTD
#define PORTD 	*(vuint32_t*) (GPIO_BASE + 0x12)
#define DDRD 	*(vuint32_t*) (GPIO_BASE + 0x11)

void gpio_init()
{
	//Pins 4,5,6,7 output in portD
	DDRD |= 0xF0;
}

void delay(vuint32_t x)
{
	vuint32_t i, j;
	for (i = 0; i < x; ++i)
		for (j = 0; j < 255; ++j);
}
int main(void)
{
	gpio_init();
	while(1)
	{
		//toggle led on pin5 portD
		PORTD ^= (1<<5);
		delay(500);
		//toggle led on pin6 portD
		PORTD ^= (1<<6);
		delay(500);
		//toggle led on pin7 portD
		PORTD ^= (1<<7);
		delay(500);
		//make buzzer on pin4 portD
		PORTD |= (1<<4);
		delay(500);
		//make buzzer off pin4 portD
		PORTD  &= ~(1<<4);
	}
}
