/**
 * @file    main.c
 * @brief   PIC16F877 Driver Usage Example
 * @details Demonstrates initialization and usage of every driver.
 *          Crystal: 4 MHz
 *
 * Wiring assumed in this example:
 *   LED       → RB1 (output)
 *   Button    → RB0/INT (input, active-low, external interrupt)
 *   ADC input → RA0/AN0
 *   PWM out   → RC2/CCP1
 *   UART TX   → RC6 (via RS232 transceiver)
 *   UART RX   → RC7
 *   SPI SCK   → RC3, MOSI→RC5, MISO→RC4
 *   I2C SCL   → RC3, SDA→RC4 (not combined with SPI in practice)
 */

/* XC8 configuration bits — adapt to your oscillator and settings */
#pragma config FOSC  = HS       /* High-speed crystal            */
#pragma config WDTE  = OFF      /* Watchdog timer disabled        */
#pragma config PWRTE = ON       /* Power-up timer enabled         */
#pragma config BOREN = ON       /* Brown-out reset enabled         */
#pragma config LVP   = OFF      /* Low-voltage programming off    */
#pragma config CPD   = OFF      /* EEPROM code protection off     */
#pragma config WRT   = OFF      /* Flash write protection off     */
#pragma config CP    = OFF      /* Code protection off            */

#include <pic16f877.h>
#include <stdint.h>

#include "../MCAL/GPIO/gpio.h"
#include "../MCAL/EXTI/exti.h"
#include "../MCAL/Timer0/timer0.h"
#include "../MCAL/PWM/pwm.h"
#include "../MCAL/ADC/adc.h"
#include "../MCAL/UART/uart.h"
#include "../MCAL/SPI/spi.h"
#include "../MCAL/I2C/i2c.h"

#define FOSC_HZ     4000000UL
#define BAUD_RATE   9600UL

/*============================================================
 * Application-level variables
 *============================================================*/
static volatile uint8_t  g_buttonPressed  = 0u;
static volatile uint16_t g_adcResult      = 0u;
static volatile uint8_t  g_rxByte         = 0u;

/*============================================================
 * Interrupt Callbacks (implementations)
 *============================================================*/

/* RB0 INT callback — set flag, main loop handles it */
void EXTI_INT_Callback(void)
{
    g_buttonPressed = 1u;
}

/* PORTB change callback */
void EXTI_RBChange_Callback(void)
{
    /* Read port to clear mismatch condition */
    (void)PORTB;
}

/* Timer0 overflow callback — used for 1ms tick */
void TIMER0_OVF_Callback(void)
{
    /* Reload TMR0 for next 1ms period
     * At 4MHz, Fosc/4=1MHz, PS=8: 1 tick = 8us
     * 256 - 125 = 131 → 125 ticks × 8us = 1ms */
    TIMER0_SetPreload(131u);
}

/* ADC conversion complete callback */
void ADC_ConvComplete_Callback(void)
{
    g_adcResult = ADC_GetResult();
}

/* UART RX callback */
void UART_RX_Callback(void)
{
    g_rxByte = UART_ReceiveByte();
    /* Echo back */
    UART_SendByte(g_rxByte);
}

/* UART TX callback — fires when TXREG empty (for buffered TX) */
void UART_TX_Callback(void) { }

/* SPI transfer complete callback */
void SPI_TransferComplete_Callback(void) { }

/* I2C slave event callback */
void I2C_Slave_Callback(void) { }

/*============================================================
 * Peripheral Initialization Functions
 *============================================================*/

static void app_gpio_init(void)
{
    /* LED on RB1 — output, initially OFF */
    GPIO_Config_t led = {
        .port      = GPIO_PORTB,
        .pin       = GPIO_PIN1,
        .direction = GPIO_OUTPUT,
        .initState = GPIO_LOW
    };
    GPIO_Init(&led);

    /* General purpose input on RD0 */
    GPIO_Config_t in = {
        .port      = GPIO_PORTD,
        .pin       = GPIO_PIN0,
        .direction = GPIO_INPUT,
        .initState = GPIO_LOW
    };
    GPIO_Init(&in);

    /* Enable PORTB weak pull-ups (for button on RB0) */
    GPIO_SetPortBPullUp(GPIO_PULLUP_ENABLE);
}

