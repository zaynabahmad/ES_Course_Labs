#include "LM35_Interface.h"
#include "LM35_Config.h"
#include "LM35_Private.h"
#include "../../MCAL/ADC/ADC_Interface.h"

void LM35_Init(void)
{
    ADC_voidInit();
}


u16 LM35_GetTemp(void)
{
    u16 adc_val = ADC_u16GetChannelReading(LM35_ADC_CHANNEL);
    
    
    u32 temp_long = ((u32)adc_val * LM35_VREF_MV) / (LM35_ADC_STEPS * LM35_MV_PER_DEG);
    
    return (u16)temp_long;
}


u16 LM35_GetTempTenth(void)
{
    u16 adc_val = ADC_u16GetChannelReading(LM35_ADC_CHANNEL);
    u32 temp_tenth = ((u32)adc_val * LM35_VREF_MV) / LM35_ADC_STEPS;

    return (u16)temp_tenth;
}