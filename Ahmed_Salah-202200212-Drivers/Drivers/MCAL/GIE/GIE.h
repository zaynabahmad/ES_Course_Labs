#ifndef GIE_H
#define GIE_H

#include "../../SERVICES/Std_Types.h"

void M_GIE_voidEnable(void);
void M_GIE_voidDisable(void);

/* Allow main.c to see these pointers for the Unified ISR */
extern void (*EXTI_CallBackPtr)(void);
extern void (*Timer0_CallBackPtr)(void);
#endif