/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0007
#define DEVICE_VER 		0x0001
#define MANUFACTURER    McSam
#define PRODUCT         isoPad
#define DESCRIPTION     McSam isoPad

/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 3

/* PCB default pin-out */
#define MATRIX_ROW_PINS { B1, B3 }
#define MATRIX_COL_PINS { E6, B5, B4 }
#define UNUSED_PINS

/* ws2812 RGB LED */
// #define RGB_DI_PIN F7

// #define RGBLED_NUM 1    // Number of LEDs

/* encoder */
#define NUMBER_OF_ENCODERS 1
#define ENCODERS_PAD_A { D5 }
#define ENCODERS_PAD_B { F1 }
#define ENCODER_RESOLUTION 4

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define TAPPING_TERM 200

#endif
