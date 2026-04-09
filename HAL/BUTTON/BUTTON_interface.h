#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Button states */
#define BUTTON_PRESSED    1
#define BUTTON_RELEASED   0

void BUTTON_Init(u8 Port, u8 Pin);
u8   BUTTON_Read(u8 Port, u8 Pin);

#endif
