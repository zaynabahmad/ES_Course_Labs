#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

/* Switch States */
#define SWITCH_PRESSED      1
#define SWITCH_RELEASED     0

/* Pull Type */
#define SWITCH_PULL_UP      0
#define SWITCH_PULL_DOWN    1

void SWITCH_Init(u8 Port, u8 Pin);
u8 SWITCH_GetState(u8 Port, u8 Pin, u8 PullType);

#endif
