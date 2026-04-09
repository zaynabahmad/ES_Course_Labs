#include "bit_math.h"
#include "ext_int.h"
#include "timer0.h"

void GPIO_Test(void);
void EXT_INT_Test(void);
void TIMER0_Test(void);
void PWM_Test(void);
void ADC_Test(void);
void UART_Test(void);
void SPI_Test(void);
void I2C_Test(void);

void main(void)
{
    //GPIO_Test();
    // EXT_INT_Test();
    // TIMER0_Test();
    //PWM_Test();
    // ADC_Test();
     //UART_Test();
     //SPI_Test();
     I2C_Test();
}



void interrupt(void)
{
    if(EXT_INT_GetFlag())         /* ? no registers */
    {
        extern unsigned char flagPressed;
        flagPressed = 1;
        EXT_INT_ClearFlag();      /* ? no registers */
    }

    if(TIMER0_GetFlag())          /* ? no registers */
    {
        extern unsigned char overflowCount;
        extern unsigned char timerFlag;
        overflowCount++;
        if(overflowCount < 30)
        {
            TIMER0_Reload(0);     /* ? no registers */
        }
        else
        {
            TIMER0_Reload(124);   /* ? no registers */
            overflowCount = 0;
            timerFlag = 1;
        }
        TIMER0_ClearFlag();       /* ? no registers */
    }
}