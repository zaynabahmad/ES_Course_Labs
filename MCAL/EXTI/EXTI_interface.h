#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Trigger options */
#define EXTI_RISING_EDGE    1
#define EXTI_FALLING_EDGE   0

/* Function prototypes */
void EXTI_Init(void);
void EXTI_Enable(void);
void EXTI_Disable(void);
void EXTI_ClearFlag(void);

#endif