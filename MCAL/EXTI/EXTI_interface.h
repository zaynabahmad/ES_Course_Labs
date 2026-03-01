#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_RISING_EDGE    1
#define EXTI_FALLING_EDGE   0

// Initializes INT0 (RB0) with the desired edge
void EXTI_voidInit(void);


// The bridge between APP and MCAL
void EXTI_voidSetCallBack(void (*Copy_pvCallBackFunc)(void));



#endif