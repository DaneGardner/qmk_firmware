
#ifdef PLANCK
#include "planck.h"
#endif

#ifdef PREONIC
#include "preonic.h"
#endif

#include "action_layer.h"
#include "eeconfig.h"

#undef AUDIO_ENABLE
extern keymap_config_t keymap_config;

#define _QWERTY 0
#define QWERTY M(_QWERTY)

#define _LOWER 1
#define LOWER M(_LOWER)

#define _UPPER 2
#define UPPER M(_UPPER)

#define _FUNCT 3
#define FUNCT M(_FUNCT)

#define _BACKLT 10
#define BACKLT M(_BACKLT)

#define _PARENS 21
#define PARENS M(_PARENS)

#define _BRACKE 22
#define BRACKE M(_BRACKE)

#define _CURLYB 23
#define CURLYB M(_CURLYB)

#define _RNDABC 30
#define RNDABC M(_RNDABC)

#define _RND123 31
#define RND123 M(_RND123)


#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define P_LAYER(_layer) if (record->event.pressed) persistant_default_layer_set(1UL<<_layer);

// When both lower and raise are pressed, go to function layer
#define UPDATE_LAYERS update_tri_layer(_LOWER, _UPPER, _FUNCT)

#define M_LAYER(_layer) if (record->event.pressed) { \
                          layer_on(_layer);          \
                          UPDATE_LAYERS;             \
                        } else {                     \
                          layer_off(_layer);         \
                          UPDATE_LAYERS;             \
                        }
