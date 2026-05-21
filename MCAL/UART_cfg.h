/**
 * @file    UART_cfg.h
 * @brief   Compile-time configuration for the USART driver.
 *
 * @details Only the target baud rate is configured here. The driver does not
 *          assume a speed mode -- it derives the best SPBRG value and chooses
 *          BRGH for the smaller rate error at init time (see UART.c).
 */
#ifndef UART_CFG_H
#define UART_CFG_H

/** Desired asynchronous baud rate in bits per second. */
#define UART_BAUD_RATE      9600uL

#endif /* UART_CFG_H */
