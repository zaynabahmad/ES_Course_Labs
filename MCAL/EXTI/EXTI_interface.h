#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define RISING_EDGE  1
#define FALLING_EDGE 2
#define LOW_LEVEL    3

void EXTI_Init(char sense);
void EXTI_Enable();
void EXTI_SetCallback(void (*ptr)(void));

#endif