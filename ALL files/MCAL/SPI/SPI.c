#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"

void SPI_Init(void)
{
    /* Configure SPI Master mode */

    /* Clear control register */
    SSPCON = 0x00;

    /* Set clock rate */
    #if SPI_CLOCK_RATE == 0
        SSPCON |= 0x00;   // Fosc/4
    #elif SPI_CLOCK_RATE == 1
        SSPCON |= 0x01;   // Fosc/16
    #elif SPI_CLOCK_RATE == 2
        SSPCON |= 0x02;   // Fosc/64
    #endif

    /* Enable SPI */
    SET_BIT(SSPCON, SSPEN);
}

u8 SPI_Transceive(u8 Data)
{
    /* Send data */
    SSPBUF = Data;

    /* Wait until transmission complete */
    while(!GET_BIT(SSPSTAT, BF));

    /* Return received data */
    return SSPBUF;
}