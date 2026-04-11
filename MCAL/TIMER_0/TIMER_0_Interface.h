#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Modes */
#define TIMER0_TIMER_MODE        0
#define TIMER0_COUNTER_MODE      1

/* Prescaler */
#define TIMER0_PRESCALER_2       0
#define TIMER0_PRESCALER_4       1
#define TIMER0_PRESCALER_8       2
#define TIMER0_PRESCALER_16      3
#define TIMER0_PRESCALER_32      4
#define TIMER0_PRESCALER_64      5
#define TIMER0_PRESCALER_128     6
#define TIMER0_PRESCALER_256     7

void TIMER0_Init(void);
void TIMER0_SetPreload(u8 value);
void TIMER0_Delay_ms(u16 ms);

void TIMER0_SetCallback(void (*Copy_ptr)(void));

#endif