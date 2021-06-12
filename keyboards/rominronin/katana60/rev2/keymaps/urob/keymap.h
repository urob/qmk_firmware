#pragma once

#include QMK_KEYBOARD_H

bool caps_word_on;
void caps_word_enable(void);
void caps_word_disable(void);

enum layer_names {
    BASE,
    _NAV,
    _NUM,
    _SYM,
    _SYS,
    _FN,
    _GRK,
    _ADJUST,
};

enum custom_keycodes {
    CAPS_WORD = SAFE_RANGE,
    MT_TAU, // dummy keycode
    MT_NU // dummy keycode
};

// Layer keys
#define ESC_SYS  LT(_SYS, KC_ESC)
#define SPC_NAV  LT(_NAV, KC_SPACE)
#define TAB_GRK  LT(_GRK, KC_TAB)
#define ENT_GRK  LT(_GRK, KC_ENT)
#define BS_NUM   LT(_NUM, KC_BSPACE)
#define DEL_FN   LT(_FN, KC_DEL)

// #define OSL_GRK  LSFT_T(OSL(_GRK))
#define OSL_GRK  OSL(_GRK)

// Misc keys
#define UNDO     LCTL(KC_Z)
#define REDO     LCTL(LSFT(KC_Z))
#define CUT      LCTL(KC_X)
#define COPY     LCTL(KC_C)
#define PASTE    LCTL(KC_V)
#define DSK_LT   LGUI(LCTL(KC_LEFT))  // prev desktop in Windows 10
#define DSK_RT   LGUI(LCTL(KC_RIGHT)) // next desktop in Windows 10
#define WIN_LT   LALT(LCTL(LSFT(KC_TAB)))  // prev window in Windows 10
#define WIN_RT   LALT(LCTL(KC_TAB))  // prev window in Windows 10
#define ADJUST   MO(_ADJUST)
#define EQM      LALT(KC_EQL)

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

// Greek letters and German umlauts
enum unicode_names {
    /* Greek letters (capitalized) */
    U_C_GAMM,
    U_C_DELT,
    U_C_THET,
    U_C_LAMB,
    U_C_XI,
    U_C_PI,
    U_C_SIGM,
    U_C_UPSI,
    U_C_PHI,
    U_C_PSI,
    U_C_OMEG,
    /* Greek letters */
    U_ALPH,
    U_BETA,
    U_GAMM,
    U_DELT,
    U_EPSI,
    U_ZETA,
    U_ETA,
    U_THET,
    U_IOTA,
    U_KAPP,
    U_LAMB,
    U_MU,
    U_NU,
    U_XI,
    U_PI,
    U_RHO,
    U_SIGM,
    U_TAU,
    U_UPSI,
    U_PHI,
    U_CHI,
    U_PSI,
    U_OMEG,
    /* German umlauts */
    U_AE, U_C_AE,
    U_OE, U_C_OE,
    U_UE, U_C_UE,
    U_SS,
};

#define ALPHA X(U_ALPH)
#define BETA X(U_BETA)
#define GAMMA XP(U_GAMM, U_C_GAMM)
#define DELTA XP(U_DELT, U_C_DELT)
#define EPSILON X(U_EPSI)
#define ZETA X(U_ZETA)
#define ETA X(U_ETA)
#define THETA XP(U_THET, U_C_THET)
#define IOTA X(U_IOTA)
#define KAPPA X(U_KAPP)
#define LAMBDA XP(U_LAMB, U_C_LAMB)
#define MUG X(U_MU) // MU conflicts with core variable
#define NU X(U_NU)
#define XI XP(U_XI, U_C_XI)
#define PI XP(U_PI, U_C_PI)
#define RHO X(U_RHO)
#define SIGMA XP(U_SIGM, U_C_SIGM)
#define TAU X(U_TAU)
#define UPSILON XP(U_UPSI, U_C_UPSI)
#define PHI XP(U_PHI, U_C_PHI)
#define CHI X(U_CHI)
#define PSI XP(U_PSI, U_C_PSI)
#define OMEGA XP(U_OMEG, U_C_OMEG)

#define AE XP(U_AE, U_C_AE)
#define OE XP(U_OE, U_C_OE)
#define UE XP(U_UE, U_C_UE)
#define ESZETT X(U_SS)
