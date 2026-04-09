/*
 * pwm_test.h
 * APP Layer - PWM Test Declarations
 */

#ifndef PWM_TEST_H
#define PWM_TEST_H

typedef unsigned char u8;

void PWM_Test_Init(void);
void PWM_Test_FadeUp(void);
void PWM_Test_FadeDown(void);
void PWM_Test_Run(void);

#endif /* PWM_TEST_H */
