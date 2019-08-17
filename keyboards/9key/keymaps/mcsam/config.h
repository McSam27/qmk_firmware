#undef MANUFACTURER
#define MANUFACTURER    Homegrown
#undef DESCRIPTION
#define DESCRIPTION     Handwired 9key macro pad

#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS { E6, B4, B5 }
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS { B3, B2, B6 }

#undef RGB_DI_PIN
#define RGB_DI_PIN B1

#undef RGBLED_NUM
#define RGBLED_NUM 8    // Number of LEDs3

#define RGBLIGHT_ANIMATIONS
