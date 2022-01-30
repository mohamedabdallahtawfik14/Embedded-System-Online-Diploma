#include "uart.h"
#include "platform_types.h"
/* global array of char act as string holding our string which we need it to be written on uart */
uint8 stringBuffer[100] = "Learn-in-Depth: Mohamed Abdallah";
void main(void)
{
    /* pass string to uart */
    // name of array point to the address of first charater stringBuffer == &stringBuffer[0]
    uart_send_string(stringBuffer); 
}