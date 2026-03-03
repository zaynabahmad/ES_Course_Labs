#ifndef BUTTON_H
#define BUTTON_H

#include "GPIO.h"

void Button_Init(unsigned short *tris, unsigned short pin);
unsigned short Button_Read(unsigned short *port, unsigned short pin);

#endif