/*
* APPLICATION LAYER


*/

#include "../HAL/LED/LED_interface.h"
#include "../HAL/Switch/Switch_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void main()
{
        ADCON1 = 0x06;
        LED_Init(GPIO_PORTB, GPIO_PIN0);
        LED_Init(GPIO_PORTB, GPIO_PIN1);
        Switch_Init(GPIO_PORTA, GPIO_PIN0);
        Switch_Init(GPIO_PORTA, GPIO_PIN1);
    while(1)
    {
                if ((switch_read(GPIO_PORTA, GPIO_PIN0) == GPIO_LOW) && (switch_read(GPIO_PORTA, GPIO_PIN1) == GPIO_LOW)) {
                        LED_Off(GPIO_PORTB, GPIO_PIN0);
                        LED_Off(GPIO_PORTB, GPIO_PIN1);
                }
                else if (switch_read(GPIO_PORTA, GPIO_PIN0) == GPIO_HIGH)
                {
                        LED_On(GPIO_PORTB, GPIO_PIN0);
                        LED_On(GPIO_PORTB, GPIO_PIN1);
                        Delay_ms(200);
                        LED_Off(GPIO_PORTB, GPIO_PIN0);
                        LED_Off(GPIO_PORTB, GPIO_PIN1);
                        Delay_ms(200);
                }
                else if (switch_read(GPIO_PORTA, GPIO_PIN1) == GPIO_HIGH)
                {
                        LED_On(GPIO_PORTB, GPIO_PIN0);
                        LED_On(GPIO_PORTB, GPIO_PIN1);
                        Delay_ms(500);
                        LED_Off(GPIO_PORTB, GPIO_PIN0);
                        LED_Off(GPIO_PORTB, GPIO_PIN1);
                        Delay_ms(500);
                }
    }
}