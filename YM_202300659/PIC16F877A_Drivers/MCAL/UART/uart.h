/*
 * uart.h
 * MCAL - UART (USART) Driver Interface for PIC16F877A
 * TX: RC6, RX: RC7
 */

#ifndef UART_H
#define UART_H

typedef unsigned char  u8;
typedef unsigned int   u16;

/* =====================================================
 * Baud Rate Defines (Fosc = 4MHz, BRGH=1)
 * SPBRG = (Fosc / (16 * BaudRate)) - 1
 * ===================================================== */
#define UART_BAUD_9600     25    /* Error: 0.16%  */
#define UART_BAUD_19200    12    /* Error: 0.16%  */
#define UART_BAUD_38400    6     /* Error: -7.8%  */
#define UART_BAUD_57600    3     /* Error: 8.5%   */

/* =====================================================
 * Error Codes
 * ===================================================== */
typedef enum {
    UART_OK             = 0,
    UART_ERROR_OVERRUN  = 1,
    UART_ERROR_FRAMING  = 2
} UART_Error_t;

/* =====================================================
 * Function Prototypes
 * ===================================================== */

/**
 * @brief  Initialize UART module
 * @param  spbrg_val : SPBRG register value (use UART_BAUD_xxx macros)
 */
void UART_Init(u8 spbrg_val);

/**
 * @brief  Transmit a single byte (blocking)
 */
void UART_SendByte(u8 data);

/**
 * @brief  Transmit a null-terminated string
 */
void UART_SendString(const u8 *str);

/**
 * @brief  Receive a single byte (blocking)
 * @return received byte
 */
u8 UART_ReceiveByte(void);

/**
 * @brief  Receive a string until newline or max_len
 * @param  buf     : destination buffer
 * @param  max_len : maximum bytes to receive
 */
void UART_ReceiveString(u8 *buf, u8 max_len);

/**
 * @brief  Check if a byte is available in receive buffer
 * @return 1 if data available, 0 otherwise
 */
u8 UART_IsDataAvailable(void);

/**
 * @brief  Check if transmit buffer is empty (ready to send)
 */
u8 UART_IsTxReady(void);

/**
 * @brief  Get and clear UART error flags
 */
UART_Error_t UART_GetError(void);

/**
 * @brief  Send a number as decimal string
 */
void UART_SendNumber(u16 num);

#endif /* UART_H */
