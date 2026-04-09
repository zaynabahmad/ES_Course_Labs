#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Switch Connection Types */
#define SWITCH_PULL_UP      0   /* Switch connected to Ground (Pressed = LOW) */
#define SWITCH_PULL_DOWN    1   /* Switch connected to VCC (Pressed = HIGH) */

/* Standardized Return States */
#define SWITCH_PRESSED      1
#define SWITCH_RELEASED     0

/* Function Prototypes */
void SWITCH_Init(u8 Port, u8 Pin);

/* Normal Read */
u8 SWITCH_GetState(u8 Port, u8 Pin, u8 ConnectionType);

/* Read with Software Debouncing */
u8 SWITCH_GetStateDebounced(u8 Port, u8 Pin, u8 ConnectionType);

#endif