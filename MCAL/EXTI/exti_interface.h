#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "D:/ES-Project-Lab/SERVICES/std_types.h"

#define EXTI_RISING_EDGE  1
#define EXTI_FALLING_EDGE 0

// Initialize External Interrupt on RB0
void EXTI_init(u8 edge);

// Set the function to be called when interrupt happens
void EXTI_setCallback(void (*ptr)(void));


extern volatile u8 exti_flag;
extern volatile u8 timer0_flag;
#endif