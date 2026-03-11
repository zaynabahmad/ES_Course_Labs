#ifndef LED_H
#define LED_H

#include "../../SERVICES/STD_TYPES.h"

typedef struct {
    uint8 port;   // 1 = PORTB
    uint8 pin;    // 1 = RB1, 2 = RB2
} Led_t;

void LED_Init(Led_t *led);
void LED_Toggle(Led_t *led);

#endif