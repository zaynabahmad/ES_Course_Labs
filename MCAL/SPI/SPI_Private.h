#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SSPSTAT    *((volatile u8*)0x94)
#define SSPCON     *((volatile u8*)0x14)
#define SSPBUF     *((volatile u8*)0x13)
#define TRISC      *((volatile u8*)0x87)
#define TRISA      *((volatile u8*)0x85)
#define ADCON1     *((volatile u8*)0x9F)

#define BF         0
#define SSPIF      3
#define SMP        7
#define CKE        6
#define CKP        4
#define SSPEN      5

#endif