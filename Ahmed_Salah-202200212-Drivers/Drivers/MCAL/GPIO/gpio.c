/**
 * @file    gpio.c
 * @brief   PIC16F877 GPIO Driver Implementation
 */

#include "gpio.h"

/*============================================================
 * Internal helpers — map port enum to SFR addresses
 *============================================================*/
static volatile unsigned char * const PORT_REG[] = {
    &PORTA, &PORTB, &PORTC, &PORTD, &PORTE
};

static volatile unsigned char * const TRIS_REG[] = {
    &TRISA, &TRISB, &TRISC, &TRISD, &TRISE
};

/*------------------------------------------------------------
 * GPIO_Init
 *------------------------------------------------------------*/
void GPIO_Init(const GPIO_Config_t *cfg)
{
    GPIO_SetDirection(cfg->port, cfg->pin, cfg->direction);

    if (cfg->direction == GPIO_OUTPUT) {
        GPIO_WritePin(cfg->port, cfg->pin, cfg->initState);
    }
}

/*------------------------------------------------------------
 * GPIO_SetDirection
 *------------------------------------------------------------*/
void GPIO_SetDirection(GPIO_Port_t port, GPIO_Pin_t pin, GPIO_Direction_t dir)
{
    uint8_t mask = (uint8_t)(1u << pin);

    if (dir == GPIO_INPUT) {
        *TRIS_REG[port] |= mask;           /* Set bit → input  */
    } else {
        *TRIS_REG[port] &= (uint8_t)(~mask); /* Clear bit → output */
    }
}

/*------------------------------------------------------------
 * GPIO_SetPortDirection
 *------------------------------------------------------------*/
void GPIO_SetPortDirection(GPIO_Port_t port, uint8_t mask)
{
    *TRIS_REG[port] = mask;
}

/*------------------------------------------------------------
 * GPIO_WritePin
 *------------------------------------------------------------*/
void GPIO_WritePin(GPIO_Port_t port, GPIO_Pin_t pin, GPIO_State_t state)
{
    uint8_t mask = (uint8_t)(1u << pin);

    if (state == GPIO_HIGH) {
        *PORT_REG[port] |= mask;
    } else {
        *PORT_REG[port] &= (uint8_t)(~mask);
    }
}

/*------------------------------------------------------------
 * GPIO_WritePort
 *------------------------------------------------------------*/
void GPIO_WritePort(GPIO_Port_t port, uint8_t value)
{
    *PORT_REG[port] = value;
}

/*------------------------------------------------------------
 * GPIO_ReadPin
 *------------------------------------------------------------*/
GPIO_State_t GPIO_ReadPin(GPIO_Port_t port, GPIO_Pin_t pin)
{
    uint8_t mask = (uint8_t)(1u << pin);
    return ((*PORT_REG[port] & mask) != 0u) ? GPIO_HIGH : GPIO_LOW;
}

/*------------------------------------------------------------
 * GPIO_ReadPort
 *------------------------------------------------------------*/
uint8_t GPIO_ReadPort(GPIO_Port_t port)
{
    return *PORT_REG[port];
}

/*------------------------------------------------------------
 * GPIO_TogglePin
 *------------------------------------------------------------*/
void GPIO_TogglePin(GPIO_Port_t port, GPIO_Pin_t pin)
{
    uint8_t mask = (uint8_t)(1u << pin);
    *PORT_REG[port] ^= mask;
}

/*------------------------------------------------------------
 * GPIO_SetPortBPullUp
 * OPTION_REG<7> = RBPU  (0 = pull-ups enabled)
 *------------------------------------------------------------*/
void GPIO_SetPortBPullUp(GPIO_PullUp_t state)
{
    if (state == GPIO_PULLUP_ENABLE) {
        OPTION_REGbits.nRBPU = 0;   /* Active-low — clear to enable */
    } else {
        OPTION_REGbits.nRBPU = 1;
    }
}
