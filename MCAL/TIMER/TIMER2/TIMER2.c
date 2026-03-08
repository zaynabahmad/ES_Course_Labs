#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER2_interface.h"
#include "TIMER2_private.h"
#include "TIMER2_config.h"

u8 current_postScaler = DEFAULT_POSTSCALER;
u8 current_preScaler = DEFAULT_PRESCALER;

void set_period_timer_2_Reg(u8 desired_value)
{
    PR2 = desired_value;
}

u8 get_PR2(void)
{
    return PR2;
}

void timer_2_intialize(void)
{
    //Turn on timer
    SET_BIT(T2CON,TMR2ON);
    //Sets preScaler to value in config
    set_timer_2_postScaler(DEFAULT_POSTSCALER);
    //Sets postScaler to value in config
    set_timer_2_preScaler(DEFAULT_PRESCALER);
}

u8 get_preScaler()
{
    return current_preScaler;
}

u8 get_postScaler()
{
    return current_postScaler;
}

void set_timer_2_preScaler(u8 PRESCALE_SELECT)
{
    //Yes i made AI write this switch case because i wouldnt write all these cases myself
    //Good use of AI !
    switch (PRESCALE_SELECT)
    {
        case PRESCALER_1_1:
            // Prescaler 1:1 -> T2CKPS1:T2CKPS0 = 00
            CLR_BIT(T2CON, T2CKPS1);
            CLR_BIT(T2CON, T2CKPS0);
            break;
            
        case PRESCALER_1_4:
            // Prescaler 1:4 -> T2CKPS1:T2CKPS0 = 01
            CLR_BIT(T2CON, T2CKPS1);
            SET_BIT(T2CON, T2CKPS0);
            break;
            
        case PRESCALER_1_16:
            // Prescaler 1:16 -> T2CKPS1:T2CKPS0 = 1x (Standard is 10)
            SET_BIT(T2CON, T2CKPS1);
            CLR_BIT(T2CON, T2CKPS0);
            break;
            
        default:
            // Default to maximum prescaler (1:16) for safety
            SET_BIT(T2CON, T2CKPS1);
            CLR_BIT(T2CON, T2CKPS0);
            break;
    }
    current_preScaler = PRESCALE_SELECT;
}

