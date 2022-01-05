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
	int destination, steps = 0;
	scanf("%d", &destination);
	if(destination % 5 != 0)
	{
		steps = (destination / 5) + 1;
	}
	else
	{
		steps = destination / 5;
	}
	printf("%d", steps);
	return 0;
}

