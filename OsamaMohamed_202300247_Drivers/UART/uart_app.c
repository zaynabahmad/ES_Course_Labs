
#include "../pic_config.h"
#include "uart.h"


void main() {
    ADCON1 = 0x06;

    UART1_Init(9600);          // 9600 baud
    Delay_ms(100);             // Wait for UART to stabilize

    UART1_Write_Text("Hello from PIC16F877A!\n");

    while (1) {
        if (UART1_Data_Ready()) {
            uint8 b = UART1_Read();
            UART1_Write(b);   
        }
    }
}