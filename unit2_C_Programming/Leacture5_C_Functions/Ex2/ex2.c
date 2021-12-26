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
	return a==0? 1:1;
}

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int num;
	printf("Enter an positive: ");
	scanf("%d", &num);
	printf("Factorial of %d = %ld", num, getFactorial(num));
	return 0;
}

