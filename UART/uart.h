// Purpose: Lists serial communication functions

#ifndef UART_H
#define UART_H

#include "std_types.h"
#include "pic_config.h"

void UART_Init(uint32 baud_rate);        // Setup serial (9600, 19200, etc)
void UART_WriteChar(uint8 data);         // Send 1 byte
void UART_WriteString(char* str);        // Send text
uint8 UART_ReadChar(void);               // Receive 1 byte
uint8 UART_DataReady(void);              // Check if data arrived

#endif