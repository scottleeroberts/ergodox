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

**Complete instructions: [MANUAL_BUILD_FLASH.md](MANUAL_BUILD_FLASH.md)**

Built against QMK firmware [`9e8199c`](https://github.com/qmk/qmk_firmware/commit/9e8199c41189a2eb6243600bf3f96f136650820b).

**Quick reference** (if you've already done the setup):
```bash
# Build (from build/qmk_firmware directory)
docker run --rm -v $(pwd):/qmk_firmware -w /qmk_firmware ghcr.io/qmk/qmk_cli \
  make ergodox_ez/shine:scottleeroberts

# Flash (press RESET button or hold Numbers + ESC first)
teensy_loader_cli -v -mmcu=atmega32u4 -w ergodox_ez_shine_scottleeroberts.hex
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
| `MANUAL_BUILD_FLASH.md` | Complete build and flash instructions |

## Variants

| Build Target | Model |
|-------------|-------|
| `ergodox_ez/shine` | Ergodox EZ Shine (RGB underglow) |
| `ergodox_ez/base` | Ergodox EZ Base (no RGB) |
| `ergodox_ez/glow` | Ergodox EZ Glow (per-key RGB) |

## License

GPL v2 (inherited from QMK Firmware)
