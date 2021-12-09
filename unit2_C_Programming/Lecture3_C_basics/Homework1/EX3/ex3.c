/*
 * ex3.c
 *
 *  Created on: Dec 8, 2021
 *      Author: Mohamed
 */

#include <stdio.h>
int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int num1, num2;
	printf("Enter two integer : ");
	scanf("%d %d", &num1, &num2);
	printf("Sum : %d", num1 + num2);
	return 0;
}

