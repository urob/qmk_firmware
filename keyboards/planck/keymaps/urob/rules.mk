UNICODEMAP_ENABLE = yes
COMBO_ENABLE = yes

# Enable link time optimization and turn of unused features
LTO_ENABLE = yes # yields weird warning during compilation due to
                 # GCC 10 bug. Can be ignored, see here for details:
				 # http://www.forum.chibios.org/viewtopic.php?t=5696&start=23
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
TERMINAL_ENABLE = no
TAB_DANCE_ENABLE = no
AUTO_SHIFT_ENABLE = no
SWAP_HANDS_ENABLE = no
MIDI_ENABLE = no
AUDIO_ENABLE = no
STENO_ENABLE = no
ENCODER_ENABLE = no
RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no

# Load the necessary external C files if and only if
# the associated config option has been enabled
ifeq ($(strip $(COMBO_ENABLE)), yes)
	VPATH += keyboards/gboards
endif

# SRC += unicode.c
SRC += oneshot.c
