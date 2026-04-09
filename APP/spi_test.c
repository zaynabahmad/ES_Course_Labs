#include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "spi_test.h"

/* RA1 used as software SS (chip-select) */
#define SPI_SS_PORT  GPIO_PORTA
#define SPI_SS_PIN   GPIO_PIN1

void spi_test_run(void)
{
    u8 rx;

    SPI_Init();

    /* Configure SS pin as output, idle high */
    GPIO_SetPinDirection(SPI_SS_PORT, SPI_SS_PIN, GPIO_OUTPUT);
    GPIO_SetPinValue(SPI_SS_PORT, SPI_SS_PIN, GPIO_HIGH);

    /* Assert SS */
    GPIO_SetPinValue(SPI_SS_PORT, SPI_SS_PIN, GPIO_LOW);

    /* Transmit a byte */
    SPI_Transmit(0xA5);

    /* Receive a byte */
    rx = SPI_Receive();
    (void)rx;

    /* Full-duplex exchange */
    SPI_TransmitReceive(0x3C, &rx);
    (void)rx;

    /* Deassert SS */
    GPIO_SetPinValue(SPI_SS_PORT, SPI_SS_PIN, GPIO_HIGH);
}
