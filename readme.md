## Building

To build it you will need [qmk_firmware][qmk] checked out and this repo checked
out to something like `keyboards/ergodox/keymaps/scottleeroberts`.

 [qmk]: https://github.com/jackhumbert/qmk_firmware

```
$ `git clone https://github.com/jackhumbert/qmk_firmware.git`
$ `cd qmk_firmware`
$ `git checkout 212aeee202`
$ `git clone https://github.com/scottleeroberts/ergodox.git \keyboards/ergodox_ez/keymaps/scottleeroberts`
$ from the root of qmk_firware, run `./util/docker_build.sh ergodox_ez:scottleeroberts`
$ teensy_loader_cli -mmcu=atmega32u4 -w ergodox_ez_scottleeroberts.hex

