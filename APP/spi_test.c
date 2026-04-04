/*
 * spi_test.c
 * Tests the SPI MCAL driver: master init, byte transmit, and byte receive.
 * Uses RC2 as a software chip-select (CS) line via GPIO.
 * No direct register access — uses only SPI_Interface.h API.
 */

#include "../MCAL/SPI/SPI_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "spi_test.h"

/* Software chip-select — drive low to select slave, high to deselect */
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

    /* Configure chip-select pin as output, idle high */
    GPIO_SetPinDirection(SPI_CS_PORT, SPI_CS_PIN, GPIO_OUTPUT);
    SPI_CS_High();

    /* Initialise SPI master (RC3=SCK, RC4=MISO, RC5=MOSI) */
    SPI_MasterInit();

    delay();

    /* --- Test: send 4 bytes to a slave device --- */
    SPI_CS_Low();

    for(i = 0; i < 4U; i++)
    {
        SPI_Write(test_data[i]);
    }

    SPI_CS_High();
    delay();

    /* --- Test: read 4 bytes from a slave (clocks out 0xFF) --- */
    SPI_CS_Low();

    for(i = 0; i < 4U; i++)
    {
        rx_byte = SPI_Read();
        (void)rx_byte;      /* In a real app, process the received data */
    }

    SPI_CS_High();
    delay();

    /* --- Test: simultaneous send/receive (transceive) --- */
    SPI_CS_Low();
    rx_byte = SPI_Transceive(0x55);
    (void)rx_byte;
    SPI_CS_High();

    /* Disable SPI when done */
    SPI_Disable();
}