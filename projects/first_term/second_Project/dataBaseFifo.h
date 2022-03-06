#ifndef DATABASEFIFO_H_
#define DATABASEFIFO_H_
#include "stdio.h"
#include "platform_Types.h"

// student data 
typedef struct
{
	char_t fname[50];
	char_t lname[50];
	uint32 roll;
	float GPA;
	uint32 cid[10];
}SstudentInfo;

// type definition
typedef struct
{
	uint32 length;
	uint32 count;
	SstudentInfo* base;
	SstudentInfo* head;
	SstudentInfo* tail;
}SFIFO_Buf_t;

//status
typedef enum
{
	SFIFO_no_error,
	SFIFO_full,
	SFIFO_not_full,
	SFIFO_empty,
	SFIFO_not_empty,
	SFIFO_null,
}SFIFO_Buf_Status;

SFIFO_Buf_Status SFIFO_enqueue (SFIFO_Buf_t* fifo, SstudentInfo item);
SFIFO_Buf_Status SFIFO_Is_Full (SFIFO_Buf_t* fifo);
SFIFO_Buf_Status SFIFO_Init (SFIFO_Buf_t* fifo, SstudentInfo* buff, uint32 length);

//APIs
void add_student_file();
void add_student_manually();
void find_rl();
void find_fn();
void fine_c();
void tot_s();
void del_s();
void up_s();
void show_s();

#endif