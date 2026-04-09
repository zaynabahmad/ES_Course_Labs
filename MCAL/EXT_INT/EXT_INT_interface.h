#ifndef EXT_INT_INTERFACE_H
#define EXT_INT_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* External Interrupt functions */
void EXT_INT0_Init(void);
void EXT_INT0_Enable(void);
void EXT_INT0_SetCallback(void (*LocalPtr)(void));


void TMR0_Init(void);
void TMR0_Enable(void);
void TMR0_SetCallback(void (*LocalPtr)(void));

#endif