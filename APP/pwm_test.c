#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"
#include "../MCAL/PWM/PWM_interface.h"
#include "pwm_test.h"

// Define Pins 
#define MOTOR_EN1_PORT  GPIO_PORTC
#define MOTOR_EN1_PIN   GPIO_PIN2  // CCP1 is hardwired to RC2
#define MOTOR_IN1_PORT  GPIO_PORTC
#define MOTOR_IN1_PIN   GPIO_PIN0  // Direction Pin 1
#define MOTOR_IN2_PORT  GPIO_PORTC
#define MOTOR_IN2_PIN   GPIO_PIN1  // Direction Pin 2

static u8 current_speed_percentage = 0;

// THE CALLBACK FUNCTION (Triggered by RB0 Button Press) 
static void APP_MotorSpeed_ISR(void)
{
    // Increase speed by 25%
    current_speed_percentage += 25;
    
    // If it exceeds 100%, cycle back to 25% 
    if(current_speed_percentage > 100)
    {
        current_speed_percentage = 25;
    }
    
    // Update the PWM hardware
    PWM1_SetDutyCycle(current_speed_percentage);
}

//THE TEST FUNCTION
void APP_TestPWM(void)
{
    // 1. Initialize GPIO 
    GPIO_Init();
    
    // Motor Enable (PWM) pin must be output
    GPIO_SetPinDirection(MOTOR_EN1_PORT, MOTOR_EN1_PIN, GPIO_OUTPUT);
    
    // Motor Direction pins must be outputs
    GPIO_SetPinDirection(MOTOR_IN1_PORT, MOTOR_IN1_PIN, GPIO_OUTPUT);
    GPIO_SetPinDirection(MOTOR_IN2_PORT, MOTOR_IN2_PIN, GPIO_OUTPUT);

    // 2. Set Motor Direction to spin "Forward" (IN1 High, IN2 Low)
    GPIO_SetPinValue(MOTOR_IN1_PORT, MOTOR_IN1_PIN, GPIO_HIGH);
    GPIO_SetPinValue(MOTOR_IN2_PORT, MOTOR_IN2_PIN, GPIO_LOW);

    // 3. Initialize External Interrupt for the Button 
    EXT_INT_Init();
    EXT_INT_SetEdge(falling_edge); // Assuming a standard pull-up button setup
    EXT_INT_SetCallback(APP_MotorSpeed_ISR);
    EXT_INT_Enable();

    // 4. Initialize PWM
    PWM1_Init();

    // 5. Start at 25% to match the assignment prompt requirement
    current_speed_percentage = 25;
    PWM1_SetDutyCycle(current_speed_percentage);

    // 6. Infinite Loop
    while(1)
    { 
        // The motor spins in the background.
    }
}