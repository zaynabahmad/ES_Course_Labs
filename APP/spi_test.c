#include "../MCAL/SPI/SPI_interface.h"

void SPI_Test()
{
    SPI_InitMaster();

    while (1)
    {
        SPI_Transfer('A'); // send data continuously
    }
}