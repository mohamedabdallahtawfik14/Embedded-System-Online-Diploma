/*
 * ex4.c
 *
 *  Created on: Dec 9, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	float num;
	printf("Enter a number: ");
	scanf("%f", &num);
	if(num > 0)
	{
		printf("%.2f is positive", num);
	}
	else if(num < 0)
	{
		printf("%.2f is negative", num);
	}
	else
	{
		printf("you entered zero");
	}
	return 0;
}

