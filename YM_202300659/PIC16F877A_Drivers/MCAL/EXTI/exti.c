/*
 * exti.c
 * MCAL - External Interrupt Driver Implementation for PIC16F877A
 */

#include "exti.h"
#include "exti_private.h"
#include "../GPIO/gpio.h"

void EXTI_Init(EXTI_Edge_t edge)
{
    /* Configure RB0 as input for INT */
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);

    /* Set edge trigger */
    EXTI_SetEdge(edge);

    /* Clear INT flag before enabling */
    INTCON_REG &= ~(1 << INTCON_INTF);
}

void EXTI_Enable(EXTI_Source_t src)
{
    if(src == EXTI_INT0)
    {
        INTCON_REG |= (1 << INTCON_INTE);   /* Enable INT0 */
    }
    else if(src == EXTI_RB_CHG)
    {
        INTCON_REG |= (1 << INTCON_RBIE);   /* Enable RB change */
    }
    INTCON_REG |= (1 << INTCON_GIE);        /* Enable Global Interrupts */
}

void EXTI_Disable(EXTI_Source_t src)
{
    if(src == EXTI_INT0)
    {
        INTCON_REG &= ~(1 << INTCON_INTE);
    }
    else if(src == EXTI_RB_CHG)
    {
        INTCON_REG &= ~(1 << INTCON_RBIE);
    }
}

void EXTI_GlobalEnable(void)
{
    INTCON_REG |= (1 << INTCON_GIE);
}

void EXTI_GlobalDisable(void)
{
    INTCON_REG &= ~(1 << INTCON_GIE);
}

void EXTI_ClearFlag(EXTI_Source_t src)
{
    if(src == EXTI_INT0)
    {
        INTCON_REG &= ~(1 << INTCON_INTF);
    }
    else if(src == EXTI_RB_CHG)
    {
        INTCON_REG &= ~(1 << INTCON_RBIF);
    }
}

u8 EXTI_GetFlag(EXTI_Source_t src)
{
    if(src == EXTI_INT0)
    {
        return (INTCON_REG >> INTCON_INTF) & 0x01;
    }
    else
    {
        return (INTCON_REG >> INTCON_RBIF) & 0x01;
    }
}

void EXTI_SetEdge(EXTI_Edge_t edge)
{
    if(edge == EXTI_RISING_EDGE)
    {
        OPTION_REG_ADDR |= (1 << OPTION_INTEDG);
    }
    else
    {
        OPTION_REG_ADDR &= ~(1 << OPTION_INTEDG);
    }
}
