#ifndef LED_H
#define LED_H
#include "../../SERVICES/STD_TYPES.h"
void LED_Init(uint8 pin);
void LED_On(uint8 pin);
void LED_Off(uint8 pin);
void LED_Toggle(uint8 pin);

#endif
