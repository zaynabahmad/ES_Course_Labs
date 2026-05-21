/**
 * @file    app_uart.h
 * @brief   Entry point for the UART echo application.
 */
#ifndef APP_UART_H
#define APP_UART_H

/**
 * @brief  Echo every byte received on the UART back to the sender, proving
 *         the transmit and receive paths end to end. Never returns.
 */
void vApp_Uart(void);

#endif /* APP_UART_H */
