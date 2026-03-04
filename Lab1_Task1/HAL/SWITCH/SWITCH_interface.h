#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "../../Services/std_types.h"

/* Switch state (active LOW = button connects pin to GND) */
#define SWITCH_PRESSED      0
#define SWITCH_RELEASED     1

/* Function Prototypes */
void   SWITCH_Init(uint8 port, uint8 pin);
uint8  SWITCH_Read(uint8 port, uint8 pin);

#endif /* SWITCH_INTERFACE_H */
