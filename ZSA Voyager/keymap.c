#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_us_international.h"

enum custom_keycodes {
    RGB_SLD = SAFE_RANGE,
    MAC_MISSION_CONTROL,
    MAC_SPOTLIGHT,
    MAC_LOCK,
    COLEMAK_CONTROL,
    TAB_LEFT,
    TAB_RIGHT,
    APP_CYCLE,
    APP_CYCLE_CONTROL,
    QWERTY_ON,
    QWERTY_OFF,
};

enum voyager_layers {
    COLEMAK,
    QWERTY,
    NAVIGATION,
    NUMBERS,
    MOUSE,
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////LAYOUT
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [COLEMAK] = LAYOUT_voyager(
        KC_ESCAPE,         QWERTY_ON, KC_AUDIO_VOL_UP, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_LALT,             QK_MAGIC_SWAP_LCTL_LGUI, KC_MEH,      KC_PSCR,    KC_HYPR,    QK_MAGIC_UNSWAP_LCTL_LGUI, MAC_SPOTLIGHT,
        KC_LGUI ,            KC_Q,    KC_W,            KC_F,                KC_P,                KC_G,                KC_J,                    KC_L,        KC_U,       KC_Y,       KC_BSPC,                   KC_LALT,
        TAB_LEFT,            KC_A,    KC_R,            KC_S,                KC_T,                KC_D,                KC_H,                    KC_N,        KC_E,       KC_I,       KC_O,                      TAB_RIGHT,
        APP_CYCLE,           KC_Z,    KC_X,            KC_C,                KC_V,                KC_B,                KC_K,                    KC_M,        KC_COMMA,   KC_DOT,     KC_QUOTE,                  APP_CYCLE_CONTROL,
                                                                            KC_LCTL,            KC_LSFT,              LT(NUMBERS, KC_SPACE),   MO(NAVIGATION)
    ),
    [QWERTY] = LAYOUT_voyager(
        KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           QWERTY_OFF,                   KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,
        APP_CYCLE,      KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                         KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT,
        KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                         KC_H,           KC_J,           KC_K,           KC_L,           KC_BSPC,        KC_ENTER,
        KC_LSFT,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                         KC_N,           KC_M,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                        KC_SPACE,       KC_LCTL,                      KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [NAVIGATION] = LAYOUT_voyager(
        KC_F1,          KC_F2,     KC_F3,   KC_F4,   KC_F5,          KC_F6,                                           KC_F7,          KC_F8,         KC_F9,   KC_F10,         KC_F11,    KC_F12,
        KC_TRANSPARENT, KC_ESCAPE, KC_DLR,  KC_HASH, KC_ASTR,        KC_AMPR,                                         KC_HOME,        LCTL(KC_LEFT), KC_UP,   LCTL(KC_RIGHT), KC_BSPC,   KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TAB,    KC_LABK, KC_LPRN, KC_LCBR,        KC_LBRC,                                         KC_END,         KC_LEFT,       KC_DOWN, KC_RIGHT,       KC_ENTER,  KC_TRANSPARENT,
        KC_TRANSPARENT, KC_LALT,   KC_F10,  KC_F11,  KC_F12,         KC_GRAVE,                                        KC_PLUS,        KC_MINUS,      KC_UNDS, KC_EQUAL,       KC_SLASH,  KC_TRANSPARENT,
                                                     KC_TRANSPARENT, KC_TRANSPARENT,                                  KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [NUMBERS] = LAYOUT_voyager(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,               KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,
        KC_TRANSPARENT, KC_ESCAPE,      KC_PERC,        KC_AT,          KC_CIRC,        KC_PIPE,                      KC_MINUS,       KC_7,           KC_8,           KC_9,           KC_BSPC,        KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TAB,         KC_DOT,         KC_COMMA,       KC_SLASH,       KC_ASTR,                      KC_PLUS,        KC_4,           KC_5,           KC_6,           KC_ENTER,       KC_TRANSPARENT,
        KC_TRANSPARENT, KC_LALT,        KC_F5,          KC_F1,          KC_F2,          KC_SPACE,                     KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_0,           KC_TRANSPARENT,
                                                                        KC_TRANSPARENT, KC_TRANSPARENT,               KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [MOUSE] = LAYOUT_voyager(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT,          KC_TRANSPARENT, KC_TRANSPARENT,       KC_TRANSPARENT, KC_TRANSPARENT,       KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_ESCAPE,      KC_MS_WH_LEFT,  KC_MS_WH_UP,    KC_MS_WH_RIGHT,      KC_PAUSE,                KC_MS_BTN5,     LGUI(LCTL(KC_LEFT)),  KC_MS_UP,       LGUI(LCTL(KC_RIGHT)), KC_BSPC,        KC_TRANSPARENT,
        KC_TRANSPARENT, KC_MS_ACCEL2,   KC_MS_ACCEL1,   KC_MS_WH_DOWN,  KC_MS_ACCEL0,        KC_SCROLL_LOCK,          KC_MS_BTN4,     KC_MS_LEFT,           KC_MS_DOWN,     KC_MS_RIGHT,          COLEMAK_CONTROL,KC_TRANSPARENT,
        KC_TRANSPARENT, KC_LCTL,        KC_LGUI,        KC_LALT,        MAC_MISSION_CONTROL, KC_SYSTEM_SLEEP,         MAC_LOCK,       QK_MAGIC_TOGGLE_CTL_GUI, KC_RALT,     KC_RGUI,              KC_ENTER,       KC_TRANSPARENT,
                                                                        COLEMAK_CONTROL,     KC_TRANSPARENT,          KC_MS_BTN1,     KC_MS_BTN2
    ),
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////OVERRIDES
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// COLEMAK
const key_override_t comma_semicolon_key_override =         ko_make_with_layers(MOD_MASK_SHIFT, KC_COMMA,           KC_SEMICOLON, (1 << COLEMAK)); // , ;
const key_override_t comma_s_key_override =                 ko_make_with_layers(MOD_MASK_SHIFT, KC_COMMA,           LSFT(KC_S), (1 << NUMBERS));   // , S
const key_override_t dot_colon_key_override =               ko_make_basic(MOD_MASK_SHIFT, KC_DOT,                   KC_COLON);                     // . :
const key_override_t exclaim_question_key_override =        ko_make_basic(MOD_MASK_SHIFT, KC_EXCLAIM,               KC_QUESTION);                  // ! ?

// NAVIGATION
const key_override_t parend_key_override =                  ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_PAREN,            KC_RIGHT_PAREN);               // ( )
const key_override_t brace_key_override =                   ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_CURLY_BRACE,      KC_RIGHT_CURLY_BRACE);         // { }
const key_override_t bracket_key_override =                 ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_BRACKET,          KC_RIGHT_BRACKET);             // [ ]
const key_override_t abracket_key_override =                ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_ANGLE_BRACKET,    KC_RIGHT_ANGLE_BRACKET);       // < >

