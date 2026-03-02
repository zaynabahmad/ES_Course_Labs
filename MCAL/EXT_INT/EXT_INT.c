#include "EXT_INT_interface.h"
#include "EXT_INT_private.h"
#include "EXT_INT_config.h"

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

/* Global pointer to hold the address of the Application function */
static void (*EXT_INT0_CallBackPtr)(void) = 0;

/**
 * @brief Initializes the INT0 hardware (Pin RB0 as input and clears flag)
 */
void EXT_INT0_Init(void)
{
    /* 1. Configure RB0 (INT0 pin) as Input */
    SET_BIT(TRISB, 0);

    /* 2. Clear the Interrupt Flag initially to prevent false triggers */
    CLR_BIT(INTCON, 1); // INTF is bit 1
}

/**
 * @brief Enables the External Interrupt and Global Interrupts
 */
void EXT_INT0_Enable(void)
{
    SET_BIT(INTCON, 7); // GIE: Global Interrupt Enable
    SET_BIT(INTCON, 4); // INTE: External Interrupt Enable
}

/**
 * @brief Disables the External Interrupt
 */
void EXT_INT0_Disable(void)
{
    CLR_BIT(INTCON, 4); // INTE: External Interrupt Enable
}

/**
 * @brief Selects trigger edge (Rising or Falling)
 * @param edge_type: 1 for Rising Edge, 0 for Falling Edge
 */
void EXT_INT0_SetEdge(u8 edge_type)
{
    if(edge_type == EXT_INT_RISING_EDGE)
    {
        SET_BIT(OPTION_REG, 6); // INTEDG: 1 = Rising Edge
    }
    else
    {
        CLR_BIT(OPTION_REG, 6); // INTEDG: 0 = Falling Edge
    }
}

/**
 * @brief Registers the function to be called when the interrupt happens
 */
void EXT_INT0_SetCallback(void (*ptr)(void))
{
    if(ptr != 0)
    {
        EXT_INT0_CallBackPtr = ptr;
    }
}

/**
 * @brief The actual Interrupt Service Routine (ISR)
 * This must be inside the MCAL layer.
 */
void interrupt(void)
{
    /* Check if External Interrupt Flag (INTF) is set */
    if(GET_BIT(INTCON, 1) == 1)
    {
        /* Execute the Application function via the Callback pointer */
        if(EXT_INT0_CallBackPtr != 0)
        {
            EXT_INT0_CallBackPtr();
        }

        /* Must clear the flag so the interrupt can happen again */
        CLR_BIT(INTCON, 1);
    }
}