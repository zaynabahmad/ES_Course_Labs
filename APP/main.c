#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/PWM/PWM_interface.h"
#include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/I2C/I2C_interface.h"
#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"

// Forward declarations of APP test functions
void ADC_LM35_Test(void);
void PWM_Motor_Test(void);
void UART_Test(void);
void SPI_Test(void);
void I2C_Test(void);
void Timer0_Test(void);

void main(void)
{
    // -------------------------------------------------------------------
    // Select the task you want to test
    // -------------------------------------------------------------------

    // 1. ADC task
   // ADC_LM35_Test();

    // 2. Timer0 LEDs task
    //Timer0_LED_Test();

    // 3. PWM Motor task
    //PWM_Motor_Test();


    // 5. UART test
    UART_Test();

    // 6. SPI test
    //SPI_Test();

    // 7. I2C test
    //I2C_Test();



}