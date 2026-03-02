#include "LED_interface.h"
#include "GPIO_interface.h"
#include "EXT_INT0_interface.h"


// =================>LED Sequences Control<=======================================
/*
void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);  // ~1ms at 8MHz
}

void main()
{
    LED_Init(GPIO_PORTB, GPIO_PIN0);
    LED_Init(GPIO_PORTB, GPIO_PIN1);

    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN2, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN3, GPIO_INPUT);

        while(1)
    {
        if(GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN2))  // Switch 1
        {
            LED_On(GPIO_PORTB, GPIO_PIN0);
            LED_On(GPIO_PORTB, GPIO_PIN1);
            delay_ms(200);
            LED_Off(GPIO_PORTB, GPIO_PIN0);
            LED_Off(GPIO_PORTB, GPIO_PIN1);
            delay_ms(200);
        }
        else if(GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN3))  // Switch 2
        {
            LED_On(GPIO_PORTB, GPIO_PIN0);
            LED_On(GPIO_PORTB, GPIO_PIN1);
            delay_ms(500);
            LED_Off(GPIO_PORTB, GPIO_PIN0);
            LED_Off(GPIO_PORTB, GPIO_PIN1);
            delay_ms(500);
        }
        else
        {
            LED_Off(GPIO_PORTB, GPIO_PIN0);
            LED_Off(GPIO_PORTB, GPIO_PIN1);
        }
    }
}

*/

// =======================================>External Interrupt Driver<=======================================

/*
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

*/
