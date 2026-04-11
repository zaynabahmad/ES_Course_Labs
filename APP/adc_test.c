#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../HAL/LM35/LM35_interface.h"
#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/DELAY/DELAY_interface.h"

void APP_ADC_Test(void)
{
    u16 adc_value;
    u16 temp_x100;

    UART_Init9600();
    LM35_Init();

    while(1)
    {
        /* Step 3 */
        ADC_Step3_WaitAcquisitionTime_us(20);

        /* Step 4 */
        ADC_Step4_StartConversion();

        /* Step 5 */
        ADC_Step5_WaitForConversion();

        /* Step 6 */
        adc_value = ADC_Step6_ReadResult();

        temp_x100 = LM35_ConvertToCentiC(adc_value);

        UART_WriteText("Temp = ");
        UART_WriteTempCenti(temp_x100);
        UART_WriteText(" C");
        UART_WriteNewLine();

        /* Step 7 */
        ADC_Step7_WaitBeforeNextSample_us(8);

        Delay_ms(1000);
    }
}