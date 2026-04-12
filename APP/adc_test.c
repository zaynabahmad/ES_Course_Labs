#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/ADC/ADC_interface.h"

void ADC_Test(void)
{
    u8 Channel;
    u8 i;
    u32 j;

    ADC_Init();

    // Test all 4 channels
    for (Channel = 0; Channel < 4; Channel++)
    {
        // Select and read channel
        (void)ADC_ReadChannel(Channel);

        // Delay for observation
        for (j = 0; j < 30000; j++)
            ;
    }

    // Continuous reading from AN0
    ADC_SelectChannel(ADC_CHANNEL_AN0);

    for (i = 0; i < 10; i++)
    {
        (void)ADC_ReadChannel(ADC_CHANNEL_AN0);

        for (j = 0; j < 20000; j++)
            ;
    }
}
