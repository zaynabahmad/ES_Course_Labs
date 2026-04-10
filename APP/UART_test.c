#include "../MCAL/UART/UART_interface.h"

void UART_test(void) {
    u8 Local_u8Data;

    UART_voidInit();
    UART_voidSendString("UART System Ready!\r\n");

    while(1) {
        /* Echo back the received character */
        Local_u8Data = UART_u8ReceiveData();
        UART_voidSendData(Local_u8Data);
    }
}