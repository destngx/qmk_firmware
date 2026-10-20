# destngx keymap for Anne Pro 2 (C18)

This keymap uses home-row mods, an FN1 layer for function, arrow, and media keys, and an FN2 layer with a numpad and Alt+number macros. The layer diagrams are in the comments in `keymap.c`.

For setup, build, and flash steps, see the [guide](../../../../.github/README.md).

## Changing the keymap

- Edit the layers in `keymap.c`. Key names are QMK keycodes, such as `KC_A` and `LGUI_T(KC_F)`.
- Tune timing in `config.h`. `TAPPING_TERM` controls how long you hold a home-row key before it acts as a modifier. `AUTO_SHIFT_TIMEOUT` controls how long you hold a key before it sends the shifted character.
- `keyboard_post_init_user` picks the LED profile used at startup.
