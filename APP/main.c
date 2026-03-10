#include "../HAL/MOTOR/MOTOR_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"

/* Duty cycle steps: 25 → 50 → 75 → 100 → 25 → ...
   Motor starts at 25% on power-up (set inside PWM_Init).        */
static const u8 speed_levels[4] = {
    MOTOR_SPEED_25,
    MOTOR_SPEED_50,
    MOTOR_SPEED_75,
    MOTOR_SPEED_100
};

static u8 speed_index = 0;   /* points to the currently active level */

void ButtonCallback(void)
{
    speed_index = (speed_index + 1u) % 4u;
    MOTOR_SetSpeed(speed_levels[speed_index]);
}

/* Unified ISR dispatcher */
void interrupt()
{
    EXT_INT0_IRQHandler();
}

void main()
{
    MOTOR_Init();                           /* direction pins + PWM at 25%   */
    EXT_INT0_Init();                        /* RB0 as falling-edge INT0 input */
    EXT_INT0_SetCallback(ButtonCallback);   /* each press steps up duty cycle */

    while(1)
    {
        /* CPU idles; all speed changes driven by EXT_INT0 ISR */
    }
}
