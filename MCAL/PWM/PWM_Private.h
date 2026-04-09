#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"


#define CCP1_DATA_LOW_REG   (*(volatile u8*)0x15)
#define CCP1_CON_REG        (*(volatile u8*)0x17)
#define TMR2_CON_REG        (*(volatile u8*)0x12)
#define PIR1_REG            (*(volatile u8*)0x0C)


#define TMR2_PERIOD_REG     (*(volatile u8*)0x92)
#define TRISC_REG           (*(volatile u8*)0x87)
#define CCP1_MODE_PWM       0x0C
#define CCP1_MODE_MASK      0x0F
#define CCP1_DUTY_L_MASK    0x30

#define TMR2_ON_BIT         2
#define TMR2_PRE_MASK       0x03


#define TMR2_PRE_1          0x00
#define TMR2_PRE_4          0x01
#define TMR2_PRE_16         0x02

#endif /* PWM_PRIVATE_H */