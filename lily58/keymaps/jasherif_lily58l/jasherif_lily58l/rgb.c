#pragma once

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
// left hand
{      5 ,  4 ,  3 ,  2 ,  1 ,      0 },
{      6 ,  7 ,  8 ,  9 , 10 ,     10 },
{     15 , 14 , 13 , 12 , 11 ,     10 },
{     16 , 17 , 18 , 19 , 20 ,     21 },
{ NO_LED , 26 , 25 , 24 , 23 ,     22 },
// right hand
{     39+1 , 38+1 , 37+1 , 36+1 , 35+1 ,     34+1 },
{     40+1 , 41+1 , 42+1 , 43+1 , 44+1 ,     45+1 },
{     51+1 , 50+1 , 49+1 , 48+1 , 47+1 ,     46+1 },
{     52+1 , 53+1 , 54+1 , 55+1 , 56+1 ,     57+1 },
{ NO_LED , 62+1 , 61+1 , 60+1 , 59+1 ,     58+1 }
}, {

// left hand
{ 89,  4}, { 72,  3}, { 54,  1}, { 37,  2}, { 19,  6}, {  1,  7},
{  1, 21}, { 19, 20}, { 37, 17}, { 54, 16}, { 72, 17}, { 89, 19},
{ 89, 33}, { 72, 31}, { 54, 30}, { 37, 31}, { 19, 35}, {  1, 36},
{  1, 50}, { 19, 49}, { 37, 46}, { 54, 44}, { 72, 46}, { 89, 47},
           {107, 40}, {104, 62}, { 81, 61}, { 63, 60}, { 45, 60},

// right hand
{135, 55}, {170, 52}, {205, 42}, {205, 13}, {170,  9}, {135, 12}, // backlight
{135,  4}, {152,  3}, {170,  1}, {187,  2}, {205,  6}, {223,  7},
{223, 21}, {205, 20}, {187, 17}, {170,  1}, {152, 17}, {135, 19},
{135, 33}, {152, 31}, {170, 30}, {187, 31}, {205, 35}, {223, 36},
{223, 50}, {205, 49}, {187, 46}, {170, 44}, {152, 46}, {135, 47},
           {117, 40}, {120, 62}, {143, 61}, {161, 60}, {179, 60}
}, {

// left hand
LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_MODIFIER,
LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
LED_FLAG_MODIFIER,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
                    LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,

// right hand
LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
LED_FLAG_MODIFIER,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_MODIFIER,
                    LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER,  LED_FLAG_MODIFIER

} };
#endif

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
rgblight_config_t        RGB_current_config;
#endif

#ifdef RGB_MATRIX_ENABLE
extern rgb_config_t rgb_matrix_config;
rgb_config_t        RGB_current_config;
#endif

void save_rgb_config(void) {
#ifdef RGBLIGHT_ENABLE
    RGB_current_config.enable = rgblight_config.enable;
    RGB_current_config.mode   = rgblight_get_mode();
    RGB_current_config.speed  = rgblight_get_speed();
    RGB_current_config.hue    = rgblight_get_hue();
    RGB_current_config.sat    = rgblight_get_sat();
    RGB_current_config.val    = rgblight_get_val();
#elif RGB_MATRIX_ENABLE
    RGB_current_config.enable = rgb_matrix_config.enable;
    RGB_current_config.mode   = rgb_matrix_get_mode();
    RGB_current_config.speed  = rgb_matrix_config.speed;
    RGB_current_config.hsv    = rgb_matrix_config.hsv;
#endif
}

void restore_rgb_config(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_set_speed_noeeprom(RGB_current_config.speed);
    if (rgblight_config.mode != RGB_current_config.mode) {
        rgblight_mode_noeeprom(RGB_current_config.mode);
    }
    if ((RGB_current_config.hue != rgblight_config.hue) || (RGB_current_config.sat != rgblight_config.sat) || (RGB_current_config.val != rgblight_config.val)) {
        rgblight_sethsv_noeeprom(RGB_current_config.hue, RGB_current_config.sat, RGB_current_config.val);
    }
    if (rgblight_config.enable) {
        rgblight_enable_noeeprom();
    } else {
        rgblight_disable_noeeprom();
    }
#elif RGB_MATRIX_ENABLE
    rgb_matrix_config.speed   = RGB_current_config.speed;
    if (rgb_matrix_config.mode != RGB_current_config.mode) {
        rgb_matrix_mode_noeeprom(RGB_current_config.mode);
    }
    if ((RGB_current_config.hsv.h != rgb_matrix_config.hsv.h) || (RGB_current_config.hsv.s != rgb_matrix_config.hsv.s) || (RGB_current_config.hsv.v != rgb_matrix_config.hsv.v)) {
        rgb_matrix_sethsv_noeeprom(RGB_current_config.hsv.h, RGB_current_config.hsv.s, RGB_current_config.hsv.v);
    }
    if (rgb_matrix_config.enable) {
        rgb_matrix_enable_noeeprom();
    } else {
        rgb_matrix_disable_noeeprom();
    }
#endif
}

void rgb_by_layer(int layer) {
#ifdef RGBLIGHT_ENABLE
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
#elif RGB_MATRIX_ENABLE
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
#endif

    switch (layer) {
        case _ADJUST:
            rgblight_sethsv_noeeprom(9, 255, 255);
            break;
        case _RAISE:
            rgblight_sethsv_noeeprom(HSV_CYAN);
            break;
        case _LOWER:
            rgblight_sethsv_noeeprom(HSV_MAGENTA);
            break;
        default:
            rgblight_sethsv_noeeprom(HSV_RED);
    }
}
