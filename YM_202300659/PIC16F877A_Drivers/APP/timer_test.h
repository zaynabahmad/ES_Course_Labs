/*
 * timer_test.h
 * APP Layer - Timer0 Test Declarations
 */

#ifndef TIMER_TEST_H
#define TIMER_TEST_H

typedef unsigned char u8;

void TIMER_Test_Init(void);
void TIMER_Test_BlockingBlink(void);
void TIMER_Test_ISR_Handler(void);
void TIMER_Test_InterruptBlink(void);
void TIMER_Test_Run(void);

#endif /* TIMER_TEST_H */
