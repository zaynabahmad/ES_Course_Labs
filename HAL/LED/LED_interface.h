#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* LED States */
#define LED_OFF    0
#define LED_ON     1

void LED_Init(uint8 Port, uint8 Pin);
void LED_On(uint8 Port, uint8 Pin);
void LED_Off(uint8 Port, uint8 Pin);
void LED_Toggle(uint8 Port, uint8 Pin);

#endif