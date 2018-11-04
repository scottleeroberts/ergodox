## Building

To build it you will need [qmk_firmware][qmk] checked out and this repo checked
out to something like `keyboards/ergodox/keymaps/scottleeroberts`.

 [qmk]: https://github.com/jackhumbert/qmk_firmware

```
$ git clone https://github.com/jackhumbert/qmk_firmware.git
$ cd qmk_firmware
$ git clone https://github.com/scottleeroberts/ergodox.git \keyboards/ergodox/keymaps/scottleeroberts
$ docker run -e keymap=scottleeroberts -e keyboard=ergodox_ez --rm -v $('pwd'):/qmk:rw edasque/qmk_firmware
$ teensy-loader-cli -mmcu=atmega32u4 -w ergodox_ez_scottleeroberts.hex

