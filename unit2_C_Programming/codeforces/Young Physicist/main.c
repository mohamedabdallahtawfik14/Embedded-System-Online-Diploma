/*
 * main.c
 *
 *  Created on: Jan 4, 2022
 *      Author: mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int noOfVectors, input[3], count, internalCount, x = 0, y = 0, z = 0;
	scanf("%d", &noOfVectors);
	for (count = 0; count < noOfVectors; ++count)
	{
		for (internalCount = 0; internalCount < 3; ++internalCount)
		{
			scanf("%d", &input[internalCount]);
		}
		x += input[0];
		y += input[1];
		z += input[2];
	}
	if((x == 0) && (y == 0) && (z == 0))
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	return 0;
}

