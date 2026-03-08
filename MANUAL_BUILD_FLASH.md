# Manual Build & Flash Instructions for Linux

**No scripts, full control, no surprises.**

Compatible with Ubuntu, Debian, Arch, Manjaro, and other Linux distributions.

## Overview

This guide uses:
- **Docker** - to build the firmware (uses QMK's official pre-built image, no Dockerfile needed)
- **teensy_loader_cli** - to flash the firmware to your keyboard

You don't need to install Python, QMK CLI, or the full AVR toolchain. Docker handles the build environment, and teensy_loader_cli is a single package install.

---

## Prerequisites

### Ubuntu / Debian

```bash
# Install Docker (if not already installed)
sudo apt update
sudo apt install docker.io
sudo systemctl start docker
sudo systemctl enable docker

# Add yourself to docker group (to run without sudo)
sudo usermod -aG docker $USER
# Log out and back in for group to take effect

# Install flashing tool
sudo apt install teensy-loader-cli
```

### Arch / Manjaro

```bash
# Install Docker (if not already installed)
sudo pacman -S docker
sudo systemctl start docker
sudo systemctl enable docker

# Add yourself to docker group (to run without sudo)
sudo usermod -aG docker $USER
# Log out and back in for group to take effect

# Install flashing tool
sudo pacman -S teensy-loader-cli
```

---

## Part 1: Build Firmware

### Step 1: Check you're in the right directory

```bash
cd ~/scottleeroberts/ergodox
ls -la keymap.c config.h rules.mk
# All three files should exist
```

### Step 2: Create build directory

```bash
mkdir -p build
cd build
```

### Step 3: Clone QMK firmware (first time only)

```bash
# Pin to the exact QMK version this firmware was tested against
QMK_SHA=9e8199c41189a2eb6243600bf3f96f136650820b

# If you haven't cloned QMK yet:
git clone https://github.com/qmk/qmk_firmware.git
cd qmk_firmware
git checkout $QMK_SHA
cd ..

# If you already have it and want to re-pin:
cd qmk_firmware
git fetch origin
git checkout $QMK_SHA
cd ..
```

**This takes 2-5 minutes depending on your internet.**

### Step 4: Initialize submodules (first time only)

```bash
cd qmk_firmware
git submodule update --init --recursive

# This takes 5-10 minutes and downloads ~2GB
# You'll see progress messages
```

### Step 5: Copy your keymap files

```bash
# Create keymap directory
mkdir -p keyboards/ergodox_ez/keymaps/scottleeroberts

# Copy your files
cp ../../keymap.c keyboards/ergodox_ez/keymaps/scottleeroberts/
cp ../../config.h keyboards/ergodox_ez/keymaps/scottleeroberts/
cp ../../rules.mk keyboards/ergodox_ez/keymaps/scottleeroberts/

# Verify they're there
ls -la keyboards/ergodox_ez/keymaps/scottleeroberts/
```

### Step 6: Build with Docker

```bash
# Make sure you're in build/qmk_firmware directory
pwd
# Should show: .../ergodox/build/qmk_firmware

# Run the build (use ergodox_ez/shine for Shine, ergodox_ez/base for Base)
docker run --rm \
  -v $(pwd):/qmk_firmware \
  -w /qmk_firmware \
  ghcr.io/qmk/qmk_cli \
  make ergodox_ez/shine:scottleeroberts
```

**This takes 2-3 minutes.** You'll see compilation messages scrolling by.

Success looks like:
```
Linking: .build/ergodox_ez_shine_scottleeroberts.elf
Creating load file for flashing: .build/ergodox_ez_shine_scottleeroberts.hex
 * The firmware size is fine - 23444/32256 (72%, 8812 bytes free)
```

### Step 7: Copy firmware out

```bash
# Copy the .hex file to parent directory
cp ergodox_ez_shine_scottleeroberts.hex ../..

# Go back to main directory
cd ../..

# Verify it's there
ls -lh ergodox_ez_shine_scottleeroberts.hex
# Should be ~65KB
```

**Build complete!** You now have: `ergodox_ez_shine_scottleeroberts.hex`

---

## Part 2: Flash Firmware

The Ergodox EZ has a single MCU (Teensy 2.0) on the right half. The left half is an I/O expander connected via I2C through the TRRS cable. **One flash updates the entire keyboard.**

### Step 1: Connect the keyboard

1. Plug in the Ergodox EZ via USB (right half has the USB port)
2. Both halves should be connected via TRRS cable

### Step 2: Put keyboard in bootloader mode

**Option A: Physical RESET button**
1. Find the small RESET pinhole button on the right half (near the TRRS jack)
2. Press it with a paperclip or SIM tool

**Option B: Keyboard shortcut (if firmware is already flashed)**
1. Hold the Numbers layer key (left thumb)
2. Press the top-left key (ESC position) which is mapped to QK_BOOT

### Step 3: Check bootloader is detected

```bash
lsusb | grep -i teensy

# Should see something like: "Van Ooijen Technische Informatica Teensy Halfkay Bootloader"
# If not, press RESET again
```

### Step 4: Flash

```bash
teensy_loader_cli -v -mmcu=atmega32u4 -w ergodox_ez_shine_scottleeroberts.hex
```

**This takes a few seconds.** The keyboard automatically resets and runs the new firmware.

### Step 5: Test

1. Keyboard should automatically reconnect after flash
2. Type some keys - they should work
3. If not working, unplug and replug USB

---

## Done!

The keyboard is now flashed and ready to use.

---

## Troubleshooting

### "No device present" or teensy_loader_cli hangs

**Cause:** Keyboard is not in bootloader mode.

**Solution:**
1. Press the physical RESET button
2. Run teensy_loader_cli immediately (within a few seconds)
3. If using `-w` flag, teensy_loader_cli will wait for the device - press RESET after starting the command

### Permission denied

```bash
# Option 1: Run with sudo
sudo teensy_loader_cli -v -mmcu=atmega32u4 -w ergodox_ez_shine_scottleeroberts.hex

# Option 2: Add udev rule (permanent fix)
sudo tee /etc/udev/rules.d/50-teensy.rules > /dev/null <<EOF
# Teensy Halfkay Bootloader
ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="0478", MODE:="0666"
EOF

sudo udevadm control --reload-rules
sudo udevadm trigger
```

### Docker permission denied

```bash
# Add yourself to docker group
sudo usermod -aG docker $USER

# Log out and back in
```

Or run Docker with sudo:
```bash
sudo docker run --rm \
  -v $(pwd):/qmk_firmware \
  -w /qmk_firmware \
  ghcr.io/qmk/qmk_cli \
  make ergodox_ez/shine:scottleeroberts
```

### Build fails with "submodule not found"

```bash
cd build/qmk_firmware
git submodule update --init --recursive --force
cd ../..
```

### Keys don't work after flashing

1. Unplug and replug USB
2. Check TRRS cable between halves is connected
3. Try reflashing

---

## Quick Reference Card

**Build:**
```bash
cd ~/scottleeroberts/ergodox
mkdir -p build && cd build
QMK_SHA=9e8199c41189a2eb6243600bf3f96f136650820b
git clone https://github.com/qmk/qmk_firmware.git  # first time
cd qmk_firmware
git checkout $QMK_SHA
git submodule update --init --recursive  # first time
mkdir -p keyboards/ergodox_ez/keymaps/scottleeroberts
cp ../../{keymap.c,config.h,rules.mk} keyboards/ergodox_ez/keymaps/scottleeroberts/
docker run --rm -v $(pwd):/qmk_firmware -w /qmk_firmware ghcr.io/qmk/qmk_cli make ergodox_ez/shine:scottleeroberts
cp ergodox_ez_shine_scottleeroberts.hex ../..
cd ../..
```

**Flash:**
```bash
# Press RESET button (or hold Numbers + ESC)
teensy_loader_cli -v -mmcu=atmega32u4 -w ergodox_ez_shine_scottleeroberts.hex
```

---

## Notes

- **Single flash** - unlike split keyboards, the Ergodox EZ only needs one flash
- **Each build is clean** - no cached state to corrupt
- **You see every command** - no hidden operations
- **Easy to debug** - if something fails, you know exactly where
- **No scripts to trust** - you control everything
- **QMK SHA pinned** - reproducible builds with `9e8199c41189a2eb6243600bf3f96f136650820b`
