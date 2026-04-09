#ifndef SWITCH_H
#define SWITCH_H


typedef enum {
    SWITCH_PIN_0 = 0,
    SWITCH_PIN_1 = 1,
    SWITCH_PIN_2 = 2,
    SWITCH_PIN_3 = 3,
    SWITCH_PIN_4 = 4,
    SWITCH_PIN_5 = 5,
    SWITCH_PIN_6 = 6,
    SWITCH_PIN_7 = 7
} Switch_PinID_t;


void SWITCH_Init(Switch_PinID_t pin);

#endif