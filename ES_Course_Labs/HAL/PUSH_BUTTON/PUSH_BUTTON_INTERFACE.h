#ifndef PUSH_BUTTON_INTERFACE_H
#define PUSH_BUTTON_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* LED States */
#define PUSH_BUTTON_OFF    0
#define PUSH_BUTTON_ON     1

void PUSH_BUTTON_Init(u8 Port, u8 Pin);
unsigned int BUTTON_Read(u8 Port , u8 Pin);

#endif