/*
 * uart.h
 * UART (EUSART) Driver for PIC16F877A — polling mode
 *
 * TX = RC6, RX = RC7
 *
 * Baud rate register:
 *   SPBRG = (F_CPU / (16 * BaudRate)) - 1   when BRGH=1 (High Speed)
 *   SPBRG = (F_CPU / (64 * BaudRate)) - 1   when BRGH=0 (Low Speed)
 */

#ifndef UART_H
#define UART_H

#include "../std_types.h"
#include <xc.h>

typedef enum { UART_8BIT_DATA, UART_9BIT_DATA } UART_DataBits;
typedef enum { UART_NO_PARITY }                  UART_Parity;   /* PIC EUSART has no HW parity */

typedef struct {
    uint32        baudRate;
    UART_DataBits dataBits;
} UART_Config;

void  UART_init          (const UART_Config *config);
void  UART_sendByte      (uint8 data);
uint8 UART_receiveByte   (void);
void  UART_sendString    (const char *str);
void  UART_receiveString (char *buf, uint8 maxLen);  /* Reads until '\n' */

#endif /* UART_H */
