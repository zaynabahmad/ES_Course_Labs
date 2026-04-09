/*
 * gpio_test.h
 * APP Layer - GPIO Test Function Declarations
 */

#ifndef GPIO_TEST_H
#define GPIO_TEST_H

typedef unsigned char u8;

void GPIO_Test_Init(void);
void GPIO_Test_LEDChaser(void);
void GPIO_Test_ButtonRead(void);
void GPIO_Test_ToggleAll(void);
void GPIO_Test_Run(void);

#endif /* GPIO_TEST_H */
