#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#define SSPCON2 (*(volatile unsigned char*)0x91)
#define SSPBUF  (*(volatile unsigned char*)0x13)
#define SSPSTAT (*(volatile unsigned char*)0x94)

#endif