#include "ADC_Interface.h"

/* =========================================================
   ADC_Init
   - Configures justification
   - Sets port configuration (analog vs digital pins)
   - Enables the ADC module
   - Uses Fosc/8 as default clock (can be tuned for your Fosc)
========================================================= */
void ADC_Init(void)
{
    /* Set Justification */
#if ADC_JUSTIFICATION == ADC_RIGHT_JUSTIFIED
    SET_BIT(ADCON1, ADFM_BIT);
#else
    CLR_BIT(ADCON1, ADFM_BIT);
#endif

    /* Configure analog pins and Vref */
    ADCON1 = (ADCON1 & 0xF0) | (ADC_PORT_CONFIG & 0x0F);

    /* Select Clock = Fosc/8 (ADCS = 01 in ADCON0, ADCS2 = 0 in ADCON1) */
    CLR_BIT(ADCON1, ADCS2_BIT);
    CLR_BIT(ADCON0, ADCS1_BIT);
    SET_BIT(ADCON0, ADCS0_BIT);

    /* Turn ON the ADC module */
    SET_BIT(ADCON0, ADON_BIT);
}

/* =========================================================
   ADC_ReadChannel
   - Selects the desired channel
   - Starts conversion
   - Waits for conversion to complete (polling)
   - Returns 10-bit result
========================================================= */
u16 ADC_ReadChannel(u8 Channel)
{
    if(Channel > ADC_CHANNEL_7) return 0;

    /* Clear channel bits and set the new channel */
    ADCON0 &= 0xC7;                   /* Clear CHS0, CHS1, CHS2 */
    ADCON0 |= (Channel << 3);         /* Shift channel number into CHS positions */

    /* Small delay for acquisition time (capacitor charge) */
    /* An actual delay utility is recommended here, but a dummy loop suffices for fast clocks */
    volatile u8 delay = 20; 
    while(delay--);

    /* Start conversion */
    SET_BIT(ADCON0, GO_DONE_BIT);

    /* Wait for conversion to finish (GO_DONE bit clears automatically) */
    while(GET_BIT(ADCON0, GO_DONE_BIT));

    /* Read result (assuming Right Justification) */
    return ((u16)(ADRESH << 8) | ADRESL);
}