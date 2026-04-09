#ifndef LM35_INTERFACE_H
#define LM35_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Error Codes */
#define LM35_OK       0
#define LM35_ERROR    1


u8 LM35_u8GetTempFloat(u8 Copy_u8ADCChannel, float* Add_pf32Temperature);

#endif /* LM35_INTERFACE_H */