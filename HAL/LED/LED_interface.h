#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* LED States */
#define LED_OFF    0
#define LED_ON     1

#define LED0_PORT    GPIO_PORTB
#define LED0_PIN     0

#define LED1_PORT    GPIO_PORTB
#define LED1_PIN     2

#define LED2_PORT    GPIO_PORTC
#define LED2_PIN     0



void LED_Init(u8 Port, u8 Pin);
void LED_On(u8 Port, u8 Pin);
void LED_Off(u8 Port, u8 Pin);
void LED_Toggle(u8 Port, u8 Pin);

#endif