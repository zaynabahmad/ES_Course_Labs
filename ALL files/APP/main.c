#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"

/* Test function prototypes */
void GPIO_Test(void);
void TIMER0_Test(void);
void EXT_INT_Test(void);
void PWM_Test(void);
void UART_Test(void);
void ADC_Test(void);
void SPI_Test(void);
void I2C_Test(void);

void main(void)
{
    /* Initialize GPIO (used by most drivers) */
    GPIO_Init();

    /* ===== SELECT ONE TEST ONLY ===== */

    //GPIO_Test();
    //TIMER0_Test();
    // EXT_INT_Test();
    
    //PWM_Test();
    
   // UART_Test();
    //ADC_Test();
    //SPI_Test();
    I2C_Test();


    while(1)
    {
        /* safety loop */
    }
}