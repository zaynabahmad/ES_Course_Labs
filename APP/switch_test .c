#include "D:/ES-Project-Lab/SERVICES/std_types.h"
#include "D:/ES-Project-Lab/MCAL/GPIO/gpio.h"
#include "D:/ES-Project-Lab/HAL/switch_interface.h"
#include "D:/ES-Project-Lab/HAL/led_interface.h"

void app_switch_test(void)
{
    u8 switchState = 0;

    SWITCH_Init(GPIO_PORTB, GPIO_PIN0);
    LED_Init(GPIO_PORTD, GPIO_PIN0);

    while(1)
    {
        switchState = SWITCH_GetState(GPIO_PORTB, GPIO_PIN0);

        if(switchState == GPIO_HIGH)
        {
            LED_On(GPIO_PORTD, GPIO_PIN0);
        }
        else
        {
            LED_Off(GPIO_PORTD, GPIO_PIN0);
        }
    }
}