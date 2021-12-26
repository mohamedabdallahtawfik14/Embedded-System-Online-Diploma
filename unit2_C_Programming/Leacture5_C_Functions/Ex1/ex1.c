/*
 * ex1.c
 *
 *  Created on: Dec 26, 2021
 *      Author: Mohamed
 */

#include <stdio.h>
#include <math.h>

int checkPrime(int a)
{
	int count;
	char prime = 1;
	for (count = 2; count <= sqrt(a); ++count)
	{
		if(a % count == 0)
		{
			prime = 0;
		}
	}
	return prime;
}

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int firstNum, secondNum, count;

	printf("Enter two numbers(intervals): ");
	scanf("%d %d", &firstNum, &secondNum);
	printf("Prime numbers between %d and %d are: ", firstNum, secondNum);
	for (count = firstNum + 1; count < secondNum; ++count)
	{
		if(checkPrime(count))
		{
			printf("%d ", count);
		}
	}
	return 0;
}


