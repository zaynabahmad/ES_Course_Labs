#include "EXT_INT_interface.h"
#include "EXT_INT_private.h"
#include "EXT_INT_config.h"

/* MCAL Dependencies */
#include "../GPIO/GPIO_interface.h"
#include "../../SERVICES/BIT_MATH.h"

/* Global Pointer To Callback Function */
void (*EXT_INT_Callback)(void) = NULL;

void EXT_INT_Init(void)
{
    /* Configure the external interrupt pin as input (RB0) */
    GPIO_SetPinDirection(EXT_INT_PORT, EXT_INT_PIN, GPIO_INPUT);

    /* Configure the default edge type (Falling edge) */
    EXT_INT_SetEdge(falling_edge);

    /* Clear the interrupt flag and ensure it is disabled initially */
    CLR_BIT(INTCON, INTF_BIT);
    CLR_BIT(INTCON, INTE_BIT); 
}

void EXT_INT_Enable(void)
{
    /* Clear any pending flag before enabling to prevent false triggers */
    CLR_BIT(INTCON, INTF_BIT);

    /* Enable the external interrupt */
    SET_BIT(INTCON, INTE_BIT);

    /* Enable global interrupts */
    SET_BIT(INTCON, GIE_BIT);
}

void EXT_INT_Disable(void)
{
    /* Disable the external interrupt */
    CLR_BIT(INTCON, INTE_BIT);
    
    /* Clear the interrupt flag */
    CLR_BIT(INTCON, INTF_BIT);
}

void EXT_INT_SetEdge(u8 Edgetype)
{
    /* YOUR FIX: Datasheet says 1 is Rising Edge, 0 is Falling Edge */
    if (Edgetype == rising_edge)
    {
        SET_BIT(OPTION_REG, INTEDGE_BIT); 
    }
    else if (Edgetype == falling_edge)
    {
        CLR_BIT(OPTION_REG, INTEDGE_BIT); 
    }
}

void EXT_INT_SetCallback(void (*ptr)(void)) 
{
    /* YOUR IMPROVEMENT: Safety check */
    if (ptr != NULL) 
    {
        EXT_INT_Callback = ptr;
    }
}

/* This function is called by the central Interrupt_Manager.c */
void EXT_INT_ISR(void)
{
    /* 1. Clear the interrupt flag inside the ISR */
    CLR_BIT(INTCON, INTF_BIT);
    
    /* Use direct mikroC register access to clear the flag (To be sure) */
     INTF_bit = 0;

    /* 2. Execute the callback if it is registered */
    if (EXT_INT_Callback != NULL) 
    {
        EXT_INT_Callback();
    }
}