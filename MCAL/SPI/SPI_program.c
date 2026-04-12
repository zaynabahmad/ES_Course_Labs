#include "SPI_interface.h"
#include "SPI_private.h"

void SPI_Init(void)
{
    TRISC5_bit = 0;   /* sck output */
    TRISC4_bit = 1;   /* sdi input  */
    TRISC3_bit = 0;   /* sdo output */

    SSPSTAT = 0x00;
    SSPCON  = 0x21;   /* master mode, fosc/16 */
}

unsigned char SPI_Transfer(unsigned char data)
{
    SSPBUF = data;
    while (!SSPIF_bit);
    SSPIF_bit = 0;
    return SSPBUF;
}