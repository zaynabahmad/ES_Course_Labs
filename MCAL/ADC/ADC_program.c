#include "ADC_interface.h"
#include "ADC_private.h"
#include "../../SERVICES/BIT_MATH.h"

static u8 ADC_ResultFormat = ADC_RIGHT_JUSTIFIED;

static void ADC_SetChannelPinAsInput(u8 channel)
{
    switch(channel)
    {
        case ADC_CHANNEL_AN0: SET_BIT(TRISA, 0); break;
        case ADC_CHANNEL_AN1: SET_BIT(TRISA, 1); break;
        case ADC_CHANNEL_AN2: SET_BIT(TRISA, 2); break;
        case ADC_CHANNEL_AN3: SET_BIT(TRISA, 3); break;
        case ADC_CHANNEL_AN4: SET_BIT(TRISA, 5); break;
        case ADC_CHANNEL_AN5: SET_BIT(TRISE, 0); break;
        case ADC_CHANNEL_AN6: SET_BIT(TRISE, 1); break;
        case ADC_CHANNEL_AN7: SET_BIT(TRISE, 2); break;
        default: break;
    }
}

void ADC_Step1_Init(u8 channel, u8 clock, u8 port_cfg, u8 result_format)
{
    ADCON1 &= 0xF0;
    ADCON1 |= (port_cfg & 0x0F);


    if(result_format == ADC_RIGHT_JUSTIFIED)
        SET_BIT(ADCON1, ADFM_BIT);
    else
        CLR_BIT(ADCON1, ADFM_BIT);

    ADC_ResultFormat = result_format;


    ADCON0 &= 0xC7;
    ADCON0 |= ((channel & 0x07) << 3);


    ADCON0 &= 0x3F;
    ADCON0 |= ((clock & 0x03) << 6);


    ADC_SetChannelPinAsInput(channel);


    SET_BIT(ADCON0, ADON_BIT);
}

void ADC_Step2_InterruptConfig(u8 interrupt_state)
{
    CLR_BIT(PIR1, ADIF_BIT);

    if(interrupt_state == ADC_INTERRUPT_ENABLE)
    {
        SET_BIT(PIE1, ADIE_BIT);
        SET_BIT(INTCON, PEIE_BIT);
        SET_BIT(INTCON, GIE_BIT);
    }
    else
    {
        CLR_BIT(PIE1, ADIE_BIT);
    }
}

void ADC_Step3_WaitAcquisitionTime_us(u16 time_us)
{
    while(time_us--)
    {
        Delay_us(1);
    }
}

void ADC_Step4_StartConversion(void)
{
    CLR_BIT(PIR1, ADIF_BIT);
    SET_BIT(ADCON0, GO_DONE_BIT);
}

void ADC_Step5_WaitForConversion(void)
{
    while(GET_BIT(ADCON0, GO_DONE_BIT));
}

u16 ADC_Step6_ReadResult(void)
{
    u16 result = 0;

    if(ADC_ResultFormat == ADC_RIGHT_JUSTIFIED)
    {
        result = ((u16)ADRESH << 8) | ADRESL;
    }
    else
    {
        result = ((u16)ADRESH << 2) | (ADRESL >> 6);
    }

    return result;
}

void ADC_Step7_WaitBeforeNextSample_us(u16 time_us)
{
    while(time_us--)
    {
        Delay_us(1);
    }
}

u16 ADC_ReadChannelBlocking(u8 channel, u16 acquisition_time_us)
{

    ADCON0 &= 0xC7;
    ADCON0 |= ((channel & 0x07) << 3);

    ADC_SetChannelPinAsInput(channel);

    ADC_Step3_WaitAcquisitionTime_us(acquisition_time_us);
    ADC_Step4_StartConversion();
    ADC_Step5_WaitForConversion();

    return ADC_Step6_ReadResult();
}