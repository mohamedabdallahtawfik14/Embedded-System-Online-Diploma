/*
 * ex1.c
 *
 *  Created on: Jan 17, 2022
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);

	int m = 29;
	printf("Address of m : 0x%p\n", &m);
	printf("value of m : %d\n", m);

	int *ab = &m;
	printf("\nNow ab is assigned with the address of m.\n");
	printf("Address of pointer ab : 0x%p\n", ab);
	printf("Content of pointer ab : %d\n", *ab);

	m = 34;
	printf("The value of m assigned to 34 now.\n");
	printf("Address of pointer ab : 0x%p\n", ab);
	printf("Content of pointer ab : %d\n", *ab);

	*ab = 7;
	printf("The pointer variable ab is assigned with the value 7 now.\n");
	printf("Address of m : 0x%p\n", &m);
	printf("value of m : %d\n", m);
	return 0;
}

