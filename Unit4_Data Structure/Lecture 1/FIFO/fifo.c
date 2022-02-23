/*
 * fifo.c
 *
 *  Created on: Feb 18, 2022
 *      Author: Mohamed
 */
//INCs
#include "platform_Types.h"
#include "fifo.h"
#include "stdio.h"

//FIFO APIs definition
FIFO_Buf_Status FIFO_Check_Validation (element_type* Buff)
{
	//check if buff didn't reserve (returned NULL) (dynamic allocation case)
	if(Buff == NULL)
	{
		return FIFO_null;
	}
	// if allocation succeeded return no_error ocuurred
	else
	{
		return FIFO_no_error;
	}
}
FIFO_Buf_Status FIFO_Init (FIFO_Buf_t* fifo, element_type* buff, uint32 length)
{
	//make base, head, tail point to base of buffet at first
	fifo->base = buff;
	fifo->head = buff;
	fifo->tail = buff;
	//set length
	fifo->length = length;
	// set number of elements in queue with 0 at first
	fifo->count = 0;
	// init done and return no_error occurred
	return FIFO_no_error;
}
FIFO_Buf_Status FIFO_enqueue (FIFO_Buf_t* fifo, element_type item)
{
	//check if fifo is full or not
	if(FIFO_Is_Full(fifo) == FIFO_full)
	{
		return FIFO_full;
	}
	else // fifo not full
	{
		// enqueue value
		*(fifo->head) = item;
		fifo->count++;
		// circular FIFO
		if(fifo->head == (fifo->base + (fifo->length * sizeof(element_type))))
		{
			fifo->head = fifo->base;
		}
		else // head didn't reach the end of fifo
		{
			fifo->head++;
		}
		//fifo enqueued succeeded and returned no_error
		return FIFO_no_error;
	}
}
FIFO_Buf_Status FIFO_dequeue (FIFO_Buf_t* fifo, element_type* item)
{
	//check if fifo is empty or not
	if(FIFO_Is_Full(fifo) == FIFO_empty)
	{
		return FIFO_empty;
	}
	else //fifo not empty
	{
		//get value
		*item = *(fifo->tail);
		// decrement number of elements in fifo
		fifo->count--;
		// circular FIFO
		if(fifo->tail == (fifo->base + (fifo->length * sizeof(element_type))))
		{
			fifo->tail = fifo->base;
		}
		else // tail didn't reach the end of fifo
		{
			fifo->tail++;
		}
		//fifo dequeued succeeded and returned no_error
		return FIFO_no_error;
	}
}
FIFO_Buf_Status FIFO_Is_Full (FIFO_Buf_t* fifo)
{
	//check if fifo is full returned FIFO_full
	if(fifo->count == fifo->length)
	{
		return FIFO_full;
	}
	// if not returned FIFO_not_full
	else
	{
		return FIFO_not_full;
	}
}
FIFO_Buf_Status FIFO_Is_Empty (FIFO_Buf_t* fifo)
{
	//check if fifo is empty returned FIFO_empty
	if(fifo->count == 0)
	{
		return FIFO_empty;
	}
	// if not returned FIFO_not_empty
	else
	{
		return FIFO_not_empty;
	}
}
void FIFO_print(FIFO_Buf_t* fifo)
{
	printf("================ FIFO_PRINT_ALL_ELEMENTS ================\n");
	//check if fifo is empty print FIFO_empty
	if(FIFO_Is_Empty(fifo) == FIFO_empty)
	{
		printf("================  NOTHING TO PRINT--> FIFO IS EMPTY ================\n");
	}
	else
	{
		uint32 i;
		element_type* temp = fifo->tail;
		for(i = 0; i < fifo->count; i++)
		{
			printf("================ ELEMENT(%d)---->%d ================\n", i+1, *temp);
			temp++;
		}
	}
	printf("================ END OF PRINT ================\n");
}
