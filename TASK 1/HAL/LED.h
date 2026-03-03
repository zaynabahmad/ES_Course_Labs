#ifndef LED_H
#define LED_H

#include "GPIO.h"

void LED_Init(unsigned short *tris, unsigned short pin);
void LED_On(unsigned short *port, unsigned short pin);
void LED_Off(unsigned short *port, unsigned short pin);

#endif