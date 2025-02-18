/* Attribution-ShareAlike 4.0 International (CC BY-SA 4.0) 2020 Max Drasbeck
 *
 * You are free to:
 *
 *  Share — copy and redistribute the material in any medium or format
 *  Adapt — remix, transform, and build upon the material
 *   for any purpose, even commercially.
 *
 * The licensor cannot revoke these freedoms as long as you follow the license terms.
 */

#include QMK_KEYBOARD_H

extern uint8_t is_master;

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // [_QWERTY] = LAYOUT(
  // KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  // KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
  // KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  // KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,   KC_MUTE, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
  //                            KC_LALT, KC_LGUI, MO(1),   KC_SPC,  KC_SPC,  MO(2),   KC_NUBS, KC_LCTL
  // ),

  // [_LOWER] = LAYOUT(
  // KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,
  // KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_PGUP, KC_MINS, KC_EQL,  KC_RBRC,
  // KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_NO,   KC_HOME, KC_PGDN, KC_END,  KC_NO,   KC_NUHS,
  // KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RO,   KC_ENT,
  //                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  // ),

  // [_RAISE] = LAYOUT(
  // KC_TRNS, RALT(KC_1), RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5),                RALT(KC_6), RALT(KC_7),    RALT(KC_8), RALT(KC_9), RALT(KC_0), KC_DEL,
  // KC_TRNS, KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                     KC_NO,      KC_NO,         KC_UP,      KC_MINS,    KC_EQL,     KC_RBRC,
  // KC_ESC,  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                     KC_NO,      KC_LEFT,       KC_DOWN,    KC_RGHT,    KC_NO,      KC_NUHS,
  // KC_LSFT, KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_VOLD,       KC_VOLU,    KC_MUTE,    KC_RO,      KC_SFTENT,
  //                                  KC_RALT,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    RALT(KC_NUBS), KC_TRNS
  // ),

  // [_ADJUST] = LAYOUT(
  // XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
  // XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,
  //                            _______, _______, _______, _______,  _______,  _______, _______, _______
  // )

 /* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  BS  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |   [   |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | LOWER|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LOWER|  Alt |  WIN | /Space  /       \Enter \  |   -  |   =  |  \   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 // left fn could be the raise layer - todo
  [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_KB_MUTE,  KC_LBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  MO(_LOWER),
                        MO(_LOWER), KC_LALT, KC_LCMD, KC_SPC, KC_ENT, KC_MINS, KC_EQL, KC_BSLS
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  cap | MOFT | MODN | MOUP | MORT | BT1  |                    |      |prtscr|scrloc| pause|  up  | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |VOLUP |VOLDN | MUTE |EJECT |      |-------.    ,-------|   *  |   /  | home | pgup | left | right|
 * |------+------+------+------+------+------|       |    |   ]   |------+------+------+------+------+------|
 * |      |pretab|nxttab| swwin|swwin |      |-------|    |-------|   +  |   _  |  end | pgdn | down |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |insert| stop |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_CAPS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1,                   _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_UP,  KC_DEL,
  KC_RCTRL,KC_VOLD, KC_VOLU, KC_MUTE, KC_EJCT, KC_BTN2,      KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT,
  KC_RSFT, S(C(KC_TAB)), C(KC_TAB), A(KC_TAB), G(KC_TAB), _______,  _______,       KC_RBRC, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, _______,
                            _______, _______, _______, _______, _______,  _______, KC_INS,  KC_STOP
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

int RGB_current_mode;

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
#endif
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
//const char *read_keylog(void);
//const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    //oled_write_ln(read_keylog(), false);
    //oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  // switch (keycode) {
  //   case QWERTY:
  //     if (record->event.pressed) {
  //       set_single_persistent_default_layer(_QWERTY);
  //     }
  //     return false;
  //     break;
  //   case LOWER:
  //     if (record->event.pressed) {
  //       layer_on(_LOWER);
  //     } else {
  //       layer_off(_LOWER);
  //     }
  //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
  //     return false;
  //     break;
  //   case RAISE:
  //     if (record->event.pressed) {
  //       layer_on(_RAISE);
  //     } else {
  //       layer_off(_RAISE);
  //     }
  //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
  //     return false;
  //     break;
  //   case ADJUST:
  //       if (record->event.pressed) {
  //         layer_on(_ADJUST);
  //       } else {
  //         layer_off(_ADJUST);
  //       }
  //       return false;
  //       break;
  // }
  return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  // // index 1 == minion side
  // if (index == 1) {
  //   if (clockwise) {
  //     tap_code(KC_VOLD);
  //   } else {
  //     tap_code(KC_VOLU);
  //   }
  // }
  uint8_t temp_mod = get_mods();
  uint8_t temp_osm = get_oneshot_mods();
  bool    is_lower  = (temp_mod | temp_osm) & MOD_BIT(MO(_LOWER));
  bool    is_shift = (temp_mod | temp_osm) & MOD_MASK_SHIFT;
  if (index == 0) {
    if (is_lower) {
      if (is_shift) {
        if (clockwise) {
          tap_code(KC_MS_D);
        } else {
          tap_code(KC_MS_U);
        }
      }
      else {
        if (clockwise) {
          tap_code(KC_MS_R);
        } else {
          tap_code(KC_MS_L);
        }
      }
    }
    else {
      if (clockwise) {
        tap_code(KC_WH_D);
      } else {
        tap_code(KC_WH_U);
      }
    }
  }
    return true;
}
#endif
