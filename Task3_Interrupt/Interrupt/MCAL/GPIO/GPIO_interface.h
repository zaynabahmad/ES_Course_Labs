#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Ports */
#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
#define GPIO_PORTD 3
#define GPIO_PORTE 4

/* Pin directions */
#define GPIO_INPUT  0
#define GPIO_OUTPUT 1

/* Pin values */
#define GPIO_LOW    0
#define GPIO_HIGH   1

void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8   GPIO_GetPinValue(u8 Port, u8 Pin);

#endif