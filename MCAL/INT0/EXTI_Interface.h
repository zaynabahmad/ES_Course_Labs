#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

#define EXTI_FALLING_EDGE 0
#define EXTI_RISING_EDGE  1

/* Driver API Prototypes */
void EXTI_voidInit(void);
void EXTI_voidSetEdge(u8 Copy_u8Edge);
void EXTI_voidEnable(void);
void EXTI_voidDisable(void);
void EXTI_voidClearFlag(void);
void EXTI_voidEnableGlobalInterrupt(void);
void EXTI_voidDisableGlobalInterrupt(void);

/* Callback function setup for the ISR */
void EXTI_voidSetCallBack(void (*Copy_pVoidCallBack)(void));

#endif