# PIC Drivers Project — Claude Instructions

## Project Goal

Implement a complete set of reusable embedded peripheral drivers for the **PIC16F877A** MCU,
following a strict layered architecture. The drivers must be portable, register-level correct,
and testable without a physical board (simulator-compatible).

Target MCU: **PIC16F877A**
Assumed F_CPU: **4 MHz** (document in each `_Config.h` if timing-dependent)

---

## Architecture Rules

### Layers (strict dependency order — lower layers must not include higher ones)

```
APP  →  HAL  →  MCAL  →  SERVICES
```

- **SERVICES**: Shared macros and types. No MCU-specific code. Included by all layers.
- **MCAL**: Direct hardware access. The only layer allowed to touch registers.
- **HAL**: High-level drivers built on top of MCAL APIs. No direct register access.
- **APP**: Application logic and driver tests. No direct register access. No HAL internals exposed.

### Strict prohibitions per layer

| Layer | Prohibited |
|-------|-----------|
| APP | Register addresses, `TRISx`/`PORTx` names, `ADCON0`, or any SFR symbol |
| APP | Including `_Private.h` files |
| HAL | Including `_Private.h` files from MCAL |
| Any | Compiler built-in register names (`PORTA`, `TRISA` as compiler keywords — use only the macros defined in `_Private.h`) |

---

## Required Drivers

| Driver | Layer | Status |
|--------|-------|--------|
| GPIO | MCAL | Done |
| External Interrupt (EXT_INT) | MCAL | Done |
| Timer0 | MCAL | Done |
| USART | MCAL | Done |
| ADC | MCAL | Pending |
| PWM (CCP1 + Timer2) | MCAL | Pending |
| SPI (MSSP Master) | MCAL | Pending |
| I2C (MSSP Master) | MCAL | Pending |
| LED | HAL | Done |

---

## Folder Structure

```
PIC_drivers/
│
├── SERVICES/
│   ├── STD_TYPES.h          # u8, u16, u32, s8, s16, s32, f32, NULL_PTR
│   └── BIT_MATH.h           # SET_BIT, CLR_BIT, TOG_BIT, GET_BIT
│
├── MCAL/
│   ├── GPIO/
│   │   ├── GPIO_private.h   # Register addresses ONLY (volatile pointer macros)
│   │   ├── GPIO_config.h    # Compile-time defaults
│   │   ├── GPIO_interface.h # Public API + constants (include this in other layers)
│   │   └── GPIO.c
│   ├── EXT_INT/             # Same 4-file pattern
│   ├── TIMER_0/             # Same 4-file pattern
│   ├── USART/               # Same 4-file pattern
│   ├── ADC/                 # Same 4-file pattern
│   ├── PWM/                 # Same 4-file pattern
│   ├── SPI/                 # Same 4-file pattern
│   ├── I2C/                 # Same 4-file pattern
│   └── INTERRUPT_MANAGER/
│       └── Interrupt_Manager.c
│
├── HAL/
│   └── LED/
│       ├── LED_private.h
│       ├── LED_config.h
│       ├── LED_interface.h
│       └── LED.c
│
├── APP/
│   ├── main.c               # Calls one test function per driver, nothing else
│   ├── gpio_test.c          # Tests GPIO driver only
│   ├── gpio_test.h
│   ├── ext_int_test.c       # Tests EXT_INT driver only
│   ├── ext_int_test.h
│   ├── timer0_test.c        # Tests Timer0 driver only
│   ├── timer0_test.h
│   ├── uart_test.c          # Tests USART driver only
│   ├── uart_test.h
│   ├── adc_test.c           # Tests ADC driver only
│   ├── adc_test.h
│   ├── pwm_test.c           # Tests PWM driver only
│   ├── pwm_test.h
│   ├── spi_test.c           # Tests SPI driver only
│   ├── spi_test.h
│   ├── i2c_test.c           # Tests I2C driver only
│   └── i2c_test.h
│
└── SERVICES/                # (as above)
```

---

## MCAL Driver File Conventions

Every MCAL driver follows the same 4-file pattern:

