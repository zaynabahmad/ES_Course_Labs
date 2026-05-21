#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "ext_int_test.h"

#define INT_LED_PORT    GPIO_PORTD
#define INT_LED_PIN     GPIO_PIN2

static void delay(void)
{
    unsigned int i;
    for(i = 0; i < 30000U; i++) { ; }
}

static void Button_ISR_Callback(void)
{
    u8 current;
    current = GPIO_GetPinValue(INT_LED_PORT, INT_LED_PIN);

    if(current == GPIO_HIGH)
    {
        GPIO_SetPinValue(INT_LED_PORT, INT_LED_PIN, GPIO_LOW);
    }
    else
    {
        GPIO_SetPinValue(INT_LED_PORT, INT_LED_PIN, GPIO_HIGH);
    }
}

void EXT_INT_Test(void)
{
    GPIO_SetPinDirection(INT_LED_PORT, INT_LED_PIN, GPIO_OUTPUT);
    GPIO_SetPinValue(INT_LED_PORT, INT_LED_PIN, GPIO_LOW);

    EXT_INT_Init();

    EXT_INT_SetCallback(Button_ISR_Callback);

    EXT_INT_SetEdge(rising_edge);
    delay();
    EXT_INT_SetEdge(falling_edge);

    EXT_INT_Enable();
}
