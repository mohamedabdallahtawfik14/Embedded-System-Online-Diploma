/*
 * main.c
 *
 *  Created on: Jan 15, 2022
 *      Author: Mohamed
 */

#include <stdio.h>

void sortArr(int cubes[], int size)
{

	int count, internalCount;
	for (count = 0; count < size - 1; ++count) {
		for (internalCount = count + 1; internalCount < size; ++internalCount) {
			if(cubes[internalCount] < cubes[count])
			{
				cubes[internalCount] = cubes[internalCount] + cubes[count];
				cubes[count] = cubes[internalCount] - cubes[count];
				cubes[internalCount] = cubes[internalCount] - cubes[count];
			}
		}

	}
}
int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int cols, cubes[100], count;
	scanf("%d", &cols);
	for (count = 0; count < cols; ++count)
	{
		scanf("%d", &cubes[count]);
	}
	sortArr(cubes, cols);
	for (count = 0; count < cols; ++count) {
		printf("%d ", cubes[count]);
	}
	return 0;
}

