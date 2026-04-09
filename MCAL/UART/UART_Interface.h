#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

typedef struct
{
    u32 BaudRate;
    u8 HighSpeed;
    u8 EnableTx;
    u8 EnableRx;
    u8 RxInterruptEnable;
} UART_ConfigType;

void UART_Init(UART_ConfigType *ConfigPtr);
void UART_WriteByte(u8 Data);
void UART_WriteString(u8 *StringPtr);
u8 UART_ReadByte(void);
void UART_SetCallback(void (*Callback)(u8));
void UART_ISR(void);

#endif
