#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/SPI/SPI_interface.h"

void SPI_Test(void) {
    u8 Local_u8ReceivedData = 0;

    SPI_voidInitMaster();

    /* Transmit dummy byte to generate clock and receive data */
    Local_u8ReceivedData = SPI_u8Transceive(0x55);
}