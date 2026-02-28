/*
* APPLICATION LAYER


*/
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/GPIO/EXT_INT_Interface.h"



/* LED on RC2 */
#define MY_LED_PORT GPIO_PORTC
#define MY_LED_PIN  0

void App_OnInterrupt(void)
{
    LED_Toggle(MY_LED_PORT, MY_LED_PIN);
}

void main()
{
    /* Initialize LED */
    LED_Init(MY_LED_PORT, MY_LED_PIN);

    /* Initialize External Interrupt INT0 */
    EXT_INT0_Init();
    EXT_INT0_SetEdge(RISING_EDGE);
    EXT_INT0_SetCallback(App_OnInterrupt);
    EXT_INT0_Enable();

    while (1)
    {
        // Main loop empty
    }
}