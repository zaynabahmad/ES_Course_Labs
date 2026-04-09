#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/PWM/PWM_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void PWM_Test(void)
{
    GPIO_Init();
    
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN2, GPIO_OUTPUT);
    
    PWM_Init(PWM_CHANNEL_1);
    
    PWM_SetDutyCycle(PWM_CHANNEL_1, 50);
    
    PWM_Start(PWM_CHANNEL_1);
    
    while(1)
    {
        PWM_SetDutyCycle(PWM_CHANNEL_1, 25);
        for(u32 i = 0; i < 50000; i++);
        
        PWM_SetDutyCycle(PWM_CHANNEL_1, 50);
        for(u32 i = 0; i < 50000; i++);
        
        PWM_SetDutyCycle(PWM_CHANNEL_1, 75);
        for(u32 i = 0; i < 50000; i++);
        
        PWM_SetDutyCycle(PWM_CHANNEL_1, 100);
        for(u32 i = 0; i < 50000; i++);
    }
}
