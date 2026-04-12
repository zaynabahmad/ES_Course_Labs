#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/SPI/SPI_interface.h"

void SPI_Test(void)
{
    u8 i;
    u32 j;

    SPI_Init(SPI_MODE_MASTER);

    // Send data pattern
    for (i = 0; i < 5; i++)
    {
        (void)SPI_TransmitReceive(0xA0 + i);
        for (j = 0; j < 15000; j++)
            ;
    }

    // Write sequence
    SPI_Write(0xAA);
    for (j = 0; j < 10000; j++)
        ;

    SPI_Write(0x55);
    for (j = 0; j < 10000; j++)
        ;

    SPI_Write(0xFF);
    for (j = 0; j < 20000; j++)
        ;

    // Test different clock rates
    SPI_SetClockRate(SPI_CLK_FOSC_64);
    SPI_Write(0xFE);

    for (j = 0; j < 30000; j++)
        ;
}
