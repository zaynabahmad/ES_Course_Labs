#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/EXT_INT/EXT_INT_interface.h"
#include "HAL/LED/LED_interface.h"
#include "HAL/SWITCH/SWITCH_interface.h"
#include "SERVICES/STD_TYPES.h"

#define LED_PORT    GPIO_PORTA
#define LED_PIN     GPIO_PIN1

#define SW_PIN      GPIO_PIN0    


static void App_OnButtonPress(void)
{
    LED_Toggle(LED_PORT, LED_PIN);   
}


void main(void)
{
    
    LED_Init(LED_PORT, LED_PIN);


    SWITCH_Init(SW_PIN);

    EXT_INT0_Init();

    EXT_INT0_SetEdge(EXT_INT_FALLING_EDGE);

    EXT_INT0_SetCallback(App_OnButtonPress);

    EXT_INT0_Enable();

    while(1)
    {
    }
}