 /* Copyright 2017 F_YUUCHI
  * Copyright 2020 Drashna Jaelre <@drashna>
  * Copyright 2020 Ben Roesner (keycapsss.com)
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes { QWERTY = SAFE_RANGE, LOWER, RAISE, ADJUST, };

#if defined(RGB_MATRIX_ENABLE)
#include "rgb.c"
#endif

#ifdef OLED_ENABLE
#include "../bongo.h"
#endif

extern uint8_t is_master;

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| Mute  |    | RGB T |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |Enter |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Space \  |RAISE | LEFT |RIGHT |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LCTRL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,  RGB_TOG,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT, \
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_SPC, MO(_RAISE), KC_LEFT, KC_RGHT \
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      |      |      |  [   |   ]  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  F6  |  F7  |  F8  |  F9  |  F10 |                    |      |RGB_SP|      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|  F11 |  F12 |      |  -   |  +   |-------.    ,-------|      |RGB_sp|RGB_HI|RGB_SI|RGB_VI|RShift|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LCTRL |      |      |      |  _   |  =   |-------|    |-------|      | RGB M|RGB_HD|RGB_SD|RGB_VD|Enter |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |      | /Space  /       \Space \  |Adjust|  UP  | DOWN |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
 KC_GRAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,       KC_F5,                     XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_DEL, \
 _______,  KC_F6,   KC_F7,   KC_F8,   KC_F9,       KC_F10,                    XXXXXXX, RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
 _______,  KC_F11,  KC_F12,  XXXXXXX, KC_MINUS,    S(KC_EQL),                 XXXXXXX, RGB_SPD, RGB_HUI, RGB_SAI, RGB_VAI, KC_RSFT,\
 _______,  XXXXXXX, XXXXXXX, XXXXXXX, S(KC_MINUS), KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,\
                              _______, _______,    _______, _______, _______, _______, KC_UP,   KC_DOWN \
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      |      |      |  {   |  }   | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  F6  |  F7  |  F8  |  F9  |  F10 |                    |      |      | Up   |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|  F11 |  F12 |      |  -   |  +   |-------.    ,-------|      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LCTRL |      |      |      |  _   |  =   |-------|    |-------|      |      |      |      |      |Enter |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |Adjust| /Space  /       \Space \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT( \
 KC_GRAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,       KC_F5,                     XXXXXXX, XXXXXXX, XXXXXXX, S(KC_LBRC), S(KC_RBRC), KC_DEL, \
 _______,  KC_F6,   KC_F7,   KC_F8,   KC_F9,       KC_F10,                    XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,    XXXXXXX, XXXXXXX,\
 _______,  KC_F11,  KC_F12,  XXXXXXX, KC_MINUS,    S(KC_EQL),                 XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT,   XXXXXXX, XXXXXXX,\
 _______,  XXXXXXX, XXXXXXX, XXXXXXX, S(KC_MINUS), KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, _______,\
                              _______, _______,    _______, _______, _______, _______, XXXXXXX, XXXXXXX\
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Space \  |RAISE | Up   | Down |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
// #if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
//     /* For any layer other than default, save current RGB state and switch to layer-based RGB */
//     if (layer_state_cmp(state, 0)) {
//         restore_rgb_config();
//     } else {
//         uint8_t layer = get_highest_layer(state);
//         if (layer_state_cmp(layer_state, 0)) save_rgb_config();
//         rgb_by_layer(layer);
//     }
// #endif
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

bool oled_task_user(void) {
  // update_log();
  if (is_keyboard_master()) {
    return false;
  } else {
    // oled_write(read_logo(), false);
    draw_bongo();
  }
  return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
    }
//     switch (keycode) {
//         case LOWER:
//             if (record->event.pressed) {
//                 layer_on(_LOWER);
//             } else {
//                 layer_off(_LOWER);
//             }
//             return false;
//         case RAISE:
//             if (record->event.pressed) {
//                 layer_on(_RAISE);
//             } else {
//                 layer_off(_RAISE);
//             }
//             return false;
//         case ADJUST:
//             if (record->event.pressed) {
//                 layer_on(_ADJUST);
//             } else {
//                 layer_off(_ADJUST);
//             }
//             return false;
// 
// #if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
//         case RGB_TOG:
//              /* Override layer-based RGB and resume RGB effect to be able to preview changes */
//              if (record->event.pressed) {
//                  rgb_matrix_toggle();
//                  save_rgb_config();
//              }
//              return false;
//         case RGB_MOD:
//              /* Override layer-based RGB and resume RGB effect to be able to preview changes */
//              if (record->event.pressed) {
//                  rgb_matrix_step();
//                  save_rgb_config();
//              }
//              return false;
// 
//         case RGB_HUI:
//         case RGB_HUD:
//         case RGB_SAI:
//         case RGB_SAD:
//         case RGB_VAI:
//         case RGB_VAD:
//         case RGB_SPI:
//         case RGB_SPD:
//              /* Override layer-based RGB and resume RGB effect to be able to preview changes */
//              if (record->event.pressed) {
//                  restore_rgb_config();
//                  process_rgb(keycode, record);
//                  save_rgb_config();
//              }
//              return false;
//         case RGBRST:
//              if (record->event.pressed) {
// #    if RGB_MATRIX_ENABLE
//                 eeconfig_update_rgb_matrix_default();
//                 rgb_matrix_enable();
// #    endif
//                 save_rgb_config();
//              }
//              return false;
//  #endif
//     }
    return true;
}

// Rotary encoder related code
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { // Encoder on master side
      if (clockwise) {
          tap_code(KC_VOLU);
      } else {
          tap_code(KC_VOLD);
      }
  }
  return true;
}
#endif
