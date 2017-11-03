#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY     0
#define _COLEMAK    1
#define _DVORAK     2
#define _SPECIAL    3
#define _NAVNUM     4
#define _FUNCTION   5
#define _TURKCE     6
#define _ADJUST    16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  ADJUST,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define NAVNUM      TT(_NAVNUM)
#define FUNCTION    OSL(_FUNCTION)
#define TURKCE      OSL(_TURKCE)

#define I_SPC   LT(_SPECIAL, KC_SPACE)
#define I_ESC   MT(MOD_LGUI,KC_ESC)
#define I_QUOT  MT(MOD_LGUI,KC_QUOT)
#define I_LENT  MT(MOD_LSFT,KC_ENT)
#define I_RENT  MT(MOD_RSFT,KC_ENT)

#define ALT_L LALT(KC_H)
#define ALT_D LALT(KC_J)
#define ALT_U LALT(KC_K)
#define ALT_R LALT(KC_L)

#define CTL_L LCTL(KC_H)
#define CTL_D LCTL(KC_J)
#define CTL_U LCTL(KC_K)
#define CTL_R LCTL(KC_L)

#define TUR_A UC(0x00E2)
#define TUR_S UC(0x015F)
#define TUR_C UC(0x00E7)
#define TUR_G UC(0x011F)
#define TUR_U UC(0x00FC)
#define TUR_I UC(0x0131)
#define TUR_O UC(0x00F6)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
| Tab  |   Q  |   W  |   E  |   R  |   T  |  Q  |  Y   |  U   |  I   |  O   |  P   | Bksp |
|------+------+------+------+------+------|  W  |------+------+------+------+------+------|
| iEsc |   A  |   S  |   D  |   F  |   G  |  E  |  H   |  J   |  K   |  L   |  ;   | iQOUT|
|------+------+------+------+------+------|  R  |------+------+------+------+------+------|
| iEnt |   Z  |   X  |   C  |   V  |   B  |  T  |  N   |  M   |  ,   |  .   |  /   | iEnt |
|------+------+------+------+------+------|  Y  |------+------+------+------+------+------|
| Ctrl | Alt  |Adjust| Fun  | N-N  | iSpc |     | tSpc | N-N  | Tur  |Adjust| Alt  | Ctrl | 
`-----------------------------------------´     `-----------------------------------------'
*/
[_QWERTY] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,   KC_T,    KC_Y,  KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC, \
  I_ESC,   KC_A,    KC_S,    KC_D,     KC_F,   KC_G,    KC_H,  KC_J,   KC_K,    KC_L,    KC_SCLN, I_QUOT,  \
  I_LENT,  KC_Z,    KC_X,    KC_C,     KC_V,   KC_B,    KC_N,  KC_M,   KC_COMM, KC_DOT,  KC_SLSH, I_RENT,  \
  KC_LCTL, KC_LALT, ADJUST,  FUNCTION, NAVNUM, I_SPC,   I_SPC, NAVNUM, TURKCE,  ADJUST,  KC_RALT, KC_RCTL  \
),

/*
|   ~  |   !  |   @  |   #  |   $  |   %  |  S  |   ^  |   &  |   *  |   _  |   =  | Del  |
|------+------+------+------+------+------|  P  |------+------+------+------+------+------|
|   `  |      |      |   (  |   )  |      |  E  |      |   {  |   }  |   -  |   +  |  \   |
|------+------+------+------+------+------|  C  |------+------+------+------+------+------|
|      |      |      |   <  |   >  |      |  I  |      |   [  |   ]  |      |      |  |   |
|------+------+------+------+------+------|  A  |------+------+------+------+------+------|
|      |      |      |      |      |      |  L  |      |      |      |      |      |      |
`-----------------------------------------´     `-----------------------------------------'
*/
[_SPECIAL] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_EQUAL, KC_DEL,  \
  KC_GRV , _______, _______, KC_LPRN, KC_RPRN, _______,     _______, KC_LCBR, KC_RCBR, KC_MINS, KC_PLUS,  KC_BSLS, \
  _______, _______, _______, KC_LABK, KC_RABK, _______,     _______, KC_LBRC, KC_RBRC, _______, _______,  KC_PIPE, \
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,  _______  \
),

