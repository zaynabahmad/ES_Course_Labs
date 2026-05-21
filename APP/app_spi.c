/**
 * @file    app_spi.c
 * @brief   SPI master application -- application layer, no register access.
 *
 * @details The application owns the *protocol* -- when to assert chip-select
 *          and which bytes form a frame -- while the MCAL owns the *transfer*.
 *          Here a fixed three-byte frame is sent and the bytes clocked back
 *          are forwarded over the UART so the exchange can be observed.
 */
#include "app_spi.h"
#include "../MCAL/SPI_interface.h"
#include "../MCAL/UART_interface.h"

/** Bytes sent on each frame -- a recognisable, non-trivial pattern. */
static const byte_t au8Frame[3] = { 0xA5u, 0x3Cu, 0x7Eu };

/** Pause between frames, in milliseconds. */
#define APP_SPI_PERIOD_MS       500u

void vApp_Spi(void)
{
    byte_t u8Index;
    byte_t u8Reply;
    char   acText[7];

    vSPI_MasterInit();
    vUART_Init();

    while (1)
    {
        vSPI_SlaveSelect(LEVEL_LOW);            /* open the frame. */

        for (u8Index = 0u; u8Index < 3u; u8Index++)
        {
            u8Reply = u8SPI_Transfer(au8Frame[u8Index]);

            IntToStr((int)u8Reply, acText);
            vUART_SendString("SPI rx=");
            vUART_SendString(acText);
            vUART_SendString("\r\n");
        }

        vSPI_SlaveSelect(LEVEL_HIGH);           /* close the frame. */
        Delay_ms(APP_SPI_PERIOD_MS);
    }
}
