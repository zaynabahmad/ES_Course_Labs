#ifndef BUTTON_H
#define BUTTON_H

#include "../../MCAL/GPIO/GPIO.h"

#define PRESSED     1
#define RELEASED    0

void H_Button_voidInit(u8 copy_u8Port, u8 copy_u8Pin);
u8   H_Button_u8GetValue(u8 copy_u8Port, u8 copy_u8Pin);

#endif