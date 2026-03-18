#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H


#define UART_BAUD_RATE    9600u


#define UART_Init()           UART1_Init(UART_BAUD_RATE)
#define UART_SendByte(b)      UART1_Write((b))
#define UART_SendString(s)    UART1_Write_Text((s))
#define UART_SendNewLine()    do { UART1_Write(13); UART1_Write(10); } while(0)

#endif /* UART_INTERFACE_H */