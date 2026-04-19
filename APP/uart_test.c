#include "../MCAL/UART/UART_interface.h"

void UART_Test_voidInit(void) {
    UART_voidInit(9600);
}

void UART_Test_voidRun(void) {
    UART_voidSendString("UART Driver Tested Successfully!\r\n");
}