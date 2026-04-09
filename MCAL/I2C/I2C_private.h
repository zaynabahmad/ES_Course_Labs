#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#define TWBR (*(volatile unsigned char*)0x20)
#define TWCR (*(volatile unsigned char*)0x56)
#define TWDR (*(volatile unsigned char*)0x23)
#define TWSR (*(volatile unsigned char*)0x21)

#endif