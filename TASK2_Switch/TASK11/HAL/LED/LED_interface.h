
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "LED_interface.h"   // for LED.c only
#include "../../MCAL/GPIO/GPIO_interface.h"  // for LED.c only

#define LED1 1
#define LED2 2

/* LED functions */
void LED_Init(void);
void LED_On(u8 led);
void LED_Off(u8 led);
void LED_Toggle(u8 led);  // optional

#endif
