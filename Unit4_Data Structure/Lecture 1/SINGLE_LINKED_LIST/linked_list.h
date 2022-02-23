/*
 * linked_list.h
 *
 *  Created on: Feb 21, 2022
 *      Author: Mohamed
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "platform_Types.h"

// type definitions
#define NULL (void*)0
#define LIST_Get_No_Of_Elements(ptr) (ptr.count)
//effective data
struct Sdata
{
	uint32 ID;
	uint8 name[50];
	float height;
};

//node
struct node
{
	struct Sdata data;
    struct node* pNext;
};

//list structure to create different lists
struct list
{
	struct node* firstNode;
	struct node* head;
	//counter for each list increasing with pushing
	uint32 count;
};

//status
typedef enum
{
    LIST_no_error,
    LIST_empty,
    LIST_not_empty,
    LIST_full,
    LIST_not_full,
    LIST_null,
	LIST_invalid_position
}LIST_Status;

// LINKED APIs
LIST_Status LIST_Is_Empty(struct list* ptr);
LIST_Status LIST_Push_Back(struct list* ptr, struct Sdata new_data);
LIST_Status LIST_Push_Front(struct list* ptr, struct Sdata new_data);
LIST_Status LIST_Push_Anywhere(struct list* ptr, struct Sdata new_data, uint32 pos);
LIST_Status LIST_Delete_Front(struct list* ptr);
LIST_Status LIST_Delete_Back(struct list* ptr);
LIST_Status LIST_Allocation_Valid(struct node* ptr);
LIST_Status LIST_Pos_Valid(struct list* ptr, uint32 pos);
LIST_Status LIST_Delete_Anywhere(struct list* ptr, uint32 pos);
struct Sdata LIST_Get_Specified_item(struct list* ptr, uint32 pos);
void LIST_print(struct list* ptr);

#endif /* LINKED_LIST_H_ */
