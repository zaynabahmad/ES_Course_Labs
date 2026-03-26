#include "LM35_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"

#define LM35_ADC_CHANNEL        ADC_CHANNEL_AN0
#define LM35_ACQ_TIME_US        20
#define LM35_NEXT_SAMPLE_US     8

void LM35_Init(void)
{
    ADC_Step1_Init(LM35_ADC_CHANNEL,
                   ADC_CLOCK_FOSC_DIV_32,
                   ADC_CFG_AN0_ONLY_ANALOG,
                   ADC_RIGHT_JUSTIFIED);

    ADC_Step2_InterruptConfig(ADC_INTERRUPT_DISABLE);
}

u16 LM35_ConvertToCentiC(u16 adc_value)
{
    return (u16)(((u32)adc_value * 50000UL) / 1024UL);
}

u16 LM35_ReadTemperatureCentiC(void)
{
    u16 adc_value;

    adc_value = ADC_ReadChannelBlocking(LM35_ADC_CHANNEL, LM35_ACQ_TIME_US);
    ADC_Step7_WaitBeforeNextSample_us(LM35_NEXT_SAMPLE_US);

    return LM35_ConvertToCentiC(adc_value);
}