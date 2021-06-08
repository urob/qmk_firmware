#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

#endif

#define MIDI_BASIC

// Home row mods settings //

// Configure the default tapping term.
#undef TAPPING_TERM
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY // See bottom of keymap.c

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD_PER_KEY

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD_PER_KEY

// Ignore same-hand mods.
#define BILATERAL_COMBINATIONS 350

// Auto Shift
// #define NO_AUTO_SHIFT_ALPHA
// #define NO_AUTO_SHIFT_NUMERIC
// #define AUTO_SHIFT_TIMEOUT TAPPING_TERM
// #define AUTO_SHIFT_NO_SETUP

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// Combos
#define COMBO_TERM 25
#define COMBO_MUST_TAP_PER_COMBO
// #define COMBO_STRICT_TIMER
#define COMBO_VARIABLE_LEN

// Configure unicode for use with WinCompose. 
#define UNICODE_SELECTED_MODES UC_WINC
#define UNICODE_KEY_WINC KC_RALT

// Limits the max. amount of layers to 8 to save firmware memory.
#define LAYER_STATE_8BIT
