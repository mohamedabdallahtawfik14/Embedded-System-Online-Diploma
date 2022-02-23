/*
 * lifo.c
 *
 *  Created on: Feb 18, 2022
 *      Author: Mohamed
 */
//INCs
#include "platform_Types.h"
#include "lifo.h"
#include "stdio.h"
//LIFO APIs definition

LIFO_Buf_Status LIFO_Check_Validation (element_type* Buff)
{
	if(Buff == NULL)
	{
		return LIFO_null;
	}
	return LIFO_no_error;
}

LIFO_Buf_Status LIFO_Init (LIFO_Buf_t *lifo, element_type* buff, uint32 length)
{
	lifo->base = buff;
	lifo->head = buff;
	lifo->length = length;
	lifo->count = 0;
	//return no error occured
	return LIFO_no_error;
}

LIFO_Buf_Status LIFO_Add_Item (LIFO_Buf_t *lifo, element_type item)
{
	//check if lifo is full
	if(LIFO_Is_Full(lifo) == LIFO_full)
	{
		return LIFO_full;
	}
	// add value to lifo
	*(lifo->head) = item;
	// make head point to next empty position
	lifo->head++;
	// incremrnt count --> currently elements at lifo
	lifo->count++;
	//return no error occured
	return LIFO_no_error;
}

LIFO_Buf_Status LIFO_Pop_Item (LIFO_Buf_t* lifo, element_type* item)
{
	//check if lifo is empty
	if(LIFO_Is_Empty(lifo) == LIFO_empty)
	{
		return LIFO_empty;
	}
	//decrement head to make it point to the target
	lifo->head--;
	//get value
	*item = *(lifo->head);
	//decrement number of elements
	lifo->count--;
	//return no error occured
	return LIFO_no_error;
}

LIFO_Buf_Status LIFO_Is_Full (LIFO_Buf_t* lifo)
{
	if(lifo->count == lifo->length)
	{
		return LIFO_full;
	}
	return LIFO_not_full;
}

LIFO_Buf_Status LIFO_Is_Empty (LIFO_Buf_t* lifo)
{
	if(lifo->count == 0)
	{
		return LIFO_empty;
	}
	return LIFO_not_empty;
}


