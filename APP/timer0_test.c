
#include "../MCAL/TIMER_0/TIMER_0_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"



static u16 Global_u16Timer0Counter = 0;


void TMR0_Test_Callback(void)
{
    Global_u16Timer0Counter++;


    if (Global_u16Timer0Counter >= 100)
    {

        static u8 LED_State = 0;
        LED_State = !LED_State;
        GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN0, LED_State);

        Global_u16Timer0Counter = 0;
    }
}


void APP_Test_TIMER0(void)
{
    static u8 Local_u8InitDone = 0;

    if (Local_u8InitDone == 0)
    {

        GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_OUTPUT);
        TMR0_voidSetCallback(TMR0_Test_Callback);
        TMR0_voidInit();
        TMR0_voidEnableInterrupt();

        Local_u8InitDone = 1;
    }
}