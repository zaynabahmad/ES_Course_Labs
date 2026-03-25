/**
 * @file    dc_motor.c
 * @brief   PIC16F87X HAL DC Motor Driver Implementation
 */

#include "dc_motor.h"

/*------------------------------------------------------------
 * Internal: set direction pins
 *------------------------------------------------------------*/
static void dcmotor_set_direction_pins(const DCMotor_Handle_t *handle,
                                        GPIO_State_t in1, GPIO_State_t in2)
{
    GPIO_WritePin(handle->in1Port, handle->in1Pin, in1);
    GPIO_WritePin(handle->in2Port, handle->in2Pin, in2);
}

/*------------------------------------------------------------
 * DCMotor_Init
 *------------------------------------------------------------*/
void DCMotor_Init(DCMotor_Handle_t *handle, const DCMotor_Config_t *cfg)
{
    /* Store config in handle */
    handle->in1Port     = cfg->in1Port;
    handle->in1Pin      = cfg->in1Pin;
    handle->in2Port     = cfg->in2Port;
    handle->in2Pin      = cfg->in2Pin;
    handle->pwmChannel  = cfg->pwmChannel;
    handle->currentDir  = DCMOTOR_DIR_STOP;
    handle->currentSpeed = 0u;

    /* Configure IN1 as output, initially LOW */
    GPIO_Config_t in1Cfg = {
        .port      = cfg->in1Port,
        .pin       = cfg->in1Pin,
        .direction = GPIO_OUTPUT,
        .initState = GPIO_LOW
    };
    GPIO_Init(&in1Cfg);

    /* Configure IN2 as output, initially LOW */
    GPIO_Config_t in2Cfg = {
        .port      = cfg->in2Port,
        .pin       = cfg->in2Pin,
        .direction = GPIO_OUTPUT,
        .initState = GPIO_LOW
    };
    GPIO_Init(&in2Cfg);

    /* Configure PWM for speed control
     * Default prescaler = 1 for best resolution at most frequencies */
    PWM_Config_t pwmCfg = {
        .channel    = cfg->pwmChannel,
        .pr2Value   = PWM_CalcPR2(cfg->pwmFreqHz, cfg->foscHz, 1u),
        .prescaler  = PWM_PRESCALER_1,
        .postscaler = PWM_POSTSCALER_1,
        .dutyCycle  = 0u                   /* Start at 0% */
    };
    PWM_Init(&pwmCfg);
}

/*------------------------------------------------------------
 * DCMotor_Forward
 *------------------------------------------------------------*/
void DCMotor_Forward(DCMotor_Handle_t *handle, uint8_t speed)
{
    handle->currentDir   = DCMOTOR_DIR_FORWARD;
    handle->currentSpeed = speed;

    dcmotor_set_direction_pins(handle, GPIO_HIGH, GPIO_LOW);
    PWM_SetDutyPercent(handle->pwmChannel, speed);
}

/*------------------------------------------------------------
 * DCMotor_Reverse
 *------------------------------------------------------------*/
void DCMotor_Reverse(DCMotor_Handle_t *handle, uint8_t speed)
{
    handle->currentDir   = DCMOTOR_DIR_REVERSE;
    handle->currentSpeed = speed;

    dcmotor_set_direction_pins(handle, GPIO_LOW, GPIO_HIGH);
    PWM_SetDutyPercent(handle->pwmChannel, speed);
}

/*------------------------------------------------------------
 * DCMotor_Stop — coast (free-running)
 *------------------------------------------------------------*/
void DCMotor_Stop(DCMotor_Handle_t *handle)
{
    handle->currentDir   = DCMOTOR_DIR_STOP;
    handle->currentSpeed = 0u;

    dcmotor_set_direction_pins(handle, GPIO_LOW, GPIO_LOW);
    PWM_SetDutyPercent(handle->pwmChannel, 0u);
}

/*------------------------------------------------------------
 * DCMotor_Brake — hard stop (short-circuit windings)
 *------------------------------------------------------------*/
void DCMotor_Brake(DCMotor_Handle_t *handle)
{
    handle->currentDir   = DCMOTOR_DIR_BRAKE;
    handle->currentSpeed = 0u;

    dcmotor_set_direction_pins(handle, GPIO_HIGH, GPIO_HIGH);
    PWM_SetDutyPercent(handle->pwmChannel, 100u);
}

/*------------------------------------------------------------
 * DCMotor_SetSpeed — update speed without changing direction
 *------------------------------------------------------------*/
void DCMotor_SetSpeed(DCMotor_Handle_t *handle, uint8_t speed)
{
    handle->currentSpeed = speed;
    PWM_SetDutyPercent(handle->pwmChannel, speed);
}

/*------------------------------------------------------------
 * DCMotor_GetDirection
 *------------------------------------------------------------*/
DCMotor_Direction_t DCMotor_GetDirection(const DCMotor_Handle_t *handle)
{
    return handle->currentDir;
}

/*------------------------------------------------------------
 * DCMotor_GetSpeed
 *------------------------------------------------------------*/
uint8_t DCMotor_GetSpeed(const DCMotor_Handle_t *handle)
{
    return handle->currentSpeed;
}
