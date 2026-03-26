#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

#define TIMER0_INTERNAL_CLOCK      0
#define TIMER0_EXTERNAL_CLOCK      1

#define TIMER0_PRESCALER_2         0
#define TIMER0_PRESCALER_4         1
#define TIMER0_PRESCALER_8         2
#define TIMER0_PRESCALER_16        3
#define TIMER0_PRESCALER_32        4
#define TIMER0_PRESCALER_64        5
#define TIMER0_PRESCALER_128       6
#define TIMER0_PRESCALER_256       7

void TIMER0_Init(void);
void TIMER0_SetPreload(u8 Copy_u8Value);
void TIMER0_EnableInterrupt(void);
void TIMER0_DisableInterrupt(void);
void TIMER0_SetCallback(void (*ptr)(void));
void TIMER0_HandleInterrupt(void);

#endif