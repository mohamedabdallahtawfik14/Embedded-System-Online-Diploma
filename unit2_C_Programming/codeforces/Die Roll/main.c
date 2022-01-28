/*
 * main.c
 *
 *  Created on: Jan 27, 2022
 *      Author: mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int yakko, wakko, maximum, prob;
	scanf("%d %d", &yakko, &wakko);
	maximum = (yakko >= wakko)? yakko : wakko;
	prob = 6 -  maximum + 1;
	switch(prob)
	{
		case 1:
		{
			printf("1/6");
		}
		break;
		case 2:
		{
			printf("1/3");
		}
		break;
		case 3:
		{
			printf("1/2");
		}
		break;
		case 4:
		{
			printf("2/3");
		}
		break;
		case 5:
		{
			printf("5/6");
		}
		break;
		case 6:
		{
			printf("1/1");
		}
		break;
	}
	return 0;
}

