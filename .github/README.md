# Anne Pro 2 firmware (destngx)

This is my fork of [OpenAnnePro/qmk_firmware](https://github.com/OpenAnnePro/qmk_firmware). It holds my custom keymap for the Anne Pro 2 (C18 revision) and the steps to build and flash it.

The original QMK readme is [`readme.md`](../readme.md) in the repo root.

## Branches

| Branch | What it is |
| --- | --- |
| `destngx` | My keymap on top of `keyboard-annepro2`. This is the default branch. Commit changes here. |
| `keyboard-annepro2` | OpenAnnePro's Anne Pro 2 branch. Leave it untouched so it matches upstream. |
| `master` | Old generic QMK without Anne Pro 2 support. Don't build from it. |

## Files

| Path | Purpose |
| --- | --- |
| `keyboards/annepro2/keymaps/destngx/keymap.c` | Layers and custom keys. The layer diagrams are in the comments. |
| `keyboards/annepro2/keymaps/destngx/config.h` | Timing for home-row mods and Auto Shift. |
| `keyboards/annepro2/keymaps/destngx/rules.mk` | QMK features and compiler flags. |

## One-time setup

1. Install the Arm GNU Toolchain so that `arm-none-eabi-gcc` is on `PATH`. I use version 15.3 from the [Arm installer](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads).
2. Install Rust, which provides `cargo`.
3. Clone this repo with its submodules:

   ```sh
   git clone --recurse-submodules git@github.com:destngx/qmk_firmware.git
   cd qmk_firmware
   git remote add upstream https://github.com/OpenAnnePro/qmk_firmware.git
   ```

4. Clone and build the flasher, [AnnePro2-Tools](https://github.com/OpenAnnePro/AnnePro2-Tools):

   ```sh
   git clone https://github.com/OpenAnnePro/AnnePro2-Tools.git
   cd AnnePro2-Tools && cargo build --release
   ```

   The flasher is `AnnePro2-Tools/target/release/annepro2_tools`.

## Build

Run this from the repo root:

```sh
make annepro2/c18:destngx
```

The build writes `annepro2_c18_destngx.bin` to the repo root.

## Flash

1. Unplug the keyboard.
2. Hold `Esc` and plug it back in. The keyboard starts in IAP (bootloader) mode.
3. Run the flasher:

   ```sh
   path/to/AnnePro2-Tools/target/release/annepro2_tools --boot annepro2_c18_destngx.bin
   ```

   `--boot` restarts the keyboard after flashing. Without it, unplug the keyboard and plug it back in.

The flasher looks for USB device `04d9:8008` and writes to address `0x4000` by default. Both are correct for this keyboard. It only flashes the main MCU, and the LED MCU keeps its existing firmware.

## Change the keymap

1. Edit the files in `keyboards/annepro2/keymaps/destngx/`. Key names are QMK keycodes, such as `KC_A` and `LGUI_T(KC_F)`.
2. Build and flash as above.
3. Commit and push:

   ```sh
   git commit -am "Describe the change"
   git push
   ```

## Pull upstream updates

```sh
git fetch upstream
git rebase upstream/keyboard-annepro2
git submodule update --init --recursive
git push --force-with-lease
```

## Known issues

`rules.mk` sets `-Wno-misleading-indentation`. Without it, GCC 15 stops the build with an error in `lib/chibios-contrib/os/hal/ports/HT32/HT32F523x2/hal_lld.c`. That code is older than GCC 15, which added the warning, and QMK treats warnings as errors.
