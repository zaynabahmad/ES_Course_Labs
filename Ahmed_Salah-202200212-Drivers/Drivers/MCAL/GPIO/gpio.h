#ifndef GPIO_H
#define GPIO_H

#include "../../SERVICES/Std_Types.h"

/* Port IDs */
#define PORTA_ID    0
#define PORTB_ID    1
#define PORTC_ID    2
#define PORTD_ID    3
#define PORTE_ID    4

/* Pin IDs */
#define PIN0        0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7

void GPIO_voidSetPinDirection(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8Direction);
void GPIO_voidSetPinValue(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8Value);
u8   GPIO_u8GetPinValue(u8 copy_u8PortID, u8 copy_u8PinID);

#endif