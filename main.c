/*
 * main.c
 *
 *  Created on: 8 lut 2026
 *      Author: kosmi
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "constants.h"

volatile uint32_t music_ms = 0;
void update_track(Track *track, volatile uint8_t *ocr_reg,
		volatile uint8_t *tccr_reg, uint8_t com_bit);

ISR(TIMER1_COMPA_vect) {
	music_ms++;
}

int main(void) {
	DDRB &= ~(1 << PB0);
	DDRB |= (1 << PB3);
	DDRD |= (1 << PD7);

	PORTB |= (1 << PB0);

	// enable CTC0
	TCCR0 |= (1 << WGM01);
	TCCR0 |= (1 << CS00) | (1 << CS01);

	// enable CTC2
	TCCR2 |= (1 << WGM21);
	TCCR2 |= (1 << CS21) | (1 << CS22);

	TCCR1B |= (1 << WGM12);
	TCCR1B |= (1 << CS11) | (1 << CS10);
	OCR1A = 124;
	TIMSK |= (1 << OCIE1A);

	Track melody = { .notes = melody_path, .size = sizeof(melody_path)
			/ sizeof(Note), .current_id_note = 0, .next_note_in = 0,
			.is_playing = 0 };
	Track support = { .notes = support_path, .size = sizeof(support_path)
			/ sizeof(Note), .current_id_note = 0, .next_note_in = 0,
			.is_playing = 0 };

	sei();

	while (1) {
		if (!(PINB & (1 << PB0))) {
			melody.is_playing = 1;
			support.is_playing = 1;
		}

		if (melody.is_playing)
			update_track(&melody, &OCR0, &TCCR0, COM00);
		if (support.is_playing)
			update_track(&support, &OCR2, &TCCR2, COM20);
		if (!support.is_playing && !melody.is_playing)
			music_ms = 0;
	}
}

void update_track(Track *track, volatile uint8_t *ocr_reg,
		volatile uint8_t *tccr_reg, uint8_t com_bit) {

	if (track->current_id_note > track->size) {
		track->current_id_note = 0;
		track->next_note_in = 0;
		track->is_playing = 0;
		*tccr_reg &= ~(1 << com_bit);
	} else if (music_ms >= track->next_note_in) {
		uint8_t current_pitch = pgm_read_byte(
				&(track->notes[track->current_id_note].pitch));
		uint16_t current_duration = pgm_read_word(
				&(track->notes[track->current_id_note].duration));

		if (current_pitch == PAUSE) {
			*tccr_reg &= ~(1 << com_bit);
		} else {
			*ocr_reg = current_pitch;
			*tccr_reg |= (1 << com_bit);
		}

		track->next_note_in = music_ms + current_duration;
		track->current_id_note++;
	}
}