/*
|      |      |  7   |  8   |  9   |      |  N  |*Left |*Down |*Up   |*Right| Prev |      |
|------+------+------+------+------+------|  A  |------+------+------+------+------+------|
|      |  0   |  4   |  5   |  6   |      |  V  | Left | Down | Up   |Right | Play |      |
|------+------+------+------+------+------|  I  |------+------+------+------+------+------|
|      |      |  1   |  2   |  3   |      |  G  |#Left |#Down |#Up   |#Right| Next |      |
|------+------+------+------+------+------|  A  |------+------+------+------+------+------|
|      |      |      |      |      |      |  T  |      |      |      |      |      |      |
`-----------------------------------------´  E  `-----------------------------------------'
 */
[_NAVNUM] = KEYMAP( \
  _______, _______, KC_7   , KC_8   , KC_9   , _______,   ALT_L  , ALT_D  , ALT_U  , ALT_R  , KC_MRWD, _______,\
  _______, KC_0   , KC_4   , KC_5   , KC_6   , _______,   KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_MPLY, _______,\
  _______, _______, KC_1   , KC_2   , KC_3   , _______,   CTL_L  , CTL_D  , CTL_U  , CTL_R  , KC_MFFD, _______,\
  _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______ \
),

/*
|      | F1   | F2   | F3   | F4   | F5   |  F  | Caps |      | Isrt |      | PrScr|      |
|------+------+------+------+------+------|  U  |------+------+------+------+------+------|
|      | F6   | F7   | F8   | F9   | F10  |  N  | Home | PgDn | PgUp | End  |      |      |
|------+------+------+------+------+------|  C  |------+------+------+------+------+------|
|      | F11  | F12  | F13  | F14  | F15  |  T  |      | Vol- | Vol+ | Mute |      |      |
|------+------+------+------+------+------|  I  |------+------+------+------+------+------|
|      |      |      |      |      |      |  O  |      |      |      |      |      |      |
`-----------------------------------------´  N  `-----------------------------------------'
 */
[_FUNCTION] = KEYMAP( \
   _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,    KC_CAPS, _______, KC_INS,  _______, KC_PSCR, _______, \
   _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,    KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______, \
   _______, KC_F11 , KC_F12 , KC_F13 , KC_F14 , KC_F15 ,    _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, \
   _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______  \
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
|      |      |      |      |      |      |     |      |      |      |Türkçe|      |      |
`-----------------------------------------´     `-----------------------------------------'
 */
[_TURKCE] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, TUR_U  , TUR_I  , TUR_O  , _______, _______, \
  _______, TUR_A  , TUR_S  , _______, _______, TUR_G  , _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, TUR_C  , _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, TURKCE , _______, _______, _______ \
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
  KC_TAB,  KC_Q,    KC_W,    KC_F,     KC_P,    KC_G,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  I_ESC,   KC_A,    KC_R,    KC_S,     KC_T,    KC_D,        KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  I_LENT,  KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, I_RENT,  \
  KC_LCTL, KC_LALT, ADJUST,  FUNCTION, NAVNUM,  I_SPC,       I_SPC,   NAVNUM,  TURKCE,  ADJUST,  KC_RALT, KC_RCTL  \
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
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,   KC_P,    KC_Y,        KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  I_ESC,   KC_A,    KC_O,    KC_E,     KC_U,    KC_I,        KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  I_LENT,  KC_SCLN, KC_Q,    KC_J,     KC_K,    KC_X,        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    I_RENT , \
  KC_LCTL, KC_LALT, ADJUST,  FUNCTION, NAVNUM,  I_SPC,       I_SPC,   NAVNUM,  TURKCE,  ADJUST,  KC_RALT, KC_RCTL  \
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

void matrix_init_user() {
    set_unicode_input_mode(UC_LNX);
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
  }
  return true;
}
