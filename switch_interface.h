#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "../../SERVICES/types.h"

#define SW_STATE_RELEASED   0
#define SW_STATE_PRESSED    1

void Switch_Setup(u8 port, u8 pin);
u8 Switch_ReadState(u8 port, u8 pin);

#endif