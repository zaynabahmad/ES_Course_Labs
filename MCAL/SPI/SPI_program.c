#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

#include "../../SERVICES/BIT_MATH.h"

void SPI_Init(void)
{
#if SPI_MODE == SPI_MASTER

    /* Set directions */
    CLR_BIT(TRISC, 5); // SDO → output
    SET_BIT(TRISC, 4); // SDI → input
    CLR_BIT(TRISC, 3); // SCK → output

    /* Enable SPI + Master mode */
    SET_BIT(SSPCON, 5); // SSPEN

    /* Clock select */
    SSPCON &= 0b11110000;
    SSPCON |= SPI_CLOCK_RATE;

#else

    /* Slave mode */
    SET_BIT(TRISC, 4); // SDI input
    SET_BIT(TRISC, 3); // SCK input
    CLR_BIT(TRISC, 5); // SDO output

    SET_BIT(SSPCON, 5); // Enable SPI

#endif
}

u8 SPI_Transmit(u8 data)
{
    SSPBUF = data;

    while(!GET_BIT(SSPSTAT, 0)); // BF flag

    return SSPBUF;
}

u8 SPI_Receive(void)
{
    while(!GET_BIT(SSPSTAT, 0));

    return SSPBUF;
}