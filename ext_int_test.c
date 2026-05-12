#include "ext_int_test.h"
#include "../MCAL/EXT_INT0_INTERFACE.h"
#include "../HAL/LED_INTERFACE.h"
#include "../MCAL/GPIO_INTERFACE.h"

static void EXT_INT_Callback(void)
{
    /* Toggle LED on PORTC pin1 each time INT0 fires */
    LED_Toggle(GPIO_PORTC, GPIO_PIN1);
}

void EXT_INT_Test_Init(void)
{
    LED_Init(GPIO_PORTC, GPIO_PIN1);
    EXT_INT0_Init();
    EXT_INT0_SetEdge(RISING_EDGE);
    EXT_INT0_SetCallback(EXT_INT_Callback);
    EXT_INT0_Enable();
}

void EXT_INT_Test_Run(void)
{
    /* Interrupt-driven: nothing to poll in the super-loop */
}
