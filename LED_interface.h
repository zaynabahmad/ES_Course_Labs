#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../MCAL/GPIO/gpio_interface.h"

void LED_ON(u8 port,u8 pin);
void LED_OFF(u8 port,u8 pin);

#endif