/*
 * main.c
 *
 *  Created on: Dec 31, 2021
 *      Author: mohamed
 */

#include <stdio.h>

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int noOfProblems, arr[3], count, internalCount, sum = 0, solvedProblems = 0;
	scanf("%d", &noOfProblems);
	for (count = 0; count < noOfProblems; ++count)
	{
		sum = 0;
		for(internalCount = 0; internalCount < 3; ++internalCount)
		{
			scanf("%d", &arr[internalCount]);
			if(arr[internalCount] == 1)
			{
				sum++;
			}
		}
		if(sum >=2)
		{
			solvedProblems++;
		}
	}
	printf("%d", solvedProblems);
	return 0;
}

