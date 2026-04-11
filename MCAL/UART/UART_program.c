#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"
#include "../../SERVICES/BIT_MATH.h"

void UART_Init(u32 baud_rate)
{
    u32 spbrg_value;

    /* High-speed async UART
       baud = Fosc / (16 * (SPBRG + 1))
    */
    spbrg_value = (UART_FOSC_HZ / (16UL * baud_rate)) - 1UL;

    if(spbrg_value > 255UL)
    {
        spbrg_value = 255UL;
    }

    SPBRG = (u8)spbrg_value;

    /* BRGH = 1 */
    SET_BIT(TXSTA, BRGH_BIT);

    /* Async mode */
    CLR_BIT(TXSTA, SYNC_BIT);

    /* Enable serial port */
    SET_BIT(RCSTA, SPEN_BIT);

    /* UART pins mode */
    SET_BIT(TRISC, 6);
    SET_BIT(TRISC, 7);

    /* Enable transmitter and receiver */
    SET_BIT(TXSTA, TXEN_BIT);
    SET_BIT(RCSTA, CREN_BIT);
}

void UART_Init9600(void)
{
    UART_Init(9600);
}

void UART_WriteChar(u8 tx_byte)
{
    while(GET_BIT(PIR1, TXIF_BIT) == 0)
    {
    }

    TXREG = tx_byte;
}

u8 UART_IsRxReady(void)
{
    return GET_BIT(PIR1, RCIF_BIT);
}

u8 UART_ReadChar(void)
{
    /* Handle overrun error */
    if(GET_BIT(RCSTA, OERR_BIT))
    {
        CLR_BIT(RCSTA, CREN_BIT);
        SET_BIT(RCSTA, CREN_BIT);
    }

    while(GET_BIT(PIR1, RCIF_BIT) == 0)
    {
    }

    return RCREG;
}

void UART_WriteText(char *str)
{
    while(*str != '\0')
    {
        UART_WriteChar(*str);
        str++;
    }
}

void UART_WriteNewLine(void)
{
    UART_WriteChar('\r');
    UART_WriteChar('\n');
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
        digits[i] = (number % 10U) + '0';
        number /= 10U;
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

    int_part = temp_x100 / 100U;
    frac1 = (temp_x100 / 10U) % 10U;
    frac2 = temp_x100 % 10U;

    UART_WriteU16(int_part);
    UART_WriteChar('.');
    UART_WriteChar(frac1 + '0');
    UART_WriteChar(frac2 + '0');
}