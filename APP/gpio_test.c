#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void GPIO_Test(void)
{
    u16 i, j;

    GPIO_Init();

    // Set PA0, PA1 as output
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);

    // Blink 5 times
    for (i = 0; i < 5; i++)
    {
        GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
        GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);

        for (j = 0; j < 5000; j++);  // 100ms delay

        GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
        GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);

        for (j = 0; j < 5000; j++);  // 100ms delay
    }

    GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
    GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
}
