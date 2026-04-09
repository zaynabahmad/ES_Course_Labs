#ifndef TIMER_0_INTERFACE_H
#define TIMER_0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

#define TIMER0_TIMER_MODE          0
#define TIMER0_COUNTER_MODE        1
#define TIMER0_LOW_TO_HIGH_EDGE    0
#define TIMER0_HIGH_TO_LOW_EDGE    1
#define TIMER0_PRESCALER_TO_WDT    1
#define TIMER0_PRESCALER_TO_TIMER0 0

typedef struct
{
    u8 Mode;
    u8 EdgeSelect;
    u8 PrescalerAssignment;
    u8 PrescalerValue;
    u8 PreloadValue;
    u8 InterruptEnable;
} TIMER0_ConfigType;

void TIMER0_Init(TIMER0_ConfigType *ConfigPtr);
void TIMER0_Start(void);
void TIMER0_Stop(void);
void TIMER0_WriteValue(u8 Value);
u8 TIMER0_ReadValue(void);
void TIMER0_SetCallback(void (*Callback)(void));
void TIMER0_ISR(void);

#endif
