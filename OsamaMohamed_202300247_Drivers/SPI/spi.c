/*
 * spi.c
 * SPI Driver for PIC16F877A — MSSP module in SPI mode
 *
 * Mode 0,0: CKP=0 (idle low), CKE=1 (transmit on active-to-idle = falling)
 * This matches the most common SPI peripheral default.
 */

#include "spi.h"
#include "../common_macros.h"

void SPI_init(const SPI_Config *config) {
    /* Reset MSSP */
    SSPCON  = 0x00;
    SSPSTAT = 0x00;

    if (config->mode == SPI_MASTER) {
        /* SCK (RC3) output, SDO (RC5) output, SDI (RC4) input */
        TRISCbits.TRISC3 = 0;
        TRISCbits.TRISC5 = 0;
        TRISCbits.TRISC4 = 1;

        /* SS (RA5) as digital output, deassert high */
        TRISAbits.TRISA5  = 0;
        PORTAbits.RA5     = 1;

        /* SSPSTAT: CKE=1 (transmit on falling edge), SMP=0 (sample at middle) */
        SSPSTATbits.CKE = 1;
        SSPSTATbits.SMP = 0;

        /* SSPCON: CKP=0 (idle low), SSPM = clock select, SSPEN=1 */
        SSPCON = (uint8)(0x20 | (config->clock & 0x03));
        /* Bit 5 = SSPEN (enable), bits 3:0 = SSPM (clock) */

    } else { /* SPI_SLAVE */
        /* SCK (RC3) input, SDI (RC4) input, SDO (RC5) output, SS (RA5) input */
        TRISCbits.TRISC3 = 1;
        TRISCbits.TRISC4 = 1;
        TRISCbits.TRISC5 = 0;
        TRISAbits.TRISA5  = 1;

        /* SSPSTAT: CKE=1, SMP=0 (must be 0 in slave mode) */
        SSPSTATbits.CKE = 1;
        SSPSTATbits.SMP = 0;

        /* SSPCON: CKP=0, SSPM=0100 (Slave mode, SS pin control enabled) */
        SSPCON = 0x24;   /* SSPEN=1, SSPM=0100 */
    }
}

uint8 SPI_sendReceiveByte(uint8 data) {
    SSPBUF = data;                      /* Write to buffer — starts transmission */
    while (!SSPSTATbits.BF);           /* Wait until buffer full (receive done)  */
    return SSPBUF;                      /* Read received byte (also clears BF)   */
}

void SPI_sendString(const char *str) {
    while (*str)
        SPI_sendReceiveByte((uint8)(*str++));
}

void SPI_receiveString(char *buf, uint8 maxLen) {
    uint8 i = 0;
    char  c;
    while (i < maxLen - 1) {
        c = (char)SPI_sendReceiveByte(0xFF);  /* Send dummy byte to clock in data */
        if (c == '\0') break;
        buf[i++] = c;
    }
    buf[i] = '\0';
}
