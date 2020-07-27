#include QMK_KEYBOARD_H

#define INDICATOR_LED_1 D2
#define INDICATOR_LED_2 D3
#define INDICATOR_LED_3 F4

#define _QWERTY 0
#define _SYMBOLS 1
#define _LOL 2
#define _MOUSE 3
#define _QMK_FUNCTIONS 4

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum custom_keycodes {
    _UKARRW = SAFE_RANGE,
    KC_SAME,
    _UKDIFF,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_6x6(KC_MPLY, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_MUTE, KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, KC_DEL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LBRC, KC_RBRC, KC_PLUS, KC_EQL, TT(1), KC_SPC, KC_ENT, TT(1), KC_LCTL, KC_LGUI, KC_RGUI, KC_RALT, TT(3), KC_LALT, KC_RCTL, TT(2)),
	[_SYMBOLS] = LAYOUT_6x6(KC_TRNS, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_MRWD, KC_MFFD, KC_NO, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS, KC_TAB, KC_GRV, KC_UP, KC_UP, KC_PGUP, KC_LBRC, KC_RBRC, KC_SAME, _UKDIFF, KC_EQL, KC_PLUS, KC_MINS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_LPRN, KC_RPRN, KC_DLR, KC_UNDS, KC_BSLS, KC_ASTR, KC_SLSH, KC_TRNS, RGUI(KC_Z), RGUI(KC_X), RGUI(KC_C), RGUI(KC_V), KC_LCBR, KC_RCBR, _UKARRW, KC_TRNS, KC_TRNS, RGUI(KC_SPC), KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[_LOL] = LAYOUT_6x6(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC, KC_1, KC_2, KC_3, KC_5, KC_4, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_B, KC_Z, KC_D, KC_F, KC_7, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_LSFT, KC_S, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[_MOUSE] = LAYOUT_6x6(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_MS_U, KC_MS_U, KC_MS_U, KC_MS_U, KC_NO, KC_ACL0, KC_ACL1, KC_ACL2, KC_WH_U, KC_NO, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_MS_R, KC_NO, KC_NO, KC_BTN1, KC_BTN2, KC_WH_D, KC_NO, KC_NO, KC_TRNS, KC_MS_D, KC_MS_D, KC_MS_D, KC_MS_D, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[_QMK_FUNCTIONS] = LAYOUT_6x6(DEBUG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS)
};

void keyboard_pre_init_user(void) {
  // Set our LED pins as output
  setPinOutput(INDICATOR_LED_1);
  setPinOutput(INDICATOR_LED_2);
  setPinOutput(INDICATOR_LED_3);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {   
    case _QWERTY:
        writePin(INDICATOR_LED_1, 0);
        writePin(INDICATOR_LED_2, 0);
        writePin(INDICATOR_LED_3, 0);
        break;
    case _SYMBOLS:
        writePin(INDICATOR_LED_1, 1);
        writePin(INDICATOR_LED_2, 0);
        writePin(INDICATOR_LED_3, 0);
        break;
    case _LOL:
        writePin(INDICATOR_LED_1, 0);
        writePin(INDICATOR_LED_2, 1);
        writePin(INDICATOR_LED_3, 0);
        break;
    case _MOUSE:
        writePin(INDICATOR_LED_1, 1);
        writePin(INDICATOR_LED_2, 1);
        writePin(INDICATOR_LED_3, 0);
        break;
    case _QMK_FUNCTIONS:
        writePin(INDICATOR_LED_1, 1);
        writePin(INDICATOR_LED_2, 1);
        writePin(INDICATOR_LED_3, 1);
        break;
    default: //  for any other layers, or the default layer
        writePin(INDICATOR_LED_1, 1);
        writePin(INDICATOR_LED_2, 1);
        writePin(INDICATOR_LED_3, 1);
        break;
    }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case _UKARRW:
        if (record->event.pressed) {
            SEND_STRING("->");
        } else {
            // when keycode is released
        }
        break;

    case KC_SAME:
        if (record->event.pressed) {
            SEND_STRING("===");
        } else {
            // when keycode is released
        }
        break;

    case _UKDIFF:
        if (record->event.pressed) {
            SEND_STRING("!==");
        } else {
            // when keycode is released
        }
        break;
    }

    return true;
}