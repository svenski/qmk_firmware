#include QMK_KEYBOARD_H

#define TAPPING_TERM 50

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | MO(1)       | esc/lay4| | back | bspc | LOWER |
 *                  `-------------|enter/gui| |Space |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[0] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T,                                KC_Y, KC_U, KC_I, KC_O, KC_P, 
        KC_A, LSFT_T(KC_S), LCTL_T(KC_D), LALT_T(KC_F), KC_G,        KC_H, RALT_T(KC_J), RCTL_T(KC_K), RSFT_T(KC_L), KC_SCLN, 
        KC_Z, KC_X, KC_C, KC_V, KC_B,                                KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, 
                 MO(1), LT(4,KC_ESC), LGUI_T(KC_ENT),                LT(2,KC_SPC), KC_BSPC, , MO(3)
           ),

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | Shift/Esc | GUI/Tab|    |      | RAISE| LOWER |
 *                  `-------------|BSpace|    |Space |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
	[1] = LAYOUT(
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PEQL,
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS,
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_PCMM, KC_P1, KC_P2, KC_P3, KC_PMNS,
             KC_TRNS, KC_NO, KC_NO,               KC_DEL, KC_P0, KC_PDOT),

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | Shift/Esc | GUI/Tab|    |      | RAISE| LOWER |
 *                  `-------------|BSpace|    |Space |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
	[2] = LAYOUT(
KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_GT,                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
KC_PERC, KC_DLR, KC_LPRN, KC_RPRN, KC_LT,                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
KC_GRV, KC_CIRC, KC_LBRC, KC_RBRC, KC_UNDS,                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
             KC_SLSH, KC_BSLS, KC_QUOT,               KC_NO, KC_NO, KC_NO),

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | Shift/Esc | GUI/Tab|    |      | RAISE| LOWER |
 *                  `-------------|BSpace|    |Space |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
	[3] = LAYOUT(
KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, LCTL(LSFT(KC_ESC)), LCTL(LALT(KC_DEL)),
RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS)
};