static void app_exti_init(void)
{
    EXTI_INT_Config_t intCfg = {
        .edge     = EXTI_EDGE_FALLING,   /* Active-low button */
        .globalIE = EXTI_DISABLE         /* Enable GIE later  */
    };
    EXTI_INT_Init(&intCfg);
}

static void app_timer0_init(void)
{
    TIMER0_Config_t t0cfg = {
        .clkSrc      = TIMER0_CLK_INTERNAL,
        .extEdge     = TIMER0_EDGE_RISING,
        .psAssign    = TIMER0_PS_ASSIGNED,
        .psRate      = TIMER0_PS_DIV8,
        .preloadVal  = 131u,             /* ~1ms at 4MHz     */
        .intEnable   = TIMER0_INT_ENABLE
    };
    TIMER0_Init(&t0cfg);
}

static void app_pwm_init(void)
{
    /* 1kHz PWM at 50% duty on CCP1/RC2 */
    /* PR2 = Fosc/(4*freq*prescaler) - 1 = 4MHz/(4*1000*1) - 1 = 249 */
    PWM_Config_t pwmCfg = {
        .channel    = PWM_CHANNEL_1,
        .pr2Value   = PWM_CalcPR2(1000u, FOSC_HZ, 1u),
        .prescaler  = PWM_PRESCALER_1,
        .postscaler = PWM_POSTSCALER_1,
        .dutyCycle  = 512u             /* 50% of 1023 */
    };
    PWM_Init(&pwmCfg);
}

static void app_adc_init(void)
{
    /* Right-justified, Fosc/8 clock, AN0 analog, interrupt enabled */
    ADC_Config_t adcCfg = {
        .clock     = ADC_CLK_FOSC_8,
        .justify   = ADC_JUSTIFY_RIGHT,
        .portCfg   = ADC_PCFG_ALL_ANALOG,
        .intEnable = ADC_INT_ENABLE
    };
    ADC_Init(&adcCfg);
}

static void app_uart_init(void)
{
    UART_Config_t uartCfg = {
        .foscHz   = FOSC_HZ,
        .baudRate = BAUD_RATE,
        .brgh     = UART_BRGH_HIGH,
        .dataBits = UART_DATABITS_8,
        .txIntEn  = UART_INT_DISABLE,
        .rxIntEn  = UART_INT_ENABLE
    };
    UART_Init(&uartCfg);
}

static void app_spi_init(void)
{
    /* Master, 1MHz (Fosc/4=1MHz), SPI MODE0 */
    SPI_Config_t spiCfg = {
        .mode      = SPI_MODE_MASTER_FOSC4,
        .clockMode = SPI_CLOCK_MODE0,
        .smp       = SPI_SMP_MIDDLE,
        .intEnable = SPI_INT_DISABLE
    };
    SPI_Init(&spiCfg);
}

static void app_i2c_init(void)
{
    /* 100kHz I2C master */
    I2C_MasterConfig_t i2cCfg = {
        .foscHz    = FOSC_HZ,
        .speedHz   = 100000UL,
        .slewRate  = I2C_SPEED_100K,
        .intEnable = I2C_INT_DISABLE
    };
    I2C_Master_Init(&i2cCfg);
}

/*============================================================
 * SPI Example — read one byte from an SPI device
 *============================================================*/
static uint8_t spi_read_register(uint8_t reg)
{
    uint8_t result;

    /* Assert CS (use GPIO — e.g., RA3 as chip select) */
    GPIO_WritePin(GPIO_PORTA, GPIO_PIN3, GPIO_LOW);

    SPI_SendByte(reg | 0x80u);   /* Read command (bit7=1 for many devices) */
    result = SPI_ReceiveByte();

    /* Deassert CS */
    GPIO_WritePin(GPIO_PORTA, GPIO_PIN3, GPIO_HIGH);
    return result;
}

