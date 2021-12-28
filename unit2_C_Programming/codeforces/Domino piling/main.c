/*
 * main.c
 *
 *  Created on: Dec 28, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d", (n*m)>>1);
	return 0;
}
