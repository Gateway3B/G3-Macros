#include QMK_KEYBOARD_H
extern char* keymapstring;

enum ferris_layers {
    COLEMAK,
    NUMBERS,
    NAVIGATION,
    MOUSE,
};

// region Key Overrides
    const key_override_t comma_semicolon_key_override =         ko_make_basic(MOD_MASK_SHIFT, KC_COMMA,                 KC_SEMICOLON);              // , ;
    const key_override_t dot_colon_key_override =               ko_make_basic(MOD_MASK_SHIFT, KC_DOT,                   KC_COLON);                  // . :
    const key_override_t exclaim_question_key_override =        ko_make_basic(MOD_MASK_SHIFT, KC_EXCLAIM,               KC_QUESTION);               // ! ?


    const key_override_t parend_key_override =                  ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_PAREN,            KC_RIGHT_PAREN);            // ( )
    const key_override_t brace_key_override =                   ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_CURLY_BRACE,      KC_RIGHT_CURLY_BRACE);      // { }
    const key_override_t bracket_key_override =                 ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_BRACKET,          KC_RIGHT_BRACKET);          // [ ]
    const key_override_t abracket_key_override =                ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_LEFT_ANGLE_BRACKET,    KC_RIGHT_ANGLE_BRACKET, ~0, MOD_MASK_ALT);    // < >

    const key_override_t dollar_percent_key_override =          ko_make_basic(MOD_MASK_SHIFT, KC_DOLLAR,                KC_PERCENT);                // $ %
    const key_override_t octothorpe_at_key_override =           ko_make_basic(MOD_MASK_SHIFT, KC_HASH,                  KC_AT);                     // # @
    const key_override_t asterisk_carrot_key_override =         ko_make_basic(MOD_MASK_SHIFT, KC_ASTERISK,              KC_CIRCUMFLEX);             // * ^
    const key_override_t ampersand_pipe_key_override =          ko_make_basic(MOD_MASK_SHIFT, KC_AMPERSAND,             KC_PIPE);                   // & |

    const key_override_t volumeup_volumedown_key_override =     ko_make_basic(MOD_MASK_SHIFT, KC_AUDIO_VOL_UP,          KC_AUDIO_VOL_DOWN);         // end pgdown
    const key_override_t f12_f2_key_override =                  ko_make_basic(MOD_MASK_SHIFT, KC_F12,                   KC_F2);                     // F12 F2

    const key_override_t plus_minus_key_override =              ko_make_basic(MOD_MASK_SHIFT, KC_KP_MINUS,              KC_KP_PLUS);                // - +
    const key_override_t equals_underscore_key_override =       ko_make_basic(MOD_MASK_SHIFT, KC_UNDERSCORE,            KC_EQUAL);                  // _ =
    const key_override_t forwardslash_backslash_key_override =  ko_make_basic(MOD_MASK_SHIFT, KC_SLASH,                 KC_BACKSLASH);              // / backslash
    const key_override_t backspace_delete_key_override =        ko_make_with_layers(MOD_MASK_SHIFT, KC_BSPC,            KC_DEL, (1 << NAVIGATION));    // <- ->

    const key_override_t dot_comma_key_override =               ko_make_with_layers(MOD_MASK_CTRL, KC_KP_DOT,           KC_COMMA, (1 << NUMBERS));  // .   ,

    const key_override_t leftspace_key_override =               ko_make_with_layers_and_negmods(0,  KC_LEFT,            LCTL(LGUI(KC_LEFT)), (1 << MOUSE), MOD_MASK_SHIFT);
    const key_override_t rightspace_key_override =              ko_make_with_layers_and_negmods(0,  KC_RIGHT,           LCTL(LGUI(KC_RIGHT)), (1 << MOUSE), MOD_MASK_SHIFT);
    const key_override_t left_tableft_key_override =            ko_make_with_layers(MOD_MASK_SHIFT, KC_LEFT,            LCTL(KC_PAGE_UP), (1 << MOUSE));
    const key_override_t right_tabright_key_override =          ko_make_with_layers(MOD_MASK_SHIFT, KC_RIGHT,           LCTL(KC_PAGE_DOWN), (1 << MOUSE));

    const key_override_t enter_application_key_override =       ko_make_basic(MOD_MASK_ALT, KC_ENTER,                   KC_APPLICATION); // Alt enter combo right clicks

    const key_override_t anglebracket_tabrev_key_override =     ko_make_basic(MOD_MASK_SA, KC_LEFT_ANGLE_BRACKET,       LALT(LSFT(KC_TAB))); // App cycle reverse
    const key_override_t dot_tabrev_key_override =              ko_make_basic(MOD_MASK_SA, KC_DOT,                      LALT(LSFT(KC_TAB))); // App cycle reverse
    const key_override_t anglebracket_tab_key_override =        ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_LEFT_ANGLE_BRACKET,      LALT(KC_TAB), (1 << NAVIGATION), MOD_MASK_SHIFT); // App cycle
    const key_override_t dot_tab_key_override =                 ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_DOT,                     LALT(KC_TAB), (1 << NAVIGATION), MOD_MASK_SHIFT); // App cycle
    
    const key_override_t right_tabright_nav_key_override =      ko_make_with_layers(MOD_MASK_SA, KC_RIGHT,              LCTL(KC_PAGE_DOWN), (1 << NAVIGATION));
    const key_override_t left_tableft_nav_key_override =        ko_make_with_layers(MOD_MASK_SA, KC_LEFT,               LCTL(KC_PAGE_UP), (1 << NAVIGATION));

    const key_override_t **key_overrides = (const key_override_t *[]) {
        &comma_semicolon_key_override,
        &dot_colon_key_override,
        &exclaim_question_key_override,

        &parend_key_override,
        &brace_key_override,
        &bracket_key_override,
        &abracket_key_override,

        &dollar_percent_key_override,
        &octothorpe_at_key_override,
        &asterisk_carrot_key_override,
        &ampersand_pipe_key_override,

        &volumeup_volumedown_key_override,
        &f12_f2_key_override,
        
        &plus_minus_key_override,
        &equals_underscore_key_override,
        &forwardslash_backslash_key_override,
        &backspace_delete_key_override,
        
        &dot_comma_key_override,

        &leftspace_key_override,
        &rightspace_key_override,
        &left_tableft_key_override,
        &right_tabright_key_override,

        &enter_application_key_override,
        
        &anglebracket_tabrev_key_override,
        &dot_tabrev_key_override,
        &anglebracket_tab_key_override,
        &dot_tab_key_override,

        &right_tabright_nav_key_override,
        &left_tableft_nav_key_override,

        NULL
    };

