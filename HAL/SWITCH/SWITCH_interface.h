#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Switch IDs for easy access */
#define SWITCH_1    1
#define SWITCH_2    2

/* Switch States */
#define SWITCH_PRESSED      1
#define SWITCH_NOT_PRESSED  0

void SWITCH_voidInit(u8 Copy_u8SwitchId);
u8 SWITCH_u8GetState(u8 Copy_u8SwitchId);


u8 SW2_Read(void);

#endif