#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/PWM/PWM_interface.h"
#include "../MCAL/INT/EXT_interface.h"

/* Motor Control Pins */
#define MOTOR_PORT      GPIO_PORTD
#define MOTOR_IN1_PIN   GPIO_PIN5
#define MOTOR_IN2_PIN   GPIO_PIN6

#define PWM_PORT        GPIO_PORTC
#define PWM_CCP1_PIN    GPIO_PIN2

#define BUTTON_PORT     GPIO_PORTB
#define BUTTON_INT_PIN  GPIO_PIN0

/* Global volatile variables to handle the interrupt state safely */
volatile uint8 g_duty_cycle_level = 25;  /* Start at 25% */
volatile uint8 g_update_pwm_flag = 1;    /* Flag to tell main loop to update */

/* * Callback function (ISR) triggered by the External Interrupt.
 * Cycles through 25% -> 50% -> 75% -> 100% -> 25%.
 */
void APP_PWM_Change_Speed_ISR(void) 
{
    if (g_duty_cycle_level == 25) 
    {
        g_duty_cycle_level = 50;
    } 
    else if (g_duty_cycle_level == 50) 
    {
        g_duty_cycle_level = 75;
    } 
    else if (g_duty_cycle_level == 75) 
    {
        g_duty_cycle_level = 100;
    } 
    else if (g_duty_cycle_level == 100) 
    {
        g_duty_cycle_level = 25; 
    }
    
    /* Signal the main loop to apply the new speed */
    g_update_pwm_flag = 1;
}

/* The single test function for PWM */
void APP_PWM_Test(void) 
{
    /* 1. Setup GPIO Directions */
    /* Set RC2 (CCP1) as OUTPUT for the PWM signal */
    GPIO_SetPinDirection(PWM_PORT, PWM_CCP1_PIN, GPIO_OUTPUT);
    
    /* Set RD5 and RD6 as OUTPUT for Motor Direction */
    GPIO_SetPinDirection(MOTOR_PORT, MOTOR_IN1_PIN, GPIO_OUTPUT);
    GPIO_SetPinDirection(MOTOR_PORT, MOTOR_IN2_PIN, GPIO_OUTPUT);

    /* Set RB0 (INT0) as INPUT for the push button */
    GPIO_SetPinDirection(BUTTON_PORT, BUTTON_INT_PIN, GPIO_INPUT);

    /* 2. Initialize PWM and External Interrupt */
    PWM1_Init();
    
    EXT_INT0_Init();
    EXT_INT0_SetEdge(EXT_INT0_RISING_EDGE); /* Triggers when button is pressed */
    EXT_INT0_SetCallback(APP_PWM_Change_Speed_ISR);
    EXT_INT0_Enable();

    /* 3. Set Motor Direction to spin Forward */
    GPIO_SetPinValue(MOTOR_PORT, MOTOR_IN1_PIN, GPIO_HIGH);
    GPIO_SetPinValue(MOTOR_PORT, MOTOR_IN2_PIN, GPIO_LOW);

    /* 4. Super Loop */
    while(1) 
    {
        /* Only update the hardware PWM register if the button was pressed */
        if (g_update_pwm_flag == 1) 
        {
            PWM1_SetDutyCycle(g_duty_cycle_level);
            g_update_pwm_flag = 0; /* Clear flag until next button press */
        }
    }
}