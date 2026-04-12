#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/SPI/SPI_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

#define SPI_CS_PORT    GPIO_PORTA
#define SPI_CS_PIN     GPIO_PIN3

void SPI_Test(void)
{
    u8 ReceivedByte;

    /* Initialize SPI */
    SPI_Init();

    /* Configure Chip Select pin as output, deselect slave */
    GPIO_SetPinDirection(SPI_CS_PORT, SPI_CS_PIN, GPIO_OUTPUT);
    GPIO_SetPinValue(SPI_CS_PORT, SPI_CS_PIN, GPIO_HIGH);

    /* Select slave */
    GPIO_SetPinValue(SPI_CS_PORT, SPI_CS_PIN, GPIO_LOW);

    /* Send a byte and receive response */
    SPI_SendByte(0xAB);
    ReceivedByte = SPI_ReceiveByte();

    /* Deselect slave */
    GPIO_SetPinValue(SPI_CS_PORT, SPI_CS_PIN, GPIO_HIGH);

    /* Loopback test: send and receive simultaneously */
    GPIO_SetPinValue(SPI_CS_PORT, SPI_CS_PIN, GPIO_LOW);
    ReceivedByte = SPI_Transceive(0x55);
    GPIO_SetPinValue(SPI_CS_PORT, SPI_CS_PIN, GPIO_HIGH);

    (void)ReceivedByte;    /* Suppress unused variable warning */
}
