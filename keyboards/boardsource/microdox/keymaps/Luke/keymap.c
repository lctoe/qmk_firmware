/*
Copyright 2020 Cole Smith <cole@boadsource.xyz>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
    _Base,
    _Raise,
    _Lower,
    _Game,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base Layer
 * ,----------------------------------.				,----------------------------------.
 * |  ' " |  , < |  . > |   P  |   Y  |				|   F  |   G  |   C  |   R  |   L  |
 * |------+------+------+------+------|				|------+------+------+------+------|
 * |   A  |   O  |   E  |   U  |   I  |				|   D  |   H  |   T  |   N  |   S  |
 * |------+------+------+------+------|				|------+------+------+------+------|
 * |  ; : |   Q  |   J  |   K  |   X  |				|   B  |   M  |   W  |   V  |   Z  |
 * `-------------+------+------+------|				|------+------+------+-------------'
 * 				       | Mute |OS/Lwr|BS/Ctl|				|Sp/Sft| Raise| Game |
 *				       `--------------------'				`--------------------'
 */
[_Base] = LAYOUT_split_3x5_3(
  KC_QUOT  KC_COMM, KC_DOT,  KC_P,    KC_Y,         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,
  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,         KC_D,    KC_H,    KC_T,    KC_N,    KC_S,
  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
  KC_MUTE, LT(_Lower, KC_LGUI), LT(_Ctrl, KC_BSPC), MT(MOD_LSFT,KC_SPC), TT(_Raise), TG(_Game)
),

/* Raise Layer
 * ,----------------------------------.				,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |       |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|				|------+------+------+------+------|
 * |   !  |   @  |   #  |   $  |   %  |       |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|				|------+------+------+------+------|
 * |      |      |      |      |      |       |      |      |      |      |      |
 * `-------------+------+------+------|				|------+------+------+-------------'
 * 				       |Ply/Ps|OS/Lwr|BS/Ctl|       |Sp/Sft| Raise| Game |
 *				       `--------------------'				`--------------------'
 */  
[_Raise] = LAYOUT_split_3x5_3(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    KC_MPLY, _______, _______,      _______, _______, _______,
),

/* Lower Layer
 * ,----------------------------------.				,----------------------------------.
 * | Quit |PrtWSc|Delete|PrtSc |MutCam|				|      |   ?  |   /  |  ` ~ |  \ | |
 * |------+------+------+------+------|				|------+------+------+------+------|
 * |CapsLk|  Tab |  Esc |Enter |MutMic|				|      |   -  |   _  |   =  |   +  |
 * |------+------+------+------+------|				|------+------+------+------+------|
 * |      |      |      |      |      |				|      |   [  |   ]  |   {  |   }  |
 * `-------------+------+------+------|				|------+------+------+-------------'
 * 				       |      |OS/Lwr|BS/Ctl|       |Sp/Sft| Raise| Game |
 *				       `--------------------'				`--------------------'
 */
[_Lower] = LAYOUT_split_3x5_3(
  LALT(KC_F4), C(KC_PSCR), KC_Del,  KC_PSCR, C(KC_E),      XXXXXXX, KC_QUES, KC_SLSH, KC_GRV,  KC_BSLS,
  KC_CAPS,     KC_TAB,     KC_ESC,  KC_ENT,  C(KC_D),      XXXXXXX, KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS,
  XXXXXXX,     XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR,
                           XXXXXXX, _______, _______,      _______, _______, _______,
),

/* Ctrl Layer
 * ,----------------------------------.				,----------------------------------.
 * | Down |  Up  | Left |Right | Find |				|FullSc|ZoomOt|ZoomIn|Print |Super |
 * |------+------+------+------+------|				|------+------+------+------+------|
 * |Select|Refres| Undo | Copy |Paste |				|      | Bold |Udline|Italic| Sub  |
 * |------+------+------+------+------|				|------+------+------+------+------|
 * |      |      |      |      |      |				|      |      |      |      |      |
 * `-------------+------+------+------|				|------+------+------+-------------'
 * 	      			 |      |OS/Lwr|BS/Ctl|       |Sp/Sft| Raise| Game |
 *				       `--------------------'				`--------------------'
 */
[_Ctrl] = LAYOUT_split_3x5_3(
  KC_DOWN, KC_UP,   KC_LEFT, KC_RGHT, C(KC_F),      KC_F11,  C(KC_MINS), C(KC_EQL,) C(KC_P), C(KC_DOT),
  C(KC_A), C(KC_R), C(KC_Z), C(KC_C), C(KC_V),      XXXXXXX, C(KC_B),    C(KC_U),   C(KC_I), C(KC_COMM),
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,    XXXXXXX,   XXXXXXX, XXXXXXX,    
                    XXXXXXX, _______, _______,      _______, _______, _______,
),

/* Game Layer
 * ,----------------------------------.       ,----------------------------------.
 * |  Tab |   Q  |   W  |   E  |   R  |       |      |      |      |      |      |
 * |------+------+------+------+------|       |------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |       |      |      |      |  Up  |      |
 * |------+------+------+------+------|       |------+------+------+------+------|
 * | Ctrl |      |      |      |   V  |       |      |      | Left | Down | Right|
 * `-------------+------+------+------|       |------+------+------+-------------'
 *               | Mute |OS/Lwr| Space|       |Sp/Sft| Raise| Game |
 *               `--------------------'       `--------------------'
 */
[_Game] = LAYOUT_split_3x5_3(
  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,       XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,
  KC_LCTL,   XXXXXXX, XXXXXXX, XXXXXXX, KC_V,       XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT,
                    KC_MUTE, _______, KC_SPC,       _______, _______, _______,
)
};

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
    	if(IS_LAYER_ON(_Game)) // Track Scrubbing (Game)
  		{
    		if (clockwise) {
      			tap_code(KC_MNXT);
    		} else {
        		tap_code(KC_MPRV);
   			}
  		}
 		else if(IS_LAYER_ON(_Ctrl)) // History Scrubbing (Ctrl)
 		{
   			if (clockwise) {
        		tap_code16(C(KC_Y));
    		} else {
        		tap_code16(C(KC_Z));
    		}
  		}
 		else if(IS_LAYER_ON(_Raise)) // Word Scrolling (Raise)
  		{
   			if (clockwise) {
        		tap_code16(C(KC_RGHT));
   			} else {
        		tap_code16(C(KC_LEFT));
   			}
  		}
 		else if(IS_LAYER_ON(_Base)) // Volume (Base)
  		{
    		if (clockwise) {
        		tap_code(KC_VOLU);
    		} else {
        		tap_code(KC_VOLD);
    		}
 		}
}

#ifdef OLED_DRIVER_ENABLE
void render_status(void) {
    oled_write_P(PSTR("Layer: "), false);
    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case _Base:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _Raise:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _Lower:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _Ctrl:
            oled_write_P(PSTR("Ctrl\n"), false);
            break;
        case _Game:
            oled_write_P(PSTR("Game\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
}
void render_right(void) {
    oled_write_P(PSTR("Layer: "), false);
    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case _Base:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _Raise:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _Lower:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _Ctrl:
            oled_write_P(PSTR("Ctrl\n"), false);
            break;
        case _Game:
            oled_write_P(PSTR("Game\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
}
#endif

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_right();
    }
}
#endif

