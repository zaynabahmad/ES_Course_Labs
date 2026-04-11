#include "../HAL/DC_MOTOR/DCMOTOR_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../HAL/SWITCH/SWITCH_config.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/PWM/PWM_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/DELAY/DELAY_interface.h"

#define MOTOR_PORT   GPIO_PORTB
#define MOTOR_IN1    GPIO_PIN4
#define MOTOR_IN2    GPIO_PIN5

volatile u8 g_buttonEvent = 0;
volatile u8 g_dutyIndex = 0;

const u8 g_dutyTable[4] = {25, 50, 75, 100};

void APP_ButtonCallback(void)
{
    g_buttonEvent = 1;
}

void APP_PWM_Test(void)
{
    DCMOTOR_Init(MOTOR_PORT, MOTOR_IN1, MOTOR_IN2);
    DCMOTOR_Forward(MOTOR_PORT, MOTOR_IN1, MOTOR_IN2);

    SWITCH_Init(&SW1);

    PWM_Init(5000);
    PWM_Start();
    PWM_SetDutyPercent(g_dutyTable[g_dutyIndex]);

    EXT_INT0_SetCallback(APP_ButtonCallback);
    EXT_INT0_Init();

    while(1)
    {
        if(g_buttonEvent == 1)
        {
            Delay_ms(50);

            if(SWITCH_GetState(&SW1) == SWITCH_PRESSED)
            {
                g_dutyIndex++;

                if(g_dutyIndex >= 4)
                {
                    g_dutyIndex = 0;
                }

                PWM_SetDutyPercent(g_dutyTable[g_dutyIndex]);

                while(SWITCH_GetState(&SW1) == SWITCH_PRESSED)
                {
                }
            }

            g_buttonEvent = 0;
        }
    }
}