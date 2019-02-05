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

#define rgblight_set_teal   rgblight_setrgb(0x00, 0xFF, 0xFF)
#define rgblight_set_red    rgblight_setrgb(0xFF, 0x00, 0x00)
#define rgblight_set_green  rgblight_setrgb(0x00, 0xFF, 0x00);
#define rgblight_set_blue   rgblight_setrgb(0x00, 0x00, 0xFF);
#define rgblight_set_yellow rgblight_setrgb(0xFF, 0xFF, 0x00);

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
