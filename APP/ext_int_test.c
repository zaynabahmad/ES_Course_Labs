#include "app_tests.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

static volatile u8 APP_EXT_INT_Pending = 0;

static void APP_EXT_INT_Handler(void)
{
    APP_EXT_INT_Pending = 1;
}

void APP_EXT_INT_Test(void)
{
    LED_Init(GPIO_PORTC, GPIO_PIN0);
    EXT_INT_Init();
    EXT_INT_SetEdge(EXT_INT_FALLING_EDGE);
    EXT_INT_SetCallback(APP_EXT_INT_Handler);
    EXT_INT_Enable();
}

void APP_EXT_INT_Task(void)
{
    if (APP_EXT_INT_Pending != 0)
    {
        APP_EXT_INT_Pending = 0;
        LED_Toggle(GPIO_PORTC, GPIO_PIN0);
    }
}
