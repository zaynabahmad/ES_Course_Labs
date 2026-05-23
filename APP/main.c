#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\GPIO\GPIO_interface.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\TIMER0\TIMER0_interface.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\ADC\ADC_interface.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\UART\UART_interface.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\I2C\I2C_interface.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\PWM\PWM_interface.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\EXTI\EXTI_interface.h"

void GPIO_Test(void);
void TIMER_Test(void);
void ADC_Test(void);
void UART_Test(void);
void I2C_Test(void);
void PWM_Test(void);
void EXTI_Test(void);

void main(void)
{
    GPIO_Test();
    TIMER_Test();
    ADC_Test();
    UART_Test();
    I2C_Test();
    PWM_Test();
    EXTI_Test();
}