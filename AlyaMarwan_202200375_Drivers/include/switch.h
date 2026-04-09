#ifndef SWITCH_H
#define SWITCH_H

#include "std_types.h"
#include "gpio.h"

#define SWITCH_PORT     GPIO_PORTB
#define SWITCH_PIN      GPIO_PIN0
#define SWITCH_PRESSED  GPIO_LOW

void  SWITCH_Init(void);
uint8 SWITCH_Read(void);

#endif