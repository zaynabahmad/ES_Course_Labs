#include "app_tests.h"

#include "../MCAL/ADC/ADC_Interface.h"

static volatile unsigned short APP_LastAdcReading = 0;

void APP_Test_ADC(void)
{
    ADC_Init();
    APP_LastAdcReading = ADC_ReadChannel(ADC_CHANNEL_0);
    (void)APP_LastAdcReading;
}
