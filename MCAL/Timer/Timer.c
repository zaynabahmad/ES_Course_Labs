#include "TImer_interface.h"

#define TMR0_PRELOAD        193   // Preload for 8ms interrupt
#define INTERRUPTS_PER_SEC  125   // 125 * 8ms = 1 second

static TimerCallback_t Timer0_GP_Callback = 0;
static unsigned char Overflow_Counter = 0;

void Timer0_Init(void) {

    OPTION_REG = 0x87; // 1000 0111

    TMR0 = TMR0_PRELOAD;

    INTCON.TMR0IE = 1; // Enable Timer0 Interrupt
    INTCON.GIE = 1;    // Enable Global Interrupt
    INTCON.PEIE = 1;   // Enable Peripheral Interrupt
}
void Timer0_SetCallback(TimerCallback_t ptr) {
    if (ptr != 0) {
        Timer0_GP_Callback = ptr;
    }
}
void Interrupt() {
    if (INTCON.TMR0IF == 1) {
        TMR0 = TMR0_PRELOAD; // Reload for next 8ms

        Overflow_Counter++;

        if (Overflow_Counter >= INTERRUPTS_PER_SEC) {
            if (Timer0_GP_Callback != 0) {
                Timer0_GP_Callback(); // This fires every 8 milli second
            }
            Overflow_Counter = 0; // Reset counter
        }

        INTCON.TMR0IF = 0; // Clear Flag
    }
}