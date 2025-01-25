#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default (Magic Strudy Layout)
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.                                               ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |                                               |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|                                               |------+------+------+------+------+------+--------|
 * |        |   V  |   M  |   L  |   C  |   P  |      |                                               |      |   B  |      |   U  |   O  |   Q  |        |
 * |--------+------+------+------+------+------|      |                                               |      |------+------+------+------+------+--------|
 * |        |   S  |   T  |   R  |   D  |   Y  |------|                                               |------|   F  |   N  |   E  |   A  |   I  |        |
 * |--------+------+------+------+------+------|      |                                               |      |------+------+------+------+------+--------|
 * |        |   X  |   K  |   J  |   G  |   W  |      |                                               |      |   Z  |   H  |      |      |      |        |
 * `--------+------+------+------+------+-------------'                                               `-------------+------+------+------+------+--------'
 * |        |      |      |      |      |                                                                           |      |      |      |      |        |
 * `------------------------------------'                                                                           `------------------------------------'
 *                                                            ,--------------.              ,----------------.
 *                                                            |       |      |              |        |       |
 *                                                     ,------+-------+------|       ,------+--------+-------.
 *                                                     |      |       |      |       |      |        |       |
 *                                                     |      | Space |------|       |------|  Tab   | Enter |
 *                                                     |      |       |      |       |      |        |       |
 *                                                     `---------------------'       `-----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,    KC_V, KC_M   , KC_L   , KC_C   , KC_P   , KC_TRNS,                                         KC_TRNS, KC_B   , KC_TRNS  , KC_U   , KC_O   , KC_Q   , KC_TRNS,
  KC_TRNS,    KC_S, KC_T   , KC_R   , KC_D   , KC_Y   ,                                                           KC_F   , KC_N   , KC_E   , KC_A   , KC_I   , KC_TRNS,
  KC_TRNS,    KC_X, KC_K   , KC_J   , KC_G   , KC_W   , KC_TRNS,                                         KC_TRNS, KC_Z   , KC_H   , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                 KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,
                                                                          KC_TRNS,      KC_TRNS,
                                                        KC_TRNS, KC_SPC , KC_TRNS,      KC_TRNS, KC_TAB, KC_ENT
),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
