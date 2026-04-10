#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"
#include "../../SERVICES/Bit_Math.h"

void UART_Init(void)
{
    CLR_BIT(TRISC_REG, 6);                  /* TX pin as output */
    SET_BIT(TRISC_REG, 7);                  /* RX pin as input  */

    TXSTA_REG = 0x20;                       /* Asynchronous, 8-bit, BRGH = 0, TX enabled */
    RCSTA_REG = 0x90;                       /* Serial port enabled, continuous receive */
    SPBRG_REG = UART_SPBRG_VALUE;
}

/* Changed parameter from 'data' to 'tx_byte' */
void UART_SendByte(u8 tx_byte)
{
    while (!GET_BIT(TXSTA_REG, TRMT_BIT));
    TXREG_REG = tx_byte;
}

void UART_SendString(const char *str)
{
    while (*str != '\0') {
        UART_SendByte((u8)*str);
        str++;
    }
}

void UART_SendNumber(u16 number)
{
    /* Moved variable declarations to the VERY TOP of the function for mikroC compatibility */
    char buffer[6];
    u8 index = 0;

    if (number == 0U) {
        UART_SendByte('0');
        return;
    }

    while (number != 0U) {
        buffer[index++] = (char)('0' + (number % 10U));
        number /= 10U;
    }

    while (index-- > 0U) {
        UART_SendByte((u8)buffer[index]);
    }
}

void UART_SendTemperature(u16 temperatureC)
{
    UART_SendNumber(temperatureC);
    UART_SendString(" C");
}