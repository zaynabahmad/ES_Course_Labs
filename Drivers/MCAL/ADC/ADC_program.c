#include "../../SERCICES/BIT_MATH.h"
#include "../../MCAL/ADC/ADC_private.h"
#include "../../MCAL/ADC/ADC_interface.h"
#include "../../MCAL/ADC/ADC_config.h"


void ADC_voidInit(void) {
    // RA0 as analog input
    GPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_INPUT);
    
    // Right justified, Fosc/8, AN0+ Vdd/Vss-
    ADCON1 = 0x80;
    ADCON0 = 0x41;  // Channel 0, ADC ON
}

uint16 ADC_u16ReadChannel(uint8 Copy_Channel) {
    ADCON0 &= 0xC5;           // Clear channel bits
    ADCON0 |= (Copy_Channel << 2);  // Set channel
    Delay_us(20);             // Acquisition time
    SET_BIT(ADCON0, 0);       // Start conversion
    while(GET_BIT(ADCON0, 2) == 0);  // Wait conversion
    CLEAR_BIT(ADCON0, 0);     // Clear GO bit
    return ((uint16)ADRESH << 8) | ADRESL;
}