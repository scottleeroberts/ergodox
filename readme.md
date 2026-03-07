# Scott's Ergodox EZ Layout

Custom QMK firmware for Ergodox EZ Shine with home-row modifiers and tmux integration.

## Features

- **Home-row modifiers**: Alt, Cmd, Ctrl, Shift on home row (ASDF / JKL;)
- **4 layers**: Base (QWERTY), Symbols, Tmux shortcuts, Numbers/RGB
- **Tmux integration**: Custom macros for window management (Ctrl+Space prefix)
- **RGB lighting**: Full control via Numbers layer
- **Home-row combos**: J+H = Escape, K+J = Backspace, D+F = Tab
- **Chordal Hold + Flow Tap**: Anti-misfire for home-row mods
- **Modern QMK**: Updated for latest QMK firmware (Mar 2026)

## Building and Flashing

### Prerequisites

```bash
# Install Docker
sudo apt install docker.io
sudo systemctl start docker
sudo usermod -aG docker $USER
# Log out and back in for group to take effect

# Install Teensy loader (for flashing)
sudo apt install teensy-loader-cli
```

### Build

```bash
cd ~/scottleeroberts/ergodox
mkdir -p build && cd build

# Clone QMK (first time only)
git clone https://github.com/qmk/qmk_firmware.git
cd qmk_firmware
git submodule update --init --recursive

# Copy keymap files
mkdir -p keyboards/ergodox_ez/keymaps/scottleeroberts
cp ../../keymap.c keyboards/ergodox_ez/keymaps/scottleeroberts/
cp ../../config.h keyboards/ergodox_ez/keymaps/scottleeroberts/
cp ../../rules.mk keyboards/ergodox_ez/keymaps/scottleeroberts/

# Build firmware (use ergodox_ez/shine for Shine variant, ergodox_ez/base for Base)
docker run --rm -v $(pwd):/qmk_firmware -w /qmk_firmware ghcr.io/qmk/qmk_cli \
  make ergodox_ez/shine:scottleeroberts

# Copy hex out
cp ergodox_ez_shine_scottleeroberts.hex ../..
cd ../..
```

### Flash

The Ergodox EZ uses the Teensy/Halfkay bootloader. Press the small RESET button on the back of the keyboard (or hit QK_BOOT on the Numbers layer), then:

```bash
teensy_loader_cli -v -mmcu=atmega32u4 -w ergodox_ez_shine_scottleeroberts.hex
```

Or use QMK's built-in flash:
```bash
# From build/qmk_firmware directory
make ergodox_ez/shine:scottleeroberts:flash
```

## Layer Guide

### BASE (Layer 0) - Default QWERTY

```
,--------------------------------------------------.           ,--------------------------------------------------.
| ESC  |  1  |  2  |  3  |  4  |  5  |     |           |     |  6  |  7  |  8  |  9  |  0  | BkSp |
|------+-----+-----+-----+-----+-----------|           |-----+-----+-----+-----+-----+-----+------|
|  `   |  Q  |  W  |  E  |  R  |  T  |     |           |     |  Y  |  U  |  I  |  O  |  P  |  -   |
|------+-----+-----+-----+-----+-----|     |           |     |-----+-----+-----+-----+-----+------|
| Ctrl |  A  |  S  |  D  |  F  |  G  |-----|           |-----|  H  |  J  |  K  |  L  |  ;  |  '   |
|      | Alt | Cmd | Tmx | Ctl | Sft |     |           |     | Sft | Ctl |     | Cmd | Alt |      |
|------+-----+-----+-----+-----+-----|     |           |     |-----+-----+-----+-----+-----+------|
| Sft  |  Z  |  X  |  C  |  V  |  B  |     |           |     |  N  |  M  |  ,  |  .  |  /  |  =   |
`------+-----+-----+-----+-----+-----------'           `-----------+-----+-----+-----+-----+------'
  |    |     |     | Cmd | Num |                                   | Sym | Tab |     |     |     |
  `--------------------------------'                               `--------------------------------'
                                     ,-----------.       ,-----------.
                                     |     |     |       |     |     |
                              ,------+-----+-----|       |-----+-----+------.
                              |      |     |     |       |     |     |      |
                              | Entr |     |-----|       |-----|  Tab| Space|
                              |      |     |     |       |     |     |      |
                              `------------------'       `------------------'
```

### SYMB (Layer 1) - Symbols & Navigation

- **Top row:** `~ ! @ # $ % ^ & * ( ) |`
- **Home row left:** `[ ] { }`
- **Home row right:** Arrow keys + `? \`
- **Bottom row:** `( )`

### TMUX (Layer 2) - Terminal Multiplexer

Activated by holding D key. All macros send Ctrl+Space prefix:

| Key | Action | Sends |
|-----|--------|-------|
| U | Copy mode | Ctrl+Space [ |
| I | Split horizontal | Ctrl+Space " |
| O | Split vertical | Ctrl+Space % |
| J | Window 1 | Ctrl+Space 1 |
| K | Window 2 | Ctrl+Space 2 |
| L | Window 3 | Ctrl+Space 3 |
| ; | Window 4 | Ctrl+Space 4 |
| ' | Window 5 | Ctrl+Space 5 |
| N | New window | Ctrl+Space c |

### NUMBERS (Layer 3) - Numpad & RGB

**Right side - Number pad:**
```
    7  8  9    Mute
    4  5  6    Vol+
    1  2  3    Vol-
 0
```

**Left side - RGB controls:**
- **Row 2:** Plain mode (static), Breathing mode
- **Row 3:** Toggle, Next mode, Hue+, Speed+, Brightness+
- **Row 4:** Prev mode, Hue-, Speed-, Brightness-

**Top left:** Reset/Bootloader (QK_BOOT)

## Configuration Details

### Home-Row Modifiers

- **Tapping term:** 170ms
- **Chordal Hold:** Same-hand tap-hold + next key resolves as tap (prevents misfires)
- **Flow Tap:** Keys pressed within 100ms of each other always tap (fast typing protection)
- **Permissive Hold:** Mod activates immediately when another key is tapped during hold

### Combos

| Combo | Action |
|-------|--------|
| J + H | Escape |
| K + J | Backspace |
| D + F | Tab |

### Chordal Hold Exceptions

| Combo | Action |
|-------|--------|
| F + W | Ctrl+W (same-hand, allowed) |
| L + Y | GUI+Y (same-hand, allowed) |

## Files

| File | Purpose |
|------|---------|
| `keymap.c` | Main keymap and macro definitions |
| `config.h` | Keyboard configuration settings |
| `rules.mk` | Build rules and feature enables |

## Variants

| Build Target | Model |
|-------------|-------|
| `ergodox_ez/shine` | Ergodox EZ Shine (RGB underglow) |
| `ergodox_ez/base` | Ergodox EZ Base (no RGB) |
| `ergodox_ez/glow` | Ergodox EZ Glow (per-key RGB) |

## License

GPL v2 (inherited from QMK Firmware)
