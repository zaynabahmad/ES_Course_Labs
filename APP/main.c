/*
 * PIC16F877A MCAL Driver Test Application
 * Toolchain: mikroC
 * Author: Ahmed Shaban 202200217
 *
 * Uncomment the test function you want to run in main().
 * Only one test should be active at a time.
 */

#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../MCAL/GPIO/GPIO_Interface.h"

/* Test function prototypes */
extern void GPIO_Test(void);
extern void EXT_INT_Test(void);
extern void TIMER0_Test(void);
extern void PWM_Test(void);
extern void ADC_Test(void);
extern void UART_Test(void);
extern void SPI_Test(void);
extern void I2C_Test(void);

void main(void)
{
    /* Initialize GPIO (all ports) */
    GPIO_Init();

    /* === Uncomment ONE test at a time === */

    GPIO_Test();
    // EXT_INT_Test();
    // TIMER0_Test();
    // PWM_Test();
    // ADC_Test();
    // UART_Test();
    // SPI_Test();
    // I2C_Test();
}
