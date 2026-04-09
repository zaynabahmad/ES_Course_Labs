#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"

#include "../../SERVICES/BIT_MATH.h"

void SPI_MasterInit(u8 ClockSelect)
{
    CLR_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);
    CLR_BIT(TRISC, 5);

    CLR_BIT(TRISA, 5);

    SSPSTAT = 0x00;
    SSPCON = (u8)(0x20 | (ClockSelect & 0x03));
}

void SPI_SlaveInit(void)
{
    SET_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);
    CLR_BIT(TRISC, 5);
    SET_BIT(TRISA, 5);

    SSPSTAT = 0x00;
    SSPCON = 0x24;
}

u8 SPI_Transceive(u8 Data)
{
    SSPBUF = Data;
    while (GET_BIT(SSPSTAT, BF_BIT) == 0U)
    {
    }

    return SSPBUF;
}
