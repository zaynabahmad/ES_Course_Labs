#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "../MCAL/TIMER_0/TIMER_0_Interface.h"
#include "../MCAL/USART/USART_Interface.h"
#include "../MCAL/PWM/PWM_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/SPI/SPI_Interface.h"
#include "../MCAL/I2C/I2C_Interface.h"
#include "../HAL/LED/LED_interface.h"

/* ================= External Test Functions ================= */

void GPIO_Test(void);
void EXT_INT_Test(void);
void TIMER_Test(void);
void UART_Test(void);
void PWM_Test(void);
void ADC_Test(void);
void SPI_Test(void);
void I2C_Test(void);

/* ================= Main Entry Point ================= */

int main(void)
{
    /* Initialize GPIO first (required by most drivers) */
    GPIO_Init();

    /* Run all driver tests */
    GPIO_Test();
    EXT_INT_Test();
    TIMER_Test();
    UART_Test();
    PWM_Test();
    SPI_Test();
    I2C_Test();

    /* ADC_Test runs its own loop - call last */
    ADC_Test();

    /* Should never reach here */
    while(1)
    {
    }

    return 0;
}
