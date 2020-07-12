#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define L0 0 // default layer
#define L1 1
#define L2 2

#define Z_CTL MT(MOD_LCTL, KC_Z)
#define SL_CTL MT(MOD_LCTL, KC_SLSH)

#define A_CMD MT(MOD_LGUI, KC_A)

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L0] = LAYOUT_ergodox(  // layer 0 : default
/*
 * left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |   =   |  0  |  2  |  3  |  4  |  5  |LEFT |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |   \   |  Q  |  W  |  E  |  R  |  T  |LCK-1|
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |  TAB  |  A  |  S  |  D  |  F  |  G  +-----+
 *    +-------+-----+-----+-----+-----+-----+ f1  |
 *    | LSHIFT|  Z  |  X  |  C  |  V  |  B  |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |  `  |  `  |  \  |LEFT |RIGHT|
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |LCTRL| LALT|
 *                                  +-----+-----+-----+
 *                                  |     |     | HOME|
 *                                  | SPC | BSPC|+----+
 *                                  |     |     | END |
 *                                  +-----+-----+-----+
 */
        KC_EQL,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5, KC_LEFT,
        KC_DEL,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T, TG(L1),
        KC_BSPC, A_CMD,  KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, Z_CTL,  KC_X,    KC_C,    KC_V,    KC_B, MO(L1),
        KC_GRV,  KC_GRV, KC_BSLS, KC_LEFT, KC_RGHT,
                                                      KC_LALT, KC_LCMD,
                                                               KC_HOME,
                                            KC_SPACE, KC_BSPC, KC_END,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |LCK-2|  6  |  7  |  8  |  9  |  0  |   -   |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        | f2  |  Y  |  U  |  I  |  O  |  P  |   \   |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+  H  |  J  |  K  |  L  |  ;  |   '   |
 *        | f1  +-----+-----+-----+-----+-----+-------+
 *        |     |  N  |  M  |  ,  |  .  |  /  | RSHIFT|
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |  UP |DOWN |  [  |  ]  | RGUI|
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    | RALT| ESC |
 *    +-----+-----+-----+
 *    | PGUP|     |     |
 *    +-----+ TAB | ENT |
 *    | PGDN|     |     |
 *    +-----+-----+-----+
 */
             KC_RGHT, KC_6,   KC_7,    KC_8,    KC_9,   KC_0,     KC_MINS,
             TG(L2),  KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,     KC_BSLS,
                      KC_H,   KC_J,    KC_K,    KC_L,   LT(1, KC_SCLN),  KC_QUOT,
             MO(L1),  KC_N,   KC_M,    KC_COMM, KC_DOT, SL_CTL,   KC_RSFT,
                              KC_UP,   KC_DOWN, KC_LBRC,KC_RBRC,  KC_RGUI,
             KC_RALT, KC_ESC,
             KC_PGUP,
             KC_PGDN, KC_TAB, KC_ENT
    ),

[L1] = LAYOUT_ergodox( // layer 1 : function layers
/* left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       | f1  | f2  | f3  | f4  | f5  |     |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     |     |     |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |     |     |     |     +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |     |     |     |     |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |     |     |     |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     |     |
 *                                  |     |     +-----+
 *                                  |     |     |     |
 *                                  +-----+-----+-----+
 */
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                      KC_TRNS, KC_TRNS,
                                                               KC_TRNS,
                                             KC_TRNS, KC_TRNS, KC_TRNS,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     | f6  | f7  | f8  | f9  | f10 |  f11  |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |  f12  |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+     |     |     |     |     |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        |     |     |     |     |     |     |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |  V+ |  V- |     |     |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+     |     |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
       KC_TRNS,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                         KC_VOLU, KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
[L2] = LAYOUT_ergodox(
/* Left hand
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    | FLASH |     |     |     |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+-----+
 *    |       |     |     |     |     |     |     |
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |     |     |     |     +-----+
 *    +-------+-----+-----+-----+-----+-----+     |
 *    |       |     |     |     |     |     |     |
 *    +-+-----+-----+-----+-----+-----+-----+-----+
 *      |     |     |     |     |     |
 *      +-----+-----+-----+-----+-----+   +-----+-----+
 *                                        |     |     |
 *                                  +-----+-----+-----+
 *                                  |     |     |     |
 *                                  |     |     +-----+
 *                                  |     |     |     |
 *                                  +-----+-----+-----+
 */
       RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
/* right hand
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     |NMLCK| P/  | P*  | P-  |       |
 *        +-----+-----+-----+-----+-----+-----+-------+
 *        |     |     | P7  | P8  | P9  | P-  |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        +-----+     | P4  | P5  | P6  | P+  |       |
 *        |     +-----+-----+-----+-----+-----+-------+
 *        |     |     | P1  | P2  | P3  |PENT |       |
 *        +-----+-----+-----+-----+-----+-----+-----+-+
 *                    |     | P0  | P.  |PENT |     |
 *    +-----+-----+   +-----+-----+-----+-----+-----+
 *    |     |     |
 *    +-----+-----+-----+
 *    |     |     |     |
 *    +-----+     |     |
 *    |     |     |     |
 *    +-----+-----+-----+
 */
       KC_TRNS,  KC_TRNS, KC_NUMLOCK,  KC_KP_SLASH,  KC_KP_ASTERISK,  KC_KP_MINUS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_P7,       KC_P8,        KC_P9,           KC_KP_MINUS, KC_TRNS,
                 KC_TRNS, KC_P4,       KC_P5,        KC_P6,           KC_PLUS,     KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_P1,       KC_P2,        KC_P3,           KC_KP_ENTER, KC_TRNS,
                          KC_TRNS,     KC_P0,        KC_KP_DOT,       KC_KP_ENTER, KC_TRNS,
       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS
),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
