#ifndef TIMER_0_INTERFACE_H
#define TIMER_0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "TIMER_0_Private.h"
#include "TIMER_0_Config.h"

#define TIMER0_PRESCALER_2    0
#define TIMER0_PRESCALER_4    1
#define TIMER0_PRESCALER_8    2
#define TIMER0_PRESCALER_16   3
#define TIMER0_PRESCALER_32   4
#define TIMER0_PRESCALER_64   5
#define TIMER0_PRESCALER_128  6
#define TIMER0_PRESCALER_256  7

void TIMER0_Init(u8 Prescaler);
void TIMER0_Start(void);
void TIMER0_Stop(void);
void TIMER0_SetValue(u8 Value);
u8 TIMER0_GetValue(void);
void TIMER0_EnableInterrupt(void);
void TIMER0_DisableInterrupt(void);
void TIMER0_SetCallback(void (*Callback)(void));
void TIMER0_ISR(void);

#endif
