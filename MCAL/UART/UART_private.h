#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

// Registers (mikroC names)
#define TXSTA_REG   TXSTA
#define RCSTA_REG   RCSTA
#define SPBRG_REG   SPBRG
#define PIR1_REG    PIR1

// Bits (mikroC provides _bit access)
#define TXIF_Bit    TXIF_bit
#define TRMT_Bit    TRMT_bit
#define RCIF_Bit    RCIF_bit

#endif