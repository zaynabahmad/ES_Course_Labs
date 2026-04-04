/*
 * adc_test.c
 * Tests the ADC MCAL driver: init, channel read (AN0), and result processing.
 * Result is used to drive an LED brightness threshold demo via GPIO.
 * No direct register access — uses only ADC_Interface.h API.
 */

#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "adc_test.h"

/* LED indicates whether ADC reading is above mid-scale */
#define ADC_LED_PORT    GPIO_PORTA
#define ADC_LED_PIN     GPIO_PIN1

/* Threshold: half of 10-bit range */
#define ADC_THRESHOLD   512U

static void delay(void)
{
    unsigned int i;
    for(i = 0; i < 20000U; i++) { ; }
}

void ADC_Test(void)
{
    u16 adc_result;
    u8  reading_count;

    /* Configure indicator LED — RA1 */
    GPIO_SetPinDirection(ADC_LED_PORT, ADC_LED_PIN, GPIO_OUTPUT);
    GPIO_SetPinValue(ADC_LED_PORT, ADC_LED_PIN, GPIO_LOW);

    /* Initialise ADC module */
    ADC_Init();

    /* Take 10 readings from AN0 and control LED based on threshold */
    for(reading_count = 0; reading_count < 10U; reading_count++)
    {
        adc_result = ADC_Read(ADC_CHANNEL_0);

        if(adc_result >= ADC_THRESHOLD)
        {
            GPIO_SetPinValue(ADC_LED_PORT, ADC_LED_PIN, GPIO_HIGH);
        }
        else
        {
            GPIO_SetPinValue(ADC_LED_PORT, ADC_LED_PIN, GPIO_LOW);
        }

        delay();
    }

    /* Test channel switching: read AN1 */
    adc_result = ADC_Read(ADC_CHANNEL_1);

    /* Turn off ADC when not needed */
    ADC_Disable();
}