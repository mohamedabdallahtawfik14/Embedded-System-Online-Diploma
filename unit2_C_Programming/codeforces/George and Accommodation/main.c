/*
 * main.c
 *
 *  Created on: Jan 13, 2022
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int noOfRooms, numPeople, capacity, sum = 0, count;
	scanf("%d", &noOfRooms);
	for (count = 0; count < noOfRooms; ++count)
	{
		scanf("%d %d", &numPeople, &capacity);
		if((capacity - numPeople) >=2)
		{
			sum++;
		}

	}
	printf("%d", sum);
	return 0;
}

