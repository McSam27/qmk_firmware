#include "aio50.h"

/* Layer 0
 * .-----------------------------------------------------------------------------------------------------------------------------------,
 * |          | ESC        | F1        | F2        | F3        | F4        | F5        | F6        | F7        | F8        |    OLED   |
 * |----------+------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+--------+--------+--------|
 * | HOME     | `~         | Q         | W         | E         | R         | T         | Y         | U         | I         | O         | P      | Del    | Bcksp  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | END      | TAB        | A         | S         | D         | F         | G         | H         | J         | K         | L      | ;      | '               |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PGUP     | SHIFT      | Z         | X         | C         | V         | B         | N         | M         | ,         | .      | /      | Shift/Enter     |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PGDN     |  CTRL      | GUI       | ALT       | FN2       | Enter/FN1 |  Space/FN1 | Raise  | Left   | Down   | Up     | Right  |  Shift |   0     |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    KEYMAP(
    KC_ESC    , KC_F1  , KC_F2  , KC_F3  , KC_F4, KC_F5 , KC_F6 , KC_F7  , KC_F8,
    KC_1      , KC_GESC, KC_Q   , KC_W   , KC_E , KC_R  , KC_T  , KC_Y   , KC_U , KC_I   , KC_O   , KC_P   , KC_DEL   , KC_BSPC,
    KC_2      , KC_TAB , KC_A   , KC_S   , KC_D , KC_F  , KC_G  , KC_H   , KC_J , KC_K   , KC_L   , KC_SCLN, KC_QUOT  ,
    KC_3      , KC_LSFT, KC_Z   , KC_X   , KC_C , KC_V  , KC_B  , KC_N   , KC_M , KC_COMM, KC_DOT , KC_SLSH, KC_SFTENT,
    KC_4      , KC_LCTL, KC_LALT, KC_LGUI, KC_TRANSPARENT, KC_ENT, LT(1, KC_SPC), KC_LEFT, KC_UP, KC_DOWN, KC_RGHT
    ),

    KEYMAP(
              KC_ESC , KC_F1  , KC_F2  , KC_F3, KC_F4 , KC_F5       , KC_F6        , KC_F7 , KC_F8  ,
    KC_1    , KC_GESC, KC_1   , KC_2   , KC_3 , KC_4  , KC_5        , KC_6         , KC_7  , KC_8   , KC_9   , KC_0   , KC_MINUS , KC_EQUAL,
    KC_2    , KC_TAB , KC_A   , KC_S   , KC_D , KC_F  , KC_LBRACKET , KC_RBRACKET  , KC_4  , KC_5   , KC_6   , KC_SCLN, KC_QUOT  ,
    KC_3    , KC_LSFT, KC_Z   , KC_X   , KC_C , KC_V  , KC_B        , KC_N         , KC_1  , KC_2   , KC_3   , KC_SLSH, KC_SFTENT,
    RESET   , KC_LCTL, KC_LALT, KC_LGUI, RESET, KC_ENT,               KC_TRNS      ,         KC_0   , KC_DOT , KC_DOWN, KC_RGHT
    )

};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!isLeftHand)
    return OLED_ROTATION_180;  // flips the display 180 to see it from my side
  return rotation;
}

const char *read_logo(void);
void oled_task_user(void){
    switch (biton32(layer_state)){
        case _DVORAK:
            oled_write_ln_P(PSTR("DVRK"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("LOWER"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("RAISE"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJST"), false);
            break;
        default:
            oled_write_ln_P(PSTR("?????"), false);
    }
  //now print logo
  oled_write(read_logo(), false);
}
#endif

// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
// 	keyevent_t event = record->event;
// 	switch (id) {
// 	}
// 	return MACRO_NONE;
// }

// OLED

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};

    oled_write_P(qmk_logo, false);
}


    void
    matrix_init_user(void) {}

void matrix_scan_user(void) {}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    render_logo();

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
