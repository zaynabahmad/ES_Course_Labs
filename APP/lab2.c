/*
* LAB 2 - External Interrupt
*/

#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../MCAL/EXT_INT0/EXT_INT0_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void led_toggle_callback(void)
{
    LED_Toggle(GPIO_PORTB, GPIO_PIN1);
}

void lab2_init(void)
{
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    SWITCH_Init(GPIO_PIN0);
    EXT_INT0_Init();
    EXT_INT0_SetCallback(&led_toggle_callback);
}
