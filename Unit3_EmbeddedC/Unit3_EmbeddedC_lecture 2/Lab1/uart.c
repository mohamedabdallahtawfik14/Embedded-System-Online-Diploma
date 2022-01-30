#include "uart.h"
#include "platform_types.h"

#define UART0DR *((vuint32_t *)((vuint32_t *)0x101f1000))

void uart_send_string(uint8 *p_tx_string)
{
    /* loop until end of string (null terminator)*/
    while(*p_tx_string != '\0')
    {
        /* write character by character on uart */
        UART0DR = (uint32)*p_tx_string;
        /* point to next character */
        p_tx_string++;
    }
}