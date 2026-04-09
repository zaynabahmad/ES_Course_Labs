#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "../../SERVICES/std_types.h"

#define EXTI_RISING_EDGE   1
#define EXTI_FALLING_EDGE  0

void EXTI_voidInit(u8 copy_u8Edge);
void EXTI_voidEnable(void);
void EXTI_voidDisable(void);

#endif