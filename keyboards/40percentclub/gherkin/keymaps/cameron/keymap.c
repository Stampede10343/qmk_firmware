#include QMK_KEYBOARD_H

#define FN1_Q LT(1, KC_Q)
#define LT3_SPC LT(3, KC_SPC)
#define LT1_ESC LT(1, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ortho_3x10(
      FN1_Q,        KC_W,         KC_E,        KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
      LGUI_T(KC_A), KC_S,         KC_D,        KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SFTENT,
      LCTL_T(KC_Z), LT(1, KC_X),  LT(2, KC_C), KC_V,   KC_BSPC, LT3_SPC, KC_B,    KC_N,    KC_M,    LT1_ESC
      ),

  [1] = LAYOUT_ortho_3x10(
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_LEFT, KC_HOME, KC_UP,   KC_END,
      KC_TRNS, KC_TRNS, KC_LALT, KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT, KC_LEFT, KC_DOWN, KC_RIGHT
      ),

  [2] = LAYOUT_ortho_3x10(
      KC_F1,   KC_F2,   KC_F3,    KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
      KC_F11,  KC_F12,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,
      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12
      ),

  [3] = LAYOUT_ortho_3x10(
      KC_DEL,  KC_EQL,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC,  KC_MINS,
      KC_TAB,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_GRV,  KC_VOLU, KC_MPLY, KC_VOLD,  KC_SCOLON,
      KC_BSLS, KC_TRNS, KC_TRNS,  KC_LALT,  KC_LSFT,  KC_TRNS, KC_COMM, KC_DOT,  KC_QUOT,  KC_SLASH
      )

};

