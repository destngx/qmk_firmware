#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _FN1_LAYER,
  _FN2_LAYER,
};

enum custom_keycodes {
  ALT_1 = SAFE_RANGE,
  ALT_2,
  ALT_3,
  ALT_4,
  ALT_5,
  ALT_6,
  ALT_7,
  ALT_8,
  ALT_9,
  ALT_0,
  ALT_MINS,
  ALT_EQL,
};

// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Ctrl    |  a  |alt s|sft d| gui f |  g  |  h  |gui j|sft k|alt l|  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  GUI  |  Alt  |               space             |  Alt  |  APP  | LEFT  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE_LAYER] = KEYMAP( /* Base */
     KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
     KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
       LCTL_T(KC_ESC), KC_A, LALT_T(KC_S), LSFT_T(KC_D), LGUI_T(KC_F), KC_G, KC_H, LGUI_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP),
      MO(_FN1_LAYER), MO(_FN2_LAYER), KC_LGUI, KC_SPC, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT
),
  /*
  * Layer _FN1_LAYER (Numpad Layer)
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  7  |  8  |  9  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |  a  |  s  |  d  |  f  |  g  |  h  |  4  |  5  |  6  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  0  |  1  |  2  |  3  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * |  FN2  |  FN1  |  GUI  |               space             |  Alt  |  APP  |  FN1  |  FN2  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
   [_FN1_LAYER] = KEYMAP( /* Base */
      KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
      KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_PSCR, KC_AP_LED_NEXT_PROFILE, KC_AP_LED_PREV_PROFILE, KC_AP_LED_ON,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_MPRV, KC_MNXT, KC_MPLY,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_MPRV, KC_MNXT, KC_TRNS, KC_MPLY, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN2_LAYER), KC_TRNS
   ),
   /*
   * Layer _FN2_LAYER (Numpad Layer)
   * ,-----------------------------------------------------------------------------------------.
   * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  7  |  8  |  9  | PS | HOME | END |   \    |
   * |-----------------------------------------------------------------------------------------+
   * | Esc     |  a  |  s  |  d  |  f  |  g  |  h  |  4  |  5  |  6  | PGUP|PGDN |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * | Shift      |  z  |  x  |  c  |  v  |  0  |  1  |  2  |  3  |INSRT| DEL |    Shift       |
   * |-----------------------------------------------------------------------------------------+
   * |  FN2  |  FN1  |  GUI  |               space             |  Alt  |  APP  |  FN1  |  FN2  |
   * \-----------------------------------------------------------------------------------------/
   *
   */
  [_FN2_LAYER] = KEYMAP( /* Base */
     KC_GRV, ALT_1, ALT_2, ALT_3, ALT_4, ALT_5, ALT_6, ALT_7, ALT_8, ALT_9, ALT_0, ALT_MINS, ALT_EQL, KC_DEL,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_7, KC_8, KC_9, KC_PSCR, KC_HOME, KC_END, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_4, KC_5, KC_6, KC_PGUP, KC_PGDN, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_INS, KC_DEL, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN1_LAYER), KC_TRNS
 ),
};
const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

// Code to run after initializing the keyboard
void keyboard_post_init_user(void) {
    annepro2LedEnable();
    annepro2LedSetProfile(5);
}

// Handle custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_1:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_TAP(X_1) SS_UP(X_LALT));
            }
            return false;
        case ALT_2:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_TAP(X_2) SS_UP(X_LALT));
            }
            return false;
        case ALT_3:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_TAP(X_3) SS_UP(X_LALT));
            }
            return false;
        case ALT_4:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_TAP(X_4) SS_UP(X_LALT));
            }
            return false;
        case ALT_5:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_TAP(X_5) SS_UP(X_LALT));
            }
            return false;
        case ALT_6:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_TAP(X_6) SS_UP(X_LALT));
            }
            return false;
        case ALT_7:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_TAP(X_7) SS_UP(X_LALT));
            }
            return false;
        case ALT_8:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_TAP(X_8) SS_UP(X_LALT));
            }
            return false;
        case ALT_9:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_TAP(X_9) SS_UP(X_LALT));
            }
            return false;
        case ALT_0:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_TAP(X_0) SS_UP(X_LALT));
            }
            return false;
        case ALT_MINS:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_TAP(X_MINUS) SS_UP(X_LALT));
            }
            return false;
        case ALT_EQL:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_TAP(X_EQUAL) SS_UP(X_LALT));
            }
            return false;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t layer) {
    switch(get_highest_layer(layer)) {
        case _FN1_LAYER:
            annepro2LedSetForegroundColor(0x00, 0x00, 0xFF);  // Blue
            break;
        case _FN2_LAYER:
            annepro2LedSetForegroundColor(0x00, 0xFF, 0x00);  // Green
            break;
        default:
            annepro2LedResetForegroundColor();  // Normal profile
            break;
    }
    return layer;
}

// Caps Lock indicator - all keys red when caps lock is on
bool led_update_user(led_t leds) {
    if (leds.caps_lock) {
        annepro2LedSetForegroundColor(0xFF, 0x00, 0x00);  // All red
    } else {
        // Restore layer color when caps lock is off
         switch(get_highest_layer(layer_state)) {
             case _FN1_LAYER:
                 annepro2LedSetForegroundColor(0x00, 0x00, 0xFF);  // Blue
                 break;
             case _FN2_LAYER:
                 annepro2LedSetForegroundColor(0x00, 0xFF, 0x00);  // Green
                 break;
             default:
                 annepro2LedResetForegroundColor();  // Normal profile
                 break;
         }
    }
    return true;
}
