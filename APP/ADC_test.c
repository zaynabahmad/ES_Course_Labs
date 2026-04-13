#include "../MCAL/ADC/ADC_interface.h"

void ADC_Test(void)
{
    u16 ADC_Value;

    /* Test 1: Initialize ADC with 10-bit resolution and VSS/VDD reference */
    ADC_Init(ADC_10BIT_RESOLUTION, ADC_REF_VSS_VDD);

    /* Test 2: Start conversion on ADC Channel 0 (blocking) */
    ADC_Value = ADC_ReadChannel(ADC_CHANNEL0);

    /* Test 3: Start conversion on ADC Channel 1 */
    ADC_StartConversion(ADC_CHANNEL1);

    /* Test 4: Check if conversion is done */
    while (!ADC_IsConversionDone());

    /* Test 5: Read ADC value after conversion completes */
    ADC_Value = ADC_ReadValue();

    /* Test 6: Set interrupt callback */
    ADC_SetCallback(NULL_PTR);

    /* Test 7: Start conversion with interrupt enabled */
    ADC_StartConversion(ADC_CHANNEL3);

    /* Test 8: Read multiple channels sequentially */
    ADC_Value = ADC_ReadChannel(ADC_CHANNEL4);
    ADC_Value = ADC_ReadChannel(ADC_CHANNEL5);
}
