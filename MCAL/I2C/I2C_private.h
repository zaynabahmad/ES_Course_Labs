#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

// MSSP Registers for I2C 
#define SSPCON  (*((volatile u8*)0x14))
#define SSPCON2 (*((volatile u8*)0x91))
#define SSPSTAT (*((volatile u8*)0x94))
#define SSPADD  (*((volatile u8*)0x93))
#define SSPBUF  (*((volatile u8*)0x13))
#define PIR1    (*((volatile u8*)0x0C))

// SSPCON2 Bits
#define SEN     0   // Start Condition Enable
#define RSEN    1   // Repeated Start Enable
#define PEN     2   // Stop Condition Enable
#define RCEN    3   // Receive Enable
#define ACKEN   4   // Acknowledge Sequence Enable
#define ACKDT   5   // Acknowledge Data bit
#define ACKSTAT 6   // Acknowledge Status bit

// PIR1 Bits
#define SSPIF   3   // MSSP Interrupt Flag

#endif