#ifndef SENSOR_INTERFACE_H
#define SENSOR_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/*
 * Generic analog sensor driver — wraps ADC_Read.
 * Returns a raw 10-bit value (0–1023).
 */

void SENSOR_Init(u8 Channel);
u16  SENSOR_Read(u8 Channel);

#endif
