#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "gpio_test.h"

// Define the hardware pins 
#define SW1_PORT    GPIO_PORTB
#define SW1_PIN     GPIO_PIN0
#define SW2_PORT    GPIO_PORTB
#define SW2_PIN     GPIO_PIN1

#define LED1_PORT   GPIO_PORTC
#define LED1_PIN    GPIO_PIN0
#define LED2_PORT   GPIO_PORTC
#define LED2_PIN    GPIO_PIN1

//A custom delay function.
static void GPIO_Delay(unsigned int multiplier)
{
    unsigned int i, j;
    for(i = 0; i < multiplier; i++)
    {
        // Arbitrary loop to consume clock cycles
        for(j = 0; j < 500; j++);
    }
}

void APP_TestGPIO(void)
{
    // 1. Initialize GPIO
    GPIO_Init();

    // 2. Set Directions
    // Buttons are Inputs
    GPIO_SetPinDirection(SW1_PORT, SW1_PIN, GPIO_INPUT);
    GPIO_SetPinDirection(SW2_PORT, SW2_PIN, GPIO_INPUT);

    // LEDs are Outputs
    GPIO_SetPinDirection(LED1_PORT, LED1_PIN, GPIO_OUTPUT);
    GPIO_SetPinDirection(LED2_PORT, LED2_PIN, GPIO_OUTPUT);

    // 3. The Polling Loop (Checks switches continuously)
    while(1)
    {
        // Read the current state of both switches
        u8 sw1_state = GPIO_GetPinValue(SW1_PORT, SW1_PIN);
        u8 sw2_state = GPIO_GetPinValue(SW2_PORT, SW2_PIN);

        // If Switch 1 is pressed -> Short sequence (fast blink)
        if (sw1_state == GPIO_HIGH)
        {
            // Turn LEDs ON
            GPIO_SetPinValue(LED1_PORT, LED1_PIN, GPIO_HIGH);
            GPIO_SetPinValue(LED2_PORT, LED2_PIN, GPIO_HIGH);
            GPIO_Delay(100); // Short delay (~0.2s)

            // Turn LEDs OFF
            GPIO_SetPinValue(LED1_PORT, LED1_PIN, GPIO_LOW);
            GPIO_SetPinValue(LED2_PORT, LED2_PIN, GPIO_LOW);
            GPIO_Delay(100); // Short delay
        }
        // If Switch 2 is pressed -> Long sequence (slow blink)
        else if (sw2_state == GPIO_HIGH)
        {
            // Turn LEDs ON
            GPIO_SetPinValue(LED1_PORT, LED1_PIN, GPIO_HIGH);
            GPIO_SetPinValue(LED2_PORT, LED2_PIN, GPIO_HIGH);
            GPIO_Delay(300); // Long delay (~0.5s)

            // Turn LEDs OFF
            GPIO_SetPinValue(LED1_PORT, LED1_PIN, GPIO_LOW);
            GPIO_SetPinValue(LED2_PORT, LED2_PIN, GPIO_LOW);
            GPIO_Delay(300); // Long delay
        }
        //  If no switch is pressed -> turn off the LEDs
        else
        {
            GPIO_SetPinValue(LED1_PORT, LED1_PIN, GPIO_LOW);
            GPIO_SetPinValue(LED2_PORT, LED2_PIN, GPIO_LOW);
        }
    }
}