### `DRIVERNAME_private.h`
- Contains **only** register address macros using volatile pointer casts:
  ```c
  #define ADCON0  (*((volatile u8*)0x1F))
  ```
- Never included outside MCAL. Never included in APP or HAL.
- Include guard: `#ifndef DRIVERNAME_PRIVATE_H`

### `DRIVERNAME_config.h`
- Contains compile-time configuration options (e.g., prescaler value, baud rate, default channel).
- May be edited by the user to tune behavior without touching implementation.
- Include guard: `#ifndef DRIVERNAME_CONFIG_H`

### `DRIVERNAME_interface.h`
- The **only** file that other layers include.
- Contains: function prototypes, public `#define` constants, `typedef` enums/structs if needed.
- Must **not** include `_private.h`.
- Must include `../../SERVICES/STD_TYPES.h` and `../../SERVICES/BIT_MATH.h`.
- Include guard: `#ifndef DRIVERNAME_INTERFACE_H`

### `DRIVERNAME.c`
- Includes its own `_private.h`, `_config.h`, `_interface.h`, and SERVICES.
- All register access done via the macros from `_private.h` using `BIT_MATH.h` macros.
- No compiler built-in SFR names.

---

## APP Layer Rules

### Per-driver test files

Each APP test file must:
1. Include only the corresponding driver's `_Interface.h` (and `STD_TYPES.h` if needed).
2. Define a single entry-point function: `void DRIVERNAME_test_run(void)`.
3. Test the driver's public API only — no register access, no `_private.h` includes.
4. Use only the constants and functions exported from `_Interface.h`.

Example `gpio_test.h`:
```c
#ifndef GPIO_TEST_H
#define GPIO_TEST_H
void gpio_test_run(void);
#endif
```

Example `gpio_test.c`:
```c
#include "../MCAL/GPIO/GPIO_interface.h"
#include "gpio_test.h"

void gpio_test_run(void) {
    GPIO_Init();
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN0, GPIO_HIGH);
    /* ... */
}
```

### `main.c` rules

```c
/* main.c — only calls test entry points, no logic */
#include "gpio_test.h"
#include "ext_int_test.h"
#include "timer0_test.h"
#include "uart_test.h"
#include "adc_test.h"
#include "pwm_test.h"
#include "spi_test.h"
#include "i2c_test.h"

int main(void) {
    gpio_test_run();
    ext_int_test_run();
    timer0_test_run();
    uart_test_run();
    adc_test_run();
    pwm_test_run();
    spi_test_run();
    i2c_test_run();
    while (1) {}
    return 0;
}
```

---

## PIC16F877A Register Map Quick Reference

Use these addresses in `_private.h` files. All addresses are for bank 0 / bank 1 as noted.

| Register | Address | Bank | Purpose |
|----------|---------|------|---------|
| PORTA | 0x05 | 0 | Port A data |
| PORTB | 0x06 | 0 | Port B data |
| PORTC | 0x07 | 0 | Port C data |
| PORTD | 0x08 | 0 | Port D data |
| PORTE | 0x09 | 0 | Port E data |
| INTCON | 0x0B | 0/1 | Interrupt control |
| PIR1 | 0x0C | 0 | Peripheral interrupt flags |
| TMR0 | 0x01 | 0 | Timer0 register |
| OPTION_REG | 0x81 | 1 | Timer0 prescaler / pullups |
| TRISA | 0x85 | 1 | Port A direction |
| TRISB | 0x86 | 1 | Port B direction |
| TRISC | 0x87 | 1 | Port C direction |
| TRISD | 0x88 | 1 | Port D direction |
| TRISE | 0x89 | 1 | Port E direction |
| PIE1 | 0x8C | 1 | Peripheral interrupt enables |
| ADRESH | 0x1E | 0 | ADC result high |
| ADCON0 | 0x1F | 0 | ADC control 0 |
| ADRESL | 0x9E | 1 | ADC result low |
| ADCON1 | 0x9F | 1 | ADC control 1 |
| SSPBUF | 0x13 | 0 | MSSP buffer (SPI/I2C) |
| SSPCON | 0x14 | 0 | MSSP control |
| SSPSTAT | 0x94 | 1 | MSSP status |
| SSPCON2 | 0x91 | 1 | MSSP control 2 (I2C) |
| SSPADD | 0x93 | 1 | I2C address / baud rate |
| CCP1CON | 0x17 | 0 | CCP1 control (PWM) |
| CCPR1L | 0x15 | 0 | PWM duty cycle low |
| CCPR1H | 0x16 | 0 | PWM duty cycle high |
| T2CON | 0x12 | 0 | Timer2 control |
| TMR2 | 0x11 | 0 | Timer2 register |
| PR2 | 0x92 | 1 | Timer2 period register |
| TXREG | 0x19 | 0 | UART TX register |
| RCREG | 0x1A | 0 | UART RX register |
| TXSTA | 0x98 | 1 | UART TX status |
| RCSTA | 0x18 | 0 | UART RX status |
| SPBRG | 0x99 | 1 | UART baud rate generator |

