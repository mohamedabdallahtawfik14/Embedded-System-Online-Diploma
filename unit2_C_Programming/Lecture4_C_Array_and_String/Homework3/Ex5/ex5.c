/*
 * ex5.c
 *
 *  Created on: Dec 15, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int noOfElements, data[20], element;
	printf("Enter no of elements : ");
	scanf("%d", &noOfElements);
	int index;
	// scan values of the array from user
	for (index = 0; index < noOfElements; ++index)
	{
		scanf("%d", &data[index]);
	}
	// take element from user to search in array
	printf("Enter the element to be searched : ");
	scanf("%d", &element);
	index = 0;
	// search number
	while((data[index] != element) && (index < noOfElements))
	{
		index++;
	}
	// condition of while is always true so there no element in array matched with the user number
	if(index == noOfElements)
	{
		printf("Element not found!!!");
	}
	// matched
	else
	{
		printf("Number found at location = %d", index + 1);
	}
	return 0;
}

