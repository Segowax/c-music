/*
 * timer0.c
 *
 *  Created on: 13 kwi 2026
 *      Author: kosmi
 */

#include <avr/io.h>

#include "timer0.h"

void timer0_init() {
	DDRB |= (1 << PB0);
	TCCR0A |= (1 << WGM01) | (1 << COM0A0);
	TCCR0B |= (1 << CS01) | (1 << CS00);
}
