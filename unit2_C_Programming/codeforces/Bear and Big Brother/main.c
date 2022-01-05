/*
 * main.c
 *
 *  Created on: Jan 4, 2022
 *      Author: mohamed
 */

#include <stdio.h>

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int limak, bob, count;
	scanf("%d %d", &limak, &bob);
	for (count = 1; limak < bob ; ++count)
	{
		limak *= 3;
		bob *=2;
		if(limak > bob)
		{
			break;
		}
	}
	printf("%d", count);
	return 0;
}

