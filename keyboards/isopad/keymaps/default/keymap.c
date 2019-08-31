#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0
 * ,-----------------------.
 * |   1   |   2   |   3   |
 * |-------+-------+-------|
 * |   4   |   5   |   6   |
 * `-----------------------'
 */
[0] = LAYOUT( \
  KC_1,       KC_2,      KC_3,       \
  KC_4,       KC_5,      KC_6       \
),

/* LAYER 1
 * ,-----------------------.
 * |  ESC  |   +   |   -   |
 * |-------+-------+-------|
 * |  BSPC |   *   |   /   |
 * `-----------------------'
 */
[1] = LAYOUT( \
  KC_ESC,   KC_PLUS, KC_MINS, \
  KC_ENTER, KC_ASTR, KC_SLSH \
)

};
