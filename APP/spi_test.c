#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/SPI/SPI_interface.h"
#include "../HAL/LED/LED_interface.h"

#define SPI_LED_PORT    GPIO_PORTA
#define SPI_LED_PIN     GPIO_PIN0

void SPI_Test(void)
{
    u8 rx1, rx2, rx3;
    u8 passed = 1;

    GPIO_Init();
    LED_Init(SPI_LED_PORT, SPI_LED_PIN);
    LED_Off(SPI_LED_PORT, SPI_LED_PIN);

    SPI_Init(SPI_MODE_0, SPI_FOSC_16);

    for(u16 i = 0; i < 5000; i++);  // Module settle

    // Send 3 patterns and verify echo-back
    rx1 = SPI_Transfer(0xAB);
    rx2 = SPI_Transfer(0x55);
    rx3 = SPI_Transfer(0xA5);

    if(rx1 != 0xAB) passed = 0;
    if(rx2 != 0x55) passed = 0;
    if(rx3 != 0xA5) passed = 0;

    passed ? LED_On(SPI_LED_PORT, SPI_LED_PIN) : LED_Off(SPI_LED_PORT, SPI_LED_PIN);
}
