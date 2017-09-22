#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0  // default layer
#define SYMB 1  // symbols
#define MEDIA 2 // media keys
#define TMUX 3  // tmux layer

#define M_TMUX M(0)
#define M_TMUX_1 M(1)
#define M_TMUX_2 M(2)
#define M_TMUX_3 M(3)
#define M_TMUX_4 M(4)
#define M_TMUX_5 M(5)
#define M_TMUX_COPY_MODE M(6)
#define M_TMUX_SP M(7)
#define M_TMUX_VS M(8)
#define M_TMUX_NEW M(9)

#define rgblight_set_teal rgblight_setrgb(0x00, 0xFF, 0xFF)
#define rgblight_set_red rgblight_setrgb(0xFF, 0x00, 0x00)
#define rgblight_set_green rgblight_setrgb(0x00, 0xFF, 0x00);
#define rgblight_set_blue rgblight_setrgb(0x00, 0x00, 0xFF);
#define rgblight_set_yellow rgblight_setrgb(0xFF, 0xFF, 0x00);

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  TEAL,
  RED,
  BLUE,
  GREEN,
  YELLOW,
  BREATH,
  TOGGLE,
  RAINBOW,
  SWIRL,
  KNIGHT,
  XMAS,
  OTHER,
  STILL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |      |           | |    |   6  |   7  |   8  |   9  |   0  |  Bkspc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | `      |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CTRL   |   A  |cmd/S |tmux/D|  ^/F |   G  |------|           |------|   H  |  ^/J |  K   |cmd/L |  ;   |   "    |
 * |--------+------+------+------+------+------|      |           | Tmux |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   |   =    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LAlt  |      |      |      | L1   |                                       |  L1  |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |Mute  |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | VolUp|       |      |        |      |
 *                                 | Enter|Backsp|------|       |------|  Tab   |Space |
 *                                 |      |ace   | VolDn|       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
          KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,         KC_NO,
        KC_GRAVE,       KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,         KC_LBRACKET,
        KC_LCTRL,       KC_A,         LGUI_T(KC_S),   LT(TMUX,KC_D),   CTL_T(KC_F),   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,         KC_NO,
        KC_LALT,        KC_NO,        KC_LGUI,  KC_LGUI, KC_LSFT,
                                                        KC_ENTER,KC__MUTE,
                                                                 KC__VOLUP,
                                               KC_ENTER,KC_BSPC, KC__VOLDOWN,
             // right hand
             KC_BSLS,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_BSPC,
             KC_RBRC,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_MINS,
                          KC_H,   CTL_T(KC_J),    KC_K,   LGUI_T(KC_L),   KC_SCLN,   KC_QUOT,
             M_TMUX,      KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_EQUAL,
                                  MO(SYMB),  KC_NO,KC_NO,KC_NO,      KC_NO,
             KC_NO,  KC_NO,
             KC_NO,
             KC_NO,  KC_TAB, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  tab   |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  [   |   ]  |   {  |   }  |      |------|           |------| left | down | up   | right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | TEAL | RED  | GREEN| BLUE | YELLOW |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |TOGGLE|BREATH|KNIGHT| XMAS | OTHER|                                       |      |RAINBW| STILL| SWIRL|       |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_NO,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,
       KC_TAB,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,
       KC_TRNS,KC_LBRC,KC_RBRC,LSFT(KC_LBRC),LSFT(KC_RBRC),KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,             KC_TRNS,
          TOGGLE,BREATH,KNIGHT,XMAS,OTHER,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,
                KC_LEFT, KC_DOWN,KC_UP,KC_RIGHT,KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, TEAL,RED,BLUE,GREEN,YELLOW,
                         KC_TRNS,STILL, RAINBOW, SWIRL, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
 /* Keymap 3: Tmux layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |cmode |  new |  vs  | sp  |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |------|           |------|      |  1   |   2  |  3   |  4   |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [TMUX] = KEYMAP(
      //left hand
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,
      // right hand
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, M_TMUX_COPY_MODE, M_TMUX_SP, M_TMUX_VS, KC_TRNS,KC_TRNS,
      KC_TRNS, M_TMUX_1, M_TMUX_2, M_TMUX_3, M_TMUX_4, M_TMUX_5,
      KC_TRNS, M_TMUX_NEW, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS
      )
};


void do_tmux_key(keyrecord_t *record, uint8_t code, uint8_t modifier) {
  if (record->event.pressed) {
    register_code(KC_LCTRL);
    register_code(KC_SPC);
    unregister_code(KC_SPC);
    unregister_code(KC_LCTRL);
    register_code(modifier);
    register_code(code);
    unregister_code(code);
    unregister_code(modifier);
  }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_LCTRL);
        register_code(KC_SPC);
        unregister_code(KC_SPC);
        unregister_code(KC_LCTRL);
      }
      break;
    case 1:
      do_tmux_key(record, KC_1, KC_NO);
      break;
    case 2:
      do_tmux_key(record, KC_2, KC_NO);
      break;
    case 3:
      do_tmux_key(record, KC_3, KC_NO);
      break;
    case 4:
      do_tmux_key(record, KC_4, KC_NO);
      break;
    case 5:
      do_tmux_key(record, KC_5, KC_NO);
      break;
    case 6:
      do_tmux_key(record, KC_LBRC, KC_NO);
      break;
    case 7:
      do_tmux_key(record, KC_QUOT, KC_LSFT);
      break;
    case 8:
      do_tmux_key(record, KC_5, KC_LSFT);
      break;
    case 9:
      do_tmux_key(record, KC_C, KC_NO);
      break;
  }
  return MACRO_NONE;
};
// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  eeconfig_init();
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case TEAL:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_set_teal;
      }
      return false;
      break;
    case RED:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_set_red;
      }
      return false;
      break;
    case BLUE:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_set_blue;
      }
      return false;
      break;
    case GREEN:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_set_green;
      }
      return false;
      break;
    case YELLOW:
      if (record->event.pressed) {
       rgblight_mode(1);
        rgblight_set_yellow;
      }
      return false;
      break;
    case BREATH:
      if (record->event.pressed) {
        rgblight_mode(5);
      }
      return false;
      break;
    case TOGGLE:
      if (record->event.pressed) {
        rgblight_toggle();
      }
      return false;
      break;
    case RAINBOW:
      if (record->event.pressed) {
        rgblight_mode(7);
      }
      return false;
      break;
    case SWIRL:
      if (record->event.pressed) {
        rgblight_mode(12);
      }
      return false;
      break;
    case KNIGHT:
      if (record->event.pressed) {
        rgblight_mode(22);
      }
      return false;
      break;
    case XMAS:
      if (record->event.pressed) {
        rgblight_mode(24);
      }
      return false;
      break;
    case OTHER:
      if (record->event.pressed) {
        rgblight_mode(30);
      }
      return false;
      break;
    case STILL:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
  }
  return true;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    // light up green when holding control
    if (keyboard_report->mods & MOD_BIT(KC_LCTRL)) {
      ergodox_right_led_on(2);
      ergodox_right_led_set(2, 100);
    }
    // light up red when holding ALT
    if (keyboard_report->mods & MOD_BIT(KC_LALT)) {
      ergodox_right_led_on(1);
      ergodox_right_led_set(1, 100);
    }
     // light up blue when holding gui
    if (keyboard_report->mods & MOD_BIT(KC_LGUI)) {
      ergodox_right_led_on(3);
      ergodox_right_led_set(3, 100);
    }
};
