// Purpose: Reads analog voltage (0-5V) and converts to number (0-1023)
// Used for potentiometers, temperature sensors, light sensors

#include "adc.h"

void ADC_Init(void) {
    // Setup ADC
    ADCON0 = 0x41;  // ADC on, Fosc/8, channel 0
    ADCON1 = 0x80;  // Right justified, Vref = VDD/VSS (5V/0V)

    // Set all pins as analog (for PIC16F877A)
    ADCON1bits.PCFG = 0b0000;
}

uint16 ADC_Read(ADC_Channel channel) {
    // Select which pin to read
    ADCON0bits.CHS = channel;

    // Wait for capacitor to charge
    __delay_us(20);

    // Start conversion
    ADCON0bits.GO = 1;

    // Wait for conversion to finish
    while(ADCON0bits.GO);

    // Return 10-bit result (0-1023)
    return (ADRESH << 8) | ADRESL;
}

float ADC_ReadVoltage(ADC_Channel channel) {
    uint16 adc_value = ADC_Read(channel);
    // Convert to voltage: (value / 1023) * 5V
    return (adc_value * 5.0) / 1023.0;
}