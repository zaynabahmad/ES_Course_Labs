# PIC16F877 Peripheral Drivers
**Based on Microchip DS30292C Datasheet**  
Toolchain: MPLAB XC8 (compatible with HI-TECH PICC with minor edits)  
Crystal: 4 MHz (all timing calculations reference this)

---

## Layered Architecture

| Layer | Purpose | Contents |
|-------|---------|----------|
| **APPLICATION** | User application logic, callbacks | `main.c` |
| **HAL** | Higher-level device drivers | *(placeholder for LCD, sensors, motors, etc.)* |
| **COMMON** | Shared utilities, ISR dispatcher | `isr.c` |
| **MCAL** | Direct HW register access | GPIO, EXTI, Timer0, PWM, ADC, UART, SPI, I2C |

## Project Structure

```
pic16f877_drivers/
├── MCAL/
│   ├── GPIO/        gpio.h, gpio.c
│   ├── EXTI/        exti.h, exti.c
│   ├── Timer0/      timer0.h, timer0.c
│   ├── PWM/         pwm.h, pwm.c
│   ├── ADC/         adc.h, adc.c
│   ├── UART/        uart.h, uart.c
│   ├── SPI/         spi.h, spi.c
│   └── I2C/         i2c.h, i2c.c
├── HAL/
│   ├── LED/         led.h, led.c
│   ├── SWITCH/      switch.h, switch.c
│   ├── DC_MOTOR/    dc_motor.h, dc_motor.c
│   └── LM35/        lm35.h, lm35.c
├── COMMON/
│   └── ISR/         isr.c  ← Single unified ISR (include ONCE)
├── APPLICATION/
│   └── main.c       ← Example usage
└── README.md
```

---

## Include Path Convention

From **APPLICATION** (e.g., `main.c`):
```c
#include "../MCAL/GPIO/gpio.h"
#include "../MCAL/UART/uart.h"
```

From **COMMON/ISR** (e.g., `isr.c`):
```c
#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/EXTI/exti.h"
```

MCAL `.c` files include their own `.h` directly (same directory):
```c
#include "gpio.h"
```

---

## Integration Rules

### 1. ISR — include once
Add `COMMON/ISR/isr.c` to your project. **Do NOT** define any `XXXX_USE_STANDALONE_ISR`
macro when using the unified ISR. If you want each driver's own ISR instead,
define the macro and exclude `isr.c`.

### 2. Interrupt enable sequence
```c
INTCONbits.PEIE = 1;  // Enable peripheral interrupts (ADC, UART, SSP)
INTCONbits.GIE  = 1;  // Enable global interrupts
```
This must be called **after** all peripheral init functions.

### 3. SPI vs I2C — shared pins
SPI and I2C both use RC3 and RC4. Use one at a time; reinitialize if switching.

### 4. ADC pin configuration
Before using ADC, configure ADCON1 (portCfg in ADC_Config_t) to make the
desired pins analog. All other I/O using those pins must be aware of this.

### 5. PWM output pin
CCP1 → RC2 must be set as output (done inside `PWM_Init`).  
CCP2 → RC1 must be set as output (done inside `PWM_Init`).

---

## Quick Reference — Key Init Snippets

### GPIO
```c
#include "../MCAL/GPIO/gpio.h"
GPIO_Config_t led = { GPIO_PORTB, GPIO_PIN1, GPIO_OUTPUT, GPIO_LOW };
GPIO_Init(&led);
GPIO_TogglePin(GPIO_PORTB, GPIO_PIN1);
```

### External Interrupt (RB0)
```c
#include "../MCAL/EXTI/exti.h"
EXTI_INT_Config_t cfg = { EXTI_EDGE_FALLING, EXTI_ENABLE };
EXTI_INT_Init(&cfg);
// Implement: void EXTI_INT_Callback(void) { ... }
```

### Timer0 — 1ms tick at 4MHz
```c
#include "../MCAL/Timer0/timer0.h"
TIMER0_Config_t cfg = {
    TIMER0_CLK_INTERNAL, TIMER0_EDGE_RISING,
    TIMER0_PS_ASSIGNED, TIMER0_PS_DIV8, 131u, TIMER0_INT_ENABLE
};
TIMER0_Init(&cfg);
// Implement: void TIMER0_OVF_Callback(void) { TIMER0_SetPreload(131u); }
```

### PWM — 1kHz at 50% duty, CCP1
```c
#include "../MCAL/PWM/pwm.h"
PWM_Config_t cfg = { PWM_CHANNEL_1, 249u, PWM_PRESCALER_1, PWM_POSTSCALER_1, 512u };
PWM_Init(&cfg);
PWM_SetDutyPercent(PWM_CHANNEL_1, 75u);  // Change to 75%
```

### ADC — blocking read on AN0
```c
#include "../MCAL/ADC/adc.h"
ADC_Config_t cfg = { ADC_CLK_FOSC_8, ADC_JUSTIFY_RIGHT, ADC_PCFG_ALL_ANALOG, ADC_INT_DISABLE };
ADC_Init(&cfg);
uint16_t val = ADC_Read(ADC_CH0);  // 0–1023
```

