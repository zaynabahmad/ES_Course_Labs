/*
 * lcd.h
 * HAL - LCD (HD44780) Driver Interface for PIC16F877A
 * Built on top of MCAL GPIO driver
 * 4-bit interface mode
 *
 * Pin Mapping (configurable):
 * RS  -> RD0
 * EN  -> RD1
 * D4  -> RD4
 * D5  -> RD5
 * D6  -> RD6
 * D7  -> RD7
 */

#ifndef LCD_H
#define LCD_H

typedef unsigned char u8;
typedef unsigned int  u16;

/* =====================================================
 * LCD Pin Configuration (HAL layer - no register access)
 * ===================================================== */
#include "../MCAL/GPIO/gpio.h"

#define LCD_CTRL_PORT   GPIO_PORTD
#define LCD_DATA_PORT   GPIO_PORTD

#define LCD_RS_PIN      GPIO_PIN0
#define LCD_EN_PIN      GPIO_PIN1
#define LCD_D4_PIN      GPIO_PIN4
#define LCD_D5_PIN      GPIO_PIN5
#define LCD_D6_PIN      GPIO_PIN6
#define LCD_D7_PIN      GPIO_PIN7

/* =====================================================
 * LCD Commands
 * ===================================================== */
#define LCD_CLEAR_DISPLAY   0x01
#define LCD_RETURN_HOME     0x02
#define LCD_ENTRY_MODE      0x06    /* Increment, no shift */
#define LCD_DISPLAY_ON      0x0C    /* Display on, cursor off, blink off */
#define LCD_DISPLAY_OFF     0x08
#define LCD_CURSOR_ON       0x0E
#define LCD_BLINK_ON        0x0F
#define LCD_FUNCTION_4BIT   0x28    /* 4-bit, 2-line, 5x8 font */
#define LCD_SET_DDRAM       0x80    /* OR with address */

/* Row offsets for 16x2 LCD */
#define LCD_ROW1_OFFSET     0x00
#define LCD_ROW2_OFFSET     0x40

/* =====================================================
 * Function Prototypes
 * ===================================================== */

/**
 * @brief  Initialize LCD in 4-bit mode
 */
void LCD_Init(void);

/**
 * @brief  Send a command byte to LCD
 */
void LCD_SendCommand(u8 cmd);

/**
 * @brief  Send a data character to LCD
 */
void LCD_SendChar(u8 ch);

/**
 * @brief  Send a null-terminated string to LCD
 */
void LCD_SendString(const u8 *str);

/**
 * @brief  Set cursor position
 * @param  row : 1 or 2
 * @param  col : 1 to 16
 */
void LCD_GotoXY(u8 row, u8 col);

/**
 * @brief  Clear LCD display
 */
void LCD_Clear(void);

/**
 * @brief  Display an integer number on LCD
 */
void LCD_SendNumber(u16 num);

#endif /* LCD_H */
