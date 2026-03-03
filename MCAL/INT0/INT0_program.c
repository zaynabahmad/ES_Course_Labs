#include "INT0_interface.h"
#include "../GPIO/GPIO_private.h"
#include "../GPIO/GPIO_interface.h"
static void (*INT0_CallBack)(void) = 0;

void INT0_Init(void)
{     
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);
    INTEDG_bit = 1;     // Rising edge trigger
    INTF_bit = 0;       // Clear interrupt flag
    INTE_bit = 1;       // Enable INT0 interrupt
    GIE_bit = 1;        // Enable global interrupt
}

void INT0_SetCallBack(void (*ptr)(void))
{
    INT0_CallBack = ptr;
}

void interrupt()
{
    if (INTCON.INTF == 1)
    {
       INTCON.INTF = 0;   // Clear flag
        
        if (INT0_CallBack != 0)
        {
            INT0_CallBack();
        }
    }
}