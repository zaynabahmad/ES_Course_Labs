/*
 * services.c
 * SERVICES Layer - Common utility implementations
 */

#include "services.h"

void Delay_us(u16 us)
{
    u16 i;
    for(i = 0; i < us; i++)
    {
        asm nop;
        asm nop;
        asm nop;
    }
}

void Delay_ms(u16 ms)
{
    u16 i;
    for(i = 0; i < ms; i++)
    {
        Delay_us(1000);
    }
}

u8 Utils_UintToStr(u16 num, u8 *buf)
{
    u8 tmp[6];
    u8 i = 0;
    u8 j;
    u8 len;

    if(num == 0)
    {
        buf[0] = '0';
        buf[1] = '\0';
        return 1;
    }
    while(num > 0)
    {
        tmp[i++] = (u8)('0' + (num % 10));
        num /= 10;
    }
    len = i;
    for(j = 0; j < i; j++)
    {
        buf[j] = tmp[i - 1 - j];
    }
    buf[i] = '\0';
    return len;
}

void Utils_UintToHex(u16 num, u8 *buf)
{
    const u8 hexChars[] = "0123456789ABCDEF";
    buf[0] = hexChars[(num >> 12) & 0x0F];
    buf[1] = hexChars[(num >>  8) & 0x0F];
    buf[2] = hexChars[(num >>  4) & 0x0F];
    buf[3] = hexChars[(num >>  0) & 0x0F];
    buf[4] = '\0';
}

u8 Utils_Strlen(const u8 *str)
{
    u8 len = 0;
    while(*str++ != '\0') len++;
    return len;
}
