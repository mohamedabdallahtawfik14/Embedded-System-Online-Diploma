/*
 * main.c
 *
 *  Created on: Feb 18, 2022
 *      Author: Mohamed
 */
//INCs
#include "stdio.h"
#include "platform_Types.h"
#include "fifo.h"

//create Buffer
#define Buff_Length 5
element_type Buff[Buff_Length];

int main(void)
{
	//check if allocation succeeded or not
	if(FIFO_Check_Validation(Buff) == FIFO_no_error)
	{
		element_type i, temp = 0;
		FIFO_Buf_t uart_fifo;
		FIFO_Buf_Status status;
		// init fifo
		if(FIFO_Init(&uart_fifo, Buff, Buff_Length) == FIFO_no_error)
		{
			printf("========================= FIFO_init--->DONE =========================\n");
		}
		else //MISRA rule
		{
			/* do nothing */
		}
		// enqueue
		for(i = 0; i < 7; i++)
		{
			status = FIFO_enqueue(&uart_fifo, i);
			switch(status)
			{
				case FIFO_no_error:
				{
					printf("================ uart_fifo enqueue(%d)---->DONE ================\n", i);
				}
				break;
				case FIFO_full:
				{
					printf("================ uart_fifo enqueue(%d)---->FAILED(FIFO is full) ================\n", i);
				}
				break;
				default:
				{
					/*do nothing*/
				}
				break;
			}
		}
		// print all elements of fifo
		FIFO_print(&uart_fifo);
		//dequeue two elements
		status = FIFO_dequeue(&uart_fifo, &temp);
		switch(status)
		{
			case FIFO_no_error:
			{
				printf("================ uart_fifo dequeue(%d)---->DONE ================\n", temp);
			}
			break;
			case FIFO_empty:
			{
				printf("================ uart_fifo dequeue---->FAILED(FIFO is empty) ================\n");
			}
			break;
			default:
			{
				/*do nothing*/
			}
			break;
		}
		status = FIFO_dequeue(&uart_fifo, &temp);
		switch(status)
		{
			case FIFO_no_error:
			{
				printf("================ uart_fifo dequeue(%d)---->DONE ================\n", temp);
			}
			break;
			case FIFO_empty:
			{
				printf("================ uart_fifo dequeue---->FAILED(FIFO is empty) ================\n");
			}
			break;
			default:
			{
				/*do nothing*/
			}
			break;
		}
		// print all elements of fifo
		FIFO_print(&uart_fifo);
		//dequeue three elements
		status = FIFO_dequeue(&uart_fifo, &temp);
		switch(status)
		{
			case FIFO_no_error:
			{
				printf("================ uart_fifo dequeue(%d)---->DONE ================\n", temp);
			}
			break;
			case FIFO_empty:
			{
				printf("================ uart_fifo dequeue---->FAILED(FIFO is empty) ================\n");
			}
			break;
			default:
			{
				/*do nothing*/
			}
			break;
		}
		status = FIFO_dequeue(&uart_fifo, &temp);
		switch(status)
		{
			case FIFO_no_error:
			{
				printf("================ uart_fifo dequeue(%d)---->DONE ================\n", temp);
			}
			break;
			case FIFO_empty:
			{
				printf("================ uart_fifo dequeue---->FAILED(FIFO is empty) ================\n");
			}
			break;
			default:
			{
				/*do nothing*/
			}
			break;
		}
		status = FIFO_dequeue(&uart_fifo, &temp);
		switch(status)
		{
			case FIFO_no_error:
			{
				printf("================ uart_fifo dequeue(%d)---->DONE ================\n", temp);
			}
			break;
			case FIFO_empty:
			{
				printf("================ uart_fifo dequeue---->FAILED(FIFO is empty) ================\n");
			}
			break;
			default:
			{
				/*do nothing*/
			}
			break;
		}
		// print all elements of fifo
		FIFO_print(&uart_fifo);
	}
	else //allocation not succeeded
	{
		printf("========================= Allocation not succeeded =========================");
	}
	return 0;
}
