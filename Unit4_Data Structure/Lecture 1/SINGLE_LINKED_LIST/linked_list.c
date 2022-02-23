/*
 * linked_list.c
 *
 *  Created on: Feb 21, 2022
 *      Author: Mohamed
 */

#include "platform_Types.h"
#include "linked_list.h"
#include "stdlib.h"
#include "stdio.h"
/*
/// summary: this function checks the linked list is empty or not
/// input: take pointer to the linked list
/// return: status of list (empty, not_empty)
 */
LIST_Status LIST_Is_Empty(struct list* ptr)
{
	//check if linked list is empty or not
	if(ptr->firstNode == NULL)
	{
		return LIST_empty;
	}
	//linked is not empty
	else
	{
		return LIST_not_empty;
	}
}
/*
/// summary: this function checks node was allocated successfully or not (malloc returned null or not)
/// input: take pointer to the linked list
/// return: status of list (null, not null)
 */
LIST_Status LIST_Allocation_Valid(struct node* ptr)
{
	if(ptr == NULL)
	{
		return LIST_null;
	}
	else
	{
		return LIST_no_error;
	}
}
/*
/// summary: this function checks if position u want to add node at it is valid or not
/// input: take pointer to the linked list, and an integer variable indicate the position you want to add node at it
/// return: status of list (no_error, invalid_position)
 */
LIST_Status LIST_Pos_Valid(struct list* ptr, uint32 pos)
{
	//u can add the node at this position
	if(pos <= (ptr->count + 1))
	{
		return LIST_no_error;
	}
	// u can't as there'r not nodes at this position to connect this node with it
	else
	{
		return LIST_invalid_position;
	}
}
/*
/// summary: this function --> add node at end of our linked list
/// input: take pointer to the linked list, and date we want to add it to the node
/// return: status of list (no_error if added successfully, null if can't allocate node)
 */
LIST_Status LIST_Push_Back(struct list* ptr, struct Sdata new_data)
{
	// give return of the fun to status var
	LIST_Status status = LIST_Is_Empty(ptr);
	//create new node
	struct node* newNode;
	//allocate new node
	//make sure allocation is done
	newNode = (struct node*)malloc(sizeof(struct node));
	if (LIST_Allocation_Valid(newNode) == LIST_null)
	{
		return LIST_null;
	}
	else
	{
		/* do nothing MISRA rule */
	}
	//always make next of new node point to null (new last node)
	newNode->pNext = NULL;
	switch(status)
	{
		//if linked list is empty
		case LIST_empty:
		{
			//make first pointer of our linked list point to first node
			ptr->firstNode = newNode;
			//make head point to new node
			ptr->head = newNode;
			//just make sure next of head is not point to garbage
			ptr->head->pNext = NULL;
		}
		break;
		//if linked list is not empty
		case LIST_not_empty:
		{
			ptr->head->pNext = newNode; // make next of head points to new node (connect last node with new node)
			newNode->pNext = NULL; //make new node point to null (became last node)
			ptr->head= newNode; // navigate head to point to last node to make it o(1)
		}
		break;
		default:
		{
			/* do no thing just for MISRA rule */
		}
		break;
	}
	newNode->data = new_data; //occupy data with new data
	ptr->count++; //increase number of elements
	return LIST_no_error; // node added successfully
}
/*
/// summary: this function --> add node at beginning of our linked list
/// input: take pointer to the linked list, and date we want to add it to the node
/// return: status of list (no_error if added successfully, null if can't allocate node)
 */
