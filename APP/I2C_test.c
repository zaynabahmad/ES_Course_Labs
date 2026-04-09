#include "../MCAL/I2C/I2C_Interface.h"
#include "../MCAL/USART/USART_Interface.h"

void APP_Test_I2C(void)
{
    static u8 Local_u8InitDone = 0;
    u8 Local_u8ErrorStatus = 0;

    if (Local_u8InitDone == 0)
    {

        I2C_voidMasterInit();
        Local_u8InitDone = 1;
        UART_Write('I'); UART_Write('2'); UART_Write('C'); UART_Write(':');
    }


    I2C_voidStart();


    Local_u8ErrorStatus = I2C_u8WriteByte(0xA0);

    if (Local_u8ErrorStatus == I2C_ACK_RECEIVED)
    {

        I2C_u8WriteByte(0xFF);
        UART_Write('O'); UART_Write('K');
    }
    else
    {

        UART_Write('?');
    }


    I2C_voidStop();

    UART_Write('\r');
    UART_Write('\n');

    Delay_ms(2000);
}