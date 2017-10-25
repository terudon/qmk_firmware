#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY     0
#define _COLEMAK    1
#define _DVORAK     2
#define _SPECIAL    3
#define _NUMBER     4
#define _NAVIGATE   5
#define _TURKCE     6
#define _ADJUST    16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  ADJUST,
  TURKCE,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define NUMBER TT(_NUMBER)
#define NAVIGATE TT(_NAVIGATE)

#define I_ESC MT(MOD_LGUI,KC_ESC)
#define I_LENT MT(MOD_LSFT,KC_ENT)
#define I_RENT MT(MOD_RSFT,KC_ENT)
#define I_SPC LT(_SPECIAL, KC_SPACE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
| Tab  |   Q  |   W  |   E  |   R  |   T  |  Q  |  Y   |  U   |  I   |  O   |  P   | Bksp |
|------+------+------+------+------+------|  W  |------+------+------+------+------+------|
| iEsc |   A  |   S  |   D  |   F  |   G  |  E  |  H   |  J   |  K   |  L   |  ;   |  "   |
|------+------+------+------+------+------|  R  |------+------+------+------+------+------|
| iEnt |   Z  |   X  |   C  |   V  |   B  |  T  |  N   |  M   |  ,   |  .   |  /   | iEnt |
|------+------+------+------+------+------|  Y  |------+------+------+------+------+------|
| Ctrl | Alt  |Adjust|Number| Nav  | iSpc |     | iSpc | Nav  |Number|Turkce| Alt  | Ctrl | 
`-----------------------------------------´     `-----------------------------------------'
*/
[_QWERTY] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  I_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  I_LENT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, I_RENT,  \
  KC_LCTL, KC_LALT, ADJUST,  NUMBER,  NAVIGATE,I_SPC,   I_SPC,NAVIGATE,   NUMBER,  TURKCE,  KC_RALT, KC_RCTL  \
),

/*
|   ~  |   !  |   @  |   #  |   $  |   %  |  S  |   ^  |   &  |   *  |   (  |   )  | Del  |
|------+------+------+------+------+------|  P  |------+------+------+------+------+------|
|   `  |      |      |      |      |      |  E  |      |   _  |   +  |   {  |   }  |  \   |
|------+------+------+------+------+------|  C  |------+------+------+------+------+------|
|      |      |      |      |      |      |  I  |      |   -  |   =  |   [  |   ]  |      |
|------+------+------+------+------+------|  A  |------+------+------+------+------+------|
|      |      |      |      |      |      |  L  |      |      |      |      |      |      |
`-----------------------------------------´     `-----------------------------------------'
*/
[_SPECIAL] = KEYMAP( \
  S(KC_TILD), KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC,  KC_AMPR, KC_ASTR,  KC_LPRN, KC_RPRN, KC_DEL,  \
  KC_TILD,    _______, _______, _______, _______, _______,     _______,S(KC_MINS),KC_PLUS,  KC_LBRC, KC_RBRC, KC_PIPE, \
  _______,    _______, _______, _______, _______, _______,     _______, KC_MINS,  KC_EQUAL, KC_LCBR, KC_RCBR, _______, \
  _______,    _______, _______, _______, _______, _______,     _______, _______,  _______,  _______, _______, _______  \
),

/*
|      | F1   | F2   | F3   | F4   | F5   |  N  |  /   |  7   |  8   |  9   |  -   |      |
|------+------+------+------+------+------|  U  |------+------+------+------+------+------|
|      | F6   | F7   | F8   | F9   | F10  |  M  |  *   |  4   |  5   |  6   |  +   |      |
|------+------+------+------+------+------|  B  |------+------+------+------+------+------|
|      | F11  | F12  | F13  | F14  | F15  |  E  |  0   |  1   |  2   |  3   |  .   |      |
|------+------+------+------+------+------|  R  |------+------+------+------+------+------|
|      |      |      |      |      |      |     |      |      |      |      |      |      |
`-----------------------------------------´     `-----------------------------------------'
 */
[_NUMBER] = KEYMAP( \
   _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,    KC_PSLS, KC_7   , KC_8   , KC_9   , KC_PMNS, _______, \
   _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,    KC_PAST, KC_4   , KC_5   , KC_6   , KC_PPLS, _______, \
   _______, KC_F11 , KC_F12 , KC_F13 , KC_F14 , KC_F15 ,    KC_0   , KC_1   , KC_2   , KC_3   , KC_PDOT, _______, \
   _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______  \
),

