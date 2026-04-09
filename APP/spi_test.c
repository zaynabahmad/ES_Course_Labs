#include "D:/ES-Project-Lab/SERVICES/std_types.h"
#include "D:/ES-Project-Lab/MCAL/GPIO/gpio.h"
#include "D:/ES-Project-Lab/MCAL/SPI/spi_interface.h"
#include "D:\ES-Project-Lab\HAL\led_interface.h"
void app_spi_test(void)
{
    u8 txValue = 0;
    u8 rxValue = 0;
    u8 ledState = 0;
    u16 delayValue = 0;

    LED_Init(GPIO_PORTD, GPIO_PIN0);

    SPI_Init();

    while(1)
    {
        rxValue = SPI_Transfer(txValue);
        (void)rxValue;

        ledState ^= 1;
        GPIO_setPinValue(GPIO_PORTD, GPIO_PIN0, ledState);

        txValue++;

        for(delayValue = 0; delayValue < 10000; delayValue++)
        {
            ;
        }
    }
}