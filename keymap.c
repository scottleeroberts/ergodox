#include QMK_KEYBOARD_H

// Layer definitions
enum layers {
    BASE,
    SYMB,
    TMUX,
    NUMBERS
};

// Custom keycodes for tmux macros and RGB mode selection
enum custom_keycodes {
    TMUX_WIN_1 = SAFE_RANGE,
    TMUX_WIN_2,
    TMUX_WIN_3,
    TMUX_WIN_4,
    TMUX_WIN_5,
    TMUX_COPY_MODE,
    TMUX_SPLIT_H,
    TMUX_SPLIT_V,
    TMUX_NEW_WIN,
    RGB_PLAIN,
    RGB_BREATHE
};

// Home-row modifiers
#define MY_A LALT_T(KC_A)
#define MY_SCLN LALT_T(KC_SCLN)
#define MY_S LGUI_T(KC_S)
#define MY_D LT(TMUX, KC_D)
#define MY_F LCTL_T(KC_F)
#define MY_G LSFT_T(KC_G)
#define MY_H LSFT_T(KC_H)
#define MY_J LCTL_T(KC_J)
#define MY_L LGUI_T(KC_L)

// Combos: press two adjacent keys simultaneously for common actions
const uint16_t PROGMEM combo_jh[] = {MY_J, MY_H, COMBO_END};
const uint16_t PROGMEM combo_kj[] = {KC_K, MY_J, COMBO_END};
const uint16_t PROGMEM combo_df[] = {MY_D, MY_F, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_jh, KC_ESC),    // J+H = Escape
    COMBO(combo_kj, KC_BSPC),   // K+J = Backspace
    COMBO(combo_df, KC_TAB),    // D+F = Tab
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_ergodox(
        // left hand
        KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,
        KC_GRAVE, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,
        KC_LCTL,  MY_A,    MY_S,    MY_D,    MY_F,    MY_G,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,
        _______,  _______, _______, KC_LCMD, MO(NUMBERS),
                                                       _______, _______,
                                                                _______,
                                              KC_ENT,  _______, _______,
        // right hand
        _______,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        _______,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
                  MY_H,    MY_J,    KC_K,    MY_L,    MY_SCLN, KC_QUOT,
        _______,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQUAL,
                           MO(SYMB),KC_TAB,  _______, _______, _______,
        _______, _______,
        _______,
        _______, KC_TAB,  KC_SPC
    ),

    [SYMB] = LAYOUT_ergodox(
        // left hand
        _______,  _______, _______, _______, _______, _______, _______,
        KC_TILD,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,
        _______,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______,
        _______,  _______, _______, KC_LPRN, KC_RPRN, _______, _______,
        _______,  _______, _______, _______, KC_BSPC,
                                                       _______, _______,
                                                                _______,
                                              _______, _______, _______,
        // right hand
        _______,  _______, _______, _______, _______, _______, _______,
        _______,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
                  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_QUES, KC_BSLS,
        _______,  _______, _______, _______, _______, _______, _______,
                           _______, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, _______
    ),

    [TMUX] = LAYOUT_ergodox(
        // left hand
        _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
                                                       _______, _______,
                                                                _______,
                                              _______, _______, _______,
        // right hand
        _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, TMUX_COPY_MODE, TMUX_SPLIT_H, TMUX_SPLIT_V, _______, _______,
                  _______, TMUX_WIN_1, TMUX_WIN_2, TMUX_WIN_3, TMUX_WIN_4, TMUX_WIN_5,
        _______,  TMUX_NEW_WIN, _______, _______, _______, _______, _______,
                           _______, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, _______
    ),

    [NUMBERS] = LAYOUT_ergodox(
        // left hand
        QK_BOOT,  _______, _______, _______, _______, _______, _______,
        _______,  RGB_PLAIN, RGB_BREATHE, _______, _______, _______, _______,
        UG_TOGG,  UG_NEXT, UG_HUEU, UG_SPDU, UG_VALU, _______,
        _______,  UG_PREV, UG_HUED, UG_SPDD, UG_VALD, _______, _______,
        _______,  _______, _______, _______, _______,
                                                       _______, _______,
                                                                _______,
                                              _______, _______, _______,
        // right hand
        _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, KC_7,    KC_8,    KC_9,    _______, KC_MUTE,
                  _______, KC_4,    KC_5,    KC_6,    _______, KC_VOLU,
        _______,  _______, KC_1,    KC_2,    KC_3,    _______, KC_VOLD,
                           KC_0,    _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, KC_TAB
    )
};

// Chordal hold override: allow specific same-hand shortcuts
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                      uint16_t other_keycode, keyrecord_t *other_record) {
    if (tap_hold_keycode == MY_F && other_keycode == KC_W) {
        return true;
    }
    if (tap_hold_keycode == MY_L && other_keycode == KC_Y) {
        return true;
    }
    return get_chordal_hold_default(tap_hold_record, other_record);
}

// Helper function: sends Ctrl+Space (tmux prefix) followed by a key
void send_tmux_key(const char* key) {
    SEND_STRING(SS_LCTL(" "));
    send_string(key);
}

// Custom keycode processing
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;

    switch (keycode) {
        case TMUX_WIN_1:      send_tmux_key("1"); return false;
        case TMUX_WIN_2:      send_tmux_key("2"); return false;
        case TMUX_WIN_3:      send_tmux_key("3"); return false;
        case TMUX_WIN_4:      send_tmux_key("4"); return false;
        case TMUX_WIN_5:      send_tmux_key("5"); return false;
        case TMUX_COPY_MODE:  send_tmux_key("["); return false;
        case TMUX_SPLIT_H:    send_tmux_key(SS_LSFT("'")); return false;
        case TMUX_SPLIT_V:    send_tmux_key(SS_LSFT("5")); return false;
        case TMUX_NEW_WIN:    send_tmux_key("c"); return false;
#ifdef RGBLIGHT_ENABLE
        case RGB_PLAIN:       rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); return false;
        case RGB_BREATHE:     rgblight_mode(RGBLIGHT_MODE_BREATHING); return false;
#endif
    }
    return true;
}
