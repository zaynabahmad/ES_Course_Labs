#include "../MCAL/GPIO/GPIO_interface.h"

/* Test function declarations */
void GPIO_Test(void);
void EXT_INT_Test(void);
void TIMER0_Test(void);
void PWM_Test(void);
void ADC_Test(void);
void UART_Test(void);
void SPI_Test(void);
void I2C_Test(void);

int main(void)
{
    GPIO_Init();

    GPIO_Test();
    EXT_INT_Test();
    TIMER0_Test();
    PWM_Test();
    ADC_Test();
    UART_Test();
    SPI_Test();
    I2C_Test();

    while(1)
    {
        /* Application runs via interrupts and callbacks */
    }

    return 0;
}
