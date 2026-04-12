#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LED/LED_interface.h"

#define EXT_INT_LED_PORT   GPIO_PORTA
#define EXT_INT_LED_PIN    GPIO_PIN0

/* Set from ISR stub only; LED toggled from main (mikroC reentrancy) */
static volatile u8 EXT_INT_LedToggleRequest;

static void EXT_INT_UserCallback(void)
{
    EXT_INT_LedToggleRequest = 1;
}

void EXT_INT_Test(void)
{
    u16 i;

    /* Initialize LED */
    LED_Init(EXT_INT_LED_PORT, EXT_INT_LED_PIN);

    /* Initialize external interrupt */
    EXT_INT_Init();
    EXT_INT_SetEdge(falling_edge);
    EXT_INT_SetCallback(EXT_INT_UserCallback);
    EXT_INT_Enable();

    /* Poll deferred work from main context */
    for(i = 0; i < 30000u; i++)
    {
        if(EXT_INT_LedToggleRequest)
        {
            EXT_INT_LedToggleRequest = 0;
            LED_Toggle(EXT_INT_LED_PORT, EXT_INT_LED_PIN);
        }
    }

    EXT_INT_Disable();
}
