/*
* APPLICATION LAYER
*/
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/GPIO/EXT_INTERRUPT/EXT_INT_INTERFACE.H"
#include "../HAL/Switch/Switch_interface.h"

void led_logic(void)
{
    LED_Toggle(GPIO_PORTC, GPIO_PIN0);
}

void short_sequence() {
    LED_Toggle(GPIO_PORTC, GPIO_PIN0);
    LED_Toggle(GPIO_PORTC, GPIO_PIN1);
    delay_ms(200);
    LED_Toggle(GPIO_PORTC, GPIO_PIN0);
    LED_Toggle(GPIO_PORTC, GPIO_PIN1);
    delay_ms(200);
}
void long_sequence() {
    LED_Toggle(GPIO_PORTC, GPIO_PIN0);
    LED_Toggle(GPIO_PORTC, GPIO_PIN1);
    delay_ms(500);
    LED_Toggle(GPIO_PORTC, GPIO_PIN0);
    LED_Toggle(GPIO_PORTC, GPIO_PIN1);
    delay_ms(500);
}
void main()
{

    //Task 1
    LED_Init(GPIO_PORTC, GPIO_PIN0);
    LED_Init(GPIO_PORTC, GPIO_PIN1);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN1, GPIO_OUTPUT);
    GPIO_SetPinValue(GPIO_PORTC, GPIO_PIN0, GPIO_LOW);
    GPIO_SetPinValue(GPIO_PORTC, GPIO_PIN1, GPIO_LOW);
    SWITCH_Init(GPIO_PORTB, GPIO_PIN0);
    SWITCH_Init(GPIO_PORTB, GPIO_PIN1);

    while (1)
    {
        if (SWITCH_Read(GPIO_PORTB, GPIO_PIN0) == GPIO_HIGH) {
            short_sequence();
        }
        else if (SWITCH_Read(GPIO_PORTB, GPIO_PIN1) == GPIO_HIGH) {
            long_sequence();
        }
        else {
            GPIO_SetPinValue(GPIO_PORTC, GPIO_PIN0, GPIO_LOW);
            GPIO_SetPinValue(GPIO_PORTC, GPIO_PIN1, GPIO_LOW);
        }
    }
    
    // Task 2
    LED_Init(GPIO_PORTC, GPIO_PIN0);
    SWITCH_Init(GPIO_PORTB, GPIO_PIN0);
    EXT_INT_Init();
    EXT_INT_SetCallback(led_logic);
    EXT_INT_Enable();
    while (1){ }
    
}