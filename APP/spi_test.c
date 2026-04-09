#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/SPI/SPI_interface.h"

void SPI_Test(void) {
    SPI_voidInitMaster();
    (void)SPI_u8Transceive(0x55); 
}