### UART — 9600 baud
```c
#include "../MCAL/UART/uart.h"
UART_Config_t cfg = { 4000000UL, 9600UL, UART_BRGH_HIGH, UART_DATABITS_8, UART_INT_DISABLE, UART_INT_ENABLE };
UART_Init(&cfg);
UART_SendString("Hello\r\n");
uint8_t b = UART_ReceiveByte();  // blocking
// Implement: void UART_RX_Callback(void) { uint8_t b = UART_ReceiveByte(); }
```

### SPI — Master, MODE0, Fosc/4
```c
#include "../MCAL/SPI/spi.h"
SPI_Config_t cfg = { SPI_MODE_MASTER_FOSC4, SPI_CLOCK_MODE0, SPI_SMP_MIDDLE, SPI_INT_DISABLE };
SPI_Init(&cfg);
uint8_t rx = SPI_TransferByte(0xABu);
```

### I2C — Master, 100kHz
```c
#include "../MCAL/I2C/i2c.h"
I2C_MasterConfig_t cfg = { 4000000UL, 100000UL, I2C_SPEED_100K, I2C_INT_DISABLE };
I2C_Master_Init(&cfg);
uint8_t buf[2];
I2C_Master_WriteRead(0x48u, 0x00u, buf, 2u);  // Read 2 bytes from device 0x48 register 0x00
```

---

## HAL Quick Reference

### LED
```c
#include "../HAL/LED/led.h"
LED_Handle_t led;
LED_Config_t cfg = { GPIO_PORTB, GPIO_PIN1, LED_ACTIVE_HIGH, LED_OFF };
LED_Init(&led, &cfg);
LED_On(&led);
LED_Toggle(&led);
LED_Off(&led);
```

### Switch (with debounce)
```c
#include "../HAL/SWITCH/switch.h"
SWITCH_Handle_t btn;
SWITCH_Config_t cfg = { GPIO_PORTB, GPIO_PIN0, SWITCH_ACTIVE_LOW, SWITCH_PULLUP_ENABLE };
SWITCH_Init(&btn, &cfg);
if (SWITCH_IsPressed(&btn)) { /* ... */ }
SWITCH_State_t s = SWITCH_ReadDebounced(&btn);  // ~20ms blocking debounce
```

### DC Motor (L298/L293 H-bridge)
```c
#include "../HAL/DC_MOTOR/dc_motor.h"
DCMotor_Handle_t motor;
DCMotor_Config_t cfg = {
    GPIO_PORTD, GPIO_PIN0,    /* IN1 */
    GPIO_PORTD, GPIO_PIN1,    /* IN2 */
    PWM_CHANNEL_1,            /* EN via CCP1 */
    1000u,                    /* 1kHz PWM */
    4000000UL                 /* 4MHz crystal */
};
DCMotor_Init(&motor, &cfg);
DCMotor_Forward(&motor, 75u);   // 75% speed forward
DCMotor_Reverse(&motor, 50u);   // 50% speed reverse
DCMotor_Brake(&motor);          // Hard stop
DCMotor_Stop(&motor);           // Coast
```

### LM35 Temperature Sensor
```c
#include "../HAL/LM35/lm35.h"
// ADC must be initialized first via ADC_Init()
LM35_Handle_t sensor;
LM35_Config_t cfg = { ADC_CH0, 5000u };  // AN0, 5V reference
LM35_Init(&sensor, &cfg);

uint16_t tempC   = LM35_ReadTempC(&sensor);      // e.g., 23
uint16_t tempCx10 = LM35_ReadTempCx10(&sensor);  // e.g., 235 → 23.5°C
uint16_t tempF   = LM35_ReadTempF(&sensor);      // e.g., 74
uint16_t mV      = LM35_ReadVoltageMv(&sensor);  // e.g., 235
```

---

## Baud Rate Table (4 MHz crystal, BRGH=1)

| Baud Rate | SPBRG | Error   |
|-----------|-------|---------|
| 9600      | 25    | 0.16%   |
| 19200     | 12    | 0.16%   |
| 38400     | 6     | −6.99%  |
| 57600     | 3     | 8.51%   |
| 115200    | 1     | −18.6%  |

For 57600+ use an 11.0592 MHz crystal for zero error.

---

## Timer0 Preload Table (4 MHz, internal clock)

| Prescaler | Preload | Overflow Period |
|-----------|---------|-----------------|
| /1        | 6       | 250 µs          |
| /8        | 131     | 1.0 ms          |
| /8        | 6       | 2.0 ms          |
| /64       | 61      | 12.48 ms        |
| /256      | 100     | 39.84 ms        |

---

## PWM Frequency Table (4 MHz, PR2 register)

| Frequency | Prescaler | PR2  | Resolution |
|-----------|-----------|------|------------|
| 1 kHz     | 1         | 249  | 10-bit     |
| 2 kHz     | 1         | 124  | 10-bit     |
| 4 kHz     | 1         | 61   | ~9-bit     |
| 10 kHz    | 1         | 24   | ~8-bit     |
| 1 kHz     | 4         | 249  | 10-bit     |
| 50 Hz     | 16        | 194  | ~9-bit     |
