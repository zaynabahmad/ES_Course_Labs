#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void UART_Init(void);

/* ── Send ── */
void UART_SendByte(u8 byte);
void UART_SendString(const u8 *str);
void UART_SendNewLine(void);
void UART_SendNumber(u32 num);

/* ── Receive ── */
u8   UART_ReceiveByte(void);                    /* blocking                          */
u8   UART_ReceiveByte_NoBlock(u8 *byte);        /* non-blocking, returns 1 if ready  */
void UART_ReceiveString(u8 *buf, u8 maxLen);    /* reads until '\r' or maxLen-1      */

/* ── Status ── */
u8   UART_IsDataReady(void);                    /* 1 = byte waiting in RCREG         */

#endif /* UART_INTERFACE_H */
