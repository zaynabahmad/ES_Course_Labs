#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H


/* ================= Registers Addresses ================= */
#define SSPCON    (*(volatile unsigned char*)0x14)
#define SSPCON2   (*(volatile unsigned char*)0x91) // Additional for I2C
#define SSPSTAT   (*(volatile unsigned char*)0x94)
#define SSPBUF    (*(volatile unsigned char*)0x13)
#define SSPADD    (*(volatile unsigned char*)0x93) // Address/Baud Rate register
#define PIR1      (*(volatile unsigned char*)0x0C)
#define PIE1      (*(volatile unsigned char*)0x8C)
#define INTCON    (*(volatile unsigned char*)0x0B)
#define TRISC     (*(volatile unsigned char*)0x87)

/* ================= SSPCON Bits ================= */
#define SSPEN     5
#define CKP       4
#define SSPM3     3
#define SSPM2     2
#define SSPM1     1
#define SSPM0     0

/* ================= SSPCON2 Bits (Critical for I2C) ================= */
#define GCEN      7    // General Call Enable
#define ACKSTAT   6    // Acknowledge Status bit
#define ACKDT     5    // Acknowledge Data bit
#define ACKEN     4    // Acknowledge Sequence Enable
#define RCEN      3    // Receive Enable bit
#define PEN       2    // Stop Condition Enable
#define RSEN      1    // Repeated Start Condition Enable
#define SEN       0    // Start Condition Enable

/* ================= SSPSTAT Bits ================= */
#define SMP       7    // Slew Rate Control
#define CKE       6    // SMBus Select
#define D_A       5    // Data/Address bit
#define P         4    // Stop bit
#define S         3    // Start bit
#define R_W       2    // Read/Write bit information
#define UA        1    // Update Address
#define BF        0    // Buffer Full bit

/* ================= PIR1 Bits ================= */
#define SSPIF     3

/* ================= PIE1 Bits ================= */
#define SSPIE     3

/* ================= INTCON Bits ================= */
#define PEIE      6
#define GIE       7

/* ================= TRISC Bits ================= */
#define TRISC3    3    // SCL pin
#define TRISC4    4    // SDA pin



#endif