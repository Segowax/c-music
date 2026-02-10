/*
 * main.c
 *
 *  Created on: 8 lut 2026
 *      Author: kosmi
 */

#include <avr/io.h>
#include <util/delay.h>

#define BPM 118
#define T_CWIERC 60000/BPM
#define T_CALA   T_CWIERC*4
#define T_POL    T_CWIERC*2
#define T_OSEMKA T_CWIERC/2
#define T_SZESN  T_CWIERC/4

#define PAUSE 0

#define C4  238
#define CS4 225
#define D4  212
#define DS4 200
#define E4  189
#define F4  178
#define FS4 168
#define G4  158
#define GS4 149
#define A4  141
#define AS4 133
#define B4  126

#define C5  118
#define CS5 112
#define D5  105
#define DS5 99
#define E5  94
#define F5  88
#define FS5 83
#define G5  79
#define GS5 74
#define A5  70
#define AS5 66
#define B5  62

typedef struct {
	uint8_t pitch;
	uint16_t duration;
} Note;

Note song[] = { { A4, T_CWIERC }, { E5, T_OSEMKA }, { DS5, T_OSEMKA }, { B4,
T_CWIERC }, { GS4,
T_CWIERC }, { B4,
T_POL }, { GS4, T_CWIERC }, { B4,
T_OSEMKA }, { AS4, T_POL + T_CWIERC }, { FS4, T_CWIERC }, { DS4, T_CWIERC }, {
PAUSE,
T_OSEMKA }, { DS4, T_CWIERC }, { FS4, T_OSEMKA }, { PAUSE, T_OSEMKA }, {
E5,
T_OSEMKA }, { DS5, T_OSEMKA }, { B4, T_CWIERC }, { GS4, T_CWIERC }, { B4,
T_CWIERC }, { AS4, T_POL }, { PAUSE, T_CWIERC }, { AS4, T_CWIERC }, { FS5,
T_CALA }, { PAUSE, T_CWIERC }, { E5, T_CWIERC }, { DS5, T_CWIERC }, { CS5,
T_CWIERC }, { B4, T_CWIERC }, { PAUSE, T_OSEMKA }, { B4, T_CWIERC }, { CS5,
T_CWIERC }, { AS4, T_POL + T_CWIERC }, { PAUSE, T_OSEMKA }, { FS4, T_OSEMKA }, {
F4,
T_SZESN }, { E4, T_SZESN }, { DS4, T_CWIERC }, { PAUSE, T_OSEMKA }, {
DS4,
T_CWIERC }, { FS4, T_CWIERC }, { A4, T_CWIERC }, { E5, T_CWIERC }, {
DS5,
T_CWIERC }, { CS5, T_CWIERC }, { AS4, T_CWIERC }, { B4, T_CWIERC }, {
CS5,
T_CWIERC }, { AS4, T_CWIERC }, { FS4, T_CWIERC }, { PAUSE, T_OSEMKA }, {
FS4,
T_CWIERC }, { PAUSE, T_OSEMKA }, { FS4, T_OSEMKA }, { PAUSE, T_SZESN }, { GS4,
T_CWIERC } };

void my_delay(double ms) {
	while (ms--) {
		_delay_ms(1);
	}
}

void play_note(uint8_t note, uint16_t ms) {
	uint16_t sound_time = ms * 0.9;
	uint16_t pause_time = ms * 0.1;

	if (note != 0) {
		OCR0 = note;
		TCCR0 |= (1 << COM00);
	}
	my_delay(sound_time);

	TCCR0 &= ~(1 << COM00);
	my_delay(pause_time);
}

int main(void) {
	DDRB |= (1 << PB3);

	// enable CTC
	TCCR0 |= (1 << WGM01);
	TCCR0 |= (1 << CS00) | (1 << CS01);
	TCCR0 |= (1 << COM00);

	while (1) {
		for (uint8_t i = 0; i < (sizeof(song) / sizeof(Note)); i++) {
			play_note(song[i].pitch, song[i].duration);
		}
	}
}
