#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../MCAL/GPIO/GPIO_interface.h"

void LED_Init(unsigned char port, unsigned char pin);
void LED_Toggle(unsigned char port, unsigned char pin);

#endif