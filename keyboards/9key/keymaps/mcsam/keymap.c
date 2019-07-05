#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT( \
        KC_1,   KC_2,   KC_3,        \
        KC_4,   KC_5,   KC_6,        \
        KC_7,   KC_8,   LT(1,KC_9)   \
    ),
	[1] = LAYOUT( \
        KC_PLUS,    KC_UNDS,    KC_ASTR,   \
        KC_BSPC,    KC_ENT,     KC_SLSH,    \
        LT(2,KC_0), KC_DOT,     KC_NO    \
    ),
	[2] = LAYOUT( \
        RGB_MODE_FORWARD, RGB_SAD,   RGB_SAI, \
        RGB_VAD,    RGB_HUI,    RGB_VAI, \
        KC_NO,      RGB_HUD,    KC_NO \
    )
};
