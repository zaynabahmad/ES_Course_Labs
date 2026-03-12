#include "Timer_interface.h"
#include "../../MCAL/Interrupt Manager/Interrupt_manager.h"
#include "../../MCAL/TMR_INT/TMR_INT_interface.h"

// Explicitly defining prescaler values to avoid "Undeclared Identifier"
#define PSC_128 6
#define PSC_256 7

volatile u16 timer0_prescaler = 0;
volatile u16 target_overflows = 0;

void Timer0_Init(u16 prescaler) {
    timer0_prescaler = prescaler;
    if(prescaler == 128) TMR_INT_SetPrescaler(PSC_128);
    else TMR_INT_SetPrescaler(PSC_256);
}

void Timer0_SetDelay(u32 delay_ms, void (*callback)(void)) {
    u32 total_ticks;
    if (timer0_prescaler > 0) {
        // Calculation for 8MHz: (ms * 2000) / Prescaler
        total_ticks = (delay_ms * 2000) / timer0_prescaler;
        target_overflows = total_ticks / 256;
    }
    TMR_INT_SetCallback(callback);
    TMR_INT_Enable();
}