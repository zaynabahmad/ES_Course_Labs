#ifndef _LED_INTERFACE_H
#define _LED_INTERFACE_H

#include "../../SERVICES/std_types.h"
#include "../../MCAL/GPIO/gpio_interface.h"

void LED_Init(u8 port, u8 pin);
void LED_ON(u8 port, u8 pin);   
void LED_OFF(u8 port, u8 pin);
void LED_Toggle(u8 port, u8 pin); 
#endif