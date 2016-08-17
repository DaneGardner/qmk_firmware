# Dane's Layout

To build for `planck` keyboard:
```bash
# clean and build
make clean && make keyboard=planck keymap=dane

# program with a moment to reset the keyboard first
sleep 15 && sudo make keyboard=planck keymap=dane dfu
```

## Core layer
* default core layer
* `Tab`/`Esc` swapped
* command keys shifted to the left.

## Lower layer
* numbers and symbols
* mouse movements on arrow keys

## Upper layer
* function keys (F01-F24) --full set only added because there was room
* `PgUp`/`PgDn`/`Home`/`End` on arrow keys --meant to hold raise with thumb, while using arrows to immediate right, one handed

## Function layer
Accessed by holding down both the `raise` and `lower` keys simultaneously. Layer is mostly keyboard and system related keys, as well as some custom macros.
* backlight
* volume controls
* sleep & power
* custom macros

## Preonic
This keyboard only adds the number keys to a new top row.  All layers behave as they would on a plain Planck.

```bash
make clean && make keyboard=planck keymap=dane
```
