/*
* APPLICATION LAYER


*/
#include "LED_interface.h"
#include "GPIO_interface.h"
#include "EXT_INT0_interface.h"

/* Callback Function */
void App_ToggleLed(void);

void main()
{
    // Initialize LED
    LED_Init(GPIO_PORTB, GPIO_PIN1);

    // Initialize External Interrupt
    EXT_INT0_Init();

    // Register callback function
    EXT_INT0_SetCallback(App_ToggleLed);

    // Enable interrupt
    EXT_INT0_Enable();

    while(1)
    {
    }
}

void App_ToggleLed(void)
{
    LED_Toggle(GPIO_PORTB, GPIO_PIN1);
}