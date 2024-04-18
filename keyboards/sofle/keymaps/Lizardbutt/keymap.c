// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    _BASE,
    _SPECIAL,
    _FUNCTION,
    _CHARACTERS,
    _ONESHOT,
    _OPTIONS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base
 * ,----------------------------------------.                    ,-----------------------------------------.
 * | ESC   | 1   | 2    | 3    | 4    | 5   |                    | 6    | 7    | 8    | 9    | 0    | - _  |
 * |-------+-----+------+------+------+-----|                    |------+------+------+------+------+------|
 * | Tab   | Q   | W    | E    | R    | T   |                    | Y    | U    | I    | O    | P    | \ |  |
 * |-------+-----+------+------+------+-----|                    |------+------+------+------+------+------|
 * | LShift| A   | S    | D    | F    | G   |-------.    ,-------| H    | J    | K    | L    | ; :  | ' "  |
 * |-------+-----+------+------+------+-----| XXXXX |    | XXXXX |------+------+------+------+------+------|
 * | LCTRL | Z   | X    | C    | V    | B   |-------|    |-------| N    | M    | = +  | , <  | . >  | / ?  |
 * `----------------------------------------/       /     \      \-----------------------------------------'
 *        | LGUI | LAlt | MO 3 | Backspc | / Enter /       \ MO 2 \  | Space | MO 1 | XXXX | OSL1 |
 *        |      |      |      |         |/       /         \      \ |       |      |      |      |
 *        '------------------------------''------'           '------''----------------------------'       */
[_BASE] = LAYOUT(
  KC_ESC,  KC_1, KC_2,    KC_3,    KC_4,            KC_5,                                  KC_6,     KC_7,          KC_8,     KC_9,         KC_0,     KC_MINS,
  KC_TAB,  KC_Q, KC_W,    KC_E,    KC_R,            KC_T,                                  KC_Y,     KC_U,          KC_I,     KC_O,         KC_P,     KC_BSLS,
  KC_LSFT, KC_A, KC_S,    KC_D,    KC_F,            KC_G,                                  KC_H,     KC_J,          KC_K,     KC_L,         KC_SCLN,  KC_QUOT,
  KC_LCTL, KC_Z, KC_X,    KC_C,    KC_V,            KC_B,         KC_MUTE,   XXXXXXX,      KC_N,     KC_M,          KC_EQUAL, KC_COMMA,     KC_DOT,   KC_SLSH,
                 KC_LGUI, KC_LALT, MO(_CHARACTERS), KC_BACKSPACE, KC_ENT,    MO(_SPECIAL), KC_SPACE, MO(_FUNCTION), XXXXXXX,  OSL(_ONESHOT)
),

/* Special
 * ,-----------------------------------------.                    ,-------------------------------------------.
 * | PT   |      |      |      |      |      |                    |      | NLOCK | /    | *    | -     |      |
 * |------+------+------+------+------+------|                    |------+-------+------+------+-------+------|
 * | PT   |      |      |      |      | DEL  |                    | PGUP | 7     | 8    | 9    | +     |      |
 * |------+------+------+------+------+------|                    |------+-------+------+------+-------+------|
 * | PT   |      |      |      |      | MWD  |-------.    ,-------| PGDN | 4     | 5    | 6    |       |      |
 * |------+------+------+------+------+------|       |    |       |------+-------+------+------+-------+------|
 * | PT   |      |      |      |      | MWU  |-------|    |-------| Home | 1     | 2    | 3    | Enter |      |
 * `-----------------------------------------/       /     \      \-------------------------------------------'
 *            | PT   | PT   |      | PT   | / PT    /       \      \  |      | 0    |      | .    |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            '-----------------------------------'           '------''---------------------------'        */   
