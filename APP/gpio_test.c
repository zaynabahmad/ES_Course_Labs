#include "../MCAL/GPIO/GPIO_interface.h"
#include "../SERVICES/BIT_MATH.h"

void APP_Test_GPIO(void)
{
    static u8 Local_u8InitDone = 0;
    u8 Local_u8ButtonState = 0;

    /* MOVE THIS LINE TO THE TOP OF THE FUNCTION */
    static u8 Toggle = 0;

    if (Local_u8InitDone == 0)
    {
        // ... Initialization code ...
        Local_u8InitDone = 1;
    }

    /* Read Button State */
    Local_u8ButtonState = GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN0);

    // ... LED logic ...

    /* Toggle Logic - Now the compiler knows what 'Toggle' is */
    Toggle = !Toggle;

CLR_BIT(INTCON, 7);

GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, Toggle);

SET_BIT(INTCON, 7);



    Delay_ms(200);
}