const key_override_t ctrl_plus_nokey_key_override =         ko_make_basic(MOD_MASK_CTRL, KC_PLUS,                   KC_NO);
const key_override_t ctrl_minus_nokey_key_override =        ko_make_basic(MOD_MASK_CTRL, KC_KP_MINUS,               KC_NO);
const key_override_t ctrl_underscore_nokey_key_override =   ko_make_basic(MOD_MASK_CTRL, KC_UNDERSCORE,             KC_NO);
const key_override_t ctrl_equals_nokey_key_override =       ko_make_basic(MOD_MASK_CTRL, KC_EQUAL,                  KC_NO);

const key_override_t forwardslash_backslash_key_override =  ko_make_basic(MOD_MASK_SHIFT, KC_SLASH,                 KC_BACKSLASH);                 // / backslash
const key_override_t backspace_delete_key_override =        ko_make_with_layers(MOD_MASK_SHIFT, KC_BSPC,            KC_DEL, (1 << NAVIGATION));    // <- ->

const key_override_t to_bracket_key_override =              ko_make_with_layers(MOD_MASK_CTRL, KC_UP,               RCS(KC_BACKSLASH), (1 << NAVIGATION)); // ctrl(up) jump to bracket
// const key_override_t down_pgdown_key_override =             ko_make_with_layers_and_negmods(MOD_MASK_CTRL, KC_DOWN, KC_PAGE_DOWN, (1 << NAVIGATION), MOD_MASK_ALT); // ctrl(down) page_down


// MOUSE
const key_override_t volumeup_volumedown_key_override =     ko_make_basic(MOD_MASK_SHIFT, KC_AUDIO_VOL_UP,          KC_AUDIO_VOL_DOWN);            // vol-up vol-down
const key_override_t mouse2_mouse3_key_override =           ko_make_with_layers(MOD_MASK_SHIFT, KC_MS_BTN2,         KC_MS_BTN3, (1 << MOUSE));     //


