/*
 * main.c
 *
 *  Created on: 8 lut 2026
 *      Author: kosmi
 */

#include <avr/io.h>
#include <util/delay.h>

#include "constants.h"

void my_delay(double ms) {
	while (ms--) {
		_delay_ms(1);
	}
}

void play_note(uint8_t note, uint16_t duration) {
	uint16_t sound_time = duration * 0.9;
	uint16_t pause_time = duration * 0.1;

	if (note != 0) {
		OCR0 = note;
		OCR2 = note;
		TCCR0 |= (1 << COM00);
		TCCR2 |= (1 << COM20);
	}
	my_delay(sound_time);

	TCCR0 &= ~(1 << COM00);
	TCCR2 &= ~(1 << COM20);
	my_delay(pause_time);
}

int main(void) {
	DDRB |= (1 << PB3);
	DDRD |= (1 << PD7);

	// enable CTC0
	TCCR0 |= (1 << WGM01);
	TCCR0 |= (1 << CS00) | (1 << CS01);
	TCCR0 |= (1 << COM00);

	// enable CTC2
	TCCR2 |= (1 << WGM21);
	TCCR2 |= (1 << CS20) | (1 << CS21);
	TCCR2 |= (1 << COM20);

	while (1) {
		for (uint8_t i = 0; i < (sizeof(melody_path) / sizeof(Note)); i++) {
			uint8_t p = pgm_read_byte(&(melody_path[i].pitch));
			uint16_t d = pgm_read_word(&(melody_path[i].duration));

			play_note(p, d);
		}
	}
}
