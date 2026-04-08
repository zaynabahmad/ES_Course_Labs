#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

/* ================= Register Addresses ================= */

#define SSPBUF   (*(volatile unsigned char*)0x13)
#define SSPCON1  (*(volatile unsigned char*)0x14)
#define SSPCON2  (*(volatile unsigned char*)0x91)
#define SSPSTAT  (*(volatile unsigned char*)0x94)
#define SSPADD   (*(volatile unsigned char*)0x93)
#define TRISC    (*(volatile unsigned char*)0x87)
#define PIR1     (*(volatile unsigned char*)0x0C)
#define PIE1     (*(volatile unsigned char*)0x8C)
#define INTCON   (*(volatile unsigned char*)0x0B)

/* ================= SSPCON1 Bits ================= */

#define SSPM0    0
#define SSPM1    1
#define SSPM2    2
#define SSPM3    3
#define CKP      4    /* Clock Polarity / SCK release (Slave stretch) */
#define SSPEN    5    /* Synchronous Serial Port Enable */
#define SSPOV    6    /* Receive Overflow Indicator */
#define WCOL     7    /* Write Collision Detect */

/* ================= SSPCON2 Bits (I2C-specific) ================= */

#define SEN      0    /* Start Condition Enable / Stretch Enable (Slave) */
#define RSEN     1    /* Repeated Start Condition Enable */
#define PEN      2    /* Stop Condition Enable */
#define RCEN     3    /* Receive Enable */
#define ACKEN    4    /* Acknowledge Sequence Enable */
#define ACKDT    5    /* Acknowledge Data bit (0 = ACK, 1 = NACK) */
#define ACKSTAT  6    /* Acknowledge Status (0 = ACK received from slave) */
#define GCEN     7    /* General Call Enable (Slave mode) */

/* ================= SSPSTAT Bits ================= */

#define BF       0    /* Buffer Full */
#define UA       1    /* Update Address (10-bit Slave mode) */
#define R_nW     2    /* Master: 1 = transmit in progress */
#define S_BIT    3    /* Start Condition detected */
#define P_BIT    4    /* Stop  Condition detected */
#define D_nA     5    /* Last byte was Data(1) or Address(0) */
#define SMP      7    /* Slew Rate Control (0 = enabled for 400 kHz) */

/* ================= PIR1 Bits ================= */

#define SSPIF    3    /* MSSP Interrupt Flag */

/* ================= PIE1 Bits ================= */

#define SSPIE    3    /* MSSP Interrupt Enable */

/* ================= INTCON Bits ================= */

#define PEIE     6    /* Peripheral Interrupt Enable */
#define GIE      7    /* Global Interrupt Enable */

/* ================= TRISC Bit Positions ================= */

#define RC3      3    /* SCL — must be Input for I2C open-drain operation */
#define RC4      4    /* SDA — must be Input for I2C open-drain operation */

/* ================= I2C Mode Codes (SSPM<3:0>) ================= */

#define I2C_MASTER_MODE     0x08    /* 1000 — FOSC / (4*(SSPADD+1)) */
#define I2C_SLAVE_7BIT      0x06    /* 0110 — Slave, 7-bit address  */
#define I2C_SLAVE_10BIT     0x07    /* 0111 — Slave, 10-bit address */

/* ================= Bus-Idle Check Mask ================= */
/*
 * The I2C bus is idle (safe to issue a new command) when:
 *   SSPSTAT<2> R_nW = 0  → no transmission in progress
 *   SSPCON2<4:0>        → none of SEN/RSEN/PEN/RCEN/ACKEN are set
 */
#define I2C_SSPSTAT_BUSY_MASK   0x04
#define I2C_SSPCON2_BUSY_MASK   0x1F

#endif
