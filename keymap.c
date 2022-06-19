#include QMK_KEYBOARD_H

enum layer_number {
  _NORMAL = 0,
  _FUNCS = 1,
  _NUMBERS = 2,
  _GAME = 3,
  _GAME_A = 4,
  _LOWER = 5,
  _RAISE = 6,
  _EXTRA = 7,
};

// Tap Dance declarations
enum {
    TD_F1_ESC,
    TD_F12_BSPC,
    TD_LEFT_BRACKET_BRACE,
    TD_LSFT_CAPS,
    TD_N_ENIE,
    TD_QUESTION,
    TD_RIGHT_BRACKET_BRACE,
    TD_SINGLE_DOUBLE,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_F1_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_ESC),
    [TD_F12_BSPC] = ACTION_TAP_DANCE_DOUBLE(KC_F12, KC_BSPC),
    [TD_LEFT_BRACKET_BRACE] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_N_ENIE] = ACTION_TAP_DANCE_DOUBLE(KC_N, RALT(KC_N)),
    [TD_QUESTION] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, RALT(KC_SLSH)),
    [TD_RIGHT_BRACKET_BRACE] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
    [TD_SINGLE_DOUBLE] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, S(KC_QUOT)),
};

#define EXTRA MO(_EXTRA)
#define FUNCS TO(_FUNCS)
#define GAME TO(_GAME)
#define GAME_A MO(_GAME_A)
#define LOWER MO(_LOWER)
#define NORMAL TO(_NORMAL)
#define NUMBERS TO(_NUMBERS)
#define RAISE MO(_RAISE)
#define SP_RALT RALT_T(KC_APP)
#define TD_CAPS TD(TD_LSFT_CAPS)
#define TD_ENIE TD(TD_N_ENIE)
#define TD_F12B TD(TD_F12_BSPC)
#define TD_F1E TD(TD_F1_ESC)
#define TD_LBRC TD(TD_LEFT_BRACKET_BRACE)
#define TD_QSTN TD(TD_QUESTION)
#define TD_QUOT TD(TD_SINGLE_DOUBLE)
#define TD_RBRC TD(TD_RIGHT_BRACKET_BRACE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layout template
 * ,-----------------------------------------------.                        ,-----------------------------------------------.
 * |       |       |       |       |       |       |                        |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                        |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                        |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                        |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |-------.        ,-------|       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|       |        |       |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |-------|        |-------|       |       |       |       |       |       |
 * `-----------------------------------------------/       /        \       \-----------------------------------------------'
 *                      |       |       | LOWER | / Space /          \ Space \  | RAISE |       |       |
 *                      |       |       |       |/       /            \       \ |       |       |       |
 *                      `-------------------------------'              '-------''-----------------------'

[_TEMPLATE] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX                             \
),
*/

[_NORMAL] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSLS, \
  TD_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  TD_QUOT, \
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MPLY, KC_DEL,  TD_ENIE, KC_M,    KC_COMM, KC_DOT,  TD_QSTN,  KC_ENT,  \
                             KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   SP_RALT, KC_RCTL                              \
),

[_FUNCS] = LAYOUT( \
  TD_F1E,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   TD_F12B, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSLS, \
  TD_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  TD_QUOT, \
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MPLY, KC_DEL,  TD_ENIE, KC_M,    KC_COMM, KC_DOT,  TD_QSTN,  KC_ENT,  \
                             KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   SP_RALT, KC_RCTL                              \
),

[_NUMBERS] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_NLCK, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_BSPC, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PAST, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PPLS, KC_PENT, \
                             XXXXXXX, XXXXXXX, LOWER,   KC_SPC,  KC_P0,   RAISE,   XXXXXXX, KC_PDOT                             \
),

[_GAME] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_T,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                      XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_G,    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_DOWN, XXXXXXX, XXXXXXX, \
  KC_B,    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_MPLY, KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                             KC_LALT, XXXXXXX, GAME_A,  KC_SPC,  KC_ENT,  RAISE,   KC_RGUI, KC_RCTL                             \
),

[_GAME_A] = LAYOUT( \
  KC_BSPC, KC_0,    KC_9,    KC_8,    KC_7,    KC_6,                      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  KC_BSLS, KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,                      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   \
  KC_QUOT, KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_ENT,  KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    KC_MPLY, KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                             KC_LALT, XXXXXXX, _______, KC_SPC,  KC_SPC,  EXTRA,   KC_RGUI, KC_RCTL                             \
),

[_LOWER] = LAYOUT( \
  TD_F1E,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  TD_F12B, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,  \
  XXXXXXX, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, XXXXXXX, _______, _______, XXXXXXX, TD_LBRC, TD_RBRC, XXXXXXX, XXXXXXX, _______, \
                             _______, _______, _______, _______, _______, EXTRA,   _______, _______                             \
),

[_RAISE] = LAYOUT( \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
                             _______, _______, EXTRA,   _______, _______, _______, _______, _______                             \
),

[_EXTRA] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, NORMAL,  \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PSCR, KC_SCRL, KC_PAUS, XXXXXXX, XXXXXXX, FUNCS,   \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_INS,  KC_HOME, KC_PGUP, XXXXXXX, XXXXXXX, NUMBERS, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_DEL,  KC_DEL,  KC_PGDN, XXXXXXX, XXXXXXX, GAME,    \
                             _______, _______, _______, _______, _______, _______, _______, _______                             \
),
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

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
    case _NORMAL:
        oled_write_ln_P(PSTR("NORMAL"), false);
        break;
    case _FUNCS:
        oled_write_ln_P(PSTR("FUNCS"), false);
        break;
    case _NUMBERS:
        oled_write_ln_P(PSTR("NUM PAD"), false);
        break;
    case _GAME:
        oled_write_ln_P(PSTR("GAME"), false);
        break;
    case _GAME_A:
        oled_write_ln_P(PSTR("GAME A"), false);
        break;
    case _LOWER:
        oled_write_ln_P(PSTR("NUMBERS"), false);
        break;
    case _RAISE:
        oled_write_ln_P(PSTR("ARROWS"), false);
        break;
    case _EXTRA:
        oled_write_ln_P(PSTR("SPECIAL"), false);
        break;
    default:
        oled_write_ln_P(PSTR("UNDEFINED"), false);
    }

    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);

  } else {
      oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

  return false;
}

// Encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}
