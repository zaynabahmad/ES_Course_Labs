#include "SENSOR_interface.h"
#include "SENSOR_config.h"
#include "../../MCAL/ADC/ADC_interface.h"

void SENSOR_Init(u8 Channel)
{
    (void)Channel;  /* Channel is passed at read time; ADC_Init handles global setup */
    ADC_Init();
}

u16 SENSOR_Read(u8 Channel)
{
    return ADC_Read(Channel);
}
