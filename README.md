# PIC16F877A Peripheral Drivers

A complete, layered embedded peripheral driver library for the **PIC16F877A** microcontroller, written in pure C against the hardware register map. All register access uses volatile pointer macros — no compiler-specific SFR names, no `xc.h`, simulator-compatible.

**Target MCU:** PIC16F877A  
**Assumed clock:** 4 MHz (F_CPU)  
**Language:** C (C89/C90 compatible)

---

## Table of Contents

1. [Architecture](#architecture)
2. [Folder Structure](#folder-structure)
3. [SERVICES Layer](#services-layer)
4. [MCAL Drivers](#mcal-drivers)
   - [GPIO](#gpio)
   - [EXT_INT](#ext_int)
   - [TIMER_0](#timer_0)
   - [USART](#usart)
   - [ADC](#adc)
   - [PWM](#pwm)
   - [SPI](#spi)
   - [I2C](#i2c)
   - [Interrupt Manager](#interrupt-manager)
5. [HAL Drivers](#hal-drivers)
   - [LED](#led)
   - [BUTTON](#button)
   - [MOTOR](#motor)
   - [SENSOR](#sensor)
6. [APP Layer](#app-layer)
7. [MSSP Mode Guard (SPI vs I2C)](#mssp-mode-guard)
8. [Register Address Map](#register-address-map)
9. [Adding a New Driver](#adding-a-new-driver)

---

## Architecture

The project enforces a strict four-layer dependency hierarchy:

```
┌─────────────────────────────┐
│            APP              │  Application logic & driver tests
├─────────────────────────────┤
│            HAL              │  Hardware Abstraction (LED, BUTTON, MOTOR, SENSOR)
├─────────────────────────────┤
│           MCAL              │  Microcontroller Abstraction (GPIO, USART, ADC, …)
├─────────────────────────────┤
│         SERVICES            │  Shared types & macros (no MCU code)
└─────────────────────────────┘
```

| Rule | Detail |
|------|--------|
| Upper layers include lower layers | APP → HAL → MCAL → SERVICES |
| Lower layers **never** include upper layers | MCAL must not include HAL headers |
| `_private.h` is **only** included by the owning `.c` file | No other file may include it |
| Register access lives **exclusively** in MCAL `.c` files | HAL and APP touch no registers |
| All register definitions use volatile pointer casts | No compiler built-in SFR names |
| All bit manipulation uses `BIT_MATH.h` macros | No raw `|=`, `&=` in driver code |
| All types use `STD_TYPES.h` | No `unsigned char`, `int`, etc. |

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
│   ├── MSSP_config.h        # Shared SPI/I2C mode guard
│   ├── GPIO/
│   │   ├── GPIO_private.h   # Register addresses (volatile pointer macros)
│   │   ├── GPIO_config.h    # Compile-time port defaults
│   │   ├── GPIO_interface.h # Public API — include this in other layers
│   │   └── GPIO.c
│   ├── EXT_INT/             # External interrupt on RB0
│   ├── TIMER_0/             # 8-bit Timer0 with overflow interrupt
│   ├── USART/               # Async UART (TX polling, RX interrupt-driven)
│   ├── ADC/                 # 10-bit ADC, channels AN0–AN7
│   ├── PWM/                 # CCP1 PWM output on RC2 (Timer2)
│   ├── SPI/                 # MSSP SPI Master (RC3/RC4/RC5)
│   ├── I2C/                 # MSSP I2C Master 100 kHz (RC3/RC4)
│   └── INTERRUPT_MANAGER/
│       └── Interrupt_Manager.c   # Single interrupt() dispatcher
│
├── HAL/
│   ├── LED/
│   ├── BUTTON/
│   ├── MOTOR/
│   └── SENSOR/
│
└── APP/
    ├── main.c               # Calls one test entry-point per driver
    ├── gpio_test.c / .h
    ├── ext_int_test.c / .h
    ├── timer0_test.c / .h
    ├── uart_test.c / .h
    ├── adc_test.c / .h
    ├── pwm_test.c / .h
    ├── spi_test.c / .h
    └── i2c_test.c / .h
```

Each MCAL driver follows the same **4-file pattern**:

| File | Purpose |
|------|---------|
| `DRIVER_private.h` | Register address macros only. Never included outside the driver's `.c`. |
| `DRIVER_config.h` | User-tunable compile-time options (prescalers, baud rates, etc.). |
| `DRIVER_interface.h` | **The only public header.** Functions, constants, typedefs. No private details. |
| `DRIVER.c` | Implementation. Includes all three headers above plus SERVICES. |

---

## SERVICES Layer

### `STD_TYPES.h`

| Type | C equivalent |
|------|-------------|
| `u8` | `unsigned char` |
| `u16` | `unsigned short int` |
| `u32` | `unsigned long int` |
| `s8` | `signed char` |
| `s16` | `signed short int` |
| `s32` | `signed long int` |
| `f32` | `float` |
| `NULL_PTR` | `(void*)0` |

### `BIT_MATH.h`

| Macro | Effect |
|-------|--------|
| `SET_BIT(REG, BIT)` | `REG \|= (1U << BIT)` |
| `CLR_BIT(REG, BIT)` | `REG &= ~(1U << BIT)` |
| `TOG_BIT(REG, BIT)` | `REG ^= (1U << BIT)` |
| `GET_BIT(REG, BIT)` | `((REG >> BIT) & 1U)` |

---

## MCAL Drivers

### GPIO

Controls the five I/O ports (A–E) of the PIC16F877A via TRIS and PORT registers.

**Include:** `MCAL/GPIO/GPIO_interface.h`

#### API

```c
void GPIO_Init(void);
void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8   GPIO_GetPinValue(u8 Port, u8 Pin);
```

#### Constants

| Constant | Value | Meaning |
|----------|-------|---------|
| `GPIO_PORTA` … `GPIO_PORTE` | 0–4 | Port identifiers |
| `GPIO_PIN0` … `GPIO_PIN7` | 0–7 | Pin identifiers |
| `GPIO_OUTPUT` | 0 | Direction = output |
| `GPIO_INPUT` | 1 | Direction = input |
| `GPIO_LOW` | 0 | Logic low |
| `GPIO_HIGH` | 1 | Logic high |

#### Configuration (`GPIO_config.h`)

| Option | Default | Meaning |
|--------|---------|---------|
| `GPIO_PORTA_DIR` | `0x00` | TRISA initial value (0=output) |
| `GPIO_PORTB_DIR` | `0xFF` | TRISB initial value (1=input) |
| `GPIO_PORTA_INIT_VAL` | `0x00` | PORTA initial output value |
| `GPIO_PORTB_INIT_VAL` | `0x00` | PORTB initial output value |

`GPIO_Init()` applies only PORTA and PORTB defaults. Call `GPIO_SetPinDirection()` for other ports.

#### Example

```c
GPIO_Init();
GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN3, GPIO_OUTPUT);
GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN3, GPIO_HIGH);
```

---

### EXT_INT

Manages the RB0/INT external interrupt with configurable edge and callback.

**Include:** `MCAL/EXT_INT/EXT_INT_Interface.h`

#### API

```c
void EXT_INT_Init(void);
void EXT_INT_Enable(void);
void EXT_INT_Disable(void);
void EXT_INT_SetEdge(u8 EdgeType);          /* EXT_INT_RISING_EDGE / EXT_INT_FALLING_EDGE */
void EXT_INT_SetCallback(void (*Callback)(void));
void EXT_INT_ISR(void);                     /* Called from Interrupt_Manager */
```

#### Configuration (`EXT_INT_Config.h`)

| Option | Default | Meaning |
|--------|---------|---------|
| `EXT_INT_PORT` | `GPIO_PORTB` | Interrupt pin port |
| `EXT_INT_PIN` | `GPIO_PIN0` | Interrupt pin number |

#### Example

```c
static void my_isr(void) { /* react to edge */ }

EXT_INT_Init();
EXT_INT_SetEdge(EXT_INT_FALLING_EDGE);
EXT_INT_SetCallback(my_isr);
EXT_INT_Enable();
```

---

### TIMER_0

8-bit overflow timer with configurable prescaler and preload. Fires an interrupt on every overflow and reloads the preload value automatically.

**Include:** `MCAL/TIMER_0/TIMER_0_Interface.h`

#### API

```c
void TIMER0_Init(void);
void TIMER0_Start(void);
void TIMER0_Stop(void);
void TIMER0_SetPreload(u8 Preload);
void TIMER0_SetCallback(void (*Callback)(void));
void TIMER0_ISR(void);                    /* Called from Interrupt_Manager */
```

#### Configuration (`TIMER_0_Config.h`)

| Option | Default | Meaning |
|--------|---------|---------|
| `TIMER0_PS_BITS` | `0x07` | Prescaler bits written to OPTION_REG PS2:PS0 (111 = 1:256) |
| `TIMER0_DEFAULT_PRELOAD` | `0x00` | TMR0 reload value after each overflow |

**Overflow period formula:**

```
T_overflow = 4 × Prescaler × (256 − Preload) / Fosc
```

With defaults (PS=256, Preload=0, Fosc=4 MHz): **T = 65.536 ms**

| `TIMER0_PS_BITS` | Prescaler | Period (Preload=0) |
|------------------|-----------|--------------------|
| `0x00` | 1:2 | 0.512 ms |
| `0x01` | 1:4 | 1.024 ms |
| `0x02` | 1:8 | 2.048 ms |
| `0x03` | 1:16 | 4.096 ms |
| `0x04` | 1:32 | 8.192 ms |
| `0x05` | 1:64 | 16.384 ms |
| `0x06` | 1:128 | 32.768 ms |
| `0x07` | 1:256 | **65.536 ms** |

#### Example

```c
static void tick(void) { /* runs every ~65 ms */ }

TIMER0_Init();
TIMER0_SetPreload(0x00);
TIMER0_SetCallback(tick);
TIMER0_Start();
```

---

### USART

Asynchronous UART at 9600 baud (configurable). TX is polling-based; RX is interrupt-driven via callback.

**Include:** `MCAL/USART/USART_Interface.h`

**Pins:** RC6 = TX, RC7 = RX (configured automatically by enabling the serial port)

#### API

```c
void UART_TX_Init(void);
void UART_RX_Init(void);
void UART_Write(u8 Data);
u8   UART_Read(void);        /* Blocking poll */
u8   UART_TX_Empty(void);    /* Returns 1 if TX shift register is empty */
void UART_SetCallback(void (*Callback)(u8));
void UART_ISR(void);         /* Called from Interrupt_Manager */
```

#### Configuration (`USART_Config.h`)

| Option | Default | Meaning |
|--------|---------|---------|
| `FOSC` | `4000000` | CPU frequency in Hz |
| `UART_BAUDRATE` | `9600` | Target baud rate |
| `UART_HIGH_SPEED` | `1` | BRGH bit (1 = high speed) |

**SPBRG calculation (BRGH=1):** `SPBRG = Fosc / (16 × Baud) − 1`  
At 4 MHz / 9600: `SPBRG = 25` → actual baud = 9615 (0.16% error)

#### Example

```c
static void on_rx(u8 data) { UART_Write(data); }  /* echo */

UART_TX_Init();
UART_RX_Init();
UART_SetCallback(on_rx);
UART_Write('H');
UART_Write('i');
```

---

### ADC

10-bit successive-approximation ADC. Channels AN0–AN7 map to PORTA and PORTE pins. Result is right-justified (bits 9:0 in ADRESH:ADRESL).

**Include:** `MCAL/ADC/ADC_interface.h`

**Pins used as inputs:** AN0=RA0, AN1=RA1, AN2=RA2, AN3=RA3, AN4=RA5, AN5=RE0, AN6=RE1, AN7=RE2

#### API

```c
void ADC_Init(void);
u16  ADC_Read(u8 Channel);   /* Returns 0–1023 */
```

#### Channel Constants

`ADC_CH0` … `ADC_CH7` (values 0–7)

#### Configuration (`ADC_config.h`)

| Option | Default | Meaning |
|--------|---------|---------|
| `ADC_ADCS2`, `ADC_ADCS1`, `ADC_ADCS0` | `0, 0, 1` | ADC clock = Fosc/8 → Tad = 2 µs (meets min 1.6 µs) |
| `ADC_RESULT_RIGHT_JUSTIFIED` | `1` | 1 = right-justified 10-bit result |
| `ADC_PCFG` | `0x00` | ADCON1 PCFG bits: `0000` = all AN0–AN7 analog |

**ADC clock selection:**

| ADCS\<2:0\> | Clock | Tad @ 4 MHz | OK? |
|-------------|-------|-------------|-----|
| `000` | Fosc/2 | 0.5 µs | No (min 1.6 µs) |
| **`001`** | **Fosc/8** | **2.0 µs** | **Yes (default)** |
| `010` | Fosc/32 | 8.0 µs | Yes |
| `011` | FRC | ~4 µs | Yes |

#### Example

```c
ADC_Init();
u16 raw = ADC_Read(ADC_CH0);   /* 0 = 0 V, 1023 = Vref+ */
```

---

### PWM

CCP1 PWM output on **RC2**. Uses Timer2 as the timebase. Duty cycle is specified in per-mille (0–1000), which gives 0.1% resolution.

**Include:** `MCAL/PWM/PWM_interface.h`

**Output pin:** RC2 / CCP1

#### API

```c
void PWM_Init(void);
void PWM_SetDutyCycle(u16 DutyCycle);   /* 0 = 0%, 1000 = 100% */
void PWM_Stop(void);
```

#### Configuration (`PWM_config.h`)

| Option | Default | Meaning |
|--------|---------|---------|
| `PWM_PR2_VALUE` | `249` | Timer2 period register (0–255) |
| `PWM_T2_PRESCALER` | `0x00` | T2CKPS\<1:0\>: `00`=1:1, `01`=1:4, `1x`=1:16 |

**PWM frequency formula:**

```
f_PWM = Fosc / (4 × T2_Prescaler × (PR2 + 1))
```

| PR2 | Prescaler | f_PWM @ 4 MHz | 10-bit resolution |
|-----|-----------|---------------|-------------------|
| 249 | 1:1 | **4 kHz** | ~10 bit |
| 249 | 1:4 | 1 kHz | ~10 bit |
| 124 | 1:1 | 8 kHz | ~9 bit |

#### Example

```c
PWM_Init();
PWM_SetDutyCycle(500);    /* 50% duty cycle */
/* ... */
PWM_SetDutyCycle(750);    /* 75% duty cycle */
PWM_Stop();
```

---

### SPI

MSSP in SPI Master mode. Active only when `MSSP_ACTIVE_MODE == MSSP_MODE_SPI` in `MCAL/MSSP_config.h`. When I2C mode is selected, all SPI functions compile as empty stubs.

**Include:** `MCAL/SPI/SPI_interface.h`

**Pins:** SCK=RC3 (output), SDO=RC5 (output), SDI=RC4 (input)  
**SS (chip-select):** managed manually by the application via `GPIO_SetPinValue()`

#### API

```c
void SPI_Init(void);
void SPI_Transmit(u8 Data);
u8   SPI_Receive(void);
void SPI_TransmitReceive(u8 TxData, u8 *RxData);
```

#### Configuration (`SPI_config.h`)

| Option | Default | Meaning |
|--------|---------|---------|
| `SPI_SSPM_BITS` | `0x00` | SSPM\<3:0\>: `0000`=Fosc/4=1 MHz, `0001`=Fosc/16, `0010`=Fosc/64 |
| `SPI_CKP` | `0` | Clock polarity: 0=idle low (mode 0/1) |
| `SPI_CKE` | `1` | Clock edge: 1=transmit on active→idle transition |
| `SPI_SMP` | `0` | Sample point: 0=middle of data output time |

#### Example

```c
/* In MSSP_config.h: #define MSSP_ACTIVE_MODE  MSSP_MODE_SPI */
SPI_Init();
GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);   /* assert SS */
SPI_Transmit(0xA5);
u8 rx = SPI_Receive();
GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);  /* deassert SS */
```

---

### I2C

MSSP in I2C Master mode at 100 kHz. Active only when `MSSP_ACTIVE_MODE == MSSP_MODE_I2C`. When SPI mode is selected, all I2C functions compile as empty stubs.

**Include:** `MCAL/I2C/I2C_interface.h`

**Pins:** SCL=RC3, SDA=RC4 (both open-drain — **external pull-up resistors required**)

#### API

```c
void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_RepeatedStart(void);
u8   I2C_WriteByte(u8 Data);      /* Returns I2C_OK (0) or I2C_NACK (1) */
u8   I2C_ReadByte(u8 SendAck);    /* SendAck: 1=ACK, 0=NACK after read */
```

#### Configuration (`I2C_config.h`)

| Option | Default | Meaning |
|--------|---------|---------|
| `I2C_SSPADD_VALUE` | `9` | SSPADD register: baud = Fosc / (4×(SSPADD+1)) = 100 kHz |
| `I2C_SMP_BIT_VALUE` | `1` | Slew rate: 1=disabled (100 kHz mode) |

**SSPADD values:**

| SSPADD | Baud rate @ 4 MHz |
|--------|------------------|
| 9 | **100 kHz** |
| 4 | 200 kHz |

#### Example

```c
/* In MSSP_config.h: #define MSSP_ACTIVE_MODE  MSSP_MODE_I2C */
I2C_Init();

I2C_Start();
if (I2C_WriteByte(0xA0) == I2C_OK)   /* slave addr + write */
{
    I2C_WriteByte(0x00);              /* register address */
    I2C_WriteByte(0x42);              /* data */
}
I2C_Stop();
```

---

### Interrupt Manager

`MCAL/INTERRUPT_MANAGER/Interrupt_Manager.c` contains the single `interrupt()` function that dispatches to all driver ISRs. Each ISR checks its own flag register internally before executing — the dispatcher calls all of them unconditionally.

```c
void interrupt(void)
{
    UART_ISR();       /* checks PIR1.RCIF */
    EXT_INT_ISR();    /* checks INTCON.INTF */
    TIMER0_ISR();     /* checks INTCON.TMR0IF */
}
```

**To add a new interrupt source:**
1. Implement `NEWDRIVER_ISR(void)` in the driver's `.c` file, declared in its `_interface.h`.
2. Add `NEWDRIVER_ISR();` to `Interrupt_Manager.c`.

---

## HAL Drivers

HAL drivers build on MCAL APIs. They never access registers directly.

---

### LED

Controls a single LED connected to any GPIO pin.

**Include:** `HAL/LED/LED_interface.h`

```c
void LED_Init(u8 Port, u8 Pin);
void LED_On(u8 Port, u8 Pin);
void LED_Off(u8 Port, u8 Pin);
void LED_Toggle(u8 Port, u8 Pin);
```

**Example:**
```c
LED_Init(GPIO_PORTB, GPIO_PIN0);
LED_On(GPIO_PORTB, GPIO_PIN0);
LED_Toggle(GPIO_PORTB, GPIO_PIN0);
```

---

### BUTTON

Reads a push-button with configurable active level (active-low by default).

**Include:** `HAL/BUTTON/BUTTON_interface.h`

```c
void BUTTON_Init(u8 Port, u8 Pin);
u8   BUTTON_Read(u8 Port, u8 Pin);   /* Returns BUTTON_PRESSED or BUTTON_RELEASED */
```

#### Configuration (`BUTTON_config.h`)

| Option | Default | Meaning |
|--------|---------|---------|
| `BUTTON_LOGIC` | `BUTTON_ACTIVE_LOW` | Active-low: pin pulled to GND when pressed |

**Example:**
```c
BUTTON_Init(GPIO_PORTB, GPIO_PIN1);
if (BUTTON_Read(GPIO_PORTB, GPIO_PIN1) == BUTTON_PRESSED)
{
    LED_On(GPIO_PORTB, GPIO_PIN0);
}
```

---

### MOTOR

Controls a DC motor via an H-bridge (e.g. L293D). Direction is set with two GPIO pins; speed is controlled through the PWM driver (CCP1/RC2).

**Include:** `HAL/MOTOR/MOTOR_interface.h`

```c
void MOTOR_Init(void);
void MOTOR_SetDirection(u8 Direction);   /* MOTOR_CW or MOTOR_CCW */
void MOTOR_SetSpeed(u16 SpeedPermille);  /* 0–1000 */
void MOTOR_Stop(void);
```

#### Configuration (`MOTOR_config.h`)

| Option | Default | Meaning |
|--------|---------|---------|
| `MOTOR_IN1_PORT/PIN` | RC0 | H-bridge IN1 pin |
| `MOTOR_IN2_PORT/PIN` | RC1 | H-bridge IN2 pin |

Speed is routed to `PWM_SetDutyCycle()` — configure frequency in `PWM_config.h`.

**Example:**
```c
MOTOR_Init();
MOTOR_SetDirection(MOTOR_CW);
MOTOR_SetSpeed(600);    /* 60% speed */
/* ... */
MOTOR_Stop();
```

---

### SENSOR

Generic analog sensor wrapper around the ADC driver. Returns a raw 10-bit value (0–1023).

**Include:** `HAL/SENSOR/SENSOR_interface.h`

```c
void SENSOR_Init(u8 Channel);
u16  SENSOR_Read(u8 Channel);   /* Returns 0–1023 */
```

#### Configuration (`SENSOR_config.h`)

| Option | Default | Meaning |
|--------|---------|---------|
| `SENSOR_DEFAULT_CHANNEL` | `0` | Default ADC channel (AN0) |

**Example:**
```c
SENSOR_Init(ADC_CH0);
u16 val = SENSOR_Read(ADC_CH0);
/* val * 5000 / 1023 gives millivolts if Vref+ = 5 V */
```

---

## APP Layer

Each driver has a dedicated test file with a single entry-point function:

| File | Entry point | Tests |
|------|-------------|-------|
| `gpio_test.c` | `gpio_test_run()` | Direction, read, write |
| `ext_int_test.c` | `ext_int_test_run()` | Falling-edge callback |
| `timer0_test.c` | `timer0_test_run()` | Overflow callback, preload |
| `uart_test.c` | `uart_test_run()` | TX string, RX echo callback |
| `adc_test.c` | `adc_test_run()` | Read AN0, threshold GPIO |
| `pwm_test.c` | `pwm_test_run()` | 25/50/75% duty ramp |
| `spi_test.c` | `spi_test_run()` | Transmit, receive, full-duplex |
| `i2c_test.c` | `i2c_test_run()` | Write/read to 0x50 EEPROM |

`main.c` calls all test entry-points in order then sits in `while(1)`:

```c
int main(void)
{
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

## MSSP Mode Guard

The MSSP peripheral is shared between SPI and I2C (both use RC3 and RC4). Only one can be active in a given firmware build.

Edit **`MCAL/MSSP_config.h`**:

```c
#define MSSP_ACTIVE_MODE   MSSP_MODE_SPI   /* or MSSP_MODE_I2C */
```

- When `MSSP_MODE_SPI`: `SPI.c` compiles the full implementation; `I2C.c` compiles empty stubs.
- When `MSSP_MODE_I2C`: `I2C.c` compiles the full implementation; `SPI.c` compiles empty stubs.

Both `.c` files must still be included in the build — the preprocessor handles exclusion.

---

## Register Address Map

All addresses refer to PIC16F877A data memory (no banking emulation needed with volatile pointer macros).

| Register | Address | Bank | Driver |
|----------|---------|------|--------|
| TMR0 | 0x01 | 0 | TIMER_0 |
| PORTA | 0x05 | 0 | GPIO |
| PORTB | 0x06 | 0 | GPIO |
| PORTC | 0x07 | 0 | GPIO |
| PORTD | 0x08 | 0 | GPIO |
| PORTE | 0x09 | 0 | GPIO |
| INTCON | 0x0B | 0/1 | EXT_INT, TIMER_0, USART |
| PIR1 | 0x0C | 0 | USART |
| TMR2 | 0x11 | 0 | PWM |
| T2CON | 0x12 | 0 | PWM |
| SSPBUF | 0x13 | 0 | SPI, I2C |
| SSPCON | 0x14 | 0 | SPI, I2C |
| CCPR1L | 0x15 | 0 | PWM |
| CCPR1H | 0x16 | 0 | PWM |
| CCP1CON | 0x17 | 0 | PWM |
| RCSTA | 0x18 | 0 | USART |
| TXREG | 0x19 | 0 | USART |
| RCREG | 0x1A | 0 | USART |
| ADRESH | 0x1E | 0 | ADC |
| ADCON0 | 0x1F | 0 | ADC |
| OPTION_REG | 0x81 | 1 | EXT_INT, TIMER_0 |
| TRISA | 0x85 | 1 | GPIO |
| TRISB | 0x86 | 1 | GPIO |
| TRISC | 0x87 | 1 | GPIO |
| TRISD | 0x88 | 1 | GPIO |
| TRISE | 0x89 | 1 | GPIO |
| PIE1 | 0x8C | 1 | USART |
| SSPCON2 | 0x91 | 1 | I2C |
| PR2 | 0x92 | 1 | PWM |
| SSPADD | 0x93 | 1 | I2C |
| SSPSTAT | 0x94 | 1 | SPI, I2C |
| TXSTA | 0x98 | 1 | USART |
| SPBRG | 0x99 | 1 | USART |
| ADRESL | 0x9E | 1 | ADC |
| ADCON1 | 0x9F | 1 | ADC |

---

## Adding a New Driver

1. Create `MCAL/NEWDRV/` with the 4-file pattern.
2. Define register addresses **only** in `NEWDRV_private.h` using `(*((volatile u8*)0xADDR))`.
3. Expose only the public API in `NEWDRV_interface.h` — no register names, no private includes.
4. Use `SET_BIT`/`CLR_BIT`/`GET_BIT` from `BIT_MATH.h` for all bit operations in the `.c`.
5. If the driver uses an interrupt, declare `NEWDRV_ISR(void)` in `_interface.h`, implement it with a self-check of the flag, and add a call in `Interrupt_Manager.c`.
6. Create `APP/newdrv_test.c` and `newdrv_test.h` with a single `newdrv_test_run()` entry point.
7. Add `newdrv_test_run()` to `APP/main.c`.
