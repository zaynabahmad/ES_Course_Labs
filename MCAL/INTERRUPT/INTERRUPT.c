#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"


#include "../EXTI/EXTI_interface.h"
#include "../TIMER/TIMER_interface.h"
#include "../USART/USART_interface.h"

extern void (*EXTI_Callback)(void);
extern void (*TIMER_Callback)(void);
extern void (*UART_Callback)(void);


void interrupt()
{
    if(GET_BIT(PIR1 , RCIF))
    {
        UART_ISR();
    }


    if(GET_BIT(INTCON, 2))
    {

        CLR_BIT(INTCON, 2);




        if(TIMER_Callback != 0)
        {
            TIMER_Callback();
        }
    }


    if(GET_BIT(INTCON, 1))
    {

        CLR_BIT(INTCON, 1);

        if(EXTI_Callback != 0)
        {
            EXTI_Callback();
        }
    }
}