/**
 * @file    dc_motor.h
 * @brief   PIC16F87X HAL DC Motor Driver Header
 * @details DC motor control via H-bridge (L298/L293).
 *          Uses MCAL GPIO for direction (IN1, IN2) and MCAL PWM for speed (EN).
 *
 * Typical wiring with L298N:
 *   IN1 → GPIO pin  (direction control)
 *   IN2 → GPIO pin  (direction control)
 *   ENA → CCP1/CCP2 (PWM speed control)
 *
 * Truth table:
 *   IN1=H, IN2=L → Forward
 *   IN1=L, IN2=H → Reverse
 *   IN1=L, IN2=L → Coast (free-running stop)
 *   IN1=H, IN2=H → Brake (short-circuit stop)
 */

#ifndef DC_MOTOR_H
#define DC_MOTOR_H

#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/PWM/pwm.h"

/*============================================================
 * Motor Direction
 *============================================================*/
typedef enum {
    DCMOTOR_DIR_STOP    = 0,   /* Coast — both pins LOW       */
    DCMOTOR_DIR_FORWARD = 1,   /* IN1=H, IN2=L               */
    DCMOTOR_DIR_REVERSE = 2,   /* IN1=L, IN2=H               */
    DCMOTOR_DIR_BRAKE   = 3    /* Both pins HIGH — hard brake */
} DCMotor_Direction_t;

/*============================================================
 * Configuration Structure
 *============================================================*/
typedef struct {
    GPIO_Port_t     in1Port;       /* IN1 direction pin port       */
    GPIO_Pin_t      in1Pin;        /* IN1 direction pin             */
    GPIO_Port_t     in2Port;       /* IN2 direction pin port       */
    GPIO_Pin_t      in2Pin;        /* IN2 direction pin             */
    PWM_Channel_t   pwmChannel;    /* PWM channel for speed (CCP1/CCP2) */
    uint32_t        pwmFreqHz;     /* Desired PWM frequency in Hz  */
    uint32_t        foscHz;        /* Crystal frequency (e.g., 4000000) */
} DCMotor_Config_t;

/*============================================================
 * Motor Handle — stores runtime info
 *============================================================*/
typedef struct {
    GPIO_Port_t        in1Port;
    GPIO_Pin_t         in1Pin;
    GPIO_Port_t        in2Port;
    GPIO_Pin_t         in2Pin;
    PWM_Channel_t      pwmChannel;
    DCMotor_Direction_t currentDir;
    uint8_t            currentSpeed;   /* 0–100 percent */
} DCMotor_Handle_t;

/*============================================================
 * API
 *============================================================*/

/**
 * @brief  Initialize DC motor driver
 * @param  handle  Pointer to DCMotor_Handle_t (filled by this function)
 * @param  cfg     Pointer to DCMotor_Config_t
 * @note   Configures IN1/IN2 as GPIO outputs and initializes PWM channel
 */
void DCMotor_Init(DCMotor_Handle_t *handle, const DCMotor_Config_t *cfg);

/**
 * @brief  Run motor forward at given speed
 * @param  handle  Pointer to initialized DCMotor_Handle_t
 * @param  speed   Speed as percentage 0–100
 */
void DCMotor_Forward(DCMotor_Handle_t *handle, uint8_t speed);

/**
 * @brief  Run motor in reverse at given speed
 * @param  handle  Pointer to initialized DCMotor_Handle_t
 * @param  speed   Speed as percentage 0–100
 */
void DCMotor_Reverse(DCMotor_Handle_t *handle, uint8_t speed);

/**
 * @brief  Stop motor (coast — free-running)
 * @param  handle  Pointer to initialized DCMotor_Handle_t
 * @note   IN1=L, IN2=L, PWM=0%
 */
void DCMotor_Stop(DCMotor_Handle_t *handle);

/**
 * @brief  Brake motor (hard stop — short-circuit windings)
 * @param  handle  Pointer to initialized DCMotor_Handle_t
 * @note   IN1=H, IN2=H, PWM=100%
 */
void DCMotor_Brake(DCMotor_Handle_t *handle);

/**
 * @brief  Update motor speed without changing direction
 * @param  handle  Pointer to initialized DCMotor_Handle_t
 * @param  speed   Speed as percentage 0–100
 */
void DCMotor_SetSpeed(DCMotor_Handle_t *handle, uint8_t speed);

/**
 * @brief  Get current motor direction
 * @param  handle  Pointer to initialized DCMotor_Handle_t
 * @return Current DCMotor_Direction_t
 */
DCMotor_Direction_t DCMotor_GetDirection(const DCMotor_Handle_t *handle);

/**
 * @brief  Get current motor speed
 * @param  handle  Pointer to initialized DCMotor_Handle_t
 * @return Speed percentage 0–100
 */
uint8_t DCMotor_GetSpeed(const DCMotor_Handle_t *handle);

#endif /* DC_MOTOR_H */
