#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H

#include "../SYS/STD_TYPES.h"

void BUTTON_Init(u8 Port, u8 Pin);
u8   BUTTON_IsPressed(u8 Port, u8 Pin);   /* returns 1 if pressed */

#endif