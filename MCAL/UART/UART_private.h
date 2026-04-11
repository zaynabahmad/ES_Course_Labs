#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define TXSTA    (*((volatile u8*)0x98))
#define RCSTA    (*((volatile u8*)0x18))
#define SPBRG    (*((volatile u8*)0x99))
#define TXREG    (*((volatile u8*)0x19))
#define RCREG    (*((volatile u8*)0x1A))
#define PIR1     (*((volatile u8*)0x0C))
#define PIE1     (*((volatile u8*)0x8C))
#define INTCON   (*((volatile u8*)0x0B))
#define TRISC    (*((volatile u8*)0x87))

/* TXSTA bits */
#define CSRC_BIT   7
#define TX9_BIT    6
#define TXEN_BIT   5
#define SYNC_BIT   4
#define BRGH_BIT   2
#define TRMT_BIT   1
#define TX9D_BIT   0

/* RCSTA bits */
#define SPEN_BIT   7
#define RX9_BIT    6
#define SREN_BIT   5
#define CREN_BIT   4
#define FERR_BIT   2
#define OERR_BIT   1
#define RX9D_BIT   0

/* PIR1 bits */
#define TXIF_BIT   4
#define RCIF_BIT   5

/* PIE1 bits */
#define TXIE_BIT   4
#define RCIE_BIT   5

/* INTCON bits */
#define PEIE_BIT   6
#define GIE_BIT    7

#endif