#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = {
#ifdef PREONIC
  {  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX },
#endif
  {  KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,     KC_I,    KC_O,    KC_P, KC_BSPC },
  {  KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,     KC_K,    KC_L, KC_SCLN, KC_QUOT },
  { KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,  KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT },
  { KC_LCTL, KC_LGUI, XXXXXXX, KC_LALT,   LOWER,  KC_SPC,  KC_SPC,  UPPER,  KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT }
},
[_LOWER] = {
#ifdef PREONIC
  { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
#endif
  {  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL },
  { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS },
  { _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, _______ },
  { _______, _______, XXXXXXX, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R }
},
[_UPPER] = {
#ifdef PREONIC
  { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
#endif
  { XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX },
  { XXXXXXX,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20, XXXXXXX },
  { _______,  KC_F21,  KC_F22,  KC_F23,  KC_F24, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______ },
  { _______, _______, XXXXXXX, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END }
},
[_FUNCT] = {
#ifdef PREONIC
  { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
#endif
  { KC_SLEP,  RND123, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,   RESET },
  {  KC_PWR,  RNDABC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  PARENS,  BRACKE,  CURLYB },
  { _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______ },
  { XXXXXXX, XXXXXXX, XXXXXXX,  BACKLT, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY }
}
};

const uint16_t PROGMEM fn_actions[] = {};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

static uint16_t random_value = 19414;
void matrix_init_user(void) {
  random_value = TCNT1;  // seed the RNG
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {

    case _QWERTY: P_LAYER(_QWERTY) break;
    case _LOWER:  M_LAYER(_LOWER)  break;
    case _UPPER:  M_LAYER(_UPPER)  break;
    case _FUNCT:  M_LAYER(_FUNCT)  break;

    case _BACKLT:
      if (record->event.pressed) {
        backlight_step();
      }
    break;

    case _PARENS:
      if (record->event.pressed) {
        return MACRO( D(LSFT), T(9), T(0), U(LSFT), T(LEFT), END );  // parens
      }
    break;

    case _BRACKE:
      if (record->event.pressed) {
        return MACRO( T(LBRC), T(RBRC), T(LEFT), END );  // square brackets
      }
    break;

    case _CURLYB:
      if (record->event.pressed) {
        return MACRO( D(LSFT), T(LBRC), T(RBRC), U(LSFT), T(LEFT), END );  // curly braces
      }
    break;

  case _RND123:
    random_value = ((random_value + 53) * 181) % 167;
    if (record->event.pressed) {
      uint8_t rval = (random_value ^ (TCNT1 % 256)) % 10;
      register_code (KC_1 + rval);
      unregister_code (KC_1 + rval);
    }
    break;
  case _RNDABC:
    random_value = ((random_value + 53) * 181) % 167;
    if (record->event.pressed) {
      uint8_t rval = (random_value ^ (TCNT1 % 256)) % 26;
      register_code (KC_A + rval);
      unregister_code (KC_A + rval);
    }
    break;

  }

  return MACRO_NONE;
};
