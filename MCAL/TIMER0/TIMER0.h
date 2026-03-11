#ifndef TIMER0_H
#define TIMER0_H
void TIMER0_Init(void);
void TIMER0_EnableInterrupt(void);
void TIMER0_SetCallback(void (*ptr)(void));
#endif
