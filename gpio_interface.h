#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "../../Services/std_types.h"
#include "gpio_private.h"

#define GPIO_HIGH 1
#define GPIO_LOW  0

#define _PORTA 1
#define _PORTB 2
#define _PORTC 3
#define _PORTD 4
#define _PORTE 5

#define OUTPUT 0
#define INPUT  1

void set_pin_direction(u8 port , u8 pin , u8 direction);
void set_pin_value(u8 port , u8 pin , u8 value);
u8   get_pin_value(u8 port , u8 pin);

#endif