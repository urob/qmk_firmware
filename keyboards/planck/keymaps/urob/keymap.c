#include QMK_KEYBOARD_H

#include "keymap.h"
#include "oneshot.h"
#include "unicode.c"

// To make combo dictionary work (see combos.def for definitinos)
#if defined(COMBO_ENABLE)
#    include "g/keymap_combo.h"
#endif



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,      TG(_NUM),XXXXXXX,   KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
    HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,      DF(BASE),DF(_CAL),  KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O, 
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,      XXXXXXX, XXXXXXX,   KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SCLN,
    UNDO,    XXXXXXX, ESC_SYS, SPC_NAV, TAB_GRK,   XXXXXXX, XXXXXXX,   ENT_GRK, REP_NUM, BS_FN,   KC_WH_D, KC_WH_U
),

[_CAL] = LAYOUT_planck_grid( /* no HRMs + OSM shift on base, other mods on layers as OSMs using Callum's code */
    _______, _______, _______, _______, _______,   _______, _______,   _______, _______, _______, _______, _______,
    KC_A   , KC_R   , KC_S   , KC_T   , _______,   _______, _______,   _______, KC_N   , KC_E   , KC_I   , KC_O   ,
    _______, _______, _______, _______, _______,   _______, _______,   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,   _______, _______,   _______, _______, _______, _______, _______
),

[_GRK] = LAYOUT_planck_grid(
    _______, OMEGA,   PHI,     PI,      BETA,      _______, _______,   EQM,     LAMBDA,  UPSILON, PSI,     ESZETT,
    ALPHA,   RHO,     SIGMA,   TAU,     GAMMA,     _______, _______,   MUG,     NU,      EPSILON, IOTA,    _______,
    ZETA,    XI,      CHI,     DELTA,   THETA,     _______, _______,   KAPPA,   ETA,     AE,      OE,      UE,
    _______, _______, _______, _______, KC_LSFT,   _______, _______,   KC_RSFT, _______, _______, _______, _______
),

[_NAV] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______,   _______, _______,   KC_INS , KC_HOME, KC_UP,   KC_END,  KC_PGUP,
    OS_GUI , OS_ALT , OS_CTRL, OS_SHFT, _______,   _______, _______,   KC_DEL , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
    _______, _______, _______, _______, _______,   _______, _______,   _______, PASTE  , COPY   , CUT    , _______,
    _______, _______, _______, _______, _______,   _______, _______,   KC_ENT , XXXXXXX, KC_BSPC, _______, _______
),

[_SYS] = LAYOUT_planck_grid(
    ADJUST , _______, _______, _______, _______,   _______, _______,   _______, KC_MPRV, KC_VOLU, KC_MNXT, KC_SLEP,
    OS_GUI , OS_ALT , OS_CTRL, OS_SHFT, _______,   _______, _______,   _______, DSK_LT,  KC_VOLD, DSK_RT,  _______,
    _______, _______, _______, _______, _______,   _______, _______,   _______, FZ_L1 ,  FZ_L2  , FZ_L3 ,  FZ_LE  ,
    _______, _______, _______, _______, _______,   _______, _______,   KC_MUTE, KC_MPLY, _______, _______, _______
),

[_NUM] = LAYOUT_planck_grid(
    KC_ESC,  KC_7,    KC_8,    KC_9,    KC_ASTR,   _______, _______,   _______, _______, _______, _______, _______,
    KC_ENT,  KC_4,    KC_5,    KC_6,    KC_PLUS,   _______, _______,   _______, OS_SHFT, OS_CTRL, OS_ALT , OS_GUI,
    KC_TAB,  KC_1,    KC_2,    KC_3,    KC_SLSH,   _______, _______,   _______, _______, _______, _______, _______,
    _______, _______, KC_DOT,  KC_0,    KC_MINS,   _______, _______,   _______, _______, _______, _______, _______
),

