#include "ext_int0.h"
#include "ext_int0_private.h"
#include "../../SERVICES/BIT_MATH.h"

/* Global static pointer to hold the address of the application's callback function.
 * It is 'static' so it cannot be accessed directly from outside this file.
 * We initialize it to 0 (NULL) for safety.
 */
static void (*EXT_INT0_Callback)(void) = 0;

void EXT_INT0_Init(void)
{
    /* Configure RB0/INT pin as an input (Bit 0 of TRISB) */
    SET_BIT(TRISB_REG, 0);

    /* Clear the interrupt flag before enabling to avoid false triggers */
    CLR_BIT(INTCON, INTCON_INTF);
}

void EXT_INT0_Enable(void)
{
    SET_BIT(INTCON, INTCON_INTE); /* Enable external interrupt 0 */
    SET_BIT(INTCON, INTCON_GIE);  /* Enable Global Interrupts */
}

void EXT_INT0_Disable(void)
{
    CLR_BIT(INTCON, INTCON_INTE); /* Disable external interrupt 0 */
}

void EXT_INT0_SetEdge(uint8 edge_type)
{
    if (edge_type == EXT_INT0_RISING_EDGE)
    {
        SET_BIT(OPTION_REG, OPTION_REG_INTEDG); /* Interrupt on rising edge */
    }
    else if (edge_type == EXT_INT0_FALLING_EDGE)
    {
        CLR_BIT(OPTION_REG, OPTION_REG_INTEDG); /* Interrupt on falling edge */
    }
}

void EXT_INT0_SetCallback(void (*ptr)(void))
{
    /* Store the passed function address into our global pointer */
    if (ptr != 0)
    {
        EXT_INT0_Callback = ptr;
    }
}

/* * Interrupt Service Routine (ISR)
 * Notice we still use the 'interrupt' keyword if we are targeting mikroC later,
 * but we use our custom bit math to check the flags!
 */
void EXT_INT0_ISR(void)
{
    /* Check if External Interrupt 0 flag is triggered */
    if (GET_BIT(INTCON, INTCON_INTF) == 1)
    {
 
        /* 1. Clear the flag immediately so it doesn't trigger infinitely */
        CLR_BIT(INTCON, INTCON_INTF);

        /* 2. Execute the callback function (No App logic here!) */
        if (EXT_INT0_Callback != 0)
        {
            EXT_INT0_Callback();
        }
    }
}