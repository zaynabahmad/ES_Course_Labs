/*
 * exti_test.h
 * APP Layer - External Interrupt Test Declarations
 */

#ifndef EXTI_TEST_H
#define EXTI_TEST_H

typedef unsigned char u8;

void EXTI_Test_Init(void);
void EXTI_Test_ISR_Handler(void);
u8   EXTI_Test_GetCount(void);
void EXTI_Test_Run(void);

#endif /* EXTI_TEST_H */
