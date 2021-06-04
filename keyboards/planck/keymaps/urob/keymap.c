#include QMK_KEYBOARD_H
#include "muse.h"

// All custom keycodes and aliases can be found in keymap.h
#include "keymap.h"
#include "combos.c"

// Unicode definitions (see keymap.h for key definitions)
const uint32_t PROGMEM unicode_map[] = {
    /* Greek letters (capitalized) */
    [U_C_GAMM] = 0x0393,
    [U_C_DELT] = 0x0394,
    [U_C_THET] = 0x0398,
    [U_C_LAMB] = 0x039B,
    [U_C_XI]   = 0x039E,
    [U_C_PI]   = 0x03A0,
    [U_C_SIGM] = 0x03A3,
    [U_C_UPSI] = 0x03A5,
    [U_C_PHI]  = 0x03A6,
    [U_C_PSI]  = 0x03A8,
    [U_C_OMEG] = 0x03A9,
    /* Greek letters */
    [U_ALPH] = 0x03B1,
    [U_BETA] = 0x03B2,  
    [U_GAMM] = 0x03B3, 
    [U_DELT] = 0x03B4, 
    [U_EPSI] = 0x03F5, // varepsilon = 03B5 
    [U_ZETA] = 0x03B6, 
    [U_ETA]  = 0x03B7, 
    [U_THET] = 0x03B8, 
    [U_IOTA] = 0x03B9, 
    [U_KAPP] = 0x03BA, 
    [U_LAMB] = 0x03BB, 
    [U_MU]   = 0x03BC, 
    [U_NU]   = 0x03BD, 
    [U_XI]   = 0x03BE, 
    [U_PI]   = 0x03C0, 
    [U_RHO]  = 0x03C1, 
    [U_SIGM] = 0x03C3, 
    [U_TAU]  = 0x03C4, 
    [U_UPSI] = 0x03C5, 
    [U_PHI]  = 0x03D5, // varphi = 03C6 
    [U_CHI]  = 0x03C7, 
    [U_PSI]  = 0x03C8, 
    [U_OMEG] = 0x03C9,
    /* German umlauts */
    [U_AE] = 0x00E4,
    [U_OE] = 0x00F6,
    [U_UE] = 0x00FC,
    [U_C_AE] = 0x00C4,
    [U_C_OE] = 0x00D6,
    [U_C_UE] = 0x00DC,
    [U_SS] = 0x00DF,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_planck_grid(
    KC_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,      KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_EQL ,
    KC_BSLS, HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,      KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,  KC_MINS,
    CWD_GRK, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, COL_GRK,
    UNDO,    DF(_NUM),KC_LALT, ESC_SYS, SPC_NAV, TAB_SYM,   ENT_SFT, BS_NUM,  DEL_FN,  KC_LGUI, KC_WH_D, KC_WH_U
),

[_GRK] = LAYOUT_planck_grid(
    _______, _______, OMEGA,   PHI,     PI,      BETA,      EQM,     LAMBDA,  UPSILON, PSI,     ESZETT,  _______,
    _______, ALPHA,   RHO,     SIGMA,   TAU,     GAMMA,     MUG,     NU,      EPSILON, IOTA,    _______, _______,
    _______, ZETA,    XI,      CHI,     DELTA,   THETA,     KAPPA,   ETA,     AE,      OE,      UE,      _______,
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______
),

[_NAV] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______,   KC_INS , KC_HOME, KC_PGUP, KC_PGDN, KC_END , _______,
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,   _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT,_______,
    _______, _______, _______, _______, _______, _______,   _______, PASTE  , COPY   , CUT    , _______, _______,
    _______, _______, _______, _______, _______, _______,   KC_ENT , KC_BSPC, KC_DEL , _______, _______, _______
),

[_SYM] = LAYOUT_planck_grid(
    KC_TILD, _______, _______, _______, _______, _______,   KC_AT  , KC_LCBR, KC_RCBR, KC_PERC, KC_ASTR, KC_PLUS,
    KC_PIPE, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,   KC_DLR , KC_LPRN, KC_RPRN, KC_AMPR, KC_CIRC, KC_UNDS,
    _______, _______, _______, _______, _______, _______,   KC_HASH, KC_LBRC, KC_RBRC, KC_EXLM, KC_QUES, KC_COLN,
    _______, _______, _______, _______, _______, _______,   KC_ENT , KC_BSPC, KC_DEL , _______, _______, _______
),

