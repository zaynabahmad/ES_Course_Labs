#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../MCAL/GPIO/gpio_interface.h"

void LED_Init(unsigned char port1, unsigned char pin1,
              unsigned char port2, unsigned char pin2);

void LED_On(unsigned char port, unsigned char pin);

void LED_Off(unsigned char port, unsigned char pin);

#endif