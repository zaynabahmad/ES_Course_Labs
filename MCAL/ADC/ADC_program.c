#include "../../SERVICES/std_types.h"
#include "../../SERVICES/bit_math.h"
#include "ADC_interface.h"
#include "ADC_private.h"

void ADC_voidInit(void) {
    /* ADCON1: Right Justified, Fosc/32, All channels Analog */
    ADCON1_REG = 0b10000000;
    /* ADCON0: ADC On */
    SET_BIT(ADCON0_REG, ADON_BIT);
}

u16 ADC_u16ReadChannel(u8 Copy_u8Channel) {
    /* Select Channel (Bits 5,4,3) */
    ADCON0_REG &= 0b11000111;
    ADCON0_REG |= (Copy_u8Channel << 3);

    /* Start Conversion */
    SET_BIT(ADCON0_REG, GO_DONE_BIT);

    /* Wait for completion */
    while(GET_BIT(ADCON0_REG, GO_DONE_BIT) == 1);

    return ((u16)ADRESH_REG << 8) | ADRESL_REG;
}