#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* PORT IDs */
#define GPIO_PORTA   0
#define GPIO_PORTB   1
#define GPIO_PORTC   2
#define GPIO_PORTD   3
#define GPIO_PORTE   4

/* PIN DIRECTION */
#define GPIO_INPUT   1
#define GPIO_OUTPUT  0

/* PIN VALUE */
#define GPIO_LOW     0
#define GPIO_HIGH    1

void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8   GPIO_GetPinValue(u8 Port, u8 Pin);
void GPIO_TogglePin(u8 Port, u8 Pin);

#endif