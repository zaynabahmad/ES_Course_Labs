/**
 * @file    test_exti.h
 * @brief   Entry point for the external-interrupt exercise.
 */
#ifndef TEST_EXTI_H
#define TEST_EXTI_H

/**
 * @brief  Demonstrate the EXTI driver: each falling edge on the INT pin
 *         toggles an LED from interrupt context. Never returns.
 */
void vTest_Exti(void);

#endif /* TEST_EXTI_H */
