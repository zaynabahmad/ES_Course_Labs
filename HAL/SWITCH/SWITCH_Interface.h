#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Switch logic — active LOW (button pulls to GND, internal pull-up assumed) */
#define SWITCH_PRESSED 0
#define SWITCH_RELEASED 1

void SWITCH_Init(u8 Port, u8 Pin);
u8 SWITCH_Read(u8 Port, u8 Pin);

extern void Delay_ms(u16 ms);

#endif