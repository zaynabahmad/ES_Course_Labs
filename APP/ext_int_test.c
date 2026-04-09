#include "../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "ext_int_test.h"

static void ext_int_handler(void)
{
    /* Toggle PORTD pin0 on each external interrupt */
    u8 val = GPIO_GetPinValue(GPIO_PORTD, GPIO_PIN0);
    GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN0, (val == GPIO_HIGH) ? GPIO_LOW : GPIO_HIGH);
}

void ext_int_test_run(void)
{
    GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN0, GPIO_LOW);

    EXT_INT_Init();
    EXT_INT_SetEdge(EXT_INT_FALLING_EDGE);
    EXT_INT_SetCallback(ext_int_handler);
    EXT_INT_Enable();
}
