#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define TXSTA   (*((volatile unsigned char*)0x98))
#define RCSTA   (*((volatile unsigned char*)0x18))
#define SPBRG   (*((volatile unsigned char*)0x99))
#define TXREG   (*((volatile unsigned char*)0x19))
#define RCREG   (*((volatile unsigned char*)0x1A))
#define PIR1    (*((volatile unsigned char*)0x0C))

#define TRISC   (*((volatile unsigned char*)0x87))

/* TXSTA bits */
#define TXEN    5
#define SYNC    4
#define BRGH    2
#define TRMT    1
#define TX9     6

/* RCSTA bits */
#define SPEN    7
#define CREN    4
#define RX9     6
#define OERR    1
#define FERR    2

/* PIR1 bits */
#define RCIF    5
#define TXIF    4

#endif