#include QMK_KEYBOARD_H

#include "../jasherif_keymap.h"


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void keyboard_post_init_user(void) {
}

#ifdef OLED_ENABLE
#include "../bongo.h"
#include "../s75.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  // if (is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  // return rotation;
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    draw_s75();
  } else {
    draw_bongo();
  }
  return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
  }
  return true;
}
