#include "../MCAL/EXT_INT0/ext_int0.h"
#include "../MCAL/TIMER0/timer0.h"
#include "../HAL/LED/led.h"

// Volatile counters for independent timing
volatile uint16 g_u16TimerTicks1 = 0;
volatile uint16 g_u16TimerTicks2 = 0;

// This runs every 1ms inside the Timer0 ISR
void Timer_Tick_Handler(void) {
    g_u16TimerTicks1++;
    g_u16TimerTicks2++;
}

void main() {
    // 1. Initializations
    LED_Init();
    TIMER0_Init();
    
    // 2. Set the callback to increment counters
    TIMER0_SetCallback(Timer_Tick_Handler);

    while(1) {
        // LED1 Task: Toggle every 2000ms (2 seconds)
        if (g_u16TimerTicks1 >= 2000) {
            LED1_Toggle();
            g_u16TimerTicks1 = 0; // Reset counter 1
        }

        // LED2 Task: Toggle every 1000ms (1 second)
        if (g_u16TimerTicks2 >= 1000) {
            LED2_Toggle();
            g_u16TimerTicks2 = 0; // Reset counter 2
        }
    }
}