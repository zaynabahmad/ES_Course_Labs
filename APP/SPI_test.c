#include "../MCAL/SPI/SPI_interface.h"
void SPI_test(void) {
    SPI_voidInitMaster();
    while(1) {
        SPI_u8Transceive('A');
        Delay_ms(100);
    }
}