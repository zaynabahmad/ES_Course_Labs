#ifndef EXTI0_INTERFACE_H
#define EXTI0_INTERFACE_H


void EXTI0_Init(void);
void EXTI0_SetCallback(void (*callback)(void));

#endif