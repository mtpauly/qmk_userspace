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
        _______,        KC_V,           KC_M,           KC_L,           KC_C,           KC_P,                           KC_B,           _______,        KC_O,           KC_U,           KC_J,           _______,
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
