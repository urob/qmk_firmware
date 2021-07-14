#pragma once

#include QMK_KEYBOARD_H
//
// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
uint8_t oneshot_mod_state;
uint16_t last_keycode;

bool caps_word_on;
void caps_word_enable(void);
void caps_word_disable(void);

enum layer_names {
    BASE,
    _CAL,
    _NAV,
    _NUM,
    _SYS,
    _FN,
    _GRK,
    _ADJUST,
};

enum custom_keycodes {
    CAPS_WORD = SAFE_RANGE,
    REPEAT,
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_GUI,
};

// Layer keys
#define ESC_SYS  LT(_SYS, KC_ESC)
#define SPC_NAV  LT(_NAV, KC_SPACE)
#define TAB_GRK  LT(_GRK, KC_TAB)
#define ENT_GRK  LT(_GRK, KC_ENT)
#define BS_NUM   LT(_NUM, KC_BSPACE)
#define DEL_FN   LT(_FN, KC_DEL)
#define REP_NUM  LT(_NUM, KC_NO) // tap-hold required basic key
#define SFT_NUM  LT(_NUM, KC_F22) // tap-hold required basic key
#define BS_FN    LT(_FN, KC_BSPACE)


// Misc keys
#define UNDO     LCTL(KC_Z)
#define REDO     LCTL(LSFT(KC_Z))
#define CUT      LCTL(KC_X)    // LSFT(KC_DEL)
#define COPY     LCTL(KC_INS)  // LCTL(KC_C)
#define PASTE    LSFT(KC_INS)  // LCTL(KC_V)
#define DSK_LT   LGUI(LCTL(KC_LEFT))  // prev desktop in Windows 10
#define DSK_RT   LGUI(LCTL(KC_RIGHT)) // next desktop in Windows 10
#define ADJUST   MO(_ADJUST)
#define EQM      LALT(KC_EQL)

#define FZ_L1    LALT(LCTL(LGUI(KC_1)))  // fancy zones layout 1
#define FZ_L2    LALT(LCTL(LGUI(KC_2)))  // fancy zones layout 2
#define FZ_L3    LALT(LCTL(LGUI(KC_3)))  // fancy zones layout 3
#define FZ_LE    LGUI(KC_TILD)           // fancy zones layout editor

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LCTL_T(KC_S)
#define HOME_T LSFT_T(KC_T)

// Right-hand home row mods
#define HOME_N RSFT_T(KC_N)
#define HOME_E RCTL_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)