/*============================================================
 * I2C Example — read temperature from LM75 (0x48) register 0x00
 *============================================================*/
static void i2c_read_temperature(void)
{
    uint8_t tempBuf[2];
    I2C_Status_t status;

    status = I2C_Master_WriteRead(0x48u, 0x00u, tempBuf, 2u);
    if (status == I2C_OK) {
        int16_t raw = (int16_t)(((uint16_t)tempBuf[0] << 1u) | (tempBuf[1] >> 7u));
        /* raw * 0.5 = temperature in °C */
        UART_SendString("Temp raw: ");
        /* Simple decimal print of MSB */
        uint8_t wholeDeg = (uint8_t)(raw >> 1);
        UART_SendByte((uint8_t)('0' + (wholeDeg / 10u)));
        UART_SendByte((uint8_t)('0' + (wholeDeg % 10u)));
        UART_SendString(" C\r\n");
    } else {
        UART_SendString("I2C Error\r\n");
    }
}

/*============================================================
 * ADC → PWM Example — map ADC result to duty cycle
 *============================================================*/
static void update_pwm_from_adc(void)
{
    /* ADC is 10-bit (0–1023), PWM duty is also 10-bit (0–1023) */
    PWM_SetDuty(PWM_CHANNEL_1, g_adcResult);
}

/*============================================================
 * Simple busy-wait delay using Timer0 overflows
 * (polling mode — only use before GIE is enabled, or after disabling it)
 *============================================================*/
static void delay_ms(uint8_t ms)
{
    /* At preload=131, PSdiv=8, Fosc=4MHz: 1 overflow ≈ 1ms */
    TIMER0_DelayOverflows(ms);
}

/*============================================================
 * main
 *============================================================*/
void main(void)
{
    /*--------------------------------------------------------
     * 1. Initialize all peripherals
     *--------------------------------------------------------*/
    app_gpio_init();
    app_exti_init();
    app_timer0_init();
    app_pwm_init();
    app_adc_init();
    app_uart_init();
    app_spi_init();
    /* app_i2c_init(); */   /* Uncomment when using I2C (conflicts with SPI on RC3/RC4) */

    /*--------------------------------------------------------
     * 2. Enable peripheral and global interrupts
     *    PEIE must be set for ADC, UART, SSP interrupts
     *--------------------------------------------------------*/
    INTCONbits.PEIE = 1;
    INTCONbits.GIE  = 1;

    /*--------------------------------------------------------
     * 3. Send startup message over UART
     *--------------------------------------------------------*/
    UART_SendString("PIC16F877 Drivers Ready\r\n");

    /*--------------------------------------------------------
     * 4. Kick off first ADC conversion
     *--------------------------------------------------------*/
    ADC_SelectChannel(ADC_CH0);
    ADC_StartConversion();

    /*--------------------------------------------------------
     * 5. Main loop
     *--------------------------------------------------------*/
    while (1) {

        /* --- Button press event (set in EXTI callback) --- */
        if (g_buttonPressed) {
            g_buttonPressed = 0u;
            GPIO_TogglePin(GPIO_PORTB, GPIO_PIN1);  /* Toggle LED */
            UART_SendString("Button pressed!\r\n");
        }

        /* --- ADC-to-PWM update --- */
        update_pwm_from_adc();

        /* Start next ADC conversion */
        ADC_SelectChannel(ADC_CH0);
        ADC_StartConversion();

        /* --- SPI register read example --- */
        (void)spi_read_register(0x0Fu);

        /* --- I2C temperature read (if I2C initialized) --- */
        /* i2c_read_temperature(); */

        /* --- Blink indication with 500ms blocking delay --- */
        delay_ms(100u);
    }
}
