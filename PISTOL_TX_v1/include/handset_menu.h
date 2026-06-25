#ifndef HANDSET_MENU_H
#define HANDSET_MENU_H

#include <stdint.h>

typedef enum {
    SCREEN_MAIN = 0,
    SCREEN_ELRS = 1,
    SCREEN_TRIM = 2,
    SCREEN_COUNT = 3
} handset_screen_t;

#define MENU_BLINK_MS 500

void menu_blink_reset(void);
uint8_t menu_blink_tick(unsigned long now);
uint8_t menu_line_inverted(uint8_t is_selected, uint8_t is_edit_mode);

#define EEPROM_PROTOCOL_ADDR 5
#define EEPROM_MIXER_ADDR 12
#define EEPROM_BUZZER_ADDR 14
#define EEPROM_LEDS_ADDR 15

void handset_main_enter(void);
void handset_main_draw(void);
void handset_main_handle_btn(uint8_t btn);
uint8_t handset_main_edit_mode(void);

void handset_trim_enter(void);
void handset_trim_draw(void);
void handset_trim_handle_btn(uint8_t btn);
uint8_t handset_trim_edit_mode(void);

#endif