[_SPECIAL] = LAYOUT(
  KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX,
  KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_PGUP, KC_P7,  KC_P8,   KC_P9,   KC_PPLS, XXXXXXX,
  KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,                        KC_PGDN, KC_P4,  KC_P5,   KC_P6,   XXXXXXX, XXXXXXX,
  KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_HOME, KC_P1,  KC_P2,   KC_P3,   KC_PENT, XXXXXXX,
                    KC_TRNS, KC_TRNS, XXXXXXX, KC_TRNS, KC_TRNS,     XXXXXXX, XXXXXXX, KC_P0,  XXXXXXX, KC_PDOT
),


/* Function
 * ,-----------------------------------------.                    ,------------------------------------------.
 * | F1   | F2   | F3   | F4   | F5   | F6   |                    |      |      | PP   | PT    | NT   | Mute |
 * |------+------+------+------+------+------|                    |------+------+------+-------+------+------|
 * | F7   | F8   | F9   | F10  | F11  | F12  |                    |      |      | Up   |       |      | VU   |
 * |------+------+------+------+------+------|                    |------+------+------+-------+------+------|
 * | PT   |      |      |      |      |      |-------.    ,-------|      | Left | Down | Right |      | VD   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+-------+------+------|
 * | PT   |      |      |      |      |      |-------|    |-------|      |      |      |       |      |      |
 * `-----------------------------------------/       /     \      \------------------------------------------'
 *            | PT   | PT   |      | PT   | / PT    /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            '-----------------------------------'           '------''---------------------------'         */
