#include QMK_KEYBOARD_H

// qmk compile -kb gmmk/pro/iso -km jc

// Snipping Tool = Win + Shift + S
#define S_TOOL LGUI(LSFT(KC_S))
// Reset Zoom = Ctrl + 0
#define RESET_ZOOM C(KC_0)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]                          PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "        #        Enter             PgDn
//      Sh_L     /        Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right

    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S_TOOL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_END,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGUP,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        KC_SLEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR,          RESET_ZOOM,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,           _______,
        _______, _______, RGB_VAI, _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, RGB_VAD, _______, _______, _______, RGB_HUI, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, RESET,   _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),
};
// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(biton32(layer_state)) {
        // Layer 1 - Zoom in and out
        case 1:
            if (clockwise) {
                tap_code16(C(KC_EQL));
            } else {
                tap_code16(C(KC_MINS));
            }
            break;

        // Layer 0 - Volume control
        default:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
    }

    return true;
}
#endif
