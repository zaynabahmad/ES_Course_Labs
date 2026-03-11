#ifndef LED_H
#define LED_H

#include "D:\Timer-week3/SERVICES/STD_TYPES.h"

void LED_Init(u8 Port, u8 Pin);
void LED_On(u8 Port, u8 Pin);
void LED_Off(u8 Port, u8 Pin);
void LED_Toggle(u8 Port, u8 Pin);

#endif