LIST_Status LIST_Push_Front(struct list* ptr, struct Sdata new_data)
{
	// give return of the fun to status var
	LIST_Status status = LIST_Is_Empty(ptr);
	//create new node
	struct node* newNode;
	//allocate new node
	//make sure allocation is done
	newNode = (struct node*)malloc(sizeof(struct node));
	if (LIST_Allocation_Valid(newNode) == LIST_null)
	{
		return LIST_null;
	}
	else
	{
		/* do nothing MISRA rule */
	}
	switch(status)
	{
		//if linked list is empty
		case LIST_empty:
		{
			//make head point to new node
			ptr->head = newNode;
			//just make sure next of head is not point to garbage
			ptr->head->pNext = NULL;
		}
		break;
		//if linked list is not empty
		case LIST_not_empty:
		{
			newNode->pNext = ptr->firstNode; //make new node point to null (became last node)
		}
		break;
		default:
		{
			/* do no thing just for MISRA rule */
		}
		break;
	}
	//always make pointer of firstNode point to new node (new first node)
	ptr->firstNode = newNode;
	newNode->data = new_data; //occupy data with new data
	ptr->count++; //increase number of elements
	return LIST_no_error; // node added in front successfully
}
// add node at anywhere u want
/*
/// summary: this function --> add node at anywhere of the linked list u want
/// input: take pointer to the linked list, and data we want to add it to the node
/// return: status of list (no_error if added successfully, null if can't allocate node)
 */
LIST_Status LIST_Push_Anywhere(struct list* ptr, struct Sdata new_data, uint32 pos)
{
	//check first if he want to add the node at valid position or invalid
	if (LIST_Pos_Valid(ptr, pos) == LIST_invalid_position)
	{
		return LIST_invalid_position;
	}
	else
	{
		/* do nothing MISRA rule */
	}
	//create new node
	struct node* newNode;
	//allocate new node
	//make sure allocation is done
	newNode = (struct node*)malloc(sizeof(struct node));
	if (LIST_Allocation_Valid(newNode) == LIST_null)
	{
		return LIST_null;
	}
	else
	{
		/* do nothing MISRA rule */
	}
	switch(pos)
	{
		//if he want to add the node at first
		case 1:
		{
			//connect new first node with the beginning of our linked list
			newNode->pNext = ptr->firstNode;
			//if there are not nodes else
			if(ptr->firstNode == NULL)
			{
				ptr->head = newNode;
			}
			//make pointer of firstNode point to new node (new first node)
			ptr->firstNode = newNode;
			//just make sure next of head is not point to garbage
			ptr->head->pNext = NULL;
		}
		break;
		default:
		{
			//make temp pointer to navigate over our list with it to reach the position
			struct node* tempPtr = ptr->firstNode;
			pos -= 2; // to make pointer stop at position before we need to add new node
			while(pos--)
			{
				//point to next node
				tempPtr = tempPtr->pNext;
			}
			//make next of new node point to current position
			newNode->pNext=tempPtr->pNext;
			// make node before that point to new node
			tempPtr->pNext=newNode;
		}

		break;
	}

	newNode->data = new_data; //occupy data with new data
	ptr->count++; //increase number of elements
	return LIST_no_error; // node added in front successfully
}
// delete node from front of our linked list
/*
/// summary: this function -->delete node from beginning of our linked list
/// input: take pointer to the linked list
/// return: status of list (no_error if deleted successfully, empty if there are not nodes to delete)
 */
LIST_Status LIST_Delete_Front(struct list* ptr)
{
	// give return of the fun to status var
	LIST_Status status = LIST_Is_Empty(ptr);
	switch(status)
	{
		//if linked list is empty
		case LIST_empty:
		{
			return LIST_empty;
		}
		break;
		//if linked list is not empty
		case LIST_not_empty:
		{
			//hold first node to free it
			struct node* tempPtr = ptr->firstNode;
			// make first pointer points to second node
			ptr->firstNode = ptr->firstNode->pNext;
			free(tempPtr); //free node
		}
		break;
		default:
		{
			/* do no thing just for MISRA rule */
		}
		break;
	}
	ptr->count--; //decrease number of elements
	return LIST_no_error; // node deleted from front successfully
}
// delete node from end of our linked list
// delete node from front of our linked list
/*
/// summary: this function -->delete node from end of our linked list
/// input: take pointer to the linked list
/// return: status of list (no_error if deleted successfully, empty if there are not nodes to delete)
 */
