
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


/* Uncomment any function and test */

void main(void)
{
    
    GPIO_Init();

    /* === Uncomment ONE test at a time === */

    GPIO_Test();
    // EXT_INT_Test();
    // TIMER0_Test();
    // UART_Test();
	// PWM_Test();
    // ADC_Test();
	// I2C_Test();
    // SPI_Test();
}
