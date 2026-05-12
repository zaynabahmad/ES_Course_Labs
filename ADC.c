#include "ADC_INTERFACE.h"
#include "ADC_PRIVATE.h"
#include "ADC_CONFIG.h"
#include "../SERVICES/BIT_MATH.h"

void ADC_Init(void)
{
    /* Set result justification */
#if ADC_RESULT_FORMAT == ADC_RIGHT_JUSTIFIED
    SET_BIT(ADCON1, ADFM);
#else
    CLR_BIT(ADCON1, ADFM);
#endif

    /* Configure analog/digital pins (PCFG3:PCFG0) */
    ADCON1 = (ADCON1 & 0xF0) | (ADC_PCFG_VALUE & 0x0F);

    /* Set conversion clock (ADCS1:ADCS0) */
    ADCON0 = (ADCON0 & 0x3F) | ((ADC_CLOCK_SELECT & 0x03) << 6);

    /* Enable ADC module */
    SET_BIT(ADCON0, ADON);
}

u16 ADC_Read(u8 channel)
{
    volatile u8 acq_delay;
    u16 result;

    /* Select analog channel (CHS2:CHS0) */
    ADCON0 = (ADCON0 & 0xC7) | ((channel & 0x07) << 3);

    /* Acquisition delay: ~20 us at 4 MHz */
    for(acq_delay = 0; acq_delay < 20u; acq_delay++);

    /* Start conversion */
    SET_BIT(ADCON0, GO_DONE);

    /* Wait for conversion to complete */
    while(GET_BIT(ADCON0, GO_DONE) == 1);

    /* Assemble 10-bit result (right-justified: ADRESH[1:0] | ADRESL[7:0]) */
#if ADC_RESULT_FORMAT == ADC_RIGHT_JUSTIFIED
    result = ((u16)(ADRESH & 0x03) << 8) | (u16)ADRESL;
#else
    result = (u16)ADRESH;
#endif

    return result;
}
