/*
 * ex3.c
 *
 *  Created on: Dec 9, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	float num1, num2, num3;
	printf("Enter three numbers: ");
	scanf("%f %f %f", &num1, &num2, &num3);
	if(num1 > num2)
	{
		if(num1 > num3)
		{
			printf("Largest number = %.2f", num1);
		}
		else
		{
			printf("Largest number = %.2f", num3);
		}
	}
	else
	{
		if(num2 > num3)
		{
			printf("Largest number = %.2f", num2);
		}
		else
		{
			printf("Largest number = %.2f", num3);
		}
	}
	return 0;
}

