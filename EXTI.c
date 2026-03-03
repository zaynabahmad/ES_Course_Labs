#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "SERVICES/STD_TYPES.h"

static void (*EXTI_CallBack)(void) = 0;

void EXTI_Init(void)
{
    TRISB.F0 = 1;        // RB0 input

#if EXTI_EDGE == 1
    OPTION_REG.INTEDG = 1;   // Rising edge
#else
    OPTION_REG.INTEDG = 0;   // Falling edge
#endif

    INTCON.INTE = 1;     // Enable external interrupt
    INTCON.GIE  = 1;     // Enable global interrupt
}

void EXTI_SetCallBack(void (*Copy_ptr)(void))
{
    if(Copy_ptr != 0)
    {
        EXTI_CallBack = Copy_ptr;
    }
}

/* Interrupt Service Routine */
void interrupt()
{
    if(INTCON.INTF == 1)
    {
        INTCON.INTF = 0;    // Clear flag

        if(EXTI_CallBack != 0)
        {
            EXTI_CallBack();
        }
    }
}