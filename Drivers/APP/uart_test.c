#include "../../App/app_interface.h"
#include "../../MCAL/UART/UART_interface.h"

void APP_UART_Test(void) {
    UART_voidInit(9600);
    
    while(1) {
        UART_voidTransmit('A');
        Delay_ms(500);
    }
}