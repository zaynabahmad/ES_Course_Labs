#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define TXREG   (*((volatile u8*)0x19))
#define RCREG   (*((volatile u8*)0x1A))
#define TXSTA   (*((volatile u8*)0x98))
#define RCSTA   (*((volatile u8*)0x18))
#define SPBRG   (*((volatile u8*)0x99))
#define PIR1    (*((volatile u8*)0x0C))
#define TRISC   (*((volatile u8*)0x87))

/* TXSTA bit positions */
#define CSRC   7   /* Clock Source Select   */
#define TX9    6   /* 9-bit Transmit Enable */
#define TXEN   5   /* Transmit Enable       */
#define SYNC   4   /* USART Mode Select: 0=async */
#define BRGH   2   /* High Baud Rate Select */
#define TRMT   1   /* Transmit Shift Reg Empty */
#define TX9D   0   /* 9th bit of transmit data */

/* RCSTA bit positions */
#define SPEN   7   /* Serial Port Enable    */
#define RX9    6   /* 9-bit Receive Enable  */
#define SREN   5   /* Single Receive Enable */
#define CREN   4   /* Continuous Receive Enable */
#define ADDEN  3   /* Address Detect Enable */
#define FERR   2   /* Framing Error bit     */
#define OERR   1   /* Overrun Error bit     */
#define RX9D   0   /* 9th bit of received data */

/* PIR1 bit positions */
#define RCIF   5   /* USART Receive Interrupt Flag  */
#define TXIF   4   /* USART Transmit Interrupt Flag */

#endif
