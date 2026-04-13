#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "../../SERVICES/BIT_MATH.h"

static u8 Local_ADC_Resolution = ADC_10BIT_RESOLUTION;
static u8 Local_ADC_CurrentChannel = ADC_CHANNEL0;
static void (*ADC_Callback)(u16) = NULL_PTR;

void ADC_Init(u8 resolution, u8 voltageRef)
{
    u8 Temp = 0;

    Local_ADC_Resolution = resolution;
    ADCON0 = 0x00;

    Temp = (ADC_DEFAULT_CLOCK << 6);
    Temp |= (ADC_DEFAULT_CHANNEL << 3) & 0x38;
    Temp |= (1 << ADON);
    ADCON0 = Temp;

    Temp = 0x00;

    if (voltageRef == ADC_REF_VSS_VDD)
        Temp = 0x00;
    else if (voltageRef == ADC_REF_VSS_VREF)
        Temp = 0x10;
    else if (voltageRef == ADC_REF_VREF_VDD)
        Temp = 0x20;
    else if (voltageRef == ADC_REF_VREF_VREF)
        Temp = 0x30;

    if (resolution == ADC_10BIT_RESOLUTION)
        SET_BIT(Temp, ADFM);
    else
        CLR_BIT(Temp, ADFM);

    Temp |= 0x00;
    ADCON1 = Temp;

    SET_BIT(INTCON, 7);
    SET_BIT(PIE1, ADIE);
    CLR_BIT(PIR1, ADIF);
}

void ADC_StartConversion(u8 channel)
{
    u8 Temp;

    if (channel > 13)
        channel = 0;

    Local_ADC_CurrentChannel = channel;
    Temp = ADCON0 & 0xC7;
    Temp |= ((channel & 0x07) << CHS0);
    ADCON0 = Temp;

    SET_BIT(ADCON0, GO_DONE);
}

u8 ADC_IsConversionDone(void)
{
    return !GET_BIT(ADCON0, GO_DONE);
}

u16 ADC_ReadValue(void)
{
    u16 Digital_Value = 0;

    if (Local_ADC_Resolution == ADC_10BIT_RESOLUTION)
    {
        Digital_Value = ((u16)ADRESH << 8) | ADRESL;
        Digital_Value >>= 6;
    }
    else
    {
        Digital_Value = ADRESH;
    }

    return Digital_Value;
}

u16 ADC_ReadChannel(u8 channel)
{
    ADC_StartConversion(channel);

    while (!ADC_IsConversionDone());

    return ADC_ReadValue();
}

void ADC_SetCallback(void (*Callback)(u16))
{
    ADC_Callback = Callback;
}

void ADC_ISR(void)
{
    u16 ADC_Value;

    CLR_BIT(PIR1, ADIF);
    ADC_Value = ADC_ReadValue();

    if (ADC_Callback != NULL_PTR)
        ADC_Callback(ADC_Value);
}
