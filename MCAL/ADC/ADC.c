#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_interface.h"
#include "../../SERVICES/BIT_MATH.h"

void ADC_Init(void)
{
    /* Configure port pins: ADCON1 PCFG<3:0> */
    ADCON1 = ADC_PCFG & 0x0F;

    /* Result format: right-justified */
#if ADC_RESULT_RIGHT_JUSTIFIED
    SET_BIT(ADCON1, ADFM_BIT);
#else
    CLR_BIT(ADCON1, ADFM_BIT);
#endif

    /* ADC clock: ADCS2 in ADCON1, ADCS1:ADCS0 in ADCON0 */
#if ADC_ADCS2
    SET_BIT(ADCON1, ADCS2_BIT);
#else
    CLR_BIT(ADCON1, ADCS2_BIT);
#endif

#if ADC_ADCS1
    SET_BIT(ADCON0, ADCS1_BIT);
#else
    CLR_BIT(ADCON0, ADCS1_BIT);
#endif

#if ADC_ADCS0
    SET_BIT(ADCON0, ADCS0_BIT);
#else
    CLR_BIT(ADCON0, ADCS0_BIT);
#endif

    /* Turn on ADC module */
    SET_BIT(ADCON0, ADON_BIT);
}

u16 ADC_Read(u8 Channel)
{
    u16 result;

    /* Select channel: CHS<2:0> in ADCON0 bits 5:3 */
    ADCON0 = (ADCON0 & 0xC7) | ((Channel & 0x07) << 3);

    /* Acquisition delay: minimum 20 µs @ Fosc=4 MHz = 20 instruction cycles */
    /* Counted loop: each iteration ~4 cycles → 5 iterations ≈ 20 cycles     */
    {
        volatile u8 i;
        for (i = 0; i < 5; i++) {}
    }

    /* Start conversion */
    SET_BIT(ADCON0, GO_DONE_BIT);

    /* Wait for conversion complete */
    while (GET_BIT(ADCON0, GO_DONE_BIT)) {}

    /* Combine 10-bit result (right-justified) */
    result = (u16)((u16)(ADRESH & 0x03) << 8) | (u16)ADRESL;

    return result;
}
