#include "ADC_interface.h"
#include "ADC_private.h"
static void (*ADC_ConversionComplete_Callback)(void) = 0;
void ADC_voidInit(void) {
    /* 1. ADCON1 Configuration:
       - Bit 7: ADFM = 1 (Right Justified for 10-bit)
       - Bits 3-0: PCFG = 0000 (All Pins Analog, Vref+ = VDD, Vref- = VSS) */
    ADCON1 = 0x80; 

    /* 2. ADCON0 Configuration:
       - Bits 7-6: ADCS1:ADCS0 = 01 (Fosc/8)
       - Bit 0: ADON = 1 (Turn ADC On) */
    ADCON0 = 0x41; 
}

void ADC_voidSelectChannel(u8 copy_u8Channel) {
    if (copy_u8Channel <= 7) {
        /* Clear channel bits (5,4,3) then set new channel */
        ADCON0 &= 0xC7;
        ADCON0 |= (copy_u8Channel << 3);
    }
}

u16 ADC_u16Read(u8 copy_u8Channel) {
    /* 1. Select the channel */
    ADC_voidSelectChannel(copy_u8Channel);
    
    /* 2. Acquisition Delay (Tacq)
       Required for the internal capacitor to charge (~20us) */
    delay_ms(100); 
    
    /* 3. Start Conversion */
    SET_BIT(ADCON0, GO_DONE_BIT);
    
    /* 4. Polling: Wait for GO/DONE bit to be cleared by hardware */
    while (GET_BIT(ADCON0, GO_DONE_BIT)); 
    
    /* 5. Return the 10-bit result */
    return ADC_u16GetConversionResult();
}

u16 ADC_u16GetConversionResult(void) {
    u16 local_u16Result = 0;
    /* Combine ADRESH and ADRESL for Right Justified result */
    local_u16Result = (ADRESH << 8) | ADRESL;
    return local_u16Result;
}

void ADC_voidStartConversion(void) {
    /* Used for Interrupt-based conversion */
    SET_BIT(ADCON0, GO_DONE_BIT);
}

void ADC_voidEnableInterrupt(void) {
    CLR_BIT(PIR1, ADIF_BIT);   // Clear Flag
    SET_BIT(PIE1, ADIE_BIT);   // Enable ADC Interrupt
    SET_BIT(INTCON, PEIE_BIT); // Peripheral Interrupt Enable
    SET_BIT(INTCON, GIE_BIT);  // Global Interrupt Enable
}

