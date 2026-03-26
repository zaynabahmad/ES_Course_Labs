#include "LM35.h"

f32 H_LM35_f32ReadTemp(u8 copy_u8ADCChannel) {
    /* Updated to include the 'M_' prefix to match your MCAL driver */
    u16 local_u16ADCValue = M_ADC_u16ReadChannel(copy_u8ADCChannel);
    
    /* * Conversion Math:
     * ADC_Value * (5000mV / 1024 steps) / (10mV / 1 degree)
     * = ADC_Value * 0.48828125
     */
    f32 local_f32Temp = (f32)(local_u16ADCValue * 0.48828125);
    
    return local_f32Temp;
}