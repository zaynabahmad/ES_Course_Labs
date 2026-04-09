#include "spi.h"
#include "led.h"

extern int SPI_TxData;
extern int SPI_RxData;

void SPI_Test(void)
{
    SPI_Init();
    LED_Init();

    while(1)
    {
        SPI_SelectSlave();
        SPI_TxData = 0xAB;
        SPI_Transceive();
        SPI_DeselectSlave();

        if(SPI_RxData == 0xAB)
            LED_On();
        else
            LED_Off();

        Delay_ms(500);
    }
}