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
  _Function,
  _Ctrl,
  _QWERTY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// This keymap is designed to move most common functions and actions to your fingers, as opposed to having to move your fingers to the keys, like on a larger board. However, some functions, like Shift and Ctrl, are not relocated for the sake of muscle memory.

// LAYERS:
// L0 is the default layer.
// Raise is accessed when the Raise key is being held.
// Lower is accessed when the Lower key is being held, and can alternatively be toggled by tapping the Lower key once.
// The Function layer is accessed when the Function key is being held.
// The Ctrl layer is accessed when the Ctrl key is being held.
// The QWERTY layer is toggled by tapping the QWERTY key once.

// NOTES:
// The Ctrl key is NOT an actual Ctrl key, but rather a momentary layer switch. This allows for you to still copy and paste (among other things) using the left hand, which is not possible in Dvorak. 
	// (Most) keys used on the Ctrl layer are in their QWERTY locations.
// The right thumb is meant to hover or rest over the space key, while the left thumb is meant to hover over the backspace key.
// There is a rotary encoder in the top left. Both the function of the encoder being rotated, and the encoder being pressed, vary based on what layer you are on.
// The Lower key on the QWERTY layer acts as space upon tapping it once so the left hand can sit comfortably while gaming and still jump while in a resting position. 
	//This is exclusive to me, after I observed that when in games, my thumb presses the space bar under the "U" key
// Ctrl + D as a mic muting function is a keybind set in discord; it is not universal for the rest of the computer.
	// "D" is chosen as the key because it is the unchangeable keybind for mute in Google Meets, which I will be using heavily during high school and a pandemic :(
	//Ctrl + E is the unchangeable keybind for camera on/off in Google Meets, hence its function being listed as "MutVid"
// The reason many keycodes or functions are on specific spaces on layers rather than everything being on the lowest layer possible is because it is designed that way.
	// For example, it wouldn't make sense to put Print Screen next to Delet on the Raise layer just because that space is open on Raise. 
	// The reason it doesn't make sense is because it is designed so if you are going to press a key with your right hand (i.e. Print Screen), then it wouldn't make sense to have that layer's key ALSO on the right hand. 
	// That's why you hold Raise with your left hand and press Delete with your left hand, or you hold Lower with your left hand and press Print Screen with your right hand.
	// This concept of hand alternation is applied all over the keyboard, from things like the rotary encoder, to niche things like Delete and Print Screen.
	
/* L0
 * ,-----------------------------------------------------------------------------------.
 * |Ply/Ps|  ' " |  , < |  . > |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  / ? |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Esc |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   :  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | - _  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  OS  | Tab  |QWERTY|Lower | Bksp |Space |Raise |  Fn  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_L0] = LAYOUT_planck_grid(
    KC_MPLY,             KC_QUOT, KC_COMM, KC_DOT,      KC_P,        KC_Y,    KC_F,    KC_G,       KC_C,        KC_R,    KC_L,    KC_SLSH,
    KC_ESC,              KC_A,    KC_O,    KC_E,        KC_U,        KC_I,    KC_D,    KC_H,       KC_T,        KC_N,    KC_S,    KC_ENT ,
    KC_LSFT,             KC_SCLN, KC_Q,    KC_J,        KC_K,        KC_X,    KC_B,    KC_M,       KC_W,        KC_V,    KC_Z,    KC_MINS,
    LM(_Ctrl, MOD_LCTL), KC_LGUI, KC_TAB,  TG(_QWERTY), TT(_Lower),  KC_BSPC, KC_SPC,  MO(_Raise), MO(_Function), KC_LEFT, KC_DOWN, KC_RGHT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Mute | ` ~  |      |      |      |      |      |      |      |  [ { |  ] } | \ |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CpsLck|      |      |      |      |      |      |      |      |      |      |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Del  |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_Raise] = LAYOUT_planck_grid(
    KC_MUTE, KC_GRV,  _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, 
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_EQL,
    _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______
), 

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |  Up  |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |PrtScn|      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_Lower] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   KC_PLUS,
    _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______, _______, _______, _______
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |MutOut|  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_Function] = LAYOUT_planck_grid(
    C(KC_D), KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/* Ctrl
 * ,-----------------------------------------------------------------------------------.
 * |      |      | Sub  |Super |Refres|Print |      |ZoomOt|ZoomIn|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Select|      |MutVid| Find |      |      | Bold |Udline|Italic|      |      | ******Print Whole Screen                           
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Undo | Redo | Copy |Paste |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |******|      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_Ctrl] = LAYOUT_planck_grid(
    _______, _______, KC_COMM, KC_DOT,  KC_R,    KC_P,    _______, KC_MINS, KC_EQL,  _______, _______, _______,
    _______, KC_A,    _______, KC_E,    KC_F,    _______, _______, KC_B,    KC_U,    KC_I,    _______, _______,
    _______, KC_Z,    KC_Y,    KC_C,    KC_V,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______, _______, _______, _______
),  
/* QWERTY
 * ,-----------------------------------------------------------------------------------.
 * |Ply/Ps|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ; : |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  , < |  . > |  / ? | ' "  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  OS  | Tab  |QWERTY|Spc/Lw| - _  |Space |Raise |  Fn  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_MPLY, KC_Q,    KC_W,    KC_E,    KC_R,               KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,               KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT ,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,               KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
    _______, KC_LGUI, KC_TAB,  _______, LT(_Lower, KC_SPC), KC_MINS, KC_SPC,  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT
)
};

void encoder_update(bool clockwise) { 
  if(IS_LAYER_ON(_Function)) // Word Scrolling
  {
    if (clockwise) {
        tap_code16(C(KC_RGHT));
    } else {
        tap_code16(C(KC_LEFT));
    }
  }
  else if(IS_LAYER_ON(_Lower)) // Track Scrolling
  {
    if (clockwise) {
        tap_code(KC_MNXT);
    } else {
        tap_code(KC_MPRV);
    }
  }
  else if(IS_LAYER_ON(_Raise)) // History Scrubbing
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