/*
|      |      |      | Prev | Play | Next |  N  | Mute | Vol- | Vol+ |      |      |      |
|------+------+------+------+------+------|  A  |------+------+------+------+------+------|
|      |      | Home | PgUp | PgDn | End  |  V  | Left | Down | Up   |Right |      |      |
|------+------+------+------+------+------|  I  |------+------+------+------+------+------|
|      |      |      |      |      |      |  G  |      |      |      |      |      |      |
|------+------+------+------+------+------|  A  |------+------+------+------+------+------|
|      |      |      |      |      |      |  T  |      |      |      |      |      |      |
`-----------------------------------------´  E  `-----------------------------------------'
 */
[_NAVIGATE] = KEYMAP( \
  _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT,   KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______,\
  _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END ,   KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,\
  _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,\
  _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______ \
),

/*
|      | Reset|      |      |      |      |  A  |      |      |      |      |      |  Del |
|------+------+------+------+------+------|  D  |------+------+------+------+------+------|
|      |      |      |Aud on|Audoff|AGnorm|  J  |AGswap|Qwerty|Colemk|Dvorak|      |      |
|------+------+------+------+------+------|  U  |------+------+------+------+------+------|
|      |      |      |      |      |      |  S  |      |      |      |      |      |      |
|------+------+------+------+------+------|  T  |------+------+------+------+------+------|
|      |      |      |      |      |      |     |      |      |      |      |      |      |
`-----------------------------------------´     `-----------------------------------------'
 */
[_ADJUST] =  KEYMAP( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/*
|      |      |      |      |      |      |  T  |      |  Ü   |  I   |  Ö   |      |      |
|------+------+------+------+------+------|  U  |------+------+------+------+------+------|
|      |  â   |  Ş   |      |      |  Ğ   |  R  |      |      |      |      |      |      |
|------+------+------+------+------+------|  K  |------+------+------+------+------+------|
|      |      |      |  Ç   |      |      |  C  |      |      |      |      |      |      |
|------+------+------+------+------+------|  E  |------+------+------+------+------+------|
|      |      |      |      |      |      |     |      |      |      |      |      |      |
`-----------------------------------------´     `-----------------------------------------'
 */
[_TURKCE] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______,UC(0x00FC),UC(0x0131),UC(0x00F6), _______, _______, \
  _______,UC(0x00E2),UC(0x015F), _______, _______,UC(0x011F), _______, _______, _______, _______, _______, _______, \
  _______, _______, _______,UC(0x00E7), _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* 
| Tab  |   Q  |   W  |   F  |   P  |   G  |  C  |  J   |  L   |  U   |  Y   |  ;   | Bksp |
|------+------+------+------+------+------|  O  |------+------+------+------+------+------|
| Esc  |   A  |   R  |   S  |   T  |   D  |  L  |  H   |  N   |  E   |  I   |  O   |  "   |
|------+------+------+------+------+------|  E  |------+------+------+------+------+------|
| iEnt |   Z  |   X  |   C  |   V  |   B  |  M  |  K   |  M   |  ,   |  .   |  /   | iEnt |
|------+------+------+------+------+------|  A  |------+------+------+------+------+------|
| Ctrl | Alt  |Adjust|Number| Nav  | iSpc |  K  | ìSpc | Nav  |Number|Adjust| Alt  | Ctrl | 
`-----------------------------------------´     `-----------------------------------------'
 */
[_COLEMAK] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  I_ESC,   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,        KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  I_LENT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, I_RENT,  \
  KC_LCTL, KC_LALT, ADJUST,  NUMBER,  NAVIGATE,I_SPC,       I_SPC,NAVIGATE,   NUMBER,  ADJUST,  KC_RALT, KC_RCTL  \
),

/* 
| Tab  |   "  |   ,  |   ,  |   P  |   Y  |  D  |  F   |  G   |  C   |  R   |  L   | Bksp |
|------+------+------+------+------+------|  V  |------+------+------+------+------+------|
| Esc  |   A  |   O  |   E  |   U  |   I  |  O  |  D   |  H   |  T   |  N   |  S   |  /   |
|------+------+------+------+------+------|  R  |------+------+------+------+------+------|
| iEnt |   ;  |   Q  |   J  |   K  |   X  |  A  |  B   |  M   |  W   |  V   |  Z   | iEnt |
|------+------+------+------+------+------|  K  |------+------+------+------+------+------|
| Ctrl | Alt  |Adjust|Number| Nav  | iSpc |     | ìSpc | Nav  |Number|Adjust| Alt  | Ctrl | 
`-----------------------------------------´     `-----------------------------------------'
 */
[_DVORAK] = KEYMAP( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,        KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  I_ESC,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,        KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  I_LENT,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    I_RENT , \
  KC_LCTL, KC_LALT, ADJUST,  NUMBER,  NAVIGATE,I_SPC,       I_SPC,NAVIGATE,   NUMBER,  ADJUST,  KC_RALT, KC_RCTL  \
)

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case TURKCE:
      if (record->event.pressed) {
        layer_on(_TURKCE);
      } else {
        layer_off(_TURKCE);
      }
  }
  return true;
}
