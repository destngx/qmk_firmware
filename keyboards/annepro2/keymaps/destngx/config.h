// Obins stock firmware has something similar to this already enabled, but disabled by default in QMK
// #define PERMISSIVE_HOLD

// Hold time for tap dance and mod-tap keys (250ms - more forgiving for fast typing)
#define TAPPING_TERM 250
// Add: disables tap-then-hold repeat so j-hold = GUI, not jjjj...
// (valid in OpenAnnePro ~2022 QMK base)
#define TAPPING_FORCE_HOLD

// Ignore mod tap interrupt - prevents mods from triggering when typing fast
#define IGNORE_MOD_TAP_INTERRUPT

// Auto Shift - hold key longer for shifted version (500ms)
#define AUTO_SHIFT_TIMEOUT 500
#define AUTO_SHIFT_NO_SETUP
