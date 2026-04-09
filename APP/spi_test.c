#include "app_tests.h"
#include "../MCAL/SPI/SPI_Interface.h"

static volatile u8 APP_SPI_LastByte = 0;
static SPI_ConfigType APP_SPI_Config = {0x01, 0, 1, 1};

void APP_SPI_Test(void)
{
    SPI_Init(&APP_SPI_Config);
    APP_SPI_LastByte = SPI_Transfer(0x55);
}
