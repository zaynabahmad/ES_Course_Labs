#include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../SERVICES/DELAY/DELAY_interface.h"

#define LATCH_PORT   GPIO_PORTB
#define LATCH_PIN    GPIO_PIN0

static void HC595_LatchPulse(void)
{
    GPIO_SetPinValue(LATCH_PORT, LATCH_PIN, GPIO_LOW);
    Delay_ms(1);
    GPIO_SetPinValue(LATCH_PORT, LATCH_PIN, GPIO_HIGH);
    Delay_ms(1);
    GPIO_SetPinValue(LATCH_PORT, LATCH_PIN, GPIO_LOW);
}

void APP_SPI_Test(void)
{
    u8 pattern = 0x01;

    GPIO_SetPinDirection(LATCH_PORT, LATCH_PIN, GPIO_OUTPUT);
    GPIO_SetPinValue(LATCH_PORT, LATCH_PIN, GPIO_LOW);

       MSPI_InitMaster(SPI_MASTER_FOSC_DIV16, SPI_MODE1);

    while(1)
    {
        MSPI_WriteByte(pattern);
        HC595_LatchPulse();

        pattern <<= 1;
        if(pattern == 0)
        {
            pattern = 0x01;
        }

        Delay_ms(500);
    }
}