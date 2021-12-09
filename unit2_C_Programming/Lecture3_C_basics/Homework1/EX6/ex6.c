/*
 * ex6.c
 *
 *  Created on: Dec 8, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	float a, b, temp;
	printf("Enter value of a : ");
	scanf("%f", &a);
	printf("Enter value of b : ");
	scanf("%f", &b);
	temp = a;
	a = b;
	b = temp;
	printf("After swapping, value of a = %f", a);
	printf("After swapping, value of b = %f", b);
	return 0;
}

