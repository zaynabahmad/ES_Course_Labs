#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

extern void (*TMR0_CallBack)(void);
typedef void (*TmrPtr_t)(void);
void Timer_Init(void);
void Timer_SetCallback(unsigned char index, TmrPtr_t ptr);



#endif