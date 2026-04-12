#include "ADC_Interface.h"

/* ================= Initialization ================= */

void ADC_Init(void)
{
    /* Configure result justification */
#if ADC_RESULT_FORMAT == ADC_RIGHT_JUSTIFIED
    SET_BIT(ADCON1, ADFM);
#else
    CLR_BIT(ADCON1, ADFM);
#endif

    /* Configure analog/digital pin mapping */
    ADCON1 &= 0xF0;
    ADCON1 |= (ADC_ANALOG_CONFIG & 0x0F);

    /* Set clock source in ADCON0 */
    ADCON0 &= 0x3F;

#if   ADC_CLOCK_SOURCE == ADC_CLOCK_FOSC_2
    CLR_BIT(ADCON0, ADCS1);
    CLR_BIT(ADCON0, ADCS0);
#elif ADC_CLOCK_SOURCE == ADC_CLOCK_FOSC_8
    CLR_BIT(ADCON0, ADCS1);
    SET_BIT(ADCON0, ADCS0);
#elif ADC_CLOCK_SOURCE == ADC_CLOCK_FOSC_32
    SET_BIT(ADCON0, ADCS1);
    CLR_BIT(ADCON0, ADCS0);
#elif ADC_CLOCK_SOURCE == ADC_CLOCK_FRC
    SET_BIT(ADCON0, ADCS1);
    SET_BIT(ADCON0, ADCS0);
#endif

    /* Turn on the ADC module */
    SET_BIT(ADCON0, ADON);
}

/* ================= Read ADC Channel ================= */

u16 ADC_Read(u8 Channel)
{
    u16 Result = 0;

    /* Select channel: clear CHS2:CHS0 then set */
    ADCON0 &= 0xC7;
    ADCON0 |= (u8)((Channel & 0x07) << 3);

    /* Acquisition delay (~20us at 4MHz) */
    {
        volatile u8 delay;
        for(delay = 0; delay < 20; delay++);
    }

    /* Start conversion */
    SET_BIT(ADCON0, GO_DONE);

    /* Wait for conversion to complete */
    while(GET_BIT(ADCON0, GO_DONE));

    /* Read result */
#if ADC_RESULT_FORMAT == ADC_RIGHT_JUSTIFIED
    Result  = (u16)ADRESH << 8;
    Result |= (u16)ADRESL;
#else
    Result  = (u16)ADRESH;
#endif

    return Result;
}
