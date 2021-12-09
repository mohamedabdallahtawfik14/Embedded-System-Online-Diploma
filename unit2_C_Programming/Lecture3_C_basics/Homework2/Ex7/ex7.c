/*
 * ex7.c
 *
 *  Created on: Dec 9, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int num;
	unsigned long long int factorial = 1;
	printf("Enter an integer: ");
	scanf("%d", &num);
	if (num < 0)
	{
		printf("Error!!! Factorial of negative number doesn't exist.");
	}
	else	// number is positive
	{
		int count;
		for (count = 1; count <= num; ++count)
		{
			factorial *= count;
		}
		printf("Factorial %llu", factorial);
	}
	return 0;
}

