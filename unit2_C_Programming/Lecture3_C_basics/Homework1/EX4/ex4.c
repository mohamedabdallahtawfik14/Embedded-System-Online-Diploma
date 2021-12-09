/*
 * ex4.c
 *
 *  Created on: Dec 8, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	float num1, num2;
	printf("Enter two numbers : ");
	scanf("%f %f", &num1, &num2);
	printf("Product : %f", num1 * num2);
	return 0;
}

