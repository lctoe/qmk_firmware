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

enum planck_layers {
  _L0,
  _L1,
  _L2,
  _L3,
  _Ctrl,
  _Dvorak
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// This keymap is designed to move most common functions and actions to your fingers, as opposed to having to move your fingers to the keys, like on a larger board. However, some functions, like Shift and Ctrl, are not relocated for the sake of muscle memory.

// LAYERS:
// L0 is the default layer.
// L1 is accessed when the L1 key is being held.
// L2 is accessed when the L2 key is being held.
// L3 is accessed when the L1 key is being held, and the L2 key is pressed.
// The Ctrl layer is accessed when the Ctrl key is being held.
// The QWERTY layer is accessed when the L2 key is being held, and the L1 key is pressed.

// NOTES:
// On layers 3 and the QWERTY layer, the L1 and L2 keycodes are present instead of being transparent, because you need access to those layers in order to return to L0.
// The Ctrl key is NOT an actual Ctrl key, but rather a momentary layer switch. This allows for you to still copy and paste (among other things) using the left hand. (Most) keys used on the Ctrl layer are in their QWERTY locations.
// The right thumb is meant to hover or rest over the space key, while the left thumb is meant to hover over the backspace key.
// There is a rotary encoder where the "Mute" key is. While the function of the turning of the encoder changes depending on which layer you're on, when you press down on the encoder, it will always toggle mute.
	
/* L0
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  ' " |  , < |  . > |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  / ? |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Mute |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  | - _  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   :  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  OS  | Alt  |PrtSc |  Tab | Bksp |Space |  L2  |  L1  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_L0] = LAYOUT_planck_grid(
    KC_ESC,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
    KC_MUTE,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
    KC_LSFT,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
    MO(_Ctrl),KC_LGUI, KC_LALT, KC_PSCR, KC_TAB,  KC_BSPC, KC_SPC,  MO(_L2), MO(_L1), KC_LEFT, KC_DOWN, KC_RGHT
),

/* L1
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   (  |   )  | [ {  | ] }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CpsLck|      |      |      |      |      |      |      |      |      |  Up  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Del  |      |  L3  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_L1] = LAYOUT_planck_grid(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, _______, 
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______,
    _______, _______, _______, _______, _______, KC_DEL,  _______, TG(_L3), _______, _______, _______, _______,
), 

/* L2
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      |      |   =  |   +  |      | \ |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |QWERTY|      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_L2] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, 	 _______, _______, _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, KC_EQL, 	 KC_PLUS, _______, KC_BSLS,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______,     _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, TG(_QWERTY), _______, _______, _______,
),

/* L3
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  L1  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_L3] = LAYOUT_planck_grid(
    KC_TILD,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, MO(_L1), _______, _______, _______,
),
/* Ctrl
 * ,-----------------------------------------------------------------------------------.
 * |      |      |Ctrl <|Ctrl >|Ctrl P|      |      |Ctrl -|Ctrl +|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Ctrl A|      |      |Ctrl F|      |      |Ctrl B|Ctrl U|Ctrl I|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Ctrl Z|Ctrl Y|Ctrl C|Ctrl V|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |CtrlPS|      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_Ctrl] = LAYOUT_planck_grid(
    _______, _______, C(KC_COMM), C(KC_DOT), C(KC_Z), _______,    _______, C(KC_MINS), C(KC_EQL), _______,    _______, _______,
    _______, C(KC_A), _______,    _______,   C(KC_F), _______,    _______, C(KC_B),    C(KC_U),   C(KC_I),    _______, _______,
    _______, C(KC_Z), C(KC_Y),    C(KC_C),   C(KC_V), _______,    _______, _______,    _______,   _______,    _______, _______,
    _______, _______, _______,    _______,   _______, C(KC_PSCR), _______, _______,    _______,   _______,    _______, _______,
),   
/* QWERTY
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ; : |  ' " |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  , < |  . > |  / ? |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  OS  | Alt  | Tab  |Space |PrtSc |Space |  L2  |  L1  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    _______, KC_LGUI, KC_LALT, KC_PSCR, KC_SPC,  KC_TAB,  KC_SPC,  MO(_L2), MO(_L1), KC_LEFT, KC_DOWN, KC_RGHT
)
};

void encoder_update(bool clockwise) { 
  if(IS_LAYER_ON(_L3)) // Letter/Word Scrolling and Selecting
  {
    if (clockwise) {
        tap_code(KC_RGHT);
    } else {
        tap_code(KC_LEFT);
    }
  }
  else if(IS_LAYER_ON(_L2)) // Zooming
  {
   if (clockwise) {
        tap_code16(C(KC_PPLS));
    } else {
        tap_code16(C(KC_PMNS));
    }
  }
  else if(IS_LAYER_ON(_L1)) // History Scrubbing
  {
   if (clockwise) {
        tap_code16(C(KC_Y));
    } else {
        tap_code16(C(KC_Z));
    }
  }
  else if(IS_LAYER_ON(_L0)) // Volume (Base)
  {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
 }
}


