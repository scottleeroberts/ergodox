#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MEDIA 2 // media keys
#define KEITH 3 // keith keys

enum {
  TD_SCLN,
  TD_SPC,
  TD_Z
};

#define M_TMUX M(0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |      |           | |    |   6  |   7  |   8  |   9  |   0  |  Bkspc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | `      |   Q  |   W  |   E  |   R  |   T  |  {   |           |  }   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|  [   |           |  ]   |------+------+------+------+------+--------|
 * | CTRL   |   A  | a/S  |   D  |  ^/F |   G  |------|           |------|   H  |  ^/J |   K  | a/L  |  ;   |   "    |
 * |--------+------+------+------+------+------|  L1  |           | Tab  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   |   =    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LAlt  |      |      | L1   | L1   |                                       |  L1  | Down | left |Right | Up   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |Mute  |       |      | Tab  |
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
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,         TG(KEITH),
        KC_GRAVE,       KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,         KC_LBRACKET,
        KC_LCTRL,       KC_A,         ALT_T(KC_S),   KC_D,   CTL_T(KC_F),   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,         KC_NO,
        KC_LALT,        KC_NO,        KC_LGUI,  KC_LGUI, KC_LGUI,
                                                        KC_ENTER,KC__MUTE,
                                                                 KC__VOLUP,
                                               KC_ENTER,KC_BSPC, KC__VOLDOWN,
             // right hand
             KC_BSLS,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_BSPC,
             KC_RBRC,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_MINS,
                          KC_H,   CTL_T(KC_J),   KC_K,   ALT_T(KC_L),   KC_SCLN,   KC_QUOT,
             M_TMUX,      KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_EQUAL,
                                  MO(SYMB),  KC_DOWN,KC_LEFT,KC_RIGHT,      KC_UP,
             KC_NO,  KC_TAB,
             KC_NO,
             KC_NO,  KC_TAB, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  tab   |  [   |   ]  |   {  |  }   |  \|  |      |           |      |   [  |   ]  |   {  |   }  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| left | down | up   | right|      |        |
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
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_NO,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,KC_TRNS,
       KC_TAB,KC_LBRC, KC_RBRC,LSFT(KC_LBRC),LSFT(KC_RBRC),KC_BSLS, KC_TRNS,
       KC_TRNS,KC_LBRC,KC_RBRC,LSFT(KC_LBRC),LSFT(KC_RBRC),KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,             KC_TRNS,
          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,
                KC_LEFT, KC_DOWN,KC_UP,KC_RIGHT,KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS,
                         KC_TRNS,KC_TRNS,      KC_TRNS,       KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MEDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,KC_TRNS, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
[KEITH] = KEYMAP(  // layer 0 : default
    // left hand
    KC_EQL,           KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_TRNS,
    KC_DELT,          KC_Q,         KC_W,   KC_F,   KC_P,   KC_G,   KC_NO,
    KC_BSPC,          KC_A,         KC_R,   KC_S,   CTL_T(KC_T),   KC_D,
    KC_LSFT,          TD(TD_Z),         KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
    KC_GRV, KC_QUOT,      LALT(KC_LSFT),  KC_LEFT,KC_RGHT,
    ALT_T(KC_APP),    KC_LGUI,
    KC_HOME,
    TD(TD_SPC),           KC_BSPC,     CTL_T(KC_ESC),
    // right hand
    KC_NO ,         KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
    M_TMUX,            KC_J,   KC_L,  KC_U,   KC_Y,   TD(TD_SCLN),             KC_BSLS,
    KC_H,             CTL_T(KC_N),    KC_E,   KC_I,   KC_O,          GUI_T(KC_QUOT),
    MEH_T(KC_NO),     KC_K,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,
    KC_UP,            KC_DOWN,KC_LBRC,KC_RBRC,          KC_NO,
    KC_LALT,          CTL_T(KC_ESC),
    KC_PGUP,
    KC_PGDN,          KC_TAB, KC_ENT
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

void do_tap_dance (qk_tap_dance_state_t *state) {
  switch (state->keycode) {
    case TD(TD_SCLN):
      if (state->count == 1) {
        register_code (KC_SCLN);
        unregister_code (KC_SCLN);
      } else {
        register_code (KC_LSFT);
        register_code (KC_SCLN);
        unregister_code (KC_SCLN);
        unregister_code (KC_LSFT);
        reset_tap_dance (state);
      }
      break;
    case TD(TD_SPC):
      if (state->count == 1) {
        register_code (KC_SPC);
        unregister_code (KC_SPC);
      } else {
        register_code (KC_LSFT);
        register_code (KC_MINS);
        unregister_code (KC_MINS);
        unregister_code (KC_LSFT);
        reset_tap_dance (state);
      }
      break;
    case TD(TD_Z):
      if (state->count == 1) {
        register_code (KC_Z);
        unregister_code (KC_Z);
      } else {
        set_oneshot_mods (MOD_LGUI);
        reset_tap_dance (state);
      }
      break;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SCLN] = ACTION_TAP_DANCE_FN (do_tap_dance),
  [TD_SPC] = ACTION_TAP_DANCE_FN (do_tap_dance),
  [TD_Z] = ACTION_TAP_DANCE_FN (do_tap_dance)
};

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
  }
  return MACRO_NONE;
};
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