// endregion

// region Tap Dances

    typedef enum {
        TD_NONE,
        TD_UNKNOWN,
        TD_SINGLE_HOLD,
        TD_DOUBLE_TAP
    } td_state_t;

    typedef struct {
        bool is_press_action;
        td_state_t state;
    } td_tap_t;

    enum ferris_tap_dances {
        TD_LCTRL_LGUI,
        TD_LayerNav_LayerMouse
    };

    td_state_t cur_dance(qk_tap_dance_state_t *state);

    void ql_finished(qk_tap_dance_state_t *state, void *user_data);
    void ql_reset(qk_tap_dance_state_t *state, void *user_data);

    td_state_t cur_dance(qk_tap_dance_state_t *state) {
        if (state->count == 1) return TD_SINGLE_HOLD;
        else if (state->count == 2) return TD_DOUBLE_TAP;
        else return TD_UNKNOWN;
    }

    static td_tap_t ql_tap_state = {
        .is_press_action = true,
        .state = TD_NONE
    };

    void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
        ql_tap_state.state = cur_dance(state);
        switch (ql_tap_state.state) {
            case TD_SINGLE_HOLD:
                layer_on(NAVIGATION);
                break;
            case TD_DOUBLE_TAP:
                layer_on(MOUSE);
                break;
            default:
                break;
        }
    }

    void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
        if (ql_tap_state.state == TD_SINGLE_HOLD) {
            layer_off(NAVIGATION);
        }
        ql_tap_state.state = TD_NONE;
    }

    qk_tap_dance_action_t tap_dance_actions[] = {
        [TD_LCTRL_LGUI] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_LGUI),
        [TD_LayerNav_LayerMouse] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset)
    };

// endregion

// region Custom Keycodes

    enum custom_keycodes {
        KEYMAP_STRING = SAFE_RANGE,
        COLEMAK_CTRL
    };

    bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
            case KEYMAP_STRING:
                if (record->event.pressed) {
                    send_string(keymapstring);
                }
                return false;

            case COLEMAK_CTRL:
                if (record->event.pressed) {
                    layer_off(MOUSE);
                    register_code(KC_LCTRL);
                }
        }

        if (record->event.key.col == 0 && record->event.key.row == 3 && !(record->event.pressed)) {
            unregister_code(KC_LCTRL);
            clear_mods();
        }

        return true;
    };