// MEDIA
const key_override_t playpause_stop_key_override =          ko_make_basic(MOD_MASK_SHIFT, KC_MEDIA_PLAY_PAUSE,      KC_MEDIA_STOP);                // play-pause stop
const key_override_t brightness_up_down_key_override =      ko_make_basic(MOD_MASK_SHIFT, KC_BRIGHTNESS_UP,         KC_BRIGHTNESS_DOWN);           // brightness-up brightness-down


const key_override_t **key_overrides = (const key_override_t *[]) {
    // COLEMAK
    &comma_semicolon_key_override,
    &comma_s_key_override,
    &dot_colon_key_override,
    &exclaim_question_key_override,

    // NAVIGATION
    &parend_key_override,
    &brace_key_override,
    &bracket_key_override,
    &abracket_key_override,

    &ctrl_plus_nokey_key_override,
    &ctrl_minus_nokey_key_override,
    &ctrl_underscore_nokey_key_override,
    &ctrl_equals_nokey_key_override,

    &forwardslash_backslash_key_override,
    &backspace_delete_key_override,

    &to_bracket_key_override,
    // &down_pgdown_key_override,

    // MOUSE
    &volumeup_volumedown_key_override,
    &mouse2_mouse3_key_override,

    // MEDIA
    &playpause_stop_key_override,
    &brightness_up_down_key_override,

    NULL
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////COMBOS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


enum combos {
    COMMA_DOT_EXCLAIM,
    SPACE_LAYER,
    CONTROL_SPACE
};

const uint16_t PROGMEM comma_dot_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM space_layer_combo[] = {LT(NUMBERS, KC_SPACE), MO(NAVIGATION), COMBO_END};
const uint16_t PROGMEM control_space_combo[] = {KC_SPACE, KC_LCTL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [COMMA_DOT_EXCLAIM] = COMBO(comma_dot_combo, KC_EXCLAIM),
    [SPACE_LAYER] = COMBO_ACTION(space_layer_combo),
    [CONTROL_SPACE] = COMBO_ACTION(control_space_combo)
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case CONTROL_SPACE:
            if (!layer_state_is(QWERTY)) {
                return false;
            }
    }

    return true;
}

static bool HOLD_KEYS = false;
static uint16_t PREV_KEY = 0;

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case SPACE_LAYER:
            if (pressed) {
                layer_on(MOUSE);
                register_code(KC_ACL1);
            }
            break;

        case CONTROL_SPACE:
            if (pressed) {
                if (HOLD_KEYS) {
                    if (PREV_KEY == KC_W) {
                        unregister_code(KC_LSFT);
                    }
                    unregister_code(PREV_KEY);
                } else {
                    if (PREV_KEY == KC_W) {
                        register_code(KC_LSFT);
                    }
                    register_code(PREV_KEY);
                }

                HOLD_KEYS = !HOLD_KEYS;
            }
            break;
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////RGB
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t coords_to_led_pin(uint8_t row, uint8_t col) {
    uint8_t temp = 0;

    if (row < 4) {
        col--;
    } else if (row == 4) {
        row = 3;
        col = 5;
    } else if (row == 5) {
        row--;
    } else {
        temp += 26;
        row -= 6;
        if (row == 4) {
            row = 3;
            col = 0;
        } else if (row == 5) {
            row--;
            col -= 5;
        }
    }

    return temp + (row * 6) + col;
}

const uint8_t DRIVER_LED_TOTAL = 52;
static uint8_t LAST_KEY = DRIVER_LED_TOTAL;

static uint8_t SWAPPED_GUI_CTRL = 26;
static uint8_t UNSWAPPED_GUI_CTRL = 30;

static uint8_t SWAPPED_QWERTY = 1;
static uint8_t UNSWAPPED_QWERTY = 5;

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][52][3] = {
    [COLEMAK] = { {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255} },

    [NAVIGATION] = { {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255} },

    [NUMBERS] = { {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245} },

    [MOUSE] = { {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204}, {217,218,204} },
};

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {

        bool is_last_key = i == LAST_KEY;

        bool is_swapped_gui_ctrl = keymap_config.swap_lctl_lgui && i == SWAPPED_GUI_CTRL;
        bool is_unswapped_gui_ctrl = !keymap_config.swap_lctl_lgui && i == UNSWAPPED_GUI_CTRL;

        bool is_swapped_qwerty = layer_state_is(QWERTY) && i == SWAPPED_QWERTY;
        bool is_unswapped_qwerty = !layer_state_is(QWERTY) && i == UNSWAPPED_QWERTY;

        if (is_last_key || is_swapped_gui_ctrl || is_swapped_gui_ctrl || is_unswapped_gui_ctrl || is_swapped_qwerty || is_unswapped_qwerty) {
            float f = (float)UINT8_MAX;
            rgb_matrix_set_color(i, f, f, f);
            continue;
        }

        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB rgb = hsv_to_rgb( hsv );
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) { return true; }
    switch (biton32(layer_state)) {
        case COLEMAK:
            set_layer_color(COLEMAK);
            break;
        case NAVIGATION:
            set_layer_color(NAVIGATION);
            break;
        case NUMBERS:
            set_layer_color(NUMBERS);
            break;
        case MOUSE:
            set_layer_color(MOUSE);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE)
                rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return true;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////CUSTOM KEYS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void register_ctrl(void) {
    if (keymap_config.swap_lctl_lgui) {
        register_code(KC_LGUI);
    } else {
        register_code(KC_LCTL);
    }
}

