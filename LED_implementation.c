#include "LED_interface.h"

void LED_ON(u8 port,u8 pin)
{
    set_pin_direction(port,pin,OUTPUT);
    set_pin_value(port,pin,GPIO_HIGH);
}

void LED_OFF(u8 port,u8 pin)
{
    set_pin_direction(port,pin,OUTPUT);
    set_pin_value(port,pin,GPIO_LOW);
}