// endregion

// region Combos

    enum combos {
        COMMA_DOT_EXCLAIM,
        KEYMAP_COMBO
    };

    const uint16_t PROGMEM comma_dot_combo[] = {KC_COMMA, KC_DOT};
    const uint16_t PROGMEM keymap_combo[] = {KC_PRINT_SCREEN, KC_PAUSE};

    combo_t key_combos[COMBO_COUNT] = {
        [COMMA_DOT_EXCLAIM] =   COMBO(comma_dot_combo, KC_EXCLAIM),
        [KEYMAP_COMBO] =        COMBO(keymap_combo, KEYMAP_STRING)
    };

// endregion

// region Layers

    /*
        OSM: One Shot Key (https://docs.qmk.fm/#/one_shot_keys)
        TO: Turn On Layer (https://docs.qmk.fm/#/feature_layers)
        MT: Mod-Tap (https://docs.qmk.fm/#/mod_tap)
        TD: Tap-Dance (https://docs.qmk.fm/#/feature_tap_dance)
    */

    const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [COLEMAK] = LAYOUT(
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
            KC_Q, KC_W, KC_F, KC_P, KC_G,                                                               KC_J, KC_L, KC_U, KC_Y, KC_BSPC,
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
            KC_A, KC_R, KC_S, KC_T, KC_D,                                                               KC_H, KC_N, KC_E, KC_I, KC_O,
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
            KC_Z, KC_X, KC_C, KC_V, KC_B,                                                               KC_K, KC_M, KC_COMMA, KC_DOT, LT(NUMBERS, KC_QUOTE),
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
            TD(TD_LCTRL_LGUI), KC_LSFT,                                                                 KC_SPACE, TD(TD_LayerNav_LayerMouse)
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
        ),

        [NUMBERS] = LAYOUT(
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
            KC_ESCAPE, KC_PERCENT, KC_AT, KC_CIRCUMFLEX, KC_PIPE,                                       KC_MINS, KC_7, KC_8, KC_9, KC_BSPC,
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
            KC_TAB, KC_DOT, KC_UNDERSCORE, KC_SLASH, KC_ASTERISK,                                       KC_PLUS, KC_4, KC_5, KC_6, KC_ENTER,
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
            KC_LALT, KC_F3, KC_F1, KC_F2, KC_GRAVE,                                                     KC_EQUAL, KC_1, KC_2, KC_3, KC_TRANSPARENT,
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
            TD(TD_LCTRL_LGUI), KC_LSFT,                                                                 KC_SPACE, KC_0
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
        ),

        [NAVIGATION] = LAYOUT(
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
            KC_ESCAPE, KC_DOLLAR, KC_HASH, KC_ASTERISK, KC_AMPERSAND,                                   KC_HOME, LCTL(KC_LEFT), KC_UP, LCTL(KC_RIGHT), KC_BSPC,
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
            KC_TAB, KC_LEFT_ANGLE_BRACKET, KC_LEFT_PAREN, KC_LEFT_CURLY_BRACE, KC_LEFT_BRACKET,         KC_END, KC_LEFT, KC_DOWN, KC_RIGHT, KC_ENTER,
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
            KC_LALT, KC_F10, KC_F11, KC_F12, KC_GRAVE,                                                  KC_PLUS, KC_KP_MINUS, KC_UNDERSCORE, KC_EQUAL, KC_SLASH,
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
            TD(TD_LCTRL_LGUI), KC_LSFT,                                                                 KC_SPACE, KC_TRANSPARENT
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
        ),

        [MOUSE] = LAYOUT(
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
            KC_ESCAPE, KC_ACL1, KC_MS_WH_UP, KC_ACL2, KC_AUDIO_VOL_UP,                                  KC_MS_BTN5, KC_LEFT, KC_MS_UP, KC_RIGHT, KC_BSPC,
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
            KC_TAB, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_MEDIA_PLAY_PAUSE,                  KC_MS_BTN4, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_ENTER,
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
            KC_LCTRL, KC_LGUI, KC_LALT, KC_PRINT_SCREEN, KC_PAUSE,                                      KC_RALT, KC_RGUI, KC_SCROLL_LOCK, KC_RCTRL, MAGIC_TOGGLE_CTL_GUI,
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
            COLEMAK_CTRL, KC_LSFT,                                                                      KC_MS_BTN1, KC_MS_BTN2
            //---------------------------------------------------------------------------------------   ---------------------------------------------------------------------------------------
        )
    };

// endregion
