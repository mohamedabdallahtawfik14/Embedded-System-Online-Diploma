/*
 * main.c
 *
 *  Created on: Jan 25, 2022
 *      Author: mohamed
 */

#include <stdio.h>

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int colors[4], count, internalCount, sum = 0;
	for (count = 0; count < 4; ++count)
	{
		scanf("%d", &colors[count]);
	}
	for (count = 0; count < 3; ++count)
	{
		for (internalCount = count + 1; internalCount < 4; ++internalCount)
		{
			if(colors[count] == colors[internalCount])
			{
				sum++;
				break;
			}
		}
	}
	printf("%d", sum);
	return 0;
}

