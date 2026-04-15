#include "../MCAL/ADC/ADC_interface.h"

void ADC_Test(void)
{
    ADC_voidInit();

    u16 value;

    while(1)
    {
        value=ADC_u16ReadChannel(0);
    }
}