#include "timer0_test.h"
#include "pwm_test.h"
#include "adc_uart_test.h"
#include "spi_test.h"
#include "i2c_test.h"
#include "gpio_test.h"

void main(void)
{
     GPIO_TEST_Run();      // LED sequence with switches
    // TIMER0_TEST_Run();    // 1-second LED toggle using Timer0 interrupt
    // PWM_TEST_Run();       // motor speed control with button (INT0)
    // ADC_UART_TEST_Run();  // LM35 temperature reading via UART
     //SPI_TEST_Run();       // loopback test
     //I2C_TEST_Run();       // EEPROM write/read

    while (1);
}