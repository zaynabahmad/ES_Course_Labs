/*
 * i2c.c
 * I2C (TWI/MSSP) Master Driver for PIC16F877A
 *
 * SDA = RC4, SCL = RC3
 * Both pins need 4.7 kΩ pull-up resistors to VDD in Proteus.
 *
 * SSPADD formula:
 *   SSPADD = (F_CPU / (4 * F_SCL)) - 1
 *   100 kHz @ 8 MHz => SSPADD = (8000000 / 400000) - 1 = 19
 */

#include "i2c.h"
#include "../common_macros.h"

/* ---- Internal helper: wait until any ongoing MSSP operation finishes ---- */
static void I2C_waitIdle(void) {
    /* Wait while MSSP is busy: any of ACKEN, RCEN, PEN, RSEN, SEN are set,
       or the ACK sequence is in progress (SSPIF not yet set)               */
    while ((SSPCON2 & 0x1F) || (SSPSTATbits.R_nW));
}

/* ------------------------------------------------------------------ */

void I2C_init(uint32 sclFreq) {
    /* RC3 (SCL) and RC4 (SDA) as inputs — MSSP controls the pins */
    TRISCbits.TRISC3 = 1;
    TRISCbits.TRISC4 = 1;

    /* Baud rate */
    SSPADD = (uint8)((F_CPU / (4UL * sclFreq)) - 1);

    /* SSPSTAT: Slew-rate control disabled for 100 kHz (SMP=1) */
    SSPSTAT = 0x80;   /* SMP=1, CKE=0 */

    /* SSPCON: SSPEN=1, SSPM=1000 (I2C Master mode) */
    SSPCON  = 0x28;   /* SSPEN=1, SSPM=1000 */

    /* SSPCON2: clear all control bits */
    SSPCON2 = 0x00;
}

void I2C_start(void) {
    I2C_waitIdle();
    SSPCON2bits.SEN = 1;        /* Initiate START condition */
    while (SSPCON2bits.SEN);    /* Wait until hardware clears SEN */
}

void I2C_repeatedStart(void) {
    I2C_waitIdle();
    SSPCON2bits.RSEN = 1;       /* Initiate REPEATED START */
    while (SSPCON2bits.RSEN);
}

void I2C_stop(void) {
    I2C_waitIdle();
    SSPCON2bits.PEN = 1;        /* Initiate STOP condition */
    while (SSPCON2bits.PEN);
}

uint8 I2C_writeByte(uint8 data) {
    I2C_waitIdle();
    SSPBUF = data;              /* Load data — transmission starts automatically */
    while (!PIR1bits.SSPIF);    /* Wait for transmission complete                */
    PIR1bits.SSPIF = 0;         /* Clear interrupt flag                          */
    return SSPCON2bits.ACKSTAT; /* 0 = ACK received, 1 = NACK received           */
}

uint8 I2C_readByteACK(void) {
    I2C_waitIdle();
    SSPCON2bits.RCEN = 1;       /* Enable receive mode */
    while (!PIR1bits.SSPIF);
    PIR1bits.SSPIF = 0;
    uint8 data = SSPBUF;

    /* Send ACK */
    I2C_waitIdle();
    SSPCON2bits.ACKDT = 0;      /* ACK value = 0 */
    SSPCON2bits.ACKEN = 1;      /* Initiate ACK  */
    while (SSPCON2bits.ACKEN);
    return data;
}

uint8 I2C_readByteNACK(void) {
    I2C_waitIdle();
    SSPCON2bits.RCEN = 1;       /* Enable receive mode */
    while (!PIR1bits.SSPIF);
    PIR1bits.SSPIF = 0;
    uint8 data = SSPBUF;

    /* Send NACK (last byte) */
    I2C_waitIdle();
    SSPCON2bits.ACKDT = 1;      /* NACK value = 1 */
    SSPCON2bits.ACKEN = 1;      /* Initiate NACK  */
    while (SSPCON2bits.ACKEN);
    return data;
}
