#include "Timer_Interface.h"
#include "../../MCAL/Interrupt Manager/Interrupt_manager.h"
#include "../../MCAL/TMR_INT/TMR_INT_interface.h"
#include "Timer_config.h"
volatile u16 timer0_prescaler = 0;

/* Set prescaler and enable Timer0 interrupt */
void Timer0_Init(u16 prescaler) {
    timer0_prescaler = prescaler;

    switch(prescaler) {
        case 2:   TMR_INT_SetPrescaler(PSC_2); break;
        case 4:   TMR_INT_SetPrescaler(PSC_4); break;
        case 8:   TMR_INT_SetPrescaler(PSC_8); break;
        case 16:  TMR_INT_SetPrescaler(PSC_16); break;
        case 32:  TMR_INT_SetPrescaler(PSC_32); break;
        case 64:  TMR_INT_SetPrescaler(PSC_64); break;
        case 128: TMR_INT_SetPrescaler(PSC_128); break;
        default: TMR_INT_SetPrescaler(PSC_256); break;
    }
}



void Timer0_SetDelay(u32 delay_ms, void (*callback)(void)) {
    u32 total_ticks;
    u8 remainder;
    // Fosc = 8MHz -> Finst = 2MHz (2 ticks per microsecond)
    // Formula: (ms * 2000) / prescaler
    total_ticks = (delay_ms * 2000) / timer0_prescaler;

    // How many full 256-tick cycles fit in total_ticks?
    target_overflows = total_ticks / 256;

    // The 'remainder' is what we preload once to offset the first overflow
    remainder = total_ticks % 256;

    if (remainder > 0) {
        TMR0 = 256 - remainder;
    } else {
        TMR0 = 0;
    }

    TMR_INT_SetCallback(callback);
    TMR_INT_Enable();
}

void Timer0_reset() {
    TMR0_Counter = 0;
}
