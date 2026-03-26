#include "../../SERVICES/Bit_Math.h"
#include "ADC.h"

/* Register Definitions (Private to ADC.c) */
#define ADCON0    *((volatile u8*)0x1F)  // Bank 0
#define ADRESH    *((volatile u8*)0x1E)  // Bank 0
#define ADCON1    *((volatile u8*)0x9F)  // Bank 1
#define ADRESL    *((volatile u8*)0x9E)  // Bank 1

void M_ADC_voidInit(void) {
    /* ADCON1: Right Justified, RA0 as Analog (Matches RA0/AN0 in schematic) */
    ADCON1 = 0x80; 

    /* ADCON0: Fosc/32, ADC On */
    ADCON0 = 0x81; 
}

u16 M_ADC_u16ReadChannel(u8 copy_u8Channel) {
    /* 1. Clear channel bits (3,4,5) and set the requested channel */
    ADCON0 &= 0xC7;
    ADCON0 |= (copy_u8Channel << 3);
    
    /* 2. Acquisition delay (Wait for internal capacitor to charge) */
    Delay_us(25);
    
    /* 3. Start Conversion (Set GO bit) */
    SET_BIT(ADCON0, 2);
    
    /* 4. Wait for conversion to finish (GO bit becomes 0) */
    while(GET_BIT(ADCON0, 2) == 1);
    
    /* 5. Return the 10-bit result from ADRESH and ADRESL */
    return (u16)((ADRESH << 8) | ADRESL);
}