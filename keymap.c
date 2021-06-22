#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _EXTRA,
  _GAME,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define EXTRA MO(_EXTRA)
#define QWERTY TO(_QWERTY)
#define GAME TO(_GAME)
#define SP_CAPS SFT_T(KC_CAPS)
#define SP_RALT RALT_T(KC_APP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |LOWER | /Space  /       \Space \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,   KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,     KC_BSLS, \
  SP_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT, \
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MPLY, KC_DEL,  KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT,  \
                             KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,  SP_RALT, KC_RCTL                              \
),

[_LOWER] = LAYOUT( \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK,                   KC_P7,   KC_P8,   KC_P9,   XXXXXXX, XXXXXXX, _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_P4,   KC_P5,   KC_P6,   XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_EQL,                    KC_P1,   KC_P2,   KC_P3,   XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_P0,   KC_P0,   KC_PDOT, XXXXXXX, XXXXXXX, _______, \
                             _______, _______, _______, _______, _______, EXTRA,   _______, _______                             \
),

[_RAISE] = LAYOUT( \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                             _______, _______, EXTRA,   _______, _______, _______, _______, _______                             \
),

[_EXTRA] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GAME,    \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, KC_GRV,  KC_LT,   KC_LPRN, KC_LCBR, KC_LBRC,                   KC_RBRC, KC_RCBR, KC_RPRN, KC_GT,   KC_UNDS, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                             _______, _______, _______, _______, _______, _______, _______, _______                             \
),

[_GAME] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    QWERTY,  \
  KC_T,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_G,    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_B,    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_MPLY, KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
                             KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   SP_RALT, KC_RCTL                             \
)
};

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
    if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
        layer_on(layer3);
    } else {
        layer_off(layer3);
    }
}

#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
    case _QWERTY:
        oled_write_ln_P(PSTR("Default"), false);
        break;
    case _LOWER:
        oled_write_ln_P(PSTR("Num Lock"), false);
        break;
    case _RAISE:
        oled_write_ln_P(PSTR("Functions"), false);
        break;
    case _EXTRA:
        oled_write_ln_P(PSTR("Special"), false);
        break;
    case _GAME:
        oled_write_ln_P(PSTR("Game"), false);
        break;
    default:
        oled_write_ln_P(PSTR("Undefined"), false);
    }

    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);

  } else {
      oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}

// Encoder
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
}
