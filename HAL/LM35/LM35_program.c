#include "LM35_interface.h"
#include "LM35_private.h"
#include "LM35_config.h"
#include "../../MCAL/ADC/ADC_interface.h"
#include "../../SERVICES/STD_TYPES.h"

void LM35_Init(void)
{
    ADC_Init();
}

float LM35_GetTemperature(void)
{
    u16   Local_RawADC;
    float Local_Temperature;

    Local_RawADC      = ADC_Read(LM35_ADC_CHANNEL);
    Local_Temperature = (float)Local_RawADC *
                        (LM35_MV_PER_STEP / LM35_MV_PER_DEGREE);

    return Local_Temperature;
}
