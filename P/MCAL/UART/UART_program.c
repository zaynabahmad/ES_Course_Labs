/* ============================================================
 * UART_program.c  -  UART driver implementation
 * Target : PIC16F877A  |  Compiler : mikroC Pro for PIC
 * ============================================================ */

#include "UART_interface.h"
#include "UART_config.h"

/* Baud rate register value (BRGH=1 formula: FOSC / (16 * baud) - 1) */
#define SPBRG_VALUE     ((FOSC / (16UL * UART_BAUDRATE)) - 1u)

/* ------------------------------------------------------------ */
void UART_Init(void)
{
    SPBRG       = SPBRG_VALUE;  /* Set baud rate       */
    TXSTA.B2    = 1;            /* BRGH = 1 (high speed)*/
    TXSTA.B5    = 1;            /* TXEN = 1 (TX enable) */
    RCSTA.B7    = 1;            /* SPEN = 1 (port on)   */
    RCSTA.B4    = 1;            /* CREN = 1 (RX enable) */
}

/* ------------------------------------------------------------ */
void UART_SendChar(char d)
{
    while (!PIR1.TXIF);         /* Wait until TX buffer empty */
    TXREG = d;
}

/* ------------------------------------------------------------ */
char UART_ReceiveChar(void)
{
    while (!PIR1.RCIF);         /* Wait until byte received   */
    return RCREG;
}

/* ------------------------------------------------------------ */
void UART_SendString(char *str)
{
    while (*str)
    {
        UART_SendChar(*str);
        str++;
    }
}
