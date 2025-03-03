#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRV
#define ES_GRTR_MAC LSFT(KC_GRV)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRV
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

#define C_MAGIC QK_AREP
#define C_GUI_ESC LGUI_T(KC_ESC)
#define C_RSFT_ENT RSFT_T(KC_ENT)
#define C_LALT_ENT LALT_T(KC_ENT)
#define C_RCTL_MINS RCTL_T(KC_MINS)
#define C_LCTL_BSPC LCTL(KC_BSPC)

enum layers {
    BASE,
};

enum custom_keycodes {
  C_MAG_2 = SAFE_RANGE,
  C_MAG_3,
  MK_DUND,
  MG_ENT,
  MG_MENT,
  MG_ER,
  MG_ES,
  MG_UST,
  MG_ON,
  MG_ION,
  MG_OA,
  MG_SP_BUT,
  MG_THE,
  MG_EFORE,
  MG_HICH,
  MG_MLATIV,
  MG_QUOT_S,
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.                                       ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |                                       |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|                                       |------+------+------+------+------+------+--------|
 * |        |   V  |   M  |   L  |   C  |   P  |      |                                       |      |   B  |   󱡄  |   U  |   O  |   Q  |        |
 * |--------+------+------+------+------+------|      |                                       |      |------+------+------+------+------+--------|
 * |        |   S  |   T  |   R  |   D  |   Y  |------|                                       |------|   F  |   N  |   E  |   A  |   I  |        |
 * |--------+------+------+------+------+------|      |                                       |      |------+------+------+------+------+--------|
 * |        |   X  |   K  |   J  |   G  |   W  |      |                                       |      |   Z  |   H  |      |      |      |        |
 * |--------+------+------+------+------+-------------'                                       `-------------+------+------+------+------+--------|
 * |        |      |      |      |      |                                                                   |      |      |      |      |        |
 * `------------------------------------'                                                                   `------------------------------------'
 *                                                    ,--------------.       ,---------------.
 *                                                    |       |      |       |      |        |
 *                                              ,-----+-------+------|       ,------+--------+-------.
 *                                              |     |       |      |       |      |        |       |
 *                                              |  󱁐  |   󰁮   |------|       |------|   󰌒    |      |
 *                                              |     |       |      |       |      |        |       |
 *                                              `--------------------'       `-----------------------'
 */

[BASE] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,    KC_V, KC_M   , KC_L   , KC_C   , KC_P   , KC_TRNS,                                         KC_TRNS, KC_B   , C_MAGIC, KC_U   , KC_O   , KC_Q   , KC_TRNS,
  KC_TRNS,    KC_S, KC_T   , KC_R   , KC_D   , KC_Y   ,                                                           KC_F   , KC_N   , KC_E   , KC_A   , KC_I   , KC_TRNS,
  KC_TRNS,    KC_X, KC_K   , KC_J   , KC_G   , KC_W   , KC_TRNS,                                         KC_TRNS, KC_Z   , KC_H   , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,
                                                                         KC_TRNS,      KC_TRNS,
                                                        KC_SPC, KC_BSPC, KC_TRNS,      KC_TRNS, KC_ENT, QK_REP
),
};
// clang-format on

const uint16_t PROGMEM combo_LTEST_12[] = { KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo_RT_12[] = { QK_REP, OSM(MOD_LSFT), COMBO_END};
const uint16_t PROGMEM combo_LB_IM[] = { KC_J, KC_G, COMBO_END};
const uint16_t PROGMEM combo_LB_MR[] = { KC_K, KC_J, COMBO_END};
const uint16_t PROGMEM combo_LB_RP[] = { KC_X, KC_K, COMBO_END};
const uint16_t PROGMEM combo_LB_IR[] = { KC_K, KC_G, COMBO_END};
const uint16_t PROGMEM combo_RB_IM[] = { KC_H, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_RB_MR[] = { KC_QUOT, KC_QUES, COMBO_END};
const uint16_t PROGMEM combo_RB_RP[] = { KC_QUES, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_RB_IR[] = { KC_H, KC_QUES, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_RT_12, KC_E),
    COMBO(combo_LB_IM, KC_COLN),
    COMBO(combo_LB_MR, C_MAG_2),
    COMBO(combo_LB_RP, C_MAG_3),
    COMBO(combo_LB_IR, MG_QUOT_S),
    COMBO(combo_RB_IM, KC_SCLN),
    COMBO(combo_RB_MR, C_MAG_2),
    COMBO(combo_RB_RP, C_MAG_3),
    COMBO(combo_RB_IR, MG_QUOT_S),
};


// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
   //placeholder
};

bool get_repeat_key_eligible_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
    switch (keycode) {
        // Ignore Custom Magic Keys
        case C_MAG_2:
        case C_MAG_3:
            return false;
        case KC_A ... KC_Z:
            if ((*remembered_mods & ~(MOD_MASK_SHIFT)) == 0) {
                *remembered_mods &= ~MOD_MASK_SHIFT;
            }
            break;
    }

    return true;
}


uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_C:
        case KC_P:
        case KC_D:
        case KC_G:
        case KC_Z: return KC_Y;
        case KC_Y: return KC_P;
        case KC_R: return KC_L;
        case KC_K: return KC_S;
        case KC_L:
        case KC_S: return KC_K;
        case KC_U: return KC_E;
        case KC_E: return KC_U;
        case KC_O: return KC_A;
        case KC_A: return KC_O;
        case KC_DOT:
            if (mods & MOD_MASK_SHIFT) {
                return KC_EQL;
            } else {
                return KC_BSLS;
            }
        case KC_COMM:
            if (mods & MOD_MASK_SHIFT) {
                return KC_EQL;
            } else {
                return MG_SP_BUT;
            }
        case KC_EQL:
        case C_RCTL_MINS:
        case KC_MINS: return KC_RABK;
        case KC_Q: return MG_MLATIV;
        case KC_H: return MG_OA;
        case KC_I: return MG_ON;
        case KC_N: return MG_ION;
        case KC_V: return MG_ER;
        case KC_X: return MG_ES;
        case KC_M: return MG_ENT;
        case KC_T: return MG_MENT;
        case KC_J: return MG_UST;
        case KC_B: return MG_EFORE;
        case KC_W: return MG_HICH;
        case KC_1 ... KC_0: return KC_DOT;
    }

    return MG_THE;
}

bool process_magic_key_2(uint16_t prev_keycode, uint8_t prev_mods) {
    switch (prev_keycode) {
        case KC_B:
            SEND_STRING("ecome");
            return false;
        case KC_F:
            SEND_STRING("ollow");
            return false;
        case KC_N:
            SEND_STRING("eighbor");
            return false;
        case KC_H:
            SEND_STRING("owever");
            return false;
        case KC_U:
            SEND_STRING("pgrade");
            return false;
        case KC_O:
            SEND_STRING("ther");
            return false;
        case KC_A:
            SEND_STRING("lready");
            return false;
        case KC_P:
            SEND_STRING("sych");
            return false;
        case KC_I:
            SEND_STRING("'ll");
            return false;
        case KC_K:
            SEND_STRING("now");
            return false;
        case KC_T:
            SEND_STRING("hough");
            return false;
        case KC_L:
            SEND_STRING("ittle");
            return false;
        case KC_M:
        case KC_R:
            SEND_STRING("ight");
            return false;
        case KC_J:
            SEND_STRING("udge");
            return false;
        case KC_C:
            SEND_STRING("ould");
            return false;
        case KC_D:
            SEND_STRING("evelop");
            return false;
        case KC_G:
            SEND_STRING("eneral");
            return false;
        case KC_W:
            SEND_STRING("here");
            return false;
        case KC_S:
            SEND_STRING("hould");
            return false;
        case KC_DOT:
            SEND_STRING("org");
            return false;
        case KC_COMM:
            SEND_STRING(" however");
            return false;
        default:
            SEND_STRING("'ll");
            return false;
    }
}

