#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "common_keyboard.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |close |           | |    |   6  |   7  |   8  |   9  |   0  |  Bkspc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | `      |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------| copy |           |      |------+------+------+------+------+--------|
 * | CTRL   |   A  |cmd/S |tmux/D|  ^/F |   G  |------|           |------|   H  |  ^/J |  K   |cmd/L |  ;   |   "    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |paste |           |tCAPS |   N  |   M  |   ,  |   .  |  /   |   =    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LAlt  |      |      |      |NumLayer|                                       |  L1  |      |      |      |      |
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
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
          KC_ESC,       KC_1,         KC_2,   KC_3,   KC_4,   KC_5,         RCTL(KC_W),
        KC_GRAVE,       KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,         RCTL(KC_C),
        KC_LCTRL,       LSFT_T(KC_A), LGUI_T(KC_S),   LT(TMUX,KC_D),   CTL_T(KC_F),   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,         RCTL(KC_V),
        KC_LALT,        KC_NO,        KC_LGUI,  KC_LGUI, MO(NUMBERS),
                                                        KC_ENTER,KC__MUTE,
                                                                 KC__VOLUP,
                                               KC_ENTER,KC_BSPC, KC__VOLDOWN,
             // right hand
             KC_BSLS,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_BSPC,
             KC_RBRC,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_MINS,
                          KC_H,   CTL_T(KC_J),    KC_K,   LGUI_T(KC_L),     LSFT_T(KC_SCLN),   KC_QUOT,
             M_TMUX,      KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_EQUAL,
                                  MO(SYMB),  KC_NO,KC_NO,KC_NO,      KC_NO,
             KC_NO,  KC_NO,
             KC_NO,
             KC_NO,  KC_TAB, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | reset  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  tab   |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  [   |   ]  |   {  |   }  |      |------|           |------| left | down | up   | right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |   (  |   )  |      |      |           |      |      | TEAL | RED  | GREEN| BLUE | YELLOW |
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
[SYMB] = LAYOUT_ergodox(
       // left hand
       RESET,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TAB,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,
       KC_TRNS,KC_LBRC,KC_RBRC,LSFT(KC_LBRC),LSFT(KC_RBRC),KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_LEFT_PAREN,KC_RIGHT_PAREN,KC_TRNS,KC_TRNS,
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

/* Keymap: Number Layer
 *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |  7   |  8   |  9   |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |------|           |------|      |  4   |   5  |  6   |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |  1   |   2  |  3   |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |  0   |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
 */
// NUMBERS
[NUMBERS] = LAYOUT_ergodox(
       // left hand
       RESET,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,
       KC_TAB,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,             KC_TRNS,
          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_7,KC_8,KC_9, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_4,KC_5,KC_6,KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_1,KC_2,KC_3,KC_TRNS,KC_TRNS,
                         KC_0,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

 /* Keymap 3: Tmux layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |cmode |  vs  |  sp  |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |------|           |------|      |  1   |   2  |  3   |  4   |   5    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      | new |      |      |      |      |        |
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
  [TMUX] = LAYOUT_ergodox(
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

