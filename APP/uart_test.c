#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/UART/UART_interface.h"

void UART_Test(void) {
    UART_voidInit();
    UART_voidTransmit('A');
    (void)UART_u8Receive(); 
}