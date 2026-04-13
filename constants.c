/*
 * constants.c
 *
 *  Created on: 18 lut 2026
 *      Author: kosmi
 */
#include <avr/pgmspace.h>

#include "structures.h"
#include "constants.h"

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
		{ DS4, T_QUARTER + T_QUAVER }, { PAUSE, T_QUAVER }, {DS4,T_QUARTER }, { FS4, T_QUARTER },
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
		{ FS4, T_WHOLE }
};
// @formatter:on

const uint16_t melody_size = sizeof(melody_path) / sizeof(Note);
