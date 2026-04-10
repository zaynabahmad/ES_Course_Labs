// Purpose: Tests ADC by reading potentiometer
// Connect potentiometer wiper to RA0/AN0

#include "adc.h"
#include "gpio.h"

void ADC_Test(void) {
    uint16 adc_value;
    float voltage;

    ADC_Init();

    // Setup LED on RB0 for visual feedback
    GPIO_SetPinDirection(PORTB_ID, PIN0, OUTPUT);

    while(1) {
        // Read potentiometer on channel 0
        adc_value = ADC_Read(ADC_CHANNEL_0);
        voltage = ADC_ReadVoltage(ADC_CHANNEL_0);

        // Blink LED faster when voltage is higher
        GPIO_WritePin(PORTB_ID, PIN0, HIGH);
        __delay_ms(adc_value / 10);  // Delay based on pot position
        GPIO_WritePin(PORTB_ID, PIN0, LOW);
        __delay_ms(adc_value / 10);
    }
}