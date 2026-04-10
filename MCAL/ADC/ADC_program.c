#include "../../SERVICES/std_types.h"
#include "../../SERVICES/bit_math.h"
#include "ADC_private.h"
#include "ADC_interface.h"

void ADC_voidInit(void) {
    /* ADCON1 configuration:
       Bit 7: Right Justified (1)
       Bits 3-0: All pins as Analog, Vref+ = VDD, Vref- = VSS (0000) */
    ADCON1_REG = 0x80;

    /* ADCON0 configuration:
       Bits 7-6: ADC Clock = Fosc/32 (10)
       Bit 0: ADC On (1) */
    ADCON0_REG = 0x81;
}

u16 ADC_u16ReadChannel(u8 copy_u8Channel) {
    /*Clear Channel Selection Bits (Bits 5-3) */
    ADCON0_REG &= 0xC7;

    /* Set the requested Channel */
    ADCON0_REG |= (copy_u8Channel << 3);

    /* Wait for Acquisition time (Short delay) */
    Delay_us(20);

    /* Start Conversion (Set GO/DONE bit) */
    SET_BIT(ADCON0_REG, 2);

    /* Wait for Conversion to complete (Bit 2 becomes 0) */
    while(GET_BIT(ADCON0_REG, 2) == 1);

    /* Return Result (Combining ADRESH and ADRESL for Right Justified) */
    return (u16)((ADRESH_REG << 8) | ADRESL_REG);
}