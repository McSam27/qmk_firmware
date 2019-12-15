#include "aio50.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,
		KC_1, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL, KC_BSPC,
		KC_2, KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
		KC_3, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT(KC_ENT),
		KC_4, KC_LCTL, KC_LALT, KC_LGUI, RESET, KC_ENT, KC_SPC, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT)
};

// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
// 	keyevent_t event = record->event;

// 	switch (id) {

// 	}
// 	return MACRO_NONE;
// }

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

// Encoder
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_PGDN);
    } else {
      tap_code(KC_PGUP);
    }
  }
}

// void led_set_user(uint8_t usb_led) {

// 	if (usb_led & (1 << USB_LED_NUM_LOCK)) {

// 	} else {

// 	}

// 	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {

// 	} else {

// 	}

// 	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

// 	} else {

// 	}

// 	if (usb_led & (1 << USB_LED_COMPOSE)) {

// 	} else {

// 	}

// 	if (usb_led & (1 << USB_LED_KANA)) {

// 	} else {

// 	}

// }
