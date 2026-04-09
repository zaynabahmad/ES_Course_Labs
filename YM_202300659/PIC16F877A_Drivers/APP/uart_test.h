/*
 * uart_test.h
 * APP Layer - UART Test Declarations
 */

#ifndef UART_TEST_H
#define UART_TEST_H

typedef unsigned char u8;
typedef unsigned int  u16;

void UART_Test_Init(void);
void UART_Test_SendCounter(void);
void UART_Test_Echo(void);
void UART_Test_Run(void);

#endif /* UART_TEST_H */
