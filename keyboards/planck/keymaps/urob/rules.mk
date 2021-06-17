UNICODEMAP_ENABLE = yes
COMBO_ENABLE = yes

# AUTO_SHIFT_ENABLE = yes
CONSOLE_ENABLE = yes
COMMAND_ENABLE = no

# Load the necessary external C files if and only if
# the associated config option has been enabled
ifeq ($(strip $(COMBO_ENABLE)), yes)
	VPATH += keyboards/gboards
endif
