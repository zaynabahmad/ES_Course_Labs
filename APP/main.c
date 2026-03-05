/*
* APPLICATION LAYER
*/
#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"

#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/INT0/EXTI_interface.h"

/* Definitions for assumed standard macros (adjust based on your actual GPIO interface) */
#ifndef GPIO_INPUT
#define GPIO_INPUT  1
#endif
#ifndef GPIO_PIN1
#define GPIO_PIN1   1
#endif

/* Application Callback Function to be executed in ISR context */
void App_ButtonAction(void)
{
    /* * Requirement: Keep ISR short and fast. 
     * Do NOT use long delays inside ISR. 
     * We simply toggle the LED here.
     */
    LED_Toggle(GPIO_PORTB, GPIO_PIN1);
}

void main()
{
    /* Initialize the LED on PORTB, PIN1 (Leave PIN0 for the external interrupt) */
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    
    /* Configuration Step 1: Set RB0 as input */
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);
    
    /* Connect the application function to the driver */
    EXTI_voidSetCallBack(App_ButtonAction);

    /* Configuration Step 2 & 3: Select interrupt edge and clear flag 
       (Both handled internally by our Init function based on config) */
    EXTI_voidInit();
    
    /* Configuration Step 4: Enable External Interrupt */
    EXTI_voidEnable();
    
    /* Configuration Step 5: Enable Global Interrupt */
    EXTI_voidEnableGlobalInterrupt();

    while(1)
    {
        /* Main loop remains empty; MCU waits for the interrupt to trigger */
    }
}





