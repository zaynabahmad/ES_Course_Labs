#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H
/* ================= Registers Addresses ================= */
#define SSPCON   (*(volatile unsigned char*)0x14)
#define SSPSTAT   (*(volatile unsigned char*)0x94)
#define SSPBUF   (*(volatile unsigned char*)0x13)
#define PIR1     (*(volatile unsigned char*)0x0C)
#define PIE1     (*(volatile unsigned char*)0x8C)
#define INTCON   (*(volatile unsigned char*)0x0B)
#define TRISC    (*(volatile unsigned char*)0x87)
/* ================= SSPCON Bits ================= */
#define SSPEN   5
#define CKP     4
#define SSPM0   0
/* ================= SSPSTAT Bits ================= */
#define BF      0
/* ================= PIR1 Bits ================= */
#define SSPIF   3
/* ================= PIE1 Bits ================= */
#define SSPIE   3
/* ================= INTCON Bits ================= */
#define PEIE    6
#define GIE     7
/* ================= TRISC Bits ================= */
#define RC3     3


#endif
