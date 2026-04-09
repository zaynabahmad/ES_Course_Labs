#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/SPI/SPI_interface.h"
#include "spi_test.h"

#define SUCCESS_LED_PORT  GPIO_PORTB
#define SUCCESS_LED_PIN   GPIO_PIN0

// A small delay between transmissions
static void APP_Delay(void)
{
    unsigned int i;
    for(i = 0; i < 50000; i++);
}

void APP_TestSPI(void)
{
    u8 received_data;

    // Initialize GPIO
    GPIO_Init();
    GPIO_SetPinDirection(SUCCESS_LED_PORT, SUCCESS_LED_PIN, GPIO_OUTPUT);

    // Initialize SPI as Master
    SPI_Master_Init();

    // Infinite Loop
    while(1)
    {
        // Transmit 0x41 ('A') and capture whatever comes back
        received_data = SPI_Transfer(0x41);

        // If Loopback is successful, the data should match exactly
        if(received_data == 0x41) 
        {
            GPIO_SetPinValue(SUCCESS_LED_PORT, SUCCESS_LED_PIN, GPIO_HIGH);
        } 
        else 
        {
            GPIO_SetPinValue(SUCCESS_LED_PORT, SUCCESS_LED_PIN, GPIO_LOW);
        }

        APP_Delay();
    }
}