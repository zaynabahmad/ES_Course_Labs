#ifndef TMR0_INTERFACE_H
#define TMR0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void TMR0_Init(void);
void TMR0_Enable(void);
void TMR0_Disable(void);
void TMR0_SetCallback(void (*ptr)(void));

#endif