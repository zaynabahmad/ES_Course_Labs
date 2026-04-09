#include "spi_interface.h"
#include "spi_private.h"
#include "spi_config.h"
#include "../../SERVICES/bit_ops.h"

void SPI_Configure(void)
{
    BIT_CLEAR(TRISC_REG, 3);  /* SCK output */
    BIT_SET(TRISC_REG, 4);    /* SDI input */
    BIT_CLEAR(TRISC_REG, 5);  /* SDO output */

    SSPCON_REG = SPI_CLOCK_SETTING;
    BIT_SET(SSPCON_REG, SSPEN);
}

u8 SPI_ExchangeByte(u8 data_out)
{
    SSPBUF_REG = data_out;
    while(!BIT_READ(PIR1_REG, SSPIF));
    BIT_CLEAR(PIR1_REG, SSPIF);
    return SSPBUF_REG;
}