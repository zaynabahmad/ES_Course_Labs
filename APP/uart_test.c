#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/UART/UART_interface.h"

void UART_Test(void) {
    u8 Local_u8ReceivedByte = 0;

    UART_voidInit();

    /* Transmit a character */
    UART_voidTransmit('A');

    /* Receive a character */
    Local_u8ReceivedByte = UART_u8Receive();
}