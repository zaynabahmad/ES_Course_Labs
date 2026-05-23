#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\GPIO\GPIO_interface.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\EXTI\EXTI_interface.h"

static volatile unsigned char led_state = 0u;

void interrupt ISR(void)
{
    if (EXTI_u8GetFlag())
    {
        EXTI_voidClearFlag();
        led_state ^= 1u;
        GPIO_voidSetPinValue('B', 0, led_state);
    }
}

void EXTI_Test(void)
{
    GPIO_voidSetPinDirection('B', 0, OUTPUT);
    GPIO_voidSetPinValue('B', 0, LOW);
    EXTI_voidEnable();
    while (1);
}