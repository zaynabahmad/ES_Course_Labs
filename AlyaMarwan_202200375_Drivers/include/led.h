#ifndef LED_H
#define LED_H

#include "std_types.h"
#include "gpio.h"

#define LED_PORT    GPIO_PORTD
#define LED_PIN     GPIO_PIN0

void LED_Init(void);
void LED_On(void);
void LED_Off(void);
void LED_Toggle(void);

#endif