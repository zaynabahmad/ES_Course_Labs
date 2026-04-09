#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

/* --- Register Addresses --- */
#define TXSTA   (*((volatile u8*)0x98))
#define RCSTA   (*((volatile u8*)0x18))
#define SPBRG   (*((volatile u8*)0x99))
#define TXREG   (*((volatile u8*)0x19))
#define RCREG   (*((volatile u8*)0x1A))
#define PIR1    (*((volatile u8*)0x0C))
#define PIE1    (*((volatile u8*)0x8C))
#define INTCON  (*((volatile u8*)0x0B)) /* This is needed for GIE and PEIE */

/* --- TXSTA Bits --- */
#define TXEN_BIT 5
#define BRGH_BIT 2
#define SYNC_BIT 4
#define TRMT_BIT 1

/* --- RCSTA Bits --- */
#define SPEN_BIT 7
#define CREN_BIT 4

/* --- PIR1 Bits --- */
#define RCIF_BIT 5

/* --- PIE1 Bits --- */
#define RCIE_BIT 5

/* --- INTCON Bits --- */
#define PEIE_BIT 6
#define GIE_BIT  7

#endif