/*
 * main.c
 *
 *  Created on: Mar 20, 2022
 *      Author: Mohamed
 */

#define F_CPU 8000000UL
#include "platform_Types.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define IO_BASE 	0x20
#define IO_PORTD 	*(vuint32_t *)(IO_BASE + 0x12)
#define IO_DDRD 	*(vuint32_t *)(IO_BASE + 0x11)
#define GSREG 		*(vuint32_t *)(IO_BASE + 0x3F)
#define INT_MCUCR 	*(vuint32_t *)(IO_BASE + 0x35)
#define INT_MCUCSR 	*(vuint32_t *)(IO_BASE + 0x34)
#define INT_GICR 	*(vuint32_t *)(IO_BASE + 0x3B)

void gpio_init() {
	//portD pin 5, 6, 7 --> output direction, rest ---> input direction
	IO_DDRD |= 0xE0;
}
void led_init() {
	//reset leds 5, 6, 7
	IO_PORTD &= ~(0xE0);
}
int main(void) {
	gpio_init();
	led_init();
	//make external int0 --> any logical change
	INT_MCUCR |= (1 << 0);
	//make external int1 --> rising edge
	INT_MCUCR |= 0x0C;
	//make external int2 --> falling edge (default falling)
	INT_MCUCSR &= ~(1 << 6);

	//enable all external interrupts
	INT_GICR |= 0xE0;

	//enable global interrupt
		GSREG |= (1 << 7);
	while (1) {
		//reset leds 5, 6, 7
		IO_PORTD &= ~(0xE0);
	}

}
ISR(INT0_vect) {
	IO_PORTD |= (1 << 5);
	_delay_ms(1000);
}
ISR(INT1_vect) {
	IO_PORTD |= (1 << 6);
	_delay_ms(1000);
}
ISR(INT2_vect) {
	IO_PORTD |= (1 << 7);
	_delay_ms(1000);
}
