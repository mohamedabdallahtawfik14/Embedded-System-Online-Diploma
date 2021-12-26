/*
 * ex2.c
 *
 *  Created on: Dec 26, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

long getFactorial(int a)
{
	if(a > 1)
	{
		return a * getFactorial(a - 1);
	}
	return 1;
}

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int num;
	do
	{
		printf("Enter an positive: ");
		scanf("%d", &num);
	}
	while(num<0);
	printf("Factorial of %d = %ld", num, getFactorial(num));
	return 0;
}

