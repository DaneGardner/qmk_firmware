BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
NKRO_ENABLE = yes           # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.
EXTRAKEY_ENABLE = no        # Audio control and System control(+450)
COMMAND_ENABLE = no         # Commands for debug and configuration

ifeq ($(KEYBOARD),planck)
OPT_DEFS += -DPLANCK
else ifeq ($(KEYBOARD),preonic)
OPT_DEFS += -DPREONIC
endif

CONFIG_H = keymaps/$(KEYMAP)/config.h
