#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_private.h"
#include "ADC_interface.h"

void ADC_voidInit(void)
{
    // Turn ON ADC
    SET_BIT(ADCON0,0);

    // Select Fosc/8
    SET_BIT(ADCON0,6);

    // Configure AN0 as analog
    ADCON1 = 0x80;
}

unsigned int ADC_u16Read(unsigned char channel)
{
    unsigned int result;

    // Clear channel bits
    ADCON0 &= 0b11000111;

    // Select channel
    ADCON0 |= (channel << 3);

    // Start conversion
    SET_BIT(ADCON0,2);

    // Wait until done
    while(GET_BIT(ADCON0,2));

    // Read result
    result = (ADRESH << 8) | ADRESL;

    return result;
}