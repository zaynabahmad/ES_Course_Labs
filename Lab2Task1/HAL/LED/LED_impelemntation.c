#include "LED_interface.h"

void LED_Init(unsigned char port1, unsigned char pin1,
              unsigned char port2, unsigned char pin2)
{
    setpindirection(port1, pin1, OUTPUT);
    setpindirection(port2, pin2, OUTPUT);

    setpinvalue(port1, pin1, LOW);
    setpinvalue(port2, pin2, LOW);
}

void LED_On(unsigned char port, unsigned char pin)
{
    setpinvalue(port, pin, HIGH);
}

void LED_Off(unsigned char port, unsigned char pin)
{
    setpinvalue(port, pin, LOW);
}