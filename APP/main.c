#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/PWM/PWM_Interface.h"
#include "../MCAL/TIMER_0/TIMER_0_Interface.h"
#include "../MCAL/USART/USART_Interface.h"
#include "../SERVICES/BIT_MATH.h"
#include "../SERVICES/STD_TYPES.h"

/* ====================================================================
   SELECT TASK TO RUN:
   1: LED Sequences Controlled by Switches (Original Task 1)
   2: Toggling an LED on RB0 Every 1 Second Using Timer0
   3: Toggling LED1(RB1) every 2s, LED2(RB2) every 1s using Timer0
   4: DC Motor Speed Control Using PWM (25%->50%->75%->100%) via Ext Int
   5: LM35 Temperature Sensor on AN0 to Virtual Terminal via UART
==================================================================== */
#define CURRENT_TASK 1

/* ====================================================================
   TASK 1 IMPLEMENTATION
==================================================================== */
#if CURRENT_TASK == 1

#define LED1_PORT GPIO_PORTC
#define LED1_PIN GPIO_PIN0
#define LED2_PORT GPIO_PORTC
#define LED2_PIN GPIO_PIN1
#define SW1_PORT GPIO_PORTB
#define SW1_PIN GPIO_PIN0
#define SW2_PORT GPIO_PORTB
#define SW2_PIN GPIO_PIN1

void Delay_ms(u16 ms) {
  volatile u16 i, j;
  for (i = 0; i < ms; i++) {
    for (j = 0; j < 100; j++) {
    }
  }
}

int main(void) {
  GPIO_Init();
  LED_Init(LED1_PORT, LED1_PIN);
  LED_Init(LED2_PORT, LED2_PIN);
  SWITCH_Init(SW1_PORT, SW1_PIN);
  SWITCH_Init(SW2_PORT, SW2_PIN);

  while (1) {
    u8 SW1_State = SWITCH_GetState(SW1_PORT, SW1_PIN, SWITCH_PULL_UP);
    u8 SW2_State = SWITCH_GetState(SW2_PORT, SW2_PIN, SWITCH_PULL_UP);

    if (SW1_State == SWITCH_PRESSED) {
      LED_On(LED1_PORT, LED1_PIN);
      LED_On(LED2_PORT, LED2_PIN);
      Delay_ms(200);
      LED_Off(LED1_PORT, LED1_PIN);
      LED_Off(LED2_PORT, LED2_PIN);
      Delay_ms(200);
    } else if (SW2_State == SWITCH_PRESSED) {
      LED_On(LED1_PORT, LED1_PIN);
      LED_On(LED2_PORT, LED2_PIN);
      Delay_ms(500);
      LED_Off(LED1_PORT, LED1_PIN);
      LED_Off(LED2_PORT, LED2_PIN);
      Delay_ms(500);
    } else {
      LED_Off(LED1_PORT, LED1_PIN);
      LED_Off(LED2_PORT, LED2_PIN);
    }
  }
  return 0;
}

/* ====================================================================
   TASK 2 IMPLEMENTATION
==================================================================== */
#elif CURRENT_TASK == 2

#define LED_PORT GPIO_PORTB
#define LED_PIN GPIO_PIN0

volatile u16 ms_counter = 0;

void Timer0_ISR_Callback(void) {
  u8 pin_state;
  /* Preload for 1ms: Fosc=4MHz -> Tcy=1us. Prescaler=8 -> Tick=8us. 1000us/8us
   * = 125. 256-125 = 131 */
  TIMER0_SetPreload(131);

  ms_counter++;
  if (ms_counter >= 1000) {
    ms_counter = 0;
    /* Toggle LED every 1 second */
    pin_state = GPIO_GetPinValue(LED_PORT, LED_PIN);
    GPIO_SetPinValue(LED_PORT, LED_PIN, pin_state ^ 1);
  }
}

int main(void) {
  LED_Init(LED_PORT, LED_PIN);

  TIMER0_SetCallback(Timer0_ISR_Callback);
  TIMER0_Init();
  // TIMER0_SetPreload(131); Removed to prevent MikroC reentrancy error

  while (1) {
    /* Main loop is non-blocked, LED toggles purely via interrupts */
  }
  return 0;
}

/* ====================================================================
   TASK 3 IMPLEMENTATION
==================================================================== */
#elif CURRENT_TASK == 3

#define LED1_PORT GPIO_PORTB
#define LED1_PIN GPIO_PIN1   // 2 sec

#define LED2_PORT GPIO_PORTB
#define LED2_PIN GPIO_PIN2   // 1 sec