void set_timer_2_postScaler(u8 POSTSCALE_SELECT)
{
    //Yes i made AI write this switch case because i wouldnt write all these cases myself
    //Good use of AI !
    switch (POSTSCALE_SELECT)
    {
        case POSTSCALER_1_1:
            // Postscaler 1:1 -> TOUTPS = 0000
            CLR_BIT(T2CON, TOUTPS3);
            CLR_BIT(T2CON, TOUTPS2);
            CLR_BIT(T2CON, TOUTPS1);
            CLR_BIT(T2CON, TOUTPS0);
            break;

        case POSTSCALER_1_2:
            // Postscaler 1:2 -> TOUTPS = 0001
            CLR_BIT(T2CON, TOUTPS3);
            CLR_BIT(T2CON, TOUTPS2);
            CLR_BIT(T2CON, TOUTPS1);
            SET_BIT(T2CON, TOUTPS0);
            break;

        case POSTSCALER_1_3:
            // Postscaler 1:3 -> TOUTPS = 0010
            CLR_BIT(T2CON, TOUTPS3);
            CLR_BIT(T2CON, TOUTPS2);
            SET_BIT(T2CON, TOUTPS1);
            CLR_BIT(T2CON, TOUTPS0);
            break;

        case POSTSCALER_1_4:
            // Postscaler 1:4 -> TOUTPS = 0011
            CLR_BIT(T2CON, TOUTPS3);
            CLR_BIT(T2CON, TOUTPS2);
            SET_BIT(T2CON, TOUTPS1);
            SET_BIT(T2CON, TOUTPS0);
            break;

        case POSTSCALER_1_5:
            // Postscaler 1:5 -> TOUTPS = 0100
            CLR_BIT(T2CON, TOUTPS3);
            SET_BIT(T2CON, TOUTPS2);
            CLR_BIT(T2CON, TOUTPS1);
            CLR_BIT(T2CON, TOUTPS0);
            break;

        case POSTSCALER_1_6:
            // Postscaler 1:6 -> TOUTPS = 0101
            CLR_BIT(T2CON, TOUTPS3);
            SET_BIT(T2CON, TOUTPS2);
            CLR_BIT(T2CON, TOUTPS1);
            SET_BIT(T2CON, TOUTPS0);
            break;

        case POSTSCALER_1_7:
            // Postscaler 1:7 -> TOUTPS = 0110
            CLR_BIT(T2CON, TOUTPS3);
            SET_BIT(T2CON, TOUTPS2);
            SET_BIT(T2CON, TOUTPS1);
            CLR_BIT(T2CON, TOUTPS0);
            break;

        case POSTSCALER_1_8:
            // Postscaler 1:8 -> TOUTPS = 0111
            CLR_BIT(T2CON, TOUTPS3);
            SET_BIT(T2CON, TOUTPS2);
            SET_BIT(T2CON, TOUTPS1);
            SET_BIT(T2CON, TOUTPS0);
            break;

        case POSTSCALER_1_9:
            // Postscaler 1:9 -> TOUTPS = 1000
            SET_BIT(T2CON, TOUTPS3);
            CLR_BIT(T2CON, TOUTPS2);
            CLR_BIT(T2CON, TOUTPS1);
            CLR_BIT(T2CON, TOUTPS0);
            break;

        case POSTSCALER_1_10:
            // Postscaler 1:10 -> TOUTPS = 1001
            SET_BIT(T2CON, TOUTPS3);
            CLR_BIT(T2CON, TOUTPS2);
            CLR_BIT(T2CON, TOUTPS1);
            SET_BIT(T2CON, TOUTPS0);
            break;

        case POSTSCALER_1_11:
            // Postscaler 1:11 -> TOUTPS = 1010
            SET_BIT(T2CON, TOUTPS3);
            CLR_BIT(T2CON, TOUTPS2);
            SET_BIT(T2CON, TOUTPS1);
            CLR_BIT(T2CON, TOUTPS0);
            break;

        case POSTSCALER_1_12:
            // Postscaler 1:12 -> TOUTPS = 1011
            SET_BIT(T2CON, TOUTPS3);
            CLR_BIT(T2CON, TOUTPS2);
            SET_BIT(T2CON, TOUTPS1);
            SET_BIT(T2CON, TOUTPS0);
            break;

        case POSTSCALER_1_13:
            // Postscaler 1:13 -> TOUTPS = 1100
            SET_BIT(T2CON, TOUTPS3);
            SET_BIT(T2CON, TOUTPS2);
            CLR_BIT(T2CON, TOUTPS1);
            CLR_BIT(T2CON, TOUTPS0);
            break;

        case POSTSCALER_1_14:
            // Postscaler 1:14 -> TOUTPS = 1101
            SET_BIT(T2CON, TOUTPS3);
            SET_BIT(T2CON, TOUTPS2);
            CLR_BIT(T2CON, TOUTPS1);
            SET_BIT(T2CON, TOUTPS0);
            break;

        case POSTSCALER_1_15:
            // Postscaler 1:15 -> TOUTPS = 1110
            SET_BIT(T2CON, TOUTPS3);
            SET_BIT(T2CON, TOUTPS2);
            SET_BIT(T2CON, TOUTPS1);
            CLR_BIT(T2CON, TOUTPS0);
            break;

        case POSTSCALER_1_16:
            // Postscaler 1:16 -> TOUTPS = 1111
            SET_BIT(T2CON, TOUTPS3);
            SET_BIT(T2CON, TOUTPS2);
            SET_BIT(T2CON, TOUTPS1);
            SET_BIT(T2CON, TOUTPS0);
            break;

        default:
            // Default to maximum postscaler (1:16) for safety
            SET_BIT(T2CON, TOUTPS3);
            SET_BIT(T2CON, TOUTPS2);
            SET_BIT(T2CON, TOUTPS1);
            SET_BIT(T2CON, TOUTPS0);
            break;
    }
    current_postScaler = POSTSCALE_SELECT;
}