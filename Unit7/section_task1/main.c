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
#define PORTD 	*(vuint8_t*) (GPIO_BASE + 0x12)
#define DDRD 	*(vuint8_t*) (GPIO_BASE + 0x11)

void gpio_init()
{
	//Pins 0,1,2,3,4,5,6,7 output in portD
	DDRD = 0xFF;
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
	sint8 count;
	while(1)
	{
		//turn on LEDs in sequential
		for (count = 0; count < 8; ++count)
		{
			PORTD |= (1<<count);
			delay(500);
		}
		//turn off LEDs in reverse
		for (count = 7; count >= 0; --count)
		{
			PORTD &= ~(1<<count);
			delay(500);
		}
		delay(500);
	}
}
