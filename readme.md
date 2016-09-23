## Building

To build it you will need [qmk_firmware][qmk] checked out and this repo checked
out to something like `keyboards/ergodox/keymaps/scottleeroberts`.

 [qmk]: https://github.com/jackhumbert/qmk_firmware

```
$ git clone https://github.com/jackhumbert/qmk_firmware.git
$ cd qmk_firmware
$ git clone https://github.com/scottleeroberts/ergodox.git \keyboards/ergodox/keymaps/scottleeroberts
$ make KEYBOARD=ergodox KEYMAP=scottleeroberts
