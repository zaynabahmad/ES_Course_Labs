#include "../MCAL/GPIO/GPIO_interface.h"

void GPIO_Test()
{
    // Set pin A0 as output
    GPIO_SetPinDirection('A', 0, OUTPUT);

    // Turn LED ON
    GPIO_WritePin('A', 0, HIGH);
}