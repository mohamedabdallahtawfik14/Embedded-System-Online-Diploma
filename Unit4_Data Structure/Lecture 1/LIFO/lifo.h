/*
 * lifo.h
 *
 *  Created on: Feb 18, 2022
 *      Author: Mohamed
 */
#ifndef LIFO_H_
#define LIFO_H_

#include "platform_Types.h"

// user configuration
#define element_type uint8

// lifo structure
typedef struct
{
	element_type* base;
	element_type* head;
	uint32 length;
	uint32 count;
}LIFO_Buf_t;

//status
typedef enum
{
	LIFO_no_error,
	LIFO_full,
	LIFO_not_full,
	LIFO_empty,
	LIFO_not_empty,
	LIFO_null,
}LIFO_Buf_Status;

//LIFO APIs
LIFO_Buf_Status LIFO_Check_Validation (element_type* Buff);
LIFO_Buf_Status LIFO_Init (LIFO_Buf_t *lifo, element_type* buff, uint32 length);
LIFO_Buf_Status LIFO_Add_Item (LIFO_Buf_t *lifo, element_type item);
LIFO_Buf_Status LIFO_Pop_Item (LIFO_Buf_t *lifo, element_type* item);
LIFO_Buf_Status LIFO_Is_Full (LIFO_Buf_t* lifo);
LIFO_Buf_Status LIFO_Is_Empty (LIFO_Buf_t* lifo);
#endif
