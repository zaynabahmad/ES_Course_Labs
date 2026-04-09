#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* LED States */
#define LED_OFF 0
#define LED_ON  1

/* LED Connection Types */
#define LED_ACTIVE_HIGH 0   /* LED Anode to Pin, Cathode to GND */
#define LED_ACTIVE_LOW  1   /* LED Cathode to Pin, Anode to VCC */


/* Function Prototypes */
void LED_Init(u8 Port, u8 Pin, u8 ConnectionType);
void LED_On(u8 Port, u8 Pin, u8 ConnectionType);
void LED_Off(u8 Port, u8 Pin, u8 ConnectionType);
void LED_Toggle(u8 Port, u8 Pin);

#endif