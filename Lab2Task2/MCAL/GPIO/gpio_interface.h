#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "gpio_private.h"
#include <stdbool.h>

void GPIO_Init(void);

void setpindirection(unsigned char port, unsigned char pin, bool direction);

void setpinvalue(unsigned char port, unsigned char pin, bool value);

unsigned char getpinvalue(unsigned char port, unsigned char pin);

#endif