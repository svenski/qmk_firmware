
#include QMK_KEYBOARD_H

#define KC_TRANS KC_TRANSPARENT


void dance_cln_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_SCLN);
  } else {
    register_code (KC_RSFT);
    register_code (KC_SCLN);
  }
}

void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_SCLN);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_SCLN);
  }
}

//Tap Dance Declarations
enum {
  TD_H_ESQ = 0,
  TD_Y_EQ = 1,
  TD_U_CAP = 2,
  TD_CLN = 3
};

qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_H_ESQ]  = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_ESC),
  [TD_Y_EQ]  = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_EQUAL),
  [TD_U_CAP]  = ACTION_TAP_DANCE_DOUBLE(KC_U, LSFT(KC_8)),
  [TD_CLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset)
// Other declarations would go here, separated by commas, if you have them
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
KC_Q, KC_W, KC_F, KC_P, KC_G,                KC_J, KC_L, TD(TD_U_CAP), KC_Y, KC_SCOLON,
MT(MOD_LALT, KC_A), MT(MOD_LSFT, KC_R), LCTL_T(KC_S), LT(2,KC_T), KC_D,               TD(TD_H_ESQ) , LT(2,KC_N), RCTL_T(KC_E), RSFT_T(KC_I),MT(MOD_LALT, KC_O),
LGUI_T(KC_Z), KC_X, KC_C, KC_V, KC_B,                KC_K, KC_M, KC_COMM, KC_DOT, LGUI_T(KC_QUOT),
             ALT_T(KC_ESCAPE), LT(4,KC_TAB), LT(1,KC_ENT),       LT(5,KC_SPC), LT(3,KC_BSPC), ALT_T(KC_SLASH)),
	[1] = LAYOUT(
KC_NO, RGUI(KC_W), RGUI(KC_F), RGUI(KC_P), RGUI(KC_G),               LSFT(KC_8), KC_7, KC_8, KC_9,  KC_PEQL,
RGUI(KC_A), RGUI(KC_R), RGUI(KC_S), RGUI(KC_T), RGUI(KC_D),               LSFT(KC_EQUAL), KC_4, KC_5, KC_6,  KC_MINUS,
RGUI(KC_Z), RGUI(KC_X), RGUI(KC_C), RGUI(KC_V), RGUI(KC_B),               KC_SLASH, KC_1, KC_2, KC_3, KC_DOT, 
             KC_TRNS, KC_NO, KC_NO,               KC_0, KC_BSPC, KC_COMM),

	[2] = LAYOUT(
            KC_NO, KC_AMPR, KC_LT, KC_GT,KC_PERC,                LSFT(KC_NONUS_HASH), KC_LBRC, KC_PLUS, KC_RBRACKET, KC_LBRC,
            KC_NONUS_BSLASH, KC_HASH, KC_QUESTION, KC_UNDS, KC_EXLM,                KC_CIRC, KC_LPRN, KC_DOLLAR, KC_RPRN, KC_COLON,
            KC_GRAVE, KC_NONUS_BSLASH, LSFT(KC_GRAVE), KC_SLSH, KC_GRAVE,                LSFT(KC_8), KC_LCBR, KC_MINS, KC_RCBR, LSFT(KC_2),
                             KC_NO, KC_BSLS, KC_EQUAL,               KC_MINS, KC_DELETE, KC_NO),
	[3] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,       KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
            KC_MPRV, KC_MNXT, KC_VOLU, KC_CAPSLOCK, LALT(KC_F4),     KC_TRNS, KC_HOME, KC_TRNS, KC_F11, KC_F12,
            KC_MSTP, KC_MPLY, KC_VOLD, KC_PSCREEN, RESET, KC_TRNS, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, DF(6), KC_TRNS, LGUI(LALT(KC_BSPACE)), KC_TRNS, KC_TRNS, KC_TRNS),

	[4] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_SLASH, KC_NONUS_HASH,     KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BTN1,
            KC_NO, KC_NO, KC_NO, KC_GRAVE, KC_BSLASH,    LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RGHT), KC_NO,
            KC_NO, KC_NO, KC_NO,                           KC_TAB, KC_DEL, KC_NO),

 [5] = LAYOUT(KC_TRANS,KC_TRANS,KC_TRANS,KC_TRANS,KC_TRANS,      LCTL(LALT(KC_LEFT)),LALT(KC_7),LALT(KC_8),LALT(KC_9),LSFT(LCTL(LALT(KC_LEFT))),
         KC_TRANS,KC_TRANS,KC_KP_MINUS,KC_TAB,KC_SLASH,    LALT(KC_H),LALT(KC_4),LALT(KC_5),LALT(KC_6),LALT(KC_L),
         KC_TRANS,KC_TRANS,KC_TRANS,KC_GRAVE,KC_NONUS_HASH,   LCTL(LALT(KC_N)),LALT(KC_1),LALT(KC_2),LALT(KC_3),KC_TRANS,
                               KC_TRANS,KC_TRANS,LALT(KC_TAB),   KC_NO,KC_DEL,KC_TRANS),
	[6] = LAYOUT(
KC_Q, KC_W, KC_F, KC_P, KC_G,                KC_J, KC_L, TD(TD_U_CAP), KC_Y, KC_SCOLON,
MT(MOD_LALT, KC_A), MT(MOD_LSFT, KC_R), LCTL_T(KC_S), LT(8,KC_T), KC_D,               TD(TD_H_ESQ) , LT(8,KC_N), RCTL_T(KC_E), RSFT_T(KC_I),MT(MOD_LALT, KC_O),
LGUI_T(KC_Z), KC_X, KC_C, KC_V, KC_B,                KC_K, KC_M, KC_COMM, KC_DOT, LGUI_T(KC_QUOT),
             ALT_T(KC_ESCAPE), LT(4,KC_TAB), LT(7,KC_ENT),       LT(5,KC_SPC), LT(9,KC_BSPC), ALT_T(KC_SLASH)),
  	[7] = LAYOUT(
KC_NO, RCTL(KC_W), RCTL(KC_F), RCTL(KC_P), RCTL(KC_G),               LSFT(KC_8), KC_7, KC_8, KC_9,  KC_PEQL,
RCTL(KC_A), RCTL(KC_R), RCTL(KC_S), RCTL(KC_T), RCTL(KC_D),               LSFT(KC_EQUAL), KC_4, KC_5, KC_6,  KC_MINUS,
RCTL(KC_Z), RCTL(KC_X), RCTL(KC_C), RCTL(KC_V), RCTL(KC_B),               KC_SLASH, KC_1, KC_2, KC_3, KC_DOT, 
             KC_TRNS, KC_NO, KC_NO,               KC_0, KC_BSPC, KC_COMM),
	[8] = LAYOUT(
            KC_NO, KC_AMPR, KC_LT, KC_GT,KC_PERC,                LSFT(KC_NONUS_HASH), KC_LBRC, KC_PLUS, KC_RBRACKET, KC_LBRC,
            KC_GRAVE, KC_HASH, KC_QUESTION, KC_UNDS, KC_EXLM,                KC_CIRC, KC_LPRN, KC_DOLLAR, KC_RPRN, KC_COLON,
            KC_NONUS_BSLASH, KC_NO, LSFT(KC_NONUS_BSLASH), KC_SLSH, KC_NONUS_BSLASH,                LSFT(KC_8), KC_LCBR, KC_MINS, KC_RCBR, LSFT(KC_2),
                             KC_NO, KC_BSLS, KC_EQUAL,               KC_MINS, KC_DELETE, KC_NO),
 [9] = LAYOUT(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,DF(0),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT)
};

void matrix_init_user(void) {
#ifdef BOOTLOADER_CATERINA
    // This will disable the red LEDs on the ProMicros
    setPinInput(D5);
    setPinInput(B0);
#endif
};


// MT(MOD_LALT, LSFT(KC_SCLN))