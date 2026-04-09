#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

/* MSSP Registers Memory Mapping */
#define SSPSTAT         *((volatile u8*)0x94)
#define SSPCON          *((volatile u8*)0x14)
#define SSPCON2         *((volatile u8*)0x91)
#define SSPBUF          *((volatile u8*)0x13)
#define SSPADD          *((volatile u8*)0x93)

/* TRIS Control for I2C Pins */
#define TRISC           *((volatile u8*)0x87)
#define SCL_PIN         3
#define SDA_PIN         4

/* PIR1 Register for Interrupt Flag */
#define PIR1            *((volatile u8*)0x0C)
#define SSPIF           3

/* SSPCON2 Bit Definitions */
#define SSPCON2_SEN     0   /* Start Condition Enable */
#define SSPCON2_RSEN    1   /* Repeated Start Enable */
#define SSPCON2_PEN     2   /* Stop Condition Enable */
#define SSPCON2_RCEN    3   /* Receive Enable */
#define SSPCON2_ACKEN   4   /* Acknowledge Sequence Enable */
#define SSPCON2_ACKDT   5   /* Acknowledge Data bit (0=ACK, 1=NACK) */
#define SSPCON2_ACKSTAT 6   /* Acknowledge Status bit */

#endif