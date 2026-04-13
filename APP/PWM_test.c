#include "../MCAL/PWM/PWM_interface.h"

void PWM_Test(void)
{
    u8 DutyCycle;

    /* Test 1: Initialize PWM with 5 kHz frequency */
    PWM_Init(5);

    /* Test 2: Set PWM Channel 1 duty cycle to 50% */
    PWM_SetDutyCycle(PWM_CHANNEL1, 50);

    /* Test 3: Set PWM Channel 2 duty cycle to 75% */
    PWM_SetDutyCycle(PWM_CHANNEL2, 75);

    /* Test 4: Start PWM on Channel 1 */
    PWM_Start(PWM_CHANNEL1);

    /* Test 5: Start PWM on Channel 2 */
    PWM_Start(PWM_CHANNEL2);

    /* Test 6: Get current duty cycle for Channel 1 */
    DutyCycle = PWM_GetDutyCycle(PWM_CHANNEL1);

    /* Test 7: Change duty cycle to 25% */
    PWM_SetDutyCycle(PWM_CHANNEL1, 25);

    /* Test 8: Stop PWM on Channel 1 */
    PWM_Stop(PWM_CHANNEL1);

    /* Test 9: Stop PWM on Channel 2 */
    PWM_Stop(PWM_CHANNEL2);
}