[_FN] = LAYOUT_planck_grid(
    KC_F12 , KC_F7  , KC_F8  , KC_F9  , _______,   _______, _______,   _______, _______, _______, _______, _______,
    KC_F11 , KC_F4  , KC_F5  , KC_F6  , _______,   _______, _______,   _______, OS_SHFT, OS_CTRL, OS_ALT , OS_GUI,
    KC_F10 , KC_F1  , KC_F2  , KC_F3  , _______,   _______, _______,   _______, _______, _______, _______, _______,
    _______, _______, KC_ESC , KC_SPC , KC_TAB ,   _______, _______,   _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI,   RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______,
    _______, AU_ON,   AU_OFF,  _______, _______, _______,   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______
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


// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
void process_caps_word(uint16_t keycode, const keyrecord_t *record) {
    // Update caps word state
    if (caps_word_on) {
        switch (keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                // Earlier return if this has not been considered tapped yet
                if (record->tap.count == 0) { return; }
                // Get the base tapping keycode of a mod- or layer-tap key
                // keycode = keycode & 0xFF;
                keycode = GET_TAP_KC(keycode);
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


static uint16_t non_combo_input_timer = 0;
uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;
void process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
    if ((keycode != REP_NUM) || (record->tap.count == 0)) { // REP_NUM is a LT, so hold should not trigger repeat
        last_modifier = oneshot_mod_state > mod_state ? oneshot_mod_state : mod_state;
        switch (keycode) {
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                if (record->event.pressed) {
                    last_keycode = GET_TAP_KC(keycode);
                }
                break;
            default:
                if (record->event.pressed) {
                    last_keycode = keycode;
                }
                break;
        }
    } else { /* repeat action defined here */
        // first check whether last keycode was shift or enter, or we paused for a while. It so morth to OS shift
         if ((last_keycode == KC_SPC) || (last_keycode == KC_ENT) || (last_keycode == KC_BSPC) || (timer_elapsed(non_combo_input_timer) > 400)) {
            if (record->event.pressed) {
               add_oneshot_mods(MOD_BIT(KC_LSFT));
            }
        // next check whether last key is a shifted alpha, if so repeat the HRM alpha used to trigger the shift
        } else if ((last_modifier == MOD_BIT(KC_LSFT)) && (last_keycode >= KC_A) && (last_keycode <= KC_Z)) {
            if (record->event.pressed) {
               register_code(KC_T);
            } else {
               unregister_code(KC_T);
            }
        } else if ((last_modifier == MOD_BIT(KC_RSFT)) && (last_keycode >= KC_A) && (last_keycode <= KC_Z)) {
            if (record->event.pressed) {
               register_code(KC_N);
            } else {
               unregister_code(KC_N);
            }
        } else { // process repeat key as usual
            if (record->event.pressed) {
                register_mods(last_modifier);
                register_code16(last_keycode);
            } else {
                unregister_code16(last_keycode);
                unregister_mods(last_modifier);
            }
        }
    }
}


// the time of the last input, used to tweak the timing of combos depending on if I'm currently
// in active typing flow (should practically remove any chance of mistriggering combos)
uint16_t get_combo_term(uint16_t index, combo_t *combo) {

  if ((index >= QW_MTAB) && (index <= COMDOT_RBRC)) { // horizontal alpha combos
    return timer_elapsed(non_combo_input_timer) > 300 ? 20 : 5;
  } 

  if (index >= WR_AT) return 40; // vertical combos

  return COMBO_TERM;
  
}

// requires combo_should trigger branch
bool combo_should_trigger(uint16_t combo_index, combo_t *combo) {
  bool is_base = (layer_state_is(BASE) || layer_state_is(_CAL));
  return is_base;
  }


bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case SPC_NAV:
    case SFT_NUM:
    case REP_NUM:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case SPC_NAV:
    case SFT_NUM:
    case REP_NUM:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_GUI:
        return true;
    default:
        return false;
    }
}




oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process caps word for updates
    process_caps_word(keycode, record);

    // Process repeat key
    process_repeat_key(keycode, record);
    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();

    // Input timer to adjust combo term
    non_combo_input_timer = timer_read();

    // callum mods
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_gui_state, KC_LGUI, OS_GUI,
        keycode, record
    );


    switch (keycode) {

        case CAPS_WORD:
            // Toggle `caps_word_on`
            if (record->event.pressed) {
                if (caps_word_on) {
                    caps_word_disable();
                    return false;
                } else {
                    caps_word_enable();
                    return false;
                }
            }
            break;

        case SFT_NUM:
            if (record->tap.count > 0) {
              // update_oneshot(
              //     &os_shft_state, KC_LSFT, OS_SHFT,
              //     OS_SHFT, record
              // );
              add_oneshot_mods(MOD_BIT(KC_LSFT)); // prevent more than first alpha getting capitalized on rolls
              return false;
            } else {
              return true;
            }

        case KC_BSPC:
        case BS_FN:
            if ((record->tap.count > 0) || (keycode != BS_FN)) { // do not morph BS_FN when hold
            static bool delkey_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    // In case only one shift is held
                    // see https://stackoverflow.com/questions/1596668/logical-xor-operator-in-c
                    // This also means that in case of holding both shifts and pressing KC_BSPC,
                    // Shift+Delete is sent (useful in Firefox) since the shift modifiers aren't deleted.
                    if (!(mod_state & MOD_BIT(KC_LSHIFT)) != !(mod_state & MOD_BIT(KC_RSHIFT))) {
                        del_mods(MOD_MASK_SHIFT);
                    }
                    register_code(KC_DEL);
                    delkey_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            return true;
            }

    }
    return true; // Process all other keycodes normally
}

// Per key auto-repeat settings
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BS_NUM:
        case REP_NUM:
        case DEL_FN:
        case BS_FN:
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
        case HOME_S:
        case HOME_T:
        case HOME_N:
        case HOME_E:
            return TAPPING_TERM - 10; // lower tapping term for shift
        case HOME_A:
        case HOME_R:
        case HOME_I:
        case HOME_O:
            return TAPPING_TERM + 70; // raise tapping term for Alt and Gui to prevent
                                      // flashing mods until bilateral combinations is fixed
        default:
            return TAPPING_TERM;
    }
};

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    // If you want all combos to be tap-only, just uncomment the next line
    // return true;

    // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, 
    // to be tap-only, this is for you:
    uint16_t key;
    uint8_t idx = 0;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP...QK_MOD_TAP_MAX:
            case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
            case QK_MOMENTARY...QK_MOMENTARY_MAX:
                return true;
        }
        idx += 1;
    }
    return false;

}

// bilateral combinations does not play well with nonstandard key matrices
// deactivate it for thumb keys as a workaround
bool get_bilateral_combinations(keypos_t *hold, keypos_t *tap) {
  bool same     = (hold->row < MATRIX_ROWS / 2) == (tap->row < MATRIX_ROWS / 2);
  bool top_rows = same && (tap->row != 3) && (tap->row != 7); // deactivate BL for thumb keys
  return top_rows;
}
