#include "../MCAL/SPI/spi_interface.h"
#include "../SERVICES/STD_TYPES.h"

void SPI_Test(void)
{
    u8 data_to_send = 0x55;
    u8 received_data;

    SPI_Init();

    while(1)
    {
        received_data = SPI_Transmit(data_to_send);
        data_to_send ^= 0xFF;   /* toggle between 0x55 and 0xAA */
    }
}