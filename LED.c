#include "D:\embeddedsystems\Labs\LABTASK2\Project\MCAL\GPIO.h"
#include "LED.h"

void LED_Init()
{
     GPIO_SetPinDirection(&TRISB, 0, OUTPUT);
     GPIO_SetPinDirection(&TRISB, 1, OUTPUT);
}

void LED_On(unsigned short pin)
{
     GPIO_WritePin(&PORTB, pin, HIGH);
}

void LED_Off(unsigned short pin)
{
     GPIO_WritePin(&PORTB, pin, LOW);
}

void LED_Toggle(unsigned short pin)
{
     PORTB ^= (1 << pin);
}