/*
 * main.c
 *
 *  Created on: Jan 5, 2022
 *      Author: mohamed
 */

#include <stdio.h>

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int number, times, count;
	scanf("%d %d", &number, &times);
	for (count = 0; count < times; ++count)
	{
		if(number % 10 == 0)
		{
			number /= 10;
		}
		else
		{
			number--;
		}
	}
	printf("%d", number);
	return 0;
}