LIST_Status LIST_Delete_Back(struct list* ptr)
{
	// give return of the fun to status var
	LIST_Status status = LIST_Is_Empty(ptr);
	switch(status)
	{
		//if linked list is empty
		case LIST_empty:
		{
			return LIST_empty;
		}
		break;
		//if linked list is not empty
		case LIST_not_empty:
		{
			//temp pointer points to first node to navigate with it over our list to reach previous of the last node
			struct node* tempPtr = ptr->firstNode;
			if(tempPtr->pNext == NULL)
			{
				ptr->firstNode = NULL;
				ptr->head = NULL;
				free(tempPtr);
			}
			else
			{
				//loop until pervious of the last node
				while(tempPtr->pNext->pNext != NULL)
				{
					//points to next node
					tempPtr = tempPtr->pNext;
				}
				//free last node
				free(tempPtr->pNext);
				//make last node points to NULL
				tempPtr->pNext = NULL;
			}
		}
		break;
		default:
		{
			/* do no thing just for MISRA rule */
		}
		break;
	}
	ptr->count--; //decrease number of elements
	return LIST_no_error; // node deleted from end successfully
}
LIST_Status LIST_Delete_Anywhere(struct list* ptr, uint32 pos)
{
	//check first if he want to delete the node that didn't exist
	if (LIST_Pos_Valid(ptr, pos) == LIST_invalid_position)
	{
		return LIST_invalid_position;
	}
	else
	{
		/* do nothing MISRA rule */
	}
	//check first if he want to delete the node that didn't exist
	if (LIST_Is_Empty(ptr) == LIST_empty)
	{
		return LIST_empty;
	}
	else
	{
		/* do nothing MISRA rule */
	}
	struct node* tempPtr = ptr->firstNode;
	switch(pos)
	{
		//if he want to add the node at first
		case 1:
		{
			//make first pointer to point to second node (it will become first node)
			ptr->firstNode = ptr->firstNode->pNext;
			//just make sure next of head is not point to garbage
			ptr->head->pNext = NULL;
			free(tempPtr);
		}
		break;
		default:
		{
			pos -= 2; // to make pointer stop at position before we need to delete the node
			while(pos--)
			{
				//point to next node
				tempPtr = tempPtr->pNext;
			}
			//connect current node with next of the next node and free the node between them
			tempPtr->pNext = tempPtr->pNext->pNext;
			//free node
			free(tempPtr->pNext);
		}
		break;
	}
	ptr->count--; //decrease number of elements
	return LIST_no_error; // node added in front successfully
}

struct Sdata LIST_Get_Specified_item(struct list* ptr, uint32 pos)
{
	//check if list is empty
//	if((LIST_Is_Empty(ptr) == LIST_empty) || pos > ptr->count)
//	{
//		printf("WARNNING!!! ===> this number is a garbage value ==>");
//	}
//	else
//	{
//		/* do nothing --> MISRA rule*/
//	}
	//make temp pointer to navigate with it over our list to reach target item
	struct node* tempPtr = ptr->firstNode;
	while(pos--)
	{
		tempPtr = tempPtr->pNext;
	}
	//return requested data
	return tempPtr->data;
}

// print all effective data of our nodes founded in our linked list
void LIST_print(struct list* ptr)
{
	//make temp pointer to navigate over our list with it
	struct node* temp = ptr->firstNode;
	if(ptr->firstNode == NULL)
	{
		printf("=================================================================================\n");
		printf("\t\t\t\tEMPTY LIST\n");
		printf("=================================================================================\n");
	}
	else
	{
		uint16 count = 1;
		//loop until last node
		while(temp != NULL)
		{
			printf("Record Number ===> %u\n", count);
			printf("\t\tID : %u\n", temp->data.ID);
			printf("\t\tName : %s\n", temp->data.name);
			printf("\t\tHeight : %g\n\n", temp->data.height);
			//point to next node
			temp = temp->pNext;
			count++;
		}
	}

	printf("\n");
}

