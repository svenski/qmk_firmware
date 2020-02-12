#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = 
        LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T,                KC_Y, KC_U, KC_I, KC_O, KC_P,
    LSFT_T(KC_A), KC_S, LCTL_T(KC_D), LALT_T(KC_F), KC_G,                KC_H, RALT_T(KC_J), RCTL_T(KC_K), KC_L, RSFT_T(KC_SCLN),
    KC_Z, KC_X, KC_C, KC_V, KC_B,                KC_N, KC_M, KC_COMM, KC_DOT, KC_QUOT,
                 MO(1), LGUI_T(              KC_ESC), LT(4,KC_ENT), LT(2,KC_SPC), RGUI_T(KC_BSPC), MO(3)),

	[1] = LAYOUT(
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PEQL,
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS,
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_PCMM, KC_P1, KC_P2, KC_P3, KC_PMNS,
             KC_TRNS, KC_NO, KC_NO,               KC_DEL, KC_P0, KC_PDOT),
	[2] = LAYOUT(
KC_NO, KC_NO, KC_NO, KC_EXLM, KC_LT,                KC_GT, KC_DLR, KC_NO, KC_NO, KC_NO,
KC_NO, KC_HASH, KC_LBRC, KC_LPRN, KC_LCBR,                KC_RCBR, KC_RPRN, KC_RBRC, KC_AT, KC_NO,
KC_NO, KC_NO, KC_NO, KC_SLSH, KC_UNDS,                KC_CIRC, KC_PERC, KC_NO, KC_NO, KC_NO,
             KC_NO, KC_BSLS, KC_QUOT,               KC_NO, KC_NO, KC_NO),
	[3] = LAYOUT(
KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, LCTL(LSFT(KC_ESC)), LCTL(LALT(KC_DEL)),
RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS),
	[4] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BTN1, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_NO, KC_NO, KC_NO, KC_NO, KC_TAB, KC_DEL, KC_NO)
};
