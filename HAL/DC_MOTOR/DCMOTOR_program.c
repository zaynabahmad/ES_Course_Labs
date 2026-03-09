#include "DCMOTOR_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void DCMOTOR_Init(u8 Port, u8 Pin1, u8 Pin2)
{
    GPIO_SetPinDirection(Port, Pin1, GPIO_OUTPUT);
    GPIO_SetPinDirection(Port, Pin2, GPIO_OUTPUT);

    DCMOTOR_Stop(Port, Pin1, Pin2);
}

void DCMOTOR_Forward(u8 Port, u8 Pin1, u8 Pin2)
{
    GPIO_SetPinValue(Port, Pin1, GPIO_HIGH);
    GPIO_SetPinValue(Port, Pin2, GPIO_LOW);
}

void DCMOTOR_Reverse(u8 Port, u8 Pin1, u8 Pin2)
{
    GPIO_SetPinValue(Port, Pin1, GPIO_LOW);
    GPIO_SetPinValue(Port, Pin2, GPIO_HIGH);
}

void DCMOTOR_Stop(u8 Port, u8 Pin1, u8 Pin2)
{
    GPIO_SetPinValue(Port, Pin1, GPIO_LOW);
    GPIO_SetPinValue(Port, Pin2, GPIO_LOW);
}