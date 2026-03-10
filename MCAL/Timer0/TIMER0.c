#include "TIMER0_interface.h"
#include "TIMER0_config.h"
#include "TIMER0_private.h"

void TIMER0_voidInit(void) {

    // 1. Select Clock Source
    #if TIMER0_CLK_SOURCE == TIMER0_INTERNAL_CLK
        OPTION_REG &= ~(1 << 5);  
    #else
        OPTION_REG |= (1 << 5);   
    #endif

    // 2. Assign Prescaler to Timer0
    OPTION_REG &= ~(1 << 3);      

    // 3. Set Prescaler Value
    OPTION_REG &= 0xF8;           
    OPTION_REG |= TIMER0_PRESCALER;

    // 4. Set Preload Value
    TMR0 = TIMER0_PRELOAD_VALUE;

    // 5. Enable Timer0 Interrupt
    INTCON |= (1 << 5);   // TMR0IE

    // 6. Enable Global Interrupt
    INTCON |= (1 << 7);   // GIE
}