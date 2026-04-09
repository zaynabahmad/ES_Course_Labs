# PIC16F877A Peripheral Drivers
## Embedded Systems Course — Driver Assignment
### Target: PIC16F877A | Compiler: MPLAB XC8 | Simulator: Proteus 8+

---

## Project Structure

```
FullName_ID_Drivers/
├── std_types.h              Standard typedefs  (uint8, uint16, bool ...)
├── common_macros.h          Bit macros         (SET_BIT, CLEAR_BIT ...)
├── pic_config.h             Config bits + _XTAL_FREQ  ← include ONCE in main app
├── GPIO/    gpio.h   gpio.c   gpio_app.c
├── EXTI/    exti.h   exti.c   exti_app.c
├── Timer1/  timer1.h timer1.c timer1_app.c
├── PWM/     pwm.h    pwm.c    pwm_app.c
├── ADC/     adc.h    adc.c    adc_app.c
├── UART/    uart.h   uart.c   uart_app.c
├── SPI/     spi.h    spi.c    spi_master_app.c  spi_slave_app.c
└── I2C/     i2c.h    i2c.c    i2c_app.c
```

---

## MPLAB X Setup (per driver project)

1. New Project → Standalone → PIC16F877A → XC8 compiler
2. Add the driver's `.h` + `.c` + `_app.c` + `std_types.h` + `common_macros.h` + `pic_config.h`
3. Project Properties → XC8 Compiler → Preprocessor macros: (none needed, F_CPU is in pic_config.h)
4. Build and program the `.hex` into Proteus

---

## Proteus Pin Reference

| Driver  | Key Pins                              | Proteus Components                        |
|---------|---------------------------------------|-------------------------------------------|
| GPIO    | RD0 (LED), RB0 (Button)              | LED + Button (active-low, RBPU enabled)   |
| EXTI    | RB0 (INT button), RD0 (LED)          | Button to GND + LED                       |
| Timer1  | RD0 (LED)                            | LED (toggles every 500 ms)                |
| PWM     | RC2 / CCP1                           | LED or Oscilloscope probe                 |
| ADC     | RA0/AN0 (POT), PORTD (LEDs)          | Potentiometer + 8 LEDs                    |
| UART    | RC6 (TX), RC7 (RX)                   | Virtual Terminal (9600 8N1)               |
| SPI     | RC3 SCK, RC5 SDO, RC4 SDI, RA5 SS   | Two PIC16F877A boards                     |
| I2C     | RC3 (SCL), RC4 (SDA)                 | LM75 sensor @ 0x48, 4.7kΩ pull-ups       |

---

## Key Differences from AVR (ATmega32)

| Topic            | AVR ATmega32          | PIC16F877A                    |
|------------------|-----------------------|-------------------------------|
| Direction reg    | DDRx (1=output)       | TRISx (0=output, 1=input)     |
| ISR syntax       | ISR(VECTORname){}     | void __interrupt() ISR(void)  |
| Global INT       | sei() / cli()         | INTCONbits.GIE = 1/0          |
| Peripheral INT   | automatic             | INTCONbits.PEIE = 1 required  |
| PWM module       | Timer0 OC0 pin        | CCP1 module, Timer2 base      |
| SPI/I2C module   | separate              | Shared MSSP module            |
| Analog pins      | digital by default    | Must set ADCON1=0x06 for digital|
| UART name        | USART                 | EUSART (TXSTA/RCSTA/SPBRG)    |
| Header           | <avr/io.h>            | <xc.h>                        |

---

## Important Notes

- **Always add `ADCON1 = 0x06;`** at the start of main() to make PORTA/PORTE digital,
  otherwise GPIO reads will be wrong.
- **One ISR only**: PIC16F877A has a single interrupt vector. All interrupt sources
  must be checked inside one `void __interrupt() ISR(void)` function.
- **SPI and I2C share the MSSP module** — they cannot be used simultaneously.
- **Pull-up resistors**: I2C requires external 4.7kΩ pull-ups on SDA and SCL in Proteus.
- **Crystal**: Use 8 MHz crystal in Proteus and set `F_CPU 8000000UL` in `pic_config.h`.
