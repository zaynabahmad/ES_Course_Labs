#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Function Prototypes */
void TIMER0_Init(void);
void TIMER0_EnableInterrupt(void);
void TIMER0_DisableInterrupt(void);

/* Pass the function you want to execute every 1 second here */
void TIMER0_SetCallback(void (*ptr)(void));

#endif /* TIMER0_INTERFACE_H */