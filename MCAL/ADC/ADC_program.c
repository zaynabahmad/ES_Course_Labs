#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\STD_TYPES.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\BIT_MATH.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\ADC\ADC_private.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\ADC\ADC_interface.h"

/* ---------------------------------------------------------- */
void ADC_voidInit(void)
{
    ADCON1 = ADC_ADCON1_CONFIG;

    ADCON0 = 0x00;

    ADCON0 |= (unsigned char)(ADC_CLK_FOSC_8 << ADC_ADCS_SHIFT);

    SET_BIT(ADCON0, ADC_ADON_BIT);
}

/* ---------------------------------------------------------- */
unsigned int ADC_u16Read(unsigned char channel)
{
    unsigned int result;
    unsigned char delay_cnt;

    /* Validate channel number before touching any register */
    if (channel > ADC_MAX_CHANNEL)
    {
        return ADC_INVALID_CHANNEL;
    }

    ADCON0 &= ADC_CHANNEL_MASK;
    ADCON0 |= (unsigned char)(channel << ADC_CHS_SHIFT);

    for (delay_cnt = 0; delay_cnt < ADC_ACQ_DELAY_COUNT; delay_cnt++)
    {

    }


    SET_BIT(ADCON0, ADC_GO_DONE_BIT);


    while (GET_BIT(ADCON0, ADC_GO_DONE_BIT))
    {
        /* wait */
    }


    result = (unsigned int)(((unsigned int)(ADRESH & 0x03u) << 8u)
                            | (unsigned int)ADRESL);

    return result;
}

/* ---------------------------------------------------------- */
float ADC_f32ToVoltage(unsigned int raw_value)
{
    /* Resolution = Vref / 2^10 = 5000 mV / 1024 = 4.8828 mV per step */
    return (float)raw_value * 4.8828f;
}