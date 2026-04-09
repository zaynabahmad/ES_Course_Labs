#ifndef TIMER0_H
#define TIMER0_H

#include "std_types.h"
#include "timer0_cfg.h"

void  TIMER0_Init(void);
void  TIMER0_Start(void);
void  TIMER0_Stop(void);
void  TIMER0_ClearFlag(void);
void  TIMER0_Preload(uint8 value);
uint8 TIMER0_GetFlag(void);
void  TIMER0_Reload(uint8 value);

#endif