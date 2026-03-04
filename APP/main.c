/*
 * APPLICATION LAYER
 * Task 2: External Interrupt - Toggle LED on button press
 */

#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/Switch_interface.h"
#include "../MCAL/EXT_INT/ext_int0.h"
// include GPIO for switch initialization
#include "../MCAL/GPIO/GPIO_interface.h"

/* Hardware definitions */
#define LED_PORT    2       /* PORTC */
#define LED_PIN     0       /* PIN0  */
#define SWITCH_PIN  0       /* RB0 - INT0 hardwired here */

void App_Toggle_LED(void)
{
    LED_Toggle(LED_PORT, LED_PIN);
}

void main(void)
{
    LED_Init(LED_PORT, LED_PIN);
    SWITCH_Init(GPIO_PORTB, SWITCH_PIN);

    EXT_INT0_Init();
    EXT_INT0_SetEdge(EXT_INT0_FALLING_EDGE);
    EXT_INT0_SetCallback(App_Toggle_LED);
    EXT_INT0_Enable();

    // while loop can be empty since we're using interrupts to toggle the LED
    while(1)
    {
    }
}

// Task 1 Code: LED blinks with polling method
// void delay(void)
// {
//     unsigned int i;
//     for(i = 0; i < 50000; i++);
// }
// void main()
// {
//     LED_Init(GPIO_PORTA, GPIO_PIN0);
//     LED_Init(GPIO_PORTA, GPIO_PIN1);
//     SWITCH_Init(GPIO_PORTB, GPIO_PIN0);
//     SWITCH_Init(GPIO_PORTB, GPIO_PIN1);
//     while(1)
//     {
//         // if switch 1 is pressed, leds blink fast (short sequance)
//         if(SWITCH_GetState(GPIO_PORTB, GPIO_PIN0) == SWITCH_PRESSED)
//         {
//             LED_On(GPIO_PORTA, GPIO_PIN0);
//             LED_On(GPIO_PORTA, GPIO_PIN1);
//             delay();
//             LED_Off(GPIO_PORTA, GPIO_PIN0);
//             LED_Off(GPIO_PORTA, GPIO_PIN1);
//             delay();
//         }
//         // if switch 2 is pressed, leds blink slow (long sequance)
//         else if(SWITCH_GetState(GPIO_PORTB, GPIO_PIN1) == SWITCH_PRESSED)
//         {
//             LED_On(GPIO_PORTA, GPIO_PIN0);
//             LED_On(GPIO_PORTA, GPIO_PIN1);
//             delay();
//             delay();
//             LED_Off(GPIO_PORTA, GPIO_PIN0);
//             LED_Off(GPIO_PORTA, GPIO_PIN1);
//             delay();
//             delay();
//         }
//         // if no switch is pressed, both leds are off
//         else
//         {
//             LED_Off(GPIO_PORTA, GPIO_PIN0);
//             LED_Off(GPIO_PORTA, GPIO_PIN1);
//         }
//     }
// }