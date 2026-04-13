/*
 * constants.h
 *
 *  Created on: 11 luty 2026
 *      Author: nax
 */

#include "structures.h"

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define BPM 118
#define T_QUARTER 60000/BPM
#define T_WHOLE   T_QUARTER*4
#define T_HALF    T_QUARTER*2
#define T_QUAVER T_QUARTER/2
#define T_SEMIQUAVER  T_QUARTER/4
#define PAUSE 0

// For prescaler N=64
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

#define C6 59
#define CS6 55
#define D6 52
#define DS6 49
#define E6 46
#define F6 44
#define FS6 41

extern const Note melody_path[];
extern const uint16_t melody_size;

#endif /* CONSTANTS_H_ */
