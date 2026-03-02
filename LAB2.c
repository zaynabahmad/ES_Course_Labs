#include "Sources/HAL/LED/LED_interface.h"
#include "../HAL/Switch/Switch.h"
#include "../MCAL/Exit.INT/EXT_INT_Interface.h"

/* --- Hardware Mapping based on your Proteus Schematic --- */
// LEDs
#define LED_PORT         PORTD
#define LED_PIN_1        3  // RC0: Blue LED
#define LED_PORT         PORTC

#define LED_PIN_2        1   // RC1: Green LED
#define INT_LED_PORT     PORTC
#define INT_LED_PIN      0 // RD1: Purple LED

// Switches
#define SW1_PORT         PORTD
#define SW1_PIN          1  // RB0/INT: Connected to Switch 1
#define SW2_PORT         PORTB
#define SW2_PIN          2  // RB1: Connected to Switch 2

// Logic States
#define GPIO_HIGH        1
#define GPIO_LOW         0

/* --- Interrupt Callback --- */
void App_OnInterrupt(void)
{
    // Toggles the Purple LED on RD1 whenever RB0 is pressed
    LED_Toggle(INT_LED_PORT, INT_LED_PIN);
}

void main()
{
    /* --- 1. Initialization --- */
    LED_Init(LED_PORT, LED_PIN_1);
    LED_Init(LED_PORT, LED_PIN_2);
    LED_Init(INT_LED_PORT, INT_LED_PIN);

    SWITCH_Init(SW1_PORT, SW1_PIN);
    SWITCH_Init(SW2_PORT, SW2_PIN);

    /* --- 2. External Interrupt Setup --- */
    EXT_INT0_Init();
    EXT_INT0_SetEdge(RISING_EDGE);   // Trigger when button sends 5V
    EXT_INT0_SetCallback(App_OnInterrupt);
    EXT_INT0_Enable();

    /* --- 3. Global Interrupt Enable (Required for PIC) --- */
    INTCON.GIE = 1;  // Enable Global Interrupts
    INTCON.PEIE = 1; // Enable Peripheral Interrupts

    while (1)
    {
        // Check Switch 1 (Fast Sequence)
        if (SWITCH_Read(SW1_PORT, SW1_PIN) == GPIO_HIGH)
        {
            LED_On(LED_PORT, LED_PIN_1);
            LED_On(LED_PORT, LED_PIN_2);
            Delay_ms(200);  // 0.2s ON

            LED_Off(LED_PORT, LED_PIN_1);
            LED_Off(LED_PORT, LED_PIN_2);
            Delay_ms(200);  // 0.2s OFF
        }
        // Check Switch 2 (Slow Sequence)
        else if (SWITCH_Read(SW2_PORT, SW2_PIN) == GPIO_HIGH)
        {
            LED_On(LED_PORT, LED_PIN_1);
            LED_On(LED_PORT, LED_PIN_2);
            Delay_ms(500);  // 0.5s ON

            LED_Off(LED_PORT, LED_PIN_1);
            LED_Off(LED_PORT, LED_PIN_2);
            Delay_ms(500);  // 0.5s OFF
        }
        // No switch pressed
        else
        {
            LED_Off(LED_PORT, LED_PIN_1);
            LED_Off(LED_PORT, LED_PIN_2);
        }
    }
}