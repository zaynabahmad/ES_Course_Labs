/*
 * Application Layer
 * Lab Task 2: External Interrupt Driver (Layered Architecture)
 *
 * Hardware:
 *   LED     -> RC0 (Port C, Pin 0) with 330 ohm resistor to GND
 *   BUTTON  -> RB0 (Port B, Pin 0) with 10k pull-up to VDD (active LOW)
 *
 * Fix: mikroC PRO does not allow the same function to be called from
 * both the main loop and an ISR (reentrancy error).
 * Solution: ISR callback only sets a volatile flag.
 *           Main loop checks the flag and does the actual GPIO work.
 */

#include "../HAL/LED/LED_interface.h"
#include "../HAL/BUTTON/BUTTON_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

/* ---- Pin Definitions ---- */
#define LED_PORT        GPIO_PORTC
#define LED_PIN         GPIO_PIN0

/* ---- Shared flag between ISR and main loop ----
 * volatile: tells the compiler this can change at any time (ISR)
 * uint8:    simple atomic read/write on 8-bit PIC
 */
volatile uint8 g_button_pressed_flag = 0;

/* -------------------------------------------------------
 * Callback Function (called from ISR inside MCAL)
 * RULE: Do NOT call any GPIO or HAL functions here.
 *       Only set the flag - main loop will handle the rest.
 * ------------------------------------------------------- */
void Button_PressedCallback(void)
{
    g_button_pressed_flag = 1;   /* Signal main loop */
}

/* ---- Main Application ---- */
void main(void)
{
    /* 1. Initialize LED as output, starts OFF */
    LED_Init(LED_PORT, LED_PIN);

    /* 2. Initialize Button: RB0 as input, falling edge, enable INT0 + GIE */
    BUTTON_Init();

    /* 3. Register callback */
    BUTTON_SetCallback(Button_PressedCallback);

    /* Super Loop */
    while(1)
    {
        /* Check if button was pressed (flag set by ISR) */
        if(g_button_pressed_flag == 1)
        {
            g_button_pressed_flag = 0;   /* Clear flag first */
            LED_Toggle(LED_PORT, LED_PIN); /* Now safe to call GPIO here */
        }
    }
}