#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

// Add to USART_private.h (or UART_private.h):
#define INTCON      (*(volatile u8*)0x0B)
#define INTCON_GIE   7
#define INTCON_PEIE  6   /* Peripheral Interrupt Enable */
#define PEIE         6   /* alias used in USART.c       */

/* ================= Registers Addresses ================= */

#define TXSTA   (*(volatile unsigned char*)0x98)
#define RCSTA   (*(volatile unsigned char*)0x18)
#define SPBRG   (*(volatile unsigned char*)0x99)
#define TXREG   (*(volatile unsigned char*)0x19)
#define RCREG   (*(volatile unsigned char*)0x1A)
#define PIR1    (*(volatile unsigned char*)0x0C)
#define PIE1    (*(volatile unsigned char*)0x8C)
//#define INTCON  (*(volatile unsigned char*)0x0B)

/* ================= TXSTA Bits ================= */

#define TXEN   5
#define BRGH   2
#define SYNC   4
#define TRMT   1

/* ================= RCSTA Bits ================= */

#define SPEN   7
#define CREN   4

/* ================= PIR1 Bits ================= */

#define RCIF   5

/* ================= PIE1 Bits ================= */

#define RCIE   5

/* ================= INTCON Bits ================= */

#define PEIE   6
#define GIE    7

#endif