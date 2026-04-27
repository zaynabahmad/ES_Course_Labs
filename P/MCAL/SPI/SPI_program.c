/* ============================================================
 * SPI_program.c  -  SPI (MSSP) driver implementation
 * Target : PIC16F877A  |  Compiler : mikroC Pro for PIC
 * ============================================================ */

#include "SPI_interface.h"

/* ------------------------------------------------------------ */
void SPI_Init(void)
{
    TRISC3_bit = 0;     /* RC3/SCK  = output (master clock) */
    TRISC4_bit = 1;     /* RC4/SDI  = input  (MISO)         */
    TRISC5_bit = 0;     /* RC5/SDO  = output (MOSI)         */

    SSPSTAT = 0x00;     /* Sample at middle, CKE=0          */
    SSPCON  = 0x21;     /* Master mode, SPI clock Fosc/16   */
}

/* ------------------------------------------------------------ */
/* Sends one byte and simultaneously returns the received byte */
char SPI_Transmit(char d)
{
    SSPBUF = d;
    while (!SSPIF_bit);     /* Wait for transfer complete */
    SSPIF_bit = 0;
    return SSPBUF;
}
