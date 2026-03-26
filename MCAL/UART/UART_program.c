#include "UART_interface.h"
#include "../GPIO/GPIO_private.h"
#include "../../SERVICES/BIT_MATH.h"

void UART_Init9600(void)
{
    /* RC6 = TX output, RC7 = RX input */
    CLR_BIT(TRISC, 6);
    SET_BIT(TRISC, 7);
 
    UART1_Init(9600);
    Delay_ms(100);
}

void UART_WriteChar(u8 tx_byte)
{
    UART1_Write(tx_byte);
}

void UART_WriteText(char *str)
{
    UART1_Write_Text(str);
}

void UART_WriteNewLine(void)
{
    UART1_Write(13);
    UART1_Write(10);
}

void UART_WriteU16(u16 number)
{
    u8 digits[5];
    s8 i = 0;

    if(number == 0)
    {
        UART_WriteChar('0');
        return;
    }

    while(number > 0)
    {
        digits[i] = (number % 10) + '0';
        number /= 10;
        i++;
    }

    while(i > 0)
    {
        i--;
        UART_WriteChar(digits[i]);
    }
}

void UART_WriteTempCenti(u16 temp_x100)
{
    u16 int_part;
    u8 frac1, frac2;

    int_part = temp_x100 / 100;
    frac1 = (temp_x100 / 10) % 10;
    frac2 = temp_x100 % 10;

    UART_WriteU16(int_part);
    UART_WriteChar('.');
    UART_WriteChar(frac1 + '0');
    UART_WriteChar(frac2 + '0');
}