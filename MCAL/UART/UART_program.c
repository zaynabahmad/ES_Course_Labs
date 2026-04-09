#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_private.h"
#include "UART_interface.h"

void UART_voidInit(void)
{
    // Baud rate = 9600 for 8MHz
    SPBRG = 51;

    // TX enable
    SET_BIT(TXSTA,5);

    // Serial port enable
    SET_BIT(RCSTA,7);

    // RX enable
    SET_BIT(RCSTA,4);
}

void UART_voidSendChar(unsigned char data)
{
    while(!GET_BIT(PIR1,4)); // wait TXIF
    TXREG = data;
}

unsigned char UART_u8ReceiveChar(void)
{
    while(!GET_BIT(PIR1,5)); // wait RCIF
    return RCREG;
}