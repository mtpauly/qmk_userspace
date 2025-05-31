// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Magic Sturdy
// V M L C P    B _ O U J
// S T R D Y    F N A E I
// W K X G Q    Z H , . ;

// Home row mods, from outer column in
// CTRL LAYER ALT SHIFT CMD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        _______,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           _______,
        _______,        KC_V,           KC_M,           KC_L,           KC_C,           KC_P,                           KC_B,           QK_AREP,        KC_O,           KC_U,           KC_J,           _______,
        KC_TAB,         LCTL_T(KC_S),   LT(1, KC_T),    LALT_T(KC_R),   LSFT_T(KC_D),   LGUI_T(KC_Y),                   RGUI_T(KC_F),   RSFT_T(KC_N),   RALT_T(KC_A),   LT(1, KC_E),    RCTL_T(KC_I),   KC_QUOTE,
        CW_TOGG,        KC_W,           KC_K,           KC_X,           KC_G,           KC_Q,                           KC_Z,           KC_H,           KC_COMM,        KC_DOT,         KC_SCLN,        KC_ENTER,
                                                                        QK_REPEAT_KEY,  KC_ESCAPE,                      KC_BSPC,        KC_SPACE
    ),
    [1] = LAYOUT(
        _______,        _______,        _______,        _______,        _______,        _______,                        _______,        _______,        _______,        _______,        _______,        _______,
        _______,        _______,        _______,        _______,        _______,        _______,                        _______,        _______,        _______,        _______,        _______,        _______,
        _______,        _______,        _______,        _______,        _______,        _______,                        _______,        _______,        _______,        _______,        _______,        _______,
        _______,        _______,        _______,        _______,        _______,        _______,                        _______,        _______,        _______,        _______,        _______,        _______,
                                                                        _______,        _______,                        _______,        _______
    ),
};

// https://github.com/Ikcelaks/keyboard_layouts/blob/main/magic_sturdy/QMK_Layout/Moonlander/magic_sturdy/keymap.c
// https://docs.qmk.fm/features/repeat_key
uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        // case KC_C:
        // case KC_P:
        // case KC_D:
        // case KC_G:
        // case KC_Z: return KC_Y;
        // case KC_Y: return KC_P;
        // case KC_R: return KC_L;
        // case KC_K: return KC_S;
        // case KC_L:
        // case KC_S: return KC_K;
        case KC_U: return KC_E;
        case KC_E: return KC_U;
        case KC_O: return KC_A;
        case KC_A: return KC_O;
        // case KC_DOT:
        //     if (mods & MOD_MASK_SHIFT) {
        //         return KC_EQL;
        //     } else {
        //         return KC_BSLS;
        //     }
        // case KC_COMM:
        //     if (mods & MOD_MASK_SHIFT) {
        //         return KC_EQL;
        //     } else {
        //         return MG_SP_BUT;
        //     }
        // case KC_EQL:
        // case C_RCTL_MINS:
        // case KC_MINS: return KC_RABK;
        // case KC_Q: return MG_MLATIV;
        // case KC_H: return MG_OA;
        // case KC_I: return MG_ON;
        // case KC_N: return MG_ION;
        // case KC_V: return MG_ER;
        // case KC_X: return MG_ES;
        // case KC_M: return MG_ENT;
        // case KC_T: return MG_MENT;
        // case KC_J: return MG_UST;
        // case KC_B: return MG_EFORE;
        // case KC_W: return MG_HICH;
        // case KC_1 ... KC_0: return KC_DOT;
    }

    return KC_TRNS;
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    // Exceptionally allow some one-handed chords for hotkeys.
    switch (tap_hold_keycode) {
        // Right ctrl and right space: Useful for fast tmux leader
        case RCTL_T(KC_I):
            if (other_keycode == KC_SPACE) {
                return true;
            }
            break;
    }
    // Otherwise defer to the opposite hands rule.
    return get_chordal_hold_default(tap_hold_record, other_record);
}
