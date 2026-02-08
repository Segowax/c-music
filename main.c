/*
 * main.c
 *
 *  Created on: 8 lut 2026
 *      Author: kosmi
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRB |= (1 << PB0);
	while (1) {
		PORTB ^= (1 << PB0);
		_delay_ms(1000);
	}
}
