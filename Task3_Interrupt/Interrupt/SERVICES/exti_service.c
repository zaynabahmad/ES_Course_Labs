#include "STD_TYPES.h"                 // Standard types like u8
#include "../MCAL/exti0_interface.h"   // Correct path to EXTI0 interface
#include "../HAL/LED/LED_interface.h"  // LED interface

// Global flag for safe LED toggle
volatile u8 led_toggle_flag = 0;

// Callback function for INT0
static void ToggleLED(void) {
    led_toggle_flag = 1;   // Set flag only
}

// Initialize LED + INT0
void EXTI0_Service_Init(void) {
    LED_Init(0, 0);           // Initialize LED (Port A, Pin 0)
    EXTI0_Init();             // Initialize INT0
    EXTI0_SetCallback(ToggleLED); // Register callback
}

// Call this in main loop to toggle LED safely
void EXTI0_Service_Loop(void) {
    if (led_toggle_flag) {    // Check if interrupt occurred
        led_toggle_flag = 0;  // Clear flag
        LED_Toggle(0, 0);     // Toggle LED safely in main context
    }
}