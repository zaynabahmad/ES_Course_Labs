#include "D:/ES-Project-Lab/SERVICES/std_types.h"
#include "D:/ES-Project-Lab/HAL/led_interface.h"
#include "D:/ES-Project-Lab/SERVICES/std_types.h"
#include "D:\ES-Project-Lab\MCAL\GPIO\gpio.h"

void app_led_test(void)
{
    u16 delayValue = 0;

    LED_Init(GPIO_PORTD, GPIO_PIN0);

    while(1)
    {
        LED_On(GPIO_PORTD, GPIO_PIN0);
        for(delayValue = 0; delayValue < 20000; delayValue++)
        {
            ;
        }

        LED_Off(GPIO_PORTD, GPIO_PIN0);
        for(delayValue = 0; delayValue < 20000; delayValue++)
        {
            ;
        }
    }
}
