#include "../SERVICES/STD_TYPES.h"
#include "spi_test.h"
#include "../MCAL/SPI/SPI_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void SPI_TEST_Run(void)
{
    u8 tx_byte = 0x55;
    u8 rx_byte;

    LED_Init(GPIO_PORTB, GPIO_PIN0);
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Off(GPIO_PORTB, GPIO_PIN0);
    LED_Off(GPIO_PORTB, GPIO_PIN1);

    SPI_Init();

    rx_byte = SPI_Transfer(tx_byte);

    if (rx_byte == tx_byte)
        LED_On(GPIO_PORTB, GPIO_PIN0);
    else
        LED_On(GPIO_PORTB, GPIO_PIN1);

    while (1);
}