#include "../MCAL/EXT_INT/EXT_INT_Interface.h"


void EXTI_APP_Callback(void)
{
    static u8 State = 0;
    State = !State;
    GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN0, State);
}

void APP_Test_EXTI(void)
{
    static u8 Local_u8InitDone = 0;

    if (Local_u8InitDone == 0)
    {

        GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN0, GPIO_OUTPUT);


        EXT_INT_SetCallback(EXTI_APP_Callback);


        EXT_INT_Init();
        EXT_INT_Enable();

        Local_u8InitDone = 1;
    }


}