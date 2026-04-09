#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


void ADC_Init(void) {
    /* 0. MAKE SURE PINS ARE INPUTS! */
    /* Set RA0 (Bit 0) as an input */
    TRISA |= 0x01;

    /* 1. Configure ADCON1 */
    if (ADC_RESULT_FORMAT == 1) {
        SET_BIT(ADCON1, ADCON1_ADFM);
    } else {
        CLR_BIT(ADCON1, ADCON1_ADFM);
    }
    ADCON1 &= 0xF0;

    /* 2. Configure ADCON0 */
    ADCON0 = (ADC_CLOCK_SELECT << 6);
    SET_BIT(ADCON0, ADCON0_ADON);
}


u16 ADC_GetChannelValue(u8 Copy_u8Channel) {
    u16 Local_u16Result = 0;

    /* 1. Select the Channel */
    // Clear previous channel bits (bits 5, 4, 3)
    ADCON0 &= 0xC7;
    // Set the new channel
    ADCON0 |= (Copy_u8Channel << 3);

    /* 2. Acquisition Delay */
    // The ADC capacitor needs a moment to charge up to the input voltage.
    // For 8MHz, a few microseconds is enough.
    delay_us(30);

    /* 3. Start Conversion */
    SET_BIT(ADCON0, ADCON0_GO_DONE);

    /* 4. Wait for Completion */
    // The GO_DONE bit stays 1 while converting, and hardware clears it to 0 when finished.
    while (GET_BIT(ADCON0, ADCON0_GO_DONE) == 1);

    /* 5. Read Result */
if (ADC_RESULT_FORMAT == 1) {
        // Cast to u16 FIRST, then shift!
        Local_u16Result = ((u16)ADRESH << 8) | ADRESL;
    } else {
        Local_u16Result = ((u16)ADRESH << 2) | (ADRESL >> 6);
    }

    return Local_u16Result;
}