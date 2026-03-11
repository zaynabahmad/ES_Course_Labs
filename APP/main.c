#include "../HAL/MOTOR/MOTOR_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

volatile u8 level = 0;
volatile u8 button_flag = 0;

void ButtonPressed(void)
{
    // Interrupt fires on both edges in Proteus — only act on actual press (LOW)
    if(GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN0) == GPIO_LOW)
    {
        button_flag = 1;
    }
}

void main(void)
{
    MOTOR_Init();
    EXT_INT0_Init();
    EXT_INT0_SetEdge(FALLING_EDGE);
    EXT_INT0_SetCallback(ButtonPressed);
    EXT_INT0_Enable();

    MOTOR_SetSpeed(level);    // Start at 25%

    while(1)
    {
        if(button_flag == 1)
        {
            button_flag = 0;
            level++;
            if(level > 3) level = 0;    // 25% ? 50% ? 75% ? 100% ? 25%...
            MOTOR_SetSpeed(level);
        }
    }
}