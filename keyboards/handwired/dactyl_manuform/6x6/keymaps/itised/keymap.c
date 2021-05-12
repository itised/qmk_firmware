#include QMK_KEYBOARD_H

#define INDICATOR_LED_1 D2
#define INDICATOR_LED_2 D3
#define INDICATOR_LED_3 F4

#define _QWERTY 0
#define _COLEMAK_DHM 1
#define _LOL 2
#define _SYMBOLS 3
#define _MOUSE 4
#define _QMK_FUNCTIONS 5

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum custom_keycodes {
    _UKARRW = SAFE_RANGE,
    _UKSAME,
    _UKDIFF,
    _UKTHIS,
    _UKEQGT,
};

// Tap Dance declarations
enum {
  TD_SFTLK = 0
};

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

// Tap Dance states
enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    //DOUBLE_TAP,
    //DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP, // Send two single taps
    //TRIPLE_TAP,
    //TRIPLE_HOLD
};

// Tap Dance functions
uint8_t cur_dance(qk_tap_dance_state_t *state);
void sftlk_finished(qk_tap_dance_state_t *state, void *user_data);
void sftlk_reset(qk_tap_dance_state_t *state, void *user_data);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_6x6(
        KC_MPLY,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                                                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_MUTE,
        KC_ESC,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                                                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                                                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINS,
        KC_DEL,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOT,
        TD(TD_SFTLK),   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                                                           KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,        TD(TD_SFTLK),
                                        LGUI(KC_GRV),   SGUI(KC_GRV),                                                                                                                                                   SGUI(KC_LBRC),  SGUI(KC_RBRC),
                                                                        TT(_SYMBOLS),   KC_SPC,                                                                                         KC_ENT,         TT(_SYMBOLS),
                                                                                                        KC_LCTL,        KC_LGUI,                        KC_RGUI,        KC_RALT,
                                                                                                        TT(_LOL),       KC_LALT,                        KC_RCTL,        KC_HYPR
    ),
    [_COLEMAK_DHM] = LAYOUT_6x6(
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,                                                                                           KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,        KC_TRNS,
        KC_TRNS,        KC_A,           KC_R,           KC_S,           KC_T,           KC_G,                                                                                           KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_TRNS,
        KC_TRNS,        KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                                                                                           KC_K,           KC_H,           KC_COMM,        KC_DOT,         KC_SLSH,        KC_TRNS,
                                        KC_TRNS,         KC_TRNS,                                                                                                                                                       KC_TRNS,        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS,                                                                                        KC_TRNS,        KC_TRNS,
                                                                                                         KC_TRNS,       KC_TRNS,                        KC_TRNS,         KC_TRNS,
                                                                                                         KC_TRNS,       KC_TRNS,                        KC_TRNS,         KC_TRNS
    ),
    [_LOL] = LAYOUT_6x6(
        KC_TRNS,        KC_TRNS,        KC_TRNS,         KC_TRNS,       KC_TRNS,        KC_TRNS,                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,         KC_TRNS,       KC_TRNS,        KC_TRNS,                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_ESC,         KC_1,           KC_2,            KC_3,          KC_5,           KC_4,                                                                                           KC_PAST,        KC_P7,          KC_P8,          KC_P9,          KC_PPLS,        KC_TRNS,
        KC_TAB,         KC_Q,           KC_W,            KC_E,          KC_R,           KC_6,                                                                                           KC_PSLS,        KC_P4,          KC_P5,          KC_P6,          KC_PMNS,        KC_TRNS,
        KC_TRNS,        KC_B,           KC_Z,            KC_D,          KC_F,           KC_7,                                                                                           KC_PCMM,        KC_P1,          KC_P2,          KC_P3,          KC_PEQL,        KC_TRNS,
                                        KC_NO,           KC_NO,                                                                                                                                                         KC_P0,          KC_PDOT,
                                                                        KC_GRV,         KC_S,                                                                                           KC_TRNS,        KC_TRNS,
                                                                                                         KC_TRNS,       KC_SPC,                         KC_TRNS,        KC_TRNS,
                                                                                                         KC_TRNS,       KC_TRNS,                        KC_TRNS,        KC_TRNS
    ),
	[_SYMBOLS] = LAYOUT_6x6(
        KC_TRNS,        KC_F11,         KC_F12,          KC_F13,        KC_F14,         KC_F15,                                                                                         KC_MRWD,        KC_MFFD,        KC_NO,          KC_VOLD,        KC_VOLU,        KC_TRNS,
        KC_TRNS,        KC_EXLM,        KC_AT,           KC_HASH,       KC_DLR,         KC_PERC,                                                                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_TRNS,
        KC_TAB,         KC_GRV,         KC_UP,           _UKTHIS,       KC_PGUP,        KC_LBRC,                                                                                        KC_RBRC,        _UKSAME,        _UKDIFF,        KC_EQL,         KC_PLUS,        KC_MINS,
        KC_TRNS,        KC_LEFT,        KC_DOWN,         KC_RGHT,       KC_PGDN,        KC_LPRN,                                                                                        KC_RPRN,        KC_DLR,         KC_UNDS,        KC_BSLS,        KC_ASTR,        KC_SLSH,
        KC_TRNS,        LALT(KC_LEFT),  LALT(KC_RGHT),   LGUI(KC_LEFT), LGUI(KC_RGHT),  KC_LCBR,                                                                                        KC_RCBR,        _UKARRW,        KC_LT,          KC_GT,          _UKEQGT,        KC_TRNS,
                                        KC_TRNS,         KC_TRNS,                                                                                                                                                       KC_TRNS,        KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS,                                                                                        KC_TRNS,        KC_TRNS,
                                                                                                         KC_TRNS,       KC_TRNS,                        KC_TRNS,         KC_TRNS,
                                                                                                         KC_TRNS,       KC_TRNS,                        KC_TRNS,         KC_TRNS
    ),
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
        break;
    case _COLEMAK_DHM:
        writePin(INDICATOR_LED_1, 1);
        writePin(INDICATOR_LED_2, 0);
        break;
    case _LOL:
        writePin(INDICATOR_LED_1, 0);
        writePin(INDICATOR_LED_2, 1);
        break;
    case _SYMBOLS:
        writePin(INDICATOR_LED_1, 1);
        writePin(INDICATOR_LED_2, 1);
        break;
    case _MOUSE:
        writePin(INDICATOR_LED_1, 0);
        writePin(INDICATOR_LED_2, 0);
        break;
    case _QMK_FUNCTIONS:
        writePin(INDICATOR_LED_1, 0);
        writePin(INDICATOR_LED_2, 0);
        break;
    default: //  for any other layers, or the default layer
        writePin(INDICATOR_LED_1, 0);
        writePin(INDICATOR_LED_2, 0);
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

    case _UKSAME:
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

    case _UKTHIS:
        if (record->event.pressed) {
            SEND_STRING("this");
        } else {
            // when keycode is released
        }
        break;

    case _UKEQGT:
        if (record->event.pressed) {
            SEND_STRING("=>");
        } else {
            // when keycode is released
        }
        break;
    }

    return true;
}

// Determine the tapdance state to return
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        // DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return SINGLE_HOLD;
        else return DOUBLE_SINGLE_TAP;
    }

    return 3;
}

// Create an instance of 'tap' for the 'sftlk' tap dance.
static tap sftlk_tap_state = {
    .is_press_action = true,
    .state = 0
};

void sftlk_finished(qk_tap_dance_state_t *state, void *user_data) {
    sftlk_tap_state.state = cur_dance(state);
    switch (sftlk_tap_state.state) {
        case SINGLE_TAP:
        case SINGLE_HOLD:
            register_code(KC_LSFT);
            break;
        case DOUBLE_SINGLE_TAP:
            togglePin(INDICATOR_LED_3);
            tap_code(KC_CAPS);
    }
}

void sftlk_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (sftlk_tap_state.state) {
        case SINGLE_TAP:
        case SINGLE_HOLD:
            unregister_code(KC_LSFT);
            break;
        case DOUBLE_SINGLE_TAP:
            //unregister_code(KC_CAPS);
            break;
    }

    sftlk_tap_state.state = 0;
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SFTLK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sftlk_finished, sftlk_reset)
};
