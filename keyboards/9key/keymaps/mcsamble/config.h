#undef MANUFACTURER
#define MANUFACTURER    Homegrown
#undef DESCRIPTION
#define DESCRIPTION     Handwired 9key macro pad

// Flipped to match Feather BLE
#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS { F6, F5, F4 }

#undef MATRIX_COL_PINS
// #define MATRIX_COL_PINS { D1, D0, D4 }
#define MATRIX_COL_PINS { B7, C7, D6 }

/* ws2812 RGB LED */
// #define RGB_DI_PIN F7

#undef RGBLED_NUM
#define RGBLED_NUM 6    // Number of LEDs

// Minify hex
// #define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_MODE_RAINBOW_MOOD
#define RGBLIGHT_MODE_BREATHING
