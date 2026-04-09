#include "../MCAL/PWM/PWM_Interface.h"
#include "util/delay.h"

void APP_Test_PWM(void)
{
    static u8 Local_u8InitDone = 0;
    static u8 Local_u8DutyCycle = 0;
    static s8 Local_s8Direction = 1;

    if (Local_u8InitDone == 0)
    {

        PWM_voidInit();
        PWM_voidStart();

        Local_u8InitDone = 1;
    }


    PWM_voidSetDutyCycle(Local_u8DutyCycle);


    Local_u8DutyCycle += Local_s8Direction;

    if (Local_u8DutyCycle >= 100)
    {
        Local_s8Direction = -1;
    }
    else if (Local_u8DutyCycle <= 0)
    {
        Local_s8Direction = 1;
    }


    Delay_ms(20);
}