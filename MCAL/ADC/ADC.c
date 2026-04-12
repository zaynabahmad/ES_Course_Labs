#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "../../SERVICES/BIT_MATH.h"

static u8 Current_Channel = ADC_DEFAULT_CHANNEL;

void ADC_Init(void)
{
    ADCON1 = 0x0E;
    ADCON0 = 0b10000001;
    SET_BIT(TRISE, 0);
}

void ADC_SelectChannel(u8 Channel)
{
    u8 ADCON0_Temp;

    if (Channel > ADC_CHANNEL_AN7)
        return;

    Current_Channel = Channel;
    ADCON0_Temp = ADCON0 & 0xC7;
    ADCON0_Temp |= ((Channel & 0x07) << 3);
    ADCON0 = ADCON0_Temp;
}

void ADC_StartConversion(void)
{
    SET_BIT(ADCON0, GO_DONE);
}

u8 ADC_IsConversionComplete(void)
{
    return (GET_BIT(ADCON0, GO_DONE) == 0);
}

u16 ADC_GetResult(void)
{
    u16 Result;
    Result = ((u16)ADRESH << 8) | ADRESL;
    return Result;
}

u16 ADC_ReadChannel(u8 Channel)
{
    ADC_SelectChannel(Channel);
    ADC_StartConversion();

    while (GET_BIT(ADCON0, GO_DONE));

    u8 delay_count = 0;
    while (delay_count < 10)
        delay_count++;

    return ADC_GetResult();
}

void ADC_SetRefVoltage(u8 RefMode)
{
    u8 ADCON1_Temp = ADCON1 & 0x0F;

    if (RefMode == ADC_VREF_EXTERNAL)
        ADCON1_Temp |= 0x30;

    ADCON1 = ADCON1_Temp;
}
