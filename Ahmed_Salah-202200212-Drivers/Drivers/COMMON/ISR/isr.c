/**
 * @file    isr.c
 * @brief   PIC16F877 — Unified Interrupt Service Routine
 * @details All peripheral interrupt flags are checked in one ISR.
 *          Include this file ONCE in your project.
 *          Do NOT define XXXX_USE_STANDALONE_ISR macros when using this.
 *
 * Interrupt Priority (checked in order):
 *  1. RB0/INT  External Interrupt   (INTCON<1,4>)
 *  2. RBx Port Change               (INTCON<0,3>)
 *  3. Timer0 Overflow               (INTCON<2,5>)
 *  4. ADC Conversion Complete       (PIR1<6>, PIE1<6>)
 *  5. UART TX Empty                 (PIR1<4>, PIE1<4>)
 *  6. UART RX Complete              (PIR1<5>, PIE1<5>)
 *  7. SSP (SPI/I2C)                 (PIR1<3>, PIE1<3>)
 *  8. CCP1 (PWM/Capture/Compare)    (PIR1<2>, PIE1<2>)
 *  9. CCP2                          (PIR2<0>, PIE2<0>)
 * 10. Timer2 (PWM timebase)         (PIR1<1>, PIE1<1>)
 */

#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/EXTI/exti.h"
#include "../../MCAL/Timer0/timer0.h"
#include "../../MCAL/ADC/adc.h"
#include "../../MCAL/UART/uart.h"
#include "../../MCAL/SPI/spi.h"
#include "../../MCAL/I2C/i2c.h"

/* Static preload storage for Timer0 auto-reload (mirrored here) */
extern uint8_t TIMER0_GetPreload(void);   /* Exposed via timer0.c if needed */

void __interrupt() PIC16F877_ISR(void)
{
    /*----------------------------------------------------------
     * 1. RB0/INT External Interrupt
     *----------------------------------------------------------*/
    if (INTCONbits.INTE && INTCONbits.INTF) {
        INTCONbits.INTF = 0;
        EXTI_INT_Callback();
    }

    /*----------------------------------------------------------
     * 2. PORTB Change Interrupt (RB4:RB7)
     *----------------------------------------------------------*/
    if (INTCONbits.RBIE && INTCONbits.RBIF) {
        (void)PORTB;                /* Read to end mismatch */
        INTCONbits.RBIF = 0;
        EXTI_RBChange_Callback();
    }

    /*----------------------------------------------------------
     * 3. Timer0 Overflow
     *----------------------------------------------------------*/
    if (INTCONbits.T0IE && INTCONbits.T0IF) {
        INTCONbits.T0IF = 0;
        TIMER0_OVF_Callback();
    }

    /*----------------------------------------------------------
     * Peripheral interrupts require PEIE=1
     *----------------------------------------------------------*/
    if (INTCONbits.PEIE) {

        /*------------------------------------------------------
         * 4. ADC Conversion Complete
         *------------------------------------------------------*/
        if (PIE1bits.ADIE && PIR1bits.ADIF) {
            PIR1bits.ADIF = 0;
            ADC_ConvComplete_Callback();
        }

        /*------------------------------------------------------
         * 5. UART TX Register Empty
         *------------------------------------------------------*/
        if (PIE1bits.TXIE && PIR1bits.TXIF) {
            /* TXIF clears when TXREG is written (not manually) */
            UART_TX_Callback();
        }

        /*------------------------------------------------------
         * 6. UART RX Data Ready
         *------------------------------------------------------*/
        if (PIE1bits.RCIE && PIR1bits.RCIF) {
            /* RCIF clears when RCREG is read */
            UART_RX_Callback();
        }

        /*------------------------------------------------------
         * 7. SSP (SPI or I2C)
         *------------------------------------------------------*/
        if (PIE1bits.SSPIE && PIR1bits.SSPIF) {
            PIR1bits.SSPIF = 0;
            /* Route to correct callback based on mode */
            if ((SSPCON & 0x0Fu) <= 0x05u) {
                /* SPI modes: 0x00–0x05 */
                SPI_TransferComplete_Callback();
            } else {
                /* I2C modes: 0x06–0x0F */
                I2C_Slave_Callback();
            }
        }

        /*------------------------------------------------------
         * 8. CCP2 (PIR2 — needs PIE2 check)
         *------------------------------------------------------*/
        if (PIE2bits.CCP2IE && PIR2bits.CCP2IF) {
            PIR2bits.CCP2IF = 0;
            /* Add CCP2 callback here if needed */
        }

        /*------------------------------------------------------
         * 9. Timer2 Match (PWM timebase)
         *------------------------------------------------------*/
        if (PIE1bits.TMR2IE && PIR1bits.TMR2IF) {
            PIR1bits.TMR2IF = 0;
            /* Add TMR2 callback here if needed */
        }

    } /* end PEIE */
}
