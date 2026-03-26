#include "MOTOR.h"

static u8 DirectionPort, P1, P2;

void H_Motor_voidInit(u8 copy_u8DirPort, u8 copy_u8Pin1, u8 copy_u8Pin2) {
    DirectionPort = copy_u8DirPort;
    P1 = copy_u8Pin1;
    P2 = copy_u8Pin2;
    
    /* Corrected: Matches your GPIO.h */
    GPIO_voidSetPinDirection(DirectionPort, P1, 1); 
    GPIO_voidSetPinDirection(DirectionPort, P2, 1); 
    M_PWM_voidInit();
}

void H_Motor_voidSetSpeed(u8 copy_u8SpeedPercent) {
    u8 local_u8Duty;
    if (copy_u8SpeedPercent > 100) copy_u8SpeedPercent = 100;

    /* Corrected: Matches your GPIO.h */
    GPIO_voidSetPinValue(DirectionPort, P1, 1); 
    GPIO_voidSetPinValue(DirectionPort, P2, 0); 

    /* Mapping to 8-bit PWM (0-255) */
    local_u8Duty = (u8)((u32)copy_u8SpeedPercent * 255 / 100);
    M_PWM_voidSetDutyCycle(local_u8Duty);
}

void H_Motor_voidStop(void) {
    /* Corrected: Removed M_ prefix to match your GPIO driver */
    GPIO_voidSetPinValue(DirectionPort, P1, 0);
    GPIO_voidSetPinValue(DirectionPort, P2, 0);
    M_PWM_voidSetDutyCycle(0);
}