---

## Constraints and Do-Not-Do List

### NEVER do these

- Do NOT access registers directly in APP or HAL (no `0x05`, no `PORTA =`, no `TRISB =`).
- Do NOT use compiler-specific built-in register names (`PORTA`, `TRISA`, `ADCON0` as XC8 SFRs).
  Use only the macros you define in `_private.h` using volatile pointer casts.
- Do NOT include `_private.h` from any file outside the owning driver's `.c` file.
- Do NOT place driver files in separate top-level folders (e.g., no `ADC/` at root level).
  All drivers live inside `MCAL/`, `HAL/`, or `APP/` as appropriate.
- Do NOT create ZIP archives or suggest downloading files.
- Do NOT put multiple drivers' test logic in a single APP file.
- Do NOT use `__delay_ms()` or other compiler built-in delay functions — implement waits using
  timer registers or counted loops.
- Do NOT mix SPI and I2C initialization in the same build without a compile-time mode guard in
  their respective `_Config.h` files (they share the MSSP hardware).

### Always do these

- Use `SET_BIT`, `CLR_BIT`, `GET_BIT`, `TOG_BIT` from `BIT_MATH.h` for all register manipulation.
- Use `u8`, `u16`, `u32` from `STD_TYPES.h` — never use `unsigned char` or `int` directly.
- Keep `_interface.h` as the only public contract for each driver.
- Every ISR function must be declared in `_interface.h` and called from `Interrupt_Manager.c`.
- Every driver that uses callbacks must store the callback as a `static` function pointer in `.c`.

---

## Implementation Phase Summary

| Phase | Goal | Dependencies | Status |
|-------|------|-------------|--------|
| 0 | Audit existing drivers | — | Done |
| 1 | APP layer restructure (per-driver test files) | GPIO, EXT_INT, TIMER_0, USART | Pending |
| 2 | ADC driver | GPIO, SERVICES | Pending |
| 3 | PWM driver (CCP1 + Timer2) | GPIO, SERVICES | Pending |
| 4 | SPI driver (MSSP Master) | GPIO, SERVICES | Pending |
| 5 | I2C driver (MSSP Master) | GPIO, SERVICES | Pending |
| 6 | HAL extensions (BUTTON, MOTOR, SENSOR) | GPIO, PWM, ADC | Optional |
| 7 | Final main.c integration | All drivers | Pending |

---

## Naming Conventions

| Item | Convention | Example |
|------|-----------|---------|
| Driver folder | UPPER_CASE | `MCAL/ADC/` |
| Source files | UPPER_CASE | `ADC.c`, `ADC_interface.h` |
| APP test files | lower_snake | `adc_test.c`, `adc_test.h` |
| Public functions | `DRIVER_VerbNoun` | `ADC_Read()`, `PWM_SetDutyCycle()` |
| Private macros | UPPER_CASE | `ADCON0`, `GO_DONE_BIT` |
| Constants/defines | UPPER_CASE with prefix | `ADC_CH0`, `PWM_PRESCALER_1` |
| Types | `u8`, `u16`, etc. | from STD_TYPES.h |
