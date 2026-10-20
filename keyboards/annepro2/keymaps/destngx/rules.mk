# Anne Pro 2 - destngx keymap
TAP_DANCE_ENABLE = no
AUTO_SHIFT_ENABLE = yes

# GCC 15 flags an unbraced wait loop in chibios-contrib hal_lld.c as an error
EXTRAFLAGS += -Wno-misleading-indentation
