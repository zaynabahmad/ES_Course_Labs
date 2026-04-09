#include "SPI_Interface.h"

void spi_test_run(void) {
    SPI_MasterInit();

    SPI_Tranceive(0xAA);
}