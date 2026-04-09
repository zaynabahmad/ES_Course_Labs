/*
 * lcd.c
 * HAL - LCD (HD44780) Driver Implementation
 * Uses MCAL GPIO and Timer0 for delays
 */

#include "lcd.h"
#include "../MCAL/GPIO/gpio.h"
#include "../MCAL/TIMER0/timer0.h"

/* =====================================================
 * Internal Helper Functions
 * ===================================================== */

static void LCD_PulseEnable(void)
{
    GPIO_WritePin(LCD_CTRL_PORT, LCD_EN_PIN, GPIO_HIGH);
    TIMER0_DelayMs(1);
    GPIO_WritePin(LCD_CTRL_PORT, LCD_EN_PIN, GPIO_LOW);
    TIMER0_DelayMs(1);
}

static void LCD_SendNibble(u8 nibble)
{
    /* Write upper nibble to D4-D7 */
    GPIO_WritePin(LCD_DATA_PORT, LCD_D4_PIN, (nibble >> 0) & 0x01);
    GPIO_WritePin(LCD_DATA_PORT, LCD_D5_PIN, (nibble >> 1) & 0x01);
    GPIO_WritePin(LCD_DATA_PORT, LCD_D6_PIN, (nibble >> 2) & 0x01);
    GPIO_WritePin(LCD_DATA_PORT, LCD_D7_PIN, (nibble >> 3) & 0x01);
    LCD_PulseEnable();
}

static void LCD_Send(u8 data, u8 isData)
{
    /* RS = 1 for data, RS = 0 for command */
    GPIO_WritePin(LCD_CTRL_PORT, LCD_RS_PIN, isData ? GPIO_HIGH : GPIO_LOW);

    /* Send high nibble first */
    LCD_SendNibble((data >> 4) & 0x0F);

    /* Send low nibble */
    LCD_SendNibble(data & 0x0F);

    TIMER0_DelayMs(2);
}

/* =====================================================
 * Public Functions
 * ===================================================== */

void LCD_Init(void)
{
    /* Configure all LCD pins as outputs */
    GPIO_SetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, GPIO_OUTPUT);
    GPIO_SetPinDirection(LCD_CTRL_PORT, LCD_EN_PIN, GPIO_OUTPUT);
    GPIO_SetPinDirection(LCD_DATA_PORT, LCD_D4_PIN, GPIO_OUTPUT);
    GPIO_SetPinDirection(LCD_DATA_PORT, LCD_D5_PIN, GPIO_OUTPUT);
    GPIO_SetPinDirection(LCD_DATA_PORT, LCD_D6_PIN, GPIO_OUTPUT);
    GPIO_SetPinDirection(LCD_DATA_PORT, LCD_D7_PIN, GPIO_OUTPUT);

    /* Initial state */
    GPIO_WritePin(LCD_CTRL_PORT, LCD_RS_PIN, GPIO_LOW);
    GPIO_WritePin(LCD_CTRL_PORT, LCD_EN_PIN, GPIO_LOW);

    /* Power-on delay */
    TIMER0_DelayMs(20);

    /* --- Initialization sequence for 4-bit mode --- */
    /* Step 1: Send 0x03 three times (8-bit mode reset) */
    LCD_SendNibble(0x03);
    TIMER0_DelayMs(5);
    LCD_SendNibble(0x03);
    TIMER0_DelayMs(1);
    LCD_SendNibble(0x03);
    TIMER0_DelayMs(1);

    /* Step 2: Switch to 4-bit mode */
    LCD_SendNibble(0x02);
    TIMER0_DelayMs(1);

    /* Step 3: Function set: 4-bit, 2 lines, 5x8 */
    LCD_SendCommand(LCD_FUNCTION_4BIT);

    /* Step 4: Display ON, cursor OFF */
    LCD_SendCommand(LCD_DISPLAY_ON);

    /* Step 5: Clear display */
    LCD_SendCommand(LCD_CLEAR_DISPLAY);
    TIMER0_DelayMs(2);

    /* Step 6: Entry mode set */
    LCD_SendCommand(LCD_ENTRY_MODE);
}

void LCD_SendCommand(u8 cmd)
{
    LCD_Send(cmd, 0);
}

void LCD_SendChar(u8 ch)
{
    LCD_Send(ch, 1);
}

void LCD_SendString(const u8 *str)
{
    while(*str != '\0')
    {
        LCD_SendChar(*str);
        str++;
    }
}

void LCD_GotoXY(u8 row, u8 col)
{
    u8 addr;
    col--;  /* Convert to 0-based */
    if(row == 1)
    {
        addr = LCD_ROW1_OFFSET + col;
    }
    else
    {
        addr = LCD_ROW2_OFFSET + col;
    }
    LCD_SendCommand(LCD_SET_DDRAM | addr);
}

void LCD_Clear(void)
{
    LCD_SendCommand(LCD_CLEAR_DISPLAY);
    TIMER0_DelayMs(2);
}

void LCD_SendNumber(u16 num)
{
    u8  buf[6];
    u8  i = 0;
    u8  j;
    u8  temp;

    if(num == 0)
    {
        LCD_SendChar('0');
        return;
    }
    while(num > 0)
    {
        buf[i++] = (u8)('0' + (num % 10));
        num /= 10;
    }
    /* Reverse */
    for(j = 0; j < i / 2; j++)
    {
        temp       = buf[j];
        buf[j]     = buf[i - 1 - j];
        buf[i-1-j] = temp;
    }
    for(j = 0; j < i; j++)
    {
        LCD_SendChar(buf[j]);
    }
}
