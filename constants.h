/*
 * constants.h
 *
 *  Created on: 11 lut 2026
 *      Author: kosmi
 */

#include <avr/pgmspace.h>

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define BPM 118
#define T_QUARTER 60000/BPM
#define T_WHOLE   T_QUARTER*4
#define T_HALF    T_QUARTER*2
#define T_QUAVER T_QUARTER/2
#define T_SEMIQUAVER  T_QUARTER/4
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

// @formatter:off
const Note melody_path[] PROGMEM  = {
		{ A4, T_QUARTER }, { E5, T_QUAVER }, { DS5, T_QUAVER }, { B4, T_QUARTER }, { GS4, T_QUARTER },
		{ B4, T_HALF }, { GS4, T_QUARTER }, { B4, T_QUARTER },
		{ AS4, T_HALF + T_QUARTER }, { FS4, T_QUARTER },
		{ DS4, T_QUARTER }, {PAUSE, T_QUARTER }, { DS4, T_QUARTER }, { FS4, T_QUARTER },
		{ FS4, T_QUARTER }, {E5, T_QUAVER }, { DS5, T_QUAVER }, { B4, T_QUARTER }, { GS4, T_QUARTER },
		{ B4, T_HALF }, { GS4, T_QUARTER }, { B4, T_QUARTER },
		{ AS4,T_HALF }, { PAUSE, T_QUARTER }, {AS4, T_QUARTER},

		{ FS5, T_WHOLE},
		{ FS5, T_QUARTER}, { E5, T_QUARTER }, { DS5, T_QUARTER }, { CS5,T_QUARTER },
		{ B4, T_QUARTER + T_QUAVER }, { PAUSE, T_QUAVER }, { B4,T_QUARTER }, { CS5,T_QUARTER },
		{ AS4, T_HALF + T_QUARTER }, {FS4, T_QUAVER }, {F4,T_SEMIQUAVER }, { E4, T_SEMIQUAVER },
		{ DS4, T_QUARTER+T_QUAVER }, { PAUSE, T_QUAVER }, {DS4,T_QUARTER }, { FS4, T_QUARTER },
		{ A4, T_QUARTER }, { E5, T_QUARTER }, {DS5,T_QUARTER }, { CS5, T_QUARTER },

		{ AS4, T_HALF }, { B4, T_QUARTER }, { CS5,T_QUARTER },
		{ AS4, T_HALF }, { FS4, T_QUARTER + T_QUAVER }, { PAUSE,T_QUAVER },
		{ FS4, T_QUARTER + T_QUAVER }, { PAUSE, T_QUAVER }, { FS4, T_QUARTER }, { GS4,T_QUARTER },
		{ A4, T_QUARTER }, { FS5, T_QUARTER }, { DS5, T_QUAVER }, { E5, T_QUAVER }, { DS5, T_QUAVER }, { B4,T_QUAVER },
		{ GS4, T_QUARTER + T_QUAVER }, { PAUSE, T_QUAVER }, { GS4, T_QUARTER }, { B4,T_QUARTER },

		{ AS4, T_HALF + T_QUARTER }, { FS4, T_QUARTER },
		{ DS4, T_QUARTER + T_QUAVER }, {PAUSE, T_QUAVER}, { DS4, T_QUARTER }, { FS4, T_QUARTER },
		{ FS4, T_QUARTER }, {E5, T_QUAVER }, { DS5, T_QUAVER }, { B4, T_QUARTER }, { GS4,T_QUARTER },
		{ B4, T_HALF }, { GS4,T_QUARTER }, { B4,T_QUARTER },

		{ B4, T_QUARTER }, { AS4,T_QUARTER + T_QUAVER }, { PAUSE, T_QUAVER }, { AS4, T_QUARTER },
		{ FS5, T_WHOLE },
		{ FS5, T_QUARTER}, { E5, T_QUARTER }, { DS5, T_QUAVER }, {E5, T_QUAVER }, { DS5, T_QUARTER },
		{ CS5, T_QUARTER }, { B4,T_QUARTER }, { GS4, T_QUARTER }, { B4, T_QUARTER },

		{ AS4, T_HALF + T_QUARTER }, { FS5, T_QUAVER }, { F5,T_SEMIQUAVER }, { E5, T_SEMIQUAVER },
		{ DS5, T_QUARTER + T_QUAVER }, { PAUSE, T_QUAVER }, { DS5,T_QUARTER }, { CS5, T_QUARTER },
		{ B4, T_HALF }, { AS4,T_QUAVER }, { B4, T_QUAVER }, { AS4, T_QUARTER },
		{ FS4, T_QUARTER + T_QUAVER }, {PAUSE, T_QUAVER }, { FS4, T_QUARTER }, { AS4, T_QUARTER },

		{ FS4, T_WHOLE },
		{ FS4, T_WHOLE }};
// @formatter:on

#endif /* CONSTANTS_H_ */
