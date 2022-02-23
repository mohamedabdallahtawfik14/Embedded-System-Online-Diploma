/*
 * fifo.h
 *
 *  Created on: Feb 18, 2022
 *      Author: MoStudy
 */

#ifndef FIFO_H_
#define FIFO_H_
//INCs
#include "platform_Types.h"

//user configuration
#define element_type uint8

// type definition
typedef struct
{
	uint32 length;
	uint32 count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buf_t;

typedef enum
{
	FIFO_no_error,
	FIFO_full,
	FIFO_not_full,
	FIFO_empty,
	FIFO_not_empty,
	FIFO_null,
}FIFO_Buf_Status;

//FIFO APIs
FIFO_Buf_Status FIFO_Check_Validation (element_type* Buff);
FIFO_Buf_Status FIFO_Init (FIFO_Buf_t* fifo, element_type* buff, uint32 length);
FIFO_Buf_Status FIFO_enqueue (FIFO_Buf_t* fifo, element_type item);
FIFO_Buf_Status FIFO_dequeue (FIFO_Buf_t* fifo, element_type* item);
FIFO_Buf_Status FIFO_Is_Full (FIFO_Buf_t* fifo);
FIFO_Buf_Status FIFO_Is_Empty (FIFO_Buf_t* fifo);
void FIFO_print(FIFO_Buf_t* fifo);
#endif /* FIFO_H_ */
