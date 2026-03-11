#include "../MCAL/Timer0/timer0.h"
#include "../HAL/LED/LED.h"

Led_t led1 = {1, 1}; // RB1
Led_t led2 = {1, 2}; // RB2

volatile unsigned int tick_count = 0;

void App_Timer_Manager(void) {
    tick_count++;

    // Toggle LED2 every 1 second (100 * 10ms)
    if (tick_count % 100 == 0) {
        LED_Toggle(&led2);
    }

    // Toggle LED1 every 2 seconds (200 * 10ms)
    if (tick_count >= 200) {
        LED_Toggle(&led1);
        tick_count = 0; // Reset
    }
}

void main() {
    LED_Init(&led1);
    LED_Init(&led2);

    TIMER0_Init();
    TIMER0_SetCallback(App_Timer_Manager);
    TIMER0_Start();

    while(1) {
        // Main loop is non-blocking
    }
}