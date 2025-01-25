# keyboard_layouts
Collection of keyboard layouts for use with QMK tools.  

Note: Layouts are currently WIP while I learn the layout and tweak the settings. Currently only base (alpha) layer is configured, but it should be easily extendable. 

## License

This repo uses the Apache License 2.0 except where otherwise indicated. See the
[LICENSE file](LICENSE.txt) for details.

## Acknowledgments  

- The [Magic Sturdy](https://github.com/Ikcelaks/keyboard_layouts) layout is based on `@Ikcelaks` customisation of [Sturdy](https://oxey.dev/sturdy/index.html) keyboard layout. 

## firmware

TO-DO

## customisations

You can use this repository as starting point of configuring your own customisations for included layouts. If so follow the below steps. 

### prerequisites
- [QMK](https://qmk.fm/) installed

### add the custom layouts to QMK 
you can either copy specific layout to the corresponding `keyboards/<specific_keyboard>/keymap/slavpilus` directory or created symlink like so:  

```bash
# from root of the cloned repo
ln -s ./qmk/ergodox_ez/keymaps/slavpilus <qmk_firmware_dir>/keyboards/ergodox_ez/keymaps/slavpilus
qmk config user.keyboard=ergodox_ez/base
``` 

For ease of use you can create similar defaults to your `qmk` configuration (adjust to your needs):
```bash
qmk config user.keyboard=ergodox_ez/base
qmk config user.keymap=slavpilus
```

### compile

```bash
qmk compile
# or if no defaults are set you need specify keyboard and layout 
qmk compile -kb=ergodox_ez/base -km=slavpilus
```

### flash keyboard
```bash
qmk flash
```

