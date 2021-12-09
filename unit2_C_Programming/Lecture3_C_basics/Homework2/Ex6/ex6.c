/*
 * ex6.c
 *
 *  Created on: Dec 9, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int num;
	printf("Enter an integer: ");
	scanf("%d", &num);
	while(num < 0)
	{
		printf("Please enter a positive integer : ");
		scanf("%d", &num);
	}
	int count, sum = 0;
	for (count = 1; count <= num; ++count)
	{
		sum += count;
	}
	printf("Sum = %d", sum);
	return 0;
}


