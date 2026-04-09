/*
 * services.h
 * SERVICES Layer - Common utility functions
 * (bit manipulation macros, software delays, string utils)
 */

#ifndef SERVICES_H
#define SERVICES_H

typedef unsigned char  u8;
typedef unsigned int   u16;
typedef unsigned long  u32;

/* =====================================================
 * Bit Manipulation Macros
 * ===================================================== */
#define SET_BIT(reg, bit)       ((reg) |=  (1u << (bit)))
#define CLR_BIT(reg, bit)       ((reg) &= ~(1u << (bit)))
#define TOG_BIT(reg, bit)       ((reg) ^=  (1u << (bit)))
#define GET_BIT(reg, bit)       (((reg) >> (bit)) & 0x01u)

/* =====================================================
 * Software Delay (Approximate, 4MHz Fosc)
 * ===================================================== */

/**
 * @brief  Software busy-wait delay in microseconds
 *         ~4 cycles per iteration at 4MHz = 1us
 */
void Delay_us(u16 us);

/**
 * @brief  Software busy-wait delay in milliseconds
 */
void Delay_ms(u16 ms);

/* =====================================================
 * String Utilities
 * ===================================================== */

/**
 * @brief  Convert unsigned integer to decimal ASCII string
 * @param  num : number to convert
 * @param  buf : output buffer (min 6 bytes)
 * @return length of resulting string
 */
u8 Utils_UintToStr(u16 num, u8 *buf);

/**
 * @brief  Convert unsigned int to hex ASCII string (4 chars + null)
 */
void Utils_UintToHex(u16 num, u8 *buf);

/**
 * @brief  Return string length
 */
u8 Utils_Strlen(const u8 *str);

#endif /* SERVICES_H */
