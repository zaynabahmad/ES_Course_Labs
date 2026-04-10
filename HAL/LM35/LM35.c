#include "../../SERVICES/STD_TYPES.h"

/* Include the MCAL ADC driver so the HAL can use it */
#include "../../MCAL/ADC/ADC_interface.h"

#include "LM35_config.h"
#include "LM35_interface.h"

u8 LM35_u8GetTempFloat(u8 Copy_u8ADCChannel, float* Add_pf32Temperature)
{
    u16 Local_u16ADCResult = 0;
    u8 Local_u8ErrorState = LM35_ERROR;

    /* Safety Check: Make sure the pointer is not NULL */
    if (Add_pf32Temperature != 0)
    {
        /* 1. Ask the MCAL ADC driver to read the raw voltage steps */
        if (ADC_u8ReadChannel(Copy_u8ADCChannel, &Local_u16ADCResult) == ADC_OK)
        {
            /* 2. Calculate the step size based on config file: (5000 / 1024) = 4.8828 mV */
            float Local_f32StepSize = LM35_VREF_MV / LM35_ADC_MAX_STEPS;
            
            /* 3. Convert raw ADC value to milliVolts */
            float Local_f32MilliVolts = (float)Local_u16ADCResult * Local_f32StepSize;
            
            /* 4. Convert milliVolts to Celsius (10mV = 1 Degree) */
            *Add_pf32Temperature = Local_f32MilliVolts / LM35_MV_PER_CELSIUS;
            
            Local_u8ErrorState = LM35_OK;
        }
    }

    return Local_u8ErrorState;
}