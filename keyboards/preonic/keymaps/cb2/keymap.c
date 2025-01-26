/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

// Left-hand home row mods
#define HOME_A LSFT_T(KC_A)
#define HOME_S LCTL_T(KC_S)
#define HOME_D LALT_T(KC_D)
#define HOME_F LGUI_T(KC_F)

// Right-hand home row mods
#define HOME_J RGUI_T(KC_J)
#define HOME_K RALT_T(KC_K)
#define HOME_L RCTL_T(KC_L)
#define HOME_SC RSFT_T(KC_SCLN)

// Hold Escape for navigation layer
#define CB_ESC LT(_NAV, KC_ESC)
enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _NAV,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT,
  CB_TR,    // next tab (cmd + shift + ])
  CB_TL,    // prev tab (cmd + shift + [)
  CB_RA,    // right arrow (<-)
  CB_LA,    // little arrow (->)
  CB_BA,    // big arrow (=>)
  CB_EXP,   // elixir pipe (|>)
  CB_LW,    // left word (alt + left)
  CB_RW,    // right word (alt + right)
  CB_LL,    // left - beginning of line (cmd + left)
  CB_RL,    // right - end of line (cmd + right)
  CB_SLW,   // select left word (shift + alt + left)
  CB_SRW,   // select right word (shift + alt + right)
  CB_MLDN,  // move line down - vscode (alt + up)
  CB_MLUP,  // move line up - vscode (alt + dn)
  CB_CLDN,  // copy line down - vscode (shift + alt + down)
  CB_CLUP   // copy line up - vscode (shift + alt + up)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   | <= SCAG home row mods
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  | Lower/Space | Space/Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_2x2u(
  KC_GRV,    KC_1,    KC_2,   KC_3,    KC_4,    KC_5,      KC_6,   KC_7,       KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,    KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,      KC_Y,   KC_U,       KC_I,    KC_O,    KC_P,    KC_BSLS,
  CB_ESC,    HOME_A,  HOME_S, HOME_D,  HOME_F,  KC_G,      KC_H,   HOME_J,     HOME_K,  HOME_L,  HOME_SC, KC_QUOT,
  KC_LSFT,   KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,      KC_N,   KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  BACKLIT,   KC_LCTL, KC_LALT,KC_LGUI, LT(_LOWER, KC_SPC), LT(_RAISE, KC_SPC), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  | Lower/Space | Space/Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_2x2u(
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,      KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,      KC_J,    KC_L,      KC_U,    KC_Y,    KC_SCLN, KC_DEL,
  CB_ESC,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,      KC_H,    KC_N,      KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_K,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  BACKLIT,   KC_LCTL, KC_LALT, KC_LGUI, LT(_LOWER, KC_SPC), LT(_RAISE, KC_SPC), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  | Lower/Space | Space/Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_preonic_2x2u(
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,      KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,    KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,      KC_F,    KC_G,      KC_C,    KC_R,    KC_L,    KC_BSLS,
  CB_ESC,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,      KC_D,    KC_H,      KC_T,    KC_N,    KC_S,    KC_SLSH,
  KC_LSFT,   KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,      KC_B,    KC_M,      KC_W,    KC_V,    KC_Z,    KC_ENT,
  BACKLIT,   KC_LCTL, KC_LALT, KC_LGUI, LT(_LOWER, KC_SPC), LT(_RAISE, KC_SPC), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |  ->  |  =>  |   [  |   ]  |  |>  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      |      | PreT | NexT |      |      |   -  |   =  |   {  |   }  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RGB_T| RGB+ | RGB- |      |             |             | Mute | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_2x2u(
  KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,   KC_F10,  KC_DEL,
  KC_TILD, KC_1,    KC_2,    KC_3,    _______, _______, CB_RA,   CB_LA,      CB_BA,      KC_LBRC, KC_RBRC, CB_EXP,
  KC_DEL,  KC_4,    KC_5,    KC_6,    CB_TL,   CB_TR,   _______, KC_MINS,    KC_EQL,     KC_LCBR, KC_RCBR, KC_BSLS,
  KC_CAPS, KC_7,    KC_8,    KC_9,    KC_0,    KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
  RGB_TOG, RGB_MODE_FORWARD, RGB_MODE_REVERSE, _______, _______, _______,    KC_KB_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             | Mute | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_2x2u(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,       KC_9,    KC_0,    KC_BSPC,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,       KC_9,    KC_0,    KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS,    KC_LBRC, KC_RBRC, KC_BSLS,
  KC_CAPS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS,    KC_PGUP, KC_PGDN, _______,
  _______, _______, _______, _______, _______,          _______,          KC_KB_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Navigation (Hold Esc)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Line↓| Line↑|      |      |      |<Line |<Word | Word>| Line>|  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Shift| Ctrl | Alt  | Cmd  |      |      | Left | Down |  Up  | Right|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |cLine↓|cLine↑|      |      |      |<sLine|<sWord|sWord>|sLine>|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_preonic_2x2u(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, _______, CB_MLDN, CB_MLUP, _______, _______, _______, CB_LL,   CB_LW,   CB_RW,   CB_RL,   KC_DEL,
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
  _______, _______, CB_CLDN, CB_CLUP, _______, _______, _______, _______, CB_SLW,  CB_SRW,  _______, KC_ENT,
  _______, _______, _______, _______, _______,          _______,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, QK_BOOT, DB_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______,
  _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
        case CB_TL:
          if (record->event.pressed) {
            SEND_STRING(SS_LGUI(SS_LSFT("[")));
          }
          return false;
          break;
        case CB_TR:
          if (record->event.pressed) {
            SEND_STRING(SS_LGUI(SS_LSFT("]")));
          }
          return false;
          break;
        case CB_RA:
          if (record->event.pressed) {
            SEND_STRING("<-");
          }
          return false;
          break;
        case CB_LA:
          if (record->event.pressed) {
            SEND_STRING("->");
          }
          return false;
          break;
        case CB_BA:
          if (record->event.pressed) {
            SEND_STRING("=>");
          }
          return false;
          break;
        case CB_EXP:
          if (record->event.pressed) {
            SEND_STRING("|>");
          }
          return false;
          break;
        case CB_LW:
          if (record->event.pressed) {
            SEND_STRING(SS_LALT(SS_TAP(X_LEFT)));
          }
          return false;
          break;
        case CB_RW:
          if (record->event.pressed) {
            SEND_STRING(SS_LALT(SS_TAP(X_RIGHT)));
          }
          return false;
          break;
        case CB_LL:
          if (record->event.pressed) {
            SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)));
          }
          return false;
          break;
        case CB_RL:
          if (record->event.pressed) {
            SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT)));
          }
          return false;
          break;
        case CB_SLW:
          if (record->event.pressed) {
            SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_LEFT))));
          }
          return false;
          break;
        case CB_SRW:
          if (record->event.pressed) {
            SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_RIGHT))));
          }
          return false;
          break;
        case CB_MLDN:
          if (record->event.pressed) {
            SEND_STRING(SS_LALT(SS_TAP(X_DOWN)));
          }
          return false;
          break;
        case CB_MLUP:
          if (record->event.pressed) {
            SEND_STRING(SS_LALT(SS_TAP(X_UP)));
          }
          return false;
          break;
        case CB_CLDN:
          if (record->event.pressed) {
            SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_DOWN))));
          }
          return false;
          break;
        case CB_CLUP:
          if (record->event.pressed) {
            SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_UP))));
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
  return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
