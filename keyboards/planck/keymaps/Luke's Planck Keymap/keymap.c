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
  _Raise,
  _Lower,
  _Number,
  _Ctrl,
  _QWERTY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// This keymap is designed to move most common functions and actions to your fingers, as opposed to having to move your fingers to the keys, like on a larger board. However, some functions, like Shift and Ctrl, are not relocated for the sake of muscle memory.

// LAYERS:
// L0 is the default layer.
// Raise is accessed when the L1 key is being held.
// Lower is accessed when the L2 key is being held.
// The number layer is accessed when the L1 key is being held, and the L2 key is pressed.
// The Ctrl layer is accessed when the Ctrl key is being held.
// The QWERTY layer is accessed when the L2 key is being held, and the L1 key is pressed.

// NOTES:
// On layers 3 and the QWERTY layer, the L1 and L2 keycodes are present instead of being transparent, because you need access to those layers in order to return to L0.
// The Ctrl key is NOT an actual Ctrl key, but rather a momentary layer switch. This allows for you to still copy and paste (among other things) using the left hand. (Most) keys used on the Ctrl layer are in their QWERTY locations.
// The right thumb is meant to hover or rest over the space key, while the left thumb is meant to hover over the backspace key.
// There is a rotary encoder where the "Mute" key is. While the function of the turning of the encoder changes depending on which layer you're on, when you press down on the encoder, it will always toggle mute.
// Shifted number keys (on the Number layer) are slightly moved around for a combination of efficiency and some compromises for muscle memory. 
// The Lower key on the QWERTY layer acts as space upon pressing it so the left hand can sit comfortably while gaming and still jump while in a resting position.
// Ctrl + M as a mic muting function is a keybind set in discord; it is not universal for the rest of the computer.
	
/* L0
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  ' " |  , < |  . > |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  / ? |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Mute |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  | - _  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   :  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  OS  | Alt  | Tab  |Lower | Bksp |Space |Raise |PrtSc | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_L0] = LAYOUT_planck_grid(
    KC_ESC,            KC_QUOT, KC_COMM, KC_DOT,  KC_P,        KC_Y,    KC_F,    KC_G,       KC_C,    KC_R,    KC_L,    KC_SLSH,
    KC_MUTE,           KC_A,    KC_O,    KC_E,    KC_U,        KC_I,    KC_D,    KC_H,       KC_T,    KC_N,    KC_S,    KC_ENT ,
    KC_LSFT,           KC_SCLN, KC_Q,    KC_J,    KC_K,        KC_X,    KC_B,    KC_M,       KC_W,    KC_V,    KC_Z,    KC_MINS,
    LM(_Ctrl, MOD_CTL),KC_LGUI, KC_LALT, KC_TAB , MO(_Lower),  KC_BSPC, KC_SPC,  MO(_Raise), KC_PSCR, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |   #  |   $  |      |      |   &  |   *  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |MicMut|   !  |   @  | Left |Right |   %  |   ^  |   (  |   )  |  [ { |  ] } | \ |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CpsLck|      |      |      |      |      |      |      |      |      |  Up  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Number| Del  |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_Raise] = LAYOUT_planck_grid(
    KC_GRV,  _______, _______, KC_HASH, KC_DLR,      _______, _______, KC_AMPR, KC_ASTR, _______, _______, _______,
    C(KC_M), KC_EXLM, KC_AT,   KC_LEFT, KC_RGHT      KC_PERC, KC_CIRC, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, _______, 
    KC_CAPS, _______, _______, _______, _______,     _______, _______, _______, _______, _______, KC_UP,   _______,
    _______, _______, _______, _______, TG(_Number), KC_DEL,  _______, _______, _______, _______, _______, _______,
), 

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      |   =  |   +  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |QWERTY|      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_Lower] = LAYOUT_planck_grid(
    _______, KC_F1,       KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F5,       KC_F6,   KC_F7,   KC_F8,   _______, _______, KC_EQL, 	KC_PLUS, _______, _______, _______,
    _______, KC_F9,       KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______,
    _______, TG(_QWERTY), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
),

/* Number
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  L1  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_Number] = LAYOUT_planck_grid(
    KC_TILD, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,       KC_9,    KC_0,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, MO(_Raise), _______, _______, _______,
),
/* Ctrl
 * ,-----------------------------------------------------------------------------------.
 * |      |      | Sub  |Super |Refres|Print |      |ZoomOt|ZoomIn|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Select|      |      | Find |      |      | Bold |Udline|Italic|      |      | ******Print Whole Screen                           
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Undo | Redo | Copy |Paste |      |      |MicMut|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |******|      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_Ctrl] = LAYOUT_planck_grid(
    _______, _______, KC_COMM, KC_DOT,  KC_R,    KC_P,    _______, KC_MINS, KC_EQL,  _______, _______, _______,
    _______, KC_A,    _______, _______, KC_F,    _______, _______, KC_B,    KC_U,    KC_I,    _______, _______,
    _______, KC_Z,    KC_Y,    KC_C,    KC_V,    _______, _______, KC_M,    _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_PSCR, _______, _______, _______, _______, _______, _______,
),  
/* QWERTY
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ; : |  ' " |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  , < |  . > |  / ? |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  OS  | Alt  | Tab  |Spc/Lw| - _  |Space |Raise |PrtSc | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,                 KC_T,    KC_Y,    KC_U,       KC_I,    KC_O,    KC_P,    KC_BSPC,
    _______, KC_A,    KC_S,    KC_D,    KC_F,                 KC_G,    KC_H,    KC_J,       KC_K,    KC_L,    KC_SCLN, KC_ENT ,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,                 KC_B,    KC_N,    KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
    _______, KC_LGUI, KC_LALT, KC_TAB,  LT(_Lower, KC_SPC),   KC_MINS, KC_SPC,  MO(_Raise), KC_PSCR, KC_LEFT, KC_DOWN, KC_RGHT
)
};

void encoder_update(bool clockwise) { 
  if(IS_LAYER_ON(_Number)) // Zooming
  {
   if (clockwise) {
        tap_code16(C(KC_PPLS));
    } else {
        tap_code16(C(KC_PMNS));
    }
  }
  else if(IS_LAYER_ON(_Lower)) // History Scrubbing
  {
   if (clockwise) {
        tap_code16(C(KC_Y));
    } else {
        tap_code16(C(KC_Z));
    }
  }
  else if(IS_LAYER_ON(_Raise)) // Letter/Word Scrolling and Selecting
  {
    if (clockwise) {
        tap_code(KC_RGHT);
    } else {
        tap_code(KC_LEFT);
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





