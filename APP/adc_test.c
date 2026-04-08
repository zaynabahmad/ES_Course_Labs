#include "../MCAL/ADC/ADC_interface.h"

void ADC_Test(void)
{
    u16 Local_Result = 0;

    /* Initialize ADC */
    ADC_Init();

    /* Read from channel 0 */
    Local_Result = ADC_Read(ADC_CH0);
}