void unregister_ctrl(void) {
    if (keymap_config.swap_lctl_lgui) {
        unregister_code(KC_LGUI);
    } else {
        unregister_code(KC_LCTL);
    }
}

void register_gui(void) {
    if (keymap_config.swap_lctl_lgui) {
        register_code(KC_LCTL);
    } else {
        register_code(KC_LGUI);
    }
}

void unregister_gui(void) {
    if (keymap_config.swap_lctl_lgui) {
        unregister_code(KC_LCTL);
    } else {
        unregister_code(KC_LGUI);
    }
}

static bool COLEMAK_CONTROL_ACTIVE = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // if (
    //     !COLEMAK_CONTROL_ACTIVE &&
    //     get_highest_layer(layer_state) == COLEMAK &&
    //     record->event.key.col == 4 && record->event.key.row == 8
    // ) {
    //     if (record->event.pressed) {
    //         register_code(KC_O);
    //     } else {
    //         unregister_code(KC_O);
    //     }
    //     return true;
    // }

    if (!(record->event.pressed)) {
        if (COLEMAK_CONTROL_ACTIVE) {
            if (record->event.key.col == 0 && record->event.key.row == 5) { // KC_CTRL
                unregister_ctrl();
                clear_mods();
                COLEMAK_CONTROL_ACTIVE = false;

            }
            if (record->event.key.col == 4 && record->event.key.row == 8) { // KC_O
                unregister_ctrl();
                clear_mods();
                COLEMAK_CONTROL_ACTIVE = false;
            }
        }
        return true;
    }

    if (layer_state_is(QWERTY)) {
        if (HOLD_KEYS) {
            if (PREV_KEY == KC_W) {
                unregister_code(KC_LSFT);
            }
            unregister_code(PREV_KEY);
            HOLD_KEYS = false;
        } else {
            PREV_KEY = keycode;
        }
    }

    switch (keycode) {
        case MAC_MISSION_CONTROL:
            HCS(0x29F);
            break;
        case MAC_SPOTLIGHT:
            layer_off(MOUSE);
            HCS(0x221);
            break;
        case MAC_LOCK:
            HCS(0x19E);
            break;

        case COLEMAK_CONTROL:
            layer_off(MOUSE);
            register_ctrl();
            COLEMAK_CONTROL_ACTIVE = true;

            return false;
            break;

        case QWERTY_ON:
            layer_on(QWERTY);
            return false;

            break;

        case QWERTY_OFF:
            layer_off(QWERTY);

            break;

        case TAB_LEFT:
            if (get_mods() == (MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT))) {
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);

                register_code(KC_ENTER);
                unregister_code(KC_ENTER);
                
                register_code(KC_LCTL);
                register_code(KC_LSFT);
            } else {
                register_code(KC_LALT);
                register_code(KC_PGUP);

                unregister_code(KC_LALT);
                unregister_code(KC_PGUP);
            }

            break;

        case TAB_RIGHT:
            register_code(KC_LALT);
            register_code(KC_PGDN);

            unregister_code(KC_LALT);
            unregister_code(KC_PGDN);

            break;

        case APP_CYCLE:
            register_code(KC_LALT);
            register_code(KC_TAB);

            unregister_code(KC_TAB);
            unregister_code(KC_LALT);

            break;

        case APP_CYCLE_CONTROL:
            register_code(KC_LCTL);
            register_code(KC_TAB);

            unregister_code(KC_TAB);
            unregister_code(KC_LCTL);

            break;
    }

    LAST_KEY = coords_to_led_pin(record->event.key.row, record->event.key.col);

    return true;
}