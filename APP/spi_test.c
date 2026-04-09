#include "app_tests.h"

#include "../MCAL/SPI/SPI_Interface.h"

static volatile unsigned char APP_LastSpiData = 0;

void APP_Test_SPI(void)
{
    SPI_MasterInit(SPI_MASTER_FOSC_16);
    APP_LastSpiData = SPI_Transceive(0x55U);
    (void)APP_LastSpiData;
}
