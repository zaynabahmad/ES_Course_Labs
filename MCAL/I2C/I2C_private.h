#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

/* Synchronous Serial Port Control Register */
#define SSPCON    (*(volatile unsigned char*)0x14)

/* MSSP Control Register 2 */
#define SSPCON2   (*(volatile unsigned char*)0x91)

/* MSSP Status Register */
#define SSPSTAT   (*(volatile unsigned char*)0x94)

/* MSSP Buffer Register (send/receive data) */
#define SSPBUF    (*(volatile unsigned char*)0x13)

/* Baud Rate Generator Register */
#define SSPADD    (*(volatile unsigned char*)0x93)

/* Peripheral Interrupt Request Register 1 */
#define PIR1      (*(volatile unsigned char*)0x0C)

/* Data Direction for RC3 (SCL) and RC4 (SDA) */
#define TRISC     (*(volatile unsigned char*)0x87)

/* ---- SSPCON bit positions ---- */
#define SSPCON_SSPEN   3    /* SSP Enable                  */
#define SSPCON_SSPM0   0    /* SSP Mode select bit 0       */
#define SSPCON_SSPM1   1    /* SSP Mode select bit 1       */
#define SSPCON_SSPM2   2    /* SSP Mode select bit 2       */
#define SSPCON_SSPM3   3    /* SSP Mode select bit 3       */

/* ---- SSPCON2 bit positions ---- */
#define SSPCON2_SEN    0    /* Start condition enable      */
#define SSPCON2_RSEN   1    /* Repeated start enable       */
#define SSPCON2_PEN    2    /* Stop condition enable       */
#define SSPCON2_RCEN   3    /* Receive enable              */
#define SSPCON2_ACKEN  4    /* ACK sequence enable         */
#define SSPCON2_ACKDT  5    /* ACK data (0=ACK, 1=NACK)   */
#define SSPCON2_ACKSTAT 6   /* ACK status (0=ACK received) */

/* ---- SSPSTAT bit positions ---- */
#define SSPSTAT_BF     0    /* Buffer full flag            */
#define SSPSTAT_R_W    2    /* Read/Write bit              */

/* ---- PIR1 bit positions ---- */
#define PIR1_SSPIF     3    /* SSP interrupt flag          */

/* ---- I2C Master mode value for SSPCON bits 3:0 ---- */
/* 1000 = I2C Master mode, clock = Fosc/(4*(SSPADD+1)) */
#define I2C_MASTER_MODE   0x08u

#define I2C_SSPADD_100K   19u

/* ---- RC3 = SCL (pin 3), RC4 = SDA (pin 4) ---- */
#define I2C_SCL_PIN   3u
#define I2C_SDA_PIN   4u

#endif /* I2C_PRIVATE_H */