
#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/USART/UART_Interface.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"


#include "SERVICES/STD_TYPES.h"


extern void APP_GPIO_Test(void);
extern void APP_EXT_INT_Test(void);
extern void APP_Timer0_Test(void);
extern void APP_PWM_Test(void);
extern void APP_ADC_Test(void);
extern void APP_UART_Test(void);
extern void APP_SPI_Test(void);
extern void APP_I2C_Test(void);

void main(void) 
{
   
    /* --- Basic I/O & Timers --- */
    // APP_GPIO_Test();
    // APP_EXT_INT_Test();
    // APP_Timer0_Test();
    // APP_PWM_Test();

    /* --- Analog & Communications --- */
    APP_ADC_Test();    
    // APP_UART_Test();
    // APP_SPI_Test();
    // APP_I2C_Test();


while(1) 
{
    // main loop can be empty because interrupts handle everything
}

    return 0;
    }
