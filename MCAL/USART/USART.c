#include "USART_Interface.h"
#include "../GPIO/GPIO_interface.h"

void (*UART_Callback)(u8) = 0;

void UART_RX_Init(void)
{
    SET_BIT(TXSTA, BRGH);
    SPBRG = (FOSC / (16UL * UART_BAUDRATE)) - 1;   /* was hardcoded 25 */
    CLR_BIT(TXSTA, SYNC);
    SET_BIT(RCSTA, SPEN);

    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN6, GPIO_INPUT);  /* RC6/TX */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN7, GPIO_INPUT);  /* RC7/RX */

    SET_BIT(RCSTA, CREN);
    SET_BIT(PIE1, RCIE);
    SET_BIT(INTCON, PEIE);
    SET_BIT(INTCON, GIE);
}

void UART_TX_Init(void)
{
    SET_BIT(TXSTA, BRGH);
    SPBRG = (FOSC / (16UL * UART_BAUDRATE)) - 1;   /* was hardcoded 25 */
    CLR_BIT(TXSTA, SYNC);
    SET_BIT(RCSTA, SPEN);

    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN6, GPIO_INPUT);  /* RC6/TX */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN7, GPIO_INPUT);  /* RC7/RX */

    SET_BIT(TXSTA, TXEN);
}

void UART_Write(u8 Data)
{
    while(!GET_BIT(TXSTA, TRMT));
    TXREG = Data;
}

u8 UART_Read(void)
{
    while(!GET_BIT(PIR1, RCIF));
    return RCREG;
}

u8 UART_TX_Empty(void)
{
    return GET_BIT(TXSTA, TRMT);
}

void UART_SetCallback(void (*Callback)(u8))
{
    if(Callback != 0)
        UART_Callback = Callback;
}

void UART_ISR(void)
{
    u8 data = RCREG;   /* reading RCREG clears RCIF automatically */
    if(UART_Callback != 0)
        UART_Callback(data);
}