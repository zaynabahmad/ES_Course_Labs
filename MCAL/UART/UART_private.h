#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

/* Transmit Data Register */
#define TXREG   (*(volatile unsigned char*)0x19)

/* Receive Data Register */
#define RCREG   (*(volatile unsigned char*)0x1A)

/* Transmit Status and Control Register */
#define TXSTA   (*(volatile unsigned char*)0x98)

/* Receive Status and Control Register */
#define RCSTA   (*(volatile unsigned char*)0x18)

/* Baud Rate Generator Register */
#define SPBRG   (*(volatile unsigned char*)0x99)

/* Peripheral Interrupt Request Register 1 */
#define PIR1    (*(volatile unsigned char*)0x0C)

/* Peripheral Interrupt Enable Register 1 */
#define PIE1    (*(volatile unsigned char*)0x8C)

/* Data direction register for Port C
 * RC6 = TX (must be output), RC7 = RX (must be input) */
#define TRISC   (*(volatile unsigned char*)0x87)

/* ---- TXSTA bit positions ---- */
#define TXSTA_TX9D   0    /* 9th bit of transmit data              */
#define TXSTA_TRMT   1    /* Transmit shift register empty flag    */
#define TXSTA_BRGH   2    /* High baud rate select                 */
#define TXSTA_SYNC   4    /* Synchronous mode select (0=async)     */
#define TXSTA_TXEN   5    /* Transmit enable                       */
#define TXSTA_TX9    6    /* 9-bit transmit enable (0=8-bit)       */
#define TXSTA_CSRC   7    /* Clock source (master/slave, sync only)*/

/* ---- RCSTA bit positions ---- */
#define RCSTA_RX9D   0    /* 9th bit of received data              */
#define RCSTA_OERR   1    /* Overrun error flag                    */
#define RCSTA_FERR   2    /* Framing error flag                    */
#define RCSTA_ADDEN  3    /* Address detect enable (9-bit mode)    */
#define RCSTA_CREN   4    /* Continuous receive enable             */
#define RCSTA_SREN   5    /* Single receive enable (sync only)     */
#define RCSTA_RX9    6    /* 9-bit receive enable (0=8-bit)        */
#define RCSTA_SPEN   7    /* Serial port enable                    */

/* ---- PIR1 bit positions ---- */
#define PIR1_TXIF   4    /* USART Transmit Interrupt Flag          */
#define PIR1_RCIF   5    /* USART Receive Interrupt Flag           */

/* ---- TRISC pin positions for UART ---- */
#define UART_TX_PIN  6u   /* RC6 = TX output */
#define UART_RX_PIN  7u   /* RC7 = RX input  */

#define UART_SPBRG_9600     51u
#define UART_SPBRG_19200    25u
#define UART_SPBRG_57600     7u

/* Active baud rate used by init */
#define UART_SPBRG_VALUE    UART_SPBRG_9600

/* Timeout loop count for receive (prevents infinite hang) */
#define UART_RX_TIMEOUT     60000u

#endif /* UART_PRIVATE_H */