bool process_magic_key_3(uint16_t prev_keycode, uint8_t prev_mods) {
    switch (prev_keycode) {
        case KC_B:
            SEND_STRING("etween");
            return false;
        case KC_N:
            SEND_STRING("umber");
            return false;
        case KC_U:
            SEND_STRING("pdate");
            return false;
        case KC_A:
            SEND_STRING("bout");
            return false;
        case KC_W:
            SEND_STRING("orld");
            return false;
        case KC_G:
            SEND_STRING("overn");
            return false;
        case KC_P:
            SEND_STRING("rogram");
            return false;
        case KC_Q:
            SEND_STRING("uestion");
            return false;
        case KC_C:
            SEND_STRING("rowd");
            return false;
        case KC_S:
            SEND_STRING("chool");
            return false;
        case KC_T:
            SEND_STRING("hrough");
            return false;
        case KC_M:
            SEND_STRING("anage");
            return false;
        case KC_O:
            SEND_STRING("xygen");
            return false;
        case KC_I:
            SEND_STRING("'m");
            return false;
        case KC_E:
            SEND_STRING("'re");
            return false;
        case KC_DOT:
            SEND_STRING("com");
            return false;
        case KC_COMM:
            SEND_STRING(" since");
            return false;
        default:
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        int rep_count = get_repeat_key_count();
        if (rep_count < -1 && keycode != MG_UST) {
            send_char('n');
            return false;
        }
        switch (keycode) {
            case C_MAG_2:
                return process_magic_key_2(QK_REP, get_last_mods());
            case C_MAG_3:
                return process_magic_key_3(QK_REP, get_last_mods());
            case MK_DUND:
                SEND_STRING(SS_LSFT(SS_TAP(X_4)) SS_DELAY(100) SS_LSFT(SS_TAP(X_MINUS)));
                return false;
            case MG_ENT:
                SEND_STRING("ent");
                return false;
            case MG_MENT:
                SEND_STRING("ment");
                return false;
            case MG_ER:
                SEND_STRING("er");
                return false;
            case MG_ES:
                SEND_STRING("es");
                return false;
            case MG_UST:
                if (rep_count < -1) {
                    SEND_STRING("ment");
                } else {
                    SEND_STRING("ust");
                }
                return false;
            case MG_OA:
                SEND_STRING("oa");
                return false;
            case MG_ON:
                SEND_STRING("on");
                return false;
            case MG_ION:
                SEND_STRING("ion");
                return false;
            case MG_SP_BUT:
                SEND_STRING(" but");
                return false;
            case MG_THE:
                SEND_STRING("the");
                return false;
            case MG_EFORE:
                SEND_STRING("efore");
                return false;
            case MG_HICH:
                SEND_STRING("hich");
                return false;
            case MG_MLATIV:
                SEND_STRING("mlativ");
                return false;
            case MG_QUOT_S:
                SEND_STRING("'s");
                return false;
        }

        if (rep_count > 0) {
            switch (keycode) {
                case KC_BSPC:
                case C_LCTL_BSPC:
                case KC_DQUO:
                case KC_LPRN:
                case KC_SPC:
                case KC_ENT:
                case C_LALT_ENT:
                case C_RSFT_ENT:
                    unregister_weak_mods(MOD_MASK_CSAG);
                    SEND_STRING("for");
                    return false;
                case KC_I:
                    unregister_weak_mods(MOD_MASK_CSAG);
                    SEND_STRING("ng");
                    return false;
                case KC_DOT:
                case KC_QUES:
                case KC_EXLM:
                case KC_COLN:
                case KC_SCLN:
                    unregister_weak_mods(MOD_MASK_CSAG);
                    send_char(' ');
                    add_oneshot_mods(MOD_MASK_SHIFT);
                    set_last_keycode(KC_SPC);
                    return false;
                case KC_COMM:
                    unregister_weak_mods(MOD_MASK_CSAG);
                    SEND_STRING(" and");
                    return false;
                case KC_A:
                    unregister_weak_mods(MOD_MASK_CSAG);
                    SEND_STRING("nd");
                    return false;
                case KC_N:
                    unregister_weak_mods(MOD_MASK_CSAG);
                    send_char('f');
                    return false;
                case KC_B:
                    unregister_weak_mods(MOD_MASK_CSAG);
                    SEND_STRING("ecause");
                    return false;
                case KC_W:
                    unregister_weak_mods(MOD_MASK_CSAG);
                    SEND_STRING("ould");
                    return false;
                case KC_Y:
                    unregister_weak_mods(MOD_MASK_CSAG);
                    if (rep_count > 2) {
                        SEND_STRING("ll");
                        return false;
                    }
                    if (rep_count > 1) {
                        send_char('\'');
                        return false;
                    }
                    SEND_STRING("ou");
                    return false;
            }
        }
    }
    return true;
}
