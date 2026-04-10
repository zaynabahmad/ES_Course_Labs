#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#define SSPCON_REG    (*((volatile unsigned char*)0x14))
#define SSPCON2_REG   (*((volatile unsigned char*)0x91))
#define SSPSTAT_REG   (*((volatile unsigned char*)0x94))
#define SSPADD_REG    (*((volatile unsigned char*)0x93))
#define SSPBUF_REG    (*((volatile unsigned char*)0x13))
#define TRISC_REG     (*((volatile unsigned char*)0x87))

#endif