#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

/* Button states */
#define BUTTON_PRESSED     1
#define BUTTON_RELEASED    0

/* Function prototypes */
void BUTTON_Init(u8 Port, u8 Pin);
u8   BUTTON_GetState(u8 Port, u8 Pin);

#endif