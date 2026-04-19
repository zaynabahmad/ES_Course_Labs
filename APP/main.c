#include "APP/gpio_test.h"
#include "APP/adc_test.h"
#include "APP/uart_test.h"
// ... include all other test headers

void main(void) {
    /* Initialize all tests */
    GPIO_Test_voidInit();
    ADC_Test_voidInit();
    UART_Test_voidInit();
    I2C_Test_voidInit();

    while(1) {
        /* Run tests periodically */
        GPIO_Test_voidRun();
        ADC_Test_voidRun();
        UART_Test_voidRun();

        // Delay for observation in Proteus
        Delay_ms(1000);
    }
}