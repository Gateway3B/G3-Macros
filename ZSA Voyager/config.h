/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define USB_SUSPEND_WAKEUP_DELAY 0
#define IGNORE_MOD_TAP_INTERRUPT
#define FIRMWARE_VERSION u8"dAA/M7l"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT
#define COMBO_COUNT 2

#define RGB_MATRIX_STARTUP_SPD 60

#undef MK_3_SPEED
#define MK_3_SPEED

#define MK_C_OFFSET_2 52
#define MK_C_OFFSET_1 16
#define MK_C_OFFSET_0 6

#define MK_W_INTERVAL_1 40
#define MK_W_INTERVAL_0 40

#define HCS(report) host_consumer_send(record->event.pressed ? report : 0); return false
