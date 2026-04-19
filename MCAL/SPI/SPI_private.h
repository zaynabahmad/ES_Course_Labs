 #ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SSPCON_REG    (*((volatile u8*)0x14))
#define SSPSTAT_REG   (*((volatile u8*)0x94))
#define SSPBUF_REG    (*((volatile u8*)0x13))

/* Bit Positions */
#define SSPEN_BIT     5
#define CKP_BIT       4
#define BF_BIT        0

#endif