#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "../../SERVICES/BIT_MATH.h"

static void (*TIMER0_Callback)(void) = 0;

void TIMER0_Init(void) {
    // Set OPTION_REG for Internal Clock (Bit 5=0) and 1:256 Prescaler (Bits 2:0=111)
    OPTION_REG_CUSTOM = 0x87; 
    TMR0_REG = TIMER0_PRELOAD_VAL;
}

void TIMER0_SetPreload(u8 Preload) {
    TMR0_REG = Preload;
}

void TIMER0_EnableInterrupt(void) {
    SET_BIT(INTCON_REG, T0IE_BIT);
    SET_BIT(INTCON_REG, GIE_BIT);
}

void TIMER0_DisableInterrupt(void) {
    CLR_BIT(INTCON_REG, T0IE_BIT);
}

void TIMER0_SetCallback(void (*ptr)(void)) {
    TIMER0_Callback = ptr;
}

/* This is called by the global interrupt function in main.c */
void TIMER0_ISR_Handler(void) {
    // Check if Timer0 caused the interrupt
    if (GET_BIT(INTCON_REG, T0IF_BIT) == 1) {
        
        TMR0_REG = TIMER0_PRELOAD_VAL; // Reload the timer
        CLR_BIT(INTCON_REG, T0IF_BIT); // Clear the flag
        
        if (TIMER0_Callback != 0) {
            TIMER0_Callback(); // Execute the application logic
        }
    }
}