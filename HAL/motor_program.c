#include "D:/ES-Project-Lab/SERVICES/std_types.h"
#include "D:/ES-Project-Lab/MCAL/GPIO/gpio.h"
#include "motor_interface.h"

void MOTOR_Init(u8 port1, u8 pin1, u8 port2, u8 pin2)
{
    GPIO_setPinDirection(port1, pin1, GPIO_OUTPUT);
    GPIO_setPinDirection(port2, pin2, GPIO_OUTPUT);

    GPIO_setPinValue(port1, pin1, GPIO_LOW);
    GPIO_setPinValue(port2, pin2, GPIO_LOW);
}

void MOTOR_Forward(u8 port1, u8 pin1, u8 port2, u8 pin2)
{
    GPIO_setPinValue(port1, pin1, GPIO_HIGH);
    GPIO_setPinValue(port2, pin2, GPIO_LOW);
}

void MOTOR_Reverse(u8 port1, u8 pin1, u8 port2, u8 pin2)
{
    GPIO_setPinValue(port1, pin1, GPIO_LOW);
    GPIO_setPinValue(port2, pin2, GPIO_HIGH);
}

void MOTOR_Stop(u8 port1, u8 pin1, u8 port2, u8 pin2)
{
    GPIO_setPinValue(port1, pin1, GPIO_LOW);
    GPIO_setPinValue(port2, pin2, GPIO_LOW);
}