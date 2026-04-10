#include "../SERVICES/Std_Types.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/EXT_INT/EXT_INT0.h"

volatile u16 tick_count = 0;

// Software states to prevent the "Physical Voltage Read" bug
u8 led1_state = GPIO_LOW;
u8 led2_state = GPIO_LOW;

void App_Timer0_Tasks(void) {
    tick_count++;

    if (tick_count % 30 == 0) {
        led2_state = !led2_state; // Flip the software memory
        GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN2, led2_state); // Apply to hardware
    }

    if (tick_count % 60 == 0) {
        led1_state = !led1_state; // Flip the software memory
        GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN1, led1_state); // Apply to hardware

        tick_count = 0; // Reset counter to prevent overflow
    }
}

void interrupt(void) {
    TIMER0_ISR_Handler();
}

void main() {
    // 1. Initialize the Pins (Using PORTB Pins 1 and 2)
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN1, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN2, GPIO_OUTPUT);

    // 2. Initialize Timer0
    TIMER0_Init();

    // SAFETY OVERRIDE: mikroC occasionally fails to switch memory banks for custom pointers.

    // 3. Start Interrupts
    TIMER0_SetCallback(App_Timer0_Tasks);
    TIMER0_EnableInterrupt();

    // 4. Main Loop
    while(1) {
        // CPU is free! Timer0 is running the show.
    }
}