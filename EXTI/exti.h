// Purpose: Lists interrupt functions (instant response to button)

#ifndef EXTI_H
#define EXTI_H

#include "std_types.h"
#include "pic_config.h"

typedef enum {
    EXTI_RISING_EDGE = 1,   // Trigger when button pressed (0->5V)
    EXTI_FALLING_EDGE = 0   // Trigger when button released (5V->0)
} EXTI_Edge;

void EXTI_Init(EXTI_Edge edge);        // Setup interrupt
void EXTI_Enable(void);                // Turn on interrupt
void EXTI_Disable(void);               // Turn off interrupt
void EXTI_SetCallback(void (*callback)(void));  // What to do when triggered

#endif