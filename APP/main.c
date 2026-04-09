#include "STD_TYPES.h"
#include "GPIO_interface.h"

/* Match these names exactly with the ones in your .c test files */
extern void usart_test_run(void);
extern void adc_test_run(void);
extern void pwm_test_run(void);
extern void spi_test_run(void);
extern void i2c_test_run(void);
extern void timer0_test_run(void);
extern void ext_int_test_run(void);

void main(void) {
    /* 1. Global GPIO Initialization */
    GPIO_Init();

    /* 2. Communication Peripheral Tests */
    usart_test_run(); // Changed from test_USART
    spi_test_run();   // Changed from test_SPI
    i2c_test_run();   // Changed from test_I2C

    /* 3. Analog & Actuator Tests */
    adc_test_run();   // Changed from test_ADC
    pwm_test_run();   // Changed from test_PWM

    /* 4. Interrupt-based Tests */
    timer0_test_run();
    ext_int_test_run();

    while(1) {
        /* Foreground tasks */
    }
}