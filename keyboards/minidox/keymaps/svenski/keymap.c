
#include QMK_KEYBOARD_H

#define KC_TRANS KC_TRANSPARENT

//Tap Dance Declarations
enum {
  TD_Q_ESC = 0,
  TD_H_EQ = 1,
  TD_I_STAR = 2
};

qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_Q_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
  [TD_H_EQ]  = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_EQUAL),
  [TD_I_STAR]  = ACTION_TAP_DANCE_DOUBLE(KC_I, LSFT(KC_8))
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
TD(TD_Q_ESC), KC_W, KC_E, KC_R, KC_T,                KC_Y, KC_U, TD(TD_I_STAR), KC_O, KC_P,
KC_A, MT(MOD_LSFT, KC_S), LCTL_T(KC_D), LALT_T(KC_F), KC_G,               TD(TD_H_EQ) , RALT_T(KC_J), RCTL_T(KC_K), RSFT_T(KC_L),KC_SCLN,
LGUI_T(KC_Z), KC_X, KC_C, KC_V, KC_B,                KC_N, KC_M, KC_COMM, KC_DOT, LGUI_T(KC_QUOT),
             LT(4,KC_NONUS_HASH), LT(1,KC_TAB), LT(5,KC_ENT),       LT(2,KC_SPC), LT(3,KC_BSPC), KC_SLASH),
	[1] = LAYOUT(
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_PSLS, KC_7, KC_8, KC_9, KC_PEQL,
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_PAST, KC_4, KC_5, KC_6, KC_PPLS,
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_DOT, KC_1, KC_2, KC_3, KC_PMNS,
             KC_TRNS, KC_NO, KC_NO,               KC_SPACE, KC_0, KC_COMM),

	[2] = LAYOUT(
            KC_NO, KC_NO, LSFT(KC_SLSH), KC_EXLM, KC_LT,                KC_GT, KC_PERC, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_HASH, KC_LBRC, KC_LPRN, KC_LCBR,                KC_RCBR, KC_RPRN, KC_RBRC, KC_AT, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_SLSH, KC_UNDS,                KC_CIRC, KC_DLR, KC_NO, KC_NO, KC_NO,
                             KC_NO, KC_BSLS, LSFT(KC_SLSH),               KC_NO, KC_NO, KC_NO),
	[3] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,       KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
            KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, LCTL(LSFT(KC_ESC)), LCTL(LALT(KC_DEL)),
            RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCREEN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[4] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_SLASH, KC_NONUS_HASH,     KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BTN1,
            KC_NO, KC_NO, KC_NO, KC_GRAVE, KC_BSLASH,    KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO,
            KC_NO, KC_NO, KC_NO,                           KC_TAB, KC_DEL, KC_NO),

 [5] = LAYOUT(KC_TRANS,KC_TRANS,KC_TRANS,KC_TRANS,KC_TRANS,      KC_GT,KC_PERC,KC_TRANS,KC_TRANS,KC_TRANS,
         KC_TRANS,KC_TRANS,KC_KP_MINUS,KC_SLASH,KC_BSLASH,    KC_RCBR,KC_RPRN,KC_RBRACKET,KC_AT,KC_EQUAL,
         KC_TRANS,KC_TRANS,KC_TRANS,KC_GRAVE,KC_NONUS_HASH,   KC_CIRC,KC_DLR,KC_TRANS,KC_TRANS,KC_TRANS,
                               KC_TRANS,KC_TRANS,KC_TRANS,   KC_TAB,KC_DEL,KC_TRANS)
};

void matrix_init_user(void) {
#ifdef BOOTLOADER_CATERINA
    // This will disable the red LEDs on the ProMicros
    setPinInput(D5);
    setPinInput(B0);
#endif
};


