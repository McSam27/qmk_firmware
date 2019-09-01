#include QMK_KEYBOARD_H

// ==========
// MACRO
// ==========
enum custom_keycodes {
	CODE = SAFE_RANGE
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
		switch (keycode) {
            case CODE:
                SEND_STRING("code .");
                return false;
		}
    }
	return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* LAYER 0
     * ,-----------------------------------.
     * |     F1    |    F2     |   MUTE    |
     * |-----------+-----------+-----------|
     * |     FN1   |   CODE    |   ENTER   |
     * `-----------------------------------'
     */
    [0] = LAYOUT(   \
        KC_F1,          KC_F2,          KC_MUTE, \
        MO(1),          CODE,           KC_ENT \
    ),

    /* LAYER 1
     * ,------------------------------------.
     * |    HOME   |    PGUP   |   MUTE     |
     * |-----------+-----------+------------|
     * |    N/A    |    PGDN   |   BSPACE   |
     * `------------------------------------'
     */
    [1] = LAYOUT(   \
        KC_HOME,        KC_PGUP,        KC__MUTE,   \
        KC_NO,          KC_PGDN,        KC_BSPACE   \
    )
};

// ==============
// START OLED
// ==============

#ifdef OLED_DRIVER_ENABLE

// NOTE:: used to print to OLED
// oled_write_P(PSTR("       ISOpad"), false);

void render_logo(void) {
    static const char PROGMEM isopad_logo[] = {
        0x80, 0x80, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
    oled_write_P(isopad_logo, false);
}

void oled_task_user(void) {
    render_logo();
}

#endif

// ==============
// ENCODER
// ==============
#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
     /* First encoder */
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}

#endif
