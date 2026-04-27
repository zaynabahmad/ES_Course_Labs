#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define RISING_EDGE  1
#define FALLING_EDGE 0

void EXTI_Init(unsigned char edge);
void EXTI_Enable(void);
void EXTI_Disable(void);

#endif