#include "led.h"

void LED_Init(void)
{
    GPIO_SetPinDirection(LED_PORT, LED_PIN, GPIO_OUTPUT);
    GPIO_WritePin(LED_PORT, LED_PIN, GPIO_LOW);
}

void LED_On(void)  { GPIO_WritePin(LED_PORT, LED_PIN, GPIO_HIGH); }
void LED_Off(void) { GPIO_WritePin(LED_PORT, LED_PIN, GPIO_LOW);  }

void LED_Toggle(void)
{
    if(GPIO_ReadPin(LED_PORT, LED_PIN) == GPIO_HIGH)
        LED_Off();
    else
        LED_On();
}