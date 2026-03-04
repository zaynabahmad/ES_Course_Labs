#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void switchInit(u8 port, u8 pin);
u8 switchGetState(u8 port, u8 pin);

#endif