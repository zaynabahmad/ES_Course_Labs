#include "../APP/usart_test.h"

int main(void)
{
    // Call the required test function for USART
    APP_TestUSART();

    while(1)
    {
        // Handled entirely by the hardware UART interrupts
    }

    return 0;
}