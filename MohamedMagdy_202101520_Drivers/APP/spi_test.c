#include "../MCAL/SPI/SPI_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "spi_test.h"

#define SPI_CS_PORT     GPIO_PORTD
#define SPI_CS_PIN      GPIO_PIN4

static void SPI_CS_Low(void)
{
    GPIO_SetPinValue(SPI_CS_PORT, SPI_CS_PIN, GPIO_LOW);
}

static void SPI_CS_High(void)
{
    GPIO_SetPinValue(SPI_CS_PORT, SPI_CS_PIN, GPIO_HIGH);
}

static void delay(void)
{
    unsigned int i;
    for(i = 0; i < 10000U; i++) { ; }
}

void SPI_Test(void)
{
    u8 rx_byte;
    u8 i;
    u8 test_data[4] = {0xA5, 0x5A, 0xDE, 0xAD};

    GPIO_SetPinDirection(SPI_CS_PORT, SPI_CS_PIN, GPIO_OUTPUT);
    SPI_CS_High();

    SPI_MasterInit();

    delay();

    SPI_CS_Low();
    for(i = 0; i < 4U; i++)
    {
        SPI_Write(test_data[i]);
    }
    SPI_CS_High();
    delay();

    SPI_CS_Low();
    for(i = 0; i < 4U; i++)
    {
        rx_byte = SPI_Read();
        (void)rx_byte;
    }
    SPI_CS_High();
    delay();

    SPI_CS_Low();
    rx_byte = SPI_Transceive(0x55);
    (void)rx_byte;
    SPI_CS_High();

    SPI_Disable();
}
