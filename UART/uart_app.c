// Purpose: Tests UART by sending messages to PC
// Connect TX pin to USB-serial RX, open Serial Monitor at 9600 baud

#include "uart.h"

void UART_Test(void) {
    uint16 counter = 0;
    char buffer[20];

    UART_Init(9600);

    // Send welcome message
    UART_WriteString("UART Test Started!\r\n");
    UART_WriteString("Sending numbers every second...\r\n");

    while(1) {
        // Convert number to text and send
        sprintf(buffer, "Count: %u\r\n", counter++);
        UART_WriteString(buffer);

        // Check if PC sent anything
        if(UART_DataReady()) {
            uint8 received = UART_ReadChar();
            UART_WriteChar(received);  // Echo back
            UART_WriteString("\r\n");
        }

        __delay_ms(1000);
    }
}