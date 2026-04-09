#include "spi.h"
#include "bit_math.h"

int SPI_TxData = 0;
int SPI_RxData = 0;

void SPI_Init(void)
{
    CLR_BIT(TRISC, 3);
    CLR_BIT(TRISC, 5);
    SET_BIT(TRISC, 4);
    CLR_BIT(TRISA, 1);
    SET_BIT(PORTA, 1);
    SSPCON  = 0x20;
    SSPSTAT = 0x00;
}

void SPI_SelectSlave(void)
{
    CLR_BIT(PORTA, 1);
}

void SPI_DeselectSlave(void)
{
    SET_BIT(PORTA, 1);
}

int SPI_Transceive(void)
{
    SSPBUF = SPI_TxData;
    while(GET_BIT(SSPSTAT, 0) == 0);
    SPI_RxData = SSPBUF;
    return SPI_RxData;
}