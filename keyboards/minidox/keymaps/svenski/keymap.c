
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
  TD_Q_ESC = 0,
  TD_Y_EQ = 1,
  TD_I_CAP = 2,
  TD_CLN = 3
};

qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_Q_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
  [TD_Y_EQ]  = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_EQUAL),
  [TD_I_CAP]  = ACTION_TAP_DANCE_DOUBLE(KC_I, LSFT(KC_8)),
  [TD_CLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset)
// Other declarations would go here, separated by commas, if you have them
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
TD(TD_Q_ESC), KC_W, KC_E, KC_R, KC_T,                TD(TD_Y_EQ), MT(MOD_LALT, KC_U), TD(TD_I_CAP), KC_O, KC_P,
MT(MOD_LALT, KC_A), MT(MOD_LSFT, KC_S), LCTL_T(KC_D), LT(2,KC_F), KC_G,               KC_H , LT(2,KC_J), RCTL_T(KC_K), RSFT_T(KC_L),TD(TD_CLN),
LGUI_T(KC_Z), KC_X, KC_C, KC_V, KC_B,                KC_N, KC_M, KC_COMM, KC_DOT, LGUI_T(KC_QUOT),
             ALT_T(KC_ESCAPE), LT(4,KC_TAB), LT(1,KC_ENT),       LT(5,KC_SPC), LT(3,KC_BSPC), ALT_T(KC_SLASH)),
	[1] = LAYOUT(
KC_NO, RCTL(KC_W), LCTL(LSFT(KC_LEFT)), LCTL(LSFT(KC_RGHT)), RCTL(KC_T),               LSFT(KC_8), KC_7, KC_8, KC_9,  KC_PEQL,
RCTL(KC_A), RCTL(KC_S), LCTL(KC_LEFT), LCTL(KC_RGHT), KC_NO,               LSFT(KC_EQUAL), KC_4, KC_5, KC_6,  KC_MINUS,
RCTL(KC_Z), RCTL(KC_X), RCTL(KC_C), RCTL(KC_V), KC_NO,               KC_SLASH, KC_1, KC_2, KC_3, KC_DOT, 
             KC_TRNS, KC_NO, KC_NO,               KC_0, KC_BSPC, KC_COMM),

	[2] = LAYOUT(
            KC_NO, KC_AMPR, KC_LT, KC_GT,KC_PERC,                LSFT(KC_NONUS_HASH), KC_LBRC, KC_RBRACKET, KC_NO, KC_LBRC,
            KC_NONUS_HASH, KC_HASH, LSFT(KC_NONUS_BSLASH), KC_UNDS, KC_EXLM,                KC_CIRC, KC_LPRN, KC_RPRN, KC_DLR, KC_SCOLON,
            KC_NO, KC_NO, KC_NO, KC_SLSH, KC_NONUS_BSLASH,                KC_DQUO, KC_LCBR, KC_RCBR, KC_NO, LSFT(KC_2),
                             KC_NO, KC_BSLS, LSFT(KC_SLSH),               KC_MINS, KC_DELETE, KC_NO),
	[3] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,       KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
            KC_F11, KC_F12, KC_TRNS, KC_CAPSLOCK, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, LCTL(LSFT(KC_ESC)), LCTL(LALT(KC_DEL)),
            RESET, LALT(KC_F4), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCREEN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[4] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_SLASH, KC_NONUS_HASH,     KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BTN1,
            KC_NO, KC_NO, KC_NO, KC_GRAVE, KC_BSLASH,    KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO,
            KC_NO, KC_NO, KC_NO,                           KC_TAB, KC_DEL, KC_NO),

 [5] = LAYOUT(KC_TRANS,KC_TRANS,KC_TRANS,KC_TRANS,KC_TRANS,      LCTL(LALT(KC_LEFT)),LCTL(LALT(KC_U)),LCTL(LALT(KC_I)),LCTL(LALT(KC_RIGHT)),LCTL(LALT(KC_P)),
         KC_TRANS,KC_TRANS,KC_KP_MINUS,KC_TAB,KC_SLASH,    LCTL(LALT(KC_H)),LCTL(LALT(KC_J)),LCTL(LALT(KC_K)),LCTL(LALT(KC_L)),KC_EQUAL,
         KC_TRANS,KC_TRANS,KC_TRANS,KC_GRAVE,KC_NONUS_HASH,   LCTL(LALT(KC_N)),LCTL(LALT(KC_M)),KC_TRANS,KC_TRANS,KC_TRANS,
                               KC_TRANS,KC_TRANS,LALT(KC_TAB),   KC_NO,KC_DEL,KC_TRANS)
};

void matrix_init_user(void) {
#ifdef BOOTLOADER_CATERINA
    // This will disable the red LEDs on the ProMicros
    setPinInput(D5);
    setPinInput(B0);
#endif
};


// MT(MOD_LALT, LSFT(KC_SCLN))