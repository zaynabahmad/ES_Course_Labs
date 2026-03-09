#include "TMR_INT_interface.h"


#include "../../SERVICES/BIT_MATH.h"

void TMR_INT_Init(void)
{
    TMR0=0;
    CLR_BIT(INTCON, TMR0IF_BIT); // Clear Timer0 interrupt flag
    CLR_BIT(INTCON, TMR0IE_BIT); // Disable Timer0 interrupt
    SET_BIT(INTCON, GIE_BIT); // Enable global interrupts
}

void TMR_INT_Enable(void)
{
    /* Enable Timer0 interrupt */
    SET_BIT(INTCON, TMR0IE_BIT);
    
    /* Enable global interrupts */
    SET_BIT(INTCON, GIE_BIT);


    CLR_BIT(INTCON, TMR0IF_BIT); // Clear any pending interrupt flag
    OPTION_REG = 0b00000110; // Set prescaler to 1:128 and assign it to Timer0
}

void TMR_INT_Disable(void)
{
    /* Disable Timer0 interrupt */
    CLR_BIT(INTCON, TMR0IE_BIT);

    /* Clear Timer0 interrupt flag */
    CLR_BIT(INTCON, TMR0IF_BIT);

}

void TMR_INT_SetPreload(u8 preload_value)
{
    TMR0 = preload_value; // Set the preload value for Timer0
}

void TMR_INT_SetPrescaler(u8 prescaler_value)
{
    // Clear old prescaler bits
    OPTION_REG &= 0xF8;   // clear PS2:PS0 (bits 0-2)

    // Set new prescaler
    OPTION_REG |= (prescaler_value & 0x07);

    // Assign prescaler to Timer0 (PSA = 0)
    CLR_BIT(OPTION_REG, PSA_BIT);

    // Ensure Timer0 uses internal clock
    CLR_BIT(OPTION_REG, TOCS_BIT); 
    CLR_BIT(OPTION_REG, TOSE_BIT);
}




void set_tmr0(u8 value) {
    TMR0 = value; // Set the Timer0 register to the specified value
}