#include "UART_interface.h"
#include "UART_private.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

void UART_Init(void) 
{
    /* For 9600 Baud at 4MHz: SPBRG = 6 */
    SPBRG = 6;

    /* TXSTA: Asynchronous, 8-bit, Transmit Enabled */
    TXSTA = 0x20; 

    /* RCSTA: Serial Port Enabled, Continuous Receive */
    RCSTA = 0x90; 
}

void UART_WriteChar(uint8 data) 
{
    /* Wait until the Transmit Shift Register is empty (TRMT) */
    while (GET_BIT(TXSTA, 1) == 0);
    
    /* Load data into transmit register */
    TXREG = data;
}

void UART_WriteText(char *text) 
{
    uint8 i = 0;
    while (text[i] != '\0') 
    {
        UART_WriteChar(text[i]);
        i++;
    }
}