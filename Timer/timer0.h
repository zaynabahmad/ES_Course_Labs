#ifndef TIMER1_H
#define TIMER1_H

#include "std_types.h"
#include "pic_config.h"

void Timer1_Init(void);
void Timer1_Start(void);
void Timer1_Stop(void);
void Timer1_SetDelayMs(uint16 delay_ms);
void Timer1_ClearFlag(void);
uint8 Timer1_IsOverflow(void);

#endif