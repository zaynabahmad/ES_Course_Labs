#ifndef TIMER0_H
#define TIMER0_H

#include "../../SERVICES/Std_Types.h"

/* Function Prototypes */
void M_TIMER0_voidInit(void);
void M_TIMER0_voidSetPreload(u8 copy_u8Preload);
void M_TIMER0_voidSetCallBack(void (*ptr)(void));

/* * EXTERN: This tells the compiler that the pointer 
 * exists in Timer0.c and can be used in main.c 
 */
extern void (*Timer0_CallBackPtr)(void);

#endif