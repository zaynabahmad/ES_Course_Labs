#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"
#include "../MCAL/PWM/PWM_interface.h"

#include "MOTOR_config.h"
#include "MOTOR_private.h"
#include "MOTOR_interface.h"


#include "STD_TYPES.h"

void MOTOR_Init(void)
{
    //This was a recomendation from that AI to keep the pin input until the intialziation process is done, i liked the idea so i used ti
    GPIO_SetPinDirection(PWM_PORT, PWM_PIN, GPIO_INPUT);
    
    PWM_inti();    
    PWM_setFrequency(5000); 
    PWM_setDutyCycle(0);
    
    GPIO_SetPinDirection(PWM_PORT, PWM_PIN, GPIO_OUTPUT);
}

