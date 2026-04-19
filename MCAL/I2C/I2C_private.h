#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#define SSPCON_REG    (*((volatile u8*)0x14))
#define SSPCON2_REG   (*((volatile u8*)0x91))
#define SSPSTAT_REG   (*((volatile u8*)0x94))
#define SSPADD_REG    (*((volatile u8*)0x93))
#define SSPBUF_REG    (*((volatile u8*)0x13))

/* Bit Positions */
#define SEN_BIT       0   // Start Enable
#define PEN_BIT       2   // Stop Enable
#define RCEN_BIT      3   // Receive Enable
#define ACKEN_BIT     4   // Ack Enable
#define ACKDT_BIT     5   // Ack Data
#define SSPIF_BIT     3   // Interrupt Flag in PIR1
#define R_W_BIT       2   // Read/Write bit in STAT

#endif