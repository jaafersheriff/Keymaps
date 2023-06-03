#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE
#include "../bongo.h"
#include "../s75.h"
#endif

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| VolD  |    | VolU  |------+------+------+------+------+------|
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
  KC_LCTL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_VOLD,  KC_VOLU,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT, \
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_SPC, MO(_RAISE), KC_LEFT, KC_RGHT \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      |      |      |  [   |   ]  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  F6  |  F7  |  F8  |  F9  |  F10 |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|  F11 |  F12 |      |  -   |  +   |-------.    ,-------|      |      |      |      |      |RShift|
 * |------+------+------+------+------+------| Mute  |    | Mute  |------+------+------+------+------+------|
 * |LCTRL |      |      |      |  _   |  =   |-------|    |-------|      |      |      |      |      |Enter |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |      | /Space  /       \Space \  |Adjust|  UP  | DOWN |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
 KC_GRAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,       KC_F5,                     XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_DEL, \
 _______,  KC_F6,   KC_F7,   KC_F8,   KC_F9,       KC_F10,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
 _______,  KC_F11,  KC_F12,  XXXXXXX, KC_MINUS,    S(KC_EQL),                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,\
 _______,  XXXXXXX, XXXXXXX, XXXXXXX, S(KC_MINUS), KC_EQL,  KC_MUTE, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,\
                              _______, _______,    _______, _______, _______, _______, KC_UP,   KC_DOWN \
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      |      |      |  {   |  }   | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  F6  |  F7  |  F8  |  F9  |  F10 |                    |      |      | Up   |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|  F11 |  F12 |      |  -   |  +   |-------.    ,-------|      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------| Mute  |    | Mute  |------+------+------+------+------+------|
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
 _______,  XXXXXXX, XXXXXXX, XXXXXXX, S(KC_MINUS), KC_EQL,  KC_MUTE, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, _______,\
                              _______, _______,    _______, _______, _______, _______, XXXXXXX, XXXXXXX\
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | PL/PA|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | PREV | NXT  |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void keyboard_post_init_user(void) {
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
// #endif
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    draw_s75();
  } else {
    draw_bongo();
  }
  return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
  }
  return true;
}
