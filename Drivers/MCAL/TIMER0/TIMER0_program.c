#include "../../SERVICES/BIT_MATH.h"
#include "../../MCAL/TIMER0/TIMER0_private.h"
#include "../../MCAL/TIMER0/TIMER0_interface.h"
#include "../../MCAL/TIMER0/TIMER0_config.h"


volatile uint16 delay_counter = 0;

void TIMER0_voidInit(void) {
    TMR0 = TIMER0_PRELOAD_VALUE;
    CLEAR_BIT(OPTION_REG, 5);  // PSA = 0 (prescaler assigned)
    OPTION_REG &= 0xF8;        // PS = 1:256
    SET_BIT(INTCON, 5);        // TMR0IE = 1
    SET_BIT(INTCON, 7);        // GIE = 1
}

void TIMER0_voidSetDelay(uint16 Copy_ms) {
    delay_counter = Copy_ms;
    while(delay_counter) {
        TMR0 = TIMER0_PRELOAD_VALUE;
    }
}

void __interrupt() ISR(void) {
    if(GET_BIT(INTCON, 2)) {
        CLEAR_BIT(INTCON, 2);
        TMR0 = TIMER0_PRELOAD_VALUE;
        if(delay_counter > 0) delay_counter--;
    }
}