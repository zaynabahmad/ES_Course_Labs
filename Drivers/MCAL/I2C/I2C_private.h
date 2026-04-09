#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#define SSPCON2   (*(volatile uint8*)0xA2)
#define SSPCON    (*(volatile uint8*)0xA0)
#define SSPSTAT   (*(volatile uint8*)0xA3)
#define SSPMSK    (*(volatile uint8*)0x93)
#define SSPADD    (*(volatile uint8*)0xA4)

#endif