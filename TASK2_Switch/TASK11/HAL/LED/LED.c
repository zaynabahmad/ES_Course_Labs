#include "../../SERVICES/STD_TYPES.h"
#include "LED_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "LED_private.h"  // contains LED1_PORT, LED1_PIN, etc.

void LED_Init(void)
{
    GPIO_SetPinDirection(LED1_PORT, LED1_PIN, GPIO_OUTPUT);
    GPIO_SetPinDirection(LED2_PORT, LED2_PIN, GPIO_OUTPUT);

    GPIO_SetPinValue(LED1_PORT, LED1_PIN, GPIO_LOW);
    GPIO_SetPinValue(LED2_PORT, LED2_PIN, GPIO_LOW);
}

void LED_On(u8 led)
{
    if(led == LED1) GPIO_SetPinValue(LED1_PORT, LED1_PIN, GPIO_HIGH);
    if(led == LED2) GPIO_SetPinValue(LED2_PORT, LED2_PIN, GPIO_HIGH);
}

void LED_Off(u8 led)
{
    if(led == LED1) GPIO_SetPinValue(LED1_PORT, LED1_PIN, GPIO_LOW);
    if(led == LED2) GPIO_SetPinValue(LED2_PORT, LED2_PIN, GPIO_LOW);
}

void LED_Toggle(u8 led)
{
    if(led == LED1) GPIO_SetPinValue(LED1_PORT, LED1_PIN, !GPIO_GetPinValue(LED1_PORT, LED1_PIN));
    if(led == LED2) GPIO_SetPinValue(LED2_PORT, LED2_PIN, !GPIO_GetPinValue(LED2_PORT, LED2_PIN));
}