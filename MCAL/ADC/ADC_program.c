#include "ADC_interface.h"
#include "ADC_private.h"
#include "../../SERVICES/BIT_MATH.h"

void ADC_Init(void)
{
    /*
     * ADCON1:
     *   ADFM = 1  → right-justified result
     *   PCFG = 0000 → all pins analog, Vref = VDD/VSS
     */

    SET_BIT(ADCON1, ADCON1_ADFM); /* Right-justify */
    ADCON1 = 0x8E;

    /*
     * ADCON0:
     *   ADCS = 10 → Fosc/32 (safe for 4 MHz)
     *   ADON = 1  → Enable ADC
     */
    CLR_BIT(ADCON0, ADCON0_ADCS0);
    SET_BIT(ADCON0, ADCON0_ADCS1);
    SET_BIT(ADCON0, ADCON0_ADON);
}
u16 ADC_Read(u8 channel)
{
    /* --- ALL DECLARATIONS MUST GO HERE AT THE TOP --- */
    volatile u8 i;
    u16 result;

    /* 1 – Select channel (bits CHS2:CHS0) */
    if (channel & 0x01)
        SET_BIT(ADCON0, ADCON0_CHS0);
    else
        CLR_BIT(ADCON0, ADCON0_CHS0);

    if (channel & 0x02)
        SET_BIT(ADCON0, ADCON0_CHS1);
    else
        CLR_BIT(ADCON0, ADCON0_CHS1);

    if (channel & 0x04)
        SET_BIT(ADCON0, ADCON0_CHS2);
    else
        CLR_BIT(ADCON0, ADCON0_CHS2);

    /* 2 – Small acquisition delay (~20 µs @ 4 MHz) */
    // Now you just use 'i' without declaring it here
    for (i = 0; i < 20; i++)
        ;

    /* 3 – Start conversion */
    SET_BIT(ADCON0, ADCON0_GO_DONE);

    /* 4 – Wait for conversion to complete */
    while (GET_BIT(ADCON0, ADCON0_GO_DONE))
        ;

    /* 5 – Read 10-bit result (right-justified) */
    // Assign to 'result' instead of declaring it here
    result = ((u16)ADRESH << 8) | ADRESL;

    return result;
}