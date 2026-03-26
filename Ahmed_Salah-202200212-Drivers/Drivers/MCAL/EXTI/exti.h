#ifndef EXTI_H
#define EXTI_H

#include "../../SERVICES/Std_Types.h"

/* Function Prototypes */
void M_EXTI_voidInit(void);
void M_EXTI_voidSetCallBack(void (*ptr)(void));

/* * EXTERN: This tells the compiler that the pointer 
 * exists in EXTI.c and can be used in main.c 
 */
extern void (*EXTI_CallBackPtr)(void);

#endif