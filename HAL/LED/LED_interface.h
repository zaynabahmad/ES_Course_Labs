#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

/* MUST include std_types first so the compiler knows what 'u8' is */
#include "../../SERVICES/std_types.h"

#define LED0    0
#define LED1    1

void LED_voidInit(u8 copy_u8Led);
void LED_voidOn(u8 copy_u8Led);
void LED_voidOff(u8 copy_u8Led);
void LED_voidToggle(u8 copy_u8Led);

#endif