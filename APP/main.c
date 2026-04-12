#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/PWM/PWM_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/I2C/I2C_interface.h"
#include "../MCAL/USART/USART_Interface.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"

// Test Functions
void GPIO_Test(void);
void PWM_Test(void);
void ADC_Test(void);
void SPI_Test(void);
void I2C_Test(void);
void UART_Test(void);
void TIMER0_Test(void);
void EXT_INT_Test(void);

static void Run_All_Tests(void)
{
    u32 i;

    GPIO_Test();
    for (i = 0; i < 100000; i++);

    PWM_Test();
    for (i = 0; i < 100000; i++);

    ADC_Test();
    for (i = 0; i < 100000; i++);

    SPI_Test();
    for (i = 0; i < 100000; i++);

    I2C_Test();
    for (i = 0; i < 100000; i++);

    UART_Test();
    for (i = 0; i < 100000; i++);

    TIMER0_Test();
    for (i = 0; i < 100000; i++);

    EXT_INT_Test();
    for (i = 0; i < 100000; i++);
}

int main(void)
{
    GPIO_Init();
    Run_All_Tests();

    while (1);

    return 0;
}
