#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "../../SERVICES/BIT_MATH.h"

void ADC_Init(void)
{
    // 1. Configure Port pins (Analog vs Digital) and Voltage Reference
    ADCON1 = (ADCON1 & 0xF0) | (ADC_PORT_CONFIG & 0x0F);

    // 2. Configure Result Format (Right Justified)
    #if ADC_RESULT_FORMAT == 1
        SET_BIT(ADCON1, ADFM);
    #else
        CLR_BIT(ADCON1, ADFM);
    #endif

    // 3. Configure Clock (Fosc/32)
    // Clear bits 6 and 7, then apply clock config
    ADCON0 = (ADCON0 & 0x3F) | ((ADC_CLOCK_SELECT & 0x03) << 6);

    // 4. Turn on the ADC Module
    SET_BIT(ADCON0, ADON);
}

u16 ADC_ReadChannel(u8 Channel)
{
    unsigned int delay;
    u16 digital_result = 0;

    // Clear current channel selection (Bits 3, 4, 5)
    ADCON0 &= 0xC7; // 0xC7 is 11000111 in binary
    
    // Set the new channel
    ADCON0 |= (Channel << 3);

    // Acquisition Time Delay 
    for(delay = 0; delay < 100; delay++);

    // Start Conversion
    SET_BIT(ADCON0, GO_DONE);

    // Wait for conversion to finish (Polling)
    // The hardware will clear the GO_DONE bit automatically when finished.
    while(GET_BIT(ADCON0, GO_DONE) == 1);

    //  Read the 10-bit result
    // ADRESH contains the top 2 bits, ADRESL contains the bottom 8 bits.
    digital_result = (ADRESH << 8) | ADRESL;

    return digital_result;
}