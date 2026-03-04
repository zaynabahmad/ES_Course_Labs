#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../Services/std_types.h"

/* LED State */
#define LED_ON      1
#define LED_OFF     0

/* Function Prototypes */
void LED_Init(uint8 port, uint8 pin);
void LED_On(uint8 port, uint8 pin);
void LED_Off(uint8 port, uint8 pin);
void LED_Toggle(uint8 port, uint8 pin);

#endif /* LED_INTERFACE_H */
