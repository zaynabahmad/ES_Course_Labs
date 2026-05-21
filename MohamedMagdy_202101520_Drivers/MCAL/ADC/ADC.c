#include "ADC_Interface.h"

void ADC_Init(void)
{
    ADCON1 = ADC_PORT_CONFIG;

    ADCON0 = (u8)((ADC_CLOCK_SEL & 0x03U) << 6);

    ADC_SelectChannel(ADC_CHANNEL_0);

    SET_BIT(ADCON0, ADON_BIT);

    CLR_BIT(PIR1, ADIF_BIT);
}

void ADC_SelectChannel(u8 Channel)
{
    ADCON0 = (ADCON0 & ~ADC_CHANNEL_MASK) | (u8)((Channel & 0x07U) << 3);
}

u16 ADC_Read(u8 Channel)
{
    u8  delay_count;
    u16 result;

    ADC_SelectChannel(Channel);

    for(delay_count = 0; delay_count < ADC_ACQUISITION_DLY; delay_count++) { ; }

    SET_BIT(ADCON0, GO_BIT);

    while(GET_BIT(ADCON0, GO_BIT)) { ; }

    result = (u16)(((u16)(ADRESH & 0x03U) << 8U) | (u16)ADRESL);

    return result;
}

void ADC_Disable(void)
{
    CLR_BIT(ADCON0, ADON_BIT);
}
