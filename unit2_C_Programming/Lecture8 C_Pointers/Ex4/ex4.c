/*
 * ex4.c
 *
 *  Created on: Jan 17, 2022
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int arr[15], numOfElements, *ptrArr, count;
	ptrArr = arr;
	printf("Input the number of elements to store in the array (max 15) : ");
	scanf("%d", &numOfElements);
	printf("Input %d number of elements in the array :\n", numOfElements);
	//******* scaning the array elements from the user ******//
	for (count = 0; count < numOfElements; ++count)
	{
		printf("element - %d : ", count + 1);
		scanf("%d", ptrArr);
		ptrArr++;
	}
	ptrArr--;
	//******* printing the array elements to the user ******//
	printf("The elements of array in reverse order are : \n");
	for (count = numOfElements; count > 0; --count)
	{
		printf("element - %d : %d\n", count, *ptrArr);
		ptrArr--;
	}
	return 0;
}


