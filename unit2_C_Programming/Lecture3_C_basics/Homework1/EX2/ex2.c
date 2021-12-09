/*
 * Ex2.c
 *
 *  Created on: Dec 8, 2021
 *      Author: Mohamed
 */

#include <stdio.h>

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	int num;
	printf("Enter a integer : ");
	scanf("%d", &num);
	printf("you entered : %d", num);
	return 0;
}


