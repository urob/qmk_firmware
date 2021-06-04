#include QMK_KEYBOARD_H
#include "keymap.h"
#include "action_tapping.h" // necessary for action_tapping_process
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif



enum combo_events {
  ZX_CUT,
  XC_COPY,
  CD_PASTE,
  PREV_WIN,
  SYM_BSLS,
  // This must be the last item in the enum.
  // This is used to automatically update the combo count.
  COMBO_LENGTH
};
// uint16_t COMBO_COUNT = COMBO_LENGTH;

const uint16_t PROGMEM cut_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM alttab_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM symb_bsls_combo[] = {HOME_S, HOME_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [ZX_CUT] = COMBO_ACTION(cut_combo),
  [XC_COPY] = COMBO_ACTION(copy_combo),
  [CD_PASTE] = COMBO_ACTION(paste_combo),
  [PREV_WIN] = COMBO_ACTION(alttab_combo),
  [SYM_BSLS] = COMBO_ACTION(symb_bsls_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case ZX_CUT:
      if (pressed) {
        tap_code16(CUT);
      }
      break;
    case XC_COPY:
      if (pressed) {
        tap_code16(COPY);
      }
      break;
    case CD_PASTE:
      if (pressed) {
        tap_code16(PASTE);
      }
      break;
    case PREV_WIN:
      if (pressed) {
        tap_code16(LALT(KC_TAB));
      }
      break;
    case SYM_BSLS:
      if (pressed) {
        tap_code16(KC_BSLS);
      }
      break;
  }
}
