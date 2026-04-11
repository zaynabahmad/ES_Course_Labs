#include "../HAL/LED/LED_interface.h"
#include "../HAL/LED/LED_config.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../HAL/SWITCH/SWITCH_config.h"
#include "../MCAL/EXTI/EXTI_interface.h"

void App_ToggleLed(void)
{
    LED_Toggle(LED1_PORT, LED1_PIN);
}

void APP_EXTI_Test(void)
{
    LED_Init(LED1_PORT, LED1_PIN);
    LED_Off(LED1_PORT, LED1_PIN);

    SWITCH_Init(&SW1);

    EXT_INT0_SetCallback(App_ToggleLed);
    EXT_INT0_Init();

    while(1)
    {
    }
}