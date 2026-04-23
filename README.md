# ES Course Labs - Embedded Systems Drivers

A comprehensive embedded systems project implementing hardware abstraction and microcontroller abstraction layers (HAL/MCAL) for the **PIC16F877A** microcontroller. This project demonstrates professional embedded systems architecture with layered driver implementations.

## Table of Contents

- [Project Overview](#project-overview)
- [Hardware Details](#hardware-details)
- [Project Architecture](#project-architecture)
- [Drivers & Register Definitions](#drivers--register-definitions)
  - [GPIO (General Purpose I/O)](#gpio-general-purpose-io)
  - [UART (Serial Communication)](#uart-serial-communication)
  - [ADC (Analog-to-Digital Converter)](#adc-analog-to-digital-converter)
  - [PWM (Pulse Width Modulation)](#pwm-pulse-width-modulation)
  - [Interrupt Management](#interrupt-management)
  - [Timer (TIMER0)](#timer0)
  - [SPI & I2C (Serial Protocols)](#spi--i2c)
- [Building the Project](#building-the-project)
- [Usage Examples](#usage-examples)
- [File Structure](#file-structure)

## Project Overview

This project provides a complete firmware implementation for the PIC16F877A microcontroller with the following features:

- **Layered Architecture**: Separation of concerns using HAL (Hardware Abstraction Layer) and MCAL (Microcontroller Abstraction Layer)
- **LED Control**: GPIO-based LED management with on/off/toggle operations
- **ADC Sampling**: 10-bit analog input conversion with interrupt-driven callbacks
- **PWM Output**: Duty cycle control synchronized with ADC input
- **Serial Communication**: UART-based command interface at 9600 baud
- **Timer-based Events**: TIMER0 overflow interrupt for periodic LED toggling
- **Button Input**: External interrupt handling for user input

## Hardware Details

**Microcontroller**: PIC16F877A
- **Architecture**: 8-bit RISC
- **Clock**: 4 MHz (FOSC = 4000000 Hz)
- **Flash Memory**: 8 KB (Program Memory)
- **RAM**: 368 bytes (Data Memory)
- **EEPROM**: 256 bytes (Data Storage)
- **Pin Count**: 40-pin DIP package

### Available I/O Ports

- **PORT A** (Base: 0x05, TRISA: 0x85) - 6 I/O pins
- **PORT B** (Base: 0x06, TRISB: 0x86) - 8 I/O pins
- **PORT C** (Base: 0x07, TRISC: 0x87) - 8 I/O pins
- **PORT D** (Base: 0x08, TRISD: 0x88) - 8 I/O pins
- **PORT E** (Base: 0x09, TRISE: 0x89) - 3 I/O pins

Each port has a corresponding TRIS register for direction control (0 = Output, 1 = Input).

## Project Architecture

```
├── APP/                          # Application Layer
│   └── main.c                   # Main application logic
├── HAL/                          # Hardware Abstraction Layer
│   └── LED/                     # LED driver (GPIO wrapper)
├── MCAL/                         # Microcontroller Abstraction Layer
│   ├── GPIO/                    # Port I/O driver
│   ├── UART/                    # Serial communication driver
│   ├── ADC/                     # Analog converter driver
│   ├── PWM/                     # Pulse width modulation driver
│   ├── TIMER0/                  # 8-bit timer driver
│   ├── SPI/                     # Serial peripheral interface
│   ├── I2C/                     # Inter-integrated circuit
│   ├── INT/                     # External interrupt handler
│   └── INT_Manager/             # Global interrupt manager
└── SERVICES/                     # Utility Libraries
    ├── STD_TYPES.h              # Standard type definitions
    └── BIT_MATH.h               # Bit manipulation macros
```

## Drivers & Register Definitions

### GPIO (General Purpose I/O)

**Driver Location**: `MCAL/GPIO/GPIO.c`

**Register Definitions**:
```c
// Data Direction Registers (1 = Input, 0 = Output)
TRISA   0x85
TRISB   0x86
TRISC   0x87
TRISD   0x88
TRISE   0x89

// Port Registers (Read/Write data)
PORTA   0x05
PORTB   0x06
PORTC   0x07
PORTD   0x08
PORTE   0x09
```

**Key Functions**:
- `GPIO_SetPinDirection(Port, Pin, Direction)` - Configure pin as input/output
- `GPIO_SetPinValue(Port, Pin, Value)` - Set pin HIGH or LOW
- `GPIO_ReadPinValue(Port, Pin)` - Read pin state

**Behavior**: The driver uses bit manipulation to set/clear individual bits in TRIS registers for direction control and port registers for value manipulation.

### UART (Serial Communication)

**Driver Location**: `MCAL/UART/UART.c`

**Register Definitions**:
```c
// Data Registers
TXREG   0x19    // Transmit Register (Write)
RCREG   0x1A    // Receive Register (Read)
SPBRG   0x99    // Baud Rate Generator

// Control Registers
RCSTA   0x18    // Receive Status & Control
TXSTA   0x98    // Transmit Status & Control

// Interrupt Registers
PIR1    0x0C    // Peripheral Interrupt Request (bit 5=RCIF, bit 4=TXIF)
PIE1    0x8C    // Peripheral Interrupt Enable (bit 5=RCIE, bit 4=TXIE)
INTCON  0x0B    // Interrupt Control (bit 6=PEIE)

// RCSTA Bits
RX9D, OERR, FERR, ADDEN, CREN(4), SREN, RX9, SPEN(7)

// TXSTA Bits
TX9D, TRMT, BRGH, SENDB, TX9(6), TXEN(5), SYNC
```

**Configuration**:
- **Baud Rate**: 9600 baud
- **Data Bits**: 8-bit
- **Stop Bits**: 1
- **Parity**: None
- **Interrupt-driven**: RX and TX with callback functions

**SPBRG Calculation** (16-bit mode):
```
SPBRG = (FOSC / (16 * Baud)) - 1
SPBRG = (4000000 / (16 * 9600)) - 1 ≈ 25
```

**Available Commands** (via UART_RX_Callback):
- `'1'` - LED ON
- `'0'` - LED OFF
- `'T'` - LED TOGGLE
- `'A'` - Read ADC value (2-byte response: HIGH, LOW)
- `'P'` - Read PWM duty cycle

### ADC (Analog-to-Digital Converter)

**Driver Location**: `MCAL/ADC/ADC.c`

**Register Definitions**:
```c
// Control Registers
ADCON0 0x1F    // ADC Control Register 0
ADCON1 0x9F    // ADC Control Register 1

// Result Registers
ADRESH 0x1E    // ADC Result High byte
ADRESL 0x9E    // ADC Result Low byte (right-justified)

// Interrupt Registers
PIR1   0x0C    // bit 6 = ADIF (Conversion Complete)
PIE1   0x8C    // bit 6 = ADIE (ADC Interrupt Enable)
INTCON 0x0B    // bit 6 = PEIE (Peripheral Interrupt Enable)

// ADCON0 Bits
ADON(0), GO(2), CHS0(3), CHS1(4), CHS2(5), ADCS0(6), ADCS1(7)

// ADCON1 Bits
PCFG0, PCFG1, PCFG2, PCFG3(3)
```

**Configuration**:
- **Resolution**: 10-bit (0-1023 digital value)
- **Channels**: Multiple analog inputs selectable via CHS bits
- **Conversion Trigger**: Software-initiated via GO bit
- **Interrupt-driven**: ADC_Conversion_Complete_Callback triggered on completion

**ADC Clock**: Determined by ADCS bits (clock = FOSC/4, /8, /16, or /32)

**Behavior**:
1. Channel selection via CHS0, CHS1, CHS2 bits in ADCON0
2. START conversion by setting GO bit (ADCON0.2)
3. Hardware clears GO bit when conversion complete
4. ADIF flag set, interrupt triggered if enabled
5. Result available in ADRESH:ADRESL registers

### PWM (Pulse Width Modulation)

**Driver Location**: `MCAL/PWM/PWM.c`

**Register Definitions**:
```c
// PWM Compare Registers
CCPR1L 0x15    // PWM Channel 1 (CCP1) Duty Cycle
CCPR2L 0x1B    // PWM Channel 2 (CCP2) Duty Cycle

// PWM Control Registers
CCP1CON 0x17   // CCP1 Control (PWM mode selection)
CCP2CON 0x1D   // CCP2 Control (PWM mode selection)

// Timer2 Registers
PR2    0x92    // Period Register
T2CON  0x12    // Timer2 Control
TMR2   0x11    // Timer2 Counter

// CCP Control Bits
CCP1M0, CCP1M1(1), CCP1M2(2), CCP1M3(3)  // Mode select (1100 = PWM)

// T2CON Bits
TMR2ON(2), TCKPS0(4), TCKPS1(5), TOUTPS0(3), TOUTPS1(4), TOUTPS2(5), TOUTPS3(6)
```

**Frequency Configuration**:
```
PWM Frequency = FOSC / (4 * PR2 * Prescalar)
PWM Frequency = 4000000 / (4 * PR2 * Prescalar)
```

**Duty Cycle Calculation**:
```
Duty Cycle (%) = (CCPR1L / (4 * PR2)) * 100
```

**Application Example**: 
- ADC input (0-1023) is scaled to PWM duty cycle (0-100%)
- `PWMDutyCycle = (ADCValue * 100) / 1024`
- Updated via `PWM_SetDutyCycle(PWM_CHANNEL1, DutyCycle)`

### TIMER0

**Driver Location**: `MCAL/TIMER0/TIMER0.c`

**Features**:
- 8-bit timer/counter with programmable prescaler
- Interrupt on overflow
- Callback mechanism for periodic events

**Application**: TIMER0 overflow interrupt triggers every ~5 overflows to toggle LED on PORTB.PIN0

### SPI & I2C

**Drivers Located**: `MCAL/SPI/SPI.c`, `MCAL/I2C/I2C.c`

Complete implementations of Serial Peripheral Interface and Inter-Integrated Circuit protocols for sensor and peripheral communication.

### Interrupt Management

**Driver Locations**: 
- `MCAL/INT/INT.c` - External interrupt (INT0 on RB0)
- `MCAL/INT_Manager/INT_Manager.c` - Global interrupt management

**INTCON Register** (0x0B):
- Bit 7: GIE (Global Interrupt Enable)
- Bit 6: PEIE (Peripheral Interrupt Enable)
- Bit 4: INT0IE (External Interrupt 0 Enable)
- Bit 3: INT0IF (External Interrupt 0 Flag)

**Behavior**: Button press on RB0 triggers external interrupt → calls `Button_Pressed_Callback()` → sends message via UART and toggles LED.

## Building the Project

### Prerequisites

- **XC8 Compiler**: Microchip XC8 C Compiler
- **DFP (Device Family Package)**: PIC16Fxxx_DFP v1.7.162 or compatible
- **GNU Make**: Build automation tool

### Build Configuration

```makefile
MCU = 16F877A
CC = xc8-cc
DFP = /opt/microchip/PIC16Fxxx_DFP/1.7.162/xc8
TARGET = app
```

### Build Commands

```bash
# Compile and link all source files
make

# Clean build artifacts
make clean

# Flash to device (using programmer)
make program
```

### Output Files

- `app.elf` - Executable ELF file
- `app.hex` - Intel HEX format (for programmers)
- `app.sym` - Symbol table
- `*.o` - Object files
- `*.d` - Dependency files
- `*.p1` - Intermediate files

## Usage Examples

### Basic LED Operations (via UART)

```
Send: '1'     → Receive: "LED ON\r\n"      (Sets PORTB.PIN0 HIGH)
Send: '0'     → Receive: "LED OFF\r\n"     (Sets PORTB.PIN0 LOW)
Send: 'T'     → Receive: "LED TOGGLE\r\n"  (Toggles PORTB.PIN0 state)
```

### ADC Reading (via UART)

```
Send: 'A'     → Receive: [HIGH_BYTE, LOW_BYTE]
               Both bytes of 10-bit ADC result from ADRESH and ADRESL
```

### PWM Duty Cycle Status (via UART)

```
Send: 'P'     → Receive: [DUTY_CYCLE]
               Current PWM duty cycle (0-100) as single byte
```

### Real-Time Operation

1. **ADC → PWM Pipeline**: ADC samples analog input, triggers interrupt, callback updates PWM duty cycle
2. **Button Input**: External interrupt on button press sends "Button Pressed!\r\n" via UART
3. **Timer Events**: TIMER0 overflow every ~5 counts toggles LED automatically
4. **Serial Control**: UART commands override automatic control

## File Structure

```
ES_Course_Labs/
├── APP/
│   └── main.c                          # Application entry point
├── HAL/
│   └── LED/
│       ├── LED.c                       # LED driver implementation
│       ├── LED_interface.h             # Public LED API
│       ├── LED_config.h                # LED configuration
│       └── LED_private.h               # Internal register definitions
├── MCAL/
│   ├── GPIO/
│   │   ├── GPIO.c, GPIO_interface.h, GPIO_config.h, GPIO_private.h
│   ├── UART/
│   │   ├── UART.c, UART_interface.h, UART_config.h, UART_private.h
│   ├── ADC/
│   │   ├── ADC.c, ADC_interface.h, ADC_config.h, ADC_private.h
│   ├── PWM/
│   │   ├── PWM.c, PWM_interface.h, PWM_config.h, PWM_private.h
│   ├── TIMER0/
│   │   ├── TIMER0.c, TIMER0_interface.h, TIMER0_config.h, TIMER0_private.h
│   ├── SPI/
│   │   ├── SPI.c, SPI_interface.h, SPI_config.h, SPI_private.h
│   ├── I2C/
│   │   ├── I2C.c, I2C_interface.h, I2C_config.h, I2C_private.h
│   ├── INT/
│   │   ├── INT.c, INT_interface.h, INT_config.h, INT_private.h
│   └── INT_Manager/
│       ├── INT_Manager.c, INT_Manager.h
├── SERVICES/
│   ├── STD_TYPES.h                     # Type definitions (u8, u16, etc.)
│   └── BIT_MATH.h                      # Bit manipulation macros
├── Makefile                            # Build configuration
└── README.md                           # This file
```

## Architecture Notes

**Standard Type Definitions** (SERVICES/STD_TYPES.h):
- `u8` - Unsigned 8-bit integer
- `u16` - Unsigned 16-bit integer
- `s8`, `s16` - Signed variants

**Bit Math Macros** (SERVICES/BIT_MATH.h):
- `SET_BIT(var, bit)` - Set bit N
- `CLR_BIT(var, bit)` - Clear bit N
- `TOG_BIT(var, bit)` - Toggle bit N
- `GET_BIT(var, bit)` - Read bit N

This three-layer architecture (APP/HAL/MCAL) provides:
✓ Hardware independence for upper layers
✓ Easy testing and porting
✓ Clear responsibility separation
✓ Reusable driver implementations

## License & References

PIC16F877A Datasheet: [Microchip Official Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/39582b.pdf)

---

**Author**: Embedded Systems Course - Lab Implementation
**Device**: PIC16F877A @ 4 MHz
**Last Updated**: 2026
