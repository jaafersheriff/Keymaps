#include QMK_KEYBOARD_H
#include "print.h"

#include "../jasherif_keymap.h"

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void keyboard_post_init_user(void) {
//     debug_enable = true;
// #ifdef CONSOLE_ENABLE
//     xprintf("keyboard init user\n");
//     dprintf("keyboard init user\n");
// #endif
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
// #ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
// #ifdef CONSOLE_ENABLE
//   xprintf("oled init user\n");
//   dprintf("oled init user\n");
// #endif
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
// #ifdef CONSOLE_ENABLE
//     xprintf("oled task master\n");
//     dprintf("oled task master\n");
// #endif
    oled_write(read_logo(), false);
    //oled_write_ln(read_layer_state(), false);
    //oled_write_ln(read_keylog(), false);
    //oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), true);
  }
}
// #endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
// #ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
// #endif
    // set_timelog();
  }
  return true;
}
