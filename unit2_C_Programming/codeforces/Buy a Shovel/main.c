/*
 * main.c
 *
 *  Created on: Jan 24, 2022
 *      Author: mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int priceShovel, r, result, count;
	count = 1;
	scanf("%d %d", &priceShovel, &r);
	do
	{
		result = ((count * priceShovel) % 10);
		count++;
	}
	while(result != r && result != 0);
	printf("%d", count - 1);
	return 0;
}

