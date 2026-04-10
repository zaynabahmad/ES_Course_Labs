#include "ADC_interface.h"
#include "ADC_private.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

void ADC_Init(void) 
{
    /* ADCON1: Right Justified, Fosc/32, RA0/AN0 Analog, others Digital [cite: 174, 179] */
    ADCON1 = 0x8E; 

    /* ADCON0: Fosc/32 clock, ADC Module On [cite: 139, 167, 190] */
    ADCON0 = 0x81; 
}

uint16 ADC_ReadChannel(uint8 Channel) 
{
    uint16 result = 0;
    
    /* 1. Select A/D input channel [cite: 142, 188] */
    ADCON0 &= 0xC7;               /* Clear CHS2:CHS0 (bits 5-3) */
    ADCON0 |= (Channel << 3);     /* Set channel [cite: 142] */

    /* 2. Wait required acquisition time [cite: 196, 211, 350] */
    Delay_us(50); 

    /* 3. Start conversion: Set GO/DONE bit [cite: 160, 199, 356] */
    SET_BIT(ADCON0, 2); 

    /* 4. Wait for A/D conversion to complete [cite: 161, 201, 358] */
    while (GET_BIT(ADCON0, 2) == 1);

    /* 5. Read result: Combine ADRESH and ADRESL [cite: 205, 360-363] */
    /* Right Justified result format [cite: 174, 228] */
    result = ((uint16)ADRESH << 8) | ADRESL;
    return result;
}