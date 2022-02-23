/*
 * main.c
 *
 *  Created on: Feb 18, 2022
 *      Author: Mohamed
 */
//INCs
#include "platform_Types.h"
#include "lifo.h"
#include <stdio.h>

// user configuration
#define Buff_Length 5
element_type Buff1[Buff_Length];

int main(void)
{
	element_type i, temp = 0;
	LIFO_Buf_t uart_lifo;
	if(LIFO_Check_Validation(Buff1) == LIFO_no_error)
	{
		LIFO_Buf_Status status;
		if(LIFO_Init(&uart_lifo, Buff1, (uint32)Buff_Length) == LIFO_no_error)
		{
			printf("================ LIFO_Init---->DONE ================\n");
			// push items to lifo
			for(i = 0; i < 7; i++)
			{
				status = LIFO_Add_Item(&uart_lifo, i);
				switch(status)
				{
					case LIFO_no_error:
					{
						printf("================ uart_lifo add(%d)---->DONE ================\n", i);
					}
					break;
					case LIFO_full:
					{
						printf("================ uart_lifo add(%d)---->faild(LIFO is full) ================\n", i);
					}
					break;
					default:
					{
						/*do nothing*/
					}
					break;
				}
			}
			printf("==========================================================\n");
			// pop items from lifo
			for(i = 0; i < 7; i++)
			{
				status = LIFO_Pop_Item(&uart_lifo, &temp);
				switch(status)
				{
					case LIFO_no_error:
					{
						printf("================ uart_lifo pop(%d)---->DONE ================\n", temp);
					}
					break;
					case LIFO_empty:
					{
						printf("================ uart_lifo pop---->faild(LIFO is already empty) ================\n");
					}
					break;
					default:
					{
						/*do nothing*/
					}
					break;
				}
			}
		}
		else //LIFO_Init
		{
			/*do nothing*/
		}
	}
	else // LIFO_Check_Validation returned LIFO_null
	{
		printf("================ Buffer didn't reserve ================\n");
	}
	return 0;
}

