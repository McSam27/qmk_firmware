#include "MiniVan20190915030037.h"
enum custom_keycodes {
M_IME = SAFE_RANGE
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
if (record->event.pressed) {
switch(keycode) {
case M_IME:
SEND_STRING(SS_DOWN(X_LSHIFT)SS_DOWN(X_LALT));
return false;
}
}
else {
switch(keycode) {
case M_IME:
SEND_STRING(SS_UP(X_LSHIFT)SS_UP(X_LALT));
return false;
}
}
return true;
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = KEYMAP(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, LT(2, KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, LT(1, KC_QUOT), KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, RSFT_T(KC_SLSH), KC_LCTL, MO(2), KC_LGUI, KC_LALT, KC_ENT, KC_SPC, KC_RALT, KC_LEFT, KC_DOWN, LT(3, KC_RIGHT)),
[1] = KEYMAP(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_PIPE, KC_DQT, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_4, KC_5, KC_6, KC_TRNS, KC_ENT, KC_TRNS, KC_MSTP, KC_MPLY, KC_MPRV, KC_MNXT, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_DOT, KC_ENT, KC_TRNS),
[2] = KEYMAP(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11, KC_F12, KC_TRNS, KC_LSFT, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAI, KC_TRNS, KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_SPC, KC_C, KC_TRNS, KC_TRNS, RGB_VAD, KC_TRNS),
};
void matrix_init_user(void) {
rgblight_init();
};
void rgblight_init_leds(void) {
process_indicator_update(layer_state, host_keyboard_leds());
};
void led_set_user(uint8_t usb_led) {
process_indicator_update(layer_state, usb_led);
};
uint32_t layer_state_set_user(uint32_t state) {
process_indicator_update(state, host_keyboard_leds());
return state;
};
void process_indicator_update(uint32_t state, uint8_t usb_led) {
LED_TYPE indicators[3] = {
{.r = 0, .g = 0, .b = 0},
{.r = 0, .g = 0, .b = 0},
{.r = 0, .g = 0, .b = 0}
};
uint8_t indexes[3] = {
0,
1,
2
};
indicators[0].r = 72;
indicators[0].g = 0;
indicators[0].b = 189;
if (state & (1<<1)){
indicators[0].r = 137;
indicators[0].g = 2;
indicators[0].b = 63;
}
if (state & (1<<2)){
indicators[0].r = 28;
indicators[0].g = 52;
indicators[0].b = 97;
}
if (state & (1<<3)){
indicators[0].r = 66;
indicators[0].g = 173;
indicators[0].b = 79;
}
if (state & (1<<0)){
indicators[0].r = 72;
indicators[0].g = 0;
indicators[0].b = 189;
}
indicators[1].r = 129;
indicators[1].g = 5;
indicators[1].b = 216;
if (state & (1<<1)){
indicators[1].r = 234;
indicators[1].g = 99;
indicators[1].b = 140;
}
if (state & (1<<2)){
indicators[1].r = 0;
indicators[1].g = 81;
indicators[1].b = 148;
}
if (state & (1<<3)){
indicators[1].r = 107;
indicators[1].g = 208;
indicators[1].b = 81;
}
if (state & (1<<0)){
indicators[1].r = 129;
indicators[1].g = 5;
indicators[1].b = 216;
}
indicators[2].r = 237;
indicators[2].g = 12;
indicators[2].b = 239;
if (state & (1<<1)){
indicators[2].r = 255;
indicators[2].g = 217;
indicators[2].b = 218;
}
if (state & (1<<2)){
indicators[2].r = 136;
indicators[2].g = 186;
indicators[2].b = 255;
}
if (state & (1<<3)){
indicators[2].r = 109;
indicators[2].g = 240;
indicators[2].b = 57;
}
if (state & (1<<0)){
indicators[2].r = 237;
indicators[2].g = 12;
indicators[2].b = 239;
}
rgblight_setrgb_many(indicators, indexes, 3);
};