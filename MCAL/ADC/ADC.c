#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"

void ADC_Init(void)
{
    TRISA_REG = 0xFF;  /* Set ALL PortA pins as input to be safe */
    ADCON1_REG = 0x80; /* All analog, Vref+ = VDD, Vref- = VSS */
    
    /* Turn ADC ON, Fosc/8, Channel 0 */
    ADCON0_REG = 0x81; 
    Delay_ms(ADC_CONVERSION_DELAY_MS);
}

u16 ADC_Read(u8 channel)
{
    /* 1. Select the channel */
    ADCON0_REG &= ~ADC_CHANNEL_MASK;
    ADCON0_REG |= (channel << 3);

    /* 2. CRITICAL: Wait for Acquisition Time */
    /* Increased delay to ensure the holding capacitor is charged */
    Delay_ms(20); 

    /* 3. Start conversion */
    ADCON0_REG |= (1 << 2); 
    
    /* 4. Wait for completion */
    while (ADCON0_REG & (1 << 2));

    return ((u16)ADRESH_REG << 8) | ADRESL_REG;
}
u16 ADC_Read_mV(u8 channel)
{
    /* Using standard 'unsigned long' since 'u32' isn't in STD_TYPES.h yet */
    unsigned long voltage;
    u16 raw = ADC_Read(channel);
    
    /* Convert raw ADC reading to millivolts using config constants */
    voltage = (unsigned long)raw * ADC_REF_MV;
    voltage = voltage / ADC_MAX_VALUE;
    
    return (u16)voltage;
}

u16 ADC_ReadTemperatureC(u8 channel)
{
    return ADC_Read_mV(channel) / 10U;
}