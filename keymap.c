#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "common_keyboard.h"
#include "common_ergodox.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * | ESC    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |  Bkspc |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | `      |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | CTRL   |   A  |cmd/S |tmux/D|  ^/F |   G  |------|           |------|   H  |  ^/J |  K   |cmd/L |  ;   |   "    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   |   =    |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      | CMD |NumLayer|                                       |  L1 | TAB  |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      |      |       |      |        |      |
   *                                 | Enter|      |------|       |------|  Tab   |Space |
   *                                 |      |      |      |       |      |        |      |
   *                                 `--------------------'       `----------------------'
   */
  // If it accepts an argument (i.e, is a function), it doesn't need KC_.
  // Otherwise, it needs KC_*
  [BASE] = LAYOUT_ergodox(  // layer 0 : default
      // left hand
      KC_ESC  ,KC_1    ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,_______,
      KC_GRAVE,KC_Q    ,KC_W   ,KC_E   ,KC_R   ,KC_T  ,_______,
      KC_LCTRL,KC_A    ,MY_S   ,MY_D   ,MY_F   ,MY_G,
      KC_LSFT ,KC_Z    ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,MY_V,
      _______ ,_______   ,_______,KC_LCMD,MO(NUMBERS),
      _______,_______,
      _______,
      KC_ENTER,_______ , _______,
      // right hand
      _______ ,KC_6    ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_BSPC,
      _______ ,KC_Y    ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_MINS,
      MY_H    ,MY_J    ,KC_K   ,MY_L   ,KC_SCLN,KC_QUOT,
      _______  ,KC_N    ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_EQUAL,
      MO(SYMB),KC_TAB   ,_______  ,_______  ,_______,
      _______ ,_______,
      _______ ,
      _______ ,KC_TAB  ,KC_SPC
      ),


  /* Keymap 1: Symbol Layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * | reset  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |  tab   |      |      |      |      |      |      |           |      |   |  |      |      |      |      |        |
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
      RESET  ,_______,_______,_______,_______,_______,_______,
      KC_TILD, KC_EXLM , KC_AT,  KC_HASH, KC_DLR,  KC_PERC, _______,
      _______,KC_LBRC,KC_RBRC,LSFT(KC_LBRC),LSFT(KC_RBRC),_______,
      _______,_______,_______,KC_LEFT_PAREN,KC_RIGHT_PAREN,_______,_______,
      TOGGLE ,BREATH ,KNIGHT ,XMAS ,OTHER,
      _______,_______,
      _______,
      _______,_______,_______,
      // right hand
      _______   ,_______,_______,_______,_______,_______,_______,
      _______   ,KC_CIRC,KC_AMPR,KC_ASTR,KC_LEFT_PAREN,KC_RIGHT_PAREN, KC_PIPE,
      KC_LEFT   ,KC_DOWN,KC_UP ,KC_RIGHT,_______, KC_BSLS,
      _______   ,_______,TEAL   ,RED     ,BLUE   ,GREEN   ,YELLOW,
      _______   ,STILL  ,RAINBOW,SWIRL   ,_______,
      _______   ,_______,
      _______   ,
      _______   ,_______,_______
      ),


      /* Keymap: Number Layer
       *
       * ,--------------------------------------------------.           ,--------------------------------------------------.
       * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
       * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
       * |        |      |      |      |      |      |      |           |      |      |  7   |  8   |  9   |      |  MUTE  |
       * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       * |        |      |      |      |      |      |------|           |------|      |  4   |   5  |  6   |      |  VolUp |
       * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       * |        |      |      |      |      |      |      |           |      |      |  1   |   2  |  3   |      |  VolDn |
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
      RESET  ,_______,_______,_______,_______,_______,_______,
      KC_TAB ,_______,_______,_______,_______,_______,_______,
      _______,_______,_______,_______,_______,_______,
      _______,_______,_______,_______,_______,_______,_______,
      _______,_______,_______,_______,_______,
      _______,_______,
      _______,
      _______,_______,_______,
      // right hand
      _______,_______,_______,_______,_______,_______   ,_______,
      _______,_______,KC_7   ,KC_8   ,KC_9   ,_______  ,KC__MUTE,
      _______,KC_4   ,KC_5   ,KC_6   ,_______,KC__VOLUP,
      _______,_______,KC_1   ,KC_2   ,KC_3   ,_______  ,KC__VOLDOWN,
      KC_0   ,_______,_______,_______,_______,
      _______,_______,
      _______,
      _______,_______,KC_TAB
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
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,
      _______, _______,
      _______,
      _______, _______, _______,
      // right hand
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, M_TMUX_COPY_MODE, M_TMUX_SP, M_TMUX_VS, _______,_______,
      _______, M_TMUX_1, M_TMUX_2, M_TMUX_3, M_TMUX_4, M_TMUX_5,
      _______, M_TMUX_NEW, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,
      _______, _______,
      _______,
      _______, _______, _______
      )
};