[_FUNCTION] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX, XXXXXXX, KC_MPLY, KC_MPRV,  KC_MNXT, KC_MUTE,
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                      XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,  XXXXXXX, KC_VOLU,
  KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, KC_VOLD,
  KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_WSCH,
                    KC_TRNS, KC_TRNS, XXXXXXX, KC_TRNS, KC_TRNS,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Characters
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | PT   |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | PT   | !    |      |      |      |      |                    | *    | %    | "    | '    | _    | |    |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | PT   | <    | [    | {    | (    | -    |-------.    ,-------| +    | )    | }    | ]    | >    | `    |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | PT   |      |      |      | @    | &    |-------|    |-------| ~    | ^    |      |      |      | ?    |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | PT   | PT   |      | PT   | / PT    /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            '-----------------------------------'           '------''---------------------------'        */
[_CHARACTERS] = LAYOUT(
  KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_TRNS, KC_EXLM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_ASTR, KC_PERC, KC_DQT , KC_QUOT, KC_UNDS, KC_PIPE,
  KC_TRNS, KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS,                       KC_PLUS, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK, KC_GRV,
  KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, KC_AT,   KC_AMPR, XXXXXXX,     XXXXXXX, KC_TILD, KC_CIRC, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUES,
                    KC_TRNS, KC_TRNS, XXXXXXX, KC_TRNS, KC_TRNS,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* One Shot
 * ,------------------------------------------.                    ,--------------------------------------------.
 * | Mute |      |      |      |       |      |                    | Boot |      |      |      |      | Options |
 * |------+------+------+------+-------+------|                    |------+------+------+------+------+---------|
 * |      |      |      |      |       |      |                    |      |      |      |      |      |         |
 * |------+------+------+------+-------+------|                    |------+------+------+------+------+---------|
 * |      |      |      |      | Find  |      |-------.    ,-------|      |      |      |      |      |         |
 * |------+------+------+------+-------+------|       |    |       |------+------+------+------+------+---------|
 * |      |      |      | Copy | Paste |      |-------|    |-------|      |      |      |      |      |         |
 * `------------------------------------------/       /     \      \--------------------------------------------'
 *            | PT   | PT   |      | PT    | / PT    /       \      \  |      |      |      |      |
 *            |      |      |      |       |/       /         \      \ |      |      |      |      |
 *            '------------------------------------'           '------''---------------------------'          */
[_ONESHOT] = LAYOUT(
  KC_KB_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OSM(_OPTIONS),
  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, KC_FIND, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,    XXXXXXX, XXXXXXX, KC_COPY, KC_PSTE, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                       KC_TRNS, KC_TRNS, XXXXXXX, KC_TRNS, KC_TRNS,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Options
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            '-----------------------------------'           '------''---------------------------'        */
[_OPTIONS] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, MU_ON,   CK_UP,   CK_ON,   AU_ON,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, MU_OFF,  CK_DOWN, CK_OFF,  AU_OFF,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, MU_TOGG, XXXXXXX, CK_TOGG, AU_TOGG,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)
};

/* Template layout
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            '-----------------------------------'           '------''---------------------------'        */
/*
[_FUNCTION] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
*/  

// Code stuff

// Layer states. Do custom fun shit here
bool oled_task_user() {
    oled_advance_page(true);
    switch (get_highest_layer(layer_state)) {
        case _BASE :
            oled_clear();
            oled_write("Main\nLayer", false);
            // const unsigned char test [] PROGMEM = {
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x3E, 0x5B, 0x4F, 0x5B, 0x3E, 0x00,
            //     0x3E, 0x6B, 0x4F, 0x6B, 0x3E, 0x00,
            //     0x1C, 0x3E, 0x7C, 0x3E, 0x1C, 0x00,
            //     0x18, 0x3C, 0x7E, 0x3C, 0x18, 0x00,
            //     0x1C, 0x57, 0x7D, 0x57, 0x1C, 0x00,
            //     0x1C, 0x5E, 0x7F, 0x5E, 0x1C, 0x00,
            //     0x00, 0x18, 0x3C, 0x18, 0x00, 0x00,
            //     0xFF, 0xE7, 0xC3, 0xE7, 0xFF, 0x00,
            //     0x00, 0x18, 0x24, 0x18, 0x00, 0x00,
            //     0xFF, 0xE7, 0xDB, 0xE7, 0xFF, 0x00,
            //     0x30, 0x48, 0x3A, 0x06, 0x0E, 0x00,
            //     0x26, 0x29, 0x79, 0x29, 0x26, 0x00,
            //     0x40, 0x7F, 0x05, 0x05, 0x07, 0x00,
            //     0x40, 0x7F, 0x05, 0x25, 0x3F, 0x00,
            //     0x5A, 0x3C, 0xE7, 0x3C, 0x5A, 0x00,
            //     0x7F, 0x3E, 0x1C, 0x1C, 0x08, 0x00,
            //     0x08, 0x1C, 0x1C, 0x3E, 0x7F, 0x00,
            //     0x14, 0x22, 0x7F, 0x22, 0x14, 0x00,
            //     0x5F, 0x5F, 0x00, 0x5F, 0x5F, 0x00,
            //     0x06, 0x09, 0x7F, 0x01, 0x7F, 0x00,
            //     0x00, 0x66, 0x89, 0x95, 0x6A, 0x00,
            //     0x60, 0x60, 0x60, 0x60, 0x60, 0x00,
            //     0x94, 0xA2, 0xFF, 0xA2, 0x94, 0x00,
            //     0x08, 0x04, 0x7E, 0x04, 0x08, 0x00,
            //     0x10, 0x20, 0x7E, 0x20, 0x10, 0x00,
            //     0x08, 0x08, 0x2A, 0x1C, 0x08, 0x00,
            //     0x08, 0x1C, 0x2A, 0x08, 0x08, 0x00,
            //     0x1E, 0x10, 0x10, 0x10, 0x10, 0x00,
            //     0x0C, 0x1E, 0x0C, 0x1E, 0x0C, 0x00,
            //     0x30, 0x38, 0x3E, 0x38, 0x30, 0x00,
            //     0x06, 0x0E, 0x3E, 0x0E, 0x06, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x5F, 0x00, 0x00, 0x00,
            //     0x00, 0x07, 0x00, 0x07, 0x00, 0x00,
            //     0x14, 0x7F, 0x14, 0x7F, 0x14, 0x00,
            //     0x24, 0x2A, 0x7F, 0x2A, 0x12, 0x00,
            //     0x23, 0x13, 0x08, 0x64, 0x62, 0x00,
            //     0x36, 0x49, 0x56, 0x20, 0x50, 0x00,
            //     0x00, 0x08, 0x07, 0x03, 0x00, 0x00,
            //     0x00, 0x1C, 0x22, 0x41, 0x00, 0x00,
            //     0x00, 0x41, 0x22, 0x1C, 0x00, 0x00,
            //     0x2A, 0x1C, 0x7F, 0x1C, 0x2A, 0x00,
            //     0x08, 0x08, 0x3E, 0x08, 0x08, 0x00,
            //     0x00, 0x80, 0x70, 0x30, 0x00, 0x00,
            //     0x08, 0x08, 0x08, 0x08, 0x08, 0x00,
            //     0x00, 0x00, 0x60, 0x60, 0x00, 0x00,
            //     0x20, 0x10, 0x08, 0x04, 0x02, 0x00,
            //     0x3E, 0x51, 0x49, 0x45, 0x3E, 0x00,
            //     0x00, 0x42, 0x7F, 0x40, 0x00, 0x00,
            //     0x72, 0x49, 0x49, 0x49, 0x46, 0x00,
            //     0x21, 0x41, 0x49, 0x4D, 0x33, 0x00,
            //     0x18, 0x14, 0x12, 0x7F, 0x10, 0x00,
            //     0x27, 0x45, 0x45, 0x45, 0x39, 0x00,
            //     0x3C, 0x4A, 0x49, 0x49, 0x31, 0x00,
            //     0x41, 0x21, 0x11, 0x09, 0x07, 0x00,
            //     0x36, 0x49, 0x49, 0x49, 0x36, 0x00,
            //     0x46, 0x49, 0x49, 0x29, 0x1E, 0x00,
            //     0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
            //     0x00, 0x40, 0x34, 0x00, 0x00, 0x00,
            //     0x00, 0x08, 0x14, 0x22, 0x41, 0x00,
            //     0x14, 0x14, 0x14, 0x14, 0x14, 0x00,
            //     0x00, 0x41, 0x22, 0x14, 0x08, 0x00,
            //     0x02, 0x01, 0x59, 0x09, 0x06, 0x00,
            //     0x3E, 0x41, 0x5D, 0x59, 0x4E, 0x00,
            //     0x7C, 0x12, 0x11, 0x12, 0x7C, 0x00,
            //     0x7F, 0x49, 0x49, 0x49, 0x36, 0x00,
            //     0x3E, 0x41, 0x41, 0x41, 0x22, 0x00,
            //     0x7F, 0x41, 0x41, 0x41, 0x3E, 0x00,
            //     0x7F, 0x49, 0x49, 0x49, 0x41, 0x00,
            //     0x7F, 0x09, 0x09, 0x09, 0x01, 0x00,
            //     0x3E, 0x41, 0x41, 0x51, 0x73, 0x00,
            //     0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00,
            //     0x00, 0x41, 0x7F, 0x41, 0x00, 0x00,
            //     0x20, 0x40, 0x41, 0x3F, 0x01, 0x00,
            //     0x7F, 0x08, 0x14, 0x22, 0x41, 0x00,
            //     0x7F, 0x40, 0x40, 0x40, 0x40, 0x00,
            //     0x7F, 0x02, 0x1C, 0x02, 0x7F, 0x00,
            //     0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00,
            //     0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00,
            //     0x7F, 0x09, 0x09, 0x09, 0x06, 0x00,
            //     0x3E, 0x41, 0x51, 0x21, 0x5E, 0x00,
            //     0x7F, 0x09, 0x19, 0x29, 0x46, 0x00,
            //     0x26, 0x49, 0x49, 0x49, 0x32, 0x00,
            //     0x03, 0x01, 0x7F, 0x01, 0x03, 0x00,
            //     0x3F, 0x40, 0x40, 0x40, 0x3F, 0x00,
            //     0x1F, 0x20, 0x40, 0x20, 0x1F, 0x00,
            //     0x3F, 0x40, 0x38, 0x40, 0x3F, 0x00,
            //     0x63, 0x14, 0x08, 0x14, 0x63, 0x00,
            //     0x03, 0x04, 0x78, 0x04, 0x03, 0x00,
            //     0x61, 0x59, 0x49, 0x4D, 0x43, 0x00,
            //     0x00, 0x7F, 0x41, 0x41, 0x41, 0x00,
            //     0x02, 0x04, 0x08, 0x10, 0x20, 0x00,
            //     0x00, 0x41, 0x41, 0x41, 0x7F, 0x00,
            //     0x04, 0x02, 0x01, 0x02, 0x04, 0x00,
            //     0x40, 0x40, 0x40, 0x40, 0x40, 0x00,
            //     0x00, 0x03, 0x07, 0x08, 0x00, 0x00,
            //     0x20, 0x54, 0x54, 0x78, 0x40, 0x00,
            //     0x7F, 0x28, 0x44, 0x44, 0x38, 0x00,
            //     0x38, 0x44, 0x44, 0x44, 0x28, 0x00,
            //     0x38, 0x44, 0x44, 0x28, 0x7F, 0x00,
            //     0x38, 0x54, 0x54, 0x54, 0x18, 0x00,
            //     0x00, 0x08, 0x7E, 0x09, 0x02, 0x00,
            //     0x18, 0x24, 0x24, 0x1C, 0x78, 0x00,
            //     0x7F, 0x08, 0x04, 0x04, 0x78, 0x00,
            //     0x00, 0x44, 0x7D, 0x40, 0x00, 0x00,
            //     0x20, 0x40, 0x40, 0x3D, 0x00, 0x00,
            //     0x7F, 0x10, 0x28, 0x44, 0x00, 0x00,
            //     0x00, 0x41, 0x7F, 0x40, 0x00, 0x00,
            //     0x7C, 0x04, 0x78, 0x04, 0x78, 0x00,
            //     0x7C, 0x08, 0x04, 0x04, 0x78, 0x00,
            //     0x38, 0x44, 0x44, 0x44, 0x38, 0x00,
            //     0x7C, 0x18, 0x24, 0x24, 0x18, 0x00,
            //     0x18, 0x24, 0x24, 0x18, 0x7C, 0x00,
            //     0x7C, 0x08, 0x04, 0x04, 0x08, 0x00,
            //     0x48, 0x54, 0x54, 0x54, 0x24, 0x00,
            //     0x04, 0x04, 0x3F, 0x44, 0x24, 0x00,
            //     0x3C, 0x40, 0x40, 0x20, 0x7C, 0x00,
            //     0x1C, 0x20, 0x40, 0x20, 0x1C, 0x00,
            //     0x3C, 0x40, 0x30, 0x40, 0x3C, 0x00,
            //     0x44, 0x28, 0x10, 0x28, 0x44, 0x00,
            //     0x4C, 0x90, 0x90, 0x90, 0x7C, 0x00,
            //     0x44, 0x64, 0x54, 0x4C, 0x44, 0x00,
            //     0x00, 0x08, 0x36, 0x41, 0x00, 0x00,
            //     0x00, 0x00, 0x77, 0x00, 0x00, 0x00,
            //     0x00, 0x41, 0x36, 0x08, 0x00, 0x00,
            //     0x02, 0x01, 0x02, 0x04, 0x02, 0x00,
            //     0x3C, 0x26, 0x23, 0x26, 0x3C, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0,
            //     0xF0, 0xF8, 0xF8, 0x18, 0x00, 0xC0,
            //     0xF0, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF,
            //     0xFF, 0xFF, 0xFF, 0xFF, 0x7E, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0xE7, 0xE7, 0xE7, 0x00, 0x00, 0x00,
            //     0x80, 0xC0, 0xE0, 0xE0, 0xE0, 0xE0,
            //     0xE0, 0xE0, 0xE0, 0xE0, 0xC0, 0x80,
            //     0x00, 0x00, 0x00, 0xE0, 0xE0, 0xC0,
            //     0xC0, 0xE0, 0xE0, 0xE0, 0xE0, 0x00,
            //     0x00, 0xE0, 0xE0, 0xC0, 0xC0, 0xE0,
            //     0xE0, 0xE0, 0xE0, 0xE0, 0xC0, 0x80,
            //     0x00, 0x00, 0x00, 0x00, 0x80, 0xC0,
            //     0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0,
            //     0xE0, 0xE0, 0xC0, 0x80, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0xE0, 0xF0, 0xF0, 0xF0, 0xE0, 0xEC,
            //     0xEE, 0xF7, 0xF3, 0x70, 0x20, 0x00,
            //     0x7C, 0x7C, 0x7C, 0x7E, 0x00, 0x7E,
            //     0x7E, 0x7E, 0x7F, 0x7F, 0x7F, 0x00,
            //     0x00, 0x80, 0xC0, 0xE0, 0x7E, 0x5B,
            //     0x4F, 0x5B, 0xFE, 0xC0, 0x00, 0x00,
            //     0xC0, 0x00, 0xDC, 0xD7, 0xDE, 0xDE,
            //     0xDE, 0xD7, 0xDC, 0x00, 0xC0, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0xF8, 0xFC, 0xFE,
            //     0xFF, 0xE0, 0x00, 0xFF, 0xFF, 0xFF,
            //     0xFF, 0xFF, 0xFF, 0x80, 0xFF, 0xFF,
            //     0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
            //     0xFF, 0x1F, 0x07, 0x01, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF,
            //     0xFF, 0xFF, 0x81, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x81, 0xFF, 0xFF,
            //     0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
            //     0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0xFF, 0xFF, 0xFF, 0x01, 0x00,
            //     0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF,
            //     0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
            //     0x9D, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C,
            //     0x1C, 0x9D, 0xDF, 0xDF, 0xDF, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x0F, 0x1F, 0x3F, 0x7F, 0x7F, 0x7F,
            //     0x7F, 0x7F, 0x3F, 0x1E, 0x0C, 0x00,
            //     0x1F, 0x1F, 0x1F, 0x3F, 0x00, 0x3F,
            //     0x3F, 0x3F, 0x7F, 0x7F, 0x7F, 0x00,
            //     0x30, 0x7B, 0x7F, 0x78, 0x30, 0x20,
            //     0x20, 0x30, 0x78, 0x7F, 0x3B, 0x00,
            //     0x03, 0x00, 0x0F, 0x7F, 0x0F, 0x0F,
            //     0x0F, 0x7F, 0x0F, 0x00, 0x03, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x03, 0x0F, 0x1F,
            //     0x3F, 0x3F, 0x3F, 0x3F, 0x1F, 0x1F,
            //     0x3F, 0x3F, 0x7F, 0x7F, 0x7F, 0x3F,
            //     0x3F, 0x1F, 0x3F, 0x7F, 0x7F, 0x7F,
            //     0x7F, 0x7C, 0x78, 0x78, 0x38, 0x1C,
            //     0x0F, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x70, 0x70,
            //     0x70, 0x70, 0x70, 0x70, 0x70, 0x78,
            //     0x3F, 0x1F, 0x0F, 0x00, 0x00, 0x00,
            //     0x01, 0x03, 0x07, 0x07, 0x07, 0x07,
            //     0x07, 0x07, 0x07, 0x07, 0x03, 0x01,
            //     0x00, 0x00, 0x00, 0x07, 0x07, 0x07,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x07, 0x07, 0x07, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x07, 0x07,
            //     0x07, 0x00, 0x00, 0x00, 0x01, 0x03,
            //     0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
            //     0x07, 0x07, 0x03, 0x01, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            // };
            break;
        case _FUNCTION : 
            oled_clear();
            oled_write("Func\nLayer", false);
            break;
        case _SPECIAL :
            oled_clear();
            oled_write("Spec\nLayer", false);
            break;
        case _CHARACTERS :
            oled_clear();
            oled_write("Char\nLayer", false);
            break;
        case _ONESHOT :
            oled_clear();
            oled_write("Cum\nLayer", false);
            break;
        }
    return false;
}

// This orients the non-master hand to display right-side-up
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        oled_clear();
        return OLED_ROTATION_270;  // flips the display 270 degrees if offhand
    }
    return rotation;
}

// Standard ASCII 5x7 font
