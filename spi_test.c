#include "../SERVICES/types.h"
#include "spi_test.h"
#include "../MCAL/SPI/spi_interface.h"
#include "../HAL/LED/led_interface.h"
#include "../MCAL/GPIO/gpio_interface.h"

void SPI_Test_Runner(void)
{
    u8 test_pattern = 0x5A;
    u8 received;

    LED_Setup(PORTB_ID, PIN0);
    LED_Setup(PORTB_ID, PIN1);
    LED_TurnOff(PORTB_ID, PIN0);
    LED_TurnOff(PORTB_ID, PIN1);

    SPI_Configure();
    received = SPI_ExchangeByte(test_pattern);

    if(received == test_pattern)
        LED_TurnOn(PORTB_ID, PIN0);
    else
        LED_TurnOn(PORTB_ID, PIN1);

    while(1);
}