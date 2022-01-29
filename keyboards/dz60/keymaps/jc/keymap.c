#include QMK_KEYBOARD_H

// qmk compile -kb dz60 -km jc

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * _______ can be used in place of KC_TRNS (transparent) *
 * XXXXXXX can be used in place of KC_NO (No Operation)  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Hack to allow different actions for tap or hold grave.
#define T_H_GRV LT(0,KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_60_iso_5x1u_split_rshift(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
    MO(1),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(1),   KC_LEFT, KC_RGHT, KC_DOWN),

  [1] = LAYOUT_60_iso_5x1u_split_rshift(
    T_H_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, RESET,   _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, KC_PGUP,
    _______, _______, _______,                            _______,                   _______, _______, KC_HOME, KC_END,  KC_PGDN),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case T_H_GRV:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_GRV); // Tap = grave
            } else if (record->event.pressed) {
                tap_code16(KC_SLEP); // Hold = sleep
            }
            return false; // Return false to ignore further processing of key
            break;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case T_H_GRV:
            return 750; // Custom delay for tap/hold grave
        default:
            return TAPPING_TERM;
    }
}
