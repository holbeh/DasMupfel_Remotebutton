#ifndef __SHELLY_H_
#define __SHELLY_H_


extern HTTPClient* http;


typedef enum {
BUTTON_LED_BAR_RIGHT = 17,
BUTTON_LED_BAR_BACK = 23,
BUTTON_CEILING_LED_1 = 34,
BUTTON_HEATER_START = 35,
} button_t;

typedef enum {
SHELLY_U_HEATING_1 = 138,
SHELLY_U_HEATING_2 = 102,
SHELLY_HEATER,
SHELLY_H20_PUMP,
SHELLY_CEILING_LED_B,
SHELLY_CEILING_LED_3,
SHELLY_CEILING_LED_2,
SHELLY_CEILING_LED_1,
SHELLY_LED_BAR_BACK,
SHELLY_LED_BAR_RIGHT,
} shelly_address_t;

inline shelly_address_t button_find_shelly(button_t button) {
    switch (button) {
        case BUTTON_LED_BAR_RIGHT: return SHELLY_LED_BAR_RIGHT;
        case BUTTON_LED_BAR_BACK: return SHELLY_LED_BAR_BACK;
        case BUTTON_CEILING_LED_1: return SHELLY_CEILING_LED_1;
        case BUTTON_HEATER_START: return SHELLY_HEATER;
    }
}

int toggle_shelly(shelly_address_t shelly);

#endif // __SHELLY_H_
