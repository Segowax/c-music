/*
 * main.c
 *
 *  Created on: 8 luty 2026
 *      Author: nax
 */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "constants.h"
#include "setup/timer0.h"

int main(void) {
	timer0_init();
	sei();

	while (1) {
		for (uint8_t i = 0; i < melody_size; i++) {
			uint8_t current_pitch = pgm_read_byte(&(melody_path[i].pitch));
			uint16_t current_duration = pgm_read_word(
					&(melody_path[i].duration));

			if (current_pitch == PAUSE) {
				TCCR0A &= ~(1 << COM0A0);
				PORTB &= ~(1 << PB0);
			} else {
				TCCR0A |= (1 << COM0A0);
				OCR0A = current_pitch;
			}

			while (current_duration > 0) {
				_delay_ms(1);
				current_duration--;
			}
		}
	}
}
