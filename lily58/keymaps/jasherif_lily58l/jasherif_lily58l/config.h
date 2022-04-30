/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2020 Ben Roesner (keycapsss.com)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define ENCODERS_PAD_A { F4 }
#define ENCODERS_PAD_B { F5 }
#define ENCODER_RESOLUTION 5

#undef RGBLIGHT_ENABLE

#define RGBLIGHT_SLEEP

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_KEYPRESSES
#    ifdef RGBLED_NUM
#        undef RGBLED_NUM
#    endif
#    define RGBLED_NUM 64  // Number of LEDs
#    define DRIVER_LED_TOTAL RGBLED_NUM

#    ifdef RGBLED_SPLIT
#       undef RGBLED_SPLIT
#    endif

#    define RGBLED_SPLIT { 29, 35 } 
#    define RGB_MATRIX_SPLIT RGBLED_SPLIT

#    define RGB_MATRIX_KEYPRESSES                // reacts to keypresses
#    define RGB_DISABLE_WHEN_USB_SUSPENDED true  // turn off effects when suspended
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255    // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.

#    define ENABLE_RGB_MATRIX_SOLID_COLOR
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define ENABLE_RGB_MATRIX_SPLASH
#    define ENABLE_RGB_MATRIX_MULTISPLASH
#    define ENABLE_RGB_MATRIX_SOLID_SPLASH
#    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#    ifdef RGB_MATRIX_STARTUP_MODE   
#       undef RGB_MATRIX_STARTUP_MODE
#    endif
#    define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR 
#endif

#define SPLIT_TRANSPORT_MIRROR
// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK
