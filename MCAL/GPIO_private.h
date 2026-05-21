/**
 * @file    GPIO_private.h
 * @brief   Register-level details of the GPIO driver -- hidden from callers.
 *
 * @details mikroC exposes the SFRs as named globals, but the driver needs to
 *          pick one *at run time* from a port index. Rather than a five-way
 *          switch in every function, the SFRs are reached through their fixed
 *          data-memory addresses so a single helper can hand back a pointer.
 *          These addresses are the PIC16F877A bank-0/bank-1 SFR map and must
 *          not be edited.
 */
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#include "../SERVICES/Types.h"

/* Bank 0 -- port data latches. */
#define GPIO_ADDR_PORTA     0x05u
#define GPIO_ADDR_PORTB     0x06u
#define GPIO_ADDR_PORTC     0x07u
#define GPIO_ADDR_PORTD     0x08u
#define GPIO_ADDR_PORTE     0x09u

/* Bank 1 -- direction (TRIS) registers; 1 = input, 0 = output. */
#define GPIO_ADDR_TRISA     0x85u
#define GPIO_ADDR_TRISB     0x86u
#define GPIO_ADDR_TRISC     0x87u
#define GPIO_ADDR_TRISD     0x88u
#define GPIO_ADDR_TRISE     0x89u

/* OPTION_REG carries the global PORTB weak pull-up enable. */
#define GPIO_ADDR_OPTION    0x81u
#define GPIO_BIT_RBPU       7u      /* /RBPU: active-low, 0 = pull-ups on */

/** Treat a raw SFR address as a writable 8-bit register. */
#define GPIO_REG(addr)      ( *((volatile byte_t *)(addr)) )

#endif /* GPIO_PRIVATE_H */
