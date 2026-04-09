#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "ADC_interface.h"
#include "ADC_private.h"

void ADC_voidInit(void) {

    ADCON1 = 0x8E;

    ADCON0 = 0x81;
}

u16 ADC_u16ReadChannel(u8 Copy_u8Channel) {
    u16 Local_u16Result = 0;
    u16 Local_u16Delay = 0;

   
    ADCON0 &= 0xC7;
    ADCON0 |= (Copy_u8Channel << 3);

    /* Acquisition delay (approx 20us) */
    for (Local_u16Delay = 0; Local_u16Delay < 50; Local_u16Delay++);

    /* Start Conversion: Set GO/DONE bit (Bit 2) */
    SET_BIT(ADCON0, 2);

    /* Wait for conversion to complete */
    while (GET_BIT(ADCON0, 2) == 1);

    /* Read Result (Right Justified) */
    Local_u16Result = ADRESL;
    Local_u16Result |= (ADRESH << 8);

    return Local_u16Result;
}