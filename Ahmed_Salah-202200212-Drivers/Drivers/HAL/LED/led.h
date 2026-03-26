#ifndef LED_H
#define LED_H

#include "../../MCAL/GPIO/GPIO.h"

void H_LED_voidInit(u8 copy_u8Port, u8 copy_u8Pin);
void H_LED_voidOn(u8 copy_u8Port, u8 copy_u8Pin);
void H_LED_voidOff(u8 copy_u8Port, u8 copy_u8Pin);
void H_LED_voidToggle(u8 copy_u8Port, u8 copy_u8Pin);

#endif