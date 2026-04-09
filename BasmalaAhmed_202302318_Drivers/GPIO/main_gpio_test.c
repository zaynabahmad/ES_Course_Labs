#include "gpio.h"

int main(void)
{
    GPIO_setPinDirection(PORTA, 0, OUTPUT);

    while(1)
    {
        GPIO_writePin(PORTA, 0, 1); // LED ON
    }

    return 0;
}