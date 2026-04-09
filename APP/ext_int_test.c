#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void External_INT_Callback(void)
{
    LED_Toggle(GPIO_PORTB, GPIO_PIN0);
}

void EXT_INT_Test(void)
{
    GPIO_Init();
    LED_Init(GPIO_PORTB, GPIO_PIN0);
    
    EXT_INT_Init();
    
    EXT_INT_SetCallback(External_INT_Callback);
    
    EXT_INT_Enable();
    
    while(1)
    {
    }
}
