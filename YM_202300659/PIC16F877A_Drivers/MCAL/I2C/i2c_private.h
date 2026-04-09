/*
 * i2c_private.h
 * MCAL - I2C (MSSP) Register Definitions for PIC16F877A
 */

#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

/* =====================================================
 * MSSP Registers (I2C Mode)
 * ===================================================== */

/* SSPBUF - Data Buffer (Bank 0) */
#define SSPBUF_REG      (*((volatile unsigned char*)0x13))

/* SSPCON - Control Register (Bank 0) */
#define SSPCON_REG      (*((volatile unsigned char*)0x14))

/* SSPCON2 - Control Register 2 (Bank 1) */
#define SSPCON2_REG     (*((volatile unsigned char*)0x91))

/* SSPSTAT - Status Register (Bank 1) */
#define SSPSTAT_REG     (*((volatile unsigned char*)0x94))

/* SSPADD - Address / Baud Rate Register (Bank 1) */
#define SSPADD_REG      (*((volatile unsigned char*)0x93))

/* =====================================================
 * SSPCON Bit Positions
 * ===================================================== */
#define SSPCON_WCOL     7   /* Write Collision    */
#define SSPCON_SSPOV    6   /* Overflow Indicator */
#define SSPCON_SSPEN    5   /* SSP Enable         */
#define SSPCON_CKP      4   /* Clock Stretch      */
#define SSPCON_SSPM3    3   /* Mode select bits   */
#define SSPCON_SSPM2    2
#define SSPCON_SSPM1    1
#define SSPCON_SSPM0    0

/* I2C Master mode: SSPM = 1000 */
#define I2C_MASTER_MODE     0x08
/* I2C Slave 7-bit: SSPM = 0110 */
#define I2C_SLAVE_7BIT_MODE 0x06

/* =====================================================
 * SSPCON2 Bit Positions
 * ===================================================== */
#define SSPCON2_GCEN    7   /* General Call Enable  */
#define SSPCON2_ACKSTAT 6   /* ACK Status (master)  */
#define SSPCON2_ACKDT   5   /* ACK Data (0=ACK, 1=NACK) */
#define SSPCON2_ACKEN   4   /* ACK Sequence Enable  */
#define SSPCON2_RCEN    3   /* Receive Enable       */
#define SSPCON2_PEN     2   /* STOP condition Enable*/
#define SSPCON2_RSEN    1   /* Repeated START Enable*/
#define SSPCON2_SEN     0   /* START condition Enable*/

/* =====================================================
 * SSPSTAT Bit Positions
 * ===================================================== */
#define SSPSTAT_SMP     7   /* Slew Rate Control    */
#define SSPSTAT_CKE     6   /* SMBus Compatibility  */
#define SSPSTAT_DA      5   /* Data/nAddress        */
#define SSPSTAT_P       4   /* STOP bit             */
#define SSPSTAT_S       3   /* START bit            */
#define SSPSTAT_RW      2   /* Read/Write           */
#define SSPSTAT_UA      1   /* Update Address       */
#define SSPSTAT_BF      0   /* Buffer Full          */

/* PIR1 SSPIF flag */
#define PIR1_REG        (*((volatile unsigned char*)0x0C))
#define PIR1_SSPIF      3

/* TRISC for SDA/SCL */
#define TRISC_REG       (*((volatile unsigned char*)0x87))
/*
 * I2C Pin Mapping:
 * SCL = RC3 (pin 18)
 * SDA = RC4 (pin 23)
 */
#define I2C_SCL_BIT     3
#define I2C_SDA_BIT     4

/* Baud rate for I2C:
 * SSPADD = (Fosc / (4 * Freq_I2C)) - 1
 * For 100kHz @ 4MHz: SSPADD = (4000000 / 400000) - 1 = 9
 * For 400kHz @ 4MHz: SSPADD = (4000000 / 1600000) - 1 = 1 (approx)
 */
#define I2C_100KHZ_4MHZ   9
#define I2C_400KHZ_4MHZ   1

#endif /* I2C_PRIVATE_H */
