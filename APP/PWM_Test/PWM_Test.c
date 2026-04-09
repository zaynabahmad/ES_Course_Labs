#include "PWM_Test.h"
#include "../../MCAL/PWM/PWM_Interface.h"
#include "../../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

/* Motor Control PWM Parameters */
#define MOTOR_PWM_CHANNEL PWM_CCP1
#define MOTOR_PWM_PORT    GPIO_PORTC
#define MOTOR_PWM_PIN     GPIO_PIN2

volatile u8 g_u8ButtonPressed = 0;

/* Interrupt Callback Routine */
void App_EXT_INT_Callback(void)
{
    /* Set flag inside ISR to trigger app logic */
    g_u8ButtonPressed = 1;
}

void PWM_Test_Init(void)
{
    /* 1. Setup External Interrupt for Button (INT on RB0) */
    EXT_INT_Init();
    EXT_INT_SetEdge(falling_edge);
    EXT_INT_SetCallback(App_EXT_INT_Callback);
    EXT_INT_Enable();

    /* 2. Setup PWM for Motor Control */
    /* According to PIC16F877A Datasheet Section 8.3.3: 
       Make the CCPx pin an output by configuring the TRIS direction bit */
    GPIO_SetPinDirection(MOTOR_PWM_PORT, MOTOR_PWM_PIN, GPIO_OUTPUT);
    
    PWM_Init();
    
    /* Start with a 25% Duty Cycle as per requirements */
    PWM_SetDutyCycle(MOTOR_PWM_CHANNEL, 25);
    PWM_Start(MOTOR_PWM_CHANNEL);
}

void PWM_Test_App(void)
{
    /* Maintain Duty Cycle State locally */
    static u8 u8CurrentDutyCycle = 25;
    
    /* Debounce counter to ignore extremely fast interrupt bouncing */
    static u32 u32DebounceCounter = 0;

    /* Decrement debounce counter if active */
    if (u32DebounceCounter > 0)
    {
        u32DebounceCounter--;
    }

    if (g_u8ButtonPressed == 1)
    {
        /* Clear the software flag first */
        g_u8ButtonPressed = 0;

        /* Only process if debounce counter is 0 */
        if (u32DebounceCounter == 0)
        {
            /* Reload debounce counter (tweak parameter based on clock) */
            u32DebounceCounter = 30000;

            /* Cycle duty cycle levels (25 -> 50 -> 75 -> 100 -> 25) */
            if (u8CurrentDutyCycle == 25)
            {
                u8CurrentDutyCycle = 50;
            }
            else if (u8CurrentDutyCycle == 50)
            {
                u8CurrentDutyCycle = 75;
            }
            else if (u8CurrentDutyCycle == 75)
            {
                u8CurrentDutyCycle = 100;
            }
            else if (u8CurrentDutyCycle == 100)
            {
                u8CurrentDutyCycle = 25; 
            }

            /* Update dynamic PWM speed */
            PWM_SetDutyCycle(MOTOR_PWM_CHANNEL, u8CurrentDutyCycle);
        }
    }
}
