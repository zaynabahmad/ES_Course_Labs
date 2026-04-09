#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "../../SERVICES/BIT_MATH.h"

/* mikroC built-in delay function */
#include <built_in.h>

void ADC_Init(void)
{
    /* 1. Configure Port Settings (Analog/Digital/Vref) */
    ADCON1 = (ADC_PORT_CONFIG & 0x0F);

    /* 2. Configure Result Format */
    #if ADC_RESULT_FORMAT == ADC_RIGHT_JUSTIFIED
        SET_BIT(ADCON1, ADFM_BIT);
    #else
        CLR_BIT(ADCON1, ADFM_BIT);
    #endif

    /* 3. Configure Clock Source */
    ADCON0 = (ADC_CLOCK_SOURCE << ADCS0_BIT);

    /* 4. Turn on the ADC module */
    SET_BIT(ADCON0, ADON_BIT);
}

u16 ADC_Read(u8 channel)
{
    u16 result = 0;

    /* 1. Select the ADC channel */
    /* Clear the channel selection bits first */
    ADCON0 &= 0xC7; /* 11000111 */
    /* Set the new channel */
    ADCON0 |= (channel << CHS0_BIT);

    /* 2. Wait for the required acquisition time (Tacq) */
    /* A small delay is required for the holding capacitor to charge.
       This value (e.g., 20us) depends on the source impedance. 
       See datasheet page 130 for details. */
    Delay_us(20);

    /* 3. Start the conversion */
    SET_BIT(ADCON0, GO_DONE_BIT);

    /* 4. Wait for the conversion to complete (polling the GO/DONE bit) */
    while(GET_BIT(ADCON0, GO_DONE_BIT) == 1);

    /* 5. Read the result */
    #if ADC_RESULT_FORMAT == ADC_RIGHT_JUSTIFIED
        result = (ADRESH << 8) | ADRESL;
    #else
        result = (ADRESH << 8) | ADRESL; 
        /* For left justified, the full 10 bits are still in these two registers,
           but shifted. The user might want to shift them back.
           result = ((ADRESH << 8) | ADRESL) >> 6; */
    #endif

    return result;
}