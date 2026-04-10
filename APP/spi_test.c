#include "APP_Tests.h"
#include "../MCAL/SPI/SPI_Interface.h"

void APP_Test_SPI(void)
{
    SPI_MasterInit();
    while(1)
    {
        SPI_Transfer('A'); // Send dummy data continuously
    }
}
