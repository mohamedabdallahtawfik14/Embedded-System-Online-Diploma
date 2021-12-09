/*
 * ex1.c
 *
 *  Created on: Dec 9, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int num;
	printf("Enter an integer you want to check : ");
	scanf("%d", &num);
	if(num % 2 ==0)
	{
		printf("%d is even", num);
	}
	else
	{
		printf("%d is odd", num);
	}
	return 0;
}
