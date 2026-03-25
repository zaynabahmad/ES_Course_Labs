/**
 * @file    gpio.h
 * @brief   PIC16F877 GPIO Driver Header
 * @details Full-featured GPIO driver for PORTA, PORTB, PORTC, PORTD, PORTE
 *          Based on PIC16F877 Datasheet DS30292C
 *
 * Register Map:
 *   PORTA  (0x05) - 6-bit bidirectional I/O
 *   PORTB  (0x06) - 8-bit bidirectional I/O (with pull-ups)
 *   PORTC  (0x07) - 8-bit bidirectional I/O
 *   PORTD  (0x08) - 8-bit bidirectional I/O (PSP capable)
 *   PORTE  (0x09) - 3-bit bidirectional I/O
 *   TRISA  (0x85) - PORTA direction control
 *   TRISB  (0x86) - PORTB direction control
 *   TRISC  (0x87) - PORTC direction control
 *   TRISD  (0x88) - PORTD direction control
 *   TRISE  (0x89) - PORTE direction control
 */

#ifndef GPIO_H
#define GPIO_H

#include <pic16f877.h>
#include <stdint.h>

/*============================================================
 * Port Identifiers
 *============================================================*/
typedef enum {
    GPIO_PORTA = 0,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE
} GPIO_Port_t;

/*============================================================
 * Pin Identifiers (bit positions)
 *============================================================*/
typedef enum {
    GPIO_PIN0 = 0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
} GPIO_Pin_t;

/*============================================================
 * Direction
 *============================================================*/
typedef enum {
    GPIO_OUTPUT = 0,
    GPIO_INPUT  = 1
} GPIO_Direction_t;

/*============================================================
 * Pin State
 *============================================================*/
typedef enum {
    GPIO_LOW  = 0,
    GPIO_HIGH = 1
} GPIO_State_t;

/*============================================================
 * Pull-up (PORTB only — OPTION_REG<7> RBPU)
 *============================================================*/
typedef enum {
    GPIO_PULLUP_DISABLE = 0,
    GPIO_PULLUP_ENABLE  = 1
} GPIO_PullUp_t;

/*============================================================
 * Configuration Structure
 *============================================================*/
typedef struct {
    GPIO_Port_t      port;
    GPIO_Pin_t       pin;
    GPIO_Direction_t direction;
    GPIO_State_t     initState;   /* Only used if direction == OUTPUT */
} GPIO_Config_t;

/*============================================================
 * API
 *============================================================*/

/**
 * @brief  Initialize a single GPIO pin
 * @param  cfg  Pointer to GPIO_Config_t
 */
void GPIO_Init(const GPIO_Config_t *cfg);

/**
 * @brief  Set direction of a single pin
 * @param  port  GPIO_Port_t
 * @param  pin   GPIO_Pin_t
 * @param  dir   GPIO_INPUT or GPIO_OUTPUT
 */
void GPIO_SetDirection(GPIO_Port_t port, GPIO_Pin_t pin, GPIO_Direction_t dir);

/**
 * @brief  Set direction of an entire port (8-bit mask, 1=input 0=output)
 * @param  port  GPIO_Port_t
 * @param  mask  8-bit TRIS value
 */
void GPIO_SetPortDirection(GPIO_Port_t port, uint8_t mask);

/**
 * @brief  Write HIGH or LOW to a single output pin
 * @param  port   GPIO_Port_t
 * @param  pin    GPIO_Pin_t
 * @param  state  GPIO_HIGH or GPIO_LOW
 */
void GPIO_WritePin(GPIO_Port_t port, GPIO_Pin_t pin, GPIO_State_t state);

/**
 * @brief  Write a byte to a full port output latch
 * @param  port   GPIO_Port_t
 * @param  value  8-bit value
 */
void GPIO_WritePort(GPIO_Port_t port, uint8_t value);

/**
 * @brief  Read the current logic level of a single pin
 * @param  port  GPIO_Port_t
 * @param  pin   GPIO_Pin_t
 * @return GPIO_HIGH or GPIO_LOW
 */
GPIO_State_t GPIO_ReadPin(GPIO_Port_t port, GPIO_Pin_t pin);

/**
 * @brief  Read the entire port (8-bit)
 * @param  port  GPIO_Port_t
 * @return 8-bit port value
 */
uint8_t GPIO_ReadPort(GPIO_Port_t port);

/**
 * @brief  Toggle a single output pin
 * @param  port  GPIO_Port_t
 * @param  pin   GPIO_Pin_t
 */
void GPIO_TogglePin(GPIO_Port_t port, GPIO_Pin_t pin);

/**
 * @brief  Enable or disable PORTB internal weak pull-ups (OPTION_REG<7>)
 * @note   Applies to entire PORTB; individual pin must be configured as input
 * @param  state  GPIO_PULLUP_ENABLE or GPIO_PULLUP_DISABLE
 */
void GPIO_SetPortBPullUp(GPIO_PullUp_t state);

#endif /* GPIO_H */
