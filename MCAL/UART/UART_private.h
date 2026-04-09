#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

/* USART Registers */
#define TXSTA           *((volatile u8*)0x98)  /* Transmit Status & Control */
#define RCSTA           *((volatile u8*)0x18)  /* Receive Status & Control */
#define SPBRG           *((volatile u8*)0x99)  /* Baud Rate Generator */
#define TXREG           *((volatile u8*)0x19)  /* Transmit Register */
#define RCREG           *((volatile u8*)0x1A)  /* Receive Register */

/* TRIS for UART Pins */
#define TRISC           *((volatile u8*)0x87)
#define TX_PIN          6
#define RX_PIN          7

/* PIR1 for Flags */
#define PIR1            *((volatile u8*)0x0C)
#define TXIF            4   /* Transmit Interrupt Flag */
#define RCIF            5   /* Receive Interrupt Flag */

/* TXSTA Bit Definitions */
#define TXSTA_TXEN      5   /* Transmit Enable */
#define TXSTA_BRGH      2   /* High Baud Rate Select */
#define TXSTA_TRMT      1   /* Transmit Shift Register Status (1=Empty) */

/* RCSTA Bit Definitions */
#define RCSTA_SPEN      7   /* Serial Port Enable */
#define RCSTA_CREN      4   /* Continuous Receive Enable */

#endif