#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define TXSTA   (*((volatile u8*)0x98))
#define RCSTA   (*((volatile u8*)0x18))
#define SPBRG   (*((volatile u8*)0x99))
#define TXREG   (*((volatile u8*)0x19))
#define RCREG   (*((volatile u8*)0x1A))
#define TRISC   (*((volatile u8*)0x87))
#define PIR1    (*((volatile u8*)0x0C))

#endif