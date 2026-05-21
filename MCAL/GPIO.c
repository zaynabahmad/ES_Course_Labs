/**
 * @file    GPIO.c
 * @brief   GPIO driver implementation for the PIC16F877A.
 *
 * @details Every public function resolves its port to a register pointer once,
 *          through the switch-case helpers below, then does the minimum bit
 *          work. Centralising the port lookup keeps the address map in exactly
 *          one place -- add a port and only the two helpers change.
 */
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_cfg.h"
#include "../SERVICES/Macros.h"

/**
 * @brief  Resolve a port index to its data-latch register.
 * @return Pointer to the live PORTx register, or NULL_PTR if @p ePort is bogus.
 * @note   switch-case (not an array) so an out-of-range value falls straight
 *         through to the NULL_PTR guard instead of indexing past the table.
 */
static volatile byte_t *pDataReg(ePort_t ePort)
{
    switch (ePort)
    {
        case GPIO_PORT_A: return (volatile byte_t *)GPIO_ADDR_PORTA;
        case GPIO_PORT_B: return (volatile byte_t *)GPIO_ADDR_PORTB;
        case GPIO_PORT_C: return (volatile byte_t *)GPIO_ADDR_PORTC;
        case GPIO_PORT_D: return (volatile byte_t *)GPIO_ADDR_PORTD;
        case GPIO_PORT_E: return (volatile byte_t *)GPIO_ADDR_PORTE;
        default:          return NULL_PTR;
    }
}

/**
 * @brief  Resolve a port index to its direction (TRIS) register.
 */
static volatile byte_t *pDirReg(ePort_t ePort)
{
    switch (ePort)
    {
        case GPIO_PORT_A: return (volatile byte_t *)GPIO_ADDR_TRISA;
        case GPIO_PORT_B: return (volatile byte_t *)GPIO_ADDR_TRISB;
        case GPIO_PORT_C: return (volatile byte_t *)GPIO_ADDR_TRISC;
        case GPIO_PORT_D: return (volatile byte_t *)GPIO_ADDR_TRISD;
        case GPIO_PORT_E: return (volatile byte_t *)GPIO_ADDR_TRISE;
        default:          return NULL_PTR;
    }
}

void vGPIO_PinMode(ePort_t ePort, byte_t u8Pin, ePinDir_t eDir)
{
    volatile byte_t *pTris = pDirReg(ePort);

#if (GPIO_ARG_GUARD == 1)
    if ((pTris == NULL_PTR) || (u8Pin > GPIO_PIN_MAX))
    {
        return;                 /* Silently ignore an impossible request. */
    }
#endif

    /* A TRIS bit of 1 means input -- so the direction enum drives the bit. */
    switch (eDir)
    {
        case GPIO_DIR_INPUT:  BIT_HIGH(*pTris, u8Pin); break;
        case GPIO_DIR_OUTPUT: BIT_LOW(*pTris, u8Pin);  break;
        default:              /* leave direction unchanged */ break;
    }
}

void vGPIO_PinWrite(ePort_t ePort, byte_t u8Pin, eLevel_t eLevel)
{
    volatile byte_t *pPort = pDataReg(ePort);

#if (GPIO_ARG_GUARD == 1)
    if ((pPort == NULL_PTR) || (u8Pin > GPIO_PIN_MAX))
    {
        return;
    }
#endif

    switch (eLevel)
    {
        case LEVEL_HIGH: BIT_HIGH(*pPort, u8Pin); break;
        case LEVEL_LOW:  BIT_LOW(*pPort, u8Pin);  break;
        default:         break;
    }
}

eLevel_t u8GPIO_PinRead(ePort_t ePort, byte_t u8Pin)
{
    volatile byte_t *pPort = pDataReg(ePort);

#if (GPIO_ARG_GUARD == 1)
    if ((pPort == NULL_PTR) || (u8Pin > GPIO_PIN_MAX))
    {
        return LEVEL_LOW;       /* Safe default for a malformed query. */
    }
#endif

    return BIT_IS_RAISED(*pPort, u8Pin) ? LEVEL_HIGH : LEVEL_LOW;
}

void vGPIO_PortMode(ePort_t ePort, byte_t u8Mask)
{
    volatile byte_t *pTris = pDirReg(ePort);

#if (GPIO_ARG_GUARD == 1)
    if (pTris == NULL_PTR)
    {
        return;
    }
#endif

    REG_LOAD(*pTris, u8Mask);
}

void vGPIO_PortWrite(ePort_t ePort, byte_t u8Value)
{
    volatile byte_t *pPort = pDataReg(ePort);

#if (GPIO_ARG_GUARD == 1)
    if (pPort == NULL_PTR)
    {
        return;
    }
#endif

    REG_LOAD(*pPort, u8Value);
}

void vGPIO_PortBPullups(flag_t bEnable)
{
    /* /RBPU is active-low, so the flag and the bit are inverted: a request to
     * enable the pull-ups means clearing the bit. */
    switch (bEnable)
    {
        case FLAG_RAISED: BIT_LOW(GPIO_REG(GPIO_ADDR_OPTION),  GPIO_BIT_RBPU); break;
        default:          BIT_HIGH(GPIO_REG(GPIO_ADDR_OPTION), GPIO_BIT_RBPU); break;
    }
}
