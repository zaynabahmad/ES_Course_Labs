/*
 * gpio.h
 * MCAL - GPIO Driver Interface for PIC16F877A
 * Public header - safe to include from all layers
 */

#ifndef GPIO_H
#define GPIO_H

/* =====================================================
 * Type Definitions
 * ===================================================== */
typedef unsigned char  u8;
typedef unsigned int   u16;

/* GPIO Ports */
typedef enum {
    GPIO_PORTA = 0,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE
} GPIO_Port_t;

/* GPIO Pins */
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

/* GPIO Direction */
typedef enum {
    GPIO_OUTPUT = 0,
    GPIO_INPUT  = 1
} GPIO_Dir_t;

/* GPIO Logic Level */
typedef enum {
    GPIO_LOW  = 0,
    GPIO_HIGH = 1
} GPIO_Level_t;

/* =====================================================
 * Function Prototypes
 * ===================================================== */

/**
 * @brief  Set the direction of a specific GPIO pin
 * @param  port  : GPIO port (GPIO_PORTA .. GPIO_PORTE)
 * @param  pin   : GPIO pin  (GPIO_PIN0 .. GPIO_PIN7)
 * @param  dir   : GPIO_OUTPUT or GPIO_INPUT
 */
void GPIO_SetPinDirection(GPIO_Port_t port, GPIO_Pin_t pin, GPIO_Dir_t dir);

/**
 * @brief  Set the direction of an entire GPIO port
 * @param  port  : GPIO port
 * @param  dir   : 0x00 = all output, 0xFF = all input (bit mask)
 */
void GPIO_SetPortDirection(GPIO_Port_t port, u8 dir);

/**
 * @brief  Write a logic level to a specific GPIO pin
 */
void GPIO_WritePin(GPIO_Port_t port, GPIO_Pin_t pin, GPIO_Level_t level);

/**
 * @brief  Write a byte to an entire GPIO port
 */
void GPIO_WritePort(GPIO_Port_t port, u8 value);

/**
 * @brief  Read a specific GPIO pin
 * @return GPIO_HIGH or GPIO_LOW
 */
GPIO_Level_t GPIO_ReadPin(GPIO_Port_t port, GPIO_Pin_t pin);

/**
 * @brief  Read an entire GPIO port
 * @return 8-bit value of the port
 */
u8 GPIO_ReadPort(GPIO_Port_t port);

/**
 * @brief  Toggle a specific GPIO pin
 */
void GPIO_TogglePin(GPIO_Port_t port, GPIO_Pin_t pin);

#endif /* GPIO_H */
