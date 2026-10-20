# destngx keymap for Anne Pro 2 (C18)

This keymap uses home-row mods, an FN1 layer for function, arrow, and media keys, and an FN2 layer with a numpad and Alt+number macros. The layer diagrams are in the comments in `keymap.c`.

## Requirements

- The `arm-none-eabi-gcc` toolchain on `PATH`.
- [AnnePro2-Tools](https://github.com/OpenAnnePro/AnnePro2-Tools), built with `cargo build --release`.
- This repo cloned with submodules: `git clone --recurse-submodules`.

## Build

Run this from the repo root:

```sh
make annepro2/c18:destngx
```

The build writes `annepro2_c18_destngx.bin` to the repo root.

## Flash

1. Unplug the keyboard.
2. Hold `Esc` and plug it back in. The keyboard starts in IAP (bootloader) mode.
3. Run the flasher with the `.bin`:

   ```sh
   path/to/AnnePro2-Tools/target/release/annepro2_tools annepro2_c18_destngx.bin
   ```

4. Unplug the keyboard and plug it back in.

This only flashes the main MCU. The LED MCU keeps its existing firmware.

## Changing the keymap

- Edit the layers in `keymap.c`. Key names are QMK keycodes, such as `KC_A` and `LGUI_T(KC_F)`.
- Tune timing in `config.h`. `TAPPING_TERM` controls how long you hold a home-row key before it acts as a modifier. `AUTO_SHIFT_TIMEOUT` controls how long you hold a key before it sends the shifted character.
- `keyboard_post_init_user` picks the LED profile used at startup.