[_SYS] = LAYOUT_planck_grid(
    ADJUST , _______, _______, _______, _______, _______,   _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_SLEP,
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,   _______, DSK_LT , WIN_LT , WIN_RT , DSK_RT , _______,
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,   KC_MUTE, KC_MPLY, _______, _______, _______, _______
),

[_NUM] = LAYOUT_planck_grid(
    _______, KC_ASTR, KC_7, KC_8, KC_9, KC_PLUS,   _______, _______, _______, _______, _______, _______,
    _______, KC_SLSH, KC_4, KC_5, KC_6, KC_MINS,   _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
    _______, KC_ESC , KC_1, KC_2, KC_3, KC_TAB ,   _______, _______, _______, _______, _______, _______,
    _______, DF(0)  , _______, KC_DOT , KC_0   , KC_ENT ,   _______, _______, _______, _______, _______, _______
),

[_FN] = LAYOUT_planck_grid(
    _______, KC_F12 , KC_F   , KC_F8  , KC_F9  , _______,   _______, _______, _______, _______, _______, _______,
    _______, KC_F11 , KC_F4  , KC_F5  , KC_F6  , _______,   _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
    _______, KC_F10 , KC_F1  , KC_F2  , KC_F3  , _______,   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_ESC , KC_SPC , KC_TAB ,   _______, _______, _______, _______, _______, _______
),


/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI,   RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, ADJUST ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM,   AG_SWAP, _______, _______,  _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,     MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,   _______, _______, _______,  _______, _______, _______
)

};


// CAPS_WORD: A "smart" Caps Lock key that only capitalizes the next identifier you type
// and then toggles off Caps Lock automatically when you're done.
void caps_word_enable(void) {
    caps_word_on = true;
    if (!(host_keyboard_led_state().caps_lock)) {
        tap_code(KC_CAPS);
    }
}

void caps_word_disable(void) {
    caps_word_on = false;
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

void process_caps_word(uint16_t keycode, const keyrecord_t *record) {
    // Update caps word state
    if (caps_word_on) {
        switch (keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                // Earlier return if this has not been considered tapped yet
                if (record->tap.count == 0) { return; }
                // Get the base tapping keycode of a mod- or layer-tap key
                keycode = keycode & 0xFF;
                break;
            default:
                break;
        }

        switch (keycode) {
            // Keycodes to shift
            case KC_A ... KC_Z:
                if (record->event.pressed) {
                    caps_word_enable();
                }
            // Keycodes that enable caps word but shouldn't get shifted
            case KC_MINS:
            case KC_BSPC:
            case KC_UNDS:
            case KC_PIPE:
            case CAPS_WORD:
                // If chording mods, disable caps word
                if (record->event.pressed && (get_mods() != MOD_LSFT) && (get_mods() != 0)) {
                    caps_word_disable();
                }
                break;
            default:
                // Any other keycode should automatically disable caps
                if (record->event.pressed) {
                    caps_word_disable();
                }
                break;
        }
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process caps word for updates
    process_caps_word(keycode, record);

    switch (keycode) {

        case CWD_GRK:
            // Toggle `caps_word_on`
            if (record->tap.count > 0) {
              if (record->event.pressed) {
                  if (caps_word_on) {
                      caps_word_disable();
                      return false;
                  } else {
                      caps_word_enable();
                      return false;
                  }
              }
            }
            break;

//        case HOME_TAU:
//          // Mod tab for tau
//          if (record->tap.count > 0) {
//              if (record->event.pressed) {
//                // the 16 bit version of the `tap_code` function is used here
//                // because KC_HASH is a non-basic keycode.
//                tap_code16(TAU);
//              }
//              return false;
//            }
//          break;

  //      default:
  //          return true;  // Process all other keycodes normally
    }
    return true; // Process all other keycodes normally
}


// Per key auto-repeat settings
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BS_NUM:
            return false;  /* allow auto-repeat for backspace */
        default:
            return true;   /* disable per default */
    }
}

// Per key permissive hold settings
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
        case HOME_R:
        case HOME_I:
        case HOME_O:
            return false;  /* disable permissive hold for Alt and Gui */
        default:
            return true;   /* enable per default */
    }
}


// Per key tapping term settings
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* use lower tapping term for thumb mods */
        case ENT_SFT:
        case BS_NUM:
        case ESC_SYS:
        case DEL_FN:
        case SPC_NAV:
        case TAB_SYM:
            return TAPPING_TERM - 20;
        case HOME_A:
        case HOME_R:
        case HOME_I:
        case HOME_O:
            return TAPPING_TERM + 80;
        default:
            return TAPPING_TERM;
    }
};
