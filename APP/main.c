#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TIMER_0/TIMER_0_Interface.h"
#include "../MCAL/USART/USART_Interface.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "../MCAL/PWM/PWM_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/I2C/I2C_interface.h"

/* Include all test implementations */
#include "GPIO_test.c"
#include "TIMER0_test.c"
#include "UART_test.c"
#include "EXT_INT_test.c"
#include "PWM_test.c"
#include "ADC_test.c"
#include "SPI_test.c"
#include "I2C_test.c"

/* Function declarations */
extern void GPIO_Test(void);
extern void Timer0_Test(void);
extern void UART_Test(void);
extern void ExternalInterrupt_Test(void);
extern void PWM_Test(void);
extern void ADC_Test(void);
extern void SPI_Test(void);
extern void I2C_Test(void);

int main(void)
{
    /* Initialize all peripherals and run tests */

    /* GPIO Test */
    GPIO_Init();
    GPIO_Test();

    /* Timer0 Test */
    // Timer0_Test();

    /* UART Test */
    // UART_Test();

    /* External Interrupt Test */
    // ExternalInterrupt_Test();

    /* PWM Test */
    // PWM_Test();

    /* ADC Test */
    // ADC_Test();

    /* SPI Test */
    // SPI_Test();

    /* I2C Test */
    // I2C_Test();

    return 0;
}