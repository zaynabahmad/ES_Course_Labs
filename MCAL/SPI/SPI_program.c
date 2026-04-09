#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

#include "../../SERVICES/BIT_MATH.h"

void SPI_Init(void)
{
    CLR_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);
    CLR_BIT(TRISC, 5);

    SSPCON = SPI_CLOCK_MODE;

    SET_BIT(SSPCON, SSPEN);
}

u8 SPI_Transfer(u8 byte)
{
    SSPBUF = byte;

    while (!GET_BIT(PIR1, SSPIF));

    CLR_BIT(PIR1, SSPIF);

    return SSPBUF;
}