volatile unsigned int led1_ms_counter = 0;
volatile unsigned int led2_ms_counter = 0;

/* ISR Callback */
void Timer0_ISR_Callback(void)
{
    /* ?? IMPORTANT: direct register access (NO function call) */
    TMR0 = 131;

    led1_ms_counter++;
    led2_ms_counter++;

    if (led1_ms_counter >= 2000)
    {
        led1_ms_counter = 0;
        GPIO_SetPinValue(LED1_PORT, LED1_PIN,
                         !GPIO_GetPinValue(LED1_PORT, LED1_PIN));
    }

    if (led2_ms_counter >= 1000)
    {
        led2_ms_counter = 0;
        GPIO_SetPinValue(LED2_PORT, LED2_PIN,
                         !GPIO_GetPinValue(LED2_PORT, LED2_PIN));
    }
}

int main(void)
{
    GPIO_Init();

    LED_Init(LED1_PORT, LED1_PIN);
    LED_Init(LED2_PORT, LED2_PIN);

    TIMER0_SetCallback(Timer0_ISR_Callback);
    TIMER0_Init();

    /* Initial preload */
    TIMER0_SetPreload(131);

    while (1)
    {
        /* Nothing here */
    }

    return 0;
}

/* ====================================================================
   TASK 4 IMPLEMENTATION (Optimized to fix Call Stack Error)
==================================================================== */
#elif CURRENT_TASK == 4

volatile u8 duty_index = 0;
volatile u8 speed_change_flag = 0;

const u8 duty_levels[] = {25, 50, 75, 100};

void Delay_ms(u16 ms)
{
    volatile u16 i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 100; j++);
}

void Switch_ISR_Callback(void)
{
    duty_index++;
    if (duty_index >= 4)
        duty_index = 0;

    speed_change_flag = 1;
}

int main(void)
{
    GPIO_Init();

    /* Motor direction */
    GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN1, GPIO_OUTPUT);

    GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN0, 1);
    GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN1, 0);

    PWM1_Init();
    Delay_ms(100);   // ?? VERY IMPORTANT
    PWM1_SetDutyCycle(duty_levels[duty_index]);

    EXT_INT_Init();
    EXT_INT_SetEdge(falling_edge);
    EXT_INT_SetCallback(Switch_ISR_Callback);
    EXT_INT_Enable();

    while (1)
    {
        if (speed_change_flag == 1)
        {
            PWM1_SetDutyCycle(duty_levels[duty_index]);
            speed_change_flag = 0;
        }
    }

    return 0;
}
/* ====================================================================
   TASK 5 IMPLEMENTATION
==================================================================== */

#elif CURRENT_TASK == 5

void FloatToString(f32 value, char *str) {
  int integer_part = (int)value;
  int fractional_part = (int)((value - (f32)integer_part) * 100.0);
  int temp = integer_part;
  int i = 0, j = 0;
  char rev[10];

  if (temp == 0) {
    str[i++] = '0';
  } else {
    while (temp > 0) {
      rev[j++] = (temp % 10) + '0';
      temp /= 10;
    }
    while (j > 0) {
      str[i++] = rev[--j];
    }
  }
  str[i++] = '.';
  str[i++] = (fractional_part / 10) + '0';
  str[i++] = (fractional_part % 10) + '0';
  str[i] = '\0';
}

void UART_Write_Text(char *str) {
  while (*str != '\0') {
    UART_Write(*str);
    str++;
  }
}

void Delay_ms(u16 ms) {
  volatile u16 i, j;
  for (i = 0; i < ms; i++) {
    for (j = 0; j < 100; j++) {
    }
  }
}

int main(void) {
  u16 adc_value;
  f32 temperature;
  char txt[20];

  /* Initialize ADC */
  ADC_Init();

  /* Initialize UART for Transmission */
  UART_TX_Init();

  Delay_ms(100);

  while (1) {
    /* Read Analog Value from AN0 */
    adc_value = ADC_ReadChannel(ADC_CHANNEL_0);

    /* Convert to Temperature (assuming 5V reference and 10-bit ADC, LM35 =
       10mV/C) 5V / 1024 = 4.88mV per step. Temperature = (adc_value * 4.88) /
       10 = adc_value * 0.488 */
    temperature = (f32)adc_value * 0.488f;

    /* Convert Float to String (MikroC compatible without stdio.h) */
    FloatToString(temperature, txt);

    /* Send over UART */
    UART_Write_Text("Temp = ");
    UART_Write_Text(txt);
    UART_Write_Text(" C\r\n");

    Delay_ms(1000);
  }
  return 0;
}
#endif