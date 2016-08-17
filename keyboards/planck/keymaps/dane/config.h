
#ifndef DANE_CONFIG_H
#define DANE_CONFIG_H

#ifdef PLANCK
#include "../../../planck/config.h"
#endif

#ifdef PREONIC
#include "../../../preonic/config.h"
#endif

#define STRING2(x) #x
#define STRING(x) STRING2(x)

#undef PRODUCT

#ifdef PLANCK
#define PRODUCT Danes Planck Keyboard
#endif

#ifdef PREONIC
#define PRODUCT Danes Preonic Keyboard
#endif

#pragma message(STRING(PRODUCT))

#undef PRODUCT_ID
#define PRODUCT_ID 0x5050

#undef BACKLIGHT_LEVELS
#define BACKLIGHT_LEVELS 4

#endif
