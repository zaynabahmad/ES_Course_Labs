#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H


// Registers
#define TXREG_REG       TXREG
#define RCREG_REG       RCREG
#define TXSTA_REG       TXSTA
#define RCSTA_REG       RCSTA
#define SPBRG_REG       SPBRG
#define PIR1_REG        PIR1

// Bits
#define TXIF_BIT        4
#define RCIF_BIT        5
#define TXEN_BIT        5
#define BRGH_BIT        2
#define SPEN_BIT        7
#define CREN_BIT        4

#endif