## Building

To build it you will need [qmk_firmware][qmk] checked out and this repo checked
out to something like `keyboards/ergodox/keymaps/scottleeroberts`.

 [qmk]: https://github.com/jackhumbert/qmk_firmware

```
$ git clone https://github.com/jackhumbert/qmk_firmware.git
$ cd qmk_firmware
$ git clone https://github.com/scottleeroberts/ergodox.git \keyboards/ergodox/keymaps/scottleeroberts
$ ln -s ~/keyboards/ergodox/keymaps/scottleeroberts \keyboards/ergodox/keymaps/scottleeroberts
$ cd ~/qmk_firmware
$ make teensy KEYBOARD=ergodox_ez KEYMAP=scottleeroberts
