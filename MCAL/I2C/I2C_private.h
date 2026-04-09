#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

/*
 * PIC16F877A – MSSP module in I2C Master mode
 *
 * Hardware pins (fixed by silicon):
 *   RC3 = SCL  (clock)  – open-drain, needs pull-up resistor (4.7k typical)
 *   RC4 = SDA  (data)   – open-drain, needs pull-up resistor (4.7k typical)
 */

/* ── SSPBUF – SSP Shift Buffer           (Bank 0: 0x13) ── */
#define I2C_SSPBUF      (*(volatile unsigned char*)0x13)

/* ── SSPCON – SSP Control Register       (Bank 0: 0x14) ── */
#define I2C_SSPCON      (*(volatile unsigned char*)0x14)
#define I2C_SSPCON_SSPEN    5   /* SSP Enable                        */
#define I2C_SSPCON_SSPM3    3   /* Mode select bits [3:0]            */
#define I2C_SSPCON_SSPM2    2
#define I2C_SSPCON_SSPM1    1
#define I2C_SSPCON_SSPM0    0

/* ── SSPCON2 – SSP Control Register 2    (Bank 1: 0x91) ── */
#define I2C_SSPCON2     (*(volatile unsigned char*)0x91)
#define I2C_SSPCON2_SEN     0   /* Start condition enable            */
#define I2C_SSPCON2_RSEN    1   /* Repeated Start enable             */
#define I2C_SSPCON2_PEN     2   /* Stop condition enable             */
#define I2C_SSPCON2_RCEN    3   /* Receive enable                    */
#define I2C_SSPCON2_ACKEN   4   /* ACK sequence enable               */
#define I2C_SSPCON2_ACKDT   5   /* ACK data (0=ACK, 1=NACK)         */
#define I2C_SSPCON2_ACKSTAT 6   /* ACK status (0=ACK received)       */

/* ── SSPSTAT – SSP Status Register       (Bank 1: 0x94) ── */
#define I2C_SSPSTAT     (*(volatile unsigned char*)0x94)
#define I2C_SSPSTAT_BF      0   /* Buffer Full                       */
#define I2C_SSPSTAT_R_W     2   /* R/W bit (master)                  */
#define I2C_SSPSTAT_S       3   /* Start bit detected                */
#define I2C_SSPSTAT_P       4   /* Stop bit detected                 */
#define I2C_SSPSTAT_D_A     5   /* Data / address                    */

/* ── SSPADD – Baud Rate Register         (Bank 1: 0x93) ── */
#define I2C_SSPADD      (*(volatile unsigned char*)0x93)

/* ── PIR1 – Peripheral Interrupt Flag    (Bank 0: 0x0C) ── */
#define I2C_PIR1        (*(volatile unsigned char*)0x0C)
#define I2C_PIR1_SSPIF      3   /* SSP Interrupt Flag                */

/* ── PIR2 – Peripheral Interrupt Flag 2  (Bank 0: 0x0D) ── */
#define I2C_PIR2        (*(volatile unsigned char*)0x0D)
#define I2C_PIR2_BCLIF      3   /* Bus Collision Interrupt Flag      */

/* ── TRISC – Port C direction            (Bank 1: 0x87) ── */
#define I2C_TRISC       (*(volatile unsigned char*)0x87)
#define I2C_TRISC3          3   /* SCL pin */
#define I2C_TRISC4          4   /* SDA pin */

/* ── SSPM[3:0] = 0b1000 → I2C Master mode ── */
#define I2C_MASTER_MODE     0x08

#endif /* I2C_PRIVATE_H */
