#include "../SERVICES/STD_TYPES.h"

extern void TIMER0_Test(void);
extern void PWM_Test(void);
extern void ADC_Test(void);
extern void UART_Test(void);
extern void SPI_Test(void);
extern void I2C_Test(void);

void main(void) {

    /* Initialize and Test Drivers */
    TIMER0_Test();
    PWM_Test();
    ADC_Test();
    UART_Test();
    SPI_Test();
    I2C_Test();

    while (1) {

    }
}