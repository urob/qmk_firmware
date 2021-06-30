#pragma once

/* Home row mods settings */

// Default tapping term.
#undef TAPPING_TERM
#define TAPPING_TERM 190
#define TAPPING_TERM_PER_KEY // See bottom of keymap.c

// Prevent rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables auto-repeat on double tap.
#define TAPPING_FORCE_HOLD_PER_KEY

// Apply the modifier on keys that are tapped during a short hold of a modtap.
#define PERMISSIVE_HOLD_PER_KEY

// Ignore same-hand mods.
#define BILATERAL_COMBINATIONS 320

/* Misc settings */

// Combo settings
#define COMBO_TERM 30
#define COMBO_TERM_PER_COMBO
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_VARIABLE_LEN
#define COMBO_ONLY_FROM_LAYER 0

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// Configure unicode for use with WinCompose.
#define UNICODE_SELECTED_MODES UC_WINC
#define UNICODE_KEY_WINC KC_RALT

// Limits the max. amount of layers to 8 to save firmware memory.
#define LAYER_STATE_8BIT
