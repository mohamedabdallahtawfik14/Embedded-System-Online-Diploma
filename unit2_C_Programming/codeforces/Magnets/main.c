/*
 * main.c
 *
 *  Created on: Jan 14, 2022
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int numOfMagnets, magnets[100000], count, groups = 1;
	scanf("%d", &numOfMagnets);
	for (count = 0; count < numOfMagnets; ++count)
	{
		scanf("%d", &magnets[count]);
	}
	for (count = 0; count < numOfMagnets - 1; ++count)
	{
		if(magnets[count] != magnets[count + 1])
		{
			groups++;
		}
	}
	printf("%d", groups);
	return 0;
}
