/*
 * ex4.c
 *
 *  Created on: Dec 15, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int noOfElements, pos, data[8], element;
	printf("Enter no of elements : ");
	scanf("%d", &noOfElements);
	// scan values of the array from user
	int index;
	for (index = 0; index < noOfElements; ++index)
	{
		scanf("%d", &data[index]);
	}
	printf("Enter the element to be inserted : ");
	scanf("%d", &element);
	printf("Enter the location : ");
	scanf("%d", &pos);
	// shift array
	for (index = 0; index < noOfElements && index <= pos + 1; ++index)
	{
		data[noOfElements - index] = data[noOfElements - index - 1];
	}
	data[pos - 1] = element;
	// show array element after addition
	for (index = 0; index <= noOfElements; ++index) {
		printf("%d  ", data[index]);
	}
	return 0;
}

