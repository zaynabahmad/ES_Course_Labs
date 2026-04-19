   #ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define TXSTA_REG    (*((volatile u8*)0x98))
#define RCSTA_REG    (*((volatile u8*)0x18))
#define SPBRG_REG    (*((volatile u8*)0x99))
#define TXREG_REG    (*((volatile u8*)0x19))
#define RCREG_REG    (*((volatile u8*)0x1A))
#define PIR1_REG     (*((volatile u8*)0x0C))

/* Bit Positions */
#define TXIF_BIT     4
#define RCIF_BIT     5
#define TRMT_BIT     1

#endif