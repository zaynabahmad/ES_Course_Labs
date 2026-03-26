#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

typedef enum
{
    SWITCH_RELEASED = 0,
    SWITCH_PRESSED = 1
}Switch_State_t;

typedef enum
{
    SWITCH_ACTIVE_LOW = 0,
    SWITCH_ACTIVE_HIGH = 1
}Switch_Connection_t;

typedef struct
{
    u8 Port;
    u8 Pin;
    Switch_Connection_t ConnectionType;
}Switch_t;

void SWITCH_Init(const Switch_t* sw);
Switch_State_t SWITCH_GetState(const Switch_t* sw);

#endif