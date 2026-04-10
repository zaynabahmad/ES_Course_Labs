#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

/* MSSP Registers */
#define SSPCON   *((volatile u8*)0x14)
#define SSPCON2  *((volatile u8*)0x91)
#define SSPSTAT  *((volatile u8*)0x94)
#define SSPADD   *((volatile u8*)0x93)
#define SSPBUF   *((volatile u8*)0x13)
#define PIR1     *((volatile u8*)0x0C)

/* TRIS */
#define TRISC    *((volatile u8*)0x87)

/* SSPCON Bits */
#define SSPEN   5

/* SSPCON2 Bits */
#define ACKSTAT 6
#define ACKDT   5
#define ACKEN   4
#define RCEN    3
#define PEN     2
#define RSEN    1
#define SEN     0

/* SSPSTAT Bits */
#define SMP     7

#endif