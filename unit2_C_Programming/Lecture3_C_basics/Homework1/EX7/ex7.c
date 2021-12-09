/*
 * ex7.c
 *
 *  Created on: Dec 9, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	float a, b;
	printf("Enter value of a : ");
	scanf("%f", &a);
	printf("Enter value of b : ");
	scanf("%f", &b);
	a = a * b;
	b = a / b;
	a = a / b;
	printf("After swapping, value of a = %.2f", a);
	printf("\nAfter swapping, value of b = %.1f", b);
	return 0;
}


