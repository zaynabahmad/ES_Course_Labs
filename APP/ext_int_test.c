#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

static u8 InterruptCount = 0;
static u8 LED_Pin = 0;

void EXT_INT_Callback(void)
{
    InterruptCount++;

    // Toggle LED on PB0
    u8 current = GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN0);
    if (current)
        GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN0, 0);
    else
        GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN0, 1);
}

void EXT_INT_Test(void)
{
    u32 j;
    u8 i;

    GPIO_Init();
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN0, 0);

    EXT_INT_Init();
    EXT_INT_SetEdge(rising_edge);
    EXT_INT_SetCallback(EXT_INT_Callback);
    EXT_INT_Enable();

    // Test rising edge - wait period
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 50000; j++);
    }

    // Test falling edge
    EXT_INT_SetEdge(falling_edge);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 50000; j++);
    }

    EXT_INT_Disable();

    // Turn off LED
    GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN0, 0);
    for (j = 0; j < 30000; j++);
}
