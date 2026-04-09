#include "app_tests.h"
#include "../MCAL/ADC/ADC_Interface.h"

static volatile unsigned int APP_ADC_LastValue = 0;
static ADC_ConfigType APP_ADC_Config = {ADC_CHANNEL_0, 0, 0x80, 1};

void APP_ADC_Test(void)
{
    ADC_Init(&APP_ADC_Config);
    APP_ADC_LastValue = ADC_ReadChannel(ADC_CHANNEL_0);
}
