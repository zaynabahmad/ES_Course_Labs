#include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/USART/USART_Interface.h"

void APP_Test_SPI(void)
{
    static u8 Local_u8InitDone = 0;
    u8 Local_u8TestData = 'S';
    u8 Local_u8ReceivedData = 0;

    if (Local_u8InitDone == 0)
    {

        SPI_voidMasterInit();
        UART_Write('S'); UART_Write('P'); UART_Write('I'); UART_Write(':');
        Local_u8InitDone = 1;
    }


    Local_u8ReceivedData = SPI_u8Transceive(Local_u8TestData);


    if (Local_u8ReceivedData == Local_u8TestData)
    {
        UART_Write('O');
        UART_Write('K');
    }
    else
    {
        UART_Write('E');
    }

    UART_Write('\r');
    UART_Write('\n');


    Delay_ms(1000);
}