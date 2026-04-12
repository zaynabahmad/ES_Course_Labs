#include "../MCAL/ADC/ADC_interface.h"

void ADC_Test(void)
{
    /* Initialize ADC */
    ADC_Init();

    /* Read from channel 0 - result used via volatile read */
    (void)ADC_Read(ADC_CH0);
}