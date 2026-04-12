#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "../../SERVICES/BIT_MATH.h"

void ADC_Init(void)
{
    /* Set ADCON1: Right justified, all analog channels */
    ADCON1 = 0x80;   /* ADFM=1 (right justify), PCFG=0000 (all analog) */

    /* Set ADC clock: Fosc/8 -> ADCS1:ADCS0 = 01 in ADCON0 */
    ADCON0 = (ADC_CLOCK_SELECT << 6);

    /* Turn on ADC module: bit0 of ADCON0 = 1 */
    SET_BIT(ADCON0, 0);

    /* Set PORTA as input for analog channels */
    TRISA = 0xFF;
}

u16 ADC_Read(u8 Channel)
{
    u16 Local_Result = 0;

    /* Select channel: bits 5:3 of ADCON0 */
    ADCON0 &= 0xC7;                    /* Clear channel bits */
    ADCON0 |= (Channel << 3);          /* Set new channel */

    /* Start conversion: set GO/DONE bit (bit1) */
    SET_BIT(ADCON0, 1);

    /* Wait for conversion to finish */
    while(GET_BIT(ADCON0, 1));

    /* Read result: right justified (10-bit) */
    Local_Result = (u16)ADRESH << 8;
    Local_Result |= ADRESL;

    return Local_Result;
}