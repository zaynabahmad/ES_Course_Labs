#include "../MCAL/PWM/PWM_interface.h"
#include "../MCAL/INT0/EXT_INT0_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"

#define MOTOR_PORT GPIO_PORTC
#define MOTOR_PIN  2  // CCP1 pin for PWM
#define BUTTON_PORT GPIO_PORTB
#define BUTTON_PIN  0  // RB0 / INT0

// Duty cycle levels in percent
u8 duty_levels[4] = {25, 50, 75, 100};
u8 duty_index = 0;

// Callback function for external interrupt (button press)
void PWM_ButtonPress_Callback(void)
{
    duty_index++;
    if(duty_index > 3) duty_index = 0;

    PWM1_SetDuty(duty_levels[duty_index]);
}

// PWM Test Function
void PWM_Motor_Test(void)
{
    // 1. Initialize motor pin as output
    GPIO_SetPinDirection(MOTOR_PORT, MOTOR_PIN, GPIO_OUTPUT);

    // 2. Initialize PWM module
    PWM1_Init();
    PWM1_SetDuty(duty_levels[duty_index]);  // start at 25%

    // 3. Initialize External Interrupt (INT0)
    EXT_INT0_Init();
    EXT_INT0_SetEdge(FALLING_EDGE);         // detect button press
    EXT_INT0_SetCallback(PWM_ButtonPress_Callback);
    EXT_INT0_Enable();

    // 4. Main loop does nothing, PWM controlled by hardware & ISR
    while(1)
    {
        // Optional: add small idle delay if needed
    }
}