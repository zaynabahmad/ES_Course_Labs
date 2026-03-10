#include "EXT_INT0_interface.h"
#include "EXT_INT0_private.h"
#include "EXT_INT0_config.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/TIMER0/TIMER0_private.h"
#include "../../SERVICES/BIT_MATH.h"

/* Global Callback Pointer */
void (*EXT_INT0_Callback)(void) = NULL_PTR;


void EXT_INT0_Init(void)
{
    /* Configure TRISB0 as input for INT0 */
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);

    if(EXT_INT0_EDGE_TYPE == RISING_EDGE)
        SET_BIT(OPTION_REG, INTEDG);
    else
        CLR_BIT(OPTION_REG, INTEDG);

    /* Enable INT0 interrupt */
    SET_BIT(INTCON, INTE);

    /* Enable Global Interrupts */
    SET_BIT(INTCON, GIE);

    /* Clear INT0 interrupt flag */
    CLR_BIT(INTCON, INTF);
}


void EXT_INT0_Enable(void)
{
    SET_BIT(INTCON, INTE);
}


void EXT_INT0_Disable(void)
{
    CLR_BIT(INTCON, INTE);
}


void EXT_INT0_SetEdge(u8 edge_type)
{
    if(edge_type == RISING_EDGE)
        SET_BIT(OPTION_REG, INTEDG);
    else
        CLR_BIT(OPTION_REG, INTEDG);
}



void EXT_INT0_SetCallback(void (*ptr)(void))
{
    EXT_INT0_Callback = ptr;
}


void interrupt (void)
{
    /* EXT_INT0 handler */
    if(GET_BIT(INTCON, INTF))
    {
        if(EXT_INT0_Callback != NULL_PTR)
            EXT_INT0_Callback();
        CLR_BIT(INTCON, INTF);
    }

    /* Timer0 overflow handler */
    if(GET_BIT(INTCON, T0IF))
    {

        CLR_BIT(INTCON, T0IF);
        if(TIMER0_Callback != NULL_PTR)
            TIMER0_Callback();
    }
}